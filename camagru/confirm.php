<?php

require_once 'config/setup.php';

if (!isset($_GET['token']))
	$user->redirect("index.php?error=2");

try {
	$stmt = $user->get_db()->prepare("UPDATE users SET token = null WHERE token=:token");
	$stmt->bindparam(":token", $_GET['token']);
	$stmt->execute();
}
catch(PDOException $e)
{
    echo $e->getMessage();
}

$user->redirect("login.php?success=2");

?>