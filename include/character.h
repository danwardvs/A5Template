#ifndef CHARACTER_H
#define CHARACTER_H

#include "box.h"
class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;

class character : public box{
  public:
    character();
    ~character();
    void init(float, float, b2World *);
    void init(float, float, float, b2World *);
    void draw();

  private:




};


#endif // CHARACTER_H
