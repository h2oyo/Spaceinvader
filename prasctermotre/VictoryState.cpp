#include "VictoryState.h"
#include "declcom.h"
#include <cstring>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
void VictoryState::update()
{

	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey('R'))
		applicationState = SPLASH;

}

void VictoryState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0, true, 0, 0x88888888);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You Lose!", x, y, s, s);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press R to Return to Main", x, y, s, s, color);


	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;
	unsigned highScore = 0;
	while (!fin.eof())	
	{
		unsigned t;
		fin >> t;			

		if (t > highScore) highScore = t;
		scores.push_back(t);
	}
	scores.pop_back();	
	fin.close();


	y = WINDOW_HEIGHT / 2;	

	s = 24 + sinf(sfw::getTime() * 6) * 2; 
	std::string score = "New high score!";
	if(scores[scores.size() - 1] == highScore)
	drawFontCentered(spriteFont, score.c_str(), 
		x + sinf(sfw::getTime() * 2) * 9,
		y + cosf(sfw::getTime() * 2) * 9 + 64,  
		s, s, RED);

	s = 24 + sinf(sfw::getTime() * 5) * 3; 
	score = "High Score: " + std::to_string(highScore);
	drawFontCentered(spriteFont, score.c_str(), 
		x + sinf(sfw::getTime() * 4) * 7,
		y + cosf(sfw::getTime() * 4) * 7 + 32,   
		s, s, RED);

	s = 24 + sinf(sfw::getTime() * 4) * 4;
	score = "Your Score: " + std::to_string(scores[scores.size() - 1]);
	drawFontCentered(spriteFont, score.c_str(), 
		x + sinf(sfw::getTime() * 3) * 8,
		y + cosf(sfw::getTime() * 3) * 8,  
		s, s, CYAN);

	s = 18;
	y = WINDOW_HEIGHT / 2 - scores.size() * s;
	for (int i = scores.size() - 2; i >= 0 && scores.size() - i < 12; --i)
	{
		drawFontCentered(spriteFont, std::to_string(scores[i]).c_str(),
			x, y + 18 * i, s, s);
	}
}