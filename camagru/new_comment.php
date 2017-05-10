<?php

require_once('config/setup.php');

if (!$user->is_loggedin() || !isset($_GET['id_photo']) || !isset($_POST['comment']))
{
	$user->redirect("index.php?error=3");
}

$id_photo = $_GET['id_photo'];
$comment = $_POST['comment'];
if (isset($_GET['page']))
	$page = $_GET['page'];
else
	$page = 1;


try
{
 	$stmt = $user->get_db()->prepare("INSERT INTO comments(id_photo, id_user, comment) VALUES(:id_photo, :id_user, :comment)");

 	$stmt->bindparam(":id_photo", $id_photo);
	$stmt->bindparam(":id_user", $_SESSION['user_id']);
  	$stmt->bindparam(":comment", $comment);
  	$stmt->execute();
  	$user->redirect("index.php?page=" . $page);
}
catch(PDOException $e)
{
    echo $e->getMessage();
}

?>