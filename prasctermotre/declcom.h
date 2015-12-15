#pragma once

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BOUNDS_TOP 600
#define BOUNDS_BOTTOM 40
#define BOUNDS_LEFT 80
#define BOUNDS_RIGHT 720

#define ORAGNE 0xffA500ff

#define TITLE "Space Invaders"

class GameState;


//declaration
extern unsigned spritePlayer;
extern unsigned spriteEnemy;
extern unsigned spriteParticle;
extern unsigned spriteSpace;
extern unsigned spriteFont;

enum STATE { SPLASH, PLAY, GAME, PAUSE, VICTORY, QUIT, HELP };

extern STATE applicationState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color = 0xffffffff);