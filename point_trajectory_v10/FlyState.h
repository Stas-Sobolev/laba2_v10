#pragma once
#include "State.h"
class FlyState : public State
{
public:
	// ������������ ����� State
	virtual void change_state(Body* body, time_ delta) override;

	// ������������ ����� State
	virtual State* clone() const override;
};

