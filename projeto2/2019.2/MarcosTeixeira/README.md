# Projeto 02: Plotagem de gráfico com os dados do acelerômetro de smartphone Android no ThingSpeak

### Conhecimentos necessários

- Javascript

### Ferramentas 

- Sublime Text 3
- DroidScript 
- ThingSpeak

### Materiais 
- Smartphone Moto X4

Inicialmente, foi feita a instalação e a pesquisa nas referências do DroidScript para obtenção do código que recebe os dados do acelerômetro. O código abaixo é o modelo disponibilizado pela aplicação.

~~~javascript
function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );
 
  txt = app.CreateText( "", 0.8, 0.3, "Multiline" );
  lay.AddChild( txt );
  app.AddLayout( lay );
 
  sns = app.CreateSensor( "Accelerometer" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();
 
}
 
function sns_OnChange( x, y, z, time )
{
  txt.SetText( "x="+x + "\n y="+y + "\n z="+z );
}
~~~

Em seguida, foi criada um canal no thingspeak intitulado “Uso do sensor”.  O objetivo é que seja gerado um gráfico com os valores do eixo x do acelerômetro. Após a criação do canal desenvolveu se uma página em HTML para visualização do gráfico.

~~~html
<!DOCTYPE html>
<html lang="pt-BR">
    <head>
        <meta charset="utf-8">
        <title>Projeto 02</title>
    </head>

    <body>
    
        <h1> Valor de X </h1>
        <h2> Acelerômetro </h2>
        <p> Recebe dados do sensor do Moto X4 </p>

        <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/890106/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&title=Valor+de+X+&type=spline&xaxis=Tempo&yaxis=Valor&yaxismax=0.01"></iframe>

    </body>
 
</html>
~~~ 

Utilizando a referência do acelerômetro fizemos algumas alterações a fim de enviar os dados para o thingspeak. A atualização dos dados do eixo x serão feitas a  cada 10 segundos, para isso, foi adicionada o método setInterval na função OnStart(). 

~~~javascript

function OnStart()
{
   lay = app.CreateLayout( "Linear", "VCenter,FillXY" );   
   txt = app.CreateText( "Valor de X do acelerometro:" );
   lay.AddChild( txt );
   app.AddLayout( lay );

   sns = app.CreateSensor( "Accelerometer" );
   sns.SetOnChange( sns_OnChange );
   sns.Start();
   setInterval(sendToAPI, 10000);
}
~~~

Enquanto a aplicação é executada no dispositivo móvel os dados do eixo x são atualizados. O código implementado no celular é o [Código](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto2/2019.2/MarcosTeixeira/codigo02.js). A página web hospedada no 000webhost é [Projeto 02](https://projetosiot.000webhostapp.com/projeto02.html).
