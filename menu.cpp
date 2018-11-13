#include<iostream>
#include "menu.h"
using namespace std;
using namespace sf;

Menu::Menu()
{
   selectedItem=0;
  //ctor
}

Menu::~Menu()
{
  //dtor
}
void Menu::setMenuItems(double width, double height){
  if(!MenuFont.loadFromFile("MenuFont.ttf"))
    cout << "Fail to load Font";
  for(int i=0; i<MENU_ITEMS; i++){
    MenuItems[i].setFont(MenuFont);
    MenuItems[i].setCharacterSize(34);
    MenuItems[i].setOutlineThickness(0.8f);
  if(i==0){
      MenuItems[i].setString("NEW GAME");
      MenuItems[i].setPosition((width/2.0)-MenuItems[i].getLocalBounds().width/2.0, (height/(double)(MENU_ITEMS+1))*(i+1));
    }
    else if(i==1){
      MenuItems[i].setString("HIGH SCORES");
      MenuItems[i].setPosition(width/2.0-MenuItems[i].getLocalBounds().width/2.0, (height/(double)(MENU_ITEMS+1))*(i+1));
    }
    else if(i==2){
      MenuItems[i].setString("MULTIPLAYER");
      MenuItems[i].setPosition(width/2.0-MenuItems[i].getLocalBounds().width/2.0, (height/(double)(MENU_ITEMS+1))*(i+1));
    }
    else if(i==3){
      MenuItems[i].setString("HELP");
      MenuItems[i].setPosition(width/2.0-MenuItems[i].getLocalBounds().width/2.0, (height/(double)(MENU_ITEMS+1))*(i+1));
    }
    else{
      MenuItems[i].setString("Exit");
      MenuItems[i].setPosition(width/2.0-MenuItems[i].getLocalBounds().width/2.0, (height/(double)(MENU_ITEMS+1))*(i+1));
    }

  }
  MenuItems[selectedItem].setFillColor(Color::Cyan);
  MenuItems[selectedItem].setOutlineColor(Color::Blue);
}
void Menu::Draw(sf::RenderWindow& window){
  Texture menuBackground;
  menuBackground.loadFromFile("menubackground.png");
  menuBackground.setRepeated(true);
  Sprite menuSprite;
  menuSprite.setTexture(menuBackground);
  window.draw(menuSprite);
  for(int i=0; i<MENU_ITEMS; i++){
    window.draw(MenuItems[i]);
  }
}
void Menu::MoveUp(){
  MenuItems[selectedItem].setFillColor(Color::White);
  MenuItems[selectedItem].setOutlineColor(Color::Black);
  selectedItem--;
  if(selectedItem<0) selectedItem=0;
  MenuItems[selectedItem].setFillColor(Color::Cyan);
  MenuItems[selectedItem].setOutlineColor(Color::Blue);

}
void Menu::MoveDown(){
  MenuItems[selectedItem].setFillColor(Color::White);
  MenuItems[selectedItem].setOutlineColor(Color::Black);
  selectedItem++;
  if(selectedItem>=MENU_ITEMS) selectedItem=MENU_ITEMS-1;
  MenuItems[selectedItem].setFillColor(Color::Cyan);
  MenuItems[selectedItem].setOutlineColor(Color::Blue);
}
int Menu::getSelectItem(){
  return selectedItem;
}
void Menu::MouseWork(int xcor, int ycor){
  for(int i=0; i<MENU_ITEMS; i++){
    if(xcor>=MenuItems[i].getPosition().x && xcor<=MenuItems[i].getPosition().x+MenuItems[i].getLocalBounds().width
       && ycor>=MenuItems[i].getPosition().y && ycor<=MenuItems[i].getLocalBounds().height+MenuItems[i].getPosition().y){
      selectedItem=i;
      break;
    }
  }
  MenuItems[selectedItem].setFillColor(Color::Cyan);
  MenuItems[selectedItem].setOutlineColor(Color::Blue);
  for(int i=0; i<4; i++){
    if(i!=selectedItem){
      MenuItems[i].setFillColor(Color::White);
      MenuItems[i].setOutlineColor(Color::Black);
    }
  }

}
