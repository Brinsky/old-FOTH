#include "Train.h"

Train::Train( sf::Texture* a_trainTexture, sf::Vector2f a_startGridPosition, dir a_startDir, Grid* a_parentGrid )
{
	sprite.setTexture(*a_trainTexture);

	position = a_startGridPosition;
	currentDir = a_startDir;

	parentGrid = a_parentGrid;

	speed = 2; //Speed in GridSpace units per second
}

void Train::changeDir( dir a_newDir )
{
	currentDir = a_newDir;
}

void Train::tick( sf::Time a_tickTime )
{
	switch (currentDir)
	{
		case North:
			position.y -= speed * a_tickTime.asSeconds();
			break;
		case West:
			position.x -= speed * a_tickTime.asSeconds();
			break;
		case South:
			position.y += speed * a_tickTime.asSeconds();
			break;
		case East:
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
