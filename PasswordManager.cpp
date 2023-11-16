//Password Manager.cpp file
#include "PasswordManager.h"
#include <string>
#include <algorithm>
using namespace std;

//*****************************************************************************
//This sets private username
void PasswordManager::setUserName(string UN) 
{
    userName = UN;
}
//Returns username when recieved
string PasswordManager::getUserName() const 
{
    return userName;
}

//*****************************************************************************
//Sets password and makes sure that it meets criteria
bool PasswordManager::setNewPassword(string setNew) 
{
    bool metCrit = meetsCriteria(setNew);
    return metCrit;
}

//*****************************************************************************
//Checking that new password meets criteria
bool PasswordManager::meetsCriteria(string nPass)
{
    bool comp = false; //set complete pass

    if(nPass.length() > 15 || nPass.length() < 127) //check length of password
    {
        if(std::any_of(nPass.cbegin(), nPass.cend(), ::isupper) && 
           std::any_of(nPass.cbegin(), nPass.cend(), ::islower) &&
           std::any_of(nPass.cbegin(), nPass.cend(), ::ispunct) &&
           nPass.find_first_of("*%") == string::npos)
                return true; // returns true if all criteria is met
    }

    return comp;

}

//*****************************************************************************
//This part is encrypting the password and assigning it to private variable
void PasswordManager::setEncryptedPassword(string EP) //(int)c
{
    for(int i = 0; i < EP.length(); i++)
    {
        char c = EP[i];
        c = (((int)c - 33) + 45) % 94 + 33;
        encrypt.push_back(c);

    }
}
//This part is returning that private variable
string PasswordManager::getEncryptedPassword() const
{
    return encrypt;
}

//*****************************************************************************
//This makes sure that the encrypted string matches the stored
