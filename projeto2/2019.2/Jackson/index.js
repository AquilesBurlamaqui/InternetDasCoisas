luxGlobal = 0;

function OnStart()

{
    lay = app.CreateLayout( "linear", "VCenter,FillXY" );    

    txt = app.CreateText( "Medindo lux" );
    txt.SetTextSize( 32 );
    lay.AddChild( txt );
    
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
  
  http.open("GET", "https://api.thingspeak.com/update?api_key=BIQCMUO4DMM1WVC2&field1=0"+luxGlobal)
  http.send()
  http.onload = setLuxText(http.responseText, luxGlobal)
}

function setLuxText(resp,lux) {
    txt.SetText( resp +" level = " + lux + " lux" );
}