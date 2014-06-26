#ifndef TRACK
#define TRACK

#include "FOTHgridObject.h"
#include <vector>

/** Represents a single piece of track. Track pieces control the movement of the train. */
class Track : public FOTHgridObject {

public:
	Track(sf::Texture* a_trackGraphic, GridSpace* a_parentGridSpace);
	void interactWithTrain(/*train*/);
	void draw(sf::RenderTarget& a_target, sf::RenderStates a_states);
	static bool isTrackAtGsu(int x, int y);

private:
	static std::vector<sf::Vector2i> trackGridSpaces;
	bool isNeighborTrack(int a_xGridPosOffset, int a_yGridPosOffset);

};

#endif
