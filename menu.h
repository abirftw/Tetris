#ifndef MENU_H
#define MENU_H
#define MENU_ITEMS 5
#include <SFML\Graphics.hpp>
#include <iostream>

class Menu
{
  public:
    void Draw (sf::RenderWindow &window);
    void setMenuItems(double width, double height);
    void MoveUp();
    void MoveDown();
    void MouseWork(int xcor, int ycor);
    int getSelectItem();
    Menu();
    virtual ~Menu();

  protected:

  private:
  sf::Font MenuFont;
  sf::Text MenuItems[MENU_ITEMS];
  int selectedItem;
};

#endif // MENU_H
