#include "Team.h"
#include "Region.h"
#include "GamePlayer.h"
#include "Vector2D.h"
#include "Game.h"
#include <limits> // Required for std::numeric_limits
#include "GamePlayerStates.h"

Team::Team(
	Game* game,
	sf::Color team_color,
	std::vector<std::pair<double, double>>& init_players,
	Region* our_goals,
	Region* their_goals
) : game(game), team_color(team_color), our_goals(our_goals), their_goals(their_goals)
{
	//TODO: use some struct
	for (const auto& player : init_players) {
				
		players.push_back(std::make_unique<GamePlayer>(
			game->entity_manager.allocate_id(),
			player.first, player.second, team_color, this)
		);

		GamePlayer* player = players.back().get();

		game->entity_manager.register_entity(player);
	}
}

void Team::update(const float delta_seconds) {
	for (const auto& player : players) {
		player->update(delta_seconds);
	}
}

void Team::draw(sf::RenderWindow& window) {
	for (const auto& player : players) {
		player->draw(window);
	}
}

void Team::assign_tasks() {
	GamePlayer* player_near_puck = nearest_player(&game->puck.centroid);

	if (player_near_puck
		&& !player_near_puck->state_machine->is_in_state<ChasePuck>()
		&& !player_near_puck->state_machine->is_in_state<DrivePuckUpfield>()
	) {
		game->message_dispatcher.dispatch(Telegram{ -1, player_near_puck->id, 1 });
	}
}

void Team::execute_logic() {
	assign_tasks();

	for (const auto& player : players) {
		player->execute_logic();
	}
}

GamePlayer* Team::nearest_player(Vector2D* point) {

	GamePlayer* result = nullptr;

	double min_distance = std::numeric_limits<double>::max();

	for (const auto& player : players) {
		double d = player->centroid.distance(*point);
		if (d < min_distance) {
			min_distance = d;
			result = player.get();
		}
	}

	return result;
}