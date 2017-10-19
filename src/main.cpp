#include <sstream>
#include "include/libtcod/libtcod.hpp"
#include "systems/PlayerSystem.hpp"
#include "level/Level.hpp"
#include "utils/EventManager.hpp"

TCODRandom rng;
Level level;
EventManager eventManager;

int main()
{
	TCODConsole::setCustomFont("assets/font10x10.png", TCOD_FONT_LAYOUT_ASCII_INROW, 16, 16);
	TCODConsole::initRoot(80, 50, "Dog Barks");
	while (!TCODConsole::root->isWindowClosed())
	{
		TCODConsole::root->clear();
		level.update();
		TCODConsole::root->flush();
	}
	return 0;
}
