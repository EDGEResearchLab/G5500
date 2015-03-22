//Written for the Arduino Mega 2560 - not validated on any other
//Arduino board (though it seems like it should work).
//David Patterson, 22-Mar-2015

#include <G5500.h>

G5500 rotor = G5500();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  printStatus();
  delay(500);
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
