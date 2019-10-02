/*
 * 
 * Programa para sensor de Humedad y Temperatura HTC11 , 
 * sobre una placa de desarrollo ESP8266 
 * @author Jesus Barajas
 * 
 */
 #include <DHT.h>//Importamos biblioteca de Adafruit, recordemos que debemos de tenerla instalda, 
                 //junto con la biblioteca Sensro Master, tambien de Adafruit

 #define DHTdata 5 //El pin donde el sensor mandará los datos sera el D1
 #define DHTtype DHT11 //Usaremos el densor DHT11

 DHT dht(DHTdata,DHTtype);//Iniciamos el sensor con los datos requeridos
 
 void setup() {
 Serial.begin(9600); //Inicializamos comunicación con el serial
 dht.begin();//Iniciamos el sensor
}

void loop() {
  float humedad = dht.readHumidity();//Obtenemos la humedad relativa que lee el sensor
  float temperatura = dht.readTemperature();//Obtenemos la temperatura en grados centigrafos que lee el sensot
  
if(!isnan(humedad) and !isnan(temperatura)){//Si las dos no tiene resultados nulos, es decir el sensor opera bien

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\n");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" *C \n");//Temperatura en grados Centigrados  
   
}
delay(2000);
}
