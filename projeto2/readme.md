# Projeto 2 - Atualização do gráfico ThingSpeak via sensor do celular

### Passo 1 - Instalar o app DroidScript no celular (android);
Somente para android:
https://play.google.com/store/apps/details?id=com.smartphoneremote.androidscriptfree&hl=pt

### Passo 2 - No DroidScript procurar nas referências e executar exemplos de códigos com sensores(ex. Sensor de luz ou Acelerômetro) 
O código abaixo exibe o valor retornado pelo sensor de luz do celular. 
```javascript
function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );

  txt = app.CreateText( "", 0.8, 0.3 );
  lay.AddChild( txt );
  app.AddLayout( lay );

  sns = app.CreateSensor( "Light" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();

}

function sns_OnChange( lux )
{
  txt.SetText( "level = " + lux + " lux" );
}


```
### Passo 3 - Construir um código no droidscript que exiba a cada 10s a informação capturada do sensor;

```javascript
luxGlobal = 0;
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
    setInterval(setLuxText(), 10000);
}

function sns_OnChange( lux )
{
  luxGlobal = lux;
}
function setLuxText() {
    txt.SetText(" level = " + lux + " luxGlobal" );
}
```

### Passo 4 - Enviar essa informação para o thingspeak;
```javascript
luxGlobal = 0;
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
  
  http.open("GET", "https://api.thingspeak.com/update?api_key=NDJBSRPGPHIRZPTB&field1="+luxGlobal)
  http.send()
  http.onload = setLuxText(http.responseText, luxGlobal)
}

function setLuxText(resp,lux) {
    txt.SetText( resp +" level = " + lux + " lux" );
}
```
### Passo 5 - Acompanhar as alterações na página que você criou e publicar essa página no githubpages ou outra plataforma de hospedagem como https://br.000webhost.com; 

Exemplo em execução: https://aquilesburlamaqui.000webhostapp.com/iot/thingspeak_android.html

