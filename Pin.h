#ifndef _pin_h
#define _pin_h

namespace rg
{

class Pin
{
public:
    Pin(int pinNumber);
    void on();
    void off();
    void toggle();
    bool isOn();
private:
    int mPinNumber;
    bool mState;
};

}

#endif
