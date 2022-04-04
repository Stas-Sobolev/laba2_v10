#include "Location.h"
#include"TaskBody.h"
std::vector<std::string> Location::tick(time_ delta)
{
    std::vector<std::string> result;
    for (auto sprite : _sprites) 
    {
        sprite->tick(delta);
        result.push_back(sprite->get_point());
    }
    return result;
}

std::string Location::description()
{
    return "location";
}

void Location::set_gravity(acceleration_ gravity)
{
    _gravity = gravity;
}

void Location::set_width(coordinate_ width)
{
    _width = width;
}

void Location::set_height(coordinate_ height)
{
    _height = height;
}

acceleration_ Location::get_gravity() const
{
    return _gravity;
}

coordinate_ Location::get_width() const
{
    return _width;
}

coordinate_ Location::get_height() const
{
    return _height;
}

void Location::add_sprite(Sprite* sprite)
{
    _sprites.push_back(sprite);
}

Location::Location(coordinate_ width, coordinate_ height, acceleration_ gravity, const std::list<Sprite*>& sprites)
{
    _width = width;
    _height = height;
    _gravity = gravity;
    _sprites = sprites;
  
}

Location::~Location()
{
    for (auto sprite : _sprites)
        delete sprite;
}

Location::Location(const Location& orig)
{
    _width = orig.get_width();
    _height = orig.get_height();
    _gravity = orig.get_gravity();
    for (auto sprite : orig._sprites)
        this->add_sprite(sprite->clone());
}

const Location& Location::operator=(const Location& orig)
{
    if (this == &orig)
        return *this;
    _width = orig.get_width();
    _height = orig.get_height();
    _gravity = orig.get_gravity();
    if (!(_sprites.empty())) 
    {
        for (auto sprite : _sprites)
            delete sprite;
        _sprites.clear();
    }
    for (auto sprite : orig._sprites)
        this->add_sprite(sprite->clone());
}


void Location::fly(speed_ V, angle_ alpha)
{
    for (auto sprite : _sprites)
        if (sprite->description() == "state_body")
            ((TaskBody*)sprite)->fly(V, alpha);
}

void Location::stay()
{
    std::list<Sprite*> copy_sprites(_sprites);
    for (auto sprite : copy_sprites)
        if (sprite->description() == "state_body")
            ((TaskBody*)sprite)->stay();
}

void Location::explotion(weight_ M)
{
    std::list<Sprite*> copy = _sprites;
    for (auto sprite : copy)
        if (sprite->description() == "state_body")
            ((TaskBody*)sprite)->explotion(M);
}


