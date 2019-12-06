No projeto 4 eu substituir o sensor do celular, por um sensor de UMIDADE TERRESTE, desenvolvi um sensor que mede a umidade do solo, para isso eu usei o Esp8266 NodeMCU e o sensor, junto a isso, os dados coletados do sensor são direcionados para um dos meus canais do ThingSpeak. 

-O Esp8266 é um Módulo WiFi ESP8266 NodeMcu ESP-12. O módulo Wifi ESP8266 NodeMCU é uma placa de desenvolvimento que combina o chip ESP8266, uma interface usb-serial e um regulador de tensão 3.3V. Utilizando a comunicação via cabo micro-usb. 

  - Foto de todo o sistema em funcionamento.
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto4/turma2019.2/Matheus%20Cavalcante/Proje4.png.jpeg).


-O código utilizado para tal projeto foi 

```javascript
#include <ESP8266WiFi.h> 
//defines 
#define SSID_REDE "Brasil" //coloque aqui o nome da rede que se deseja conectar 
#define SENHA_REDE "13032018" //coloque aqui a senha da rede que se deseja conectar 
#define INTERVALO_ENVIO_THINGSPEAK 30000 //intervalo entre envios de dados ao ThingSpeak (em ms) 
//constantes e variáveis globais 
char EnderecoAPIThingSpeak[] = "api.thingspeak.com"; 
String ChaveEscritaThingSpeak = "WRVJ7UG72VH3L9MR"; 
long lastConnectionTime; 
WiFiClient client; 
//prototypes 
void EnviaInformacoesThingspeak(String StringDados); 
void FazConexaoWiFi(void); 
float FazLeituraUmidade(void); 
/* 
* Implementações 
*/ 
//Função: envia informações ao ThingSpeak 
//Parâmetros: String com a informação a ser enviada 
//Retorno: nenhum 
void EnviaInformacoesThingspeak(String StringDados) 
{ 
if (client.connect(EnderecoAPIThingSpeak, 80)) 
{ 
//faz a requisição HTTP ao ThingSpeak 
client.print("POST /update HTTP/1.1\n"); 
client.print("Host: api.thingspeak.com\n"); 
client.print("Connection: close\n"); 
client.print("X-THINGSPEAKAPIKEY: "+ChaveEscritaThingSpeak+"\n"); 
client.print("Content-Type: application/x-www-form-urlencoded\n"); 
client.print("Content-Length: "); 
client.print(StringDados.length()); 
client.print("\n\n"); 
client.print(StringDados); 
lastConnectionTime = millis(); 
Serial.println("- Informações enviadas ao ThingSpeak!"); 
} 
} //Função: faz a conexão WiFI 
//Parâmetros: nenhum 
//Retorno: nenhum 
void FazConexaoWiFi(void) 
{ 
client.stop(); 
Serial.println("Conectando-se à rede WiFi..."); 
Serial.println(); 
delay(1000); 
WiFi.begin(SSID_REDE, SENHA_REDE); 
while (WiFi.status() != WL_CONNECTED) 
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println(""); 
Serial.println("WiFi connectado com sucesso!"); 
Serial.println("IP obtido: "); 
Serial.println(WiFi.localIP()); 
delay(1000); 
} //Função: faz a leitura do nível de umidade 
//Parâmetros: nenhum 
//Retorno: umidade percentual (0-100) 
//Observação: o ADC do NodeMCU permite até, no máximo, 3.3V. Dessa forma, 
// para 3.3V, obtem-se (empiricamente) 978 como leitura de ADC 
float FazLeituraUmidade(void) 
{ 
int ValorADC; 
float UmidadePercentual; 
ValorADC = analogRead(0); //978 -> 3,3V 
Serial.print("[Leitura ADC] "); 
Serial.println(ValorADC); 
//Quanto maior o numero lido do ADC, menor a umidade. 
//Sendo assim, calcula-se a porcentagem de umidade por: 
// 
// Valor lido Umidade percentual 
// _ 0 _ 100 
// | | 
// | | 
// - ValorADC - UmidadePercentual 
// | | 
// | | 
// _|_ 978 _|_ 0 
// 
// (UmidadePercentual-0) / (100-0) = (ValorADC - 978) / (-978) 
// Logo: 
// UmidadePercentual = 100 * ((978-ValorADC) / 978) 
UmidadePercentual = 100 * ((978-(float)ValorADC) / 978); 
Serial.print("[Umidade Percentual] "); 
Serial.print(UmidadePercentual); 
Serial.println("%"); 
return UmidadePercentual; 
} void setup() 
{ 
Serial.begin(9600); 
lastConnectionTime = 0; 
FazConexaoWiFi(); 
Serial.println("Planta IoT com ESP8266 NodeMCU"); 
} //loop principal 
void loop() 
{ 
float UmidadePercentualLida; 
int UmidadePercentualTruncada; 
char FieldUmidade[11]; 
//Força desconexão ao ThingSpeak (se ainda estiver desconectado) 
if (client.connected()) 
{ 
client.stop(); 
Serial.println("- Desconectado do ThingSpeak"); 
Serial.println(); 
} 
UmidadePercentualLida = FazLeituraUmidade(); 
UmidadePercentualTruncada = (int)UmidadePercentualLida; //trunca umidade como número inteiro 
//verifica se está conectado no WiFi e se é o momento de enviar dados ao ThingSpeak 
if(!client.connected() && 
(millis() - lastConnectionTime > INTERVALO_ENVIO_THINGSPEAK)) 
{ 
sprintf(FieldUmidade,"field1=%d",UmidadePercentualTruncada); 
EnviaInformacoesThingspeak(FieldUmidade); 
} 
delay(1000); 
} 
```
-Exemplo do meu projeto em Funcionamento.
https://thingspeak.com/channels/900038/charts/1?bgcolor=%23ffffff&color=%23d6 2020&dynamic=true&results=60&type=line&update=15 

