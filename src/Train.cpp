#include "Train.h"

Train::Train( sf::Texture* a_trainTexture, sf::Vector2f a_startGridPosition, dir a_startDir, Grid* a_parentGrid )
{
	sprite.setTexture(*a_trainTexture);

	position = a_startGridPosition;
	currentDir = a_startDir;

	parentGrid = a_parentGrid;

	speed = 0.25;
}

void Train::changeDir( dir a_newDir )
{
	currentDir = a_newDir;
}

void Train::tick()
{
	switch (currentDir)
	{
		case North:
			position.y += speed;
			break;
		case West:
			position.x -= speed;
			break;
		case South:
			position.y -= speed;
			break;
		case East:
			position.x += speed;
			break;
		default:
			break;
	}
}

void Train::draw( sf::RenderTarget& a_target, sf::RenderStates a_states )
{
	sprite.setPosition(
		(position.x * parentGrid->getGridSpaceDimensions().x) + parentGrid->getGridPosition().x,
		(position.y * parentGrid->getGridSpaceDimensions().y) + parentGrid->getGridPosition().y);

	a_target.draw(sprite, a_states);
} 
