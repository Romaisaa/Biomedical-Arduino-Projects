class airQuality{
  private:
  float sensorValue;
  public:
  int Pin;
  airQuality(int Pin){
    this->Pin= Pin;
  }
  float getQuality(){
    sensorValue = analogRead(Pin); // read analog input pin 0

    return sensorValue;
    //100-150 normal air
// 700 Alcohol
//750 Lighter gases
  }
  
};