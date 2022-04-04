#pragma once
#ifndef LOCATION_H_
#define LOCATION_H_

#include<list>
#include "Sprite.h"

class Location : public World
{
private:
	coordinate_ _width;
	coordinate_ _height;
	acceleration_ _gravity;
	std::list<Sprite*> _sprites;
public:


	// Унаследовано через World
	virtual std::vector<std::string> tick(time_ delta) override;

	virtual std::string description() override;

	virtual void set_gravity(acceleration_ gravity) override;

	virtual void set_width(coordinate_ width) override;

	virtual void set_height(coordinate_ height) override;

	virtual acceleration_ get_gravity() const override;

	virtual coordinate_ get_width() const override;

	virtual coordinate_ get_height() const override;

	virtual void add_sprite(Sprite* sprite) override;

	//constructors
	Location(coordinate_ widht, coordinate_ height, acceleration_ gravity, const std::list<Sprite*>& sprites);
	~Location();
	Location(const Location& orig);
	const Location& operator=(const Location& orig);

	//methods

	void fly(speed_ V,angle_ alpha);
	void stay();
	void explotion(weight_ M);
};
#endif // !1



