#include "TrackLayer.h"
#include <iostream>

TrackLayer::TrackLayer( int a_posGsuX, int a_posGsuY, FOTHgrid* a_parentGrid )
{
	posGsu.x = a_posGsuX;
	posGsu.y = a_posGsuY;

	parentGrid = a_parentGrid;

	prevTrack = NULL;

	// Required to orient the first piece of Track properly
	prevTrackBackDir = foth::South;

	// Place an initial North/South piece of track
	placeTrack( foth::North );
}

/* Dependent on mode; causes TrackLayer to move and
* potentially place track, remove track, or do nothing.
* Returns false if the movement is illegal.
*/
bool TrackLayer::moveAndPlace( foth::dir a_dir )
{
    sf::Vector2i posOffsetGsu( 0, 0 );

	// Determine how to change GSU coordinates to move in specified direction
	switch( a_dir )
	{
		case foth::North:
			posOffsetGsu.x = 0;
			posOffsetGsu.y = -1;
			break;
		case foth::West:
			posOffsetGsu.x = -1;
			posOffsetGsu.y = 0;
			break;
		case foth::South:
			posOffsetGsu.x = 0;
			posOffsetGsu.y = 1;
			break;
		case foth::East:
			posOffsetGsu.x = 1;
			posOffsetGsu.y = 0;
			break;
		default:
			break;
	}

    // GridSpace to be checked for validity (will be null if not within bounds)
    GridSpace* targetGridSpace = parentGrid->getGridSpaceAtGsu(posGsu.x + posOffsetGsu.x,
            posGsu.y + posOffsetGsu.y);

	// Check for validity of position and move
	// Critera: is a valid position within the Grid and contains no Track
	if( (targetGridSpace != NULL) && (targetGridSpace->getGridObject() == NULL) )
	{
		posGsu.y += posOffsetGsu.y;
		posGsu.x += posOffsetGsu.x;

		placeTrack(a_dir);

		return true;
	}
	else
	{
		return false;
	}
}

/* Handles placing a new Track alongside orienting the new Track and the
* segment of Track behind/before it.
* a_frontDir is the direction value that the TrackLayer is currently moving in
*/
void TrackLayer::placeTrack(foth::dir a_frontDir)
{
    // All pieces placed by TrackLayer are intially straight
	Track* resultPiece = parentGrid->addTrackAtGsu(posGsu.x, posGsu.y, a_frontDir, foth::getOppositeDir(a_frontDir));

	if( resultPiece != NULL )
    {
        // Case only applies to first use of placeTrack
        if( prevTrack != NULL)
        {
            // Because a new piece has been created, the directions on the previous
            // piece need to be recalculated (by overwriting). The method below
            // preserves that piece's "backDir" while giving it a new "frontDir"
            prevTrack->setEndDirs(a_frontDir, prevTrackBackDir);
        }

        // After updating the previous piece, the new piece becomes the previous piece
        prevTrack = resultPiece;
        // And the new backDir becomes the previous backDir
        prevTrackBackDir = foth::getOppositeDir(a_frontDir);
    }
}
