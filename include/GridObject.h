#ifndef GRIDOBJECT
#define GRIDOBJECT

#include <SFML/Graphics.hpp>

class GridSpace;

class GridObject {

public:
	GridObject(float a_objectPositionX, float a_objectPositionY, sf::Texture* a_objectGraphic,  GridSpace* a_parentGridSpace);
	GridObject(sf::Vector2f a_objectPosition, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void setObjectPosition(float a_positionX, float a_positionY);
	void setObjectPosition(sf::Vector2f a_position);
	sf::Vector2f getObjectPosition();
	
protected:
	GridSpace* parentGridSpace;
	sf::Sprite objectGraphic;
	sf::Vector2f objectPosition;

};

#endif
