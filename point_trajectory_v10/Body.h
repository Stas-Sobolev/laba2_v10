#pragma once
#ifndef BODY_H_
#define BODY_H_

#include "Location.h"

class Body : public Sprite
{
private:
	speed_ _Vx;
	speed_ _Vy;
	weight_ _M;
public:
	virtual void fly(speed_ V, angle_ angle) = 0;
	virtual void stay() = 0;
	virtual void explotion(weight_ m) = 0;

	Body(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy, weight_ M);
	Body(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy, weight_ M);

	void set_Vx(speed_ Vx);
	void set_Vy(speed_ Vy);
	void set_M(weight_ M);
	speed_ get_Vx()const;
	speed_ get_Vy()const;
	weight_ get_M()const;
	// Унаследовано через Sprite
	

};

#endif // !1



