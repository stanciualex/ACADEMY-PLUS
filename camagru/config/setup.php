<?php

date_default_timezone_set('Europe/Bucharest');

session_start();

include ('database.php');
try {
	$DB_HANDLE = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$DB_HANDLE->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch (PDOExceptions $e) {
	echo "Connection failed: " . $e->getMessage();
	die();
}

require_once 'User.Class.php';
$user = new User($DB_HANDLE);

?>