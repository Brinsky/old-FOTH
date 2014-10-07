#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager(std::string textureFileName){

	std::ifstream in(textureFileName.c_str());
	
	int numberOfTextures = 0;

	while(true){

		std::getline(in, textureFileName);
		if(in.eof()) break;
		numberOfTextures++;

	}

	std::cout << numberOfTextures << std::endl;

}
