<h1>#Projeto 1</h1>
<p>Tomando como orienta&ccedil;&atilde;o as instru&ccedil;&otilde;es dadas, iniciei o projeto conhecendo a linguagem html e script com codigo dado.</p>
<h2>Passo 1 - Cria&ccedil;&atilde;o de p&aacute;gina HTML</h2>
<p>&Eacute; preciso fazer um "cabe&ccedil;alho" em uma pagina HTML para mostrar qual a vers&atilde;o utilizada e os primeiros comandos.&nbsp;</p>
<p>&lt;!DOCTYPE html&gt;<br />&lt;<span class="pl-ent">html</span>&gt;</p>
<p>Finalizando com &lt;/html&gt;</p>
<p><strong>- inserindo um titulo da pagina</strong></p>
<p>&lt;head&gt;<br />&lt;title&gt;<br /><em>Titulo a ser exposto</em><br />&lt;/title&gt;<br />&lt;/head&gt;</p>
<p><strong>- abrindo espa&ccedil;o para o corpo da pagina</strong></p>
<p>&lt;body&gt;</p>
<p><strong>- inserindo espa&ccedil;o para um subtitulo</strong></p>
<p>&lt;h1&gt;<br /><em>Subtitulo a ser exposto</em><br />&lt;/h1&gt;</p>
<p><strong>- inserindo um novo paragrafo no texto da pagina</strong></p>
<p>&lt;p&gt;<br /><em>texto a ser exposto na pagina</em><br />&lt;/p&gt;</p>
<p><strong>- fechando o espa&ccedil;o para o corpo da pagina</strong></p>
<p>&lt;/body&gt;</p>
<h2>Passo 2 - Utilizar outros comandos do HTML</h2>
<p><strong>- adiconando um link na pagina</strong></p>
<p>&lt;a href="http://www.google.com"&gt;Ir para p&aacute;gina de busca&lt;/a&gt;</p>
<h2>Passo 3 - Incluir outras m&iacute;dias via tag</h2>
<p><strong>- inserindo um video do youtube na pagina</strong></p>
<p>&lt;iframe width="400" height="300" src="https://www.youtube.com/embed/QSIPNhOiMoE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen&gt;&lt;/iframe&gt;</p>
<p><em>width e height s&atilde;o as defini&ccedil;&otilde;es do tamanho do video em pixel</em><br /><em>src &eacute; o link do video entre " "</em><br /><em>frameborder &eacute; a borda do video</em></p>
<p>&nbsp;</p>
<h2>Passo 4 - Criar conta no ThingSpeak</h2>
<p>criando conta no https://thingspeak.com/</p>
<p>ID usuario criado: <strong>mixaboente</strong></p>
<h2>Passo 5 - Compartilhar canal e Adicionar iframe do servi&ccedil;o na p&aacute;gina html criada</h2>
<p><em>* foi alterado o numero do canal da instru&ccedil;&atilde;o para o criado na minha ID 839382</em></p>
<p>&lt;html&gt;<br />&lt;head&gt;<br />&lt;title&gt;<br /><em>titulo da pagina Projeto 1 - P&aacute;gina com Thingspeak</em>&nbsp;<br />/title&gt;<br />&lt;meta charset="utf-8"&gt;<br />&lt;/head&gt;<br />&lt;body&gt;<br />&lt;h1&gt;<br />Titulo do Thingspeak<br />&lt;/h1&gt;<br />&lt;iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&amp;color=%23d62020&amp;dynamic=true&amp;results=60&amp;type=line&amp;update=15"&gt;&lt;/iframe&gt;<br />&lt;/body&gt;<br />&lt;/html&gt;</p>
<p>&nbsp;</p>
<h2>Passo 6 - Criar uma fun&ccedil;&atilde;o que gere informa&ccedil;&otilde;es rand&ocirc;micas para alimentar o canal do thingspeak via api rest fornecida pelo Canal</h2>
<p><em>* alterei o valor inicial dado nas orienta&ccedil;&otilde;es de 3000 para 1000</em></p>
<p>&lt;html&gt;<br />&lt;head&gt;<br />&lt;title&gt;<br />Titulo da pagina<br />&lt;/title&gt;<br />&lt;script&gt;<br />var count=1;<br />function sendToAPI(lux) <br />{<br />count=Math.floor((Math.random() * 100) + 1);<br />const http = new XMLHttpRequest()<br />http.open("GET", "https://api.thingspeak.com/update?api_key=VF3OG48ATFZ397R7&amp;field1=0"+lux)<br />http.send()<br />http.onload = console.log(http.responseText+" "+lux)<br />}<br />setInterval( function() { sendToAPI(count) }, 1000); &lt;/script&gt;<br />&lt;/head&gt;<br />&lt;body&gt;<br />&lt;h1&gt;<br />Titulo do Tingspeak<br />&lt;/h1&gt;<br />&lt;p&gt;<br />A cada segundo ser&aacute; enviado n&uacute;mero randomico para o thinkspeak<br />&lt;/p&gt;<br />&lt;iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/839382/charts/1?bgcolor=%23ffffff&amp;color=%23d62020&amp;dynamic=true&amp;results=60&amp;type=line"&gt;&lt; /iframe&gt;<br />&lt;/body&gt;<br />&lt;/html&gt;<br />&lt;/body&gt;</p>
<p>Link de como ficou o Passo 6 (<em>criado no site 000webhostapp.com</em>)</p>
<p><a href="https://mboente.000webhostapp.com/">Pagina da Michele no Webhostapp</a></p>
