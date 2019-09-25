/*
 * 
 * @author Jesus Barajas
 * Código que concta un sensor PIR montado en una placa NodeMCU, con ESP8266, este publicará en el topic deseado si hay movimento o no
 * 
 */
 
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "WIFI";//Nombre de la red WIFI
const char* password = "password";//Contraseña de ka red WIFI
const char* mqtt_server = "000.000.000.000";//Dirección IP donde se encuentra el broker, en la mayoria de los casos es una Raspberry Py

WiFiClient espClient; //Creamos un objeto de tipo WIFI client, https://links2004.github.io/Arduino/dc/da7/class_wi_fi_client.html
PubSubClient client(espClient); //Sea crea un objeto de tipo PubSubClient con el constructor client(client), esto es posible porque WIFIClient hereda de Client
                                //Aun tenemos que configurar el servidor, esto se hara en la parte de setup

int ledPin = 4;//Pin donde esta el lado positivo del LED de salida
int pirPin = 5;//Pin donde se encuentra el pin de en medio del sensor PIR
int val = 0;//Variable que guarda si hay movimiento o no

long lastMsg = 0;//mensaje
char msg[50];//Arreglo que guarda el mensaje


void setup() {
  pinMode (ledPin,OUTPUT);//LED es salida
  pinMode (pirPin, INPUT);// Sensor PIR es entrada
  Serial.begin(9600);//Velocidad del monitor serial
  setup_wifi(); //Llamado a funcion 
  client.setServer(mqtt_server, 1883); // Configuracion del servidor, por default el Broker tendra el puerto 1883 abierto, 
                                       // mientras que mqtt_server es la dirección ip que definimos un poco mas arriba
  }
void setup_wifi() {                    
 
  WiFi.begin(ssid, password); //Inicia la peticion de conexión WifI
  Serial.print("Conectando a la rer WIFI : ");
  Serial.println(ssid);//Nombre de la red WiFi
  
  //En caso de que no se pueda establecer conexión se va a reintentar hasta lograrlo
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);//retraso de un segundo para vovler a intentar
    Serial.print("*");
  }
  
  //Cuando se logra establecer la conexión  
  Serial.println("\n WiFi conectado \n Dirección IP: ");
  Serial.println(WiFi.localIP());//Se imprime la IP del servicio al que esta conectado, esta debe de ser la misma que nosotros ingresamos en un principio
}

void reconnect() {
   while (!client.connected()) { //Si no estamos conectados
      Serial.print("Reconectando...");
   
      if (!client.connect("ESP8266Client")) {//Si logramos conectar 
        Serial.print("No es posible reconectar");
        Serial.print(client.state());
        delay(5000);
      }
    }
  }

 /*
  * Funcion prinicpal que hará que el snesor PIR detecte movmiento y efecute acciones con base en esto
  */
void loop () {
  val = digitalRead(pirPin);//Leemos si hay movimento o no
  digitalWrite(ledPin,val);// Prendemos el led en caso de haber movimento
  
  if (!client.connected()) {//Retraso por si se pierde la conexión
    reconnect();
  }
  
  client.loop();
  delay(1000);
  
  //Si se quiere conectar otro PIr se debera de camviar el canal hijo, esto porque si ambos estan en el mismo canal movimiento, hay interferencia.
  if (val == 1){
    digitalWrite(ledPin,LOW);
    snprintf (msg, 75, "Se detecta movimiento de sensor 1 %ld", val);
    client.publish("IIMAS/laboratorio1/movimiento/sensor1", msg);//Mensaje que se publica en el topic
  } 
  Serial.println(val);
}
