<html>
  
  <head>
    <title>IoT ECT</title>
  </head>
  <body>
    <?php
      $servername = "localhost";
      $username = "id8913225_silvabrunu";
      $password = "senha123";
      $dbname = "id8913225_iot";

      // Create connection
      $conn = new mysqli($servername, $username, $password,$dbname);

      // Check connection
      if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
      } 

      $sql = "SELECT * FROM sensorLux";
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
    
    <div style="width:75%;">
        <canvas id="canvas"></canvas>
    </div>
    
    
     <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/709921/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
     <br>
    <a href="grafico.html">Grafico - Graph.js</a></br>
    <a href="index.html">Voltar</a>
    
    
  </body>
</html>