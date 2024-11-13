#pragma once
#include <string>

class Page
{
public:
	/*
	* create an empty page
	*/
	void init();

	/*
	* delete ol posts (doesn't clear status)
	*/
	void clearPage();

	/*
	* add post to page data
	*/
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

