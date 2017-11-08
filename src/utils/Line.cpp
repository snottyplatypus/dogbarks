#include "Line.hpp"
#include "../level/Level.hpp"

bool PhysicalLine::putPoint(int x, int y)
{
	_lastPos = { x, y };
	switch (TCODConsole::root->getChar(x, y))
	{
	case BLOCK3:
	case GANG_B:
	case DOOR:
		return false;
		break;
	default:
		break;
	}	
	TCODConsole::root->putCharEx(x, y, TCODConsole::root->getChar(x, y), TCODConsole::root->getCharForeground(x, y), _bg);
	return true;
}

bool BloodLine::putPoint(int x, int y)
{
	switch (TCODConsole::root->getChar(x + _mod._x, y + _mod._y))
	{
	case BLOCK3:
	case BLOCK2:
	case GANG_B:
	case DOOR:
		return false;
		break;
	default:
		break;
	}
	level._terrain[x][y] = {
							level._terrain[x][y]._renderer->_tile,
							level._terrain[x][y]._renderer->_name,
							level._terrain[x][y]._isTransparent,
							level._terrain[x][y]._isWalkable,
							TCODColor::darkerRed,
							TCODColor::darkestRed
							};
	return true;
}
