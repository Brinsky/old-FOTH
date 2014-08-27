#include "TrackLayer.h" 
#include <iostream>

TrackLayer::TrackLayer(sf::Texture* a_layerTexture, sf::Texture* a_layerArrow, int a_posGsuX, int a_posGsuY, FOTHgrid* a_parentGrid )
{

    layerGraphic.setTexture(*a_layerTexture); 
	layerDirectionalArrow.setTexture(*a_layerArrow);

	posGsu.x = a_posGsuX;
	posGsu.y = a_posGsuY;

	parentGrid = a_parentGrid;

	prevTrack = NULL;

	// Required to orient the first piece of Track properly
	prevTrackBackDir = FOTH::South;

	// Place an initial North/South piece of track
	placeTrack( FOTH::North );
}

/* Dependent on mode; causes TrackLayer to move and
* potentially place track, remove track, or do nothing.
* Returns false if the movement is illegal.
*/

bool TrackLayer::moveAndPlace( FOTH::dir a_dir )
{
    sf::Vector2i posOffsetGsu( 0, 0 );

	// Determine how to change GSU coordinates to move in specified direction
	switch( a_dir )
	{
		case FOTH::North:
			posOffsetGsu.x = 0;
			posOffsetGsu.y = -1;
			break;
		case FOTH::West:
			posOffsetGsu.x = -1;
			posOffsetGsu.y = 0;
			break;
		case FOTH::South:
			posOffsetGsu.x = 0;
			posOffsetGsu.y = 1;
			break;
		case FOTH::East:
			posOffsetGsu.x = 1;
			posOffsetGsu.y = 0;
			break;
		default:
			break;
	}

    // GridSpace to be checked for validity (will be null if not within bounds)
    GridSpace* targetGridSpace = parentGrid->getGridSpaceAtGsu(posGsu.x + posOffsetGsu.x, posGsu.y + posOffsetGsu.y);

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
void TrackLayer::placeTrack(FOTH::dir a_frontDir)
{
    // All pieces placed by TrackLayer are intially straight
	Track* resultPiece = parentGrid->addTrackAtGsu(posGsu.x, posGsu.y, a_frontDir, FOTH::getOppositeDir(a_frontDir));

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
        prevTrackBackDir = FOTH::getOppositeDir(a_frontDir);
    }
}

void TrackLayer::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	if(parentGrid->getGridSpaceAtGsu(posGsu.x, posGsu.y - 1) != NULL && (parentGrid->getGridSpaceAtGsu(posGsu.x, posGsu.y - 1)->getGridObject() == NULL)){

		layerDirectionalArrow.setRotation(0);		
		layerDirectionalArrow.setPosition((posGsu.x * parentGrid->getGridSpaceDimPxl().x), ((posGsu.y - 1)  * parentGrid->getGridSpaceDimPxl().y));
		a_target.draw(layerDirectionalArrow, a_states);

	}

	if((parentGrid->getGridSpaceAtGsu(posGsu.x, posGsu.y + 1) != NULL) && (parentGrid->getGridSpaceAtGsu(posGsu.x, posGsu.y + 1)->getGridObject() == NULL)){
	
		layerDirectionalArrow.setRotation(180);
		layerDirectionalArrow.setPosition((posGsu.x * parentGrid->getGridSpaceDimPxl().x) + 64, ((posGsu.y + 1)  * parentGrid->getGridSpaceDimPxl().y) + 64);	
		a_target.draw(layerDirectionalArrow, a_states);

	}

	if((parentGrid->getGridSpaceAtGsu(posGsu.x + 1, posGsu.y) != NULL && (parentGrid->getGridSpaceAtGsu(posGsu.x + 1, posGsu.y)->getGridObject() == NULL))){

		layerDirectionalArrow.setRotation(90);	
		layerDirectionalArrow.setPosition(((posGsu.x + 1) * parentGrid->getGridSpaceDimPxl().x) + 64, (posGsu.y  * parentGrid->getGridSpaceDimPxl().y));	
		a_target.draw(layerDirectionalArrow, a_states);

	}

	if((parentGrid->getGridSpaceAtGsu(posGsu.x - 1, posGsu.y) != NULL) && (parentGrid->getGridSpaceAtGsu(posGsu.x - 1, posGsu.y)->getGridObject() == NULL)){
	
		layerDirectionalArrow.setRotation(270);
		layerDirectionalArrow.setPosition(((posGsu.x - 1) * parentGrid->getGridSpaceDimPxl().x), (posGsu.y * parentGrid->getGridSpaceDimPxl().y) + 64);
		a_target.draw(layerDirectionalArrow, a_states);

	}

	layerGraphic.setPosition(posGsu.x * parentGrid->getGridSpaceDimPxl().x, posGsu.y * parentGrid->getGridSpaceDimPxl().y);
	a_target.draw(layerGraphic, a_states);

}
