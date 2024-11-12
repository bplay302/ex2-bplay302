#pragma once
#include <string>

class Page
{
public:
	void init();

	void clearPage();

	void addLineToPosts(const std::string& newLine);

	//setters
	void setStatus(const std::string& status);

	//getters
	std::string getPosts() const;
	std::string getStatus() const;

private:
	std::string _status;
	std::string _posts;
};

