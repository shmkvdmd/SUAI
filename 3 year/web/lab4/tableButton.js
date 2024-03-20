document.getElementById("addEmptyRowButton").addEventListener("click", function() {
    var table = document.querySelector("#table table tbody");
    var newRow = table.insertRow();
    for (var i = 0; i < 4; i++) {
        newRow.insertCell();
    }
});
