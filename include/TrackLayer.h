#ifndef TRACKLAYER
#define TRACKLAYER

#include "FOTHgrid.h"
#include "GridSpace.h"
#include "Track.h"
#include "FOTHUtility.h"

/** A mechanism controlled by the player in order to place Track */
class TrackLayer
{
	public:
	enum mode { Place = 0, Move = 1, Remove = 2 };
	TrackLayer( int a_posGsuX, int a_posGsuY, FOTHgrid* a_parentGrid );


	bool moveAndPlace( foth::dir a_dir );

	private:
	void placeTrack( foth::dir a_frontDir );

	/* The direction towards the previous piece of track.
	* Used to keep new track pieces connected to the
	* previous ones.
	*/
	FOTHgrid* parentGrid;
	Track* prevTrack;

	/* Used to track the direction the TrackLayer came from when
    * placing the previous Track piece. Refers to the direction
    * of the piece prior to the previous Track piece, as seen
    * from that Track piece.
    */
	foth::dir prevTrackBackDir;
	sf::Vector2i posGsu;
	mode layerMode;
};

#endif
