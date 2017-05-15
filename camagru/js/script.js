function getBottom(sticker)
{
	if (sticker == "sunglasses")
		return "75px";
	else if (sticker == "hat")
		return "165px";
	else if (sticker == "emoji")
		return "75px";
	else if (sticker == "joint")
		return "-50px";
	else if (sticker == "thuglife")
		return "75px";
	else if (sticker == "turban")
		return "120px";
	return null;
}

function selectChanged() {
	
	var select = document.getElementById("select").value;
	var btn = document.getElementById("startbutton");
	var upl = document.getElementById("inputphoto");
	var sticker = document.getElementById("sticker");
	var preview = document.getElementById("preview");
	var	path = "src/";

	if (select == "default")
	{
		btn.disabled = true;
		upl.disabled = true;
		path = "";
		bottom_diff = 0;
		left_diff = 0;
	}
	else
	{
		btn.disabled = false;
		upl.disabled = false;
		path += select;
		path += ".png";
		sticker.style.bottom = getBottom(select);
	}
	sticker.src = path;
}

function newPhoto()
{
	var canvas = document.getElementById("canvas");
	var img    = canvas.toDataURL("image/png");
	var sticker = document.getElementById("select").value;
	var ajax = new XMLHttpRequest();

	ajax.open("POST", 'new_photo.php', true);
	ajax.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	ajax.send("img=" + img.split(',')[1] + "&sticker=" + sticker);
	setTimeout("location.href = 'photo.php';",250);
}

function takePhoto() 
{
	var sticker = document.getElementById("sticker");
	var preview = document.getElementById("preview");
	var save = document.getElementById("save")

	preview.src = sticker.src;
	preview.style.bottom = sticker.style.bottom;
	save.disabled = false;
}

function remove_error_msg()
{
	document.getElementById("error-msg").remove();
}