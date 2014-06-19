#include "Track.h"

std::vector<sf::Vector2i> Track::trackGridSpaces;

Track::Track(sf::Texture* a_trackGraphic, GridSpace* a_parentGridSpace) : FOTHgridObject(0, 0, a_trackGraphic, a_parentGridSpace){

	trackGridSpaces.push_back(parentGridSpace->getGridSpacePosition());

}

bool Track::isTrack(int x, int y){

	for(int i = 0; i < trackGridSpaces.size(); i++){

		if(trackGridSpaces[i] == sf::Vector2i(x, y)){
		
			return true;

		}

	}

	return false;

}

bool Track::isNeighborTrack(int a_xGridPosOffset, int a_yGridPosOffset){

	for(int i = 0; i < trackGridSpaces.size(); i++){

		if(trackGridSpaces[i] == sf::Vector2i(parentGridSpace->getGridSpacePosition().x + a_xGridPosOffset, parentGridSpace->getGridSpacePosition().y + a_yGridPosOffset)){
		
			return true;

		}

	}

	return false;

}

void Track::interactWithTrain(/*train*/){
}

void Track::draw(sf::RenderTarget& a_target, sf::RenderStates a_states){

	objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));

	objectGraphic.setPosition((parentGridSpace->getGridSpaceDimensions().x * (parentGridSpace->getGridSpacePosition().x + objectPosition.x)) + parentGridSpace->getGridPosition().x, (parentGridSpace->getGridSpaceDimensions().y * (parentGridSpace->getGridSpacePosition().y + objectPosition.y)) + parentGridSpace->getGridPosition().y);

	if(isNeighborTrack(0, -1)){

		if(isNeighborTrack(1, 0)){
		
			objectGraphic.setTextureRect(sf::IntRect(0, 64, 64, 64));

		}else if(isNeighborTrack(-1, 0)){
			
			objectGraphic.setTextureRect(sf::IntRect(64, 64, 64, 64));

		}else{
			
			objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));

		}
		
	}else if(isNeighborTrack(0, 1)){

		if(isNeighborTrack(1, 0)){

			objectGraphic.setTextureRect(sf::IntRect(0, 128, 64, 64));
		
		}else if(isNeighborTrack(-1, 0)){

			objectGraphic.setTextureRect(sf::IntRect(64, 0, 64, 64));

		}else{

			objectGraphic.setTextureRect(sf::IntRect(0, 0, 64, 64));

		}

	}else if(isNeighborTrack(-1, 0) || isNeighborTrack(1, 0)){

		objectGraphic.setTextureRect(sf::IntRect(64, 128, 64, 64));
	
	}

	a_target.draw(objectGraphic, a_states);

}
