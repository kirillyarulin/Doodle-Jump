#pragma once
#include "Entity.h"

class Map : public Entity {
public:
	Map() : Entity("map.png", { 0,0 }) {}

};