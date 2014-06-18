#ifndef FOTH_GRID
#define FOTH_GRID

#include <vector>
#include "Grid.h"
#include "Track.h"

class FOTHgrid : public Grid {

public:
	FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures);
	void scroll( sf::Time  a_tickTime, float scrollSpeed /*In GridSpace units per second*/ );
	void addTrack(int x, int y);

protected:
	std::vector<sf::Texture*> gridObjectTextures;

};

#endif

