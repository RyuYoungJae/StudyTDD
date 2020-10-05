#pragma once
#include <memory>
#include <string>
#include <unordered_map>

class Video;
class RentalSystem
{
private:
	std::unordered_map<std::string, std::shared_ptr<Video>> m_titles;

public:
	RentalSystem() = default;

	void Register(const std::shared_ptr<Video>& video);
	std::shared_ptr<Video> Find(const std::string& title);
};