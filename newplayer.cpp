#include "newplayer.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include <SFML\Graphics.hpp>
#include<stdio.h>
#include<cstdio>

using namespace std;
using namespace sf;

int timeint;

int Blocks1[7][4] = {
	1 + 4,3 + 4,5 + 4,7 + 4,
	2 + 4,4 + 4,5 + 4,7 + 4,
	3 + 4,5 + 4,4 + 4,6 + 4,
	3 + 4,5 + 4,4 + 4,7 + 4,
	2 + 4,3 + 4,5 + 4,7 + 4,
	3 + 4,5 + 4,7 + 4,6 + 4,
	2 + 4,3 + 4,4 + 4,5 + 4,
};
int Blocks2[7][4] = {
	1 + 44,3 + 44,5 + 44,7 + 44,
	2 + 44,4 + 44,5 + 44,7 + 44,
	3 + 44,5 + 44,4 + 44,6 + 44,
	3 + 44,5 + 44,4 + 44,7 + 44,
	2 + 44,3 + 44,5 + 44,7 + 44,
	3 + 44,5 + 44,7 + 44,6 + 44,
	2 + 44,3 + 44,4 + 44,5 + 44,
};

int player1 = 0, player2 = 0;


NewPlayer::NewPlayer()
{///////////////////::::PLAYER2//////////////
	for (int i = 0; i < WidthBlocks2-20; i++) {
		for (int j = 0; j < HeightBlocks2; j++) {
			field2[j][i] = 0;
		}
	}
	///////////////////PLAYER2:::://////////////

	///////////////////::::PLAYER1//////////////
	for (int i = 0; i < WidthBlocks1; i++) {
		for (int j = 0; j < HeightBlocks1; j++) {
			field1[j][i] = 0;
		}
	}
	///////////////////PLAYER1:::://////////////

	///////////////////::::PLAYER2//////////////
	isGameOver2 = false;
	srand(time(0));
	CurrentScore2 = 0;
	randomBlockNo2 = rand() % 7;
	ShapeNum2 = 1 + randomBlockNo2;
	BlockNo2 = randomBlockNo2;
	for (int i = 0; i < 4; i++) {
		m2[i].x = Blocks2[BlockNo2][i] / 2;
		m2[i].y = Blocks2[BlockNo2][i] % 2;

	}
	///////////////////PLAYER2:::://////////////
	
	///////////////////::::PLAYER1//////////////
	isGameOver1 = false;
	CurrentScore1 = 0;
	randomBlockNo1 = rand() % 7;
	ShapeNum1 = 1 + randomBlockNo1;
	BlockNo1 = randomBlockNo1;
	for (int i = 0; i < 4; i++) {
		m1[i].x = Blocks1[BlockNo1][i] / 2;
		m1[i].y = Blocks1[BlockNo1][i] % 2;

	}
	///////////////////PLAYER1:::://////////////
	//ctor
}


NewPlayer::~NewPlayer()
{
	//dtor
}

////////////////////////////::::::::Game Refreshes///////////////////////////////
void NewPlayer::anewgame(char nw)
{

	if (nw == 'y' || nw == 'Y')
	{
		for (int i = 0; i < WidthBlocks1; i++) {
			for (int j = 0; j < HeightBlocks1; j++) {
				field2[i][j]=field1[j][i] = 0;
			}
		}
		

		isGameOver1 = false;
		isGameOver2 = false;
		CurrentScore1 = 0;
		CurrentScore2 = 0;
		timeover = false;
		timeint = 0;
	}
}
////////////////////////////Game Refreshes::::::::///////////////////////////////

///////////////////::::PLAYER2//////////////
bool NewPlayer::isFilled2() {
	for (int i = 0; i < 4; i++) {
		if (m2[i].x < 20 || m2[i].x >= WidthBlocks2 || m2[i].y >= HeightBlocks2)
			return false;
		else if (field2[m2[i].y][m2[i].x])
			return false;
	}
	return true;
}
///////////////////PLAYER2:::://////////////

///////////////////::::PLAYER1//////////////
bool NewPlayer::isFilled1() {
	for (int i = 0; i < 4; i++) {
		if (m1[i].x < 0 || m1[i].x >= WidthBlocks1 || m1[i].y >= HeightBlocks1)
			return false;
		else if (field1[m1[i].y][m1[i].x])
			return false;
	}
	return true;
}
///////////////////PLAYER1:::://////////////


