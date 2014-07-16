#include "FOTHgrid.h"

FOTHgrid::FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures) : Grid(0, 0, 7, a_length, 64, 64, a_gridObjectTextures[0]) {

	gridObjectTextures = a_gridObjectTextures;

}

/** If possible, creates a Track at a specified GridSpace. Returns false otherwise */
Track* FOTHgrid::addTrackAtGsu(int x, int y, FOTH::dir a_endDirA, FOTH::dir a_endDirB){

    // Check if GridSpace is valid
    if( isWithinGrid(x, y) )
    {
        // Make sure the GridSpace is empty
        if( grid[x][y]->getGridObject() == NULL )
        {
            // Add a new Track to the GridSpace
            Track* newTrack = new Track(gridObjectTextures[1], a_endDirA, a_endDirB, grid[x][y]);
            grid[x][y]->setGridObject(newTrack);
            return newTrack;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
