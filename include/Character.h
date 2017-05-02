#ifndef CHARACTER_H
#define CHARACTER_H

#include "globals.h"
#include "Box.h"
#include "keyListener.h"

class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;
class keyListener;

class Character : public Box{
  public:
    Character();
    ~Character();
    void init(float, float, b2World *, keyListener *);
    void draw();
    void update();

  private:
    keyListener *gameKeyListener;
    b2Body *sensor_body;




};


#endif // CHARACTER_H
