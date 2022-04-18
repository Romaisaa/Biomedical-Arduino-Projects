#define sensor 3
#define buzzer 13
char inputByte;
bool flag;

 
void setup() {
Serial.begin(9600);
pinMode(sensor,INPUT);
pinMode(buzzer,OUTPUT);

}
 
void loop() {

  inputByte = Serial.read();
  Serial.println(inputByte);
  
  if(inputByte == 'S')
    flag = true;
  else if (inputByte == 'E')
    flag = false;

    if (flag == true){
      bool value = digitalRead(sensor);
      if(value!= 1){
        digitalWrite(buzzer, HIGH);
      }
      else{
        digitalWrite(buzzer,LOW);
      }
   }
   else{
      digitalWrite(buzzer, LOW);
    }
    
  delay(500);
}
