## Fazer led piscar ao apertar um botão de um controle remoto

	Com o IDE do Arduino configurado para executar os códigos referente ao ESP8266, Faça o download da biblioteca IRremoteESP8266-master e em seguida faça a instalação da mesma na IDE do Arduino.

Componentes usados no projeto:
    - ESP8266
    - Cabo de dados USB
    - 3 jumps fêmea-fêmea
    - Um controle remoto
    - Um receptor infravermelho

	Os Jump fêmea são colocados no GND, VCC e OUT do receptor infravermelho e posteriormente inseridos nos pinos G, 3V e D6 no ESP8266.

	Em seguida, será necessário carregar o código no NodeMCU. Conecte o cabo USB no seu NodeMCU e a outra ponta na porta USB do seu computador. Na IDE confira se a placa selecionada é o NodeMCU e se a porta COM selecionada é a correta.

	O código para testes está abaixo. Porém esse código é apenas para clonar as teclas do controle cujo deseja usar na aplicação. Logo,  basta copiar o mesmo, colar na IDE, salvar e carregar no NodeMCU:

'''
#include <IRremoteESP8266.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 12; //PINO DIGITAL EM QUE O FOTORRECEPTOR ESTÁ CONECTADO - GPIO12 / PINO D6

IRrecv irrecv(RECV_PIN); //VARIÁVEL DO TIPO IRrecv

decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS

void setup(){
  Serial.begin(115200); //INICIALIZA A SERIAL
  irrecv.enableIRIn();  //INICIALIZA O RECEPTOR
}
//MÉTODO RESPONSÁVEL POR FAZER A DECODIFICAÇÃO DO SINAL IR RECEBIDO
//OS DADOS SÃO PASSADOS PARA A BIBLIOTECA IRREMOTE QUE FAZ TODO O
//TRATAMENTO E RETORNA AS INFORMAÇÕES DE ACORDO COM O PROTOCOLO RECONHECIDO
void dump(decode_results *results) {
  int count = results->rawlen;
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  
  Serial.println();
}

void loop() {
  //RETORNA NA SERIAL AS INFORMAÇÕES FINAIS SOBRE O COMANDO IR QUE FOI IDENTIFICADO
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); //RECEBE O PRÓXIMO VALOR
  
} '''

	Após o arquivo ser carregado abra o monitor serial da IDE e verifique se a taxa de velocidade no rodapé do monitor está configurada para 115200 bauds, caso não esteja faça a alteração. Aguarde 10 segundos e em seguida aponte o controle remoto que será clonado para o fotorreceptor IR que está conectado ao NodeMCU e aperte algum dos botões e aguarde o fotorreceptor IR capturar e informar os dados no monitor serial. Nesse projeto, ao apertar a tecla 1, 2 e 3, os valores de respostas foram 9716be3f, 3d9ae3f7 e 6182021b. Vale salientar que é bom clicar mais de uma vez na tecla para ter certeza no código dela, pois pode ocorrer erros durante a resposta do controle.

	Com os códigos dos botões desejados capturados, Agora será necessário colocá-los no código abaixo para fazer com que o LED pisque ao apertar o botão desejado. Nesse caso, ao apertar a tecla 1 o led fica aceso por 1s, caso aperte o botão 2, fica aceso por 2s e assim por diante.

'''
#include <IRremoteESP8266.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 12; //PINO DIGITAL EM QUE O FOTORRECEPTOR ESTÁ CONECTADO - GPIO12 / PINO D6
int pino_led = 2;

IRrecv irrecv(RECV_PIN); //VARIÁVEL DO TIPO IRrecv

decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS

void setup(){
  Serial.begin(115200); //INICIALIZA A SERIAL
  irrecv.enableIRIn();  //INICIALIZA O RECEPTOR

  pinMode(pino_led, OUTPUT);
}
void loop() {


  int aux = false;
  //RETORNA NA SERIAL AS INFORMAÇÕES FINAIS SOBRE O COMANDO IR QUE FOI IDENTIFICADO
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);

  // BOTAO 1
  if ( results.value == 2534850111){
    aux = false;
    digitalWrite(pino_led, LOW);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    delay(1000);                      // Wait for a second
    digitalWrite(pino_led, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(1000);
    irrecv.resume();
    //BOTAO 2
  }else if ( results.value == 1033561079){
    digitalWrite(pino_led, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(2000);                      // Wait for a second
    digitalWrite(pino_led, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(1000);
    
   //BOTAO 3
  }else if( results.value == 1635910171){
    digitalWrite(pino_led, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(3000);                      // Wait for a second
    digitalWrite(pino_led, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(1000);
   

    //BOTAO 4
  }else if ( results.value == 2351064443){
    digitalWrite(pino_led, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(4000);                      // Wait for a second
    digitalWrite(pino_led, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(1000);

  }else if ( results.value == 1217346747){
    digitalWrite(pino_led, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(5000);                      // Wait for a second
    digitalWrite(pino_led, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(1000);
  
    irrecv.resume(); //RECEBE O PRÓXIMO VALOR
  

}
 
'''
