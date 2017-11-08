#pragma once
#include "../include/libtcod/libtcod.hpp"
#include "PositionComponent.hpp"
#include "../utils/Global.hpp"
#include "../utils/DataManager.hpp"
#include <string>

struct RenderComponent {
	RenderComponent(std::string tile = "nothing", const std::string name = "Object", const TCODColor foreground = TCODColor::white)
		: _tile(tile), _fg(foreground), _bg(TCODColor::black), _name(name) {}
	~RenderComponent() {}

	void update(PositionComponent pos) const
	{
		TCODConsole::root->putCharEx(pos._x, pos._y, data._tiles[_tile], _fg, _bg);
	}

	void update(PositionComponent& pos, PositionComponent& mod) const
	{
		TCODConsole::root->putCharEx(pos._x + mod._x, pos._y + mod._y, data._tiles[_tile], _fg, _bg);
	}

	std::string _tile;
	TCODColor _fg;
	TCODColor _bg;
	std::string _name;
};