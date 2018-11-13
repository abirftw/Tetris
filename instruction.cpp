#include <SFML\Graphics.hpp>
#include <iostream>
#include<fstream>
#include "instruction.h"
using namespace std;
using namespace sf;
int pg=0;


instruction::instruction()
{
  //ctor
}

instruction::~instruction()
{
  //dtor
}
string line,line2;

void instruction::setInst(double width, double height)
{
		if (!instFont.loadFromFile("menuFont.ttf"))
			cout << "Error Loading Font\n";
		for (int i = 0; i < LINE_H; i++) {
			inst[i].setFont(instFont);
			inst[i].setCharacterSize(34);
			inst[i].setOutlineThickness(0.8f);
			inst[i].setOutlineColor(Color::Black);
			inst[i].setFillColor(Color::Red);
		}
		inst[0].setOutlineColor(Color::Green);
		inst[0].setFillColor(Color::Yellow);
		ifstream myfile("instruction1.txt");
		if (myfile.is_open())
		{
			for (int i = 0; i < LINE_H; i++)
			{

				line[0] = '\0';
				getline(myfile, line);
				
				inst[i].setString(line);
				inst[i].setPosition(width / 2.0 - inst[i].getLocalBounds().width / 2.0, (height / (double)(LINE_H + 2))*(i + 1));
				
			}
			

			myfile.close();
		}
		for (int i = 0; i < LINE2_H; i++) {
			inst2[i].setFont(instFont);
			inst2[i].setCharacterSize(34);
			inst2[i].setOutlineThickness(0.8f);
			inst2[i].setOutlineColor(Color::Black);
			inst2[i].setFillColor(Color::Red);
		}
		inst2[0].setOutlineColor(Color::Green);
		inst2[0].setFillColor(Color::Yellow);
		inst2[2].setOutlineColor(Color::Green);
		inst2[2].setFillColor(Color::Black);
		inst2[8].setOutlineColor(Color::Green);
		inst2[8].setFillColor(Color::Black);
		myfile.open("instruction2.txt");
		if (myfile.is_open())
		{
			for (int i = 0; i < LINE2_H; i++)
			{

				line2[0] = '\0';
				getline(myfile, line2);

				inst2[i].setString(line2);
				inst2[i].setPosition(width / 2.0 - inst2[i].getLocalBounds().width / 2.0, (height / (double)(LINE2_H + 4))*(i + 1));

			}


			myfile.close();
		}

}

void instruction::displayInstruction(sf::RenderWindow& window,int next) {
	if (next==0)
	{
		pg = 0;
		Texture instruction1;
		if (!instruction1.loadFromFile("instructionPage1.jpg"))
			cout << "Couldn't load Texture";
		instruction1.setRepeated(true);
		Sprite instruction1Sprite;
		instruction1Sprite.setTexture(instruction1);
		window.draw(instruction1Sprite);

		Texture next;
		if (!next.loadFromFile("nextbutton.png"));
		nextpg.setTexture(next);
		nextpg.setPosition(450, 500);
		window.draw(nextpg);

		Texture back;
		if (!back.loadFromFile("backbutton.png"));
		backpg.setTexture(back);
		backpg.setPosition(50, 500);
		window.draw(backpg);
		for (int i = 0; i < LINE_H; i++)
			window.draw(inst[i]);
	}
	else if (next==1 )
	{
		pg = 1;
		Texture instruction2;
		if (!instruction2.loadFromFile("instructionPage2.jpg"))
			cout << "Couldn't load Texture";
		instruction2.setRepeated(true);
		Sprite instruction2Sprite;
		instruction2Sprite.setTexture(instruction2);
		window.draw(instruction2Sprite);

		Texture back;
		if (!back.loadFromFile("backbutton.png"));
		Sprite backpg;
		backpg.setTexture(back);
		backpg.setPosition(50, 500);
		window.draw(backpg);
		for (int i = 0; i < LINE2_H; i++)
			window.draw(inst2[i]);
	}
	
}

void instruction::Mousework3(int xcor, int ycor)
{


	if ((xcor >= backpg.getPosition().x && xcor <= backpg.getPosition().x+backpg.getLocalBounds().width) && 
     (ycor >= backpg.getPosition().y && ycor <= backpg.getPosition().y+backpg.getLocalBounds().height))
	{
		selectedoption = 0;
	}
	else if((xcor >= nextpg.getPosition().x && xcor <= nextpg.getPosition().x+nextpg.getLocalBounds().width) && 
     (ycor >= nextpg.getPosition().y && ycor <= nextpg.getPosition().y+nextpg.getLocalBounds().height))
	{
		selectedoption = 1;
	}

}
int instruction::getSelectItem3() {
	return selectedoption;
}
