#include <SFML/Graphics.hpp>
#include<string.h>
#include "Invaders.h"
using namespace sf;
using namespace std;


#ifndef GYMMA_H
#define GYMMA_H

class Gymma: public Invaders {
public:
     
     Gymma(){}
     virtual void setimage(std::string png_path) {
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   
   }
   
   virtual ~Gymma(){}

};   

#endif  // GYMMA_H
