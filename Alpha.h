#include <SFML/Graphics.hpp>
#include<string.h>
#include "Invaders.h"
using namespace sf;
using namespace std;

#ifndef ALPHA_H
#define ALPHA_H


class Alpha: public Invaders {
public:
     
     Alpha(){}
     virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   
   }
   
   virtual ~Alpha(){}

};   

#endif  // ALPHA_H
