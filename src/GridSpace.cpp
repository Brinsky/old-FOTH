#include "GridSpace.h"
#include "Grid.h"
#include "GridObject.h"

GridSpace::GridSpace(int a_gridSpacePositionX, int a_gridSpacePositionY, sf::Texture* a_spaceTexture, Grid* a_parentGrid){ 

	parentGrid = a_parentGrid; 
	object = NULL; 
	
	background.setTexture(*a_spaceTexture); 
	
	gridSpacePosition.x = a_gridSpacePositionX; 
	gridSpacePosition.y = a_gridSpacePositionY;

}

GridSpace::GridSpace(sf::Vector2i a_gridSpacePosition, sf::Texture* a_spaceTexture, Grid* a_parentGrid){

	parentGrid = a_parentGrid;
	object = NULL;

	background.setTexture(*a_spaceTexture);

	gridSpacePosition = a_gridSpacePosition;

}

GridObject* GridSpace::getGridObject(){

	return object;

}

void GridSpace::setGridObject(GridObject* a_object){

	object = a_object;

}

sf::Vector2i GridSpace::getGridSpacePosition(){

	return gridSpacePosition;

}

sf::Vector2i GridSpace::getGridSpaceDimensions(){

	return parentGrid->getGridDimensions();

}

void GridSpace::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	background.setPosition(
	((gridSpacePosition.x * parentGrid->getGridSpaceDimensions().x) + parentGrid->getGridPosition().x),
	((gridSpacePosition.y * parentGrid->getGridSpaceDimensions().y) + parentGrid->getGridPosition().y));
	
	a_target.draw(background, a_states);
	
	
	if(object != NULL){

		object->draw(a_target, a_states);

	}

}

bool GridSpace::containsPixelCoordinates(int x, int y){

	sf::Rect<int> gridSpaceBoundaries(background.getPosition().x, background.getPosition().y, parentGrid->getGridSpaceDimensions().x, parentGrid->getGridSpaceDimensions().y);
	
	return gridSpaceBoundaries.contains(x, y);

}

