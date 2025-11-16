#pragma once
#include <vector>
#include "Vector2D.h"
#include "GameEntity.h"
#include <SFML/Graphics.hpp>
#include "Puck.h"
#include "RectangleRegion.h"
#include "PlayArea.h"
#include "Team.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"

class Game {
public:
	Game();

	void add_object(GameEntity* gameObject); //references don't  handle polymorphism well

	void update(float delta_seconds);

	void draw();

	void execute_logic();

	void run_game_loop();

	void init();

	~Game();
	
	Puck puck;

	PlayArea play_area;

	EntityManager entity_manager;

	MessageDispatcher message_dispatcher{ &entity_manager };

private:
	//std::vector<GameEntity*> game_objects;
	std::vector<std::pair<double, double>> team_a_init = { {100,100}, /*{100,200},*/ {200,150}};
	std::vector<std::pair<double, double>> team_b_init = { /*{400,100}, {400,200}, {300, 150}*/};

	Team team_a{this, sf::Color::Green, team_a_init, &play_area.a_team_goal_scoring_area, &play_area.b_team_goal_scoring_area };
	Team team_b{this, sf::Color::Red, team_b_init, &play_area.b_team_goal_scoring_area, &play_area.a_team_goal_scoring_area };
	sf::RenderWindow window;	

	bool clock_running{ false };
};