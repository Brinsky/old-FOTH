#ifndef FOTH_GRID
#define FOTH_GRID

#include <vector>
#include "Grid.h"
#include "Track.h"

/** Implementation specific subclass of Grid, manages textures and track placement */
class FOTHgrid : public Grid {

public:
	FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures);
	bool addTrackAtGsu(int x, int y);
	bool removeTrackAtGsu(int x, int y);

protected:
	std::vector<sf::Texture*> gridObjectTextures;

};

#endif

