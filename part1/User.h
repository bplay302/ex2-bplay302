#pragma once
#include <string>
#include "DeviceList.h"

class User
{
public:
	/*
	* init User
	* \param user's id
	* \param user's username
	* \param user's age
	*/
	void init(const unsigned int id, const std::string& username, const unsigned int age);

	/*
	* clear user data
	*/
	void clear();

	/*
	* add device to user's devices list
	* \param device data to add
	*/
	void addDevice(const Device newDevice);

	/*
	* check if all devices of the user are activated
	*/
	bool checkIfDevicesAreOn() const;

	//getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();

private:
	unsigned int _id;
	std::string _username;
	unsigned int _age;	
	DevicesList _devices;
};

