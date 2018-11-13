#ifndef HIGHSCORES_H
#define HIGHSCORES_H 5
#include <SFML\Graphics.hpp>
#include <iostream>
#include<fstream>
#include<string>
class HighScores
{
  public:
    void displayScore(sf::RenderWindow &window);
    void setHighScore(double width, double height);
    bool isBackButtonChosen(int x, int y);
    int *returnHighScoreList();
    std::string allNames[HIGHSCORES_H];
    HighScores();
    virtual ~HighScores();

  protected:

  private:
  int currentScore;
  sf::Text ScoreName[HIGHSCORES_H];
  sf::Text Score[HIGHSCORES_H];
  int allScores[HIGHSCORES_H];
  sf::Font ScoreFont;
  sf::Texture backButtonTexture;
  sf::CircleShape backButton;

};

#endif // HIGHSCORES_H
