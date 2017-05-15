<?php

require_once('config/setup.php');

if (!$user->is_loggedin())
{
	$user->redirect("index.php?error=2");
}

if (!$user->is_activated())
	$user->redirect("index.php?error=4");

$user_msg = "You are not logged in.";

if ($user->is_loggedin())
{
	$user_msg = "Welcome, " . $_SESSION['user_session'] . "!";
}

 try
 {
    $stmt = $user->get_db()->prepare("SELECT id_photo, src, date FROM photos WHERE id_user=:id_user");
    $stmt->execute(array(':id_user'=>$_SESSION['user_id']));
    $imgs = $stmt->fetchAll();
}
 catch(PDOException $e)
 {
     echo $e->getMessage();
 }

?>
<!DOCTYPE html>
<html>
<head>
<title>Take a photo - Camagru</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
<script src="js/script.js"></script>
<script src="js/photo.js"></script>
<script src="js/input.js"></script>
</head>
<body>

<header>
	<div class="left">
	  <li><a class="logo" href="index.php">Camagru</a></li>
	</div>
	<ul>
	  <div class="right">
	  <li><a href="index.php">Gallery</a></li>
	  <li><a class="active" href="photo.php">Photos</a></li>
	  <?php 
	  if ($user->is_loggedin())
	  	echo '<li><a href="logout.php">Logout</a></li>';
	  else
	  	echo '<li><a href="login.php">Login</a></li>';
	  ?>
	  <li class="user-msg"><?php echo $user_msg; ?></li>
	</div>
	</ul>
</header>

<div class="photo-page">
	<div class="main">
		<table>
			<tr style="height: 50%;">
				<td>
					<div class="camera" style="min-height: 250px;">	
						<video id="video">Video stream not available.</video>
						<img id="sticker" src="" />
 					</div>
				</td>
				<td>
					<div class="output">	
    					<canvas id="canvas"></canvas>
    					<img id="preview"/>
  					</div>
				</td>
			</tr>
			<tr>
				<td>
					<ul>
					<li><input type="file" name="inputphoto" id="inputphoto" class="inputfile" accept="image/png" disabled />
						<label for="inputphoto" disabled>Upload photo</label>
						</li>
					<li><button id="startbutton" disabled onclick="takePhoto()">Take photo</button></li>
					</ul>
				</td>
				<td>
					<button id="save" onclick="newPhoto();" disabled>Save photo</button>
				</td>
			</tr>
			<tr>
				<td>
					<select onchange="selectChanged()" id="select">
						<option value="default">Select a sticker...</option>
  						<option value="sunglasses">Sunglasses</option>
  						<option value="hat">Hat</option>
  						<option value="emoji">Emoji</option>
  						<option value="joint">Joint</option>
  						<option value="thuglife">Thug Life Sunglasses</option>
  						<option value="turban">Turban</option>
					</select>
				</td>
				<td>
					<p>Note: Only <b>.png</b> formats are avilable for upload.</p>
				</td>
			</tr>
		</table>
	</div>

	<div id="side" class="side">
			<?php

				foreach ($imgs as $img)
				{
					echo '<div class="thumbnail">';
					echo '<ul>';
					echo '<li>' . $user->time_diff($img['date']) . '</li>';
					echo '<li><a href="remove_photo.php?id=' . $img['id_photo'] . '">remove</a></li>';
					echo '</ul>';
					echo '<img src="data:image/jpg;base64,'. base64_encode($img['src']) .'"/>';
					echo '<hr>';
					echo '</div>';
				}
			?>
	</div>
</div>


<footer>
	<p>2017 &copy Created by astanciu</p>
</footer>


</body>
</html>