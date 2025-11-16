#include "GamePlayer.h"
#include "Team.h"
#include "Game.h"
#include "GamePlayerStates.h"
#include "TrivialLogger.h"

GamePlayer::GamePlayer(int id, double x, double y, sf::Color color, Team* team) : team(team) {
    log(LogLevel::INFO, "GamePlayer::GamePlayer - creating player " + std::to_string(id));

    this->id = id;
    centroid = Vector2D{ x, y };

    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));

    state_machine = new StateMachine(this);

    state_machine->set_current_state(Idle::instance());
}

void GamePlayer::execute_logic() {


    state_machine->update();

    //double distance = centroid.distance(target);

    //if (distance > 20) {

    //    //TODO: redo with one liner
    //    Vector2D desired_velocity = (target - centroid);
    //    desired_velocity.normalize();
    //    desired_velocity *= max_speed;

    //    speed_vector = desired_velocity;

    //} else {
    //    speed_vector = Vector2D{ 0,0 };

    //    const double PUCK_STRIKE_FORCE = 200.;
    //    strike_puck(team->game->puck, team->their_goals->centroid, PUCK_STRIKE_FORCE);
    //}
}

void GamePlayer::update(const double& dt) {
    centroid += speed_vector * dt;

}

void GamePlayer::draw(sf::RenderWindow& window) {
    shape.setPosition(sf::Vector2f(centroid.x, centroid.y)); //setOrigin?
    window.draw(shape);
}

void GamePlayer::strike_puck(Vector2D& target, double speed) {
    Puck& puck = team->game->puck;

    if (can_reach_puck()) {
        puck.send_towards(target, speed);
    }
}

void GamePlayer::handle_message(const Telegram& telegram) {
    
    if (telegram.msg_id == 1) {
        //std::cout << "Player " << id << "GOT THE MESSAGE" << std::endl;

        state_machine->change_state(ChasePuck::instance());
    }
}

bool GamePlayer::can_reach_puck() {
    Puck& puck = team->game->puck;

    double distance = centroid.distance(puck.centroid);

    return distance < 20;
}