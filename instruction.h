#ifndef INSTRUCTION_H
#define LINE_H 5
#define LINE2_H 13
#include <SFML\Graphics.hpp>
#include <iostream>
#include<fstream>

class instruction
{
  public:
    instruction();
    virtual ~instruction();
    void displayInstruction(sf::RenderWindow &window,int next);
    void Mousework3(int xcor, int ycor);
    void setInst(double width, double height);
    int getSelectItem3();
    

  protected:

  private:
  int selectedoption;
	sf::Text inst[LINE_H];
	sf::Text inst2[LINE2_H];
	sf::Font instFont;
  sf::Sprite nextpg;
  sf::Sprite backpg;
};

#endif // INSTRUCTION_H
