<?php

require_once('config/setup.php');

$id_comment = $_GET['id'];

if (!$user->is_loggedin() || !isset($_GET['id']))
{
	$user->redirect("index.php?error=3");
}

if (isset($_GET['page']))
	$page = $_GET['page'];
else
	$page = 1;

try
{
  	$stmt = $user->get_db()->prepare("DELETE FROM comments WHERE id_comment=:id_comment");
  	$stmt->bindparam(":id_comment", $id_comment);
    $stmt->execute();
  	$user->redirect("index.php?page=" . $page);
}
catch(PDOException $e)
{
    echo $e->getMessage();
}

?>