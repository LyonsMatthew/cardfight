#pragma once
#include <map>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static sf::Texture& use_texture(const std::string& key);
	static sf::Font& use_font(const std::string& key);
	static sf::SoundBuffer& use_sound(const std::string& key);
	static sf::Music& use_music(const std::string& key);

	static void load_texture(const std::string& key, const std::string& path);
	static void load_font(const std::string& key, const std::string& path);
	static void load_sound(const std::string& key, const std::string& path);
	static void load_music(const std::string& key, const std::string& path);

	static void unload_texture(const std::string& key);
	static void unload_font(const std::string& key);
	static void unload_sound(const std::string& key);
	static void unload_music(const std::string& key);

	static void reset();

private:
	static std::map<std::string, sf::Texture> textures;
	static std::map<std::string, sf::Font> fonts;
	static std::map<std::string, sf::SoundBuffer> sounds;
	static std::map<std::string, sf::Music> music;

};