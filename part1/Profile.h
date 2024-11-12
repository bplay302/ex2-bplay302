#pragma once
#include "User.h"
#include "Page.h"
#include "UserList.h"
#include <string>

class Profile
{
public:
	void init(const User& owner);
	
	void clear();

	void addPostToProfilePage(const std::string& post);

	void addFriend(const User friendToAdd);

	//getters
	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;

	std::string getFriendsWithSameNameLength();

	//setters
	void setStatus(const std::string& newStatus);

	
private:
	User _owner;
	Page _page;
	UserList _friendsList;
};

