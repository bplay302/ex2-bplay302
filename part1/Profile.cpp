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

    //the first word start pos
    wordStart = statusStr.find_first_not_of(' ');
    //the first word end pos
    wordEnd = statusStr.find_first_of(' ', wordStart);

    //go through all words
    while (wordStart != std::string::npos)
    {
        //replace word with word to replace
        statusStr = statusStr.replace(wordStart, (wordEnd - wordStart), word);

        // find the next word start and end pos
        wordStart = statusStr.find_first_not_of(' ', wordStart + word.length());
        wordEnd = statusStr.find_first_of(' ', wordStart);
    }

    //set the status to the corrected one
    this->_page.setStatus(statusStr);
}

void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& new_word)
{
    // Find the first apearence of the word
    size_t pos = this->_page.getStatus().find(word_to_replace);

    // go through all apearences of the word and replace it with the new word
    while (pos != std::string::npos) 
    {
        // replace the word with replace word
        this->_page.setStatus(this->_page.getStatus().replace(pos, word_to_replace.size(), new_word));

        // Find the next apearance of the word
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
