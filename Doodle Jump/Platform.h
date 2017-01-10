#pragma once
#include "Entity.h"
#include "PlatformType.h"

using namespace sf;

class Platform : public Entity {
	bool _isLive;
protected:
	PlatformType name;

	Platform(String file, Vector2f coord) : Entity(file, coord), _isLive(true) {}
	Platform() {}
public:
	virtual void update(float time,float dy) {}
	void kill() { _isLive = false; }
	bool isLive() const { return _isLive; }
	PlatformType getName() const { return name; }

	virtual ~Platform() {}
};