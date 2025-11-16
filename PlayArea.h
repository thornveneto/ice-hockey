#pragma once
#include "RectangleRegion.h"
#include <SFML/Graphics.hpp>
#include <array> // For std::array

class PlayArea {
public:
	const double width{ 500. };
	const double height{ 300. };

private:
	sf::RectangleShape ice_rink{ sf::Vector2f(width, height) };
	sf::RectangleShape a_team_goal_scoring_area_visual;
	sf::RectangleShape b_team_goal_scoring_area_visual;

	std::array<sf::Vertex, 2> center_line = {
		sf::Vertex{sf::Vector2f(width/2, 0.f), sf::Color::Red},
		sf::Vertex{sf::Vector2f(width / 2, height), sf::Color::Red}
	};

public:
	RectangleRegion a_team_goal_scoring_area{ 1, 50., 150., 50., 100. };
	RectangleRegion b_team_goal_scoring_area{ 2, 450., 150., 50., 100. };

	PlayArea() {
		ice_rink.setFillColor(sf::Color::White);
		ice_rink.setPosition(sf::Vector2f(0.f, 0.f));

		a_team_goal_scoring_area_visual.setFillColor(sf::Color::Blue);
		a_team_goal_scoring_area_visual.setSize(
			sf::Vector2f{ static_cast<float>(a_team_goal_scoring_area.width), static_cast<float>(a_team_goal_scoring_area.height) }
		);
		a_team_goal_scoring_area_visual.setOrigin(sf::Vector2f(a_team_goal_scoring_area_visual.getSize().x / 2, a_team_goal_scoring_area_visual.getSize().y / 2));
		a_team_goal_scoring_area_visual.setPosition(
			sf::Vector2f{ static_cast<float>(a_team_goal_scoring_area.centroid.x), static_cast<float>(a_team_goal_scoring_area.centroid.y) }
		);

		b_team_goal_scoring_area_visual.setFillColor(sf::Color::Red);
		b_team_goal_scoring_area_visual.setSize(
			sf::Vector2f{ static_cast<float>(b_team_goal_scoring_area.width), static_cast<float>(b_team_goal_scoring_area.height) }
		);
		b_team_goal_scoring_area_visual.setOrigin(sf::Vector2f(b_team_goal_scoring_area_visual.getSize().x / 2, b_team_goal_scoring_area_visual.getSize().y / 2));
		b_team_goal_scoring_area_visual.setPosition(
			sf::Vector2f{ static_cast<float>(b_team_goal_scoring_area.centroid.x), static_cast<float>(b_team_goal_scoring_area.centroid.y) }
		);
	}

	void draw(sf::RenderWindow& window) {

		window.draw(ice_rink);
		window.draw(center_line.data(), center_line.size(), sf::PrimitiveType::Lines);
		window.draw(a_team_goal_scoring_area_visual);
		window.draw(b_team_goal_scoring_area_visual);
	}
};