#include "sfwdraw.h"
#include "player.h"
#include <iostream>

int main()
{

	sfw::initContext(600, 600, "waddap" );
	sfw::setBackgroundColor(0x3C1053FF);
	Player me;
	me.pos = { 400,300 };
	me.speed = 10;

	Player bot;
	bot.pos = { 200, 200 };
	


	while (sfw::stepContext())
	{
		me.update();
		me.Draw();
	}

	
	
	sfw::termContext();
}