#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
using namespace sf;
using namespace std;

#ifndef DRAGON_H
#define DRAGON_H

class Dragon: public Enemy {
public:

   Dragon(){}
   virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   
   }
/*   
   Dragon(std::string png_path)
   {
     this->sprite.setScale(0.6,0.6);
     tex.loadFromFile(png_path);
     this->sprite.setTexture(tex);
     x=310;y=75;
     sprite.setPosition(x,y); 
   }
*/
   ~Dragon(){}
};

#endif  // ENEMY_H







