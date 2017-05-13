<?php

require_once 'config/setup.php';

if (!isset($_GET['token']))
	$user->redirect("index.php?error=2");

$user->logout();
try {
	$stmt = $user->get_db()->prepare("UPDATE users SET token = NULL WHERE token=:token");
	$stmt->bindparam(":token", $_GET['token']);
	$stmt->execute();
}
catch(PDOException $e)
{
    echo $e->getMessage();
}

$user->redirect("login.php?success=2");

?>