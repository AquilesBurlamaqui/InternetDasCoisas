<!DOCTYPE html>
<html>
  <head>
    <title>IoT ECT</title>
    <script>
        //criar váriavel global
        var count=1;
        //definição de função para envio de dados para o thinkspeak
        function sendToAPI(lux) {
          //gera um número randomico entre 1 e 100
          count=Math.floor((Math.random() * 100) + 1);
          //criar um objeto capaz de enviar dados via requisição HTTP GET
          const http = new XMLHttpRequest()
          //prepara um GET passando a váriavel lux como ultimo paramentro do link
          http.open("GET", "GET https://api.thingspeak.com/update?api_key=LGH7H1SR5EDKQURB&field1="+lux)
          //envia um GET
          http.send()
          //quando a requisição retornar ele chama o console e imprime o valor gerado
          http.onload = console.log(http.responseText+" "+lux)
        }   
        //a função de envio de dados é chamada de 3 em 3 segundos
        setInterval( function() { sendToAPI(count) }, 3000);
    </script>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </head>
         
  <body>

  <h1>Praticando Javascript com Iot</h1>
  <p>De 3 em 3 segundos enviando número randomico para o thinkspeak</p>
  <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839395/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&title=Lumin%C3%A2ncia+do+ambiente&type=line&xaxis=Intervalo+de+tempo+%28s%29&yaxis=LUX"></iframe>
  </body>
</html>