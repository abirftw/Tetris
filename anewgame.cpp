#include<iostream>
#include<cstdlib>
#include<time.h>
#include <SFML\Graphics.hpp>
#include <fstream>
#include "anewgame.h"
using namespace std;
using namespace sf;
//Which Block Units to fill depending on the blockNo//
int Blocks[7][4] = {
	1 + 4,3 + 4,5 + 4,7 + 4,
	2 + 4,4 + 4,5 + 4,7 + 4,
	3 + 4,5 + 4,4 + 4,6 + 4,
	3 + 4,5 + 4,4 + 4,7 + 4,
	2 + 4,3 + 4,5 + 4,7 + 4,
	3 + 4,5 + 4,7 + 4,6 + 4,
	2 + 4,3 + 4,4 + 4,5 + 4,
    };

ANewGame::ANewGame()
{
  //all the default states when starting a new game
  for(int i=0; i<WidthBlocks; i++){
    for(int j=0; j<HeightBlocks; j++){
      field[j][i]=0;
    }
  } //all the game field unit is 0, meaning they are unfilled
  isGameOver=false; 
  srand(time(0)); //seeding time to generate more random numbers
  CurrentScore=0;
  randomBlockNo[0]=rand()%7; //using rand() to generate random numbers with respect to the current time
  ShapeNum=1+randomBlockNo[0];
  BlockNo=randomBlockNo[0];
    for(int i=0; i<4; i++){
      m[i].x=Blocks[BlockNo][i]/2;      // using the block array to fill the respective block units
      m[i].y=Blocks[BlockNo][i]%2;
    }
    checked=false;
    randomBlockNo[1]=rand()%7;
    indexForHighScore=-1;
  //ctor
}
ANewGame::~ANewGame()
{
  //dtor
}
bool ANewGame::isFilled(){
  for(int i=0; i<4; i++){
    if(m[i].x<0 || m[i].x>=WidthBlocks || m[i].y>=HeightBlocks) //checking if the block touches
      return false;
    else if(field[m[i].y][m[i].x])                              //any of the boundaries of the field
      return false;
  }
  return true;
}
void ANewGame::resetGame(){
  //turning back all the variables to the default state to reset the game
  for(int i=0; i<WidthBlocks; i++){
    for(int j=0; j<HeightBlocks; j++){
      field[j][i]=0;
    }
  }
  isGameOver=false;
  srand(time(0));
  CurrentScore=0;
  randomBlockNo[0]=rand()%7;
  ShapeNum=1+randomBlockNo[0];
  BlockNo=randomBlockNo[0];
    for(int i=0; i<4; i++){
      m[i].x=Blocks[BlockNo][i]/2;
      m[i].y=Blocks[BlockNo][i]%2;
    }
  randomBlockNo[1]=rand()%7;
  indexForHighScore=-1;
  
}
void ANewGame::setLeft(){
  dx=1;
}
void ANewGame::setRight(){
  dx=-1;
}
void ANewGame::MoveDown() {
	for (int i = 0; i < 4; i++) {
		n[i] = m[i];
		m[i].y += dy;
	}
	if (!isFilled()) {
		for (int i = 0; i < 4; i++) {
			m[i] = n[i];
		}
	}
}
void ANewGame::Move(){
  for(int i=0; i<4; i++){
    n[i]=m[i];
    m[i].x+=dx;
  }
  if(!isFilled()){
    for(int i=0; i<4; i++){
      m[i]=n[i];
    }
  }
}
void ANewGame::Rotate(){
  p=m[1];
  for(int i=0; i<4; i++){
      int x = m[i].y-p.y;
			int y = m[i].x-p.x;
			m[i].x = p.x - x;
			m[i].y = p.y + y;
  }
  if(!isFilled()){
    for(int i=0; i<4; i++){
      m[i]=n[i];
    }
  }
}
void ANewGame::FallBlock(){
  if(!isGameOver){
   for(int i=0; i<4; i++){
    n[i]=m[i];
    if(field[m[i].y][m[i].x]){
      isGameOver=true;
    }
    m[i].y+=1;
   }
   if(!isFilled()){
    for(int i=0; i<4; i++){
      field[n[i].y][n[i].x]=ShapeNum;
    }
     randomBlockNo[0]=randomBlockNo[1];

    ShapeNum=1+randomBlockNo[0];
    BlockNo=randomBlockNo[0];
    for(int i=0; i<4; i++){
      m[i].x=Blocks[BlockNo][i]/2;
      m[i].y=Blocks[BlockNo][i]%2;
    }
      randomBlockNo[1]=rand()%7;
   }
    
  }
}
int ANewGame::CheckLine(){
  int numOFLines=HeightBlocks-1;
  int ClearedLines=0;
  for(int i=HeightBlocks-1; i>=0; i--){  
     int BlocksInLine=0;
     for(int j=0; j<WidthBlocks; j++){ //checking whether block units fill the entire width of the field
        if(field[i][j])
          BlocksInLine++;
        field[numOFLines][j]=field[i][j];

     }
     if(BlocksInLine<WidthBlocks)
      numOFLines--; //if a line exists all the upper blocks will go down a line
     else
      ClearedLines++; 
  }
  return ClearedLines; //how many lines were cleared
}
bool ANewGame::checkHighScore(){
  if(isGameOver){
                          //To check which highscore can current score replace, 
                          //will retain -1 if can't replace any high score
  for(int i=5; i>=0; i--){
    if(CurrentScore>HighScoreList[i]){
      indexForHighScore=i;
    }
  }
  if(indexForHighScore==-1)
    return false;
  else{
    ofstream myfile;
    myfile.open("Scores.txt");
    while(myfile.is_open()){
      for(int i=0;HighScoreList[i]>CurrentScore; i++){
        myfile << HighScoreList[i] << "\n";
      }
      myfile << CurrentScore << "\n";
      for(int i=indexForHighScore; i<4 ; i++){
        myfile << HighScoreList[i];
        if(i<3) myfile << "\n";
      }
       myfile.close();
    }
    return true;
  }
}
  
}
void ANewGame::getCurrentScoreList(int allScore[]){
  for(int i=0; i<5; i++){
    HighScoreList[i]=allScore[i]; //store the scores in file for comparing with the current score
  }
}
void ANewGame::setScore(int LinesCleared){
  int scoreIncrease;
  int pointMultiplier=0;
  switch(LinesCleared){
  case 1:
    pointMultiplier=10;
    break;
  case 2:
    pointMultiplier=20;
    break;
  case 3:
    pointMultiplier=40;
    break;
  case 4:
    pointMultiplier=80;  //earning more points depending on the number of lines cleared
    break;
  default:
    break;
  }
  scoreIncrease=LinesCleared*pointMultiplier;
  CurrentScore+=scoreIncrease; //total score

}
void ANewGame::Draw(sf::RenderWindow& window){

  if(!background.loadFromFile("Blocks.png"))
    cout << "Couldn't load Background Texture";
  if(!blockUnit.loadFromFile("BlockUnit.png"))
    cout << "Couldn't load Block Texture";
  background.setRepeated(true);
  Sprite gameBackground, blockBackground;
  blockBackground.setTexture(blockUnit);
  gameBackground.setTexture(background);
  gameBackground.setTextureRect(IntRect(0,0,300,600));
  window.draw(gameBackground);
  for(int i=0; i<WidthBlocks; i++){  //draw the filled blocks in the field
    for(int j=0; j<HeightBlocks; j++){
      if(field[j][i]){
				switch (field[j][i]) {
        case 1:
          blockBackground.setColor(Color::Magenta);
          break;
				case 2:
					blockBackground.setColor(Color::White);
					break;
				case 3:
					blockBackground.setColor(Color::Green);
					break;
				case 4:
					blockBackground.setColor(Color::Blue);
					break;
				case 5:
					blockBackground.setColor(Color::Red);
					break;
				case 6:
					blockBackground.setColor(Color::Cyan);
					break;
				case 7:
					blockBackground.setColor(Color::Yellow);
					break;
				default:
						break;
				}
          blockBackground.setPosition(i*30,j*30);
          window.draw(blockBackground);

      }
    }
  }
  for(int i=0; i<4; i++){
		switch (ShapeNum)
		{
    case 1:
          blockBackground.setColor(Color::Magenta);
          break;
				case 2:
					blockBackground.setColor(Color::White);
					break;
				case 3:
					blockBackground.setColor(Color::Green);
					break;
				case 4:
					blockBackground.setColor(Color::Blue);
					break;
				case 5:
					blockBackground.setColor(Color::Red);
					break;
				case 6:
					blockBackground.setColor(Color::Cyan);
					break;
				case 7:
					blockBackground.setColor(Color::Yellow);
					break;
		default:
			break;
		}
    blockBackground.setPosition(m[i].x*30,m[i].y*30);
    window.draw(blockBackground);
  }
  Text nextBlockText;
  nextBlockText.setFont(gameFont);
  nextBlockText.setString("NEXT PIECE:");
  nextBlockText.setCharacterSize(20);
  nextBlockText.setPosition(300,250);
  window.draw(nextBlockText);
  for(int i=0; i<4; i++){
    nb[i].x=Blocks[randomBlockNo[1]][i]/2 + 10;
    nb[i].y=Blocks[randomBlockNo[1]][i]%2 + 10;
    switch(randomBlockNo[1]){
      case 1-1:
          blockBackground.setColor(Color::Magenta);
          break;
				case 2-1:
					blockBackground.setColor(Color::White);
					break;
				case 3-1:
					blockBackground.setColor(Color::Green);
					break;
				case 4-1:
					blockBackground.setColor(Color::Blue);
					break;
				case 5-1:
					blockBackground.setColor(Color::Red);
					break;
				case 6-1:
					blockBackground.setColor(Color::Cyan);
					break;
				case 7-1:
					blockBackground.setColor(Color::Yellow);
					break;
    }
    blockBackground.setPosition(nb[i].x*30,nb[i].y*30);
    window.draw(blockBackground);
  }
  ///////////*Setting Score Start*/////////////
  sf::Text scoreText;
  scoreText.setFont(gameFont);
  scoreText.setString("SCORE:");
  scoreText.setPosition(300,50);
  setScore(CheckLine());
  char temp[10];
  sprintf(temp,"%d",CurrentScore);
  Score.setString(temp);
  if(!gameFont.loadFromFile("gamefont.ttf"))
    cout << "Unable to load game font";
  Score.setFont(gameFont);
  Score.setPosition(490-Score.getLocalBounds().width, 100);
  window.draw(Score);
  window.draw(scoreText);
    ///////////*Setting Score Finish*/////////////

}

