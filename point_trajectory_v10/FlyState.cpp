#include "FlyState.h"

void FlyState::change_state(Body* body, time_ delta)
{
    double Vx = body->get_Vx();
    double Vy = body->get_Vy();
    double g = body->get_world()->get_gravity();
    double x = body->get_place().get_x();
    double y = body->get_place().get_y();

    x = x + Vx * delta;
    y = y + Vy * delta - (g * delta * delta) / 2;
    Vy = Vy - g * delta;

    body->set_Vx(Vx);
    body->set_Vy(Vy);
    
    body->set_place(WorldPoint(body->get_world(), x, y));
}

State* FlyState::clone() const
{
    return new FlyState(*this);
}
