//Written for the Arduino Mega 2560 - not validated on any other
//Arduino board (though it seems like it should work).
//David Patterson, 22-Mar-2015

#include <G5500.h>

G5500 rotor = G5500();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100000);
}

void loop() {
  // put your main code here, to run repeatedly:
  printStatus();
  Serial.println("Enter desired az: ");
  int azimuth = Serial.parseInt();
  Serial.println("Enter desired el: ");
  int elevation = Serial.parseInt();
  Serial.print("Setting azimuth to: ");
  Serial.println(azimuth);
  Serial.print("Setting elevation to: ");
  Serial.println(elevation);
  Serial.println();
  rotor.setAzEl(azimuth, elevation); 
}

void printStatus()
{
  int az = rotor.getAzDegrees();
  int el = rotor.getElDegrees();
  Serial.print("Current Az: ");
  Serial.print(az);
  Serial.print(" Current El: ");
  Serial.println(el);
}
