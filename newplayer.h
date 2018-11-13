#ifndef NEWPLAYER_H
#define NEWPLAYER_H
#include<cstdlib>
#include<time.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include<stdio.h>
class NewPlayer
{
public:
	NewPlayer();
	bool isFilled2();
	void Move2();
	void setLeft2();
	void setRight2();
	void Rotate2();
	void FallBlock2();
	void MoveDown2();
	int CheckLine2();
	void setScore2(int LinesCleared2);
	bool isFilled1();
	void Move1();
	void setLeft1();
	void setRight1();
	void Rotate1();
	void FallBlock1();
	void MoveDown1();
	int CheckLine1();
	void setScore1(int LinesCleared);
	void Draw2(sf::RenderWindow &window);
	void clock(float time);
	void anewgame(char nw);
	~NewPlayer();
protected:

private:
	const int WidthBlocks2 = 30;
	const int HeightBlocks2 = 20;
	int field2[20][10];
	struct coordinates {
		int x,y;
	}m2[4], n2[4], v2[4], p2, m1[4], n1[4], v1[4], p1;
	int dx2 = 0;
	int dy2 = 1;
	bool isGameOver2;
	int ShapeNum2;
	int BlockNo2;
	int randomBlockNo2;
	int CurrentScore2;
	sf::Texture background2, blockUnit2;
	sf::Text Score2;
	sf::Text gameOverText2;
	sf::Font gameFont2;
	sf::Text Name2;
	int enternam2 = 50;

	const int WidthBlocks1 = 10;
	const int HeightBlocks1 = 20;
	int field1[20][10];
	int dx1 = 0;
	int dy1 = 1;
	bool isGameOver1;
	int ShapeNum1;
	int BlockNo1;
	int randomBlockNo1;
	int CurrentScore1;
	sf::Texture background1, blockUnit1;
	sf::Text Score1;
	sf::Text gameOverText1;
	sf::Font gameFont1;
	sf::Text Name1;
	sf::Text timeLeft;
	bool timeover=false;
	int enternam1 = 50;

};
#endif // NEWPLAYER_H
