
int ledPins[] = {2,3,4,5,6,7,8,9};
int temperaturePin = 0;
 

void setup()
{
  Serial.begin(9600);
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){
      pinMode(ledPins[i],OUTPUT);
  }
}
 
 
/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop()                
{
  float temperature = getVoltage(temperaturePin);
  temperature = (temperature - 0.5) * 100;
  Serial.println(temperature);
  showTemperature(temperature);
  delay(1000);
}

void showTemperature(float temperature){
    //reset previous state
    for(int i = 0; i < 8; i++){        
      digitalWrite(ledPins[i], LOW);
  }
  
  int res;
  
  if(temperature >= 23.0){
    res = ledPins[0];
  } else if(temperature >= 22.0){
   res = ledPins[1];
  } else if(temperature >= 21.0){
   res = ledPins[2];
  } else if(temperature >= 20.0){
   res = ledPins[3];
  } else if(temperature >= 19.0){
   res = ledPins[4];
  } else if(temperature >= 18.0){
   res = ledPins[5];
  } else if(temperature >= 17.0){
   res = ledPins[6];
  } else if(temperature < 17.0){
   res = ledPins[7];
  }
  
  digitalWrite(res, HIGH);
}

float getVoltage(int pin){
  float res;
  
  res = analogRead(pin) * .004882814;
  
  return res;
}

