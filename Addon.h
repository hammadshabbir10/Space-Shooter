#include <SFML/Graphics.hpp>
#include<string.h>
#include<cstdlib>
#include<ctime>

using namespace sf;
using namespace std;


#ifndef ADDON_H
#define ADDON_H


class Addon {

public:
    
    float speed = 0.3;
    Texture tex;
    Sprite sprite;
    bool checker = false;   
  
  Addon(){}
  virtual void setimage(std::string png_path) = 0; 

   
    void move() {
      
      if(sprite.getPosition().y > 750){
      checker = true;} 
      
      float delta_x=0,delta_y=0;
      delta_y = 1;

      delta_x*=speed;
      delta_y*=speed;
      sprite.move(delta_x, delta_y);

   }
      
     virtual ~Addon(){}
};



class Powerup: public Addon {

public:

   float speed = 2;
   
Powerup(){}

    virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
  } 
      
   virtual ~Powerup(){}
};



class Danger: public Addon {
public:

  float speed = 2;
Danger(){}
  
     virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   
   }
   
  
 
   virtual ~Danger(){}

};



class Live: public Addon {

public:
float speed = 2;

 Live(){}
     virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
   }  
    
   
   
   virtual ~Live(){}

};

class Fire: public Addon {

public:

   float speed = 2;
   
Fire(){}

    virtual void setimage(std::string png_path){
     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
  } 
      
   virtual ~Fire(){}
};

#endif  // ADDON_H




