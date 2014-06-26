#ifndef FOTHUTILITY
#define FOTHUTILITY

namespace FOTH
{
	/** An enumeration type for directions */
	enum dir { North = 0, West = 1, South = 2, East = 3 };
	
	dir getOppositeDir( dir a_dir );

	//Add fpair and ipair structs
	//Possibly add gsu and pxl typedefs
}

#endif
