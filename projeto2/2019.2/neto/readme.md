Primeiro, baixei o aplicativo no meu android, "DoidScript". Nele é possível ter as primeiras experiências com os sensores do celular. 

Segundo, utilizei o código que exibe a cada 10 s a os números capturados pelo sensor.

```luxGlobal = 0;
function setLuxText() {
    txt.SetText(" level = " + luxGlobal + " luxGlobal" +count);
}

function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );

  txt = app.CreateText( "", 0.8, 0.3 );
  lay.AddChild( txt );
  app.AddLayout( lay );

  sns = app.CreateSensor( "Light" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();
  setInterval(function(){
      txt.SetText(" level = " + luxGlobal + " luxGlobal");
      }, 10000);
  
}

function sns_OnChange( lux )
{
  //txt.SetText( "level = " + lux + " lux" );
  luxGlobal = lux;
}
```

Terceiro, enviei as informações para o thingspeak, logo também, coloquei as informações no meu site.

```luxGlobal = 0;
//Chamada quando a aplicacao inicia
function OnStart()
{
    //criar layout centralizados verticalmente
    lay = app.CreateLayout( "linear", "VCenter,FillXY" );    

    //criar label texto e adiciona ao layout
    txt = app.CreateText( "Medindo lux" );
    txt.SetTextSize( 32 );
    lay.AddChild( txt );
    
    //adicionar o layout ao app    
    app.AddLayout( lay );
    
    sns = app.CreateSensor( "Light" );
    sns.SetOnChange( sns_OnChange );
    sns.Start();
    setInterval(sendToAPI, 10000);
}

function sns_OnChange( lux )
{
  luxGlobal = lux;
}

function sendToAPI() {
  const http = new XMLHttpRequest()
  
  http.open("GET", "https://api.thingspeak.com/update?api_key=JZC2DFVPBGMA2VKE&field1=0"+luxGlobal)
  http.send()
  http.onload = setLuxText(http.responseText, luxGlobal)
}

function setLuxText(resp,lux) {
    txt.SetText( resp +" level = " + lux + " lux" );
}
```










Meu projeto está sendo exibido no site : "https://zenetoooooooooh.000webhostapp.com/".
Para visualizar basta traduzi-lo no site :"translatetheweb.com"
