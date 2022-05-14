//#define thumbPin  A0
int thumbPin = A0;
int indexPin = A1;
int middlePin =  A2;
int ringPin = A3;
int littlePin= A4;     

void setup() {
  Serial.begin(9600);
  pinMode(thumbPin, INPUT);
  pinMode(indexPin, INPUT);
  pinMode(middlePin, INPUT);
  pinMode(ringPin, INPUT);
  pinMode(littlePin, INPUT);
  
}

void loop() {

  int ADCThumb = analogRead(thumbPin);
  int ADCIndex = analogRead(indexPin);
  int ADCMiddle = analogRead(middlePin);
  int ADCRing = analogRead(ringPin);
  int ADCLittle = analogRead(littlePin);
  

  // Use the calculated resistance to estimate the sensor's bend angle:
  float thumbAngle = map(ADCThumb, 767, 895, 0, 90.0);
  float indexAngle =map(ADCIndex, 767, 895, 0, 90.0);
  float middleAngle = map(ADCMiddle, 767, 895, 0, 90.0);
  float ringAngle = map(ADCRing, 767, 895, 0, 90.0);
  float littleAngle = map(ADCLittle, 767, 895, 0, 90.0);


  
  Serial.println("Thumb angle " + String(thumbAngle) + " degrees");
  Serial.println("Index angle " + String(indexAngle) + " degrees");
  Serial.println("Middle angle " + String(middleAngle) + " degrees");
  Serial.println("Angle angle " + String(ringAngle) + " degrees");
  Serial.println("Little angle " + String(littleAngle) + " degrees");


  delay(2000);
}
