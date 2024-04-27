document.getElementById("changeSizeButton").addEventListener("click", function() {
    var logo = document.getElementById("header").getElementsByTagName("img")[0];
    logo.style.width = "100px";
    logo.style.height = "75px";
});
