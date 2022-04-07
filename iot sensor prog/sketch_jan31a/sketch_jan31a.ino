const int ldr=22;
const int led=16;
bool val;
void setup(){
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);

}
void loop()
{
  val=digitalRead(ldr);
  if(val==1)
  {
    digitalWrite(led,1);
    Serial.println("led is glowing\n");
    delay(1000);
  }
  else{
    digitalWrite(led,0);
    delay(1000);
  }
}