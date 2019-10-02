# Projeto 1
Criamos uma conta no 000webhost.com para hospedar uma Página HTML,criado de forma simples (bloco de notas)  e nesta pagina inserimos um grafico do ThingSpeak(também foi criada uma conta no ThingSpeak) que gera números aleatorios a cada 3 segundos, simulando um sensor e esses valores são plotados em um gráfico, que está localizado na página HTML.
>                 <!DOCTYPE html>
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
          http.open("GET", "https://api.thingspeak.com/update?api_key=1176CMZW9Y5XENRT&field1="+lux)
          //envia um GET
          http.send()
          //quando a requisição retornar ele chama o console e imprime o valor gerado
          http.onload = console.log(http.responseText+" "+lux)
        }
        //a função de envio de dados é chamada de 3 em 3 segundos
        setInterval( function() { sendToAPI(count) }, 3000);
    </script>
  </head>

  <body>

  <h1>Praticando Javascript com Iot</h1>
  <p>De 3 em 3 segundos enviando número randomico para o thinkspeak</p>
  <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839398/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>

  </body>
</html>
   
 
