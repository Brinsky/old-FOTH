#ifndef FOTHUTILITY
#define FOTHUTILITY

namespace foth
{
    //Add fpair and ipair structs
	//Possibly add gsu and pxl typedefs

	/// An enumeration type for directions
	enum dir { North = 0, West = 1, South = 2, East = 3 };

	dir getOppositeDir(dir a_dir);
	void getLevelGrid(const std::string &filename);
	std::string getFileAsString(const std::string &filename);
}

#endif
