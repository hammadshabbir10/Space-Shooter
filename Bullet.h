#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;

#ifndef BULLET_H
#define BULLET_H
/*
class Bullet {
public:
    
    Texture tex;
    Sprite sprite;
    float speed = 0;
    int x, y;
    Bullet(){}
    Bullet(Texture* texture, Vector2f (pos)){
      
       x =340, y= 655;
       this->sprite.setTexture(*texture);
       this->sprite.setPosition(x,y+20);
       this->sprite.setScale(1, 1);
       this->sprite.setPosition(pos);
       this->sprite.getPosition().x+30, sprite.getPosition().y;
    } 
           
};

*/


class Bullet {
public:
    
    Texture tex;
    Sprite sprite;
    float speed = 4;
    int x, y;

    Bullet() {
      
       tex.loadFromFile("img/PNG/Lasers/laserBlue15.png");
       tex.loadFromFile("img/PNG/Effects/fire19.png");
       sprite.setTexture(tex);
       sprite.setScale(0.75,0.75);
    } 
      
   void pos(float x1,float y1) {
      x=x1,y=y1;
      sprite.setPosition(x+50,y);
   }        
   
   void move() {
      float delta_x=0,delta_y=0;
      delta_y = -1;

      delta_x*=speed;
      delta_y*=speed;
      sprite.move(delta_x, delta_y);

   }
};


#endif  // BULLET_H

