#pragma once
#include <string>
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(const std::string& networkName, const unsigned int minAge);
	
	void clear();

	bool addProfile(const Profile& profile_to_add);

	//getters
	std::string getNetworkName() const;
	int getMinAge() const;

	std::string getWindowsDevices() const;

private:
	std::string _Name;
	unsigned int _minAge;
	ProfileList _profiles;
};

