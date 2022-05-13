class Flex{
  public:
    const float VCC = 5;      // voltage at Ardunio 5V line
    const float R_DIV = 10000.0;  // resistor used to create a voltage divider
    const float flatResistance = 25000.0; // resistance when flat
    const float bendResistance = 100000.0;  // resistance at 90 deg
    int FlexPin;
    void FlexBegin(int Pin){
      FlexPin=Pin;
      pinMode(FlexPin,INPUT);
      }
    float getAngle(){
      int ADCflex = analogRead(FlexPin);
      float Vflex = ADCflex * VCC / 1023.0;
      float Rflex = R_DIV * (VCC / Vflex - 1.0);

  // Use the calculated resistance to estimate the sensor's bend angle:
      float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
      return angle;
      }
    
  };