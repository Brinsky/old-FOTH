#ifndef FOTH_GRID
#define FOTH_GRID

#include <vector>
#include "Grid.h"
#include "Track.h"
#include "FOTHUtility.h"

/** Implementation specific subclass of Grid, manages textures and track placement */
class FOTHgrid : public Grid {

public:
	FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures);
	Track* addTrackAtGsu(int x, int y, FOTH::dir a_endDirA, FOTH::dir a_endDirB);

protected:
	std::vector<sf::Texture*> gridObjectTextures;

};

#endif

