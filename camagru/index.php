<?php

require_once('config/setup.php');

if (isset($_GET['error']))
	$error = $_GET['error'];
else
	$error = 0;

$user_msg = "You are not logged in.";

if ($user->is_loggedin())
{
	$user_msg = "Welcome, " . $_SESSION['user_session'] . "!";
}

if ($error == 1)
	$error_msg = "You are already logged in!";
else if ($error == 2)
	$error_msg = "You can't acces this page, you are not logged in!";
else if ($error == 3)
	$error_msg = "Acces denied!";
else if ($error == 4)
	$error_msg = "You account is not confirmed! Please check your mail inbox.";

if (isset($_GET['page']))
	$page = $_GET['page'];
else
	$page = 1;

$stmt = $user->get_db()->prepare("SELECT COUNT(*) AS total FROM photos");
$stmt->execute();
$total = $stmt->fetch();
$total = $total['total'];

try
{
   	$stmt = $user->get_db()->prepare("SELECT * FROM photos ORDER BY date DESC LIMIT " . (($page - 1) * 10) . ", 10");
    $stmt->execute();
    $imgs = $stmt->fetchAll();

    $stmt = $user->get_db()->prepare("SELECT * FROM comments");
    $stmt->execute();
    $comments = $stmt->fetchAll();
}
catch(PDOException $e)
{
    echo $e->getMessage();
}


?>
<!DOCTYPE html>
<html>
<head>
<title>Camagru</title>
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
	  <li><a class="active" href="index.php">Gallery</a></li>
	  <li><a href="photo.php">Photos</a></li>
	  <?php 
	  if ($user->is_loggedin())
	  	echo '<li><a href="logout.php">Logout</a></li>';
	  else
	  	echo '<li><a href="login.php">Login</a></li>';
	  ?>
	  <li class="user-msg"><?php echo $user_msg; ?></li>
	</div>
	</ul>
</header>

<?php
	echo '<div class="next-div">';
	if ($page > 1 && $total > 40)
		echo '<a href="index.php?page=' . ($page - 1) . '" class="type2">&#8249;</a>';
	if ($total)
		echo '<a href="index.php?page=1" class="type1">1</a>';
	if ($total > 10)
		echo '<a href="index.php?page=2" class="type1">2</a>';
	if ($total > 20)
		echo '<a href="index.php?page=3" class="type1">3</a>';
	if ($total > 40)
	{
		echo '<a href="#" class="dots">...</a>';
		echo '<a href="index.php?page=' . (floor($total / 10) + 1) . '" class="type1">' . (floor($total / 10) + 1) . '</a>';
	}
	else if ($total > 30)
		echo '<a href="index.php?page=4" class="type1">4</a>';
	if ($page < floor($total / 10) + 1 && $total > 40)
		echo '<a href="index.php?page=' . ($page + 1) . '" class="type2">&#8250;</a>';
	echo '</div>';
?>

<?php
if ($error)
	echo '<div class="error-msg" id="error-msg">
	<img class="close" src="src/close.png" height="2%" width="2%" onClick="remove_error_msg()">
	<img src="src/error.png" height="8%" width="8%">
	<p>' . $error_msg . '</p>
</div>';
?>

<?php
foreach ($imgs as $img)
{
	echo '<div class="gallery-post">';
	echo '<ul>';
		echo '<li>' . $user->get_username($img['id_user']) . '</li>';
		echo '<li>' . $user->time_diff($img['date']) . '</li>';
	echo '</ul>';
	echo '<div class="pic">';
		echo '<img src="data:image/jpg;base64,'. base64_encode($img['src']) .'"/>';
	echo '</div>';
	echo '<p>' . $img['likes'] . ' likes</p>';
	if ($user->is_loggedin())
	{
		if ($user->user_like_photo($img['id_photo']))
			echo '<p><a href="like.php?id_photo=' . $img['id_photo'] . '&action=down&page=' . $page . '">I don\'t like this post anymore</a></p>';
		else
			echo '<p><a href="like.php?id_photo=' . $img['id_photo'] . '&action=up&page=' . $page . '">I like this post</a></p>';
	}
	echo '<hr>';
	
	foreach ($comments as $comm)
	{
		if ($comm['id_photo'] == $img['id_photo'])
		{
			echo '<p id="comment">';
			echo '<b>' . $user->get_username($comm['id_user']) . '</b>: ';
			echo $comm['comment'];
			if ($user->is_loggedin() && $comm['id_user'] == $_SESSION['user_id'])
				echo ' <a href="remove_comment.php?id=' . $comm['id_comment'] . '&page=' . $page . '"><img id="comment-remove" src="src/close.png" height="2%" width="2%"></a>';
			echo '</p>';
		}
	}
	//echo '<p><b>Cristiii:</b> frumoasa poza! :)</p>';
	if ($user->is_loggedin())
		echo '<form method="POST" action="new_comment.php?id_photo=' . $img['id_photo'] . '&page=' . $page . '">
		<input class="comment-input" type="text" name="comment" placeholder="Leave a comment...">
	</form>';
	echo '</div>';
}

?>

<?php
	echo '<div class="next-div">';
	if ($page > 1 && $total > 40)
		echo '<a href="index.php?page=' . ($page - 1) . '" class="type2">&#8249;</a>';
	if ($total)
		echo '<a href="index.php?page=1" class="type1">1</a>';
	if ($total > 10)
		echo '<a href="index.php?page=2" class="type1">2</a>';
	if ($total > 20)
		echo '<a href="index.php?page=3" class="type1">3</a>';
	if ($total > 40)
	{
		echo '<a href="#" class="dots">...</a>';
		echo '<a href="index.php?page=' . (floor($total / 10) + 1) . '" class="type1">' . (floor($total / 10) + 1) . '</a>';
	}
	else if ($total > 30)
		echo '<a href="index.php?page=4" class="type1">4</a>';
	if ($page < floor($total / 10) + 1 && $total > 40)
		echo '<a href="index.php?page=' . ($page + 1) . '" class="type2">&#8250;</a>';
	echo '</div>';
?>

<!--
<div class="gallery-post">
	<ul>
		<li>Author</li>
		<li>Date</li>
	</ul>
	<div class="pic">
		<img src="img/590220534ee2f.png">
	</div>
	<p>123 likes</p>
	<p id="like-btn">I like this post</p>
	<hr>
	<p><b>Cristiii:</b> frumoasa poza! :)</p>
	<p><b>Alunela:</b> Wow, ce magnific!</p>
	<p><b>Ionica:</b> ba pula, cand imi dai banii aia fututi mortii matii</p>
	<form method="post" action="index.php">
		<input class="comment-input" type="text" name="comment" placeholder="Leave a comment...">
	</form>
</div>
-->

<footer>
	<p>2017 &copy Created by astanciu</p>
</footer>

</body>
</html>