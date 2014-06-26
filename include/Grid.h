#ifndef GRID
#define GRID

#include <SFML/Graphics.hpp>

class GridSpace;

/** A structured grid containing and managing a two-dimensional array of GridSpaces */
class Grid {

public:
	Grid(float a_gridPosPxlX, float a_gridPosPxlY, int a_gridDimGsuWidth, int a_gridDimGsuLength, int a_gridSpaceDimPxlWidth, int a_gridSpaceDimPxlLength, sf::Texture* a_defaultSpaceTexture);
	Grid(sf::Vector2f a_gridPosPxl, sf::Vector2i a_gridDimGsu, sf::Vector2i a_gridSpaceDimPxl, sf::Texture* a_defaultSpaceTexture);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setGridPosPxl(float a_positionX, float a_positionY);
	void setGridPosPxl(sf::Vector2f a_position);
	void moveGridPosGsu(float a_offsetX, float a_offsetY); //In GridSpace units!
	void moveGridPosGsu(sf::Vector2f a_offset); //In GridSpace units!
	bool isWithinGrid( float posGsuX, float posGsuY );
	sf::Vector2f getGridPosPxl();
	sf::Vector2i getGridDimGsu();
	sf::Vector2i getGridSpaceDimPxl();

protected:
	GridSpace*** grid;
	GridSpace* getGridSpaceContaining(int PxlX, int PxlY);
	sf::Vector2f gridPosPxl;
	sf::Vector2i gridDimGsu;
	sf::Vector2i gridSpaceDimPxl;

};

#endif
