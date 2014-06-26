#include "TrackLayer.h"
#include <iostream>

TrackLayer::TrackLayer( int a_posGsuX, int a_posGsuY, FOTHgrid* a_parentGrid )
{
	posGsu.x = a_posGsuX;
	posGsu.y = a_posGsuY;

	parentGrid = a_parentGrid;

	layerMode = Place;

	// Place an initial North/South piece of track
	placeTrack( FOTH::South, FOTH::North );
}

bool TrackLayer::shiftAndAct( FOTH::dir a_dir )
{
	if( move(a_dir) )
	{
		switch (layerMode)
		{
			case Place:
				// Places properly oriented track
				placeTrack( FOTH::getOppositeDir(a_dir), a_dir );
				break;
			case Remove:
				removeTrack();
				break;
			default:
				break;
		}
		return true;
	}
	else
	{
		return false;
	}
}

/** Note: Direction values are interchangeable */
bool TrackLayer::placeTrack( FOTH::dir a_endDirA, FOTH::dir a_endDirB )
{
	return parentGrid->addTrackAtGsu(posGsu.x, posGsu.y, a_endDirA, a_endDirB);
}

bool TrackLayer::move( FOTH::dir a_dir )
{
	sf::Vector2i newPosGsu( 0, 0 );

	// Determine how to change coordinates to move correctly
	switch( a_dir )
	{
		case FOTH::North:
			newPosGsu.x = 0;
			newPosGsu.y = -1;
			break;
		case FOTH::West:
			newPosGsu.x = -1;
			newPosGsu.y = 0;
			break;
		case FOTH::South:
			newPosGsu.x = 0;
			newPosGsu.y = 1;
			break;
		case FOTH::East:
			newPosGsu.x = 1;
			newPosGsu.y = 0;
			break;
		default:
			break;
	}

	//Check for validity of position and move
	if( parentGrid->isWithinGrid(posGsu.x + newPosGsu.x,
		posGsu.y + newPosGsu.y) )
	{
		// If there was a Track piece at the "previous" position, redirect it
		if( (layerMode == Place) )//&& (Track::isTrackAtGsu(posGsu.x, posGsu.y)) )
		{
		    // Overwrite previous Track piece
		    parentGrid->addTrackAtGsu(posGsu.x, posGsu.y, FOTH::getOppositeDir(a_dir), a_dir);
		}

		posGsu.y += newPosGsu.y;
		posGsu.x += newPosGsu.x;

		return true;
	}
	else
	{
		return false;
	}
}

bool TrackLayer::removeTrack()
{
    return parentGrid->removeTrackAtGsu(posGsu.x, posGsu.y);
}
