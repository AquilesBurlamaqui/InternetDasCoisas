xGlobal = 0;

function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );

  txt = app.CreateText("Medindo X");
  txt.SetTextSize( 32 );
  lay.AddChild( txt );
  app.AddLayout( lay );
  sns = app.CreateSensor( "Accelerometer" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();
  setInterval(sendToAPI, 100)
}

function sns_OnChange( x )
{
    xGlobal = x;
}

function sendToAPI() {
  const http = new XMLHttpRequest()
  
  http.open("GET", "https://api.thingspeak.com/update?api_key=KAA7ID9VZ1J6UKTN&field1=" + xGlobal)
  http.send()
  http.onload = setLuxText(http.responseText, xGlobal)
}

function setLuxText(resp,x) {
    txt.SetText("x=" + x);
}




