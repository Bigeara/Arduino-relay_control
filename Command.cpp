
#include "Command.h"
#include "Relay.h"

namespace rg
{

Command::~Command()
{

}




RelayCommand::RelayCommand(Relay & obj)
: Command()
, mRelay(obj)
{

}

void RelayCommand::action()
{
    mRelay.toggle();
}



MultiRelayCommand::MultiRelayCommand(Relay * const relayList, int nRelays)
: Command()
, mRelayList(relayList)
, mRelays(nRelays)
{

}

void MultiRelayCommand::action()
{
    for ( int i = 0; i < mRelays; ++i) {
        mRelayList[i].toggle();
    }
}


FunctionCommand::FunctionCommand(void (&func)(Relay * const, int), Relay * const relayList, int nRelays)
: Command()
, mFunction(func)
, mRelayList(relayList)
, mInt(nRelays)
{

}

void FunctionCommand::action()
{
    mFunction(mRelayList, mInt);
}



NoCommand::NoCommand()
: Command()
{

}

void NoCommand::action()
{

}


}
