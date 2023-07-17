////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					//------------Required Libraries for GamePlay---------------//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <vector>
#include "player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Addon.h"
#include "Dragon.h"
#include "Monster.h"
#include "Invaders.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gymma.h"
using namespace sf;
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

						//-----------Title & Menu-------------// 

const char title[] = "OOP-Project, Spring-2023";
char startOption;
char exitOption;
char instructionOption;
char gameOver;
char Win;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					//------------------Main Class----------------//
class Game {
public:
 
  Sprite background;		//Game background sprite
  Sprite gameOver;
  Sprite instructionOption;
  Sprite exitOption;
  Sprite startOption;
  Sprite menu;
  Sprite Win;
  Sprite danger;
  Sprite explosion;
  Sprite sheiled;
  Sprite beam;
  Sprite fire;
  Texture fireTex;
  Sprite fire_a;
  Texture fireTex_a;
  Sprite fire_b;
  Texture fireTex_b;
  Texture beamTex;
  Texture eplosion_texture;
  Texture bg_texture;
  Texture mu_texture;
  Texture sheild_texture;
  Texture bulletTex;
  Texture enemyTex;
  Texture dragonTex;
  Texture monsterTex;
  Texture powerupTex;
  Texture dangerTex;
  Player* p;			//player 
  Enemy** e1;			//Enemy
  Bullet bullets[10];		// Array to store bullets
  Addon** a;
  int shoot_bullet = 10;	//Bullet 
  int Score = 0;		//Scoring
  int Level = 1;		//Levels
  int Lives = 3;		//Lives 
  bool PowerUp= false; 
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				//------------------Starting Game Constructor------------------//
Game() {
  
   srand(time(0));
   p  =  new Player("img/player_ship.png");
   e1 =  new  Enemy*[5];
   a  =  new Addon*[4];
   a[0]  = new Danger[1]; 
   a[1]  = new Live[1];
   a[2]  = new Powerup[1];
   a[3]  = new Fire[1]; 
   e1[0] = new Alpha[10];
   e1[1] = new Beta[10];
   e1[2] = new Gymma[10];
   e1[3] = new Dragon[1];
   e1[4] = new Monster[1];
   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
   
   						//-----Loading Textures & Images-------//
  
   bg_texture.loadFromFile("img/background.jpg");
   bulletTex.loadFromFile("img/PNG/Lasers/laserBlue15.png");
   enemyTex.loadFromFile("img/enemy_1.png");
   dragonTex.loadFromFile("img/dragon1.png");
   monsterTex.loadFromFile("img/monster.png");
   background.setTexture(bg_texture);
   background.setScale(1.5, 1.5);
   beamTex.loadFromFile("img/Beam.jpeg");
   beam.setTexture(beamTex);
   fireTex.loadFromFile("img/PNG/Effects/fire17.png");
   fire.setTexture(fireTex);
   sheild_texture.loadFromFile("img/PNG/Effects/shield2.png");
   sheiled.setTexture(sheild_texture);
   if(PowerUp = true){                                                                                                                 
   sheild_texture.loadFromFile("img/PNG/Effects/shield2.png");
   sheiled.setTexture(sheild_texture);
   sheiled.setPosition(p->sprite.getPosition().x+400,p->sprite.getPosition().y+500);
   sheiled.setScale(1,1);}
   dangerTex.loadFromFile("img/PNG/Power-ups/danger.png");
   eplosion_texture.loadFromFile("img/explosion.png");
   explosion.setTexture(eplosion_texture);
   explosion.setScale(1,1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
   					
   						//---------Images of Enemies----------//
   
   for(int i=0;i<10;i++){
    e1[0][i].setimage("img/enemy_1.png");  //Alpha Invader Enemy
   }
  
   for(int i=0;i<10;i++){
    e1[1][i].setimage("img/enemy_2.png");  //Beta Invader Enemy
   }
   
   for(int i=0;i<10;i++){
    e1[2][i].setimage("img/enemy_3.png");  //Gymma Invader Enemy
   }
			                          
    for(int i=0;i<1;i++){
    e1[3][i].setimage("img/dragon1.png");  //Dragon Enemy
   }  
  
   for(int i=0;i<1;i++){
    e1[4][i].setimage("img/monster.png");  //Monster Enemy
   }  		
           
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                                  
                                       //--------Images of Addons-----//
   for(int i=0;i<1;i++){
    a[0][i].setimage("img/PNG/Power-ups/danger_1.png");  //Danger
   } 
   
   for(int i=0;i<1;i++){
    a[1][i].setimage("img/PNG/Power-ups/live_2.png");  //Live
   }
   
   for(int i=0;i<1;i++){
    a[2][i].setimage("img/PNG/UI/playerLife2_blue.png");  //Power-up
   }
      
    for(int i=0;i<1;i++){
    a[3][i].setimage("img/PNG/Power-ups/fire.png");  //Fire-up
   }    
   
      //////////////////////////////////////////////////////////////////////////////////////////////////////                             
      
      						//-------Position Setting For Addons-------//
           		//Danger Set                          
           a[0][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);
           a[0][0].sprite.setScale(1,1); 
           
                      //Live Set                            
           a[1][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);
           a[1][0].sprite.setScale(1,1);                          
           
                      //Powerup Set                            
           a[2][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);
           a[2][0].sprite.setScale(1,1); 
           
                       //Fire Set                            
           a[3][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);
           a[3][0].sprite.setScale(1,1);                                                     
    
}
 void start_game() {
    
    
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    clock.restart();
    float timer = 0;
    int shoot_bullets = 0;
    float timere = 0;
    int enemy_count = 0;
    int b_checker = 0;
    int b_checker1 = 0;
    int b_checker2 = 0;
    int b_checker3 = 0;
    int b_checker4 = 0;
    int b_checker5 = 0;
    EnemyBullet eb("img/PNG/Effects/fire02.png");
    bool menu_checker = true;
    bool start_game = false; 
    bool canShoot = true; 
    int selected_option ;
    int prev_option = 0;
    int temp = 0; 
    int temp1 = 0;  
    int temp2 = 0; 
    float addon_timer = 0.0;
    float addon_timer1 = 0.0;
    float addon_timer2 = 0.0;
    float addon_timer3 = 0.0;
    float monster_timer = 0.0;
    float dragon_timer = 0.0;     
    float laser_timer = 0.0;
    float fire_timer = 0.0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;  
        timere += time;
        addon_timer+=time;
        addon_timer1+=time;
        addon_timer2+=time;
        addon_timer3+=time;
        monster_timer+=time;
        dragon_timer+=time;
        laser_timer+= time;
        fire_timer+= time;
        
 	Event e;
        
        					
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        		
						
						//----------Menu display-----------//

if(menu_checker)
{
      
        mu_texture.loadFromFile("img/background3.jpg");
        menu.setTexture(mu_texture);
        menu.setScale(1, 1);
        
        sf::Font font;
        font.loadFromFile("img/ShortBaby-Mg2w.ttf");        //adress of downloaded font
        
        sf::Text title;
        title.setFont(font);
        title.setString("Space Shooter");
        title.setCharacterSize(80);
        title.setFillColor(sf::Color::Red);
        title.setStyle(sf::Text::Bold);
        title.setPosition(150.f, 100.f);

        sf::Text startOption;
        startOption.setFont(font);
        startOption.setString("Start Game");
        startOption.setCharacterSize(40);
        startOption.setFillColor(sf::Color::White);
        startOption.setPosition(250.f, 250.f);
        
        sf::Text instructionOption;
        instructionOption.setFont(font);
        instructionOption.setString("Instructions");
        instructionOption.setCharacterSize(40);
        instructionOption.setFillColor(sf::Color::White);
        instructionOption.setPosition(250.f, 300.f);
        
        
         sf::Text HighestScore;
         HighestScore.setFont(font);
         HighestScore.setString("High Score");
         HighestScore.setCharacterSize(40);
         HighestScore.setFillColor(sf::Color::White);
         HighestScore.setPosition(250.f, 350.f);  
        
                     
        sf::Text gameOver;
        gameOver.setFont(font);
        gameOver.setString("Game Over");
        gameOver.setCharacterSize(40);
        gameOver.setFillColor(sf::Color::White);
        gameOver.setPosition(250.f, 400.f);  
        
        sf::Text exitOption;
        exitOption.setFont(font);
        exitOption.setString("Exit");
        exitOption.setCharacterSize(40);
        exitOption.setFillColor(sf::Color::White);
        exitOption.setPosition(250.f, 450.f);
          
        if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
           menu_checker = false;
       

        if (Keyboard::isKeyPressed(Keyboard::Up)) // If up key is pressed
        {
            selected_option--;
             if (selected_option < 0) selected_option = 3;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
        {
            selected_option++;
              if (selected_option > 3) selected_option = 1;
        }

                  
        if (Keyboard::isKeyPressed(Keyboard::Up)) // If down key is pressed
            selected_option++;		   // move to the next menu option
        if (Keyboard::isKeyPressed(Keyboard::Down)) //If up key is pressed
            selected_option--; 		   // move to the previous menu option    

        if (selected_option == 0) {
    	startOption.setFillColor(sf::Color::Red);
    	exitOption.setFillColor(sf::Color::White);
    	instructionOption.setFillColor(sf::Color::White);
    	gameOver.setFillColor(sf::Color::White);}
	
	else if (selected_option == 1) {
    	startOption.setFillColor(sf::Color::White);
    	exitOption.setFillColor(sf::Color::Red);
    	instructionOption.setFillColor(sf::Color::White);
    	gameOver.setFillColor(sf::Color::White);}

	else if (selected_option == 2) {
    	startOption.setFillColor(sf::Color::White);
    	exitOption.setFillColor(sf::Color::White);
    	instructionOption.setFillColor(sf::Color::Red);
    	gameOver.setFillColor(sf::Color::White);}
	
	else if (selected_option == 3) {
    	startOption.setFillColor(sf::Color::White);
    	exitOption.setFillColor(sf::Color::White);
    	instructionOption.setFillColor(sf::Color::White);
    	gameOver.setFillColor(sf::Color::Red);}
                       
        window.draw(menu);      
        window.draw(title);
        window.draw(startOption);
        window.draw(exitOption);
        window.draw(instructionOption);
        window.draw(HighestScore);
        window.draw(gameOver);
 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					//-----------SAtart the Game----------//
else 
{
        
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed)	 // If cross/close is clicked/pressed
                window.close();		//close the game                        	    
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Up) &&(Keyboard::isKeyPressed(Keyboard::Right))){ //If up key is pressed
		p->change_picture("img/player_ship2.png");
		p->move("ur");}
        else  if (Keyboard::isKeyPressed(Keyboard::Up) && (Keyboard::isKeyPressed(Keyboard:: Left))){ //If up key is pressed
		p->change_picture("img/player_ship1.png");
		p->move("ul");}
        else  if (Keyboard::isKeyPressed(Keyboard::Down )&& (Keyboard::isKeyPressed(Keyboard::Right))){ //If up key is pressed
		p->change_picture("img/player_ship3.png");
		p->move("dr");}
        else  if (Keyboard::isKeyPressed(Keyboard::Down) && (Keyboard::isKeyPressed(Keyboard::Left))){ //If up key is pressed
		p->change_picture("img/player_ship4.png");
		p->move("dl");}

else
{
           p->change_picture("img/player_ship.png");
        if (Keyboard::isKeyPressed(Keyboard::Left)){		//If left key is pressed   
            p->move("l");}   					// Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) {	// If right key is pressed
            p->move("r");}					//player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) {		//If up key is pressed 
            p->move("u"); }					//playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) {		// If down key is pressed
            p->change_picture("img/player_ship5.png");
            p->move("d");} 					//player will move downward
}

       //  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
       //   std::cout << "Mouse position: " << mousePosition.x << ", " << mousePosition.y << std::endl;         
          
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                       //-------------shooting Bullet-------------//
                                       

        if (Keyboard::isKeyPressed(Keyboard::Space)) // If down key is pressed   
           shoot_bullet=1;
        
        if (shoot_bullet==1) {
            p->fire();
            shoot_bullet=0;
        }
        
   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

						//------------Addon Random Falling-----------//
        if(a[0][0].checker){
            a[0][0].checker = false;
            a[0][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);}
            
        if(a[1][0].checker){
            a[1][0].checker = false;
            a[1][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);}
   
        if(a[2][0].checker){
            a[2][0].checker = false;
            a[2][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);}        
            
        if(a[3][0].checker){
            a[3][0].checker = false;
            a[3][0].sprite.setPosition(rand() % (700 - 1 + 1) + 1,0);}                      

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	                                   //----------In game Window------------//
        sf::Font font;
        font.loadFromFile("img/ShortBaby-Mg2w.ttf");        //adress of downloaded font                           
    
        sf::Text display("Score:", font);                       //for Displaying the score on window
        display.setCharacterSize(20);
        display.setFillColor(sf::Color::White);
        display.setPosition(30,8);                            //Postion setting 
        
                                      
        sf:: Text dis_score(std::to_string (Score) , font);      //Score marks 
        dis_score.setCharacterSize(20);
        dis_score.setPosition(90,8);                              
                    
        sf::Text level("Level: ", font);                       //for Displaying the Levels on window
        level.setCharacterSize(20);
        level.setFillColor(sf::Color::White);
        level.setPosition(680,8);                            //Postion setting 
        
                                      
        sf:: Text dis_level(std::to_string (Level) , font);      //Levels 
        dis_level.setCharacterSize(20);
        dis_level.setPosition(740,8); 
    
        sf::Text lives("Lives: ", font);                       //for Displaying the Levels on window
        lives.setCharacterSize(20);
        lives.setFillColor(sf::Color::White);
        lives.setPosition(30,660);                            //Postion setting 
        
                                      
        sf:: Text dis_lives(std::to_string (Lives) , font);   //Levels 
        dis_lives.setCharacterSize(20);
        dis_lives.setPosition(90,660); 
        
        
        sf::Text Name("Hammad Shabbir", font);                 //for Displaying the Name on window
        Name.setCharacterSize(15);
        Name.setFillColor(sf::Color::White);
        Name.setPosition(650,680); 
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        	
     			   	//----------------------Window Draw Scenz---------------------//
        	
	window.getSize();
	window.clear(Color::Black);	//clears the screen
	window.draw(background);	// setting background
	window.draw(p->sprite);	// setting player on screen
	window.draw(display);		//Score
	window.draw(dis_score);	//Updated Score
	window.draw(level);		//Levels
	window.draw(dis_level);	//Updated levels
	window.draw(lives);		//Lives
	window.draw(dis_lives);	//Updated lives
	window.draw(Name);		//Subscript my name
	window.draw(eb.sprite);
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	                                 //-------------Draw the Bullets---------//
                                     
        if(p->bulnum!=0)
        {  for (int i=0;i<p->bulnum;i++)
           {window.draw(p->bul[i].sprite);
            p->bul[i].move();}
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

					//--------------Enemy Bullets-----------//
 
        if(timere >= 3 && b_checker == 0){
           
           enemy_count = rand()%10;
           int b = rand()%3; 
           eb.sprite.setPosition(e1[b][enemy_count].sprite.getPosition().x+370, e1[b][enemy_count].sprite.getPosition().y+52);
           timere = 0;        
           b_checker = 1;
        
        }
        
        if(b_checker == 1) {
           
              eb.move();
              if(eb.sprite.getPosition().x > 780){
                   timer = 0;
                   b_checker = 0;
              }      
         
         }
  
          
        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 				
 					//-------------Collision b/t BUllet  & Enemie------------------//
                
                                                   //---------ALPHA IMAGE-------//
        
        for (int i = 0; i <= 10; i++) {
          for (int j = 0; j < p->bulnum; j++) {
            if (p->bul[j].sprite.getGlobalBounds().intersects(e1[0][i].sprite.getGlobalBounds())) {
              e1[0][i].alive = 1; 
              e1[0][i].sprite.setPosition(1000, 1000);   
              if(Level==1){
              Score+=10;}
              else if(Level == 2){
              Score+=20;}
              else if(Level == 3){
              Score+=30;}
              p->bul[j].pos(10000,10000);
              //delete p->bul[j];
              break; // move to next bullet
            }  
            
          }
        }
        
 
                                                  //-------BETA IMAGE------//
        
         for (int i = 0; i < 10; i++) {
          for (int j = 0; j < p->bulnum; j++) {
            if (p->bul[j].sprite.getGlobalBounds().intersects(e1[1][i].sprite.getGlobalBounds())) {
              e1[1][i].alive = 1;
              e1[1][i].sprite.setPosition(1000, 1000);
              if(Level==1){
              Score+=10;}
              else if(Level == 2){
              Score+=20;}
              else if(Level == 3){
              Score+=30;}
              p->bul[j].sprite.setPosition(-100, p->y -33);
              break; // move to next bullet
              
            }
          }
        }
       
                                             //------GYMMA IMAGE-------//  
         
         for (int i = 0; i < 10; i++) {
          for (int j = 0; j < p->bulnum; j++) {
            if (p->bul[j].sprite.getGlobalBounds().intersects(e1[2][i].sprite.getGlobalBounds())) {
              e1[2][i].alive = 1;
              e1[2][i].sprite.setPosition(1000, 1000);
              if(Level==1){
              Score+=10;}
              else if(Level == 2){
              Score+=20;}
              else if(Level == 3){
              Score+=30;}
              p->bul[j].sprite.setPosition(-100, p->y -33);
              break; // move to next bullet
              
            }
          }
        
        }
                                           //------Collision b/w Player and Enemie-------//
                                           
                                           
         for (int i = 0; i < 10; i++) {
             for (int j = 0; j < 10; j++) {
               if (p->sprite.getGlobalBounds().intersects(e1[0][i].sprite.getGlobalBounds())||
                   p->sprite.getGlobalBounds().intersects(e1[1][i].sprite.getGlobalBounds()) || 
                    p->sprite.getGlobalBounds().intersects(e1[2][i].sprite.getGlobalBounds())) {
                    p = new Player("img/player_ship.png"); 
                    Lives--;
                    break; // move to next bullet
              
            }
          }
        
        }                                   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
        
                                             //Collision b/w Dragon Fire and Player
     /*  
          for (int i = 0; i < 1; i++) {
             for (int j = 0; j < 1; j++) {
            if (p->sprite.getGlobalBounds().intersects(e1[4][i].sprite.getGlobalBounds())) {
               p = new Player("img/player_ship.png");
               break; // move to next bullet
          }
         }
       }   
          
              for (int i = 0; i < 1; i++) {
             for (int j = 0; j < 1; j++) {
            if (p->sprite.getGlobalBounds().intersects(e1[3][i].sprite.getGlobalBounds())) {
               p = new Player("img/player_ship.png");
               break; // move to next bullet
          }
         }
       }   
     */   
     
     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                
       				//---------Collision between Addons and Spaceship--------//
       			
                                                 //------For Danger Sign------//
       for (int i = 0; i <= 1; i++) {
          for (int j = 0; j < 1 ; j++) {
            if (p->sprite.getGlobalBounds().intersects(a[0][i].sprite.getGlobalBounds())) {
               a[0][i].sprite.setPosition(1000, 1000);
               Lives = Lives-1;          
               p = new Player("img/player_ship.png");     
               break; // move to next bullet
               
            }  
            
          }
        }	
       		
                         			  //--------For Live Sign-------//
        					  
        					  
      for (int i = 0; i <= 1; i++) {
          for (int j = 0; j < 1 ; j++) {
            if (p->sprite.getGlobalBounds().intersects(a[1][i].sprite.getGlobalBounds())) {
               a[1][i].sprite.setPosition(1000, 1000);
               Lives = Lives+1;             
              break; // move to next bullet
            }  
            
          }
        }	
        	                               //--------For Powerup----------//
        	                               
        	                               
   for (int i = 0; i <= 1; i++) {
          for (int j = 0; j < 1 ; j++) {
            if (p->sprite.getGlobalBounds().intersects(a[2][i].sprite.getGlobalBounds())) {
               a[2][i].sprite.setPosition(1000, 1000);
               Lives+=2;
               PowerUp = true;
               break; // move to next bullet
            }  
            
          }
        }	
                                          //---------For Fire-----------//  
                                          
     for (int i = 0; i <= 1; i++) {
          for (int j = 0; j < 1 ; j++) {
            if (p->sprite.getGlobalBounds().intersects(a[3][i].sprite.getGlobalBounds())) {
               a[3][i].sprite.setPosition(1000, 1000);
               Lives-=1;
               break; // move to next bullet
            }  
            
          }
        }	                                     
                                                                		  	
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  					//--------------Dragon Draw------------//
    	 
    	 
    if(dragon_timer >=43 && dragon_timer <=47 ){
        
        fireTex_a.loadFromFile("img/Beam.jpeg");					
        fire_a.setTexture(fireTex_a);
        fire_a.setScale(0.4, 1);
        fire_a.setPosition(e1[3][0].sprite.getPosition().x+120,e1[3][0].sprite.getPosition().y+70);
        window.draw(fire_a);}
 
    if(dragon_timer >=41 && dragon_timer <=47 ){
        
        fireTex_a.loadFromFile("img/Beam.jpeg");					
        fire_a.setTexture(fireTex_a);
        fire_a.setScale(0.4,1);
        fire_a.setPosition(e1[3][0].sprite.getPosition().x+70,e1[3][0].sprite.getPosition().y+70);
        window.draw(fire_a);}
    	 
    	 
     if(dragon_timer >=42 && dragon_timer <=47 ){
        
        fireTex_b.loadFromFile("img/Beam.jpeg");					
        fire_b.setTexture(fireTex_b);
        fire_b.setScale(0.4, 1);
        fire_b.setPosition(e1[3][0].sprite.getPosition().x+20,e1[3][0].sprite.getPosition().y+70);
        window.draw(fire_b);}
   	 	 	 
    	 
    	 if(dragon_timer >=40 && dragon_timer <=47){
             
            for (int i = 0; i <= 2; i++) 
            {
              for (int j = 0; j < 10; j++) 
              {
                  
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
             }
          }  
            e1[4][0].sprite.setPosition(10000,10000);
            e1[3][0].sprite.setPosition(310,75);
            e1[3][0].sprite.setScale(0.67,0.67);    
            window.draw(e1[3][0].sprite);
  }	
  
         if(dragon_timer >=49 && dragon_timer <=51){
              
              dragon_timer = 0;
              fire_timer = 0;
            for(int i=0; i<10; i++){
 
                e1[0][i].alive = -1;
                e1[1][i].alive = -1;
                e1[2][i].alive = -1;
            }  
            Score+=50;  
           }
          
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
                                       
                                        //----------MOnster Laser & Dragon Fire--------//
                                        
       					
        if(monster_timer >=25 && monster_timer <=37 ){
       
        beamTex.loadFromFile("img/beam5.jpeg");					
        beam.setTexture(beamTex);
        beam.setScale(1, 1.5);
        beam.setPosition(e1[4][0].sprite.getPosition().x+100,e1[4][0].sprite.getPosition().y+100);
        window.draw(beam);}
				
      
         if(monster_timer >=25 && monster_timer <=37){
             
            for (int i = 0; i <= 2; i++) 
            {
              for (int j = 0; j < 10; j++) 
              {
               
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
             }
          }  
            e1[4][0].sprite.setPosition(250,10);
            e1[4][0].sprite.setScale(0.2,0.2);    
            window.draw(e1[4][0].sprite);
   
   }
   e1[4][0].sprite.move(0.6,0);
           if(monster_timer >=40 && monster_timer <=42){
           
              monster_timer = 0;
              laser_timer = 0;
              for(int i=0; i<10; i++){
                
                e1[0][i].alive = -1;
                e1[1][i].alive = -1;
                e1[2][i].alive = -1;
            } 
            Score+=40;  
           }
           
            
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					//---------Lives End & Game Over----------//
					
      if(Lives == 0)
      {
         for (int i = 0; i <= 2; i++) 
         {
            for (int j = 0; j < 10; j++) 
            {
                
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
            }
            
        }    
        
        
         for (int i = 0; i <= 3; i++) 
         {
            for (int j = 0; j < 1; j++) 
            {
            
              a[i][j].sprite.setPosition(10000,10000);
            }
            
         }     
        
        mu_texture.loadFromFile("img/background3.jpg");
        menu.setTexture(mu_texture);
        menu.setScale(1, 1);
        
        sf::Font font;
        font.loadFromFile("img/ShortBaby-Mg2w.ttf");        
       
        
        sf::Text gameOver;
        gameOver.setFont(font);
        gameOver.setString("Game Over :(");
        gameOver.setCharacterSize(100);
        gameOver.setFillColor(sf::Color::White);
        gameOver.setPosition(150.f, 270.f);  
        
        window.draw(menu);      
        window.draw(gameOver);
        //window.close();
        
          
     } 
      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
     
					//--------------Addons Draw & Moving--------------//
        
           					
	  if(addon_timer >= 10 && addon_timer<=18){               
	  a[0][0].move();
	   window.draw(a[0][0].sprite);		//Danger
	   }
	  if(addon_timer1 >= 30 && addon_timer1 <=38){  
	   a[1][0].move();      		    
           window.draw(a[1][0].sprite);		//Live
           }
          if(addon_timer2 >= 25 && addon_timer2 <=33){  
           a[2][0].move();
           window.draw(a[2][0].sprite);		//PowerUp
           } 
          if(addon_timer3 >= 33 && addon_timer3 <=41){  
           a[3][0].move();
           window.draw(a[3][0].sprite);		//Fire
           } 
           
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
           
                                                //---------Reset TImer----------//
                                                				    
          if(addon_timer >=20 && addon_timer <=22){
             addon_timer = 0;
             Score+=5;
          } 
          
          if(addon_timer1 >=40 && addon_timer1 <=42){
             addon_timer1 = 0;
          } 
          
          if(addon_timer2 >=35 && addon_timer2 <=37){
             addon_timer2 = 0;
          }  
         
          if(addon_timer3 >=43 && addon_timer3 <=45){
             addon_timer3 = 0;
          }   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            //---------------------------------------Eniemies Draw-------------------------------------------//
     
               				//-------ALPHA ENEMIE--------//
       				

     	        		        	   //-----RECTANGLE-----//        
if(Level == 1) {

if(temp==0){   
   
     if(e1[0][0].alive == -1) 
     { 
            e1[0][0].sprite.setPosition(220,50);
            e1[0][0].sprite.setScale(0.5,0.5);
            window.draw(e1[0][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(350,50);
            e1[1][1].sprite.setScale(0.43,0.43);
            window.draw(e1[1][1].sprite);
     }
         
         
     if(e1[0][2].alive == -1) 
     {   
            e1[0][2].sprite.setPosition(490,50);
            e1[0][2].sprite.setScale(0.5,0.5);
            window.draw(e1[0][2].sprite);
     }
     
         
     if(e1[0][3].alive == -1) 
     {       
            e1[0][3].sprite.setPosition(220,250);
            e1[0][3].sprite.setScale(0.5,0.5);
            window.draw(e1[0][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(350,250);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[0][5].alive == -1) 
     {        
            e1[0][5].sprite.setPosition(490,250);
            e1[0][5].sprite.setScale(0.5,0.5);
            window.draw(e1[0][5].sprite);
    } 
    
     if(e1[2][6].alive == -1) 
     {       
            e1[2][6].sprite.setPosition(220,150);
            e1[2][6].sprite.setScale(0.35,0.35);
            window.draw(e1[2][6].sprite);
     }
     
     if(e1[2][7].alive == -1) 
     {       
            e1[2][7].sprite.setPosition(490,150);
            e1[2][7].sprite.setScale(0.35,0.35);
             window.draw(e1[2][7].sprite);
     }
    
}    		
    						//---TRINANGLE----//

if(temp==1){

       
      if(e1[0][0].alive == -1) 
     { 
            e1[0][0].sprite.setPosition(390,50);
            e1[0][0].sprite.setScale(0.5,0.5);
            window.draw(e1[0][0].sprite);
     } 
     
         
     if(e1[2][1].alive == -1) 
     {  
            e1[2][1].sprite.setPosition(300,120);
            e1[2][1].sprite.setScale(0.35,0.35);
            window.draw(e1[2][1].sprite);
     }
     
     if(e1[0][2].alive == -1) 
     {  
            e1[0][2].sprite.setPosition(190,220);
            e1[0][2].sprite.setScale(0.5,0.5);
            window.draw(e1[0][2].sprite);
     }
     
         
     if(e1[2][3].alive == -1) 
     {   
            e1[2][3].sprite.setPosition(480,120);
            e1[2][3].sprite.setScale(0.35,0.35);
            window.draw(e1[2][3].sprite);
     }
     
         
     if(e1[1][5].alive == -1) 
     {       
            e1[1][5].sprite.setPosition(430,220);
            e1[1][5].sprite.setScale(0.43,0.43);
            window.draw(e1[1][5].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(315,220);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
          
     if(e1[0][6].alive == -1) 
     {       
            e1[0][6].sprite.setPosition(545,220);
            e1[0][6].sprite.setScale(0.5,0.5);
            window.draw(e1[0][6].sprite);
    }
    
  
    
}
    						//---X-shape---// 
 
if(temp == 2){ 
           
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(200,50);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(500,50);
            e1[1][1].sprite.setScale(0.43,0.43);
            window.draw(e1[1][1].sprite);
     }
     
         
     if(e1[0][2].alive == -1) 
     {   
            e1[0][2].sprite.setPosition(290,120);
            e1[0][2].sprite.setScale(0.5,0.5);
            window.draw(e1[0][2].sprite);
     }
     
         
     if(e1[2][3].alive == -1) 
     {       
            e1[2][3].sprite.setPosition(200,330);
            e1[2][3].sprite.setScale(0.35,0.35);
            window.draw(e1[2][3].sprite);
     }
     
  
  
    if(e1[0][4].alive == -1) 
     {   
            e1[0][4].sprite.setPosition(430,120);
            e1[0][4].sprite.setScale(0.5,0.5);
            window.draw(e1[0][4].sprite);
     }   
    
    
     if(e1[0][5].alive == -1) 
     {   
            e1[0][5].sprite.setPosition(290,260);
            e1[0][5].sprite.setScale(0.5,0.5);
            window.draw(e1[0][5].sprite);
     }  
     
     if(e1[2][6].alive == -1) 
     {   
            e1[2][6].sprite.setPosition(500,330);
            e1[2][6].sprite.setScale(0.35,0.35);
            window.draw(e1[2][6].sprite);
     }  
     
     if(e1[0][7].alive == -1) 
     {   
            e1[0][7].sprite.setPosition(430,260);
            e1[0][7].sprite.setScale(0.5,0.5);
            window.draw(e1[0][7].sprite);
     }  
     
 
  
}//temp

}//Level 


else if(Level == 2) {
		
				//-----------Circle Shape--------//
if(temp1==0){
    				
     if(e1[0][0].alive == -1) 
     { 
            e1[0][0].sprite.setPosition(300,50);
            e1[0][0].sprite.setScale(0.5,0.5);
            window.draw(e1[0][0].sprite);
     } 
     
         
     if(e1[0][1].alive == -1) 
     {  
            e1[0][1].sprite.setPosition(400,50);
            e1[0][1].sprite.setScale(0.5,0.5);
            window.draw(e1[0][1].sprite);
     }
     
         
     if(e1[2][2].alive == -1) 
     {   
            e1[2][2].sprite.setPosition(250,220);
            e1[2][2].sprite.setScale(0.35,0.35);
            window.draw(e1[2][2].sprite);
     }
     
         
     if(e1[2][3].alive == -1) 
     {       
            e1[2][3].sprite.setPosition(450,220);
            e1[2][3].sprite.setScale(0.35,0.35);
            window.draw(e1[2][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(230,120);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[1][5].alive == -1) 
     {        
            e1[1][5].sprite.setPosition(470,120);
            e1[1][5].sprite.setScale(0.43,0.43);
            window.draw(e1[1][5].sprite);
    } 
  
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(310,280);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(410,280);
            e1[1][1].sprite.setScale(0.43,0.43);
            window.draw(e1[1][1].sprite);
     }
 
    
}    
}
   
   					//----------DAIMOND----------//
if(temp1==1){  
    						
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(240,80);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[2][1].alive == -1) 
     {  
            e1[2][1].sprite.setPosition(330,50);
            e1[2][1].sprite.setScale(0.35,0.35);
            window.draw(e1[2][1].sprite);
     }
     
         
     if(e1[2][2].alive == -1) 
     {   
            e1[2][2].sprite.setPosition(430,50);
            e1[2][2].sprite.setScale(0.35,0.35);
            window.draw(e1[2][2].sprite);
     }
     
         
     if(e1[1][3].alive == -1) 
     {       
            e1[1][3].sprite.setPosition(515,80);
            e1[1][3].sprite.setScale(0.43,0.43);
            window.draw(e1[1][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(270,150);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[1][5].alive == -1) 
     {        
            e1[1][5].sprite.setPosition(480,150);
            e1[1][5].sprite.setScale(0.43,0.43);
            window.draw(e1[1][5].sprite);
    } 
     
     if(e1[0][6].alive == -1) 
     {        
            e1[0][6].sprite.setPosition(310,230);
            e1[0][6].sprite.setScale(0.5,0.5);
            window.draw(e1[0][6].sprite);
    } 
    
    
    if(e1[0][7].alive == -1) 
     {        
            e1[0][7].sprite.setPosition(440,230);
            e1[0][7].sprite.setScale(0.5,0.5);
            window.draw(e1[0][7].sprite);
    } 
    
    
    if(e1[1][8].alive == -1) 
     {        
            e1[1][8].sprite.setPosition(375,290);
            e1[1][8].sprite.setScale(0.43,0.43);
            window.draw(e1[1][8].sprite);
    } 
    
      
}

					//----------HEART---------//
if(temp1==2){  
    							
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(335,119);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[0][1].alive == -1) 
     {  
            e1[0][1].sprite.setPosition(275,50);
            e1[0][1].sprite.setScale(0.5,0.5);
            window.draw(e1[0][1].sprite);
     }
     
         
     if(e1[0][2].alive == -1) 
     {   
            e1[0][2].sprite.setPosition(405,50);
            e1[0][2].sprite.setScale(0.5,0.5);
            window.draw(e1[0][2].sprite);
     }
     
         
     if(e1[1][3].alive == -1) 
     {       
            e1[1][3].sprite.setPosition(200,120);
            e1[1][3].sprite.setScale(0.43,0.43);
            window.draw(e1[1][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(470,120);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[2][5].alive == -1) 
     {        
            e1[2][5].sprite.setPosition(260,200);
            e1[2][5].sprite.setScale(0.38,0.38);
            window.draw(e1[2][5].sprite);
    } 
    
      if(e1[2][6].alive == -1) 
     {        
            e1[2][6].sprite.setPosition(400,200);
            e1[2][6].sprite.setScale(0.38,0.38);
            window.draw(e1[2][6].sprite);
    } 
    
     if(e1[1][7].alive == -1) 
     {        
            e1[1][7].sprite.setPosition(335,270);
            e1[1][7].sprite.setScale(0.43,0.43);
            window.draw(e1[1][7].sprite);
    } 
    
     
  
 }//Temp 

				//------------ALL SHAPES--------------//
else if(Level == 3){


if(temp2==0){  
    			             
     if(e1[0][0].alive == -1) 
     { 
            e1[0][0].sprite.setPosition(230,50);
            e1[0][0].sprite.setScale(0.5,0.5);
            window.draw(e1[0][0].sprite);
     } 
     
         
     if(e1[2][1].alive == -1) 
     {  
            e1[2][1].sprite.setPosition(360,50);
            e1[2][1].sprite.setScale(0.38,0.38);
            window.draw(e1[2][1].sprite);
     }
     
         
     if(e1[0][2].alive == -1) 
     {   
            e1[0][2].sprite.setPosition(490,50);
            e1[0][2].sprite.setScale(0.5,0.5);
            window.draw(e1[0][2].sprite);
     }
     
     if(e1[2][3].alive == -1) 
     {       
            e1[2][3].sprite.setPosition(230,140);
            e1[2][3].sprite.setScale(0.38,0.38);
            window.draw(e1[2][3].sprite);
     }
     
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(370,140);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
     }
     
     if(e1[2][5].alive == -1) 
     {       
            e1[2][5].sprite.setPosition(490,140);
            e1[2][5].sprite.setScale(0.38,0.38);
            window.draw(e1[2][5].sprite);
     }
     
         
     if(e1[1][6].alive == -1) 
     {       
            e1[1][6].sprite.setPosition(240,220);
            e1[1][6].sprite.setScale(0.43,0.43);
            window.draw(e1[1][6].sprite);
     }
     
         
     if(e1[2][7].alive == -1) 
     {       
            e1[2][7].sprite.setPosition(360,230);
            e1[2][7].sprite.setScale(0.38,0.38);
            window.draw(e1[2][7].sprite);
    }
    
        
     if(e1[1][8].alive == -1) 
     {        
            e1[1][8].sprite.setPosition(500,220);
            e1[1][8].sprite.setScale(0.43,0.43);
            window.draw(e1[1][8].sprite);
    } 
  
    
}	


   
if(temp2==1){
                                          
     if(e1[2][0].alive == -1) 
     { 
            e1[2][0].sprite.setPosition(390,50);
            e1[2][0].sprite.setScale(0.38,0.38);
            window.draw(e1[2][0].sprite);
     } 
     
         
     if(e1[0][1].alive == -1) 
     {  
            e1[0][1].sprite.setPosition(260,140);
            e1[0][1].sprite.setScale(0.5,0.5);
            window.draw(e1[0][1].sprite);
     }
     
         
     if(e1[1][2].alive == -1) 
     {   
            e1[1][2].sprite.setPosition(200,220);
            e1[1][2].sprite.setScale(0.38,0.38);
            window.draw(e1[1][2].sprite);
     }
     
         
     if(e1[0][3].alive == -1) 
     {       
            e1[0][3].sprite.setPosition(490,140);
            e1[0][3].sprite.setScale(0.5,0.5);
            window.draw(e1[0][3].sprite);
     }
     
         
     if(e1[2][4].alive == -1) 
     {       
            e1[2][4].sprite.setPosition(440,220);
            e1[2][4].sprite.setScale(0.38,0.38);
            window.draw(e1[2][4].sprite);
    }
    
        
     if(e1[2][5].alive == -1) 
     {        
            e1[2][5].sprite.setPosition(300,220);
            e1[2][5].sprite.setScale(0.38,0.38);
            window.draw(e1[2][5].sprite);
    } 
  
     if(e1[1][6].alive == -1) 
     {        
            e1[1][6].sprite.setPosition(545,220);
            e1[1][6].sprite.setScale(0.43,0.43);
            window.draw(e1[1][6].sprite);
    } 
    
        
     if(e1[2][7].alive == -1) 
     {  
            e1[2][7].sprite.setPosition(380,140);
            e1[2][7].sprite.setScale(0.38,0.38);
            window.draw(e1[2][7].sprite);
     }
     
    
}
    
    if(temp2==2){
                                         
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(200,50);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(500,50);
            e1[1][1].sprite.setScale(0.43,0.43);
            window.draw(e1[1][1].sprite);
     }
     
         
     if(e1[2][2].alive == -1) 
     {   
            e1[2][2].sprite.setPosition(290,120);
            e1[2][2].sprite.setScale(0.38,0.38);
            window.draw(e1[2][2].sprite);
     }
     
         
     if(e1[0][3].alive == -1) 
     {       
            e1[0][3].sprite.setPosition(200,330);
            e1[0][3].sprite.setScale(0.5,0.5);
            window.draw(e1[0][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(360,180);
            e1[1][4].sprite.setScale(0.49,0.49);
            window.draw(e1[1][4].sprite);
    }
    
    if(e1[2][5].alive == -1) 
     {   
            e1[2][5].sprite.setPosition(430,120);
            e1[2][5].sprite.setScale(0.38,0.38);
            window.draw(e1[2][5].sprite);
     }   
    
    
     if(e1[2][6].alive == -1) 
     {   
            e1[2][6].sprite.setPosition(290,260);
            e1[2][6].sprite.setScale(0.38,0.38);
            window.draw(e1[2][6].sprite);
     }  
     
     if(e1[0][7].alive == -1) 
     {   
            e1[0][7].sprite.setPosition(500,330);
            e1[0][7].sprite.setScale(0.5,0.5);
            window.draw(e1[0][7].sprite);
     }  
     
     if(e1[2][8].alive == -1) 
     {   
            e1[2][8].sprite.setPosition(430,260);
            e1[2][8].sprite.setScale(0.38,0.38);
            window.draw(e1[2][8].sprite);
     }  
     
    
}  

 
if(temp2==3){
       
     if(e1[2][0].alive == -1) 
     { 
            e1[2][0].sprite.setPosition(300,50);
            e1[2][0].sprite.setScale(0.38,0.38);
            window.draw(e1[2][0].sprite);
     } 
     
         
     if(e1[2][1].alive == -1) 
     {  
            e1[2][1].sprite.setPosition(400,50);
            e1[2][1].sprite.setScale(0.38,0.38);
            window.draw(e1[2][1].sprite);
     }
     
         
     if(e1[2][2].alive == -1) 
     {   
            e1[2][2].sprite.setPosition(250,220);
            e1[2][2].sprite.setScale(0.35,0.35);
            window.draw(e1[2][2].sprite);
     }
     
         
     if(e1[2][3].alive == -1) 
     {       
            e1[2][3].sprite.setPosition(450,220);
            e1[2][3].sprite.setScale(0.35,0.35);
            window.draw(e1[2][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(230,120);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[1][5].alive == -1) 
     {        
            e1[1][5].sprite.setPosition(470,120);
            e1[1][5].sprite.setScale(0.43,0.43);
            window.draw(e1[1][5].sprite);
    } 
  
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(310,280);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(410,280);
            e1[1][1].sprite.setScale(0.43,0.43);
            window.draw(e1[1][1].sprite);
     }
   
     
      if(e1[0][1].alive == -1) 
     {  
            e1[0][1].sprite.setPosition(350,110);
            e1[0][1].sprite.setScale(0.5,0.5);
            window.draw(e1[0][1].sprite);
     }
     
    
     
      if(e1[0][1].alive == -1) 
     {  
            e1[0][1].sprite.setPosition(350,220);
            e1[0][1].sprite.setScale(0.5,0.5);
            window.draw(e1[0][1].sprite);
     }
 
   
 
 } 
 
 if(temp2==4){  
    						
     if(e1[1][0].alive == -1) 
     { 
            e1[1][0].sprite.setPosition(240,80);
            e1[1][0].sprite.setScale(0.43,0.43);
            window.draw(e1[1][0].sprite);
     } 
     
         
     if(e1[2][1].alive == -1) 
     {  
            e1[2][1].sprite.setPosition(330,50);
            e1[2][1].sprite.setScale(0.35,0.35);
            window.draw(e1[2][1].sprite);
     }
     
         
     if(e1[2][2].alive == -1) 
     {   
            e1[2][2].sprite.setPosition(430,50);
            e1[2][2].sprite.setScale(0.35,0.35);
            window.draw(e1[2][2].sprite);
     }
     
         
     if(e1[1][3].alive == -1) 
     {       
            e1[1][3].sprite.setPosition(515,80);
            e1[1][3].sprite.setScale(0.43,0.43);
            window.draw(e1[1][3].sprite);
     }
     
         
     if(e1[1][4].alive == -1) 
     {       
            e1[1][4].sprite.setPosition(270,150);
            e1[1][4].sprite.setScale(0.43,0.43);
            window.draw(e1[1][4].sprite);
    }
    
        
     if(e1[1][5].alive == -1) 
     {        
            e1[1][5].sprite.setPosition(480,150);
            e1[1][5].sprite.setScale(0.43,0.43);
            window.draw(e1[1][5].sprite);
    } 
     
     if(e1[0][6].alive == -1) 
     {        
            e1[0][6].sprite.setPosition(310,230);
            e1[0][6].sprite.setScale(0.5,0.5);
            window.draw(e1[0][6].sprite);
    } 
    
    
    if(e1[0][7].alive == -1) 
     {        
            e1[0][7].sprite.setPosition(440,230);
            e1[0][7].sprite.setScale(0.5,0.5);
            window.draw(e1[0][7].sprite);
    } 
    
    
    if(e1[1][8].alive == -1) 
     {        
            e1[1][8].sprite.setPosition(375,290);
            e1[1][8].sprite.setScale(0.43,0.43);
            window.draw(e1[1][8].sprite);
    } 
    
      
}  
 
 
 if(temp2==5){  
                             
      if(e1[2][0].alive == -1) 
     { 
            e1[2][0].sprite.setPosition(335,125);
            e1[2][0].sprite.setScale(0.38,0.38);
            window.draw(e1[2][0].sprite);
     } 
     
         
     if(e1[1][1].alive == -1) 
     {  
            e1[1][1].sprite.setPosition(285,50);
            e1[1][1].sprite.setScale(0.48,0.48);
            window.draw(e1[1][1].sprite);
     }
     
         
     if(e1[1][2].alive == -1) 
     {   
            e1[1][2].sprite.setPosition(390,50);
            e1[1][2].sprite.setScale(0.48,0.48);
            window.draw(e1[1][2].sprite);
     }
     
         
     if(e1[0][3].alive == -1) 
     {       
            e1[0][3].sprite.setPosition(240,130);
            e1[0][3].sprite.setScale(0.5,0.5);
            window.draw(e1[0][3].sprite);
     }
     
         
     if(e1[0][4].alive == -1) 
     {       
            e1[0][4].sprite.setPosition(430,130);
            e1[0][4].sprite.setScale(0.5,0.5);
            window.draw(e1[0][4].sprite);
    }
    
        
     if(e1[2][5].alive == -1) 
     {        
            e1[2][5].sprite.setPosition(250,200);
            e1[2][5].sprite.setScale(0.38,0.38);
            window.draw(e1[2][5].sprite);
    } 
  
    if(e1[2][6].alive == -1) 
     {        
            e1[2][6].sprite.setPosition(340,200);
            e1[2][6].sprite.setScale(0.38,0.38);
            window.draw(e1[2][6].sprite);
    } 
    
    if(e1[2][7].alive == -1) 
     {        
            e1[2][7].sprite.setPosition(430,200);
            e1[2][7].sprite.setScale(0.38,0.38);
            window.draw(e1[2][7].sprite);
    } 
    if(e1[1][8].alive == -1) 
     {        
            e1[1][8].sprite.setPosition(340,275);
            e1[1][8].sprite.setScale(0.48,0.48);
            window.draw(e1[1][8].sprite);
    } 
                                                                                  
}  
}

if(Score == 80 && temp == 0){
temp = 1;
for(int i=0; i<10; i++){
 
   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }

}

if(Score == 150 && temp == 1){
temp = 2;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }

}

if(Score == 230 && temp ==2){
temp = 3;
Level++;
for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
} 


if(Score >=395 && Score <=500 && temp1==0){
temp1 = 1;
for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
}


if(Score >=670 && Score <=680 && temp1==1){
temp1 = 2;
for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }

}

if(Score >= 835 && Score <= 850 && temp1 ==2){
temp1 = 3;
Level++;
for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
} 


if(Score >= 1190 && Score <= 1230 && temp2 ==0){
temp2 = 1;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
} 


if(Score >= 1600 && Score <= 1800 && temp2 ==1){
temp2 = 2;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
} 

if(Score >= 2000 && Score <= 2200 && temp2==2){
temp2 = 3;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
}


if(Score >= 2250 && Score <= 2640 && temp2==3){
temp2 = 4;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
}


if(Score >= 2640 && Score <= 2900 && temp2==4){
temp2 = 5;

for(int i=0; i<10; i++){

   e1[0][i].alive = -1;
   e1[1][i].alive = -1;
   e1[2][i].alive = -1;
 }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		


if(Score >=2900 && temp2==5){

 for (int i = 0; i <= 2; i++) 
  {
            for (int j = 0; j < 10; j++) 
            {
                
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].alive = 1;
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
                 e1[i][j].sprite.setPosition(1000, 1000);
            }
            
        }    
        
        
         for (int i = 0; i <= 3; i++) 
         {
            for (int j = 0; j < 1; j++) 
            {
            
              a[i][j].sprite.setPosition(10000,10000);
            }
            
         }     
        
        mu_texture.loadFromFile("img/background3.jpg");
        menu.setTexture(mu_texture);
        menu.setScale(1, 1);
        
        sf::Font font;
        font.loadFromFile("img/ShortBaby-Mg2w.ttf");        
       
        
        sf::Text Win;
        Win.setFont(font);
        Win.setString("YOU WIN :(");
        Win.setCharacterSize(100);
        Win.setFillColor(sf::Color::White);
        Win.setPosition(150.f, 270.f);  
        window.draw(menu);      
        window.draw(Win);
}                                                                                                         			             
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                             

  
    }   
     
	window.display();  //Displying all the sprites
    
    }


}



};

