class UltraSonic {
  private:
  float SOUND_SPEED= 0.034;
  float CM_TO_INCH= 0.393701;
  public:
    int echoPin;
    int trigPin;
    float distanceCm;
    void UltraBegin(int echoPin, int trigPin){
      this->echoPin= echoPin;
      this->trigPin= trigPin;
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    }
    float getDistance(){
      digitalWrite(trigPin, LOW);
       delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
      float duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
     distanceCm = duration * SOUND_SPEED/2;
     return distanceCm;
    }
};