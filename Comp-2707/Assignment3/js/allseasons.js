function changepic() {
    const image = document.getElementById("season");
    image.src = "../pictures/" + document.getElementById("dropdown").value + ".jpg";
}