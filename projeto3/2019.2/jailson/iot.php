<html>
  <head>
    <title>IoT ECT</title>
  </head>
  <body>
    <?php
      $servername = "localhost";
      $username = "id10448610_admin";
      $password = "admin";
      $dbname = "id10448610_iot";
 
      // Create connection
      $conn = new mysqli($servername, $username, $password, $dbname);
 
      // Check connection
      if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
      }
 
      $sql = "SELECT * FROM lux_sensor";
      $result = $conn->query($sql);
 
      if (!$result) {
        trigger_error('Invalid query: ' . $conn->error);
      }

      if ($result->num_rows > 0) {
          // output data of each row
          while($row = $result->fetch_assoc()) {
              echo "Lux: " . $row["lux"]." Data:". $row["data"]."<br>";
          }
      } else {
          echo "0 results";
      }
      $conn->close();
    ?>
    <p><a href="thingspeak.html">Grafico - Thingspeak</a></p>
    <p><a href="grafico.html">Grafico - Graph.js</a></p>
    <p><a href="index.html">Voltar</a></p>  
  </body>
</html>