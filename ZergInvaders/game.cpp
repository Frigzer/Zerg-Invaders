#include "game.h"

void Game::initGUI(float width, float height)
{
	//Wczytuje czcionkê

	if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "!ERROR::GAME::INITGUI::Nie udalo sie wczytac czcionki" << std::endl;

	//Tekst ile punktów
	pointText.setFont(font);
	pointText.setCharacterSize(36);
	pointText.setFillColor(sf::Color::White);
	pointText.setString("test");
	pointText.setPosition(20.f, enemiesLeft.getPosition().y);

	//Tekst pozostali przeciwnicy
	enemiesLeft.setFont(font);
	enemiesLeft.setCharacterSize(36);
	enemiesLeft.setFillColor(sf::Color::White);
	enemiesLeft.setPosition(width / 4.f, 0.f);

	//Tekst stage
	stageText.setFont(font);
	stageText.setCharacterSize(36);
	stageText.setFillColor(sf::Color::White);

	//Ikonka hp
	hpTexture.loadFromFile("Textures/TerranDominionLogo.png");
	
	hpSymbol1.setTexture(hpTexture);
	hpSymbol1.setScale(0.1f, 0.1f);
	hpSymbol1.setPosition(width - hpSymbol1.getGlobalBounds().width, 10.f);

	hpSymbol2.setTexture(hpTexture);
	hpSymbol2.setScale(0.1f, 0.1f);
	hpSymbol2.setPosition(hpSymbol1.getPosition().x- hpSymbol2.getGlobalBounds().width, 10.f);

	hpSymbol3.setTexture(hpTexture);
	hpSymbol3.setScale(0.1f, 0.1f);
	hpSymbol3.setPosition(hpSymbol2.getPosition().x - hpSymbol3.getGlobalBounds().width, 10.f);

	//Tekst koñca gry
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setString("GAME OVER!");
	gameOverText.setPosition(
		width / 2.f - gameOverText.getGlobalBounds().width / 2.f,
		height / 2.f - gameOverText.getGlobalBounds().height / 2.f
	);

	//Tekst do pliku
	saveToFile = "";

	loadLoadingScreen = false;

}

void Game::initAudio(float width, float height)
{
	zergDeathBuffer.loadFromFile("Sound/zerg_death.wav");
	zergDeath.setBuffer(zergDeathBuffer);
	zergDeath.setVolume(40);

	explosionBuffer.loadFromFile("Sound/get_damaged.wav");
	explosion.setBuffer(explosionBuffer);
	explosion.setVolume(40);

	playerDeathBuffer.loadFromFile("Sound/get_destroyed.wav");
	playerDeath.setBuffer(playerDeathBuffer);
	playerDeath.setVolume(40);

	playerEatenAliveBuffer.loadFromFile("Sound/player_death.wav");
	playerEatenAlive.setBuffer(playerEatenAliveBuffer);
	playerEatenAlive.setVolume(40);

	queenDeathBuffer.loadFromFile("Sound/queen_death.wav");
	queenDeath.setBuffer(queenDeathBuffer);
	queenDeath.setVolume(40);

	projectileBuffer.loadFromFile("Sound/shot.wav");
	projectileSound.setBuffer(projectileBuffer);
	projectileSound.setVolume(20);

	terran1.loadFromFile("Music/terran_1.wav");
	backgrundMusic.setBuffer(terran1);
	backgrundMusic.setLoop(true);
	backgrundMusic.play();

	
}

void Game::initTextures(float width, float height)
{
	textures["playerBullet"] = new sf::Texture();
	textures["playerBullet"]->loadFromFile("Textures/fireball.png");

	textures["guardianBullet"] = new sf::Texture();
	textures["guardianBullet"]->loadFromFile("Textures/accid_bullet.png");

	textures["broodlordBullet"] = new sf::Texture();
	textures["broodlordBullet"]->loadFromFile("Textures/zerg_scourge_1.png");

	bloodTexture.loadFromFile("Textures/zerg_death.png");
	zergBloodSplash.setTexture(bloodTexture);
	zergBloodSplash.setScale(0.1f, 0.1f);

	playerDeathTexture.loadFromFile("Textures/explosion.png");
	playerDeathImage.setTexture(playerDeathTexture);
	playerDeathImage.setScale(0.2f, 0.2f);
	
}

void::Game::initSettings(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shoot)
{
	
	goLeft=left;
	goRight=right;
	this->shoot=shoot;

}

void Game::initPlayer(float width, float height)
{
	player = new Player();
	player->setPlayerPosition(
		width / 2.f - player->getPlayerBounds().width / 2.f,
		height - 100
	);
	gameOver = false;
}

