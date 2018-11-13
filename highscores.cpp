#include<iostream>
#include "highscores.h"
#include <SFML\Graphics.hpp>
#include<fstream>
#include <sstream> 
using namespace std;
using namespace sf;

HighScores::HighScores()
{ 
  ///////////////Back Button Parameters////////////
  backButtonTexture.loadFromFile("backbutton.png");
  backButton.setPointCount(1000);
  backButton.setTexture(&backButtonTexture);
  backButton.setRadius(15);
  backButton.setPosition(30,30);
  backButton.setOutlineColor(Color::Cyan);
      ///////////Parameters End////////////
  
}
HighScores::~HighScores()
{
  //dtor
}
int* HighScores::returnHighScoreList(){
    return allScores;
}
void HighScores::setHighScore(double width, double height){
  if(!ScoreFont.loadFromFile("menuFont.ttf"))
    cout << "Error Loading Font\n";
  for(int i=0; i<HIGHSCORES_H; i++){
    
    ScoreName[i].setFont(ScoreFont);
    ScoreName[i].setCharacterSize(34);
    ScoreName[i].setOutlineThickness(0.8f);
    
    Score[i].setFont(ScoreFont);
    Score[i].setCharacterSize(34);
    Score[i].setOutlineThickness(0.8f);
   }
  string line;
  ifstream myfile ("Scores.txt");
  if (myfile.is_open())
  {
    int i=0;
    while ( getline (myfile,line) )
    { 
      stringstream ss(line);
      Score[i].setString(line);
      ss >> allScores[i];
      Score[i].setPosition(width/2.0-Score[i].getLocalBounds().width/2.0 +50, (height/(double)(HIGHSCORES_H+1))*(i+1));
      i++;
    }
    myfile.close();
  }
  myfile.open("ScoreNames.txt");
  if (myfile.is_open())
  {
    int i=0;
    while ( getline (myfile,line) )
    {
      allNames[i]=line;
      ScoreName[i].setString(line);
      ScoreName[i].setPosition(width/2.0-ScoreName[i].getLocalBounds().width/2.0 -50, (height/(double)(HIGHSCORES_H+1))*(i+1));
      i++;
    }
    myfile.close();
  }
}
bool HighScores::isBackButtonChosen(int x, int y){
  if(x>=backButton.getPosition().x && x<=backButton.getLocalBounds().width+backButton.getPosition().x
     && y>=backButton.getPosition().y && y<=backButton.getLocalBounds().height+backButton.getPosition().y){
       backButton.setOutlineThickness(1);
       return true;
     }
  backButton.setOutlineThickness(0);
  return false;
}
void HighScores::displayScore(sf::RenderWindow &window){
  
   Texture HighScoreBackground;
   if(!HighScoreBackground.loadFromFile("menubackground.png"))
    cout << "Couldn't load Texture";
   HighScoreBackground.setRepeated(true);
   Sprite BackgroundSprite;
   BackgroundSprite.setTexture(HighScoreBackground);
   window.draw(BackgroundSprite);
   window.draw(backButton);
   for(int i=0; i<HIGHSCORES_H; i++){
    window.draw(Score[i]);
    window.draw(ScoreName[i]);
   }

}
