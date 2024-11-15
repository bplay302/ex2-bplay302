#include "SocialNetwork.h"

void SocialNetwork::init(const std::string& networkName, const unsigned int minAge)
{
    this->_Name = networkName;
    this->_minAge = minAge;
    this->_profiles.init();
}

void SocialNetwork::clear()
{
    this->_minAge = 1000; //set min age to a large value for reset
    this->_Name = "";
    this->_profiles.clear();
}

bool SocialNetwork::addProfile(const Profile& profile_to_add)
{
    if (profile_to_add.getOwner().getAge() < this->_minAge)
    {
        return false;
    }
    else
    {
        this->_profiles.add(profile_to_add);
        return true;
    }
}

std::string SocialNetwork::getNetworkName() const
{
    return this->_Name;
}

int SocialNetwork::getMinAge() const
{
    return this->_minAge;
}

std::string SocialNetwork::getWindowsDevices() const
{
    DeviceNode* userDeviceTmp = nullptr;
    ProfileNode* profileTmp = this->_profiles.get_first();
    std::string windowDevicesStr = "";

    //move through all profiles in the social network
    while (profileTmp)
    {
        userDeviceTmp = profileTmp->get_data().getOwner().getDevices().get_first();
        //move through all devices in user's Devices
        while (userDeviceTmp)
        {
            std::string ID = std::to_string(userDeviceTmp->get_data().getID()); //device's ID as a string
            std::string OS = userDeviceTmp->get_data().getOS();

            //add active window devices to string
            if (userDeviceTmp->get_data().isActive() && (OS == WINDOWS10 || OS == WINDOWS11 || OS == WINDOWS7))
            {
                windowDevicesStr += '[' + ID + ", " + OS + "], ";
            }

            userDeviceTmp = userDeviceTmp->get_next();
        }

        profileTmp = profileTmp->get_next();
    }
    
    //remove last ", " from the string
    windowDevicesStr.pop_back();
    windowDevicesStr.pop_back();

    return windowDevicesStr;
}
