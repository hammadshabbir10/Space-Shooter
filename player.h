#include <SFML/Graphics.hpp>
#include<string.h>
#include "Bullet.h"
#include "Addon.h"
using namespace sf;
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
   
    Texture tex;
    Sprite sprite;
    float speed = 0.8;
    int x,y;

    //std::vector<Bullet> bullets;
    Bullet* bul;    
    int bulnum = 0;	
    int shoot_bullet = 10;
    Player(){}
  
    Player(std::string png_path) {

     tex.loadFromFile(png_path);
     sprite.setTexture(tex);
     x=340;y=600;
     sprite.setPosition(x,y);
     sprite.setScale(0.9,0.9);
     
   }

//1.  


   void fire() {
    
      
    if(bulnum==0)
    {
      
       bul = new Bullet[10];
       bul[0].pos(sprite.getPosition().x,sprite.getPosition().y);
       bulnum++;
   
    }
    else
    {
     
       Bullet temparr[bulnum+1];
       for(int i=0; i<bulnum; i++)
       {
           temparr[i] = bul[i];
       }
       
       delete[] bul;
       bul = new Bullet[bulnum+1];
      
       for(int i=0; i<bulnum+1; i++)
       {
          bul[i] = temparr[i];
       }
       
       bul[bulnum].pos(sprite.getPosition().x,sprite.getPosition().y);
       bulnum++;
    }
    
     bul[bulnum-1].move();
  }
  

//2.
  void change_picture(string s) {
  
      tex.loadFromFile(s);
      sprite.setTexture(tex);
  }     
   
 
   
  void move(string s) {
   
  float delta_x=0,delta_y=0;
   
  if(s == "l") 
     delta_x = -1;	//move the player left
  else if(s == "r")
     delta_x = 1; 	//move the player right
  else if(s =="u")
     delta_y = -1;	//move the player to top
  else if(s == "d")
     delta_y = 1;	//move the player to bottom
  else if (s == "ul"){
     delta_x = -1;
     delta_y = -1;
  }
  else if (s == "ur"){
     delta_x = 1;
     delta_y = -1;
  }  
  else if (s == "dr"){
     delta_x = 1;
     delta_y = 1;
  }
  else if (s == "dl"){
     delta_x = -1;
     delta_y = 1;
  } 
   delta_x*=speed;
   delta_y*=speed;


// Wrap around the screen horizontally
   
    if (sprite.getPosition().x < 0) 
        sprite.setPosition(780,sprite.getPosition().y);    // Move to the right side of the screen
    else if (sprite.getPosition().x > 780)
        sprite.setPosition(0,sprite.getPosition().y);      // Move to the left side of the screen

// Wrap around the screen vertically

    if (sprite.getPosition().y < 0)
        sprite.setPosition(sprite.getPosition().x,780);   // Move to the bottom of the screen
    else if (sprite.getPosition().y > 780)
        sprite.setPosition(sprite.getPosition().x,0);              // Move to the top of the screen

   sprite.move(delta_x, delta_y);

  }

};


#endif  // PLAYER_H

