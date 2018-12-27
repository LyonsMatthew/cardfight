#include "ResourceUser.h"

ResourceUser::ResourceUser()
{
}

ResourceUser::~ResourceUser()
{
	std::set<std::string> registered_key_copy = std::set<std::string>(registered_texture_keys);
	for (std::string key : registered_key_copy)
		unregister_texture(key);
	registered_key_copy = std::set<std::string>(registered_font_keys);
	for (std::string key : registered_key_copy)
		unregister_font(key);
	registered_key_copy = std::set<std::string>(registered_sound_keys);
	for (std::string key : registered_key_copy)
		unregister_sound(key);
	registered_key_copy = std::set<std::string>(registered_music_keys);
	for (std::string key : registered_key_copy)
		unregister_music(key);
}

void ResourceUser::register_texture(const std::string& key, const std::string& path)
{
	ResourceManager::load_texture(key, path);
	ResourceUser::registered_texture_keys.insert(key);
}

void ResourceUser::unregister_texture(const std::string& key)
{
	ResourceManager::unload_texture(key);
	ResourceUser::registered_texture_keys.erase(key);
}

void ResourceUser::register_font(const std::string& key, const std::string& path)
{
	ResourceManager::load_font(key, path);
	ResourceUser::registered_font_keys.insert(key);
}

void ResourceUser::unregister_font(const std::string& key)
{
	ResourceManager::unload_font(key);
	ResourceUser::registered_font_keys.erase(key);
}

void ResourceUser::register_sound(const std::string& key, const std::string& path)
{
	ResourceManager::load_sound(key, path);
	ResourceUser::registered_sound_keys.insert(key);
}

void ResourceUser::unregister_sound(const std::string& key)
{
	ResourceManager::unload_sound(key);
	ResourceUser::registered_sound_keys.erase(key);
}

void ResourceUser::register_music(const std::string& key, const std::string& path)
{
	ResourceManager::load_music(key, path);
	ResourceUser::registered_music_keys.insert(key);
}

void ResourceUser::unregister_music(const std::string& key)
{
	ResourceManager::unload_music(key);
	ResourceUser::registered_music_keys.erase(key);
}