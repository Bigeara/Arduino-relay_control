#ifndef _command_h
#define _command_h



namespace rg
{

class Relay;

class Command
{
public:
  virtual ~Command();
  virtual void action() = 0;
};

class RelayCommand: public Command
{
public:
  RelayCommand(Relay & obj);
  virtual void action();
private:
  Relay & mRelay;
};

class MultiRelayCommand: public Command
{
public:
  MultiRelayCommand(Relay * const relayList, int nRelays);
  virtual void action();
private:
  Relay * const mRelayList;
  const int mRelays;
};

class FunctionCommand: public Command
{
public:
  FunctionCommand(void (&func)(Relay * const, int), Relay * const relayList, int nRelays);
  virtual void action();
private:
  void (&mFunction)(rg::Relay * const, int);
  Relay * const mRelayList;
  const int mInt;
};

class NoCommand: public Command
{
public:
    NoCommand();
    virtual void action();
};

}
#endif