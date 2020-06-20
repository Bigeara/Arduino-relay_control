
#include "Pin.h"
#include "Relay.h"
#include "Command.h"

void printBanner(rg::Relay * const relayList, int nRelays)
{
  const char lineChar = '|';
  const char openChar = '/';
  const char spaceChar = ' ';
  Serial.print('\n');
  for (int i = 0; i < nRelays; ++i) {
    Serial.print(i+1);
    Serial.print(lineChar);
    Serial.print(spaceChar);
  }
  Serial.print('\n');

  for (int i = 0; i < nRelays; ++i) {
    Serial.print(spaceChar);
    relayList[i].isOn() ? Serial.print(lineChar) : Serial.print(openChar);
    Serial.print(spaceChar);
  }
  Serial.print('\n');

  for (int i = 0; i < nRelays; ++i) {
    Serial.print(spaceChar);
    Serial.print(lineChar);
    Serial.print(spaceChar);
  }
  Serial.print('\n');
  Serial.print('\n');

  for (int i = 0; i < nRelays; ++i) {
    Serial.print(i);
    Serial.print(": ");
    Serial.print(relayList[i].getName());
    Serial.print('\n');
  }
}

rg::Relay relayList[7] = {
    rg::Relay("One", 2),
    rg::Relay("Two", 3),
    rg::Relay("Three", 4),
    rg::Relay("Four", 5),
    rg::Relay("Five", 6),
    rg::Relay("Six", 7),
    rg::Relay("Seven", 8)
  };


struct MenuItem
{
  char cmdChar;
  rg::Command & cmd;
};

rg::RelayCommand toggle0 {relayList[0]};
rg::RelayCommand toggle1 {relayList[1]};
rg::RelayCommand toggle2 {relayList[2]};
rg::RelayCommand toggle3 {relayList[3]};
rg::RelayCommand toggle4 {relayList[4]};
rg::RelayCommand toggle5 {relayList[5]};
rg::RelayCommand toggle6 {relayList[6]};
rg::MultiRelayCommand toggleGroupA {&(relayList[0]), 4};

rg::FunctionCommand help {printBanner, relayList, 7};

rg::NoCommand nothing {};

MenuItem commands[9] = {
  {'1', toggle0 },
  {'2', toggle1 },
  {'3', toggle2 },
  {'4', toggle3 },
  {'5', toggle4 },
  {'6', toggle5 },
  {'7', toggle6 },
  {'?', nothing },
  {'a', toggleGroupA }
};

void clearScreen()
{
  Serial.write(27);
  Serial.write("[2J");
  Serial.write(27);
  Serial.write("[H");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  printBanner(relayList, 7);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);

  int incomingByte;

  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    for (int i = 0; i < 9; ++i) {
      if (incomingByte == commands[i].cmdChar) {
        commands[i].cmd.action();
        clearScreen();
        help.action();
        break;
      }
    }
  }
}
