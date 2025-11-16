#include "Game.h"
#include "Puck.h"
#include "GamePlayer.h"
#include <SFML/Graphics.hpp>

Game::Game() :
    window(sf::VideoMode({ 550, 550 }), "ICE HOCKEY"),
    puck(0, 250.f, 150.f) //TODO: make it dependent on field size
{
}

void Game::add_object(GameEntity* gameObject) {//references don't  handle polymorphism well {
	//TODO: do we need this?
    //game_objects.push_back(gameObject);
}

void Game::update(const float delta_seconds) {
    puck.update(delta_seconds);

    team_a.update(delta_seconds);
    team_b.update(delta_seconds);
}

void Game::execute_logic() {

    team_a.execute_logic();
    team_b.execute_logic();
}

void Game::draw() {
    window.clear();

    play_area.draw(window);

    puck.draw(window);

    team_a.draw(window);
    team_b.draw(window);

    window.display();
}

Game::~Game() { //because we are adding pointers by calling new
    //for (auto ptr : game_objects) {
    //    delete ptr;
    //}
    //game_objects.clear(); // optional but good practice
}

void Game::init() {
    //game_objects.push_back(new GamePlayer(1, 0, 0, sf::Color::Green));
    //game_objects.push_back(new GamePlayer(2, 200, 100, sf::Color::Red));
}

void Game::run_game_loop() {

    sf::Clock clock; // For measuring elapsed time

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart(); // Get elapsed time since last frame

        if (clock_running) {

            
            float deltaSeconds = deltaTime.asSeconds();

            update(deltaSeconds);

            execute_logic();

            if (play_area.a_team_goal_scoring_area.inside(puck.centroid)) {
                std::cout << "PUCK IN A ZONE" << std::endl;
            }
            else if (play_area.b_team_goal_scoring_area.inside(puck.centroid)) {
                std::cout << "PUCK IN B ZONE" << std::endl;
            }

        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    clock_running = !clock_running;
                    //Vector2D click_radius_vector{ static_cast<double>(mouseButtonPressed->position.x), static_cast<double>(mouseButtonPressed->position.y) };

                    //GamePlayer* puck_hitter = dynamic_cast<GamePlayer*>(game_objects[0]); //TODO: super unsafe method
                    //const double PUCK_STRIKE_FORCE = 200.;
                    //puck_hitter->strike_puck(puck, click_radius_vector, PUCK_STRIKE_FORCE);
                }
            }
        }

        draw();
    }
}