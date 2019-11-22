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
  
  http.open("GET", "https://api.thingspeak.com/update?api_key=WYQ5N2GLA1GPZOPL&field1="+luxGlobal)
  http.send()
  http.onload = setLuxText(http.responseText, luxGlobal)
}

function setLuxText(resp,lux) {
    txt.SetText( resp +" level = " + lux + " lux" );
}
