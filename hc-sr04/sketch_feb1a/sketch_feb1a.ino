#include "ThingSpeak.h"
#include "WiFi.h"

char ssid[] = "TIKONA WIFI";
char pass[] = "adityakaushik";
int ledpin = 16;
int inputpin = 2;
int pirState = LOW;
int val =0;
WiFiClient client;
//thingspeak details
unsigned long myChannelField =;
const int ChannelField = 1;
const char * myWriteAPIKey = "";
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(inputpin, INPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

}
void loop()
{
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("attepting to connect to ssid");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
    {
      WiFi.begin(ssid,pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nconnected");
  }

val = digitalRead(inputpin);
if (val == HIGH){
  digitalWrite(ledpin, HIGH);
  if (pirState == LOW){
    Serial.println("motion detected\n");
    pirState = HIGH;

  }
}
else{
  digitalWrite(ledpin, LOW);
  if (pirState == HIGH){
    Serial.println("motion ended");
    pirState = LOW;
  }
}
ThingSpeak.writeField(myChannelField,ChannelField,val,myWriteAPIKey);
delay(1000);
}