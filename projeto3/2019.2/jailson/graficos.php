<!DOCTYPE html>
<html>
    <head>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.4.0/Chart.min.js"></script>
    <title>Internet das Coisas</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
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
        url: 'https://iotufrn2019.000webhostapp.com/api.php/lux_sensor',
        dataType: 'json',
      }).done(function (results) {
        console.log(results);
        // Split timestamp and data into separate arrays
        var labels = [], data=[];
        results.forEach(function(packet) {
          labels.push(new Date(packet.data).formatMMDDYYYY());
          data.push(parseFloat(packet.lux));
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