#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "FOTHgrid.h"
#include "Train.h"

//Gsu = GridSpace Units
//Pxl = Pixels

const int SCREEN_WIDTH = 448;
const int SCREEN_HEIGHT = 640;

int main(){

	std::vector<sf::Texture*> gridObjectTextures;

	sf::Texture defaultTexture;
	if ( !defaultTexture.loadFromFile( "res/OpenPlain.png" ) )
	{
		std::cout << "Texture did not load properly!" << std::endl;
		return -1;
	}
	gridObjectTextures.push_back(&defaultTexture);

	sf::Texture trainTexture;
	if ( !trainTexture.loadFromFile( "res/Train.png" ) )
	{
		std::cout << "Texture did not load properly!" << std::endl;
		return -1;

	}

	sf::Texture trackTexture;
	if(!trackTexture.loadFromFile("res/Track.png")){

		std::cout << "Texture did not load properly!" << std::endl;
		return -1;

	}
	gridObjectTextures.push_back(&trackTexture);

	FOTHgrid testGrid(20, gridObjectTextures);
	Train painTrain( &trainTexture, sf::Vector2f( 2, 18 ), FOTH::North, (Grid*) &testGrid );

	//Creating window and setting frame rate
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FOTH");
	window.setFramerateLimit(60);

	Camera screen(SCREEN_WIDTH, SCREEN_HEIGHT, &window);

	sf::Clock timeDiff; //Used to properly advance the game each tick
	sf::Time tickTime;

	//The "game loop"
	while ( window.isOpen() )
	{

		sf::Event event;

		//Checking window events
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				window.close();

			if(event.type == sf::Event::MouseButtonPressed){

				if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){

					testGrid.removeTrack(sf::Mouse::getPosition(window).x + (window.getView().getCenter().x - 224),
                        sf::Mouse::getPosition(window).y + (window.getView().getCenter().y - 320));

				}else{

					testGrid.addTrack(sf::Mouse::getPosition(window).x + (window.getView().getCenter().x - 224),
                        sf::Mouse::getPosition(window).y + (window.getView().getCenter().y - 320));

				}

			}

		}

		//Takes current value in timeDiff and restarts it
		//Used to "freeze" a single time value to ensure all tick functions receive the same time
		tickTime = timeDiff.restart();

		painTrain.tick(tickTime);
		screen.move(0, -1);

		//Drawing operations
		window.clear();
		testGrid.draw( window, sf::RenderStates::Default );
		painTrain.draw( window, sf::RenderStates::Default );
		window.display();

	}

   	 return 0;

}
