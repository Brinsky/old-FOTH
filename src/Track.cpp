#include "Track.h"

std::vector<sf::Vector2i> Track::trackGridSpaces;

Track::Track(sf::Texture* a_trackGraphic, FOTH::dir a_endDirA, FOTH::dir a_endDirB, GridSpace* a_parentGridSpace) : FOTHgridObject(0, 0, a_trackGraphic, a_parentGridSpace)
{
	trackGridSpaces.push_back(parentGridSpace->getGridSpacePosGsu());
	endDirA = a_endDirA;
	endDirB = a_endDirB;

	drawOffsets.x = 0;
	drawOffsets.y = 0;

	orientSprite();
}

// This function needs to change, and possibly doesn't work properly at all
bool Track::isTrackAtGsu(int x, int y)
{
	for(int i = 0; i < trackGridSpaces.size(); i++){

		if(trackGridSpaces[i] == sf::Vector2i(x, y)){

			return true;

		}

	}

	return false;
}

bool Track::isNeighborTrack(int a_xGridPosOffset, int a_yGridPosOffset)
{
	for(int i = 0; i < trackGridSpaces.size(); i++){

		if(trackGridSpaces[i] == sf::Vector2i(parentGridSpace->getGridSpacePosGsu().x + a_xGridPosOffset, parentGridSpace->getGridSpacePosGsu().y + a_yGridPosOffset)){

			return true;

		}

	}

	return false;
}

void Track::interactWithTrain(/*train*/)
{

}

//** Run this whenever endDirs are updated to reorient Track sprites */
void Track::orientSprite()
{
	switch( endDirA )
	{
		case FOTH::North:
			switch( endDirB )
			{
				case FOTH::West:
					//4
					objectGraphic.setRotation(90);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 0;
					break;
				case FOTH::South:
					//1
					objectGraphic.setRotation(0);
					objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 0;	
					break;
				case FOTH::East:
					//3
					objectGraphic.setRotation(180);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 64;	
					break;
				default:
					break;
			}
			break;
		case FOTH::West:
			switch( endDirB )
			{
				case FOTH::North:
					//4
					objectGraphic.setRotation(90);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 0;
					break;
				case FOTH::South:
					//2
					objectGraphic.setRotation(0);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 0;
					break;
				case FOTH::East:
					//6
					objectGraphic.setRotation(90);
					objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 0;		
					break;
				default:
					break;
			}
			break;
		case FOTH::South:
			switch( endDirB )
			{
				case FOTH::North:
					//1
					objectGraphic.setRotation(0);
					objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 0;	
					break;
				case FOTH::West:
					//2
					objectGraphic.setRotation(0);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 0;		
					break;
				case FOTH::East:
					//5
					objectGraphic.setRotation(270);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 64;
					break;
				default:
					break;
			}
			break;
		case FOTH::East:
			switch( endDirB )
			{
				case FOTH::North:
					//3
					objectGraphic.setRotation(180);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 64;
					break;
				case FOTH::West:
					//6
					objectGraphic.setRotation(90);
					objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));
					drawOffsets.x = 64;
					drawOffsets.y = 0;		
					break;
				case FOTH::South:
					//5
					objectGraphic.setRotation(270);
					objectGraphic.setTextureRect(sf::IntRect(64, 0, 128, 64));
					drawOffsets.x = 0;
					drawOffsets.y = 64;
					break;
				default:
					break;
			}
			break;
		default:
			//1
			objectGraphic.setRotation(0);
			objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));
			drawOffsets.x = 0;
			drawOffsets.y = 0;
			break;
	}
}

void Track::draw(sf::RenderTarget& a_target, sf::RenderStates a_states)
{
	objectGraphic.setPosition((parentGridSpace->getGridSpaceDimPxl().x * (parentGridSpace->getGridSpacePosGsu().x + objectPosGsu.x)) + parentGridSpace->getGridPosPxl().x + drawOffsets.x, (parentGridSpace->getGridSpaceDimPxl().y * (parentGridSpace->getGridSpacePosGsu().y + objectPosGsu.y)) + parentGridSpace->getGridPosPxl().y + drawOffsets.y);

	a_target.draw(objectGraphic, a_states);
}

FOTH::dir Track::getEndDirA()
{
	return endDirA;
}

FOTH::dir Track::getEndDirB()
{
	return endDirB;
}

/** Note: EndDirs are interchangeable */
void Track::setEndDirs( FOTH::dir a_endDirA, FOTH::dir a_endDirB )
{
	endDirA = a_endDirA;
	endDirB = a_endDirB;

	// Must reorient sprites
	orientSprite();
}
