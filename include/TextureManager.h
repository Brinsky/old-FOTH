#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

class TextureManager {

public:
	TextureManager(std::string textureFileName);

private:
	sf::Texture* textures;

};

#endif
