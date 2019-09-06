<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Resume of LUX values</title>
  <link rel="stylesheet" href="/static/bootstrap.min.css">
  <link rel="stylesheet" href="/static/style.cover.css">
</head>
<body class="text-center">

  <div class="cover-container d-flex w-100 h-100 p-3 mx-auto flex-column">

    <header class="masthead mb-auto">
      <div class="inner">
        <h3 class="masthead-brand">IoT</h3>
        <nav class="nav nav-masthead justify-content-center">
          <a class="nav-link active" href="/local">Início</a>
          <a class="nav-link" href="/local/thingspeak">Grafico - Thingspeak</a></a>
          <a class="nav-link" href="/local/grafico">Grafico - Graph.js</a>
        </nav>
      </div>
    </header>

    <main role="main" class="inner cover data-box">
    <?php
      $servername = "sql107.epizy.com";
      $username = "epiz_24386991";
      $password = "1Zdn4sWlZxZ";
      $dbname = "epiz_24386991_db_iot";
 
      $conn = new mysqli($servername, $username, $password,$dbname);
 
      if ($conn->connect_error) {
          echo "<p class='lead mt-3'><span class='btn btn-light'><b>Connection failed</b></span></p> " . $conn->connect_error;
      } else {

        $sql = "SELECT * FROM lux_sensor;";

        $result = $conn->query($sql);
  
        if ($result->num_rows > 0) {

            while($row = $result->fetch_assoc()) {
              ?>
              <div class="alert alert-light text-dark" role="alert">
                <small>Lux: </small><b><?=$row["value"]?></b><small class="ml-4">Data: </small><b><?=$row["date"]?></b>
              </div>
              <?php
            }
            
        } else {
          ?>
            <p class="lead">
              <span class="btn btn-light"><b>0 Results</b></span>
            </p>
          <?php
        }

        $conn->close();
      }
    ?>
        
    </main>

    <footer class="mastfoot mt-auto">
      <small>
        <div class="">
          <p>Cover template for <a href="https://getbootstrap.com/">Bootstrap</a>, by <a href="https://twitter.com/mdo">@mdo</a>.</p>
        </div>
      </small>
    </footer>

  </div>

</body>

</html>