<?php

require_once('config/setup.php');

if (!$user->is_loggedin() || !isset($_GET['id']))
{
	$user->redirect("index.php?error=3");
}

  try
  {
      $stmt = $user->get_db()->prepare("SELECT id_user FROM photos WHERE id_photo=:id_photo LIMIT 1");
      $stmt->bindparam(":id_photo", $_GET['id']);
      $stmt->execute();
      $img = $stmt->fetch(PDO::FETCH_ASSOC);
      if ($img['id_user'] == $_SESSION['user_id'])
      {
      	$stmt = $user->get_db()->prepare("DELETE FROM photos WHERE id_photo=" . $_GET['id']);
      	$stmt->execute();
      	$user->redirect("photo.php");
      }
      else
      	echo "nem tiit";

  }
   catch(PDOException $e)
   {
        echo $e->getMessage();
   }

?>