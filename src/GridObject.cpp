#include "GridObject.h"
#include "GridSpace.h"

GridObject::GridObject(float a_objectPosGsuX, float a_objectPosGsuY, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace){


	objectPosGsu.x = a_objectPosGsuX;
	objectPosGsu.y = a_objectPosGsuY;
	parentGridSpace = a_parentGridSpace;
	objectGraphic.setTexture(*a_objectGraphic);

}

GridObject::GridObject(sf::Vector2f a_objectPosGsu, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace){

	objectPosGsu = a_objectPosGsu;
	parentGridSpace = a_parentGridSpace;
	objectGraphic.setTexture(*a_objectGraphic);

}

void GridObject::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	objectGraphic.setPosition(
	(parentGridSpace->getGridPosPxl().x + (parentGridSpace->getGridSpaceDimPxl().x * (parentGridSpace->getGridSpacePosGsu().x + objectPosGsu.x))),
	(parentGridSpace->getGridPosPxl().y + (parentGridSpace->getGridSpaceDimPxl().y * (parentGridSpace->getGridSpacePosGsu().y + objectPosGsu.y))));

	a_target.draw(objectGraphic, a_states);

}

void GridObject::setObjectPosGsu(float a_positionX, float a_positionY){

	objectPosGsu.x = a_positionX;
	objectPosGsu.y = a_positionY;

}

void GridObject::setObjectPosGsu(sf::Vector2f a_position){

	objectPosGsu = a_position;

}

sf::Vector2f GridObject::getObjectPosGsu(){

	return objectPosGsu;

}
