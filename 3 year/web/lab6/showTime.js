function displayTime() {
    var currentTime = new Date();
    var hours = currentTime.getHours();
    var minutes = currentTime.getMinutes();
    var seconds = currentTime.getSeconds();
    return "Текущее время: " + hours + ":" + minutes + ":" + seconds;
}

document.getElementById("showHourButton").addEventListener("click", function() {
    var currentTime = new Date();
    var hours = currentTime.getHours();
    alert("Текущее время (часы): " + hours);
});

document.getElementById("showMinuteButton").addEventListener("click", function() {
    var currentTime = new Date();
    var minutes = currentTime.getMinutes();
    alert("Текущее время (минуты): " + minutes);
});

document.getElementById("showSecondButton").addEventListener("click", function() {
    var currentTime = new Date();
    var seconds = currentTime.getSeconds();
    alert("Текущее время (секунды): " + seconds);
});

document.getElementById("showFullTimeButton").addEventListener("click", function() {
    var fullTime = displayTime();
    alert(fullTime);
});