///////////////////::::PLAYER2//////////////                           ///////////////////::::PLAYER2//////////////                   
///////////////////::::PLAYER2//////////////                           ///////////////////::::PLAYER2////////////// 
///////////////////::::PLAYER2//////////////                           ///////////////////::::PLAYER2////////////// 
void NewPlayer::setLeft2() {
	dx2 = 1;
}
void NewPlayer::setRight2() {
	dx2 = -1;
}
void NewPlayer::MoveDown2() {
	for (int i = 0; i < 4; i++) {
		n2[i] = m2[i];
		m2[i].y += dy2;
	}
	if (!isFilled2()) {
		for (int i = 0; i < 4; i++) {
			m2[i] = n2[i];
		}
	}
}
void NewPlayer::Move2() {
	for (int i = 0; i < 4; i++) {
		n2[i] = m2[i];
		m2[i].x += dx2;
	}
	if (!isFilled2()) {
		for (int i = 0; i < 4; i++) {
			m2[i] = n2[i];
		}
	}
}
void NewPlayer::Rotate2() {
	p2 = m2[1];
	for (int i = 0; i < 4; i++) {
		int x2 = m2[i].y - p2.y;
		int y2 = m2[i].x - p2.x;
		m2[i].x = p2.x - x2;
		m2[i].y = p2.y + y2;
	}
	if (!isFilled2()) {
		for (int i = 0; i < 4; i++) {
			m2[i] = n2[i];
		}
	}
}
void NewPlayer::FallBlock2() {

		for (int i = 0; i < 4; i++) {
			n2[i] = m2[i];
			if (field2[m2[i].y][m2[i].x]) {
				isGameOver2 = true;
			}
			m2[i].y += 1;
		}
		if (!isFilled2()) {
			for (int i = 0; i < 4; i++) {
				field2[n2[i].y][n2[i].x] = ShapeNum2;
			}
			randomBlockNo2 = rand() % 7;
			ShapeNum2 = 1 + randomBlockNo2;
			BlockNo2 = randomBlockNo2;

			for (int i = 0; i < 4; i++) {
				m2[i].x = Blocks2[BlockNo2][i] / 2;
				m2[i].y = Blocks2[BlockNo2][i] % 2;
			}
		}
}
int NewPlayer::CheckLine2() {
	int numOFLines2 = HeightBlocks2 - 1;
	int ClearedLines2 = 0;
	for (int i = HeightBlocks2 - 1; i >= 0; i--) {
		int BlocksInLine2 = 0;
		for (int j = 0; j < WidthBlocks2-20; j++) {
			if (field2[i][j])
				BlocksInLine2++;
			field2[numOFLines2][j] = field2[i][j];

		}
		if (BlocksInLine2 < WidthBlocks2-20)
			numOFLines2--;
		else
			ClearedLines2++;
	}
	return ClearedLines2;
}
void NewPlayer::setScore2(int LinesCleared2) {
	int scoreIncrease2;
	int pointMultiplier2 = 0;
	if (LinesCleared2 == 1)
		pointMultiplier2 = 10;
	else if (LinesCleared2 < 5)
		pointMultiplier2 = 20;
	else if (LinesCleared2 < 10)
		pointMultiplier2 = 40;
	else if (LinesCleared2 < 15)
		pointMultiplier2 = 80;
	else if (LinesCleared2 < HeightBlocks2)
		pointMultiplier2 = 160;
	scoreIncrease2 = LinesCleared2 * pointMultiplier2;
	CurrentScore2 += scoreIncrease2;

}
///////////////////PLAYER2:::://////////////                ///////////////////PLAYER2:::://////////////         
///////////////////PLAYER2:::://////////////                 ///////////////////PLAYER2:::://////////////
///////////////////PLAYER2:::://////////////               ///////////////////PLAYER2:::://////////////




