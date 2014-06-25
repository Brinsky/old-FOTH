#ifndef TRAIN
#define TRAIN

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "FOTHUtility.h"

/* A train which moves down a track */
class Train
{
	public:
	Train( sf::Texture* a_trainTexture, sf::Vector2f a_startGridPosition, FOTH::dir a_startDir, Grid* a_parentGrid );
	void changeDir( FOTH::dir a_newDir );
	void tick( sf::Time a_tickTime );
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);


	private:
	sf::Vector2f position; //Position in GridSpaces
	FOTH::dir currentDir;
	Grid* parentGrid;
	float speed;
	sf::Sprite sprite;
	int nextGridSpaceEdge( FOTH::dir a_dir ); //Returns GSU
};

#endif
