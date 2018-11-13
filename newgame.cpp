#include<iostream>
#include <SFML\Graphics.hpp>
#include "newgame.h"
#include <SFML\Graphics\VertexArray.hpp>
#include<cmath>
using namespace std;
using namespace sf;

NewGame::NewGame()
{
  dx=0;
  dy=0;
  angle=0;
  ShapeA.setPointCount(8);
  ShapeA.setPoint(0, Vector2f(0.f, 0.f));
  ShapeA.setPoint(1, Vector2f(0.0f, 30.f));
  ShapeA.setPoint(2, Vector2f(30.f, 30.f));
  ShapeA.setPoint(3, Vector2f(30.f, 60.f));
  ShapeA.setPoint(4, Vector2f(60.f, 60.f));
  ShapeA.setPoint(5, Vector2f(60.f, 30.f));
  ShapeA.setPoint(6, Vector2f(90.f, 30.f));
  ShapeA.setPoint(7, Vector2f(90.f, 0.f));
  //ctor
}

NewGame::~NewGame()
{
  //dtor
}
void NewGame::moveUp(){
 if(ShapeA.getPosition().y>0)
  ShapeA.move(0,-30.0f);
}
void NewGame::moveDown(double height){
  if(ShapeA.getPosition().y+ShapeA.getGlobalBounds().height<height)
    ShapeA.move(0,30.0f);
}
void NewGame::rotateBlock(){
    ShapeA.rotate(90);
}
void NewGame::moveLeft(){
  if(ShapeA.getPosition().x>0)
    ShapeA.move(-30,0);
}
void NewGame::moveRight(double width){
  if(ShapeA.getPosition().x+ShapeA.getGlobalBounds().width<width){
    ShapeA.move(30,0);
  }
}
void NewGame::Draw(RenderWindow &window){
  if(!gameBackground.loadFromFile("Blocks.png"))
    cout << "Unable to Background load Texture";
  if(!ShapeTexture.loadFromFile("BlockUnit.jpg"))
    cout << "Unable to Block load Texture";
  rotation=false;
  ShapeTexture.setRepeated(true);
  gameBackground.setRepeated(true);
  Sprite GameSpriteBG;
  ShapeA.setTexture(&ShapeTexture);
  ShapeA.setTextureRect(IntRect(0,0,ShapeA.getLocalBounds().width,ShapeA.getLocalBounds().height));
  GameSpriteBG.setTexture(gameBackground);
  GameSpriteBG.setTextureRect(IntRect(0,0,300,600));
  window.draw(GameSpriteBG);
  window.draw(ShapeA);
}
