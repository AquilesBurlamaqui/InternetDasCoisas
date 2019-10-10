- Antes de tudo, precisei aprender o que eram os bancos de dados feitos com PHP e como eles funcionavam.  
```A principal característica desse método é o não-acesso desses dados pelos usuários ou por usuários maliciosos, além do fácil acesso do administrador à tais dados.```  
- Criei uma tabela com três colunas, uma com auto incremento que funciona como o id de cada entrada, outra com o nível de luminosidade capturada e, por fim, uma que marcava a hora exata em que esse dado foi guardado.  
```Nesse caso, a única linha dessa coluna que eu precisava alimentar era a do nível de luz, já que o ID tinha auto incremento e que o "Timestamp" era marcado, pela própria tabela, assim que o dado chegava.```  

- Aproveitei o código dos projetos anteriores para usar o meu celular como sensor de luz, só que dessa vez usando o artefato do PHP.  
- Depois usei a biblioteca chartjs para mostrar esses dados em forma de gráfico.  
