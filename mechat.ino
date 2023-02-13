#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "ESP_MICRO.h"


#define motorENAleft D5
#define motorleft1 D3
#define motorleft2 D4

#define motorENAright D0
#define motorright1 D1
#define motorright2 D2

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
//ESP8266WebServer server(80);
int flag=0;
float dis=0;
float deg=0;
void setup() {
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  
pinMode(motorENAleft,OUTPUT);
pinMode(motorleft1,OUTPUT);
pinMode(motorleft2,OUTPUT);
pinMode(motorENAright,OUTPUT);
pinMode(motorright1,OUTPUT);
pinMode(motorright2,OUTPUT);

digitalWrite(motorright1,LOW);
digitalWrite(motorright2,LOW);
digitalWrite(motorleft1,LOW);
digitalWrite(motorleft2,LOW);

analogWrite(motorENAright,500);
analogWrite(motorENAleft,500);

  server.begin();
  //Serial.println("HTTP server started");
}
void loop() {

  delay(300);
  waitUntilNewReq();
  flag=1;
  String a=getPath();
  
  char b1 = a.charAt(1);

  float c1=(float)(b1);
  char b2 = a.charAt(2);
  float c2=(float)(b2);
  char b3 = a.charAt(3);
  float c3=(float)(b3);

  if(c3==0)
  {
    dis=c2-48;
    dis=(dis+1.8133)/3.1807;
    deg=((dis+10.895)/10.705)*2.15;
  }
  else
  {
    dis=10*(c2-48)+c3-48;
    dis=(dis+1.8133)/3.1807;
    deg=((dis+10.895)/10.705)*2.15;

  }
  Serial.println(c1);

  if(c1==74)
  {
  Serial.println("go forward");
  
  digitalWrite(motorleft1,HIGH);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,HIGH);
  digitalWrite(motorright2,LOW);
  delay(dis*100);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,LOW);
  digitalWrite(motorright2,LOW);
  c1=0;
  returnThisInt(5);

  }


  if(c1==98)
  {
  Serial.println("go backward");

  digitalWrite(motorleft2,HIGH);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorright2,HIGH);
  digitalWrite(motorright1,LOW);
  delay(dis*100);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,LOW);
  digitalWrite(motorright2,LOW);
    c1=0;
      returnThisInt(5);

  }

if(c1==108)
  {
  Serial.println("turn left");

    
  digitalWrite(motorleft2,HIGH);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorright1,HIGH);
  digitalWrite(motorright2,LOW);
  delay(deg*100);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,LOW);
  digitalWrite(motorright2,LOW);
    c1=0;
      returnThisInt(5);

  }

  
if(c1==114)
  {
  Serial.println("turn right");
  
  digitalWrite(motorleft1,HIGH);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright2,HIGH);
  digitalWrite(motorright1,LOW);
  delay(deg*100);
  digitalWrite(motorleft1,LOW);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,LOW);
  digitalWrite(motorright2,LOW);
    c1=0;
      returnThisInt(5);

    
  }
  
  
  returnThisInt(5);
}




