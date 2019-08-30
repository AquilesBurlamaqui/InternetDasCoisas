# Projeto 2: Atualização do gráfico ThingSpeak via sensor do celular;

* Passo 1: Instalar o app DroidScript no celular (android);

https://play.google.com/store/apps/details?id=com.smartphoneremote.androidscriptfree&hl=pt

* Passo 2: No app procurar a aba "referências", depois "sensores" e em seguida executar o sensor de luz ou acelerômetro.
- Código:

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

* Passo 3: Construir no app um código que exiba a cada 10 segundos a informação capturada do sensor;

- No app foi criado um novo projeto com o código abaixo;
- O código foi inserido utilizando a função "WiFi Connect" do app. Com a função é possível espelhar para o computador, facilitando a inserção do código.

luxGlobal = 0;
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

* Passo 4: Enviar essa informação para o thingspeak;


