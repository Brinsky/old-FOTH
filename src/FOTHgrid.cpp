#include "FOTHgrid.h"

FOTHgrid::FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures) : Grid(0, (10 - a_length) * 64, 7, a_length, 64, 64, a_gridObjectTextures[0]) {

	gridObjectTextures = a_gridObjectTextures;

}

void FOTHgrid::scroll(sf::Time a_tickTime, float scrollSpeed){

	moveGridPosition( 0, a_tickTime.asSeconds() * scrollSpeed ); //Scroll speed is negated for proper direction

}

void FOTHgrid::addTrack(int x, int y){

	//grid[getGridSpaceContaining(x, y).x][getGridSpaceContaining(x, y).y]->setGridObject(new Track());

}
