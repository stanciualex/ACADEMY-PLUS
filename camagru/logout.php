<?php

require_once('config/setup.php');
$user->logout();
$user->redirect("index.php");

?>