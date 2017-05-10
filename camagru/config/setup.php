<?php

date_default_timezone_set('Europe/Bucharest');

session_start();

include ('database.php');
try {
	$DB_HANDLE = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$DB_HANDLE->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE IF NOT EXISTS camagru";
	$DB_HANDLE->exec($sql);
	$sql = "USE camagru;
		CREATE TABLE `camagru`.`users` ( `id` INT NOT NULL AUTO_INCREMENT , `email` TEXT NOT NULL , `username` TEXT NOT NULL , `password` TEXT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;
		CREATE TABLE `camagru`.`photos` ( `id_photo` INT NOT NULL AUTO_INCREMENT , `id_user` INT NOT NULL , `src` LONGBLOB NOT NULL , `date` DATETIME NOT NULL , `likes` INT NOT NULL DEFAULT '0' , PRIMARY KEY (`id_photo`)) ENGINE = InnoDB;
		CREATE TABLE `camagru`.`comments` ( `id_comment` INT NOT NULL AUTO_INCREMENT , `id_user` INT NOT NULL , `id_photo` INT NOT NULL , `comment` TEXT NOT NULL , PRIMARY KEY (`id_comment`)) ENGINE = InnoDB;
		CREATE TABLE `camagru`.`likes` ( `id_like` INT NOT NULL AUTO_INCREMENT , `id_user` INT NOT NULL , `id_photo` INT NOT NULL , PRIMARY KEY (`id_like`)) ENGINE = InnoDB;
	";
	$DB_HANDLE->exec($sql);
}
catch (PDOExceptions $e) {
	echo "Connection failed: " . $e->getMessage();
	die();
}

require_once 'User.Class.php';
$user = new User($DB_HANDLE);

?>