var side = document.getElementsByClassName("side");
console.log(side);

window.onload=function(){
    var input = document.getElementById('inputphoto');
    input.addEventListener('change', handleFiles);
    function handleFiles(e) {
        var canvas = document.getElementById('canvas');
        var ctx = canvas.getContext('2d');
        var img = new Image;
        img.src = URL.createObjectURL(e.target.files[0]);
        img.onload = function() {
        	if (img.width > 500 || img.height > 500)
        		alert("The image is too big! Maximum accepted resolution is 500x500.");
        	else
        	{
	            if (img.width > window.innerWidth / 3)
	                canvas.width = window.innerWidth / 3;
	            if (img.height > window.innerHeight / 3)
	                canvas.height = window.innerHeight / 3;
	            takePhoto();
	            ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
        	}
        }
    }
}