///////////////////::::PLAYER1//////////////                           ///////////////////::::PLAYER1//////////////                   
///////////////////::::PLAYER1//////////////                           ///////////////////::::PLAYER1////////////// 
///////////////////::::PLAYER1//////////////                           ///////////////////::::PLAYER1////////////// 
void NewPlayer::setLeft1() {
	dx1 = 1;
}
void NewPlayer::setRight1() {
	dx1 = -1;
}
void NewPlayer::MoveDown1() {
	for (int i = 0; i < 4; i++) {
		n1[i] = m1[i];
		m1[i].y += dy1;
	}
	if (!isFilled1()) {
		for (int i = 0; i < 4; i++) {
			m1[i] = n1[i];
		}
	}
}
void NewPlayer::Move1() {
	for (int i = 0; i < 4; i++) {
		n1[i] = m1[i];
		m1[i].x += dx1;
	}
	if (!isFilled1()) {
		for (int i = 0; i < 4; i++) {
			m1[i] = n1[i];
		}
	}
}
void NewPlayer::Rotate1() {
	p1 = m1[1];
	for (int i = 0; i < 4; i++) {
		int x = m1[i].y - p1.y;
		int y = m1[i].x - p1.x;
		m1[i].x = p1.x - x;
		m1[i].y = p1.y + y;
	}
	if (!isFilled1()) {
		for (int i = 0; i < 4; i++) {
			m1[i] = n1[i];
		}
	}
}
void NewPlayer::FallBlock1() {
	if (!isGameOver1) {
		for (int i = 0; i < 4; i++) {
			n1[i] = m1[i];
			if (field1[m1[i].y][m1[i].x]) {
				isGameOver1 = true;
			}
			m1[i].y += 1;
		}
		if (!isFilled1()) {
			for (int i = 0; i < 4; i++) {
				field1[n1[i].y][n1[i].x] = ShapeNum1;
			}
			randomBlockNo1 = rand() % 7;
			ShapeNum1 = 1 + randomBlockNo1;
			BlockNo1 = randomBlockNo1;

			for (int i = 0; i < 4; i++) {
				m1[i].x = Blocks1[BlockNo1][i] / 2;
				m1[i].y = Blocks1[BlockNo1][i] % 2;
			}
		}
	}
}
int NewPlayer::CheckLine1() {
	int numOFLines = HeightBlocks1 - 1;
	int ClearedLines = 0;
	for (int i = HeightBlocks1 - 1; i >= 0; i--) {
		int BlocksInLine = 0;
		for (int j = 0; j < WidthBlocks1; j++) {
			if (field1[i][j])
				BlocksInLine++;
			field1[numOFLines][j] = field1[i][j];

		}
		if (BlocksInLine < WidthBlocks1)
			numOFLines--;
		else
			ClearedLines++;
	}
	return ClearedLines;
}
void NewPlayer::setScore1(int LinesCleared) {
	int scoreIncrease;
	int pointMultiplier = 0;
	if (LinesCleared == 1)
		pointMultiplier = 10;
	else if (LinesCleared < 5)
		pointMultiplier = 20;
	else if (LinesCleared < 10)
		pointMultiplier = 40;
	else if (LinesCleared < 15)
		pointMultiplier = 80;
	else if (LinesCleared < HeightBlocks1)
		pointMultiplier = 160;
	scoreIncrease = LinesCleared * pointMultiplier;
	CurrentScore1 += scoreIncrease;

}
///////////////////PLAYER1:::://////////////                ///////////////////PLAYER1:::://////////////         
///////////////////PLAYER1:::://////////////                 ///////////////////PLAYER1:::://////////////
///////////////////PLAYER1:::://////////////               ///////////////////PLAYER1:::://////////////

void NewPlayer::clock(float time)
{
	 timeint = time;
	if (timeint == 202)
	{
		timeover = true;
	}

}




