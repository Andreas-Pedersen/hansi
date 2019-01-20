/*  Andreas Pedersen
 *  2018.
 *  Leser data fra HAN-porten og sender det videre til HS3 via NODE-RED på port 1880 /han?data=
 */

#include "config_prod.h" 
#include <ESP8266WiFi.h>

int gotData = 0;
String data = "";  
char lager[260];

void setup() {
  Serial.begin(2400,SERIAL_8N1);   
  WiFi.begin(secret_ssid, secret_ssid_password);
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
 
    if (!client.connect(secret_nodered_host, secret_nodered_port)) {
      Serial.println("connection failed");
      return;
    }
  
    client.print(String("GET ") + secret_nodered_url + String(data) + " HTTP/1.1\r\n" + "Host: " + secret_nodered_host + "\r\n\r\n");
    gotData = 0;
    data = "";
 
 }

}  // THE-END
