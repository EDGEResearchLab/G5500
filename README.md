# G5500
Arduino library for interfacing with the Yaesu G-5500 controller for el/az antenna positioners.  Use the standard Arduino process for installing and using this library.

This is a very simple Arduino library intended to make it possible to easily control Yaesu's G-5500 controller (and the el/az positioner that it connects to).  It requires 5 digital pins (4 for motor control and 1 for an activity LED) and 2 analog pins.  For now, you'll need to edit the .h file with your specific pin assignments.

Instantiation of an instance:
G5500 rotator = G5500()

Public functions:
 - void setAzEl(int azimuth, int elevation) takes integer degrees, and serially sets the azimuth then the elevation.  Range checks for in-range values (0-450 azimuth, 0-180 elevation).
 - void setAz(int azimuth) same as above, but azimuth only.
 - void setEl(int elevation) same as above, but elevation only.
 - int getAz() returns raw ADC values for the azimuth feedback voltage.
 - int getEl() same as above for elevation.
 - int getAzDegrees() returns calculated position in degrees from 0 for azimuth.
 - int getElDegrees() same as above for elevation.

Pins used:
 - move antenna east (+az): 8
 - move antenna west (-az): 9
 - move antenna up (+el)  : 10
 - move antenna down (-el): 11
 - motor activity LED pin : 13
 - Elevation feedback Vin : A0
 - Azimuth feedback Vin   : A1

Examples: 
G5500_InputAzEl waits for user input for azimuth and elevation values then commands the positoner to that location
G5500_QueryPosition can be used (along with the Out Voltage Adj. potentiometer on the back of the G-5500) to calibrate your positioner to the expectations of the library. 

Hardware used: 
Arduino Mega 2560
Freetronics ProtoShield
4x jumper wires
4x 8.2kOhm resistors
4x 4N4401 transistors
3 lengths of 8-conductor cable (for making connections to/from the G-5500)
1x Yaesu G-5500 El/Az positioner system

You'll want to consult the G-5500 manual (http://www.yaesu.co.uk/files/G-5500%20Operating%20Manual_a.pdf) and the manual for the factory interface, the GS-232A (http://polysat.calpoly.edu/download/earthstation/documents/gs-232a.pdf) for full information.  Both manuals are also included in this repo.  Note that there appears to be an error, as observed feedback voltages on the development G-5500 do not match what's indicated in the manuals.  This code works with the development setup, and it may be necessary to tweak yours to work with it.  