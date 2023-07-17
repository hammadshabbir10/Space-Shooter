#include <SFML/Graphics.hpp>
#include<string.h>
#include "Invaders.h"
using namespace sf;
using namespace std;

#ifndef BETA_H
#define BETA_H

class Beta: public Invaders {
public:
     
     Beta(){}
     virtual void setimage(std::string png_path) {
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   
   }
   
   virtual ~Beta(){}

};   

#endif  // BETA_H





