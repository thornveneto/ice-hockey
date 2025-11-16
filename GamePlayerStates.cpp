#include "GamePlayerStates.h"
#include "GamePlayer.h"
#include "Team.h"
#include "Game.h"

/*
	Chasing Puck States
*/

ChasePuck* ChasePuck::instance() {
	static ChasePuck static_instance;

	return &static_instance;
}

void ChasePuck::enter(GamePlayer* game_player) {
}

void ChasePuck::execute(GamePlayer* game_player) {
	Puck* puck = &game_player->team->game->puck;

    //double distance = game_player->centroid.distance(puck->centroid);

	if (!game_player->can_reach_puck()) {

		//TODO: redo with one liner
		Vector2D desired_velocity = (puck->centroid - game_player->centroid);
		desired_velocity.normalize();
		desired_velocity *= game_player->max_speed;

		game_player->speed_vector = desired_velocity;

	} else {
		game_player->state_machine->change_state(DrivePuckUpfield::instance());
		//game_player->speed_vector = Vector2D{ 0,0 };

		//const double PUCK_STRIKE_FORCE = 200.;
		//game_player->strike_puck(game_player->team->game->puck, game_player->team->their_goals->centroid, PUCK_STRIKE_FORCE);
	}

}

void ChasePuck::exit(GamePlayer* game_player) {
}

/*
	Idle state, mostly not to rush into action

*/
Idle* Idle::instance() {
	static Idle static_instance;

	return &static_instance;
}

void Idle::enter(GamePlayer* game_player) {
}

void Idle::execute(GamePlayer* game_player) {

	game_player->speed_vector = Vector2D{ 0,0 };
}

void Idle::exit(GamePlayer* game_player) {
}

/*
	Driving Puck Upfield

*/
DrivePuckUpfield* DrivePuckUpfield::instance() {
	static DrivePuckUpfield static_instance;

	return &static_instance;
}

void DrivePuckUpfield::enter(GamePlayer* game_player) {
}

void DrivePuckUpfield::execute(GamePlayer* game_player) {

	Region* their_goals = game_player->team->their_goals;

	double distance = game_player->centroid.distance(their_goals->centroid);

	if (distance > 20 && game_player->can_reach_puck()) {
		Vector2D desired_velocity = (their_goals->centroid - game_player->centroid);
		desired_velocity.normalize();
		desired_velocity *= game_player->max_speed;

		game_player->speed_vector = desired_velocity;

		game_player->team->game->puck.send_towards(their_goals->centroid, game_player->max_speed);
	} else {
		game_player->speed_vector = Vector2D{ 0,0 };

		//const double PUCK_STRIKE_FORCE = 200.;
		//game_player->strike_puck(game_player->team->game->puck, game_player->team->their_goals->centroid, PUCK_STRIKE_FORCE);
	}



}

void DrivePuckUpfield::exit(GamePlayer* game_player) {
}
