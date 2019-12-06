Projeto 3, o intuito desse projeto é gerar um gráfico, utilizando o sensor de luminosidade do celular, porém, diferente do projeto 2, sem a dependência dos gráficos do ThingSpeak. 

Primeiro criamos uma conta no site WebHost, logo após um banco de dados no mesmo. Com o nome iot, o bando gerado foi id10512316_iot. O banco de dados ficava responsável por receber e armazenar os dados do sensor.
Depois foram criados 3 códigos no WebHost, que seriam necessário para o objetivo final, que é gerar um gráfico que mostraria os valores recebidos e armazenados na tabela. Que são eles o iot.php , api.php, graficos.php, os códigos estão logo abaixo, e todos foram disponibilizados pelo professor. Pequenas mudanças foram feitas neles, como Nome do banco e senha.

- O que é um API ?
  API é o acrônimo de Application Programming Interface ou, em português, Interface de Programação de Aplicativos. API é o conjunto de padrões de programação que permite a construção de aplicativos e a sua utilização de maneira não tão evidente para os usuários.
	




 - Codido do iot.php

```php
<html>
 
  <head>
    <title>IoT ECT</title>
  </head>
  <body>
    <?php
      $servername = "localhost";
      $username = "id10512316_iot";
      $password = "12345";
      $dbname = "id10512316_iot";
 
      // Create connection
      $conn = new mysqli($servername, $username, $password,$dbname);
 
      // Check connection
      if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
      }
 
      $sql = "SELECT * FROM lux_sensor";
      $result = $conn->query($sql);
 
      if ($result->num_rows > 0) {
          // output data of each row
          while($row = $result->fetch_assoc()) {
              echo "Lux: " . $row["valor"]." Data:". $row["data"]."<br>";
          }
      } else {
          echo "0 results";
      }
      $conn->close();
    ?>
    <a href="thingspeak.html">Grafico - Thingspeak</a></br>
    <a href="grafico.html">Grafico - Graph.js</a></br>
    <a href="index.html">Voltar</a>
   
  </body>
</html>
```



 -Codigo do api.php
 
```php
<?php
error_reporting(~E_WARNING & ~E_NOTICE);
 
$servername = "localhost";
$username = "id10512316_iot";
$password = "12345";
$dbname = "id10512316_iot";
 
// get the HTTP method, path and body of the request
$method = $_SERVER['REQUEST_METHOD'];
$request = explode('/', trim($_SERVER['PATH_INFO'],'/'));
$input = json_decode(file_get_contents('php://input'),true);
 
// connect to the mysql database
$link = mysqli_connect($servername, $username, $password, $dbname);
mysqli_set_charset($link,'utf8');
 
// retrieve the table and key from the path
$table = preg_replace('/[^a-z0-9_]+/i','',array_shift($request));
$key = array_shift($request)+0;
 
// escape the columns and values from the input object
$columns = preg_replace('/[^a-z0-9_]+/i','',array_keys($input));
$values = array_map(function ($value) use ($link) {
  if ($value===null) return null;
  return mysqli_real_escape_string($link,(string)$value);
},array_values($input));
 
// build the SET part of the SQL command
$set = '';
for ($i=0;$i<count($columns);$i++) {
  $set.=($i>0?',':'').'`'.$columns[$i].'`=';
  $set.=($values[$i]===null?'NULL':'"'.$values[$i].'"');
}
 
// create SQL based on HTTP method
switch ($method) {
  case 'GET':
    $sql = "select * from `$table`".($key?" WHERE id=$key":''); break;
  case 'PUT':
    $sql = "update `$table` set $set where id=$key"; break;
  case 'POST':
    $sql = "insert into `$table` set $set"; break;
  case 'DELETE':
    $sql = "delete `$table` where id=$key"; break;
}
 
// excecute SQL statement
$result = mysqli_query($link,$sql);
 
// die if SQL statement failed
if (!$result) {
  http_response_code(404);
  die(mysqli_error());
}
 
// print results, insert id or affected row count
if ($method == 'GET') {
  if (!$key) echo '[';
  for ($i=0;$i<mysqli_num_rows($result);$i++) {
    echo ($i>0?',':'').json_encode(mysqli_fetch_object($result));
  }
  if (!$key) echo ']';
} elseif ($method == 'POST') {
  echo mysqli_insert_id($link);
} else {
  echo mysqli_affected_rows($link);
}
 
// close mysql connection
mysqli_close($link);
```


 -codigo do graficos.php

```php
<!DOCTYPE html>
<html>
    <head>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.4.0/Chart.min.js"></script>
  </head>
  <body>
    <canvas id="myLineChart" width="740" height="200"></canvas>
    <script>
    function drawLineChart() {
 
      // Add a helper to format timestamp data
      Date.prototype.formatMMDDYYYY = function() {
          return (this.getMonth() + 1) +
          "/" +  this.getDate() +
          "/" +  this.getFullYear();
      }
 
      var jsonData = $.ajax({
        url: 'https://matheuscavalcante.000webhostapp.com/api.php/lux_sensor',
        dataType: 'json',
      }).done(function (results) {
        console.log(results);
        // Split timestamp and data into separate arrays
        var labels = [], data=[];
        results.forEach(function(packet) {
          labels.push(new Date(packet.data).formatMMDDYYYY());
          data.push(parseFloat(packet.valor));
        });
 
        // Create the chart.js data structure using \'labels\' and \'data\'
        var tempData = {
          labels : labels,
          datasets : [{
              label                 : "Lux",
              fillColor             : "rgba(151,187,205,0.2)",
              strokeColor           : "rgba(151,187,205,1)",
              pointColor            : "rgba(151,187,205,1)",
              pointStrokeColor      : "#fff",
              pointHighlightFill    : "#fff",
              pointHighlightStroke  : "rgba(151,187,205,1)",
              data                  : data
          }]
        };
 
        // Get the context of the canvas element we want to select
        var ctx = document.getElementById("myLineChart").getContext("2d");
 
        var myLineChart = new Chart(ctx, {
          type: 'line',
          data: tempData
        });
      });
    }
    drawLineChart();
  </script>
  </body>
</html>
```
