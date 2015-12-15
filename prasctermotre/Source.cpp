#include "sfwdraw.h"
#include "declcom.h"
#include "GameState.h"
#include "SplashState.h"
#include "PauseState.h"
#include "VictoryState.h"


unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteParticle;
unsigned spriteSpace;
unsigned spriteFont;

STATE applicationState = SPLASH;
int main()
{
	sfw::initContext(WINDOW_WIDTH,WINDOW_HEIGHT, "Space Invaders!");


	spritePlayer = sfw::loadTextureMap("./textures/Player.png");
	spriteParticle = sfw::loadTextureMap("./textures/Bullet.png");
	spriteEnemy = sfw::loadTextureMap("./textures/Enemy.png");
	spriteSpace = sfw::loadTextureMap("./textures/Background.jpg");
	spriteFont = sfw::loadTextureMap("./textures/fontmap.png", 16, 16);
	Player go(400,300);
	
	GameState gs;
	SplashState ss;
	PauseState ps;
	VictoryState vs;
	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		switch (applicationState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			gs.reset();
			applicationState = GAME;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			gs.update();
			gs.draw();
			vs.update();
			vs.draw();
			break;

		}
	}



	sfw::termContext();
	

	return 0;
}


void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(spriteFont, text, x, y, w, h, 0, 0, color);
}
