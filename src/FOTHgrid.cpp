#include "FOTHgrid.h"

FOTHgrid::FOTHgrid(int a_length, std::vector<sf::Texture*> a_gridObjectTextures) : Grid(0, (10 - a_length) * 64, 7, a_length, 64, 64, a_gridObjectTextures[0]) {

	gridObjectTextures = a_gridObjectTextures;

}

/** If possible, creates a Track at a specified GridSpace. Returns false otherwise */
bool FOTHgrid::addTrackAtGsu(int x, int y, FOTH::dir a_endDirA, FOTH::dir a_endDirB){

    // Check if GridSpace is valid
    if( isWithinGrid(x, y) )
    {
        // Make sure the GridSpace is empty
        if( grid[x][y]->getGridObject() == NULL )
        {
            // Add a new Track to the GridSpace
            grid[x][y]->setGridObject(new Track(gridObjectTextures[1], a_endDirA, a_endDirB, grid[x][y]));
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/** If possible, removes a Track at a specified GridSpace. Returns false otherwise */
bool FOTHgrid::removeTrackAtGsu(int x, int y){

    // Check if GridSpace is valid
    if( isWithinGrid(x, y) )
    {
        // Check if a Track exists within that GridSpace
        if( Track::isTrackAtGsu(x, y) )
        {
            // "Remove" the Track from the GridSpace
            grid[x][y]->setGridObject(NULL);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
