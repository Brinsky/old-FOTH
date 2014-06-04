#ifndef TRAIN
#define TRAIN

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "GridObject.h"
#include "GridSpace.h"

//Define a type for directions
enum  Dir { north, south, east, west };

class Train
{
	public:
	Train( sf::Vector2f a_startGridPosition, Dir a_startDir );
	void changeDir( Dir a_newDir );
	void tick();
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);

	private:
	sf::Vector2f position; //Position in GridSpaces
	Dir currentDir;
	float speed;
};

#endif
