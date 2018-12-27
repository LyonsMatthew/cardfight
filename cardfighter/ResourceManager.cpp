#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}
ResourceManager::~ResourceManager()
{

}

sf::Texture& ResourceManager::use_texture(const std::string& key)
{
	return textures.at(key);
}

sf::Font& ResourceManager::use_font(const std::string& key)
{
	return fonts.at(key);
}

sf::SoundBuffer& ResourceManager::use_sound(const std::string& key)
{
	return sounds.at(key);
}

sf::Music& ResourceManager::use_music(const std::string& key)
{
	return music.at(key);
}

void ResourceManager::load_texture(const std::string& key, const std::string& path)
{
	sf::Texture texture;
	texture.loadFromFile(path);
	ResourceManager::textures.emplace(key, texture);
}

void ResourceManager::load_font(const std::string& key, const std::string& path)
{
	sf::Font font;
	font.loadFromFile(path);
	ResourceManager::fonts.emplace(key, font);
}

void ResourceManager::load_sound(const std::string& key, const std::string& path)
{
	sf::SoundBuffer sound;
	sound.loadFromFile(path);
	ResourceManager::sounds.emplace(key, sound);
}

void ResourceManager::load_music(const std::string& key, const std::string& path)
{
	sf::Music music;
	music.openFromFile(path);
	//ResourceManager::music.emplace(key, music);
}

void ResourceManager::unload_texture(const std::string& key)
{
	ResourceManager::textures.erase(key);
}

void ResourceManager::unload_font(const std::string& key)
{
	ResourceManager::fonts.erase(key);
}

void ResourceManager::unload_sound(const std::string& key)
{
	ResourceManager::sounds.erase(key);
}

void ResourceManager::unload_music(const std::string& key)
{
	ResourceManager::music.erase(key);
}

void ResourceManager::reset()
{
	textures.clear();
	fonts.clear();
	sounds.clear();
	music.clear();
}

std::map<std::string, sf::Texture> ResourceManager::textures = std::map<std::string, sf::Texture>();
std::map<std::string, sf::Font> ResourceManager::fonts = std::map<std::string, sf::Font>();
std::map<std::string, sf::SoundBuffer> ResourceManager::sounds = std::map<std::string, sf::SoundBuffer>();
std::map<std::string, sf::Music> ResourceManager::music = std::map<std::string, sf::Music>();