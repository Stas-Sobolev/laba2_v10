#include "TaskBody.h"
#include<cmath>
std::vector<std::string> TaskBody::tick(time_ delta)
{
    _state->change_state(this, delta);
    return { " " };
}

std::string TaskBody::description()
{
    return "state_body";
}

Sprite* TaskBody::clone() const
{
    return new TaskBody(*this);
}

void TaskBody::fly(speed_ V, angle_ angle) 
{
    double Vx;
    double Vy;
    Vx = V * cos(angle);
    Vy = V * sin(angle);

    set_Vx(Vx);
    set_Vy(Vy);

    delete _state;
    _state = new FlyState;
}

void TaskBody::stay() 
{
    if (get_place().get_y() < 0.1)
    {
        
        delete _state;
        _state = new StayState;
    }
}

void TaskBody::explotion(weight_ m) 
{
    double Vx = get_Vx();
    double Vy = get_Vy();
    double M = get_M();
    double x = get_place().get_x();
    double y = get_place().get_y();
    double Vy_2;
    double V = sqrt(Vx * Vx + Vy * Vy);
    if (Vy <= 0)
    {
        Vy_2 = Vy * (M - m) / (M - m);
    }
    else
        Vy_2 = (Vy * (M + m) / (M - m));
    set_Vy(Vy_2);
    set_Vx(Vx);

    set_M(M - m);

    TaskBody* lower_body = new TaskBody(get_world(), get_place(), 0, Vy / 2, m);

    delete _state;
    delete lower_body->_state;

    _state = new FlyState;
    lower_body->_state = new FlyState;

    get_world()->add_sprite(lower_body);
}

TaskBody::TaskBody(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy, weight_ M) : Body(world,place,Vx,Vy,M)
{
    _state = new StayState;
}

TaskBody::TaskBody(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy, weight_ M):
    TaskBody(world,WorldPoint(world,x,y),Vx,Vy,M) {}

TaskBody::TaskBody(const TaskBody& orig):
    TaskBody(orig.get_world(),orig.get_place(),orig.get_Vx(),orig.get_Vy(),orig.get_M())
{
    _state = orig._state->clone();
}


