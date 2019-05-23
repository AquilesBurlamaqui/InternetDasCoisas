
# Internet das Coisas

Tutorial md https://guides.github.com/features/mastering-markdown/


## Disciplina ministrada na graduação da Escola de Ciências e Tecnologia da UFRN


* Projeto 1 - [Criação de Página HTML e exibição do gráfico ThingSpeak](projeto1/readme.md)
* Projeto 2 - [Atualização do gráfico ThingSpeak via sensor do celular](projeto2/readme.md)
* Projeto 3 - [Substituição do ThingSpeak por sistema web e banco de dados](projeto3/readme.md)
* Projeto 4 - [Utilização do NODEMCU+sensores em substituição dos sensores do celular](projeto4/readme.md)
* Projeto 5 - [Utilização do protocolo MQTT (Usando Broker na Nuvem).](projeto5/readme.md)
* Projeto 6 - [Node-Red](projeto6/readme.md)
* [Projetos Finais](projetosfinais/readme.md)


## Contribuidores 

- Jilcimar
- Vinícius
- Maria Emanuele
- Bruno

## Dicas
  # Código para reset
  
``` C
  /*
 * circuits4you.com
 * ESP8266 software reset demo
 * This program counts from 1 to 20
 * and resets at 6 count before completing counting
*/
#include <ESP8266WiFi.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int i;
  
  for(i=0;i<20;i++)
  {
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    delay(500);                       // wait for a second
    Serial.print("count");
    Serial.println(i);

    if(i==6)
    {
      Serial.println("Resetting ESP");
      ESP.restart(); //ESP.reset();
    }
  }
}
```
