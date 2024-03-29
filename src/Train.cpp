#include "Train.h"
#include <cmath>

Train::Train( sf::Texture* a_trainTexture, sf::Vector2f a_startGridPosition, FOTH::dir a_startDir, Grid* a_parentGrid )
{
	sprite.setTexture(*a_trainTexture);

	position = a_startGridPosition;
	currentDir = a_startDir;

	parentGrid = a_parentGrid;

	speed = 2; //Speed in GridSpace units per second
}

void Train::changeDir( FOTH::dir a_newDir )
{
	currentDir = a_newDir;
}

void Train::tick( sf::Time a_tickTime )
{
	switch (currentDir)
	{
		case FOTH::North:
			position.y -= speed * a_tickTime.asSeconds();
			break;
		case FOTH::West:
			position.x -= speed * a_tickTime.asSeconds();
			break;
		case FOTH::South:
			position.y += speed * a_tickTime.asSeconds();
			break;
		case FOTH::East:
			position.x += speed * a_tickTime.asSeconds();
			break;
		default:
			break;
	}
}

void Train::draw( sf::RenderTarget& a_target, sf::RenderStates a_states )
{
	sprite.setPosition(
		(position.x * parentGrid->getGridSpaceDimPxl().x) + parentGrid->getGridPosPxl().x,
		(position.y * parentGrid->getGridSpaceDimPxl().y) + parentGrid->getGridPosPxl().y);

	a_target.draw(sprite, a_states);
}

/** Finds the upcoming (from the Train's perspective) edge between two GridSpaces **/
int Train::nextGridSpaceEdge( FOTH::dir a_dir )
{
	int edgeCoordGsu = -1;

	switch (a_dir)
	{
		case FOTH::North:
			edgeCoordGsu = std::floor(position.y);
			break;
		case FOTH::West:
			edgeCoordGsu = std::floor(position.x);
			break;
		case FOTH::South:
			edgeCoordGsu = std::ceil(position.y);
			break;
		case FOTH::East:
			edgeCoordGsu = std::ceil(position.y);
			break;
		default:
			break;
	}

	return edgeCoordGsu;
}
