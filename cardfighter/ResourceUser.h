#pragma once
#include "ResourceManager.h"
#include "iterator"


class ResourceUser
{
public:
	ResourceUser();
	~ResourceUser();
	
	void register_texture(const std::string& key, const std::string& path);
	void unregister_texture(const std::string& key);
	void register_font(const std::string& key, const std::string& path);
	void unregister_font(const std::string& key);
	void register_sound(const std::string& key, const std::string& path);
	void unregister_sound(const std::string& key);
	void register_music(const std::string& key, const std::string& path);
	void unregister_music(const std::string& key);

protected:
	std::set<std::string> registered_texture_keys;
	std::set<std::string> registered_font_keys;
	std::set<std::string> registered_sound_keys;
	std::set<std::string> registered_music_keys;

	virtual void register_resources() = 0;
	virtual void use_resources() = 0;

private:
	
};