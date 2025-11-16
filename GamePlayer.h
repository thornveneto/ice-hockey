#pragma once
#include "Vector2D.h"
#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Puck.h"
#include "StateMachine.h"

class Team;

class GamePlayer : public GameEntity {
private:
    const double puck_reach_distance = 20.;

public:
    bool controlls_puck{ false };

    StateMachine* state_machine;

    Team* team;

    sf::CircleShape shape;
    double radius{ 10. };

    const double max_speed{ 100. };

    GamePlayer(int id, double x, double y, sf::Color color, Team* team);

    void execute_logic() override;
    void draw(sf::RenderWindow& window) override;
    void update(const double& dt) override;

    void handle_message(const Telegram& telegram) override;

    void strike_puck(Vector2D& target, double speed);

    bool can_reach_puck();

    ~GamePlayer() { delete state_machine; }
};