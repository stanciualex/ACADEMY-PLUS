<?php

require_once 'config/setup.php';

$error = 0;

if ($user->is_loggedin())
{
	$user->redirect("index.php?error=1");
}

if (isset($_POST['submit']))
{
	if ($user->login($_POST['username'], $_POST['password']))
		$user->redirect("index.php");
	else
		$error = 1;
}

?>

<!DOCTYPE html>
<html>
<head>
<title>Login - Camagru</title>
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
			<input type="text" name="username" placeholder="Username"/>
			<input type="password" name="password" placeholder="Password"/>
			<input type="submit" name="submit" value="login" class="button"/>
			<p class="message">Not registered? <a href="register.php">Create an account</a></p>
			<p class="message">Forgot password? <a href="#">Click here</a></p>
			<?php if ($error) echo "<p class='error'>Invalid username or password!</p>"; ?>
			<?php if ($user->is_loggedin()) echo "<p class='error'>You are already logged in!</p>"; ?>
    	</form>
  	</div>
</div>

<footer>
	<p>2017 &copy Created by astanciu</p>
</footer>


</body>
</html>