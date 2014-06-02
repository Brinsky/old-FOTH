#ifndef FOTH_GRID_OBJECT
#define FOTH_GRID_OBJECT

#include "GridObject.h"
#include "GridSpace.h"

class FOTHgridObject : public GridObject {

public:
	FOTHgridObject(float a_positionX, float a_positionY, sf::Texture* a_objectGraphic, GridSpace* a_parentGridSpace);
	virtual void interactWithTrain(/*train*/) = 0;

};

#endif
