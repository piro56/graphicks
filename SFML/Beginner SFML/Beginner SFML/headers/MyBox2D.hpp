#pragma once

#include <box2d/box2d.h>


class MyBox2D
{
private:

	b2World* world;
	const float timestep = 1.0f / 6000.0f;
	int32 velocityIterations = 1;
	int32 positionIterations = 1;

	b2BodyDef groundBodyDef;
	b2PolygonShape groundBox;

	b2Body* groundBody;

public:
	b2Body* dynamicBody;

	MyBox2D();
	void init();
	void simulate();

};