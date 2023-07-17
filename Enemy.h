#include <SFML/Graphics.hpp>
#include<string>
#include "EnemyBullet.h"
using namespace sf;
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:

   Texture tex;
   Sprite sprite;
   int x,y;
   bool checker = false;
   float speed = 0.5; 
   EnemyBullet* bul1 = nullptr;
   int e_b = 0;
   int alive = -1;
   //x=340,y=625;
   //sprite.setPosition(x,y);
  
   Enemy(){} 
   virtual void setimage(std::string png_path) = 0; 
   
   void fire(EnemyBullet& e){
     
     e.sprite.move(0, 0.3);
             
   } 
    

  
    void fire() {
        
    if(e_b==0)
    {
       bul1 = new EnemyBullet[100];
       bul1[0].pos(sprite.getPosition().x,sprite.getPosition().y);
       e_b++;
    }
    else
    {
       EnemyBullet temparr[e_b+1];
       int j=0;
       while(j<e_b) 
       {
           temparr[j] = bul1[j];
           j++;
       }
      
       delete[] bul1;
       bul1 = new EnemyBullet[e_b+1];
       int i =0;
        
       while( i<e_b+1) 
       {
          bul1[i] = temparr[i];
          i++;
       }
       
       bul1[e_b].pos(sprite.getPosition().x,sprite.getPosition().y);
       e_b++;
    }
    
     bul1[e_b-1].move();
  }
  
 
     
    virtual ~Enemy() {
        if (bul1) {
            delete[] bul1;
        }
    }

};


#endif  // ENEMY_H


/*  
   Enemy(std::string png_path)
   {
     this->sprite.setScale(0.5,0.5);
     tex.loadFromFile(png_path);
     this->sprite.setTexture(tex);
     x=340;y=50;
     sprite.setPosition(x,y); 
   }
*/

/*   
    Enemy(std::string png_path, std::string bullet_png_path, float s) {
    bul1 = 0;
        //bul = new EnemyBullet[10];
        for (int i = 0; i < 10; i++) {
            bul1[i] = EnemyBullet(bullet_png_path, s);
        }
    }

    void fire() {
        for (int i = 0; i < 10; i++) {
            if (!bul[i].active) {
                bul[i].pos(sprite.getPosition().x + 20, sprite.getPosition().y + 50);
                break;
            }
        }
    }
*/

