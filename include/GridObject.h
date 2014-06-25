#ifndef GRID_OBJECT
#define GRID_OBJECT

#include <SFML/Graphics.hpp>

class GridSpace;

class GridObject {

public:
	GridObject(float a_objectPosGsuX, float a_objectPosGsuY, sf::Texture* a_objectGraphic,  GridSpace* a_parentGridSpace);
	GridObject(sf::Vector2f a_objectPosGsu, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace);
	virtual	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setObjectPosGsu(float a_positionX, float a_positionY);
	void setObjectPosGsu(sf::Vector2f a_position);
	sf::Vector2f getObjectPosGsu();

protected:
	GridSpace* parentGridSpace;
	sf::Sprite objectGraphic;
	sf::Vector2f objectPosGsu;

};

#endif
