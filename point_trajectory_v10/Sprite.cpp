#include"Sprite.h"

std::string Sprite::get_point() const
{
	return _place.get_point();
}

World* Sprite::get_world() const
{
	return _world;
}

const WorldPoint& Sprite::get_place() const
{
	return _place;
}

void Sprite::set_world(World* world)
{
	_world = world;
}

void Sprite::set_place(const WorldPoint& place)
{
	_place = place;
}

Sprite::Sprite(World* world, const WorldPoint& place):_world(world),_place(place){}


Sprite::Sprite(World* world, coordinate_ x, coordinate_ y):Sprite(world,WorldPoint(world,x,y)){}



