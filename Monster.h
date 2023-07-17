#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
using namespace sf;
using namespace std;

#ifndef MONSTER_H
#define MONSTER_H

class Monster: public Enemy {
public:

   Monster(){}
   virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
 
   }
   
/*  
   Monster(std::string png_path)
   {
     this->sprite.setScale(0.09,0.09);
     tex.loadFromFile(png_path);
     this->sprite.setTexture(tex);
     x=310;y=75;
     sprite.setPosition(x,y); 
   }
*/
   virtual ~Monster(){}
};

#endif  // ENEMY_H