void Game::initEnemies(float width, float height)
{
	
	death_animation = false;
	enemy_deleted = false;
	queen_defeated = false;
	spawnTimerMax = 1600.f;

	spawnTimer= spawnTimerMax;

	newGamePlus = 1;

	difficulty = 1.f;

	right = false;
	left = false;

	queen = new Enemy;
	
	float k = 40.f;
	float l = height / 6.f;

	for (int i = 0; i < 40; i++)
	{
		enemies.push_back(new Enemy(newGamePlus ,rand()%(101- newGamePlus)+ newGamePlus, k, l));
		k += enemies[i]->getEnemyBounds().width+20.f;

		if (enemies[i]->getEnemyPosition().x + 2 * enemies[i]->getEnemyBounds().width + 40.f >= width)
		{
			k = 40.f;
			l += enemies[i]->getEnemyBounds().height;
		}
	}
	direction = 0.1f;
}

void Game::initWorld(float width, float height)
{
	if (!backgroundTexture.loadFromFile("Textures/background3.jpg"))
		std::cout << "!ERROR::GAME::INITWORLD::Nie mozna zaladowac tla" << std::endl;

	background.setTexture(backgroundTexture);

	loadingTexture.loadFromFile("Textures/loading_screen_1.jpg");
	loadingScreen.setTexture(loadingTexture);
}

Game::Game(float width, float height, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shoot)
{
	initWorld(width, height);

	initGUI(width, height);

	initTextures(width, height);

	initSettings(left, right, shoot);

	initPlayer(width, height);

	initAudio(width, height);

	initEnemies(width, height);

}

Game::~Game()
{
	delete player;

	//Usuwanie tekstur
	for (auto& i : textures)
	{
		delete i.second;
	}
	textures.clear();

	//Usuwanie pocisków gracza
	for (auto* i : playerBullets)
	{
		delete i;
	}
	playerBullets.clear();

	//Usuwanie pocisków przeciwników
	for (auto* i : enemyBullets)
	{
		delete i;
	}
	enemyBullets.clear();

	//Usuwanie przeciwników
	for (auto* i : enemies)
	{
		delete i;
	}
	enemies.clear();

	//Usuwanie królowej
	delete queen;
	
	getContentToFile();

}

int& Game::getPlayerHp()
{
	return player->getHp();
}

void Game::getContentToFile()
{
	StringCrypter* obj = new StringCrypter("a9d1r6cx4x9v0d5p7w4m5k29v9xc02457sc64u1h");
	std::string temp = saveToFile;
	std::ofstream plik("Leaderboard/wyniki.txt", std::ios_base::app);
	string password = obj->encryptString(temp);
	password += "\n";
	plik << password;
	plik.close();
}

void Game::spawnEnemies(float width, float height)
{
	player->setHp(3);
	newGamePlus += 1;
	difficulty = 1;
	float k = 40.f;
	float l = height / 6.f;

	for (int i = 0; i < 40; i++)
	{
		
		enemies.push_back(new Enemy(newGamePlus,rand() % (101 - newGamePlus) + newGamePlus, k, l));
		k += enemies[i]->getEnemyBounds().width + 20.f;
		
		

		if (enemies[i]->getEnemyPosition().x + 2 * enemies[i]->getEnemyBounds().width + 40.f >= width)
		{
			k = 40.f;
			l += enemies[i]->getEnemyBounds().height;
		}
	}
	direction = 0.1f;
}

void Game::spawnQueen(float width, float height)
{
	
	spawnTimer += 0.5f;

	int temp = rand() % 2 + 400;

	//Spawnuje lec¹cego w lewo
	if (spawnTimer >= spawnTimerMax && temp == 400)
	{
		queen=new Enemy(1,temp, width + queen->getEnemyBounds().width, 60.f);
		left = true;
		spawnTimer = 0.f;
	}
	//Spawnuje lec¹cego w prawo
	else if (spawnTimer >= spawnTimerMax && temp == 401)
	{
		queen= new Enemy(1,temp, 0.f - queen->getEnemyBounds().width - 40.f, 60.f);
		right = true;
		spawnTimer = 0.f;
	}

	//Leci w lewo
	if (left)
		queen->move(-1.f, 0.f);
	//Leci w prawo
	else if (right)
		queen->move(1.f, 0.f);

	//Usuwa lec¹cego w prawo
	if (queen->getEnemyPosition().x > width && right)
	{
		difficulty += 1.f;
		delete queen;
		queen = new Enemy;
		right = false;
	}
	//Usuwa lec¹cego w lewo
	else if (queen->getEnemyPosition().x + queen->getEnemyBounds().width < 0.f && left)
	{
		difficulty += 1.f;
		delete queen;
		queen = new Enemy;
		left = false;

	}
}

