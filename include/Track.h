#ifndef TRACK
#define TRACK

#include "FOTHgridObject.h"
#include "FOTHUtility.h"
#include <vector>

/** Represents a single piece of track. Track pieces control the movement of the train. */
class Track : public FOTHgridObject {

public:
	Track(sf::Texture* a_trackGraphic, FOTH::dir a_endDirA, FOTH::dir b_endDirB, GridSpace* a_parentGridSpace);
	void interactWithTrain(/*train*/);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	void orientSprite();
	static bool isTrackAtGsu(int x, int y);
	FOTH::dir getEndDirA();
	FOTH::dir getEndDirB();
	void setEndDirs( FOTH::dir a_endDirA, FOTH::dir a_endDirB );

private:
	/** End directions determine the orientation of the track and the corresponding sprite */
	FOTH::dir endDirB;
	FOTH::dir endDirA;
	static std::vector<sf::Vector2i> trackGridSpaces;
	bool isNeighborTrack(int a_xGridPosOffset, int a_yGridPosOffset);
	sf::Vector2i drawOffsets;

};

#endif
