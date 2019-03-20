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
### Passo 4 - Enviar essa informação para o thingspeak;
### Passo 5 - Acompanhar as alterações na página que você criou e publicar essa página no githubpages ou outra plataforma de hospedagem (https://br.000webhost.com) ; 
