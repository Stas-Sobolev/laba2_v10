#pragma once
#include "StayState.h"
class TaskBody : public Body
{
private:
	State* _state;
public:
	// Унаследовано через Body
	virtual std::vector<std::string> tick(time_ delta) override;

	virtual std::string description() override;

	virtual Sprite* clone() const override;

	virtual void fly(speed_ V, angle_ angle) override;

	virtual void stay() override;

	virtual void explotion(weight_ m) override;

	//constructors
	TaskBody(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy, weight_ M);
	TaskBody(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy, weight_ M);

	TaskBody(const TaskBody& orig);
	const TaskBody& operator= (const TaskBody& orig) = delete;
};

