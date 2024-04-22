#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
#include<map>
#include<vector>
#include<SFML/Graphics.hpp>

class State
{
private:
	sf::RenderWindow* window; 
	std::vector<sf::Texture> textures; 

public:
	State(sf::RenderWindow* window); 
	virtual ~State(); 
	virtual void update(const float& dt) = 0; 
	virtual void render(sf::RenderTarget* target = nullptr) = 0; 
};

