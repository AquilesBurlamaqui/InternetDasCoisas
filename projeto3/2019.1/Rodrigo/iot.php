<html>
  
  <head>
    <title>IoT ECT</title>
  </head>
  <body>
    <?php
      $servername = "localhost";
      $username = "id9176393_rfazevedo";
      $password = "alicefz12";
      $dbname = "id9176393_rfazevedo";
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
