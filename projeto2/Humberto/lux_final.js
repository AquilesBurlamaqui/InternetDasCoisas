luxGlobal =0;
//Called when application is started.
function OnStart()
{
	//Create a layout with objects vertically centered.
	lay = app.CreateLayout( "linear", "VCenter,FillXY" );	

	//Create a text label and add it to layout.
	txt = app.CreateText( "Medindo Lux", 0.8, 0.3 );
	txt.SetTextSize( 32 );
	lay.AddChild( txt );
	
	//Add layout to app.	
	app.AddLayout( lay );
	
	sns = app.CreateSensor("Light");
	sns.SetOnChange(sns_OnChange);
	sns.Start();
	setInterval(sendToAPI,10000)
}


function sns_OnChange(lux)
{
    luxGlobal=lux;
}

    function sendToApi (){
    txt.SetText("Lux atual = " + lux + " lux");
          const http = new XMLHttpRequest()
          http.open("GET", "https://api.thingspeak.com/update?api_key=03VLNYXHEGNGGZOD&field1="+luxGlobal)
          http.send()
          http.onload = txt.SetText("Enviado = " + luxGlobal + " lux");
        }
        
   
   
