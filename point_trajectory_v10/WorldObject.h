#pragma once
#ifndef WORLDOBJECT_H_
#define WORLDOBJECT_H_
#include<string>
#include<vector>

namespace my_type

{
	using time_ = unsigned long long int;
	using speed_ = double;
	using coordinate_ = double;
	using acceleration_ = double;
	using angle_ = double;
	using weight_ = double;
}

using namespace my_type;

class WorldObject
{
public:
	virtual std::vector<std::string> tick(time_ delta) = 0;
	virtual std::string description() = 0;
};
#endif // !WORLDOBJECT_H_
