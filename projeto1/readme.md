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
