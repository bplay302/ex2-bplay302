#include "Profile.h"

void Profile::init(const User& owner)
{
    this->_owner = owner;
    this->_page.init();
    this->_friendsList.init();
}

void Profile::clear()
{
    this->_owner.clear();
    this->_page.clearPage();
    this->_friendsList.clear();
}

void Profile::addPostToProfilePage(const std::string& post)
{
    this->_page.addLineToPosts(post);
}

void Profile::addFriend(const User friendToAdd)
{
    this->_friendsList.add(friendToAdd);
}

User Profile::getOwner() const
{
    return this->_owner;
}

std::string Profile::getPage() const
{
    return "Status: " + this->_page.getStatus() + '\n'
        + "*******************\n" + "*******************\n" + this->_page.getPosts();
}

std::string Profile::getFriends() const
{
    UserNode* friendUser = this->_friendsList.get_first();
    std::string friendsString = "";


    while (friendUser)
    {
        friendsString += friendUser->get_data().getUserName() + ',';

        friendUser = friendUser->get_next();
    }
    
   friendsString.pop_back();

   return friendsString;
}

std::string Profile::getFriendsWithSameNameLength()
{
    UserNode* friendUser = this->_friendsList.get_first();
    std::string friendsString = "";


    while (friendUser)
    {
        if (friendUser->get_data().getUserName().length() == 
            this->_owner.getUserName().length())
        {
            friendsString += friendUser->get_data().getUserName() + ',';
        }

        friendUser = friendUser->get_next();
    }

    friendsString.pop_back();

    return friendsString;
}

void Profile::setStatus(const std::string& newStatus)
{
    this->_page.setStatus(newStatus);
}
