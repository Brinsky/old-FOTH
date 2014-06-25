#ifndef TRACKLAYER
#define TRACKLAYER

#include "Grid.h"
#include "GridSpace.h"
#include "Track.h"
#include "FOTHUtility.h"

/** A mechanism controlled by the player in order to place Track */
class TrackLayer
{
	public:
	enum mode { Place = 0, Move = 1, Remove = 2 };
	TrackLayer( int initialPosGsuX, int initialPosGsuY );

	/** Dependent on mode; causes TrackLayer to move and
	* potentially place track, remove track, or do nothing.
	* Returns false if the movement is illegal.
	**/
	bool shiftAndAct( FOTH::dir a_dir );

	private:
	
	/** Places track at the TrackLayer's current location.
	* Fails and returns false if a Track is already present. 
	*/
	bool placeTrack( FOTH::dir a_comingFromDir, FOTH::dir a_goingToDir );

	/** Attempts to move the TrackLayer. Returns false if
	* movement is illegal.
	*/
	bool move( FOTH::dir a_dir );

	/** Attempts to remove a Track at the TrackLayer's
	* location. Returns false if Track isn't present.
	*/
	bool removeTrack();

	sf::Vector2i posGsu;
	mode layerMode;
};

#endif
