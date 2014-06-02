#include <iostream>
#include <SFML/Graphics.hpp>
#include "FOTHgrid.h"
 
int main(){

	sf::Texture defaultTexture;
	if( !defaultTexture.loadFromFile( "res/OpenPlain.png" ) )
	{
		std::cout << "Texture did not load properly!" << std::endl;
		return -1;
	}
	
	FOTHgrid testGrid(20, &defaultTexture);

	//Creating window and setting frame rate
	sf::RenderWindow window(sf::VideoMode(448, 640), "FOTH");
	window.setFramerateLimit(60);

	//The "game loop"
	while ( window.isOpen() )
	{
		
		sf::Event event;

		//Checking window events
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				window.close();
		}
		
		testGrid.scroll(1);	

		//Drawing operations
		window.clear();
		testGrid.draw( window, sf::RenderStates::Default );
		window.display();
	
	}

    return 0;

}
