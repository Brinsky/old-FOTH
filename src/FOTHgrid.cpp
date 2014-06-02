#include "FOTHgrid.h"

FOTHgrid::FOTHgrid(int a_length, sf::Texture* a_FOTHdefaultTexture) : Grid(0, (10 - a_length) * 64, 7, a_length, 64, 64, a_FOTHdefaultTexture) {
}

void FOTHgrid::scroll(int a_tick){

	moveGridPosition(0, a_tick);

}
