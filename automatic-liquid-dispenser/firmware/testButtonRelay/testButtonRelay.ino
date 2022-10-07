void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
pinMode(1, INPUT);
//pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(1)) {
digitalWrite(5, HIGH);
  
} else {
digitalWrite(5, LOW);  
}

}
