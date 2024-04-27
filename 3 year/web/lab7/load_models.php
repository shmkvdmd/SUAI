<?php

$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "test";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$manufacturer = $_GET['manufacturer'];

$sql = "SELECT toys.name AS toy_name, manufacturers.name AS manufacturer_name, toys.price, toys.description
        FROM toys
        INNER JOIN manufacturers ON toys.manufacturer_id = manufacturers.id
        WHERE manufacturers.name = '$manufacturer'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row["toy_name"] . "</td>";
        echo "<td>" . $row["manufacturer_name"] . "</td>";
        echo "<td>" . $row["price"] . "</td>";
        echo "<td>" . $row["description"] . "</td>";
        echo "</tr>";
    }
} else {
    echo "<tr><td colspan='4'>Нет данных</td></tr>";
}
$conn->close();
?>
