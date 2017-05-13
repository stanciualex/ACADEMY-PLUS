<?php

require_once 'config/setup.php';

$error = 0;

if ($user->is_loggedin())
{
	$user->redirect("index.php?error=1");
}

if (isset($_POST['submit']))
{
	try {
		$stmt = $user->get_db()->prepare("SELECT * FROM users WHERE email=:email LIMIT 1");
		$stmt->bindparam(":email", $_POST['email']);
		$stmt->execute();
        if($stmt->rowCount() > 0)
        {
        	$user->new_password($_POST['email']);
        	$user->redirect("login.php");
        }
        else
        	$error = 1;
	}
	catch(PDOException $e)
    {
           echo $e->getMessage();
    }
}

?>

<!DOCTYPE html>
<html>
<head>
<title>New password - Camagru</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
<script src="js/script.js"></script>
</head>
<body>

<header>
	<div class="left">
	  <li><a class="logo" href="index.php">Camagru</a></li>
	</div>
	<ul>
	  <div class="right">
	  <li><a href="index.php">Gallery</a></li>
	  <li><a href="photo.php">Photos</a></li>
	  <?php 
	  if ($user->is_loggedin())
	  	echo '<li><a class="active" href="logout.php">Logout</a></li>';
	  else
	  	echo '<li><a class="active" href="login.php">Login</a></li>';
	  ?>
	  <li class="user-msg">You are not logged in.</li>
	</div>
	</ul>
</header>


<div class="login-page">
	<div class="form">
		<form method="post" class="login-form">
			<input type="text" name="email" placeholder="Email" required/>
			<input type="submit" name="submit" value="send" class="button"/>
			<?php if ($error) echo "<p class='error'>This email does not exist!</p>"; ?>
    	</form>
  	</div>
</div>

<footer>
	<p>2017 &copy Created by astanciu</p>
</footer>


</body>
</html>