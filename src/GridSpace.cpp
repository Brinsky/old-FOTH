#include "GridSpace.h"
#include "Grid.h"
#include "GridObject.h"

GridSpace::GridSpace(int a_gridSpacePosGsuX, int a_gridSpacePosGsuY, sf::Texture* a_spaceTexture, Grid* a_parentGrid){

	parentGrid = a_parentGrid;
	object = NULL;

	background.setTexture(*a_spaceTexture);

	gridSpacePosGsu.x = a_gridSpacePosGsuX;
	gridSpacePosGsu.y = a_gridSpacePosGsuY;

}

GridSpace::GridSpace(sf::Vector2i a_gridSpacePosGsu, sf::Texture* a_spaceTexture, Grid* a_parentGrid){

	parentGrid = a_parentGrid;
	object = NULL;

	background.setTexture(*a_spaceTexture);

	gridSpacePosGsu = a_gridSpacePosGsu;

}

GridObject* GridSpace::getGridObject(){

	return object;

}

void GridSpace::setGridObject(GridObject* a_object){

	object = a_object;

}

sf::Vector2i GridSpace::getGridSpacePosGsu(){

	return gridSpacePosGsu;

}

sf::Vector2i GridSpace::getGridSpaceDimPxl(){

	return parentGrid->getGridSpaceDimPxl();

}

void GridSpace::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	background.setPosition(
	((gridSpacePosGsu.x * parentGrid->getGridSpaceDimPxl().x) + parentGrid->getGridPosPxl().x),
	((gridSpacePosGsu.y * parentGrid->getGridSpaceDimPxl().y) + parentGrid->getGridPosPxl().y));

	a_target.draw(background, a_states);

	if(object != NULL){

		object->draw(a_target, a_states);

	}

}

bool GridSpace::containsPosPxl(int x, int y){

	sf::Rect<int> gridSpaceBoundaries(background.getPosition().x, background.getPosition().y, parentGrid->getGridSpaceDimPxl().x, parentGrid->getGridSpaceDimPxl().y);

	return gridSpaceBoundaries.contains(x, y);

}

sf::Vector2f GridSpace::getGridPosPxl(){

	return parentGrid->getGridPosPxl();

}
