#ifndef TRAIN
#define TRAIN

#include <SFML/Graphics.hpp>

#include "Grid.h"

class Train
{
	public:
	//Define an enumeration type for directions
	enum dir { North = 0, West = 1, South = 2, East = 3 };

	Train( sf::Texture* a_trainTexture, sf::Vector2f a_startGridPosition, dir a_startDir, Grid* a_parentGrid );
	void changeDir( dir a_newDir );
	void tick();
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);


	private:
	sf::Vector2f position; //Position in GridSpaces
	dir currentDir;
	Grid* parentGrid;
	float speed;
	sf::Sprite sprite;
};

#endif
