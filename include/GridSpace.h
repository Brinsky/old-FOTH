#ifndef GRIDSPACE
#define GRIDSPACE

#include <SFML/Graphics.hpp>

class Grid;
class GridObject;

class GridSpace {

public:
	GridSpace(int a_gridSpacePositionX, int a_gridSpacePositionY, sf::Texture* a_spaceTexture, Grid* a_parentGrid);
	GridSpace(sf::Vector2i a_gridSpacePosition, sf::Texture* a_spaceTexture, Grid* a_parentGrid);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setGridObject(GridObject* a_object);
	sf::Vector2i getGridSpacePosition();
	sf::Vector2i getGridSpaceDimensions();

protected:
	Grid* parentGrid;
	GridObject* object;
	sf::Sprite background;
	sf::Vector2i gridSpacePosition;

};

#endif
