#include "FOTHUtility.h"


FOTH::dir FOTH::getOppositeDir( dir a_dir )
{
	dir oppDir = North;
	
	switch (a_dir)
	{
		case North:
			oppDir = South;
			break;
		case West:
			oppDir = East;
			break;
		case South:
			oppDir = North;
			break;
		case East:
			oppDir = West;
			break;
		default:
			break;
	}

	return oppDir;
}
