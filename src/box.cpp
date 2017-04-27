#include "box.h"
#include <Box2D/Box2D.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

box::box(){


}

void box::init(float newX, float newY, b2World *newGameWorld){

  gameWorld = newGameWorld;
  b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(newX, newY);
	body = gameWorld -> CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);


}

void box::draw(){

  b2Vec2 position = body -> GetPosition();
  x = position.x;
  y = position.y;

  al_draw_filled_rectangle(x*20, -y*20, (x+2)*20 , (-y+2)*20,al_map_rgb(255,0,0));
}

box::~box(){


}
