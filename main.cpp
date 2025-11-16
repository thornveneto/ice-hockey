#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2D.h"
#include "GamePlayer.h"
#include "Game.h"
#include "Puck.h"
#include <iomanip>
#include "TrivialLogger.h"

int main()
{
    CURRENT_LOG_LEVEL = LogLevel::INFO;
    Game game;

    game.init();
    game.run_game_loop();
}