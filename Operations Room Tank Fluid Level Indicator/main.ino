// LEDs Pins
int l1=6;
int l2=9;
int l3=10;

// Other Pins
const int analog_0 = A0;
const int buzzer = 4;
const int buttonPin = 5;

// Water level variables
int level;
int minLevel = 0;

// Button Variable
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(buzzer, OUTPUT);
}


void loop() {  
  level = analogRead(analog_0);
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH && level>0) {
    int sum=0;
    for(int i=0; i<50; i++){
      level=analogRead(analog_0);
      sum+= level;
    }
  minLevel = sum/50;
  
  // Serial.println(minLevel);
  delay(500);
  }
  
  level = level - minLevel;
  Serial.println(level);
  if(level>-10&&level<20)
  { 
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
  else if(level>20&&level<50)
  {
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, LOW);
  }
  else if(level>40)
  {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, HIGH);
    if(minLevel > 0){
      tone(buzzer, 3000);
      delay(1000);
      noTone(buzzer);
      delay(1000);
    }
 }
}
