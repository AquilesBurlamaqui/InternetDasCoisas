<!DOCTYPE html>
<html>
 <body>
	<h1>#Projeto 1</h1>
	<p>Tomando como orientação as instruções dadas, iniciei o projeto conhecendo a linguagem html e script com codigo dado.</p>
	<p>Passo 1 - Criação de página HTML</p>

<html>
  //inserindo um titulo da pagina
  <head>
      <title>Internet das Coisas</title>
  </head>
  //abrindo espaço para o corpo da pagina
  <body>
    //inserindo espaço para um subtitulo
    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    //inserindo um novo paragrafo no texto da pagina
    <p>Em breve adicionarei informações de vários sensores</p>

  </body>
</html> 

	<p>Passo 2 - Utilizar outros comandos do HTML</p>

<html>
  <head>
    <title>Internet das Coisas</title>
  </head>
  <body>

    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    <p>Em breve adicionarei informações de vários sensores</p>
    
    //adiconando um link na pagina
    
    <a href="http://www.google.com">Ir para página de busca</a>

  </body>
</html>

	<p>Passo 3 - Incluir outras mídias via tag</p>

    
<html>
  <head>
    <title>Internet das Coisas</title>
  </head>
  <body>

    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    <p>Em breve adicionarei informações de vários sensores</p>
    <a href="http://www.google.com">Ir para página de busca</a>
    
    //inserindo um video do youtube na pagina
    
    <iframe width="560" height="315" src="https://www.youtube.com/embed/QSIPNhOiMoE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

  </body>
</html>

	<p>Passo 4 - Criar conta no ThingSpeak</p>

criando conta no https://thingspeak.com/

ID usuario: mixaboente

	<p>Passo 5 - Compartilhar canal e Adicionar iframe do serviço na página html criada</p>

<html>
	<head>
		<title>Projeto 1 - Página com Thingspeak </title>
		<meta charset="utf-8">
  </head>
	<body>
	
	<h1>Thingspeak</h1>

//foi alterado o numero do canal da instrução para o criado na minha ID 839382

  	<iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
	</body>
</html>

	<p>Passo 6 - Criar uma função que gere informações randômicas para alimentar o canal do thingspeak via api rest fornecida pelo Canal</p>

<html>
  <head>
    <title>IoT ECT</title>
    <script>
        var count=1;
        function sendToAPI(lux) 
        {
          count=Math.floor((Math.random() * 100) + 1);
          const http = new XMLHttpRequest()
          http.open("GET", "https://api.thingspeak.com/update?api_key=VF3OG48ATFZ397R7&field1=0"+lux)
          http.send()
          http.onload = console.log(http.responseText+" "+lux)
        }
        //alterei o valor inicial de 3000 para 1000
        setInterval( function() { sendToAPI(count) }, 1000);
        
    </script>
  </head>
         
  <body>

  <h1>Praticando Javascript com Iot modificando o tempo sugerido</h1>
  <p>A cada segundo será enviado número randomico para o thinkspeak</p>
  <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line"></iframe>
  </body>
</html>

</body>

<a href="https://mboente.000webhostapp.com">Pagina da Michele no Webhostapp</a>
</html>
