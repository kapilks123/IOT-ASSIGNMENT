const int ldr=16;
const int led=22;
int val; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(ldr);
Serial.println(val);
if(val>=1500)
{
  digitalWrite(led,1);

}
else
{
  digitalWrite(led,0);
  delay(1000);
}
}
