#pragma once
#include "Global.h"
#include"GameState.h"

class Game
{
private: 
	sf::RenderWindow* window; 
	sf::Event event; 
	sf::Clock dtclock; 
	float dt; 
	std::stack<State*> states; // will manage game state main menu state and other things 

	void initwindow(); 
	void initStates(); 
	void initfont(); 
	void pollEvent(); 
public: 
	Game(); 
	~Game(); 

	const bool isGameRunning() const; 
	void updateDt(); 
	void update(); 
	void render(); 
};

