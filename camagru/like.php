<?php

require_once('config/setup.php');

$id_photo = $_GET['id_photo'];
$action = $_GET['action'];

if (!$user->is_loggedin() || !isset($_GET['id_photo']) || !isset($_POST['comment']))
{
	$user->redirect("index.php?error=3");
}

$value = 0;
if ($action == 'up')
	$value = 1;
if ($action == 'down')
	$value = -1;

try
{
 	$stmt = $user->get_db()->prepare("UPDATE photos SET likes = likes + " . $value . " WHERE id_photo=:id_photo");
	$stmt->bindparam(":id_photo", $id_photo);
  	$stmt->execute();

  	if ($action == 'up')
  	{
  		$stmt = $user->get_db()->prepare("INSERT INTO likes(id_user, id_photo) VALUES(:id_user, :id_photo)");
  		$stmt->bindparam(":id_user", $_SESSION['user_id']);
  		$stmt->bindparam(":id_photo", $id_photo);
  		$stmt->execute();
  	}
  	if ($action == 'down')
  	{
  		$stmt = $user->get_db()->prepare("DELETE FROM likes WHERE id_user=:id_user AND id_photo=:id_photo");
  		$stmt->bindparam(":id_user", $_SESSION['user_id']);
  		$stmt->bindparam(":id_photo", $id_photo);
      	$stmt->execute();
  	}

  	$user->redirect("index.php?page=" . $_GET['page']);
}
catch(PDOException $e)
{
    echo $e->getMessage();
}

?>