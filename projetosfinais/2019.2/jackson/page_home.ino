void homePage() {

  String textoHTML;
  textoHTML += "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>ESP Server</title><meta name='viewport' ";
  textoHTML += "content='width=device-width,initial-scale=1'><link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.10.2/css/all.css'>";
  textoHTML += "<link href='https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css' rel='stylesheet'></head><body>";
  textoHTML += "<div class='container text-center mt-5'><h1><i class='fas fa-home'></i> IOT</h1><h3 class='mt-4'>Refresh Status ";
  textoHTML += "<button id='refresh' class='btn btn-outline-secondary rounded-0'><i class='fas fa-redo'></i></button></h3>";
  textoHTML += "<div id='light-on'><br><i class='fas fa-spin fa-sun text-warning'></i><h1><i class='fas fa-lightbulb text-warning'></i>";
  textoHTML += "</h1></div><div id='light-off'><br><i class='fas fa-sun'></i><h1><i class='fas fa-lightbulb'></i></h1></div><br>";
  textoHTML += "<button id='change' class='btn btn-dark px-4 rounded-0'><i class='fas fa-toggle-on'></i> Led</button><br>";
  textoHTML += "<button id='voice' class='btn btn-dark px-4 rounded-0 mt-3'><i class='fas fa-microphone'></i> Comando</button></div>";
  textoHTML += "<script src='https://code.jquery.com/jquery-3.4.1.min.js'></script><script>$('#light-on, #light-off').addClass('d-none'); ";
  textoHTML += "$('#change').click(function (e) {e.preventDefault(); ";
  textoHTML += "$.get('/led/change', function (data) {data.led == '1' ? $('#light-on').removeClass('d-none') : $('#light-on').addClass('d-none');";
  textoHTML += "data.led == '0' ? $('#light-off').removeClass('d-none') : $('#light-off').addClass('d-none');});});";
  textoHTML += "function ledStatus() {$.get('/led/status', function (data) {data.led == '1' ? $('#light-on').removeClass('d-none') : $('#light-on').addClass('d-none');";
  textoHTML += "data.led == '0' ? $('#light-off').removeClass('d-none') : $('#light-off').addClass('d-none');});}";
  textoHTML += "$('#refresh').click(() => ledStatus()); ledStatus();";
  textoHTML += "try {var SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;var recognition = new SpeechRecognition();";
  textoHTML += "}catch (e) {console.error(e);alert('No Browser Support');}";
  textoHTML += "recognition.continuous = true;recognition.onresult = function (event) {var current = event.resultIndex;var transcript = event.results[current][0].transcript;";
  textoHTML += "var mobileRepeatBug = (current == 1 && transcript == event.results[0][0].transcript);";
  textoHTML += "if (!mobileRepeatBug) {$.get('/command', { text: transcript },function (data, textStatus, jqXHR) {";
  textoHTML += "console.log(data);},);}};$('#voice').click(function (e) {e.preventDefault();recognition.start();});";
  textoHTML += "recognition.onstart = function () {$('#voice').toggleClass().addClass('btn btn-warning px-4 rounded-0 mt-3')};";
  textoHTML += "recognition.onspeechend = function () {$('#voice').toggleClass().addClass('btn btn-dark px-4 rounded-0 mt-3')};";
  textoHTML += "recognition.onerror = function (event) {$('#voice').toggleClass().addClass('btn btn-danger px-4 rounded-0 mt-3');alert(event)}</script></body></html>";

  server.send(200, "text/html", textoHTML);
  digitalWrite(indicator, 0);
}
