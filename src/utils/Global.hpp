#pragma once
#include <libtcod/libtcod.hpp>

extern TCODRandom rng;
extern TCOD_key_t key;
extern float time;

static const int MIN_ROOM_SIZE = 2 + 2;
static const int MAX_ROOM_SIZE = 7 + 2;
static const int DISTANCE_BORDERS = 4;