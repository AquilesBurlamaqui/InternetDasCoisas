# Sensor de Presença - PIR HC-SR501
![PIR](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQlPwKhonsljaeZ4nTet6fBFs_itHyJSJN2enu6CBj6bLKG9rSi)

## CARACTERÍSTICAS:
* sensor de movimento para Arduino;
* sensor PIR;
* realiza detecção através de sistema infravermelho;
* detecta movimento em uma área de até 7 metros;
* raio de alcance de aproximadamente 100°;
* ajuste do tempo de retardo e sensibilidade;
* tempo de retardo máximo de 200 segundos;
* possui proteção para o ponto sensorial infravermelho;
* datasheet HC-SR501: [Download AQUI](https://www.usinainfo.com.br/index.php?controller=attachment&id_attachment=432).

## ESPECIFICAÇÕES:
* modelo: HCSR501;
* chip: BISS0001;
* alimentação: 5V - 20VDC;
* saída TTL/OUT: 3.3V;
* tempo de retardo ajustável: 2s - 200s;
* distância detectável (ajustável): 3m - 7m;
* ângulo de detecção: < 100° (podendo chegar à 120°);
* dimensões (CxLxA): 32x24x24mm;
* peso: 5g.

__OBS: a alimentação de 3V fornecida pelo módulo ESP8266 também é suficiente para o funcionamento do sensor.__ 

# Sensor de Presença + Motor de Vibração
![sensor + motor de vibração](https://i.imgur.com/D89rDxu.jpg)

### O sensor de presença é usado normalmente em conjunto com outros dispositivos. Foi-se utilizado o motor de vibração para ser acionado em resposta à detecção de movimento obtida pelo sensor, com o seguinte código enviado para o ESP8266:
```
//Definição do pino de saída do sensor PIR
#define PIN_SENSOR D6
//Definição do pino de entrada do motor de vibração
#define PIN_VIBR D7
 
void setup(){
  //Configuração cada um dos pinos como entrada ou saída de dados
  pinMode(PIN_VIBR, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
}
 
void loop(){
  //Faz a leitura do sensor de presença (retorna HIGH ou LOW)
  bool sinal = digitalRead(PIN_SENSOR);
  
  Serial.println(sinal);
  //HIGH : movimento detectado
  if (sinal){
    //aciona o motor
    digitalWrite(PIN_VIBR, HIGH);
    }
  
  //LOW : nenhum movimento detectado
  else{
     //desativa o motor
    digitalWrite(PIN_VIBR, LOW);
    }
}
```
__OBS: no caso desta combinação, quanto maior o tempo ajustado no PIR mais duradouro será o tempo de vibração gerado pelo motor.__

## Referências:
* https://portal.vidadesilicio.com.br/sensor-de-presenca-hc-sr501/
* https://www.robocore.net/loja/sensores/sensor-de-presenca-pir-hc-sr501
* https://www.usinainfo.com.br/sensor-de-movimento-arduino/sensor-pir-sensor-de-movimento-para-arduino-hc-sr501-2634.html
* https://www.youtube.com/watch?v=0SnDHiJaR5M
