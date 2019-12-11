<!doctype html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <title>DashBoard - SENSOR LUX</title>

        <!-- Fonts -->
        <link href="https://fonts.googleapis.com/css?family=Nunito:200,600" rel="stylesheet">

        <!-- Styles -->
        <style>
            html, body {
                background-color: #fff;
                color: #636b6f;
                font-family: 'Nunito', sans-serif;
                font-weight: 200;
                height: 100vh;
                margin: 0;
            }

            .full-height {
                height: 100vh;
            }

            .flex-center {
                align-items: center;
                display: flex;
                justify-content: center;
            }

            .position-ref {
                position: relative;
            }

            .top-right {
                position: absolute;
                right: 10px;
                top: 18px;
            }

            .content {
                text-align: center;
            }

            .title {
                font-size: 84px;
            }

            .links > a {
                color: #636b6f;
                padding: 0 25px;
                font-size: 13px;
                font-weight: 600;
                letter-spacing: .1rem;
                text-decoration: none;
                text-transform: uppercase;
            }

            .m-b-md {
                margin-bottom: 30px;
            }
        </style>

        <!-- Ícones -->
        <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">
        <script defer src="https://use.fontawesome.com/releases/v5.8.1/js/all.js" integrity="sha384-g5uSoOSBd7KkhAMlnQILrecXvzst9TdC09/VM+pjDTCM+1il8RHz5fKANTFFb+gQ" crossorigin="anonymous"></script>

        <!-- Imports dos gráficos -->

        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.4.0/Chart.min.js"></script>

    </head>
    <body>
        <div class="flex-center position-ref full-height">
            @if (Route::has('login'))
                <div class="top-right links">
                    @auth
                        <a href="{{ url('/home') }}">Home</a>
                    @else
                        <a href="{{ route('login') }}">Login</a>

                        @if (Route::has('register'))
                            <a href="{{ route('register') }}">Register</a>
                        @endif
                    @endauth
                </div>
            @endif

            <div class="content">
                <div class="title m-b-md">
                    SENSOR LUX <i class="fa fa-lightbulb"></i>
                </div>

                <div class="links">
                    {{--<a onclick="ativar()">Grafico - Thingspeak</a>--}}
                    <a onclick="ativar_js()">Grafico - Graph.js</a>
                </div>

                <div class="row" id="grafico" style="display: none;">
                    <h2>Gráfico - Thingspeak</h2>
                </div>
                <br>
                <div class="row" id="graficojs"  style="display: none;">
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
                                url: '{{url('/api/recuperar/dados')}}',
                                dataType: 'json',
                            }).done(function (results) {
                                console.log(results);
                                // Split timestamp and data into separate arrays
                                var labels = [], data=[];
                                results.forEach(function(packet) {
                                    labels.push(new Date(packet.created_at).formatMMDDYYYY());
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
                </div>
            </div>
        </div>
    </body>

<footer>
    <script>
        // Ativar ou não o os gráfico
        function ativar(){
            if(document.getElementById('grafico').style.display == "none"){
                document.getElementById('grafico').style.display = "block";
            }
            else {
                document.getElementById('grafico').style.display = "none";
            }
        }

        // Ativar ou não o os gráfico JS
        function ativar_js(){
            if(document.getElementById('graficojs').style.display == "none"){
                document.getElementById('graficojs').style.display = "block";
            }
            else {
                document.getElementById('graficojs').style.display = "none";
            }
        }
    </script>
</footer>
</html>
