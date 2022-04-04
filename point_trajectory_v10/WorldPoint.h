#pragma once
#ifndef WORLDPOINT_H_
#define WORLDPOINT_H_

#include "World.h"

class WorldPoint 
{
private:

	coordinate_ _x;
	coordinate_ _y;
	World* _world;
public:

	void set_world(World* world);

	void set_x(coordinate_ x);

	void set_y(coordinate_ y);

	coordinate_ get_x() const;

	coordinate_ get_y() const;

	World* get_world() const;

	std::string get_point() const;

	//constructors
	WorldPoint(World* world, coordinate_ x, coordinate_ y);
	WorldPoint(World* world);



};

#endif // !1




