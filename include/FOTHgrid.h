#ifndef FOTH_GRID
#define FOTH_GRID

#include "Grid.h"

class FOTHgrid : public Grid {

public:
	FOTHgrid(int a_length, sf::Texture* a_FOTHdefaultTexture);
	void scroll( sf::Time  a_tickTime, float scrollSpeed /*In GridSpace units per second*/ );

};

#endif