void NewPlayer::Draw2(sf::RenderWindow& window) 
{
	
	//////////////////////////////////////sidebg//

	sf::Texture bg;
	//if (!bg.loadFromFile("bgtetris2.png"));
	{/*cout << "Couldn't load Side Background (bgtetris)Texture anewgame\n";*/ 1 == 1; }
	sf::Sprite bgImage;
	//bgImage.setTexture(bg);
	window.draw(bgImage);
	//////////////////////////////////////////sidebg//
	if (!background2.loadFromFile("Blocks.png"))
		cout << "Couldn't load Background2 Texture newplayer";
	if (!blockUnit2.loadFromFile("BlockUnit.png"))
		cout << "Couldn't load Block2 Texture newplayer";
	
	background2.setRepeated(true);
	Sprite gameBackground2, blockBackground2;
	blockBackground2.setTexture(blockUnit2);
	gameBackground2.setTexture(background2);
	
	
	char temp3[60];
	sprintf(temp3, "Time Left: %d", 202 - timeint);
	timeLeft.setString(temp3);
	if (!gameFont2.loadFromFile("gamefont.ttf"))
		cout << "Unable to load game font";
	timeLeft.setFont(gameFont2);


	////secondBlockPart(player2)//////
	if (!isGameOver2 && !timeover) {
		gameBackground2.setPosition(sf::Vector2f(600, 0));
		gameBackground2.setTextureRect(IntRect(0, 0, 300, 600));
		window.draw(gameBackground2);
		for (int i = 0; i < WidthBlocks2 - 20; i++)
		{
			for (int j = 0; j < HeightBlocks2; j++)
			{
				if (field2[j][i])
				{
					switch (field2[j][i])
					{
					case 1:
          blockBackground2.setColor(Color::Magenta);
          break;
				case 2:
					blockBackground2.setColor(Color::White);
					break;
				case 3:
					blockBackground2.setColor(Color::Green);
					break;
				case 4:
					blockBackground2.setColor(Color::Blue);
					break;
				case 5:
					blockBackground2.setColor(Color::Red);
					break;
				case 6:
					blockBackground2.setColor(Color::Cyan);
					break;
				case 7:
					blockBackground2.setColor(Color::Yellow);
					break;
		    default:
			    break;
					}
					blockBackground2.setPosition(600 + i * 30, j * 30);
					window.draw(blockBackground2);

				}
			}
		}
		for (int i = 0; i < 4; i++)
		{

			switch (ShapeNum2)
			{
			case 1:
          blockBackground2.setColor(Color::Magenta);
          break;
				case 2:
					blockBackground2.setColor(Color::White);
					break;
				case 3:
					blockBackground2.setColor(Color::Green);
					break;
				case 4:
					blockBackground2.setColor(Color::Blue);
					break;
				case 5:
					blockBackground2.setColor(Color::Red);
					break;
				case 6:
					blockBackground2.setColor(Color::Cyan);
					break;
				case 7:
					blockBackground2.setColor(Color::Yellow);
					break;
		default:
			break;
			}


			blockBackground2.setPosition(m2[i].x * 30, m2[i].y * 30);
			window.draw(blockBackground2);
		}
		///////////*Setting Score for player2 Start*/////////////
		setScore2(CheckLine2());
		char temp2[60];
		sprintf(temp2, "Player2\nScore: %d", CurrentScore2);
		Score2.setString(temp2);
		if (!gameFont2.loadFromFile("gamefont.ttf"))
			cout << "Unable to load game font";
		Score2.setFont(gameFont2);
		Score2.setPosition(1120 - Score2.getLocalBounds().width, 100);
		window.draw(Score2);
		///////////*Setting Score Finish*/////////////
		///////////countdown200sec///////////
		timeLeft.setPosition(1158 - timeLeft.getLocalBounds().width, 300);
		window.draw(timeLeft);
	}
	else if(isGameOver2 || timeover)
	{

		gameOverText2.setFont(gameFont2);
		if (timeover)
		gameOverText2.setString("TIME OVER!");
		if(isGameOver2)
		gameOverText2.setString("GAME OVER!");
		gameOverText2.setCharacterSize(40);
		gameOverText2.setPosition(900 - gameOverText2.getLocalBounds().width / 2.0, 225);
		window.draw(gameOverText2);
		Score2.setPosition(900 - Score2.getLocalBounds().width / 2.0, 300);
		Score2.setCharacterSize(35);
		window.draw(Score2);

		
			/////entername/////////

			char nam2[1000];

			/*cin >> enternam;*/
			/*enternam2++;
			sprintf_s(nam2, "Name is %d", enternam2);
			Name2.setString(nam2);
			if (!gameFont2.loadFromFile("gamefont.ttf"))
				cout << "Unable to load game font";
			Name2.setFont(gameFont2);
			Name2.setPosition(520 - Name2.getLocalBounds().width, 100);
			
			/////entername/////////


		
		window.draw(Name2);*/

	}

		//////////player1////////
	if (!isGameOver1 && !timeover) {
		blockBackground2.setPosition(sf::Vector2f(0, 0));
		gameBackground2.setPosition(sf::Vector2f(0, 0));
		gameBackground2.setTextureRect(IntRect(0, 0, 300, 600));
		window.draw(gameBackground2);
		for (int i = 0; i < WidthBlocks1; i++)
		{
			for (int j = 0; j < HeightBlocks1; j++)
			{
				if (field1[j][i])
				{
					switch (field1[j][i])
					{
					case 1:
          blockBackground2.setColor(Color::Magenta);
          break;
				case 2:
					blockBackground2.setColor(Color::White);
					break;
				case 3:
					blockBackground2.setColor(Color::Green);
					break;
				case 4:
					blockBackground2.setColor(Color::Blue);
					break;
				case 5:
					blockBackground2.setColor(Color::Red);
					break;
				case 6:
					blockBackground2.setColor(Color::Cyan);
					break;
				case 7:
					blockBackground2.setColor(Color::Yellow);
					break;
		default:
			break;
					}
					blockBackground2.setPosition(i * 30, j * 30);
					window.draw(blockBackground2);

				}
			}
		}
		for (int i = 0; i < 4; i++)
		{

			switch (ShapeNum1)
			{
			case 1:
				blockBackground2.setColor(Color(100, 100, 100));
				break;
			case 2:
				blockBackground2.setColor(Color::Blue);
				break;
			case 3:
				blockBackground2.setColor(Color::Green);
				break;
			case 4:
				blockBackground2.setColor(Color::Red);
				break;
			case 5:
				blockBackground2.setColor(Color::Yellow);
				break;
			case 6:
				blockBackground2.setColor(Color::Cyan);
				break;
			case 7:
				blockBackground2.setColor(Color::White);
				break;
			default:
				break;
			}


			blockBackground2.setPosition(m1[i].x * 30, m1[i].y * 30);
			window.draw(blockBackground2);

		}




		///////////*Setting Score for player1 Start*/////////////
		setScore1(CheckLine1());
		char temp1[60];
		sprintf(temp1, "Player1\nScore: %d", CurrentScore1);
		Score1.setString(temp1);
		if (!gameFont2.loadFromFile("gamefont.ttf"))
			cout << "Unable to load game font";
		Score1.setFont(gameFont2);
		Score1.setPosition(520 - Score1.getLocalBounds().width, 100);
		window.draw(Score1);
		///////////*Setting Score Finish*/////////////
		////////countdown200sec/////
		timeLeft.setPosition(558 - timeLeft.getLocalBounds().width, 300);
		window.draw(timeLeft);
	}
	else if(isGameOver1 || timeover)
	{

		gameOverText1.setFont(gameFont1);
		if (timeover)
		gameOverText1.setString("TIME OVER!");
		if(isGameOver1)
		gameOverText1.setString("GAME OVER!");
		gameOverText1.setCharacterSize(40);
		gameOverText1.setPosition(300 - gameOverText1.getLocalBounds().width / 2.0, 225);
		window.draw(gameOverText1);
		Score1.setPosition(300 - Score1.getLocalBounds().width / 2.0, 300);
		Score1.setCharacterSize(35);
		window.draw(Score1);

		
			/////entername/////////

			char nam1[1000];

			/*cin >> enternam;*/
			enternam1++;
			sprintf(nam1, " ", enternam1);
			Name1.setString(nam1);
			if (!gameFont1.loadFromFile("gamefont.ttf"))
				cout << "Unable to load game font";
			Name1.setFont(gameFont1);
			Name1.setPosition(300 - Name1.getLocalBounds().width, 100);
			
			/////entername/////////


		
		window.draw(Name1);

	}
	if ((isGameOver1 && isGameOver2) || timeover)
	{

		if (CurrentScore1 > CurrentScore2)
		{
			gameOverText1.setString("PLAYER ONE WON!!");
		}
		else if (CurrentScore2 > CurrentScore1)
		{
			gameOverText1.setString("PLAYER TWO WON!!");
			
		}
		else
		{
			gameOverText1.setString("IT'S A DRAW!");
		}
		gameOverText1.setFont(gameFont1);
		gameOverText1.setCharacterSize(50);
		gameOverText1.setPosition(600 - gameOverText1.getLocalBounds().width / 2.0, 100);
		window.draw(gameOverText1);
	}
	
	
	
}
