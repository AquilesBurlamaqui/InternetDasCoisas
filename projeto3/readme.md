# Projeto 3 - Substituição do ThingSpeak por sistema web e banco de dados

### Passo 1 - Criar conta em site que ofereça serviço de hospedagem, PHP e banco de dados Mysql
Sugestão de criar a conta no serviço  https://br.000webhost.com 

### Passo 2 - Criar um banco de dados(mysql) para armazenar os dados do sensor;
#### 2.1 No  https://br.000webhost.com  ir em Database Manager e criar new Database
  - Um banco de dados será criado com informações como:
```
DB Name 	DB User 	DB Host 	 
id8850089_db_iot 	id8850089_db_iot 	localhost
```
- Entre em Manage - para gerenciar o seu banco de dados criado, escolha PhpMyAdmin; 
  - O PhpMyadmin é um sistema web que te ajudar a gerenciar o banco de dados.
- No menu lateral, escolha o seu banco, ex: d8850089_db_iot
- Procure no contéudo centra a função Create table, ela possui um formulário para entrada do nome
  - Esse formulário pede o nome da tabela a ser criada e o número de colunas.
  - Coloque o nome: lux_sensor e colunas 3 e clique em GO/IR
- Primeiro campo: id:INT - index:PRIMARY - AI:MARQUE (Se surgir uma janela popup, aperto em G) para confirmar que id é chave primária)
- Segundo campo: valor:INT
- Terceiro campo: data:timestamp - Default:CURRENT_TIMES
- Aperte SAVE

Sua tabela estará criada. Ela armazenará 3 informações. Um identificador único(como se fosse um CPF para cada dado, de modo que ele possa ser diferenciado dos demais, por isso dizemos que ele é PRIMARY-não se repete, e AI-autoincremento sera organizado como se fosse um contador. O primeiro valor será 1, o segundo 2, e assim por diante) 
 
 - Ainda utilizando o phpmyadmin, e ja com sua tabela criada, tente inserir um dado via interface do phpmyadmin. 
  - Selecione a tabela no menu lateral, e no menu superior, escolha INSERT;
  - Aparecerá vários campos para entrada de dados. Preencha somente um dos campos, o referente a valor. Coloque qualquer valos, por exemplo 50. Não precisa colocar o id (pois ele sera incrementado automaticamente), nem precisar colocar a data (pois ele sera preencido com a hora do sistema)
  - Clique em BROWSE para verificar se o valor que você entrou esta armazenado. Ele deve listar todos os valores armazenados nesta tabela desse banco;

### Passo 2 - Criar um código php para receber os dados e inserir no banco;

### Passo 3 - Criar um código php para recuperar os dados do banco;

### Passo 4 - Criar um código em php para exibir como um gráfico os dados recebidos;


