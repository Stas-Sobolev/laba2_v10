#include "StayState.h"

void StayState::change_state(Body* body, time_ delta)
{
}

State* StayState::clone() const
{
    return new StayState(*this);
}
