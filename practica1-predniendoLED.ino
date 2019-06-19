//11 de Junio de 2019
//Prendiendo de manera intermitente un led

#define LED 13 //LED CONECTADO AL PUERTO, asignacion, la palabra LED al número 13
#define ON HIGH
#define OFF LOW
void setup() {
  pinMode(LED, OUTPUT);//Definimos el puerto 13 como salida
}

void loop() {
  digitalWrite(LED, ON);//Prendemos LED
  delay(1);//Tiempo que dura encendido
  digitalWrite(LED, OFF);//Apagamos LED
  delay(1000);//tiempo que dura apagado
  digitalWrite(LED, ON);//Prendemos LED
  delay(3000);//Tiempo que dura encendido
  digitalWrite(LED, OFF);//Apagamos LED
  delay(1000);//Timepo que dura apagado
}
