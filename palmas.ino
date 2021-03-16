// Código acender e apagar led com palmas 
//Autor: Pedro Lins

#define relay 7 //define o pino do relay
#define sensor 8 //define o pino digital onde está conectada a sáda digital do microfone.
bool estado_atual_sensor = LOW;//aplicando uma váriavel booleana para controle da condição de leitura definindo qual estado do microfone no momento
bool estado_anterior_sensor = LOW;//aplicando uma váriavel booleana para controle da condição de leitura
bool estado_relay = HIGH;// variável que gurada o estado do relay

void setup() {
  pinMode(relay,OUTPUT);// define o pino do relay como saída, justamente para o envio do sinal 
  pinMode(sensor,INPUT);// define o pino digital como INPUT para leitura dos dados
  Serial.begin(9600);// inicializa a serial em 9600 bits 
  digitalWrite(relay,HIGH);// inicializa o relay desligado
}

void loop() {
  estado_atual_sensor = digitalRead(sensor); // envia para variável o estado do sensor se está em high ou low
  Serial.print("estado_atual_sensor: "+String(estado_atual_sensor)); // realiza o print na serial do estado do sensor lido no momento 
  Serial.println("estado_anterior_sensor: "+String(estado_anterior_sensor));//realiza o print na serial do estado anterior do sensor
  if((estado_atual_sensor == HIGH)&&(estado_anterior_sensor == LOW)) {// Condicional que se verdadeira realiza a troca da variável booleana estado_relay 
    estado_relay = !estado_relay;// troca do estado do relay para true ou para false dependendo do estado que estava anteriormente
    Serial.println("entrouu");// print na serial que entrou na condicional 
    digitalWrite(relay,estado_relay);//comando que aciona ou desaciona o relay e conseguentemente o led ou lâmpada conectado ao mesmo
    delay(200);//delay de 200 ms para o som de uma palma não ser detectado mais de uma vez 
  }else{
    Serial.println("nao entrou");//realiza o print na serial caso não tenha entrado na condicional a cima
  }
  estado_anterior_sensor = estado_atual_sensor; //momento em que a variável estado_anterior_sensor recebe seu valor  antes de entrar no próximo loop 
