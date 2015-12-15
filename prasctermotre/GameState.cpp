#include "GameState.h"
#include "Player.h"
#include <fstream>
#include <string>

void GameState::update()
{

	spawnDelay += sfw::getDeltaTime();
	if (spawnDelay > spawnRate)
	{

		spawnDelay = 0;
		spawnEnemy(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
		spawnEnemy(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
	}






	player.update();
	
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i].update();
	}
	for (int i = 0; i < enemies.size(); ++i)
		enemies[i].update();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].update();

	//Player vs Bullets
	for (int i = 0; i < bullets.size(); ++i)
		collides(player, bullets[i]);

	// for every bullet and every enemy,
	for (int i = 0; i < enemies.size(); ++i) // for enemy
		for (int j = 0; j < bullets.size(); ++j) // for every bullet
			collides(enemies[i], bullets[j]);

	for (int i = 0; i+1 < bullets.size(); ++i)
		for (int j = i + 1; j < bullets.size(); ++j)
			collides(bullets[i], bullets[j]);

	if (applicationState == GAME)
	{
		if (!player.active)
		{
			std::fstream fout("scores.dat",std::ios_base::out|std::ios_base::app);
			fout << score << std::endl;
			fout.close();


			applicationState = VICTORY;
		}
		if (sfw::getKey('P'))
			applicationState = PAUSE;
	}
	else player.setInactive();
}

void GameState::draw()

{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT);
	

	player.draw();
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i].draw();
	}
	for (int i = 0; i <enemies.size(); ++i)
	{
		enemies[i].draw();
	}
	for (int i = 0; i <particles.size(); ++i)
	{
		particles[i].draw();
	}

	sfw::drawString(spriteFont, std::to_string(score).c_str(),
		0, WINDOW_HEIGHT, 20, 20);

	
}

void GameState::spawnBullet(float x, float y, float a_speed)
{
	Bullet b(x, y, a_speed);

	for (int i = 0; i < bullets.size(); ++i)
		if (!bullets[i].active)
		{
			bullets[i] = b;
			return;
		}
  	bullets.push_back(b);
}

void GameState::spawnEnemy(float x, float y)
{
	Enemy b(x, y);

	for (int i = 0; i < enemies.size(); ++i)
		if (!enemies[i].active)
		{
			enemies[i] = b;
			return;
		}
	enemies.push_back(b);
}

void GameState::spawnParticle(float x, float y, float a_startRadius, float a_endRadius, float a_lifetime, unsigned a_color)
{
	Particle b(x, y, a_startRadius, a_endRadius, a_lifetime, a_color);


	for (int i = 0; i < particles.size(); ++i)
		if (!particles[i].active)
		{
			particles[i] = b;
			return;
		}
	particles.push_back(b);

}
