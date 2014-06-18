#ifndef GRID
#define GRID

#include <SFML/Graphics.hpp>

class GridSpace;

class Grid {

public:
	Grid(float a_gridPositionX, float a_gridPositionY, int a_gridDimensionsWidth, int a_gridDimLengthLength, int a_gridSpaceDimensionsWidth, int a_gridSpaceDimensionsLength, sf::Texture* a_defaultSpaceTexture);
	Grid(sf::Vector2f a_gridPosition, sf::Vector2i a_gridDimensions, sf::Vector2i a_gridSpaceDimensions, sf::Texture* a_defaultSpaceTexture);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setGridPosition(float a_positionX, float a_positionY);
	void setGridPosition(sf::Vector2f a_position);
	void moveGridPosition(float a_offsetX, float a_offsetY); //In GridSpace units!
	void moveGridPosition(sf::Vector2f a_offset); //In GridSpace units!
	sf::Vector2f getGridPosition();
	sf::Vector2i getGridDimensions();
	sf::Vector2i getGridSpaceDimensions();
	sf::Vector2i getGridSpaceContaining(int x, int y);	

protected:
	GridSpace*** grid;
	sf::Vector2f gridPosition;
	sf::Vector2i gridDimensions;
	sf::Vector2i gridSpaceDimensions;

};

#endif
