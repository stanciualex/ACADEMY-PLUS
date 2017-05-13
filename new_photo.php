<?php

require_once 'config/setup.php';

$img = $_POST['img'];
$sticker = $_POST['sticker'];
$img = str_replace(' ', '+', $img);
$img = base64_decode($img);

$dest = imagecreatefromstring($img);
$src = imagecreatefrompng('src/' . $sticker . '.png');

imagealphablending($dest, true);
imagesavealpha($dest, true);

$diff = 0;
if ($sticker == "sunglasses")
  $diff = -37;
else if ($sticker == "hat")
  $diff = -82;
else if ($sticker == "emoji")
  $diff = -37;
else if ($sticker == "joint")
  $diff = 25;
else if ($sticker == "thuglife")
  $diff = -37;
else if ($sticker == "turban")
  $diff = -60;

$dest_x = imagesx($dest);
$dest_y = imagesy($dest);
$src_x = imagesx($src);
$src_y = imagesy($src);

imagecopy($dest, $src, $dest_x / 2 - $src_x / 2, $dest_y / 2 - $src_y / 2 + $diff, 0, 0, $src_x, $src_y);

ob_start();
imagepng($dest);
$image_blob = ob_get_clean();

imagedestroy($dest);
imagedestroy($src);


/*
  $image = imagecreatefromstring($img);
  if (!file_exists("img"))
    mkdir("img");
  $path = "img/" . uniqid() . ".png";
  imagepng($image, $path);

*/

  try
  {
      $stmt = $user->get_db()->prepare("INSERT INTO photos(id_user, src, date) VALUES(:id_user, :src, :date)");
      $date = date("Y-m-d H:i:s");
      $stmt->bindparam(":id_user", $_SESSION['user_id']);
      $stmt->bindparam(":src", $image_blob);
      $stmt->bindparam(":date", $date);
      $stmt->execute();

  }
   catch(PDOException $e)
   {
        echo $e->getMessage();
   }

?>