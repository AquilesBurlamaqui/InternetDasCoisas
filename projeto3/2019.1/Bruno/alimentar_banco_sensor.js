luxGlobal = 0;
//Chamada quando a aplicacao inicia
function OnStart(){
    //criar layout centralizados verticalmente
    lay = app.CreateLayout("linear", "VCenter,FillXY"); 
    
    //criar label texto e adiciona ao layout
    txt = app.CreateText("Medindo luminosidade");
    txt.SetTextSize(32);
    lay.AddChild(txt);
  
  //adicionar o layout ao app 
  app.AddLayout(lay);
  
  sns = app.CreateSensor("Light");
  sns.SetOnChange(sns_OnChange);
  sns.Start();
      setInterval(sendToAPI, 1000);
}

function sns_OnChange(lux){
    luxGlobal = lux;
}
function sendToAPI(){
    
    const http = new XMLHttpRequest()
    //http.open("GET", "https://api.thingspeak.com/update?api_key=FBAOL6V3GWXN1H3N&field1="+luxGlobal);
    http.open("POST", "https://silvabrunu.000webhostapp.com/api.php/sensorLux");
    http.setRequestHeader("Content-type", "application/json");
    var data = JSON.stringify({"valor":""+luxGlobal});
    http.send(data);
    http.onload = setLuxText(http.responseText, luxGlobal)
}
function setLuxText(resp,lux) {
    txt.SetText( resp +" level = " + lux + " lux" );
}