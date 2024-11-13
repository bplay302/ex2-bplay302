#include "Profile.h"

void Profile::init(const User& owner)
{
    this->_owner = owner;
    this->_page.init();
    this->_friendsList.init();
}

void Profile::clear()
{
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

void Profile::changeAllWordsInStatus(const std::string& word)
{
    size_t wordStart = 0, wordEnd = 0;
    std::string statusStr = this->_page.getStatus();

    std::string newStatus = "";

    while (wordStart != std::string::npos)
    {
        wordStart = statusStr.find_first_not_of(' ', wordStart);
        wordEnd = statusStr.find_first_of(' ', wordStart);

        statusStr.replace(wordStart, (wordEnd - wordStart), word);
    }

}

void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& new_word)
{
    // Find the first occurrence of the substring
    size_t pos = this->_page.getStatus().find(word_to_replace);

    // Iterate through the string and replace all
    // occurrences
    while (pos != std::string::npos) 
    {
        // Replace the substring with the specified string
        this->_page.getStatus().replace(pos, word_to_replace.size(), new_word);

        // Find the next occurrence of the substring
        pos = this->_page.getStatus().find(word_to_replace,
            pos + new_word.size());
    }
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

    //move through all friends and add their user name to the string, sperated by ',' 
    while (friendUser)
    {
        friendsString += friendUser->get_data().getUserName() + ',';

        friendUser = friendUser->get_next();
    }
    
    //remove ',' in the end of the string
    if (!friendsString.empty())
    {
        friendsString.pop_back();
    }

   return friendsString;
}

std::string Profile::getFriendsWithSameNameLength()
{
    UserNode* friendUser = this->_friendsList.get_first();
    std::string friendsString = "";

    //move through all friends
    while (friendUser)
    {
        // if their user name length is the same as the user, add it to the string, sperated by ',' 
        if (friendUser->get_data().getUserName().length() == 
            this->_owner.getUserName().length())
        {
            friendsString += friendUser->get_data().getUserName() + ',';
        }

        friendUser = friendUser->get_next();
    }

    //remove ',' in the end of the string
    if (!friendsString.empty())
    {
        friendsString.pop_back();
    }
   
    return friendsString;
}

void Profile::setStatus(const std::string& newStatus)
{
    this->_page.setStatus(newStatus);
}
