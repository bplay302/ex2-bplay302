#pragma once
#include <string>
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork
{
public:
	/*
	* init the SocialNetwork
	* \param the name of the network
	* \param min age for users in the network
	*/
	void init(const std::string& networkName, const unsigned int minAge);
	
	/*
	*  clear the social network
	*/
	void clear();

	/*
	* add profile to the socialNetwork profiles
	* \param profile data to add
	*/
	bool addProfile(const Profile& profile_to_add);

	//getters
	std::string getNetworkName() const;
	int getMinAge() const;

	/*
	* get a list in a string of the active window devices in the network
	*/
	std::string getWindowsDevices() const;

private:
	std::string _Name;
	unsigned int _minAge;
	ProfileList _profiles;
};

