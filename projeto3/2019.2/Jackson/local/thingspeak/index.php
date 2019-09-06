<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Resume of LUX values</title>
  <link rel="stylesheet" href="/static/bootstrap.min.css">
  <link rel="stylesheet" href="/static/style.cover.css">
  <script src="/static/jquery.min.js"></script>
</head>
<body class="text-center">

  <div class="cover-container d-flex w-100 h-100 p-3 mx-auto flex-column">

    <header class="masthead mb-auto">
      <div class="inner">
        <h3 class="masthead-brand">IoT</h3>
        <nav class="nav nav-masthead justify-content-center">
          <a class="nav-link" href="/local">Início</a>
          <a class="nav-link active" href="/local/thingspeak">Grafico - Thingspeak</a></a>
          <a class="nav-link" href="/local/grafico">Grafico - Graph.js</a>
        </nav>
      </div>
    </header>

    <main role="main" class="inner cover data-box">
      <div class="bg-white rounded">
        <iframe style="width: 450px; height: 250px; border: none" src="https://thingspeak.com/channels/846903/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=10&type=line&update=10" onload="adjustCenter()"></iframe>
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
    var count=1;
    function sendToAPI(lux) {
      count=Math.floor((Math.random() * 100) + 1);
      const http = new XMLHttpRequest()
      http.open("GET", "https://api.thingspeak.com/update?api_key=BIQCMUO4DMM1WVC2&field1="+lux)
      http.send()
      http.onload = console.log(http.responseText+" "+lux)
    }
    setInterval( function() { sendToAPI(count) }, 10000);
  </script>

</body>

</html>