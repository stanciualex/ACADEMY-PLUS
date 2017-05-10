<?php

class User
{
    private $db;

    function __construct($DB_con)
    {
      $this->db = $DB_con;
    }

    public function get_db()
    {
      return $this->db;
    }

    public function send_register_mail($email, $username)
    {
        $subject = 'Welcome to Camagru!';
        $message = 'Welcome, ' . $username;
        $message .= "We ardasdasdasdasdasadasdas";
        $headers = 'From: astanciu@student.42.fr' . "\r\n" .
            'Reply-To: astanciu@student.42.fr' . "\r\n" .
            'X-Mailer: PHP/' . phpversion();

        mail($email, $subject, $message, $headers);
    }

    public function register($email, $username, $password)
    {
       try
       {
           $new_password = password_hash($password, PASSWORD_DEFAULT);
           $stmt = $this->db->prepare("INSERT INTO users(email,username,password)
                                                       VALUES(:email, :username, :password)");

           $stmt->bindparam(":email", $email);
           $stmt->bindparam(":username", $username);
           $stmt->bindparam(":password", $new_password);
           $stmt->execute();
           //$this->send_register_mail($email, $username);
           return $stmt;
       }
       catch(PDOException $e)
       {
           echo $e->getMessage();
       }
    }

    public function login($username, $password)
    {
       try
       {
          $stmt = $this->db->prepare("SELECT * FROM users WHERE username=:username LIMIT 1");
          $stmt->execute(array(':username'=>$username));
          $userRow = $stmt->fetch(PDO::FETCH_ASSOC);
          if($stmt->rowCount() > 0)
          {
             if(password_verify($password, $userRow['password']))
             {
                $_SESSION['user_session'] = $userRow['username'];
                $_SESSION['user_id'] = $userRow['id'];
                return true;
             }
             else
             {
                return false;
             }
          }
       }
       catch(PDOException $e)
       {
           echo $e->getMessage();
       }
   }	

   public function user_exist($email, $username)
   {
     try
       {
          $stmt = $this->db->prepare("SELECT * FROM users WHERE email=:email OR username=:username");
          $stmt->execute(array(':email'=>$email, ':username'=>$username));
          $userRow = $stmt->fetch(PDO::FETCH_ASSOC);
          if($stmt->rowCount() > 0)
          {
              return true;
          }
          else
          {
              return false;
          }
       }
       catch(PDOException $e)
       {
           echo $e->getMessage();
       }
          
   }

   public function get_username($id)
    { 
      try
      {
          $stmt = $this->db->prepare("SELECT username FROM users WHERE id=:id LIMIT 1");
          $stmt->bindparam(":id", $id);
          $stmt->execute();
          $user = $stmt->fetch();
          return $user['username'];
      }
      catch(PDOException $e)
      {
          echo $e->getMessage();
          return null;
      }
    }

   public function user_like_photo($id)
   {
      $stmt = $this->db->prepare("SELECT * FROM likes WHERE id_user=:id_user AND id_photo=:id_photo");
      $stmt->bindparam(":id_user", $_SESSION['user_id']);
      $stmt->bindparam(":id_photo", $id);
      $stmt->execute();
      if ($stmt->rowCount() > 0)
          return true;
      else
          return false;
   }

   public function time_diff($time)
  {
    $oldDate = new DateTime($time);
    $currentDate =  new Datetime();
    $diff = $oldDate->diff($currentDate);
    $y = $diff->format('%y');
    $m = $diff->format('%m');
    $a = $diff->format('%a');
    $h = $diff->format('%h');
    $i = $diff->format('%i');
    $s = $diff->format('%s');
    if ($y)
      return $y == 1 ? $y . " year ago" : $y . " years ago";
    if ($m)
      return $m == 1 ? $m . " month ago" : $m . " months ago";
    if ($a)
      return $a == 1 ? $a . " day ago" : $a . " days ago";
    if ($h)
      return $h == 1 ? $h . " hour ago" : $h . " hours ago";
    if ($i)
      return $i == 1 ? $i . " minute ago" : $i . " minutes ago";
    if ($s)
      return $s == 1 ? $s . " second ago" : $s . " seconds ago";
  }

   public function is_loggedin()
   {
      if(isset($_SESSION['user_session']))
      {
         return true;
      }
      else
      {
        return false;
      }
   }

   public function redirect($url)
   {
       header("Location: $url");
   }

   public function logout()
   {
        session_destroy();
        unset($_SESSION['user_session']);
        return true;
   }
}
?>
