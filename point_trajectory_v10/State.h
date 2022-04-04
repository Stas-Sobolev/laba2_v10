#pragma once
#ifndef STATE_H_
#define STATE_H_
#include"Body.h"
class State
{
public:
	virtual void change_state(Body* body, time_ delta) = 0;
	virtual State* clone()const = 0;
};
#endif // !STATE_H_
