#include "FOTHgrid.h"

FOTHgrid::FOTHgrid(int a_length, sf::Texture* a_FOTHdefaultTexture) : Grid(0, (10 - a_length) * 64, 7, a_length, 64, 64, a_FOTHdefaultTexture) {
}

void FOTHgrid::scroll(sf::Time a_tickTime, float scrollSpeed){

	moveGridPosition( 0, a_tickTime.asSeconds() * scrollSpeed ); //Scroll speed is negated for proper direction
}
