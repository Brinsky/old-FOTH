#ifndef GRIDSPACE
#define GRIDSPACE

#include <SFML/Graphics.hpp>

class Grid;
class GridObject;

class GridSpace {

public:
	GridSpace(int a_gridSpacePosGsuX, int a_gridSpacePosGsuY, sf::Texture* a_spaceTexture, Grid* a_parentGrid);
	GridSpace(sf::Vector2i a_gridSpacePosGsu, sf::Texture* a_spaceTexture, Grid* a_parentGrid);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setGridObject(GridObject* a_object);
	GridObject* getGridObject();
	sf::Vector2i getGridSpacePosGsu();
	sf::Vector2i getGridSpaceDimPxl();
	bool containsPosPxl(int x, int y);
	sf::Vector2f getGridPosPxl();

protected:
	Grid* parentGrid;
	GridObject* object;
	sf::Sprite background;
	sf::Vector2i gridSpacePosGsu;

};

#endif
