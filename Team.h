#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Region.h"
#include "Vector2D.h"

class Game;
class GamePlayer;

class Team {
private:
	sf::Color team_color;

public:
	Game* game;
	std::vector<std::unique_ptr<GamePlayer>> players;
	Region* our_goals;
	Region* their_goals;

	Team(
		Game* game,
		sf::Color team_color,
		std::vector<std::pair<double, double>>& init_players,
		Region* our_goals,
		Region* their_goals
	);

	void update(const float delta_seconds);

	void draw(sf::RenderWindow& window);

	void execute_logic();

	void assign_tasks();

	GamePlayer* nearest_player(Vector2D* point);
};