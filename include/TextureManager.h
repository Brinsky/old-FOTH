#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

class TextureManager {

public:
	TextureManager(std::string textureFileName);
	sf::Texture& getTexture(std::string textureClassName);

private:
	sf::Texture* textures;
	std::string* nameList;

};

#endif
