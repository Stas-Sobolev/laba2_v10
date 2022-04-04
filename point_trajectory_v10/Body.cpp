#include "Body.h"

Body::Body(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy, weight_ M) :
	Sprite(world, place), _Vx(Vx), _Vy(Vy), _M(M) {}


Body::Body(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy, weight_ M):
	Sprite(world, WorldPoint(world, x, y)), _Vx(Vx), _Vy(Vy), _M(M) {}

void Body::set_Vx(speed_ Vx)
{
	_Vx = Vx;
}

void Body::set_Vy(speed_ Vy)
{
	_Vy = Vy;
}

void Body::set_M(weight_ M)
{
	_M = M;
}

speed_ Body::get_Vx() const
{
	return _Vx;
}

speed_ Body::get_Vy() const
{
	return _Vy;
}

weight_ Body::get_M() const
{
	return _M;
}



