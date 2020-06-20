
#include "Relay.h"
#include <string.h>

namespace rg
{

Relay::Relay(const char * const name, int pinNumber)
: mPin(pinNumber)
, mName()
{
    strcpy(mName, name);
}

//relays are active when pin outputs 0v
void Relay::on()
{
    mPin.off();
}

//relays are disabled when pin outputs 5v
void Relay::off()
{
    mPin.on();
}

void Relay::toggle()
{
    mPin.toggle();
}

bool Relay::isOn()
{
  return !mPin.isOn();
}

const char * Relay::getName()
{
    return mName;
}

}
