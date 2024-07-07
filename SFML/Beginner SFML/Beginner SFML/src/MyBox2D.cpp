#include "MyBox2D.hpp"

MyBox2D::MyBox2D()
{
	world = nullptr;
	groundBody = nullptr;
	dynamicBody = nullptr;
}

void MyBox2D::init()
{
	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);

	groundBodyDef.position.Set(0.0f, -10.0f);

	groundBody = world->CreateBody(&groundBodyDef);

	groundBox.SetAsBox(25.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	dynamicBody = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	dynamicBody->CreateFixture(&fixtureDef);
}

void MyBox2D::simulate()
{
	world->Step(timestep, velocityIterations, positionIterations);
}