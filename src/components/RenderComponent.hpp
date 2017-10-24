#pragma once
#include "../include/libtcod/libtcod.hpp"
#include "PositionComponent.hpp"
#include "../Tile.hpp"
#include "../utils/Global.hpp"
#include <string>

struct RenderComponent {
	RenderComponent(const int tile = NOTHING, const std::string name = "Object", const TCODColor foreground = TCODColor::white)
		: _tile(tile), _fg(foreground), _bg(TCODColor::black), _name(name) {}
	~RenderComponent() {}

	void update(PositionComponent pos) const
	{
		TCODConsole::root->putCharEx(pos._x, pos._y, _tile, _fg, _bg);
	}

	int _tile;
	TCODColor _fg;
	TCODColor _bg;
	std::string _name;
};