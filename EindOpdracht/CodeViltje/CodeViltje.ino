#include "HX711.h"

HX711 scale(6, 5);
int const ledPin = 9; 

float calibration_factor = 523;
int units;
float tolerance = 10; 

bool debugMode = false; 

void setup() {
  scale.set_scale();
  scale.tare(); 
  long zero_factor = scale.read_average(); 

  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);  
  Serial.println("Zet een leeg glas op viltje en kijken of het lampje aan is. Zo niet, reset de arduino.");
}

void loop() {
  scale.set_scale(calibration_factor); 
  units = scale.get_units(), 1;
 
  if (units <= tolerance && units >= -tolerance){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 1;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 1;
    else if(temp == 'd' || temp == 'D')
      debugMode = !debugMode;
      Serial.print("Debug Mode: "); 
      Serial.println(debugMode); 
  }
  
  if(debugMode){
     Serial.print("Reading: ");
     Serial.print(units);
     Serial.print(" grams"); 
     Serial.print(" calibration_factor: ");
     Serial.print(calibration_factor);
     Serial.println();
  }

  delay(100);
}
