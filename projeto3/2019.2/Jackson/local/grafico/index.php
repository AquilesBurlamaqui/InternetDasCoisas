<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Resume of LUX values</title>
  <link rel="stylesheet" href="/static/bootstrap.min.css">
  <link rel="stylesheet" href="/static/style.cover.css">
  <script src="/static/jquery.min.js"></script>
  <script src="/static/charts.min.js"></script>
</head>
<body class="text-center">

  <div class="cover-container d-flex w-100 h-100 p-3 mx-auto flex-column">

    <header class="masthead mb-auto">
      <div class="inner">
        <h3 class="masthead-brand">IoT</h3>
        <nav class="nav nav-masthead justify-content-center">
          <a class="nav-link" href="/local">Início</a>
          <a class="nav-link" href="/local/thingspeak">Grafico - Thingspeak</a></a>
          <a class="nav-link active" href="/local/grafico">Grafico - Graph.js</a>
        </nav>
      </div>
    </header>

    <main role="main" class="inner cover data-box">
      <div class="bg-white h-100 w-100 rounded">
        <canvas id="myLineChart" style="width: 100%; height: 95%; padding: 10px;"></canvas>
      </div>
    </main>

    <footer class="mastfoot mt-auto">
      <small>
        <div class="">
          <p>Cover template for <a href="https://getbootstrap.com/">Bootstrap</a>, by <a href="https://twitter.com/mdo">@mdo</a>.</p>
        </div>
      </small>
    </footer>

  </div>

  <script>
    function drawLineChart() {

      Date.prototype.formatMMDDYYYY = function() {
          return (this.getMonth() + 1) +
          "/" +  this.getDate() +
          "/" +  this.getFullYear();
      }

      $.ajax({
        url: '/local/api/get/'
      })
      .done(function (results) {
        console.log(results);

        var labels = [], data=[];
        results.forEach(function(packet) {
          labels.push(new Date(packet.date).toLocaleString());
          data.push(parseFloat(packet.value));
        });

        var tempData = {
          labels : labels,
          datasets : [{
              label                 : "Lux",
              fillColor             : "rgb(100,100,100)",
              strokeColor           : "rgb(100,100,100)",
              pointColor            : "rgb(100,100,100)",
              pointStrokeColor      : "#fff",
              pointHighlightFill    : "#fff",
              pointHighlightStroke  : "rgb(100,100,100)",
              data                  : data
          }]
        };

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