void Game::updateGUI(float width, float height)
{
	std::stringstream point;
	std::stringstream rest;
	std::stringstream stage;

	time_t current_time = time(NULL);

	struct tm* curtime = localtime(&current_time);

	point << "Score: " << points;

	pointText.setString(point.str());
	rest << "\tEnemies left: " << enemies.size() << "\t Stage: " << newGamePlus;
	enemiesLeft.setString(rest.str());

	stage << "\t Stage: " << newGamePlus << "\tDate: " << asctime(curtime) << "\n";
	stageText.setString(stage.str());
	saveToFile = pointText.getString() + stageText.getString();
	
}

void Game::updatePlayerInput(float width, float height)
{
	//Poruszanie siê postaci
	//W lewo
	if (sf::Keyboard::isKeyPressed(goLeft))
		player->move(-1.f, 0.f);
	//w prawo
	else if (sf::Keyboard::isKeyPressed(goRight))
		player->move(1.f, 0.f);

	//Strzelanie
	if (sf::Keyboard::isKeyPressed(shoot) && player->canAttack())
	{
		projectileSound.play();
		playerBullets.push_back(new Bullet(
			textures["playerBullet"],
			player->getPlayerPosition().x + player->getPlayerBounds().width / 2.9f,
			player->getPlayerPosition().y,
			0.f,
			-1.f,
			8.f//5
		)
		);
	}
}

void Game::updatePlayerCollision(float width, float height)
{
	//Kolizja w lewo
	if (player->getPlayerPosition().x < 0.f)
		player->setPlayerPosition(0.f, player->getPlayerPosition().y);
	//Kolizja w prawo
	else if (player->getPlayerPosition().x + player->getPlayerBounds().width > width)
		player->setPlayerPosition(width - player->getPlayerBounds().width, player->getPlayerPosition().y);
}

void Game::updateBullets(float width, float height)
{
	// Usuwanie pocisków gracza
	for (auto bullet = playerBullets.begin(); bullet != playerBullets.end(); )
	{
		(*bullet)->update();

		if ((*bullet)->getBounds().top + (*bullet)->getBounds().height < 0.f)
		{
			delete* bullet;
			bullet = playerBullets.erase(bullet);
		}
		else
		{
			++bullet;
		}
	}

	// Usuwanie pocisków przeciwników
	for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end(); )
	{
		(*bullet)->update();

		if ((*bullet)->getBounds().top > height)
		{
			delete* bullet;
			bullet = enemyBullets.erase(bullet);
		}
		else
		{
			++bullet;
		}
	}
}

void Game::updateEnemies(float width, float height)
{
	
	for (auto* enemy : enemies)
	{
		if (enemy->getEnemyPosition().y + enemy->getEnemyBounds().height >= 2.f + player->getPlayerPosition().y)
		{
			playerEatenAlive.play();
			gameOver = true;
		}
		//Poruszanie siê
		//W prawo
		if (enemy->getEnemyPosition().x + enemy->getEnemyBounds().width >= width && direction > 0)
		{
			direction *= -1.0f;
			for (auto* enemy : enemies) { enemy->move(-1.f, 10.f); }
		}
		//W lewo
		else if (enemy->getEnemyPosition().x <= 0.f && direction < 0)
		{
			direction *= -1.0f;
			
			for (auto* enemy : enemies) { enemy->move(1.f, 10.f); }
		}
		enemy->move((direction*1.f)*difficulty, 0.f);
		
		//Strzelanie
		if (enemy->getEnemyType() == 1 && enemy->canAttack() && (rand()%100+1)>87)
		{
			enemyBullets.push_back(new Bullet(
				textures["guardianBullet"],
				enemy->getEnemyPosition().x + enemy->getEnemyBounds().width / 3.f,
				enemy->getEnemyPosition().y + enemy->getEnemyBounds().height,
				0.f,
				1.f,
				7.f//5
			)
			);
		}
		else if (enemy->getEnemyType() == 2 && enemy->canAttack() && (rand() % 100 +1) > 94)
		{
			enemyBullets.push_back(new Bullet(
				textures["broodlordBullet"],
				enemy->getEnemyPosition().x + enemy->getEnemyBounds().width / 3.f,
				enemy->getEnemyPosition().y + enemy->getEnemyBounds().height,
				0.f,
				1.f,
				10.f//7
			)
			);
		}
		enemy->update();
	}

}

