#include "ThingSpeak.h"
#include "WiFi.h"

//wifi delatils
char ssid[] = "TIKONA WIFI";
char pass[] = "adityakaushik";

//declaring 
const int trigger = 16;
const int echo = 22;
const int led = 18;
long T;
float distanceCM;
WiFiClient client;

//thingspeak details
unsigned long myChannelField = 1644749;
const int ChannelField3 = 3;
const char * myWriteAPIKey = "YVUVG2GIM8Y4H2EC";

void setup(){
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led,OUTPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
//wifisetup//
if(WiFi.status()!= WL_CONNECTED)
{
  Serial.print("trying to connect to ssid");
  Serial.println(ssid);
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nconnected");
}
digitalWrite(trigger, LOW);
 delay(1);
 digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
T = pulseIn(echo, HIGH);
distanceCM = (T * 0.034)/2;
Serial.print("distance in cm:");
Serial.println(distanceCM);

ThingSpeak.writeField(myChannelField,ChannelField3,distanceCM ,myWriteAPIKey);
delay(1000);
}