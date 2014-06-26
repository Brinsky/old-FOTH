#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "FOTHgrid.h"
#include "Train.h"
#include "TrackLayer.h"

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
	TrackLayer layer( 2, 14, &testGrid );

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
            {
                window.close();
            }
            else if( event.type == sf::Event::KeyPressed )
            {
                switch( event.key.code )
                {
                    case sf::Keyboard::Left:
                        layer.shiftAndAct(FOTH::West);
                        break;
                    case sf::Keyboard::Right:
                        layer.shiftAndAct(FOTH::East);
                        break;
                    case sf::Keyboard::Up:
                        layer.shiftAndAct(FOTH::North);
                        break;
                    case sf::Keyboard::Down:
                        layer.shiftAndAct(FOTH::South);
                        break;
                    default:
                        break;
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
