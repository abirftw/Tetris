#ifndef ANEWGAME_H
#define ANEWGAME_H
#include<cstdlib>
#include<time.h>
#include <SFML\Graphics.hpp>
#include <iostream>

class ANewGame
{
  public:
    ANewGame();
    int returnCurrentScore();
    bool isFilled();
    void Move();
    void setLeft();
    void setRight();
    void Rotate();
    void FallBlock();
    void MoveDown();
    int CheckLine();
    void setScore(int LinesCleared);
    bool checkHighScore();
    void getCurrentScoreList(int allScore[]);
    void Draw(sf::RenderWindow &window);
    bool isGameOver;
    void resetGame();
    int indexForHighScore;
    sf::Font gameFont;
    ~ANewGame();

  protected:

  private:
    const int WidthBlocks = 10;
    const int HeightBlocks = 20;
    int field[20][10];
    struct coordinates{
      int x, y;
    }m[4],n[4],p,nb[4];
		int dx = 0;
		int dy = 1;
    int ShapeNum;
    int BlockNo;
    int randomBlockNo[2];
    bool checked;
    int CurrentScore;
    int HighScoreList[5];
    sf::Texture background, blockUnit;
    sf::Text Score;
};

#endif // ANEWGAME_H
