- Fiz uma conta no 000webhost para hospedar [meu site](https://paulohenriqueaf.000webhostapp.com/index.html), onde coloquei primeiramente uma página do tipo *home* que irá levar os usuários para as páginas dos respectivos projetos da disciplina.  

>    <!DOCTYPE html>
      <html>
        <head>
          <title>Internet das Coisas do Paulo</title>
        </head>
        <body>
          <h3>Sejam bem vindos ao meu primeiro site com IoT</h3>
          <p>Em breve colocarei mais informações de vários sensores</p>
          <a href= "pagina1.html">clique e vá para a página 1</a>
        </body>
      </html>  
- Depois criei a primeira página, onde ficará o [Projeto 1](https://paulohenriqueaf.000webhostapp.com/pagina1.html), onde se encontra o iframe do gráfico do canal criado no ThingSpeak, que é alimentado por um algoritmo de aleatoriedade feito em javascript.  
>   <!DOCTYPE html>
    <html>

      <head>
        <title>Página 1</title>
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
                http.open("GET", "https://api.thingspeak.com/update?api_key=KA3JZSSI2W3Y6OZJ&field1="+lux)
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
          <p>De 3 em 3 segundos enviando número randomico para o thinkspeak e atualizando o gráfico</p>
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/843690/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
          <a href= "index.html">clique e vá para a página inicial</a>
      </body>

    </html>  
