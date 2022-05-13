class Ldr{
  private:
const double k = 5.0/1024;
const double luxFactor = 500000;
const double R2 = 10000;
const double LowLightLimit = 200; 
const double B = 1.3*pow(10.0,7);
const double m = -1.4;
 int Pin; 
 
 public:
  void ldrBegin(int pin){
    Pin=pin;
    pinMode(Pin,INPUT);
  }
  float get_intensity () {  
    int RawADC0= analogRead(Pin);
    RawADC0= map(RawADC0,0,4096,0,1023);
    float V2 = k*RawADC0;
    float R1 = (6.0/V2 - 1)*R2;
    float lux = B*pow(R1,m);
    return lux;}
    
    

};