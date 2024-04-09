#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

std::vector<Sprite> createEnemies(Texture* texture)
{
	srand((int)time(0));
	int numEnemies = rand() % 15 + 1;

	std::vector<Sprite> enemies;

	// Set up the enemy sprite
	Sprite enemy;
	enemy.setTexture(*texture);
	enemy.rotate(180);

	for (int i = 0; i < numEnemies; i++)
	{
		float x = (rand() % 1850) + 70;
		float y = -(rand() % 1080);
		enemy.setPosition(x, y);
		enemies.push_back(enemy);
	}

	return enemies;

}

void moveEnemies(std::vector<Sprite>* enemies, Time dt)
{
	float enemySpeed = 0.0f;

	for (int i = 0; i < enemies->size(); i++)
	{
		enemySpeed = (rand() % 200) + 300;

		// Move each enemy down
		enemies->at(i).setPosition(enemies->at(i).getPosition().x,
			enemies->at(i).getPosition().y + (enemySpeed * dt.asSeconds()));
	}
}
