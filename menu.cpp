#include "menu.h"

Menu::Menu()
{
	
}

Menu::Menu(float width, float height)
{
	menuMusicBuffer.loadFromFile("Music/terran_4.wav");
	menuMusic.setBuffer(menuMusicBuffer);
	menuMusic.setLoop(true);
	menuMusic.play();
	

	if (!backgroundTexture.loadFromFile("Textures/menu_background_1.jpg"))
		std::cout << "!ERROR::GAME::INITWORLD::Nie mozna zaladowac tla" << std::endl;

	background.setTexture(backgroundTexture);

	if (!font.loadFromFile("Fonts/RubikBubbles-Regular.ttf"))
	{
		std::cout << "!ERROR::MENU::MENU::Nie udalo sie wczytac czcionki" << std::endl;
	}

	menuTitle.setFont(font);
	menuTitle.setString("ZERG INVADERS");
	menuTitle.setFillColor(sf::Color::Red);
	menuTitle.setOutlineColor(sf::Color::Black);
	menuTitle.setOutlineThickness(2);
	menuTitle.setCharacterSize(100);
	menuTitle.setPosition(width / 2 - menuTitle.getGlobalBounds().width / 2, 40);


	//Play
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setOutlineThickness(2);
	menu[0].setString("Play");
	menu[0].setCharacterSize(70);
	menu[0].setPosition(sf::Vector2f(width / 2-menu[0].getGlobalBounds().width/2,40+ height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	//Options
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setOutlineThickness(2);
	menu[1].setString("Settings");
	menu[1].setCharacterSize(70);
	menu[1].setPosition(sf::Vector2f(width / 2 - menu[1].getGlobalBounds().width/2, 40 + height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	//Leaderboard
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setOutlineColor(sf::Color::Black);
	menu[2].setOutlineThickness(2);
	menu[2].setString("Scorerboard");
	menu[2].setCharacterSize(70);
	menu[2].setPosition(sf::Vector2f(width / 2 - menu[2].getGlobalBounds().width/2, 40 + height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	//Exit
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setOutlineColor(sf::Color::Black);
	menu[3].setOutlineThickness(2);
	menu[3].setString("Exit");
	menu[3].setCharacterSize(70);
	menu[3].setPosition(sf::Vector2f(width / 2 - menu[3].getGlobalBounds().width/2, 40 + height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	mainMenuSelected = 0;
}

Menu::~Menu()
{
	
}

void Menu::musicPlay()
{
	menuMusic.play();
}

void Menu::musicStop()
{
	menuMusic.stop();
}

void Menu::render(sf::RenderWindow& target)
{
	target.draw(background);
	target.draw(menuTitle);
	for (int i=0; i<MAX_NUMBER_OF_ITEMS;++i)
	{
		target.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		menu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 3;
		}
		menu[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void Menu::moveDown()
{
	if (mainMenuSelected + 1 <= MAX_NUMBER_OF_ITEMS)
	{
		menu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 4)
		{
			mainMenuSelected = 0;
		}
		menu[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

int Menu::mainMenuPressed()
{
	return mainMenuSelected;
}

