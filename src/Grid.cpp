#include "Grid.h"
#include "GridSpace.h"

Grid::Grid(float a_gridPosPxlX, float a_gridPosPxlY, int a_gridDimGsuWidth, int a_gridDimGsuLength, int a_gridSpaceDimPxlWidth, int a_gridSpaceDimPxlLength, sf::Texture* a_defaultSpaceTexture){

	gridPosPxl.x = a_gridPosPxlX;
	gridPosPxl.y = a_gridPosPxlY;

	gridDimGsu.x = a_gridDimGsuWidth;
	gridDimGsu.y = a_gridDimGsuLength;

	gridSpaceDimPxl.x = a_gridSpaceDimPxlWidth;
	gridSpaceDimPxl.y = a_gridSpaceDimPxlLength;

	grid = new GridSpace**[gridDimGsu.x];

	for(int i = 0; i < gridDimGsu.x; i++){

		grid[i] = new GridSpace*[gridDimGsu.y];

	}

	for(int i = 0; i < gridDimGsu.x; i++){

		for(int j = 0; j < gridDimGsu.y; j++){

			grid[i][j] = new GridSpace(i, j, a_defaultSpaceTexture, this);

		}

	}

}

Grid::Grid(sf::Vector2f a_gridPosPxl, sf::Vector2i a_gridDimGsu, sf::Vector2i a_gridSpaceDimPxl, sf::Texture* a_defaultSpaceTexture){

	gridPosPxl = a_gridPosPxl;

	gridDimGsu = a_gridDimGsu;

	gridSpaceDimPxl = a_gridSpaceDimPxl;

	grid = new GridSpace**[gridDimGsu.x];

	for(int i = 0; i < gridDimGsu.x; i++){

		grid[i] = new GridSpace*[gridDimGsu.y];

	}

	for(int i = 0; i < gridDimGsu.x; i++){

		for(int j = 0; j < gridDimGsu.y; j++){

			grid[i][j] = new GridSpace(i, j, a_defaultSpaceTexture, this);

		}

	}

}

void Grid::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	for(int i = 0; i < gridDimGsu.x; i++){

		for(int j = 0; j < gridDimGsu.y; j++){

			grid[i][j]->draw(a_target, a_states);

		}

	}

}

void Grid::setGridPosPxl(float a_positionX, float a_positionY){

	gridPosPxl.x = a_positionX;
	gridPosPxl.y = a_positionY;

}

void Grid::setGridPosPxl(sf::Vector2f a_position){

	gridPosPxl = a_position;

}

void Grid::moveGridPosGsu(float a_offsetX, float a_offsetY){

	moveGridPosGsu( sf::Vector2f( a_offsetX, a_offsetY ) );

}

void Grid::moveGridPosGsu(sf::Vector2f a_offset){

	gridPosPxl.x += (a_offset.x * gridSpaceDimPxl.x);
	gridPosPxl.y += (a_offset.y * gridSpaceDimPxl.y);

}

sf::Vector2f Grid::getGridPosPxl(){

	return gridPosPxl;

}

sf::Vector2i Grid::getGridDimGsu(){

	return gridDimGsu;

}

sf::Vector2i Grid::getGridSpaceDimPxl(){

	return gridSpaceDimPxl;

}

GridSpace* Grid::getGridSpaceContaining(int x, int y){

	for(int i = 0; i < gridDimGsu.x; i++){

		for(int j = 0; j < gridDimGsu.y; j++){

			if(grid[i][j]->containsPosPxl(x, y)){

				return grid[i][j];

			}

		}

	}

	return NULL;

}
