#include "game.h"
#include "menu.h"
#include "window.h"
#include "settings.h"
#include "scoreboard.h"

#include <time.h>
#include <vector>

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <Windows.h>


int main()
{

	//Ukrycie terminala
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, 0);

	//Generowanie liczb losowych
	srand((unsigned)(time(0)));

	//Tekstura ekranu ³adowania
	sf::Texture loadingTexture;

	//Ekran ³adowania
	sf::Sprite loadingScreen;
	
	//Inicjalizacja ekranu ³adowania
	loadingTexture.loadFromFile("Textures/loading_screen_1.jpg");
	loadingScreen.setTexture(loadingTexture);

	//Obiekt gry
	Window window;

	//Inicjalizacja menu
	Menu menu(window.getWindow()->getSize().x, window.getWindow()->getSize().y);

	//Definicja gry
	Game* game;

	//Definicja ekranu wyników
	Scoreboard* scoreboard;

	//Inicjalizacja ustawieñ
	Settings settings(window.getWindow()->getSize().x, window.getWindow()->getSize().y);

	//Domyœlne sterowanie
	sf::Keyboard::Key goLeft = sf::Keyboard::A;
	sf::Keyboard::Key goRight = sf::Keyboard::D;
	sf::Keyboard::Key shoot = sf::Keyboard::Space;

	//Pêtla dpowiedzialna za dzia³anie gry
	while(window.getWindow()->isOpen())
	{	
		sf::Event event;
		while (window.getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.getWindow()->close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					menu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					menu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					bool gotoMainLoop = false;
					int x = menu.mainMenuPressed();
					switch (x)
					{
					case 0:
						window.getWindow()->clear();
						window.getWindow()->draw(loadingScreen);
						window.getWindow()->display();
						menu.musicStop();
						game = new Game(window.getWindow()->getSize().x, window.getWindow()->getSize().y, goLeft, goRight, shoot);
						gotoMainLoop = false;
						while (window.getWindow()->isOpen() && !gotoMainLoop)
						{
							sf::Event aevent;
							while (window.getWindow()->pollEvent(aevent) && !gotoMainLoop)
							{
								if (aevent.type == sf::Event::Closed)
								{
									window.getWindow()->close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										gotoMainLoop = true;
										menu.musicPlay();
									}
								}
							}
							if (game->getPlayerHp() > 0 && !game->getGameOver())
								game->update(window.getWindow()->getSize().x, window.getWindow()->getSize().y);

							game->render(*window.getWindow());
							
						}
						
						delete game;
						break;
					case 1:
						//window.getWindow()->clear();
						//window.getWindow()->draw(loadingScreen);
						//window.getWindow()->display();
						
						//settings = new Settings(window.getWindow()->getSize().x, window.getWindow()->getSize().y, );
						gotoMainLoop = false;
						while (window.getWindow()->isOpen() && !gotoMainLoop)
						{
							sf::Event aevent;
							while (window.getWindow()->pollEvent(aevent) && !gotoMainLoop)
							{
								if (aevent.type == sf::Event::Closed)
								{
									window.getWindow()->close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										gotoMainLoop = true;
										
									}
								}
								if (aevent.type == sf::Event::KeyReleased)
								{
									if (aevent.key.code == sf::Keyboard::Up)
									{
										settings.moveUp();
										break;
									}
									if (aevent.key.code == sf::Keyboard::Down)
									{
										settings.moveDown();
										break;
									}
									if (aevent.key.code == sf::Keyboard::Return)
									{
										
										int y = settings.mainMenuPressed();
										switch (y)
										{
										case 0:
											settings.setLeft(sf::Keyboard::A);
											goLeft = settings.getLeft();
											break;
										case 1:
											settings.setLeft(sf::Keyboard::Left);
											goLeft = settings.getLeft();
											break;
										case 2:
											settings.setRight(sf::Keyboard::D);
											goRight = settings.getRight();
											break;
										case 3:
											settings.setRight(sf::Keyboard::Right);
											goRight = settings.getRight();
											break;
										case 4:
											settings.setShoot(sf::Keyboard::Space);
											shoot = settings.getShoot();
											break;
										case 5:
											settings.setShoot(sf::Keyboard::W);
											shoot = settings.getShoot();
											break;
										case 6:
											settings.setShoot(sf::Keyboard::Up);
											shoot = settings.getShoot();
											break;
										}
									}
								}
							}

							settings.render(*window.getWindow());
						}
						break;

					case 2:

						//window.getWindow()->clear();
						//window.getWindow()->draw(loadingScreen);
						//window.getWindow()->display();
						//menu.musicStop();
						scoreboard = new Scoreboard();
						gotoMainLoop = false;
						while (window.getWindow()->isOpen() && !gotoMainLoop)
						{
							sf::Event aevent;
							while (window.getWindow()->pollEvent(aevent) && !gotoMainLoop)
							{
								if (aevent.type == sf::Event::Closed)
								{
									window.getWindow()->close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										gotoMainLoop = true;
									}
								}
							}
							scoreboard->render(*window.getWindow());
						}
						delete scoreboard;
						break;
					case 3:		
						window.getWindow()->close();
						break;
					}
				}
			}
		}
		window.getWindow()->clear();
		menu.render(*window.getWindow());
		window.getWindow()->display();
	}
	
	//Koniec
	return 0;
}