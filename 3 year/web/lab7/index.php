<head>
	<meta charset="UTF-8">
	<meta name="keywords" content="роботы, игрушки, робототехника, развлечения">
	<meta name="author" content="Демид Шумков">
	<meta name="description" content="Сайт о роботах игрушках">
	<title>Роботы игрушки</title>
	<link rel="stylesheet" href="styles.css">
	<style>
		#footer{
			padding: 10px;
			text-align: center;
		}
	</style>
</head>
<body>
	<div id="header" style="text-align: center;">
		<h1>Роботы игрушки</h1>
		<h2>Главная страница</h2>
		<img src="logo.png" alt="Картинка сайта">
	</div>
	<hr>
	<div id="info">
		<h1>Приветствие</h1>
		<p>Добро пожаловать на наш сайт о захватывающем мире роботов-игрушек! Мы - команда энтузиастов, которые увлечены миром технологий и фантазии. Наш сайт представляет собой уникальное место, где вы сможете погрузиться в захватывающий мир робототехники и развлечений.</p>
		<p>Роботы-игрушки уже давно не являются просто детскими игрушками. Они стали настоящими технологическими чудесами, способными удивить и вдохновить как детей, так и взрослых. На нашем сайте вы найдете разнообразные модели роботов-игрушек: от умных роботов, способных обучаться и взаимодействовать с окружающей средой, до забавных роботов-подружек для самых маленьких.</p>
		<p>На нашем сайте вы найдете обзоры самых популярных моделей роботов-игрушек, а также советы по выбору и использованию этих удивительных устройств. Мы регулярно обновляем информацию о новинках рынка и делимся интересными фактами и идеями по использованию роботов-игрушек в повседневной жизни.</p>
		<p>Не упустите шанс окунуться в увлекательный мир роботов-игрушек вместе с нами! Приглашаем вас и ваших детей на наш сайт, где каждый найдет что-то увлекательное и вдохновляющее!</p>
	</div>
	<hr>
	<div id="menu">
		<h2>Навигация по страницам</h2>
		<div id="links">
			<a href="forma.htm">Добавление</a> |
			<a href="sources.html">Использованные источники</a>
		</div>
		<hr>
		<h2>Ассортимент роботов игрушек</h2>
		<div id="table">
		<select id="manufacturerSelect" onchange="loadModels()">
			<option value="">Выберите производителя</option>
			<?php

        $servername = "localhost"; 
        $username = "root"; 
        $password = "";
        $dbname = "test"; 

        $conn = new mysqli($servername, $username, $password, $dbname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
		
        $sql = "SELECT name FROM manufacturers";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "<option value='" . $row["name"] . "'>" . $row["name"] . "</option>";
            }
        }
        ?>
		</select>
		<table border="1" style="border: 2px solid red;">
        <caption>Характеристики роботов-игрушек</caption>
        <colgroup>
            <col style="background-color: PaleGoldenrod;">
            <col span="2" style="background-color: PeachPuff;">
            <col style="background-color: PaleGoldenrod;">
        </colgroup>
        <thead>
            <tr>
                <th>Название робота</th>
				<th>Производитель</th>
                <th>Цена</th>
                <th>Описание</th>
            </tr>
        </thead>
        <tfoot>
            <tr>
                <td colspan="4">Ассортимент будет пополняться</td>
            </tr>
        </tfoot>
        <tbody id="toyTableBody">
            <?php
            $servername = "localhost";
            $username = "root"; 
            $password = ""; 
            $dbname = "test";

            $conn = new mysqli($servername, $username, $password, $dbname);
			
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $sql = "SELECT toys.name AS toy_name, manufacturers.name AS manufacturer_name, toys.price, toys.description
			FROM toys
			INNER JOIN manufacturers ON toys.manufacturer_id = manufacturers.id";
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
                echo "<tr><td colspan='3'>Нет данных</td></tr>";
            }
					$conn->close();
					?>
				</tbody>
			</table>
		</div>
		<hr>
		<h2>Вам будет интересно</h2>
		<div id="list">
			<ol type="I">
				<li>Примеры использования роботов-игрушек в различных сферах:
					<ol>
						<li>Образование и наука</li>
						<li>Развлечение и развлекательная индустрия</li>
					</ol>
				</li>
				<li>Роль роботов-игрушек в развитии детей:
					<ol>
						<li>Развитие творческого мышления</li>
						<li>Обучение основам программирования и инженерии</li>
					</ol>
				</li>
				<li>Технологии в робототехнике:
					<ol>
						<li>Использование искусственного интеллекта в роботах-игрушках</li>
						<li>Распознавание голоса и лица</li>
						<li>Сенсоры и датчики в роботах-игрушках</li>
					</ol>
				</li>
			</ol>
		</div>
	</div>
	<hr>
	<div id="footer" class="gradient">
		<p>2024 Роботы игрушки. </p>
	</div>
    <button id="authorInfoButton">Показать информацию об авторе</button>
	<button id="showFullTimeButton">Показать полное текущее время</button>
    <button id="showHourButton">Показать текущее время (часы)</button>
	<button id="showMinuteButton">Показать текущее время (минуты)</button>
	<button id="showSecondButton">Показать текущее время (секунды)</button>
    <button id="changeColorButton">Изменить цвет</button>
    <button id="changeSizeButton">Изменить размер</button>
	<button id="addEmptyRowButton">Добавить строку в таблицу</button>
	
    <script src="authorInfo.js"></script>
	<script src="tableButton.js"></script>
    <script src="showTime.js"></script>
    <script src="changeColor.js"></script>
    <script src="changeSize.js"></script>
	<script>
    function loadModels() {
        var manufacturer = document.getElementById("manufacturerSelect").value;
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("toyTableBody").innerHTML = this.responseText;
            }
        };
        xhttp.open("GET", "load_models.php?manufacturer=" + manufacturer, true);
        xhttp.send();
    }
</script>

</body>
</html>
