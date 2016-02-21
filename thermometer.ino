#include <OneWire.h>
#include <DallasTemperature.h>
#include <LedControl.h>

#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LedControl lc1=LedControl(11,9,10,1);

float temp = 0;

void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();

  lc1.shutdown(0,false); //0 verwijst naar nummer chip
  lc1.setIntensity(0,8);
  lc1.setChar(0,7,'6',false);
  lc1.setChar(0,6,'6',false);
  lc1.setChar(0,5,'6',false);
   
}


void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures
  temp = sensors.getTempCByIndex(0);
  int tempint = int(temp*10);
  int decimal = tempint%10;
  tempint = tempint/10;
  int one = tempint%10;
  tempint = tempint/10;
  int ten = tempint;
  Serial.println(temp);
  lc1.setDigit(0,7,ten,false);
  lc1.setDigit(0,6,one,true);
  lc1.setDigit(0,5,decimal,false);
  lc1.setRow(0,4,B01100011);
  lc1.setRow(0,3,B01001110);
  delay(1000);
