#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window/Mouse.hpp>
#include "anewgame.h"
#include "menu.h"
#include "highscores.h"
#include "gameover.h"
#include "instruction.h"
#include "newplayer.h"
using namespace sf;
using namespace std;
int main(){
  bool backAction=false;
  int index;
  int currentScreen=0, nextPage=0;
  float timePassed=0, delay=0.5, difficultyTime=10, timePassed2=0, timePassed3=0, elapsed=0;
  View View(FloatRect(0, 0, 1200, 600));
  RenderWindow window01(VideoMode(500,600),"Tetris 1.01RC",Style::Titlebar);
  instruction instructionScreen;
  gameover gameoverScreen;
  Menu menuScreen;
  HighScores Scores;
  ANewGame game;
  NewPlayer player2;
  Clock timeElapsed;
  Clock clockforMultiplayer;
  Time second = sf::seconds(1);
  instructionScreen.setInst(window01.getSize().x,window01.getSize().y);
  menuScreen.setMenuItems(window01.getSize().x,window01.getSize().y);
  Scores.setHighScore(window01.getSize().x,window01.getSize().y);
  game.getCurrentScoreList(Scores.returnHighScoreList());
  while(window01.isOpen()){
    if(game.isGameOver){
        if(game.checkHighScore()){
            index=game.indexForHighScore;
            gameoverScreen.getName(Scores.allNames);
        }
        Scores.setHighScore(window01.getSize().x, window01.getSize().y);
        game.resetGame();
        currentScreen=4;
        delay=0.5;
    }
    Event event01;
    float time = timeElapsed.getElapsedTime().asSeconds();
    timeElapsed.restart();
    timePassed+=time;
    timePassed2+=time;
    timePassed3+=time;
    if(timePassed>delay){
        if(currentScreen==2){
            game.FallBlock();
            timePassed=0;
        }
        if(currentScreen==5){
            player2.FallBlock1();
            player2.FallBlock2();
            timePassed=0;
        }
    }
    if(timePassed2>difficultyTime){
        if(delay-0.02>0.12)
            delay-=0.02;
        timePassed2=0;
    }
    if (currentScreen == 5)
	{
		if (elapsed <= 202)
		{
			elapsed = clockforMultiplayer.getElapsedTime().asSeconds();
			player2.clock(elapsed);
		}
	}
    while(window01.pollEvent(event01)){
        if(event01.type==Event::Closed){
            window01.close();
        }
        if(event01.type==Event::KeyPressed){

            if(event01.key.code==Keyboard::BackSpace){
                if(menuScreen.getSelectItem()==1 || currentScreen==5){
                  currentScreen=0;
                }
                if(currentScreen==2){
                    currentScreen=4;
                }
            }
            if(event01.key.code==Keyboard::Enter){
               if(currentScreen==0){
                if(menuScreen.getSelectItem()==3){
                    currentScreen=5;
                }
                if(menuScreen.getSelectItem()==1){
                  currentScreen=1;
                }
                if(menuScreen.getSelectItem()==0){
                  currentScreen=2;
                }
                if(menuScreen.getSelectItem()==2){
                  currentScreen=6;
                }
                if(menuScreen.getSelectItem()==4){
                    window01.close();
                }
               }
               if(currentScreen==4){
                 if(gameoverScreen.nameNeed){
                    gameoverScreen.setNames(index);
                    Scores.setHighScore(window01.getSize().x, window01.getSize().y);
                    gameoverScreen.stringReset();
                    gameoverScreen.nameNeed=false;
                 }
               }
            }
            if(event01.key.code==Keyboard::Up){
                if(currentScreen==0)
                    menuScreen.MoveUp();
            }
            if(event01.key.code==Keyboard::Down){
                if(currentScreen==0)
                    menuScreen.MoveDown();
                if (currentScreen == 2)
                    game.MoveDown();
                if(currentScreen==6)
                   player2.MoveDown2();

            }
            if(event01.key.code==Keyboard::Right){
                if(currentScreen==2){
                    game.setLeft();
                    game.Move();
                }
                if(currentScreen==6){
                    player2.setLeft2();
                    player2.Move2();
                }

            }
            if(event01.key.code==Keyboard::Left){
                if(currentScreen==2){
                    game.setRight();
                    game.Move();
                }
                if(currentScreen==6){
                    player2.setRight2();
                    player2.Move2();
                }
            }
            if(event01.key.code==Keyboard::Space){
                if(currentScreen==2){
                     game.Rotate();
                }
                if(currentScreen==6){
                    player2.Rotate2();
                }


            }
            if (event01.key.code == Keyboard::S) {

				if (currentScreen == 6)
					player2.MoveDown1();

			}

			if (event01.key.code == Keyboard::D) {
				if (currentScreen == 6) {
					player2.setLeft1();
					player2.Move1();
				}

			}
			if (event01.key.code == Keyboard::A) {
				if (currentScreen == 6) {
					player2.setRight1();
					player2.Move1();
				}
			}
			if (event01.key.code == Keyboard::W) {
				if (currentScreen == 6) {
					player2.Rotate1();
				}
			}
        }
       if (event01.type == Event::MouseMoved) {
			if(currentScreen==0){
              menuScreen.MouseWork(event01.mouseMove.x, event01.mouseMove.y);
			}
            if(currentScreen==1){
                if(Scores.isBackButtonChosen(event01.mouseMove.x, event01.mouseMove.y)){
                    backAction=true;
                }
              }
            if(currentScreen==4){
                gameoverScreen.OptionChosen(event01.mouseMove.x, event01.mouseMove.y);
            }
            if(currentScreen==5){
                instructionScreen.Mousework3(event01.mouseMove.x, event01.mouseMove.y);
            }
        }
        if(event01.type==Event::MouseButtonPressed){
              if(currentScreen==5){
                if(instructionScreen.getSelectItem3()==1){
                    nextPage=1;
                }
                else if(nextPage==0 && instructionScreen.getSelectItem3()==0){
                    currentScreen=0;
                }
                else if(nextPage==1 && instructionScreen.getSelectItem3()==0){
                    nextPage=0;
                }
              }
              if(currentScreen==0){
               if(menuScreen.getSelectItem()==3){
                    window01.close();
                }
                if(menuScreen.getSelectItem()==1){
                  currentScreen=1;
                }
                if(menuScreen.getSelectItem()==0){
                  currentScreen=2;
                }
              }
              if(currentScreen==1){
                if(backAction){
                    currentScreen=0;
                    backAction=false;
                }
              }
              if(currentScreen==4){
                if(!gameoverScreen.nameNeed){
                if(gameoverScreen.getSelectedOption()==0){
                    currentScreen=2;
                }
                else if(gameoverScreen.getSelectedOption()==1){
                    currentScreen=0;
                    if(!game.isGameOver)
                        game.resetGame();
                    delay=0.5;
                }
              }
              }
            }
        if(event01.type==Event::TextEntered){
            if(currentScreen==4){
              if(gameoverScreen.nameNeed){
                    gameoverScreen.playerInput+=event01.text.unicode;
                    gameoverScreen.playerText.setString(gameoverScreen.playerInput);
                }
            }
        }
    }

    window01.clear();
    if(!currentScreen)
        menuScreen.Draw(window01);
    else if(currentScreen==1)
        Scores.displayScore(window01);
    else if(currentScreen==2)
        game.Draw(window01);
    else if(currentScreen==4){
        gameoverScreen.draw(window01,game.isGameOver);
        }
    else if(currentScreen==5){
        instructionScreen.displayInstruction(window01,nextPage);
    }
    else if(currentScreen==6){
        window01.setSize(sf::Vector2u(1200, 600));
		FloatRect visibleArea(0, 0, 1200, 600);
        window01.setView(sf::View(visibleArea));
        player2.Draw2(window01);
    }

    window01.display();
  }
  return 0;
}
