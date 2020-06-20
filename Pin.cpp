
#include "Pin.h"
#include <Arduino.h>

namespace rg
{

Pin::Pin(int pinNumber)
: mPinNumber(pinNumber)
, mState()
{
  pinMode(mPinNumber, OUTPUT);
}

void Pin::on()
{
  mState = true;
  digitalWrite(mPinNumber, HIGH);
}

void Pin::off()
{
  mState = false;
  digitalWrite(mPinNumber, LOW);
}

void Pin::toggle()
{
  if(mState == false){
    on();
  }
  else {
    off();
  }
}

bool Pin::isOn()
{
  return mState;
}

}
