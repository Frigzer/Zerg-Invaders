#include "scoreboard.h"

void Scoreboard::initText()
{
	if (!font.loadFromFile("Fonts/RubikBubbles-Regular.ttf"))
	{
		std::cout << "!ERROR::MENU::MENU::Nie udalo sie wczytac czcionki" << std::endl;
	}

	results.setFont(font);
	results.setCharacterSize(30);
	results.setFillColor(sf::Color::Blue);
	results.setOutlineColor(sf::Color::Red);
	results.setOutlineThickness(2);
	results.setPosition(10,10);
}

Scoreboard::Scoreboard()
{
	if (!backgroundTexture.loadFromFile("Textures/menu_background_1.jpg"))
		std::cout << "!ERROR::GAME::INITWORLD::Nie mozna zaladowac tla" << std::endl;

	background.setTexture(backgroundTexture);

	initText();

	StringCrypter* obj = new StringCrypter("a9d1r6cx4x9v0d5p7w4m5k29v9xc02457sc64u1h");
	std::string temp;

	std::ifstream plik("Leaderboard/wyniki.txt");
	if (plik.is_open())
	{
		char wiersz[10000];
		while (plik.getline(wiersz, 10000))
		{
			string plainText = obj->decryptString(wiersz);
			temp.insert(0,plainText);
			//temp+= plainText;
			//temp += "\n";
		}
	}
	results.setString(temp);//????????????????
	plik.close();
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::render(sf::RenderWindow& target)
{
	target.clear();
	target.draw(background);

	target.draw(results);

	target.display();
}
