#define LED_PIN_A 22
#define LED_PIN_B 32
#define LED_PIN_C 16
void setup() {

  // put your setup code here, to run once:
pinMode(LED_PIN_A,OUTPUT);
pinMode(LED_PIN_B,OUTPUT);
pinMode(LED_PIN_C,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_PIN_A,HIGH);
digitalWrite(LED_PIN_B,HIGH);
digitalWrite(LED_PIN_C,HIGH);
Serial.println("all 3 led is on\n");
delay(2000);
digitalWrite(LED_PIN_A,LOW);
digitalWrite(LED_PIN_B,LOW);
digitalWrite(LED_PIN_C,LOW);
Serial.println("led is off\n");
delay(2000);
}
