<?php

require_once 'config/setup.php';

$error = 0;

if ($user->is_loggedin())
{
	$user->redirect("index.php?error=1");
}

if (isset($_POST['submit']))
{
	if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
 		$error = 1;
 	else if (!preg_match("/^[a-zA-Z0-9]*$/", $_POST['username']))
		$error = 2;
	else if (strlen($_POST['password']) < 8)
	 	$error = 3;
	else if ($user->user_exist($_POST['email'], $_POST['username']))
		$error = 4;
	else
	{
		$user->register($_POST['email'], $_POST['username'], $_POST['password']);
		$user->redirect("login.php");
	}
}

?>

<!DOCTYPE html>
<html>
<head>
<title>Register - Camagru</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
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
			<input type="text" name="username" placeholder="Username" required/>
			<input type="password" name="password" placeholder="Password" required/>
			<input type="submit" name="submit" value="register" class="button"/>
			<?php
				if ($error == 1) echo "<p class='error'>The email format is invalid!</p>";
				if ($error == 2) echo "<p class='error'>The username must contain only letters and numbers</p>";
				if ($error == 3) echo "<p class='error'>The password must contain at least 8 characters </p>";
				if ($error == 4) echo "<p class='error'>This email or username is already used!</p>";
				
			?>
    	</form>
  	</div>
</div>

<footer>
	<p>2017 &copy Created by astanciu</p>
</footer>


</body>
</html>