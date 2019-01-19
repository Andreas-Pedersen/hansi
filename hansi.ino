/*  Andreas Pedersen
 *  2018.
 *  Leser data fra HAN-porten og sender det videre til HS3 via NODE-RED på port 1880 /han?data=
 */
 
#include <ESP8266WiFi.h>
//////////////////////////////////////////////////////////
////////////// PERSONLIGE VARIABLER //////////////////////
//////////////////////////////////////////////////////////

const char* ssid = "mittnettverk";      // Navn på wifi-nettverk
const char* password = "passord";   // Passord til dette
const char* host = "192.168.0.10";       // IP TIL NODE-RED
const String url = "/postboks?data="; // hvilken url Node red lytter på
const int port = 1880;          // PORT TIL NODE-RED

int gotData = 0;
String data = "";  
char lager[260];

void setup() {
  Serial.begin(2400,SERIAL_8N1);   
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
 delay(5000);
}

void loop() {

if(Serial.available()>0){
  int i=0;
  while(Serial.available() > 0){
    data += Serial.read();
    data += ",";
    delay(5);
    if (Serial.available() < 5){   //vent litt hvis det er lite data i bufferen
      delay(25);
    }
  }
  gotData = 1;
}

if (gotData != 0){
    
    WiFiClient client;
 
    if (!client.connect(host, int(port))) {
      Serial.println("connection failed");
      return;
    }
  
    client.print(String("GET ") + url + String(data) + " HTTP/1.1\r\n" + "Host: " + host + "\r\n\r\n");
    gotData = 0;
    data = "";
 
 }

}  // THE-END
