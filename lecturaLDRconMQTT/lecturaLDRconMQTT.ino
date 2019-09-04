/*
 * 
 * En este programa escribiremos la información luminosa captada por un sensor LDR hacia el Broker mosquitto instalado en una raspberry Py
 * El programa esta escrito para ser ejecutado sobre una placa de desarrollo ESP8266 montada en un NodeMCU
 * 
 * @author : Jesus Barajas
 * 3 de Septiembre de 2019
 * 
*/
 
#include <ESP8266WiFi.h> //Biblioteca para ESP8266
#include <PubSubClient.h> //Biblioteca para MQTT

//Definimos variables globales
const char* ssid = "AVERNO"; //Nombre de la red
const char* password = "M0v13lee@nuX7g";//Contraseña de red
const char* mqtt_server = "192.168.10.133";//Establecemos la dirección IP del servidor
char msg[50];
const int LDR = A0; //Puerto de entrada A0 en al placa ESP8266
WiFiClient espClient; //Creamos un objeto de tipo WIFI client, https://links2004.github.io/Arduino/dc/da7/class_wi_fi_client.html
PubSubClient client(espClient); //Sea crea un objeto de tipo PubSubClient con el constructor client(client), esto es posible porque WIFIClient hereda de Client
                                //Aun tenemos que configurar el servidor, esto se hara en la parte de setup

void setup() {
  Serial.begin(9500); //Velociada de envio de mensajes
  setup_wifi(); //Llamado a funcion 
  client.setServer(mqtt_server, 1883); // Configuracion del servidor, por default el Broker tendra el puerto 1883 abierto, 
                                       // mientras que mqtt_server es la dirección ip que definimos un poco mas arriba
  }


 /*
  * Método que conecta mediante WiFi por parte del ESP8266
  */
void setup_wifi() {                    
  delay(10);
  
  // Informacion del la red wifi a la que se va esta intentando conectar
  Serial.println();
  Serial.print("Conectando a la red ");
  Serial.println(ssid);//Nombre de la red WiFi
  WiFi.begin(ssid, password); //Inicia la peticion de conexión WifI

  //En caso de que no se pueda establecer conexión se va a reintentar hasta lograrlo
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);//retraso de medio segundo para vovler a intentar
    Serial.print("*");
  }
  
  //Cuando se logra establecer la conexión  
  Serial.println("\n WiFi conectado \n Dirección IP: ");
  Serial.println(WiFi.localIP());//Se imprime la IP del servicio al que esta conectado, esta debe de ser la misma que nosotros ingresamos en un principio
}

/*
 * Método que soluciona fallas en la conexión de red
 */
 
void reconnect() {
   while (!client.connected()) { //Si no estamos conectados
      Serial.print("Reconectando...");
   
      if (client.connect("ESP8266Client")) {//Si logramos conectar
        client.publish("IIMAS/laboratorio1/LDR", "Empezando escritura"); //Se empieza la comunicación y con la escritura en el topic
      }
      else {//Si se continua en este estado
        Serial.print("No es posible reconectar=");
        Serial.print(client.state());
        Serial.println("Intentando de nuevo en 5 segundos");
        delay(5000);
      }
    }
  }
 
void loop() {
  int entrada = analogRead(LDR); //Se lee la entrada análoga 
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(200);
  snprintf (msg, 75, "Voltaje: %ld", entrada);
  Serial.print("Publish message: ");//Terminal local
  Serial.println(msg);//Terminal local 
  client.publish("IIMAS/laboratorio1/LDR", msg);//Mensaje que se publica en el topic
}
