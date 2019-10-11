# Projeto 4 - NodeMCU + Switch Button
### Passo 0 - Preparar o Ambiente Arduino - IDE
Adicionar em preferencias->URL adicionais para gerenciamento de placas : http://arduino.esp8266.com/stable/package_esp8266com_index.json

Link com tutorial para instalar a placa ESP e programas iniciais para a placa
https://www.filipeflop.com/blog/programar-nodemcu-com-ide-arduino/


### Passo 1 - Montar o circuito com o NodeMCU e o Switch Button
![button]()


### Passo 2 - Executar o seguinte código que verifica o estado do Switch Button

```c++
/*
 Este codigo tem a função de ler o estado de um botao conectado ao ESP32 e exibe o estado no monitor serial.
*/

// O pino D7 do NodeMCU corresponde ao pino 13 no Arduino, nele esta ligado o switch button; nomeamos ele
int switchbutton = 13;

void setup() {
  // Inicializa a comunicacao serial ah 9600 bits por segundo
  Serial.begin(9600);
  // Define o pino do switch button como entrada
  pinMode(switchbutton, INPUT);
}

void loop() {
  // Ler o pino do switch button
  int buttonState = digitalRead(switchbutton);
  // Escreve no monitor serial o estado do switch button
  Serial.println(buttonState);
  // Adiciona um delay para a estabilidade dos dados
  delay(10);
}

```
