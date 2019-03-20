# Projeto 1 - Criação de Página HTML e exibição do gráfico ThingSpeak


### Passo 1 - Criação de página HTML localmente
Utilizar o tutorial https://www.w3schools.com/ para aprender a linguagem de marcação HTML. Através dessa linguagem é possível construir páginas para a web.

Abra um editor de texto qualquer (notepad, bloco de notas, geanny, kate, codeblock) crie um arquivo chamado index.html com o seguinte conteúdo:
```HTML
<!DOCTYPE html>
<html>
  <head>
    <title>Internet das Coisas</title>
  </head>
  <body>

    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    <p>Em breve adicionarei informações de vários sensores</p>

  </body>
</html> 
```
Lembrar de salvar o arquivo como: index.html

### Passo 2 - Utilizar outros comandos do HTML
Aprender as tags básicas do HTML ( html, head, body, title, h1, a href, image)
```HTML
<!DOCTYPE html>
<html>
  <head>
    <title>Internet das Coisas</title>
  </head>
  <body>

    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    <p>Em breve adicionarei informações de vários sensores</p>
    <a href="http://www.google.com">Ir para página de busca</a>

  </body>
</html> 
```


### Passo 3 - Incluir outras mídias via tag <iframe> 
Incluir serviços de outros sites dentro de sua página (Incluir videos do youtube, usando a tag iframe)
  
```HTML
<!DOCTYPE html>
<html>
  <head>
    <title>Internet das Coisas</title>
  </head>
  <body>

    <h1>Bem vindos ao meu primeiro site com IoT</h1>
    <p>Em breve adicionarei informações de vários sensores</p>
    <a href="http://www.google.com">Ir para página de busca</a>
    <iframe width="560" height="315" src="https://www.youtube.com/embed/QSIPNhOiMoE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

  </body>
</html> 
```
### Passo 4 - Criar conta no ThingSpeak
https://thingspeak.com/

### Passo 5 - Criar canal no ThingSpeak
Uma vez que tenhamos criado uma conta no site ThingSpeak, devemos logar no sistema e criar um Canal.
Para esse projeto, criaremos um canal chamado LUX. 
Este canal exibirá informações de um sensor de luz(luminosidade e data em que dado foi coletado).
Devemos habilitar o mesmo para que tenha acesso público.

### Passo 5 - Compartilhar canal e Adicionar iframe do serviço na página html criada; 
```HTML
<!DOCTYPE html>
<html>
	<head>
		<title>Projeto 1 - Página com Thingspeak </title>
		<meta charset="utf-8">
  </head>
	<body>
	
	<h1>Thingspeak</h1>

  	<iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/709914/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
	</body>
</html> 
```

### Passo 6 - Criar uma função que gere informações randômicas para alimentar o canal do thingspeak via api rest fornecida pelo Canal;
Para resolver o passo 6 precisamos criar um código javascript que gere número randomicos que simulem os dados capturados de um sensor de luz. Esse dados gerados deverão ser enviados para GET https://api.thingspeak.com/update?api_key=OYUIUNJVJ995AK6C&field1=0 
Onde o Zero no final do link deve ser substituido pelo valor gerado pela função.
```javascript
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
          http.open("GET", "https://api.thingspeak.com/update?api_key=OYUIUNJVJ995AK6C&field1="+lux)
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
  <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/709914/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>

  </body>
</html>
```
Exemplo funcionando: https://aquilesburlamaqui.000webhostapp.com/thingspeak.html

