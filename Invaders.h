#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
using namespace sf;
using namespace std;

#ifndef INVADERS_H
#define INVADERS_H

class Invaders: public Enemy {
public:
   
    Invaders(){}
    virtual void setimage(std::string png_path) = 0;
    virtual ~Invaders(){}
    
};   


#endif  // INVADERS_H


