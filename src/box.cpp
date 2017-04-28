#include "box.h"
#include <Box2D/Box2D.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#define PI 3.14159263

box::box(){


}

void box::init(float newX, float newY, b2World *newGameWorld){

  width = 1.5;
  height = 1.5;

  gameWorld = newGameWorld;
  b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(newX, newY);
	body = gameWorld -> CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width/2, height/2);

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

void box::init(float newX, float newY, float newFloat, b2World *newGameWorld){


}


void box::draw(){

  b2Vec2 position = body -> GetPosition();
  x = position.x;
  y = position.y;
  angle = body -> GetAngle();

  ALLEGRO_TRANSFORM trans, prevTrans;

  // back up the current transform
  al_copy_transform(&prevTrans, al_get_current_transform());

  // scale using the new transform
  al_identity_transform(&trans);

  al_rotate_transform(&trans, -angle);
  al_translate_transform(&trans, (x+width/2)*20, -(y+width/2)*20);

  al_use_transform(&trans);

  //al_draw_filled_rectangle(x*20, -y*20, (x+2)*20 , (-y+2)*20,al_map_rgb(255,0,0));

  al_draw_rectangle(-(width/2)*20, -(height/2)*20, (width/2)*20 , (height/2)*20,al_map_rgb(0,0,0),3);

  al_draw_filled_rectangle(-(width/2)*20, -(height/2)*20, (width/2)*20 , (height/2)*20,al_map_rgb(255,0,0));





  // restore the old transform
  al_use_transform(&prevTrans);

}

box::~box(){


}
