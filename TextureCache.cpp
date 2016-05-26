#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
namespace NeroEngine{
	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}


	GLTexture TextureCache::getTexture(std::string texturePath){

		//auto  mit =  _textureMap.find(texturePath);
		//��map�в���texture
		std::map<std::string, GLTexture>::iterator mit = _textureMap.find(texturePath);

		if (mit == _textureMap.end()){
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			std::pair<std::string, GLTexture> newPair(texturePath, newTexture);

			//_textureMap.insert(make_pair(texturePath,newTexture));
			_textureMap.insert(newPair);

			std::cout << "��ȡ��ͼ:" + texturePath + "\n";
			return newTexture;
		}
		//std::cout << "ʹ�û�����ͼ\n";
		return mit->second;


	}
}