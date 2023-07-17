#include <SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;

#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

class EnemyBullet {
public:
    
    Texture tex;
    Sprite sprite;
    float speed = 2;
    int x, y;
    bool active;
    EnemyBullet(){}
    EnemyBullet(std::string png_path){
       
       tex.loadFromFile("img/PNG/Effects/fire01.png");
       sprite.setTexture(tex);
       sprite.setScale(1,1);
       
    } 
      
   void pos(float x1,float y1)
   {
      x=x1,y=y1;
      sprite.setPosition(x,y);
   }        
   
   void move() {
      float delta_x=0,delta_y=0;
      delta_y = 1;
      
      delta_x*=speed;
      delta_y*=speed;
      sprite.move(0, delta_y);
      
   }
              
};

#endif  // ENEMYBULLET_H

