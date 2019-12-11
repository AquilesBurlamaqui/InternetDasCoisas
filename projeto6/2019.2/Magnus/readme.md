# Node-RED - Coleta de dados gerados por sensor e envio por e-mail em forma de array
![Imgur](https://i.imgur.com/fVp8J0Y.png)
### A primeira parte dos nodes é para injeção de dados, funcionando como um sensor. Caso haja de fato um sensor gerando os dados, essa parte pode ser desconsiderada.
![Imgur](https://i.imgur.com/4onJGrq.png)
#### OBS: caso use o injetor com intervalo de envios, é preciso que desative a injeção quando não for mais usar para que não ocorra o envio contínuo de dados para o e-mail quando não for necessário.
### Através do node *mqtt*, o servidor e o tópico (deve ser único) precisam ser fornecidos.
![Imgur](https://i.imgur.com/J9MoMVP.png)
### Nesta segunda parte, os dados gerados pelo sensor irão para o node *join*, que irá, neste caso, gerar um array com os dados recebidos e depois enviar para o e-mail que o usuário decidir.
![Imgur](https://i.imgur.com/CUxWiDi.png)
### Para transformar os dados em um array de dados deve-se definir dentro do node *join* esta criação. Escolhendo o modo manual, o usuário pode definir array e definir o tamanho do array para envio, ou o tempo a partir do início para que em seu fim gere o array.
![Imgur](https://i.imgur.com/jQZ5nuA.png)
### Para habilitar o uso do e-mail é necessário instalar a extensão no editor do Node-RED. Clicando no canto superior direito, o usuário deve clicar em *Manage palette*.
![Imgur](https://i.imgur.com/yNQeIRi.png)
### Após isso, a busca deve ser feita na aba *Install*, e ao encontrar a extensão, o usuário pode instalá-la e ler a sua documentação clicando no ícone ao lado do seu nome.
![Imgur](https://i.imgur.com/8O9UTM1.png)
### No node *email*, é preciso preencher o e-mail do destinatário e o seu e-mail, assim como a senha, para que o node envie e receba a partir dele.
![Imgur](https://i.imgur.com/0ED2uAf.png)
#### OBS: o gmail precisa ser liberado para poder ser utilizado. No gerenciamento da conta Google, é necessário ativar o *Acesso a app menos seguro*.
### Array recebido por e-mail:
![Imgur](https://i.imgur.com/lKsjgPg.png)
![Imgur](https://i.imgur.com/VMpwJzp.png)
### A última parte é para mostrar no editor do Node-RED os e-mails recebidos.
![Imgur](https://i.imgur.com/jxTmJFl.png)
### Na configuração do node pode-se definir o tempo para buscar novas atualizações no e-mail, escolher a pasta (*INBOX* neste caso), com o critério escolhido (*Unseen*) e agir de acordo com o *Disposition* marcado.
![Imgur](https://i.imgur.com/ZAFmMM5.png)
#### OBS: atenção com o valor escolhido do *Disposition*, ele pode marcar todos os e-mails como lido ou excluí-los.
### E-mail mostrado no Node-RED:
![Imgur](https://i.imgur.com/z9txQdX.png)
