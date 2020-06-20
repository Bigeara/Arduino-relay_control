#ifndef _relay_h
#define _relay_h

#include "Pin.h"

namespace rg
{

class Relay
{
public:
  Relay(const char * const name, int pinNumber);
  void on();
  void off();
  void toggle();
  bool isOn();
  const char * getName();
private:
  Pin mPin;
  char mName[30];
};

}

#endif
