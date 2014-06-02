#include "Grid.h"
#include "GridSpace.h"

Grid::Grid(float a_gridPositionX, float a_gridPositionY, int a_gridDimensionsWidth, int a_gridDimensionsLength, int a_gridSpaceDimensionsWidth, int a_gridSpaceDimensionsLength, sf::Texture* a_defaultSpaceTexture){

	gridPosition.x = a_gridPositionX;
	gridPosition.y = a_gridPositionY;
	
	gridDimensions.x = a_gridDimensionsWidth;
	gridDimensions.y = a_gridDimensionsLength;
	
	gridSpaceDimensions.x = a_gridSpaceDimensionsWidth;
	gridSpaceDimensions.y = a_gridSpaceDimensionsLength;
	
	grid = new GridSpace**[gridDimensions.x];
	
	for(int i = 0; i < gridDimensions.x; i++){
	
		grid[i] = new GridSpace*[gridDimensions.y];
	
	}
	
	for(int i = 0; i < gridDimensions.x; i++){
	
		for(int j = 0; j < gridDimensions.y; j++){
		
			grid[i][j] = new GridSpace(i, j, a_defaultSpaceTexture, this);
		
		}
	
	}

}

Grid::Grid(sf::Vector2f a_gridPosition, sf::Vector2i a_gridDimensions, sf::Vector2i a_gridSpaceDimensions, sf::Texture* a_defaultSpaceTexture){

	gridPosition = a_gridPosition;
	
	gridDimensions = a_gridDimensions;
	
	gridSpaceDimensions = a_gridSpaceDimensions;
	
	grid = new GridSpace**[gridDimensions.x];
	
	for(int i = 0; i < gridDimensions.x; i++){
	
		grid[i] = new GridSpace*[gridDimensions.y];
	
	}
	
	for(int i = 0; i < gridDimensions.x; i++){
	
		for(int j = 0; j < gridDimensions.y; j++){
		
			grid[i][j] = new GridSpace(i, j, a_defaultSpaceTexture, this);
		
		}
	
	}

}

void Grid::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){
	
	for(int i = 0; i < gridDimensions.x; i++){
	
		for(int j = 0; j < gridDimensions.y; j++){
		
			grid[i][j]->draw(a_target, a_states);
		
		}
	
	}

}

void Grid::setGridPosition(float a_positionX, float a_positionY){

	gridPosition.x = a_positionX;
	gridPosition.y = a_positionY;

}

void Grid::setGridPosition(sf::Vector2f a_position){

	gridPosition = a_position;

}

void Grid::moveGridPosition(float a_offsetX, float a_offsetY){

	gridPosition.x += a_offsetX;
	gridPosition.y += a_offsetY;

}

void Grid::moveGridPosition(sf::Vector2f a_offset){

	gridPosition.x += a_offset.x;
	gridPosition.y += a_offset.y;

}

sf::Vector2f Grid::getGridPosition(){

	return gridPosition;

}

sf::Vector2i Grid::getGridDimensions(){
	
	return gridDimensions;

}

sf::Vector2i Grid::getGridSpaceDimensions(){

	return gridSpaceDimensions;

}
