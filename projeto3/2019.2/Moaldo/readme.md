# Projeto 3
No terceiro projeto foi apresentado uma plataforma de hospedagem de sites, para que pudéssemos colocar nosso site de fato
disponível na internet. Esta plataforma nos da a oportunidade da criação de bancos de dados, assim substituiremos o ThingSpeak
pelo banco de dados, para tal tarefa utilizamos a linguagem SQL para a criação das tabelas e de seus campos.  
Criado o banco de dados, utilizamos a linguegem PHP e SQL para recuperar os dados presentes no banco de dados em forma de uma
simples lista.  
Seguimos criando uma API, um codigo escrito em PHP capaz de enviar e recuperar informações do banco de dados, utilizando de métodos
HTTP, GET, POST, PUT, DELETE.  
Em seguida criamos um codigo para apresentar os dados obtidos em forma de gráfico, utilizamos varias linguagens nesta tarefa, tais 
como HTML, JavaScript e PHP.  
Por fim, usamos o smartphone para alimentar o banco de dados com informações do sensor de luminosidade. Modificamos o codigo do 
[Projeto 2](https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2/2019.2/Moaldo), alterando o metodo de
envio das informações trocamos o metodo GET por POST.  

No final do projeto foram aprendidas várias novas tecnologias, a troca do ThingSpeak pelo banco de dados nos possibilita armazenar
mais dados e realizar tratamento de informações de uma forma mais avançada e com mais detalhes. Ao se aprofundar um pouco mais
em PHP e JS podemos criar ferramentas mais poderosas e completas. Os conhecimentos obtidos a partir da execução do projeto serão 
muito importantes para a criação do projeto final.  
Como resultado foi criado o arquivo [iot.php](url) que contem a forma de listagem simples dos dados, o arquivo [api.php](url)
tem a API principal que envia e recupera os dados, o arquivo [graficos.php](url) contem o codigo capaz de exibir as informações
em forma de gráfico, o arquivo [lux2.js](url) contem o programa para smartphone para enviar as informações do sensor para o banco 
de dados.  
O resultado final é o [meu site](https://moaldoiot.000webhostapp.com/iot.php).
