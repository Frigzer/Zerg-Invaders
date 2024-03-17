#include "settings.h"

void Settings::initControls()
{
	goLeft = sf::Keyboard::A;
	goRight = sf::Keyboard::D;
	shoot = sf::Keyboard::Space;
}

Settings::Settings()
{
}

Settings::Settings(float width, float height)
{
	if (!font.loadFromFile("Fonts/RubikBubbles-Regular.ttf"))
	{
		std::cout << "!ERROR::MENU::MENU::Nie udalo sie wczytac czcionki" << std::endl;
	}

	if (!backgroundTexture.loadFromFile("Textures/menu_background_1.jpg"))
		std::cout << "!ERROR::GAME::INITWORLD::Nie mozna zaladowac tla" << std::endl;

	background.setTexture(backgroundTexture);

	initControls();

	//Move Left: A
	choose[0].setFont(font);
	choose[0].setFillColor(sf::Color::Blue);
	choose[0].setOutlineColor(sf::Color::Black);
	choose[0].setOutlineThickness(2);
	choose[0].setString("Move Left: A");
	choose[0].setCharacterSize(30);
	choose[0].setPosition(sf::Vector2f(width / 2 - choose[0].getGlobalBounds().width/2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 1));


	//Move Left: LeftButton
	choose[1].setFont(font);
	choose[1].setFillColor(sf::Color::White);
	choose[1].setOutlineColor(sf::Color::Red);
	choose[1].setOutlineThickness(2);
	choose[1].setString("Move Left: LeftButton");
	choose[1].setCharacterSize(30);
	choose[1].setPosition(sf::Vector2f(width / 2 - choose[1].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 2));

	//Move Right: D
	choose[2].setFont(font);
	choose[2].setFillColor(sf::Color::White);
	choose[2].setOutlineColor(sf::Color::Black);
	choose[2].setOutlineThickness(2);
	choose[2].setString("Move Right: D");
	choose[2].setCharacterSize(30);
	choose[2].setPosition(sf::Vector2f(width / 2 - choose[2].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 3));

	//Move Right: RightButton
	choose[3].setFont(font);
	choose[3].setFillColor(sf::Color::White);
	choose[3].setOutlineColor(sf::Color::Red);
	choose[3].setOutlineThickness(2);
	choose[3].setString("Move Right: RightButton");
	choose[3].setCharacterSize(30);
	choose[3].setPosition(sf::Vector2f(width / 2 - choose[3].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 4));

	//Shoot: spacebar
	choose[4].setFont(font);
	choose[4].setFillColor(sf::Color::White);
	choose[4].setOutlineColor(sf::Color::Black);
	choose[4].setOutlineThickness(2);
	choose[4].setString("Shoot: spacebar");
	choose[4].setCharacterSize(30);
	choose[4].setPosition(sf::Vector2f(width / 2 - choose[4].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 5));

	//Shoot: W
	choose[5].setFont(font);
	choose[5].setFillColor(sf::Color::White);
	choose[5].setOutlineColor(sf::Color::Red);
	choose[5].setOutlineThickness(2);
	choose[5].setString("Shoot: W");
	choose[5].setCharacterSize(30);
	choose[5].setPosition(sf::Vector2f(width / 2 - choose[5].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 6));

	//Shoot: UpButton
	choose[6].setFont(font);
	choose[6].setFillColor(sf::Color::White);
	choose[6].setOutlineColor(sf::Color::Red);
	choose[6].setOutlineThickness(2);
	choose[6].setString("Shoot: UpButton");
	choose[6].setCharacterSize(30);
	choose[6].setPosition(sf::Vector2f(width / 2 - choose[6].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_OPTIONS + 1) * 7));

	mainMenuSelected = 0;
}

Settings::~Settings()
{

}

void Settings::setLeft(sf::Keyboard::Key key)
{
	goLeft = key;
	if(goLeft==sf::Keyboard::A)
	{
		choose[0].setOutlineColor(sf::Color::Black);
		choose[1].setOutlineColor(sf::Color::Red);
	}
	else if(goLeft==sf::Keyboard::Left)
	{
		choose[0].setOutlineColor(sf::Color::Red);
		choose[1].setOutlineColor(sf::Color::Black);
	}
}

void Settings::setRight(sf::Keyboard::Key key)
{
	goRight = key;
	if (goRight == sf::Keyboard::D)
	{
		choose[2].setOutlineColor(sf::Color::Black);
		choose[3].setOutlineColor(sf::Color::Red);
	}
	else if (goRight == sf::Keyboard::Right)
	{
		choose[2].setOutlineColor(sf::Color::Red);
		choose[3].setOutlineColor(sf::Color::Black);
	}
}

void Settings::setShoot(sf::Keyboard::Key key)
{
	shoot = key;
	if (shoot == sf::Keyboard::Space)
	{
		choose[4].setOutlineColor(sf::Color::Black);
		choose[5].setOutlineColor(sf::Color::Red);
		choose[6].setOutlineColor(sf::Color::Red);
	}
	else if (shoot == sf::Keyboard::W)
	{
		choose[4].setOutlineColor(sf::Color::Red);
		choose[5].setOutlineColor(sf::Color::Black);
		choose[6].setOutlineColor(sf::Color::Red);
	}
	else if (shoot == sf::Keyboard::Up)
	{
		choose[4].setOutlineColor(sf::Color::Red);
		choose[5].setOutlineColor(sf::Color::Red);
		choose[6].setOutlineColor(sf::Color::Black);
	}
}

sf::Keyboard::Key Settings::getLeft()
{
	return goLeft;
}

sf::Keyboard::Key Settings::getRight()
{
	return goRight;
}

sf::Keyboard::Key Settings::getShoot()
{
	return shoot;
}


void Settings::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		choose[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 6;
		}
		choose[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void Settings::moveDown()
{
	if (mainMenuSelected + 1 <= MAX_NUMBER_OF_OPTIONS)
	{
		choose[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 7)
		{
			mainMenuSelected = 0;
		}
		choose[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

int Settings::mainMenuPressed()
{
	return mainMenuSelected;
}

void Settings::update()
{
	
}

void Settings::render(sf::RenderWindow& target)
{
	target.clear();

	target.draw(background);

	for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; ++i)
	{
		target.draw(choose[i]);
	}

	target.display();
}