#pragma once
#ifndef SPRITE_H_
#define SPRITE_H_

#include"WorldPoint.h"

class Sprite : public WorldObject
{
private:
	World* _world;
	WorldPoint _place;
public:
	std::string get_point() const;
	World* get_world() const;
	const WorldPoint& get_place() const;

	void set_world(World* world);
	void set_place(const WorldPoint& place);

	Sprite(World* world, const WorldPoint& place);
	Sprite(World* world, coordinate_ x, coordinate_ y);

	virtual Sprite* clone() const = 0;
};
#endif