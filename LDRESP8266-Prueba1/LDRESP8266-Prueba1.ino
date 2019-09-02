/*
 * 
 * Programa para arduino que modula la intensidad de brillo de un led mediante la cantidad de luz que recibe un sensor ldr.
 * 
 * @author Jesus Barajas
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 //Update these with values suitable for your network.
const char* ssid = "AVERNO";
const char* password = "M0v13lee@nuX7g";
const char* mqtt_server = "192.168.10.133";
 
const int LED_PIN = 5; //Puerto de salida D1 en la placa ESP8266
const int LDR = A0; //Puerto de entrada A0 en al placa ESP8266
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600); //Imprimir en terminal de IDE arduino
  pinMode(LED_PIN, OUTPUT); //LED en el pin 4 es la salida
  }

void loop() {
  int entrada = analogRead(LDR); //Se lee la entrada análoga 
  entrada = entrada - 600;//Bajamos la intensidad de voltaje que recibe para darle mayor sensibilidad 
  analogWrite(LED_PIN, entrada);//Se manda como salida a LED_PIN el valor que se reciba de la entrada LDR sobre 4 para que sea un valor menor que 256
  delay(150); //tiempo entre dos ciclos loop
  Serial.print("Voltaje = ");//Cadena
  Serial.println(entrada); //Cantidad de voltaje que estaa recibiendo nuestra resistencia
  }
