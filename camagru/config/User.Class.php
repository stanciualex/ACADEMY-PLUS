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

    public function send_register_mail($email, $username, $token)
    {
        $url = "http://$_SERVER[HTTP_HOST]";
        $subject = "Welcome to Camagru!";
        $message = "Welcome, " . $username . "!\n\n";
        $message .= "We are happy to see you here. In order to confirm your account, please click on this link: " . $url . "/camagru/confirm.php?token=" . $token . "\n\n";
        //$message .= "We are happy to see you here. In order to confirm your account, please click on this link: http://google.com\n\n";
        $message .= "Have a nice day,\nCamagru team";
        $headers = 'From: astanciu@student.42.fr' . "\r\n" .
            'Reply-To: astanciu@student.42.fr' . "\r\n";

        mail($email, $subject, $message, $headers);
    }

    public function send_password_mail($email, $new_password, $username)
    {
        $subject = "Camagru - Password recovery";
        $message = "Hello, " . $username . "\n\n";
        $message .= "You have just requested a password recovery. You can find you new login data below.\n";
        $message .= "Username: " . $username . "\n";
        $message .= "Password: " . $new_password . "\n\n";
        $message .= "Have a nice day,\nCamagru team";
        $headers = 'From: astanciu@student.42.fr' . "\r\n" .
            'Reply-To: astanciu@student.42.fr' . "\r\n";

        mail($email, $subject, $message, $headers);
    }

    public function register($email, $username, $password)
    {
       try
       {
           $new_password = password_hash($password, PASSWORD_DEFAULT);
           $stmt = $this->db->prepare("INSERT INTO users(email,username,password,token)
                                                       VALUES(:email, :username, :password, :token)");

           $token = uniqid();
           $stmt->bindparam(":email", $email);
           $stmt->bindparam(":username", $username);
           $stmt->bindparam(":password", $new_password);
           $stmt->bindparam(":token", $token);
           $stmt->execute();
           $this->send_register_mail($email, $username, $token);
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

    public function get_username_by_email($email)
    { 
      try
      {
          $stmt = $this->db->prepare("SELECT username FROM users WHERE email=:email LIMIT 1");
          $stmt->bindparam(":email", $email);
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


   private function randomPassword() {
        $alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';
        $pass = array();
        $alphaLength = strlen($alphabet) - 1;
        for ($i = 0; $i < 8; $i++) {
            $n = rand(0, $alphaLength);
            $pass[] = $alphabet[$n];
        }
        return implode($pass); 
}

   public function new_password($email)
   {
      $new_password = $this->randomPassword();
      try {
        $stmt = $this->db->prepare("UPDATE users SET password=:new_password WHERE email=:email");
        $stmt->bindparam(":new_password", password_hash($new_password, PASSWORD_DEFAULT));
        $stmt->bindparam(":email", $email);
        $stmt->execute();
        $this->send_password_mail($email, $new_password, $this->get_username_by_email($email));
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

   public function is_activated()
   {
       $stmt = $this->db->prepare("SELECT token FROM users WHERE id=:id LIMIT 1");
       $stmt->bindparam(":id", $_SESSION['user_id']);
       $stmt->execute();
       $user = $stmt->fetch();
       if ($user['token'])
          return false;
       else
          return true;
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
