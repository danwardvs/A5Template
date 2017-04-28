#ifndef BOX_H
#define BOX_H

class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;

class box{
  public:
    box();
    ~box();
    void init(float, float, b2World *);
    void init(float, float, float, b2World *);
    void draw();

  private:
    float x;
    float y;
    float angle;

    float width;
    float height;

    b2World *gameWorld;
    b2Body *body;




};


#endif // BOX_H
