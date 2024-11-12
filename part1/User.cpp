#include "User.h"

void User::init(const unsigned int id, const std::string& username, const unsigned int age)
{
    this->_id = id;
    this->_username = username;
    this->_age = age;
    this->_devices.init();
}

void User::clear()
{
    this->_devices.clear();
    this->_age = 0;
    this->_id = 0;
    this->_username = "";
}

void User::addDevice(const Device newDevice)
{
    this->_devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
    DeviceNode* tempDevices = this->_devices.get_first();
    bool devicesOn = true;

    while (tempDevices)
    {
        if (!tempDevices->get_data().isActive())
        {
            devicesOn = false;
        }
        tempDevices = tempDevices->get_next();
    }

    return devicesOn;
}

unsigned int User::getID() const
{
    return this->_id;
}

std::string User::getUserName() const
{
    return this->_username;
}

unsigned int User::getAge() const
{
    return this->_age;
}

DevicesList& User::getDevices()
{
    return this->_devices;
}
