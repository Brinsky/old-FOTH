#include "GridObject.h"
#include "GridSpace.h"

GridObject::GridObject(float a_objectPositionX, float a_objectPositionY, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace){


	objectPosition.x = a_objectPositionX;
	objectPosition.y = a_objectPositionY;
	parentGridSpace = a_parentGridSpace;
	objectGraphic.setTexture(*a_objectGraphic);
	
}

GridObject::GridObject(sf::Vector2f a_objectPosition, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace){

	objectPosition = a_objectPosition;
	parentGridSpace = a_parentGridSpace;
	objectGraphic.setTexture(*a_objectGraphic);

}

void GridObject::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	objectGraphic.setPosition((objectPosition.x + parentGridSpace->getGridSpacePosition().x) * parentGridSpace->getGridSpaceDimensions().x, (objectPosition.y + parentGridSpace->getGridSpacePosition().y) * parentGridSpace->getGridSpaceDimensions().y);

	a_target.draw(objectGraphic, a_states);

}

void GridObject::setObjectPosition(float a_positionX, float a_positionY){

	objectPosition.x = a_positionX;
	objectPosition.y = a_positionY;

}

void GridObject::setObjectPosition(sf::Vector2f a_position){

	objectPosition = a_position;

}

sf::Vector2f GridObject::getObjectPosition(){

	return objectPosition;

}
