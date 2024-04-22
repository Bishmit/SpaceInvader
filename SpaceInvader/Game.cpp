#include "Game.h"

void Game::initwindow()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Space Invader"); 
	window->setFramerateLimit(60); 
}

void Game::initStates()
{
	this->states.push(new GameState(this->window)); 
}

void Game::initfont()
{

}

void Game::pollEvent()
{
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			window->close(); 
		}
	}
}

Game::Game()
{
	initwindow(); 
	initStates(); 
	
}

Game::~Game()
{
	delete this->window; 

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop(); 
	}
}

const bool Game::isGameRunning() const
{
	return window->isOpen(); 	
}

void Game::updateDt()
{
	// dt variable will be updated with the time it takes to update and render onr frame
	this->dt = this->dtclock.restart().asSeconds(); 

}

void Game::update()
{
	pollEvent(); 
	updateDt(); 
	if (!this->states.empty())
		this->states.top()->update(this->dt);
}

void Game::render()
{
	window->clear(); 
	// render the state of game 
	if (!this->states.empty())
		this->states.top()->render(this->window); 

	window->display(); 
}
