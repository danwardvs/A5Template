#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <Box2D/Box2D.h>
#include <box.h>
#include <vector>

// Events
ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
ALLEGRO_TIMER* timer = nullptr;
ALLEGRO_DISPLAY *display;

// Fps timer
int fps;
double old_time = 0;
const float MAX_FPS = 60;
int frames_array[100];
int frame_index = 0;

// Closing or naw
bool closing = false;

float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;


  //B2_NOT_USED(argc);
	//B2_NOT_USED(argv);

	// Define the gravity vector.
b2Vec2 gravity(0.0f, -10.0f);

	// Do we want to let bodies sleep?
bool doSleep = true;

	// Construct a world object, which will hold and simulate the rigid bodies.
b2World gameWorld(gravity, doSleep);

b2Body* body;


box myBox;

std::vector<box> gameBoxes;

void create_box(float newX, float newY){
  box newBox;
  newBox.init(newX,newY,&gameWorld);
  gameBoxes.push_back(newBox);
}

void setup_b2(){



	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -39.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = gameWorld.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 0.0f);
	body = gameWorld.CreateBody(&bodyDef);

  create_box(0.8,0);
  create_box(0.25f,1);


	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.

	// This is our little game loop.

		// Now print the position and angle of the body.

}

void setup(){


  al_init();

  al_install_keyboard();
  al_install_mouse();
  al_install_joystick();

  al_init_primitives_addon();


  timer = al_create_timer(1.0 / MAX_FPS);

  display = al_create_display(800, 600);

  event_queue = al_create_event_queue();
  al_register_event_source( event_queue, al_get_display_event_source(display));
  al_register_event_source( event_queue, al_get_timer_event_source(timer));
  al_register_event_source( event_queue, al_get_keyboard_event_source());
  al_register_event_source( event_queue, al_get_joystick_event_source());

  al_start_timer(timer);






}



void draw(){
}

void update(){


    // Event checking
  ALLEGRO_EVENT ev;
  al_wait_for_event( event_queue, &ev);

  // Timer
  if( ev.type == ALLEGRO_EVENT_TIMER){

    // Update
    		gameWorld.Step(timeStep, velocityIterations, positionIterations);



  }
  // Exit
  else if( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
    closing = true;

  }

  if( al_is_event_queue_empty(event_queue)){

    // Draw


    al_clear_to_color( al_map_rgb(0,255,0));

    //draw();
    for(int i=0; i<gameBoxes.size(); i++)
      gameBoxes[i].draw();

    al_flip_display();

    // Update fps buffer
    for( int i = 99; i > 0; i--)
      frames_array[i] = frames_array[i - 1];
    frames_array[0] = (1.0/(al_get_time() - old_time));
    old_time = al_get_time();

    int fps_total = 0;
    for( int i = 0; i < 100; i++)
      fps_total += frames_array[i];

    // FPS = average
    fps = fps_total/100;
  }
}


int main(int argc, char **argv){

  setup();
  setup_b2();


  while(!closing)
    update();

  al_destroy_display(display);


  return 0;
}
