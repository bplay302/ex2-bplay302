#pragma once
#include "User.h"
#include "Page.h"
#include "UserList.h"
#include <string>

class Profile
{
public:
	/*
	* create an epmty profile for user
	* \param the user that ownthe profile
	*/
	void init(const User& owner);
	
	/*
	* clears the profile data
	*/
	void clear();

	/*
	* add a post to the profile data
	* \param post to add
	*/
	void addPostToProfilePage(const std::string& post);

	/*
	* add a friend(another user) to friend list of the profile
	* \param user to add as a friend
	*/
	void addFriend(const User friendToAdd);

	//BONOS: in constarction
	void changeAllWordsInStatus(const std::string& word);
	void changeWordInStatus(const std::string& word_to_replace, const std::string& new_word);
	//--------------------- 
	

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

