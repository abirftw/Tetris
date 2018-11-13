#include<iostream>
#include "gameover.h"
#include <SFML\Graphics.hpp>
#include<fstream>
using namespace std;
using namespace sf;
gameover::gameover()
{ 
  
  nameNeed=false;
  selectedOption=0;
  gameFont.loadFromFile("gamefont.ttf");
  playerText.setFillColor(Color::Black);
  playerText.setString("");
  playerText.setCharacterSize(25);
  playerText.setFont(gameFont);
  newHighscore.setFont(gameFont);
  gameOverText.setFont(gameFont);
  for(int i=0; i<2; i++){
    Options[i].setFont(gameFont);
    Options[i].setCharacterSize(35);
    Options[i].setPosition(250-Options[i].getLocalBounds().width,(600/4.0)*(i+2));
    if(i==0)
      Options[i].setString("RETRY");
    else
      Options[i].setString("MENU");  
    }
  newHighscore.setString("NEW HIGHSCORE!");
  
  gameOverText.setString("GAME OVER!");
  gameOverText.setCharacterSize(40);
  gameOverText.setPosition(250-gameOverText.getLocalBounds().width/2.0,150);
  //ctor
}

gameover::~gameover()
{
  //dtor
}
void gameover::stringReset(){
  playerText.setString("");
}
void gameover::getName(string all[]){

    nameNeed=true;
    for(int i=0; i<5; i++){
      allNames[i]=all[i];
    }
}
void gameover::setNames(int index){
  ofstream myfile("ScoreNames.txt");
    while(myfile.is_open()){
      for(int i=0;i<index; i++){
        myfile << allNames[i] << "\n";
      }
      myfile <<  playerInput << "\n";
      for(int i=index; i<4 ; i++){
        myfile << allNames[i];
        if(i<3) myfile << "\n";
      }
       myfile.close();
    }
}
void gameover::draw(sf::RenderWindow& window, bool over){
  if(over)
    window.draw(gameOverText);
  else{
    Options[0].setString("RESUME");
  }
  if(!nameNeed){
  for(int i=0; i<2; i++){
    window.draw(Options[i]);
  }
  }
  else{
    Text nameinput;
    nameinput.setFont(gameFont);
    nameinput.setCharacterSize(25);
    nameinput.setString("HIGH SCORE!\nENTER NAME:");
    nameinput.setPosition(250-nameinput.getLocalBounds().width/2.0,250);
    window.draw(nameinput);
    TextField.setSize(Vector2f(120,30));
    TextField.setPosition(250-TextField.getLocalBounds().width/2.0,350);
    playerText.setPosition(255-TextField.getLocalBounds().width/2.0,345);
    TextField.setFillColor(Color::White);
    window.draw(TextField);
    window.draw(playerText);
  }
}
int gameover::getSelectedOption(){
  return selectedOption;
}

void gameover::OptionChosen(int x, int y){
  for(int i=0; i<2; i++){
    if(x>=Options[i].getPosition().x && x<=Options[i].getLocalBounds().width+Options[i].getPosition().x
     && y>=Options[i].getPosition().y && y<=Options[i].getLocalBounds().height+Options[i].getPosition().y){
      selectedOption=i;
      break;
     }
  }
  Options[selectedOption].setFillColor(Color::Cyan);
  for(int i=0; i<2; i++){
    if(i!=selectedOption)
      Options[i].setFillColor(Color::White);
  }
}

