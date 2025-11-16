#pragma once
#include "GameEntity.h"

class Puck : public GameEntity {
public:
    sf::CircleShape shape;
    double radius{ 5. };

    Puck(int id, double x, double y) {
        this->id = id;
        centroid = Vector2D{ x, y };        

        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Black);
        shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));
    }

    void send_towards(Vector2D& target,double speed);

    void execute_logic() override;
    void draw(sf::RenderWindow& window) override;
    void update(const double& dt) override;
    void handle_message(const Telegram& telegram) override;
};