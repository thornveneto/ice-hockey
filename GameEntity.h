#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"

class Telegram;

class GameEntity {	
public:
	int id;
	Vector2D speed_vector{ 0,0 };
	Vector2D centroid;

	virtual void draw(sf::RenderWindow& window)=0;
	virtual void update(const double& dt)=0;
	virtual void execute_logic()=0;
	virtual void handle_message(const Telegram& telegram) = 0;
	virtual ~GameEntity() {}
};