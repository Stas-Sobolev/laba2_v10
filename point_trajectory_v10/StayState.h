#pragma once
#include "FlyState.h"
class StayState : public State
{
public:
	// Унаследовано через State
	virtual void change_state(Body* body, time_ delta) override;

	// Унаследовано через State
	virtual State* clone() const override;
};

