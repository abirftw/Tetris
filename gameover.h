#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML\Graphics.hpp>
#include <iostream>


class gameover
{
  public:
    gameover();
    virtual ~gameover();
    void draw(sf::RenderWindow &window, bool over);
    int getSelectedOption();
    void setNames(int index);
    void stringReset();
    void getName(std::string all[]);
    void OptionChosen(int x, int y);
    std::string playerInput;
    sf::Text playerText;
    bool nameNeed;

  protected:

  private:
    std::string allNames[5];
    int nameToReplace;
    sf::Text gameOverText;
    sf::Font gameFont;
    sf::Text newHighscore;
    sf::Text Options[2];
    sf::RectangleShape TextField;
    int selectedOption;
};

#endif // GAMEOVER_H
