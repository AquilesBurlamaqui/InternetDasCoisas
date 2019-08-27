O projeto 2 foi desenvolvido a partir do modelo de acelerômetro disponível na biblioteca do aplicativo DroidScript

No início foi necessário utilizar um dispositivo Android e adquirir o aplicativo no repositório da Google.

Seguindo o tutorial disponibilizado, foi feito a adequação do exemplo, que era utilizado para o sensor de luz, para o acelerômetro, no qual foi mudado nomes de variáveis e os links de alimentação do código. 
O código abaixo descreve bem a configuração feita para que o acelerômetro funcione:

// Código utilizado //

dirGlobal=0;

function OnStart()
{
     lay = app.CreateLayout( "Linear", "VCenter,FillXY" );

     txt = app.CreateText( "", 0.8, 0.3, "Multiline" );
     lay.AddChild( txt );
     app.AddLayout( lay );

     sns = app.CreateSensor( "Accelerometer" );
     sns.SetOnChange( sns_OnChange );
     sns.Start();
     setInterval(sendToAPI,10000);

}

function sns_OnChange(x,y)
{
     dirGlobal=x;
}

function sendToAPI() {
     const http = new XMLHttpRequest()
  
     http.open("GET", "https://api.thingspeak.com/update?api_key=ZJL904XR0FKPBVQR&field1="+dirGlobal)
     http.send()
     http.onload = setLuxText(http.responseText, dirGlobal)
}

function setLuxText(resp,x) {
     txt.SetText( resp +" Aceleração x = " + x + " metros" );
}

//

O acelerômetro possui 3 marcadores de direção, x, y e z. Para otimizar o código escolhi uma das direções, no caso a direção x para que o gráfico no Thingspeak fosse alimentado apenas por valores de x. A cada 10 segundos há uma captura dos dados coletados e assim o gráfico é atualizado conforme o valor que foi enviado.

