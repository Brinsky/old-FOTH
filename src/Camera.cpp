#include "Camera.h"

Camera::Camera(int a_windowWidth, int a_windowHeight, sf::RenderWindow* a_windowToControl){

	windowDimensions.x = a_windowWidth;
	windowDimensions.y = a_windowHeight;

	controlledWindow = a_windowToControl;

	cameraPosition = controlledWindow->getView().getCenter();

}

void Camera::setPosition(float a_positionX, float a_positionY){

	cameraPosition.x = a_positionX + (windowDimensions.x / 2);
	cameraPosition.y = a_positionY + (windowDimensions.y / 2);

	sf::View tempView = controlledWindow->getView();
	tempView.setCenter(cameraPosition.x, cameraPosition.y);

	controlledWindow->setView(tempView);

}

void Camera::move(float a_offsetX, float a_offsetY){

	cameraPosition.x += a_offsetX;
	cameraPosition.y += a_offsetY;

	sf::View tempView = controlledWindow->getView();
	tempView.setCenter(cameraPosition.x, cameraPosition.y);

	controlledWindow->setView(tempView);

}