void Game::updateCombat(float width, float height)
{
	//Œmieræ przeciwnika
	death_animation = false;
	for (int i = 0; i < enemies.size(); ++i)
	{
		enemy_deleted = false;
		for (size_t j = 0; j < playerBullets.size() && !enemy_deleted; j++)
		{
			if (enemies[i]->getEnemyBounds().intersects(playerBullets[j]->getBounds()))
			{
				enemies[i]->loseHp(1);
				if (enemies[i]->getHp() <= 0)
				{
					zergBloodSplash.setPosition(enemies[i]->getEnemyPosition().x, enemies[i]->getEnemyPosition().y);
					points += enemies[i]->getPoints();
					difficulty += 0.5f;
					zergDeath.play();
					delete enemies[i];
					enemies.erase(enemies.begin() + i);

					enemy_deleted = true;
					death_animation = true;

				}
				delete playerBullets[j];
				playerBullets.erase(playerBullets.begin() + j);	
				
			}
		}
	}

	//Strata hp gracza
	for (int i = 0; i < enemyBullets.size(); ++i)
	{
		if (player->getPlayerBounds().intersects(enemyBullets[i]->getBounds()))
		{
			
			player->loseHp(1);
			if(getPlayerHp() >= 1)
				explosion.play();
			else
				playerDeath.play();

			delete enemyBullets[i];
			enemyBullets.erase(enemyBullets.begin() + i);
		}
	}

	//Pokonanie królowej
	queen_defeated = false;
	for (size_t i = 0; i < playerBullets.size() && !queen_defeated; i++)
	{
		if (queen->getEnemyBounds().intersects(playerBullets[i]->getBounds()))
		{
			zergBloodSplash.setPosition(queen->getEnemyPosition().x, queen->getEnemyPosition().y);
			points += queen->getPoints();
			queenDeath.play();
			delete queen;
			queen = new Enemy;

			right = false;
			left = false;

			delete playerBullets[i];
			playerBullets.erase(playerBullets.begin() + i);
			queen_defeated = true;
		}
	}
}

bool Game::getGameOver()
{
	return gameOver;
}

void Game::updateHp(float width, float height)
{
	
}

void Game::update(float width, float height)
{
	updateGUI(width, height);

	player->update();

	updatePlayerInput(width, height);

	updatePlayerCollision(width, height);

	updateEnemies(width, height);

	updateBullets(width, height);

	updateCombat(width, height);

	spawnQueen(width, height);

	updateHp(width, height);

	if (enemies.size() == 0 && loadLoadingScreen)
	{
		//Usuwanie pocisków gracza
		for (auto* i : playerBullets)
		{
			delete i;
		}
		playerBullets.clear();

		//Usuwanie pocisków przeciwników
		for (auto* i : enemyBullets)
		{
			delete i;
		}
		enemyBullets.clear();

		spawnEnemies(width, height);
		loadLoadingScreen = false;
	}
}



void Game::renderGUI(sf::RenderWindow* target)
{
	target->draw(pointText);

	target->draw(enemiesLeft);

	if (getPlayerHp() == 3)
	{
		target->draw(hpSymbol1);
		target->draw(hpSymbol2);
		target->draw(hpSymbol3);
	}
	else if(getPlayerHp() == 2)
	{
		target->draw(hpSymbol1);
		target->draw(hpSymbol2);
	}
	else if(getPlayerHp() == 1)
		target->draw(hpSymbol1);
}

void Game::render(sf::RenderWindow& target)
{
	target.clear();

	target.draw(background);

	player->render(&target);

	queen->render(&target);
	if (queen_defeated)
		target.draw(zergBloodSplash);

	for (auto* enemy : enemies)
	{
		enemy->render(&target);
	}
	if (death_animation)
	{
		target.draw(zergBloodSplash);
	}

	for (auto* bullet : playerBullets)
	{
		bullet->render(&target);
	}

	for (auto* bullet : enemyBullets)
	{
		bullet->render(&target);
	}

	renderGUI(&target);

	if (enemies.size() == 0)
	{
		loadLoadingScreen = true;
		target.draw(loadingScreen);
	}

	if (player->getHp() <= 0 || getGameOver())
	{
		playerDeathImage.setPosition(player->getPlayerPosition().x, player->getPlayerPosition().y);
		target.draw(playerDeathImage);
		target.draw(gameOverText);
		backgrundMusic.stop();
	}

	target.display();
}


