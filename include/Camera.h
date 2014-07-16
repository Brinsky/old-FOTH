#ifndef CAMERA
#define CAMERA

#include <SFML/Graphics.hpp>

/** A controllable camera used to display a specific game area on the main window */
class Camera {

public:
	Camera(int a_positionX, int a_positionY, int a_windowWidth, int a_windowHeight, sf::RenderWindow* a_windowToControl);
	void move(float a_offsetX, float a_offsetY);
	void setPosition(float a_positionX, float a_positionY);
	sf::Vector2f getPosition();

protected:
	sf::RenderWindow* controlledWindow;
	sf::Vector2i windowDimensions;
	sf::Vector2f cameraPosition;

};

#endif
