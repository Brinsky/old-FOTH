#include "Train.h"

Train::Train( sf::Vector2f a_startGridPosition, Dir a_startDir )
{
	position = a_startGridPosition;
	currentDir = a_startDir;
}

void Train::changeDir( Dir a_newDir )
{
	currentDir = a_newDir;
}
