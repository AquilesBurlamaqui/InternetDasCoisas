<!DOCTYPE html>
<html>
  <body>
    <h1>#Projeto 1</h1>
    Tomando como orientação as instruções dadas, iniciei o projeto conhecendo a linguagem html e script com codigo dado.
    
    	<p><b>Passo 1 - Criação de página HTML</p></b>
  
  	É preciso fazer um "cabeçalho" em uma pagina HTML para mostrar qual a versão utilizada e os primeiros comandos. Lembrando que o comando descrito abaixo não tem espaço entre o < e o comando.
    
    <p><b>- inserindo um titulo da pagina</b></p>

	<p>< head>< title> Titulo a ser exposto</ title>< /head></p>
      
	<p><b>- abrindo espaço para o corpo da pagina</b></p>
      
    < body>
	<p><b>- inserindo espaço para um subtitulo</b></p>
      
	< h1>Subtitulo a ser exposto< /h1>
      
	<p><b>- inserindo um novo paragrafo no texto da pagina</p></b>
      
	< p>texto a ser exposto na pagina< /p>
      
	<p><b>- fechando o espaço para o corpo da pagina</b></p>
      
  	< /body>

    <p>
    <b>Passo 2 - Utilizar outros comandos do HTML</b></p>
      <p>- adiconando um link na pagina</p>
        < a href="http://www.google.com">Ir para página de busca< /a>
	  
      <p><b>Passo 3 - Incluir outras mídias via tag</b></p>
          
          <p>- inserindo um video do youtube na pagina</p>   
          

          <p>
            < iframe width="400" height="300" src="https://www.youtube.com/embed/QSIPNhOiMoE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>< /iframe>
            </p> 


            <p>
  width e height são as definições do tamanho do video em pixel<br>
  src é o link do video entre " "<br>
  frameborder é a borda do video<br>
            </p>
    
              <p>
       EXEMPLO:<br>
       <iframe width="400" height="300" src="https://www.youtube.com/embed/A5NW50cMuwo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
              </p> 
	
              <p><b>Passo 4 - Criar conta no ThingSpeak</b></p>

<p>
  criando conta no https://thingspeak.com/<br>
  ID usuario criado: <b>mixaboente</b>
     </p>



	<p>Passo 5 - Compartilhar canal e Adicionar iframe do serviço na página html criada</p>
    <p>
        <i>* foi alterado o numero do canal da instrução para o criado na minha ID 839382</i>
    </p>

< html><br>
	< head><br>
	< title>titulo da pagina Projeto 1 - Página com Thingspeak < /title><br>
	<  meta charset="utf-8"><br>
    < /head><br>
	< body><br>
	< h1>titulo do Thingspeak< /h1><br>
    < iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15">< /iframe><br>
	< /body><br>
    < /html><br>
    
      <p>
       EXEMPLO:<br>
        <h1>titulo do Thingspeak</h1><br>
 <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
      </p>

      <p><b>Passo 6 - Criar uma função que gere informações randômicas para alimentar o canal do thingspeak via api rest fornecida pelo Canal</b></p>
<p>
         <i>* alterei o valor inicial dado nas orientações de 3000 para 1000 
          </i></p>
< html><br>
< head><br>
< title>Titulo da pagina< /title><br>
< script><br>
        var count=1;<br>
        function sendToAPI(lux) <br>
        {<br>
          count=Math.floor((Math.random() * 100) + 1);<br>
          const http = new XMLHttpRequest()<br>
          http.open("GET", "https://api.thingspeak.com/update?api_key=VF3OG48ATFZ397R7&field1=0"+lux)<br>
          http.send()<br>
          http.onload = console.log(http.responseText+" "+lux)<br>
        }<br>
   setInterval( function() { sendToAPI(count) }, 1000);
   < /script><br>
  < /head><br>
   < body><br>
< h1>Titulo do Tingspeak< /h1><br>
 < p>A cada segundo será enviado número randomico para o thinkspeak< /p><br>
  < iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line">< /iframe><br>
< /body><br>
< /html><br>
< /body><br>

  <p><b>Link de como ficou o Passo 6</b>
    <i>criado no site 000webhostapp.com</i></p>
  <a href="https://mboente.000webhostapp.com">Pagina da Michele no Webhostapp</a>
</html>
