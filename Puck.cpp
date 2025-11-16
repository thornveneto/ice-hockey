#include "Puck.h"
#include <iostream>

void Puck::execute_logic() {
    //if (target.x > shapeObject.x) directionVector.x = 1;
    //else if (target.x < shapeObject.x) directionVector.x = -1;
    //else directionVector.x = 0;

    //if (target.y > shapeObject.y) directionVector.y = 1;
    //else if (target.y < shapeObject.y) directionVector.y = -1;
    //else directionVector.y = 0;
}

void Puck::update(const double& delta_seconds) {
    centroid += speed_vector * delta_seconds;

    //TODO: interact with environment
    const double ICE_PUCK_DECREASE = 0.1;
    speed_vector *= (1 - delta_seconds * ICE_PUCK_DECREASE);
}

void Puck::draw(sf::RenderWindow& window) {
    shape.setPosition(sf::Vector2f(centroid.x, centroid.y)); //setOrigin?
    window.draw(shape);
}

void Puck::send_towards(Vector2D& target, double speed) {

    Vector2D desired_velocity = (target - centroid);
    desired_velocity.normalize();
    desired_velocity *= speed;

    speed_vector = desired_velocity;
}

void Puck::handle_message(const Telegram& telegram) {

}