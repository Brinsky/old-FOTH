#include "Camera.h"

Camera::Camera(int a_positionX, int a_positionY, int a_windowWidth, int a_windowHeight, sf::RenderWindow* a_windowToControl){

	windowDimensions.x = a_windowWidth;
	windowDimensions.y = a_windowHeight;

	controlledWindow = a_windowToControl;

	cameraPosition.x = a_positionX;
	cameraPosition.y = a_positionY;

	sf::View tempView = controlledWindow->getView();
	tempView.setCenter(cameraPosition.x + (windowDimensions.x / 2), cameraPosition.y + (windowDimensions.y / 2));

	controlledWindow->setView(tempView);

}

void Camera::setPosition(float a_positionX, float a_positionY){

	cameraPosition.x = a_positionX;
	cameraPosition.y = a_positionY;

	sf::View tempView = controlledWindow->getView();
	tempView.setCenter(cameraPosition.x + (windowDimensions.x / 2), cameraPosition.y + (windowDimensions.y / 2));

	controlledWindow->setView(tempView);

}

void Camera::move(float a_offsetX, float a_offsetY){

//	cameraPosition.x += a_offsetX;
//	cameraPosition.y += a_offsetY;

//	sf::View tempView = controlledWindow->getView();
//	tempView.setCenter(cameraPosition.x + (windowDimensions.x / 2), cameraPosition.y + (windowDimensions.y / 2));

//	controlledWindow->setView(tempView);

	setPosition(cameraPosition.x + a_offsetX, cameraPosition.y + a_offsetY);

}

sf::Vector2f Camera::getPosition(){

	return cameraPosition;

}
