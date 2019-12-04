# Projeto 01: Uso do ThingSpeak para geração de gráficos

A partir dos tutoriais disponíveis no Codecademy, foi possível obter conhecimentos básicos para criação de páginas HTML. Após o estudo sobre elementos e estrutura do HTML desenvolveu-se uma página simples que permitisse a inserção de links, uso de títulos e textos.

Utilizando a plataforma ThingSpeak podemos realizar a  aquisição e visualização dos dados que foram gerados pelo código em JS (Javascript), sendo enviados para um canal intitulado LUX.  A aplicação em JS gera números aleatórios na função sendToAPI(lux)e realiza a transferência de dados  HTTP, pelo objeto XMLHttpRequest. O envio é feito a cada 3000 milisegundos usando o método setInterval. 

Geração dos valores aleatórios
cont = cont+Math.floor((Math.random() * 100) + 2);

Método setInterval
setInterval( function() { sendToAPI(cont) }, 3000);
