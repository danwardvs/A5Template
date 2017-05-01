#ifndef BOX_H
#define BOX_H
#include <allegro5/allegro.h>
#define BOX 0

class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;

class Box{
  public:
    Box();
    ~Box();
    void init(float, float, b2World *);
    void init(float, float, float, b2World *);
    void draw();
    void update();
    int getType();

  protected:

    int type;

    float x;
    float y;
    float angle;
    ALLEGRO_COLOR color = al_map_rgb(0,0,0);

    float width;
    float height;

    b2World *gameWorld;
    b2Body *body;






};


#endif // BOX_H
