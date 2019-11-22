x = 0;
y = 0;
z = 0;
time = 0;

function OnStart()
{
    
    lay = app.CreateLayout( "Linear", "VCenter,FillXY" );    

    txt = app.CreateText( "Valor de X do acelerometro:" );
    lay.AddChild( txt );
    app.AddLayout( lay );

    sns = app.CreateSensor( "Accelerometer" );
    sns.SetOnChange( sns_OnChange );
    sns.Start();
    //A cada dez segundos
    setInterval(sendToAPI, 10000);
}

function sns_OnChange( x, y, z, time )
{
    txt.SetText( "x=" + x + "\n y=" + y + "\n z=" + z );
}

function sendToAPI() 
{
  const http = new XMLHttpRequest()
  http.open("GET", "https://api.thingspeak.com/update?api_key=I68DWLKYDLZVREKA&field1="+x)
  http.send()
  http.onload = setAceText(http.responseText, x)
}

function setAceText(resp,lux) 
{
    txt.SetText( "x=" + x );
}
