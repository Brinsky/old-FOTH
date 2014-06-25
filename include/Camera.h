#ifndef CAMERA
#define CAMERA

#include <SFML/Graphics.hpp>

class Camera {

public:
	Camera(int a_windowWidth, int a_windowHeight, sf::RenderWindow* a_windowToControl);
	void move(float a_offsetX, float a_offsetY);
	void setPosition(float a_positionX, float a_positionY);

protected:
	sf::RenderWindow* controlledWindow;
	sf::Vector2i windowDimensions;
	sf::Vector2f cameraPosition;

};

#endif