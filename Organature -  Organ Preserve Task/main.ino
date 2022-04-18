//These values are in the datasheet
#define RT0 10000   // Ω
#define B 3977      // K
//--------------------------------------


#define VCC 5    //Supply voltage
#define R 10000  //R=10KΩ

char inputByte;
double maxValue, minValue;
int redLed = 8;         // pin of the red LED
int greenLed = 9;       // pin of the green LED
double maxTemp = 37.5;
double minTemp = 36.5;
int i = 0;

int buzzer= 4;
int maxlimit;
int minlimit;

//Variables
float RT, VR, ln, TX, VRT;
float T0=25;



void setup() {

  pinMode(buzzer,OUTPUT);
  
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  
  Serial.begin(9600);
  
  T0 += 273.15;
}

void loop() {
  
   inputByte = Serial.read();

  switch (inputByte){
    case 'a': maxTemp += 1;       // max up
            break;
    case 'b': maxTemp -= 1;       // max down
            break;
    case 'c': minTemp += 1;       // min up
            break;
    case 'd': minTemp -= 1;       // min down
            break;
    default: break;
    }

    
    VRT = analogRead(A0);              //Acquisition analog value of VRT
    VRT = (5.00 / 1023.00) * VRT;      //Conversion to voltage
    VR = VCC - VRT;
    RT = VRT / (VR / R);               //Resistance of RT
    
    ln  = log(RT / RT0);
    TX = (1 / ((ln / B) + (1 / T0))); //Temperature from thermistor

    TX = TX - 273.15;                 //Conversion to Celsius
    
    if (minTemp > TX || maxTemp < TX){
      digitalWrite(redLed,HIGH);
      digitalWrite(greenLed,LOW);
      digitalWrite(buzzer,HIGH);
      tone(buzzer,1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer,200);
      delay(100);
      noTone(buzzer);
     }
     else{
       digitalWrite(greenLed,HIGH);
       digitalWrite(redLed,LOW);
       digitalWrite(buzzer,LOW);
      }
      
      String dataV = String(int (TX));
      Serial.print(dataV);
      delay(200);
}
