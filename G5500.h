/*G5500.h - Library for interfacing with the Yaesu G5500 roator
controller.  Note that no particular language support is implied,
as that is left to the user to implement.*/
#ifndef G5500_h
#define G5500_h

#include "Arduino.h"

class G5500
{
  public:
    G5500();
    void setAzEl (int azimuth, int elevation);
    void setAz (int azimuth);
    void setEl (int elevation);
    int getAz ();
    int getEl ();
    int getAzDegrees ();
    int getElDegrees ();
      
  private:
    int _upPin = 10;
    int _downPin = 11;
    int _eastPin = 8;
    int _westPin = 9;
    int _LEDPin = 13;
    int _azSensePin = A1;
    int _elSensePin = A0;
    //All of the following are determined experimentally
    const int _zeroAzPoint  = 2;
    const int _maxAzPoint   = 460;
    const int _zeroElPoint= 0;
    const int _maxElPoint = 960;
    const float _elRes    = 0.1875;
    const float _azRes    = 0.9826;
    //Set for ~2 deg dead zones to avoid chattering the motors
    const int _azDeadZone = 2;
    const int _elDeadZone = 10;
};

#endif
