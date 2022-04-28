//
// Created by over- on 26/04/2022.
//
#include <bits/stdc++.h>
#include "LoginFunctions.h"
using namespace std;


void user::setName(string name)
{
    userName = name;
}

void user::setEmail(string email)
{
    userEmail = email;
}

void user::setPhoneNumber(string phoneNumber)
{
    userPhoneNumber = phoneNumber;
}

void user::setPassword(string password)
{
    userPassword = password;
}

void user::printInfo()
{
    cout << "username: " << userName << endl;
    cout << "Email: " << userEmail << endl;
    cout << "phone number: " << userPhoneNumber << endl;
    cout << "password: " << userPassword << endl;
}

string user::username()
{
    return userName;
}

string user::email()
{
    return userEmail;
}

string user::phoneNumber()
{
    return userPhoneNumber;
}

string user::password()
{
    return userPassword;
}

bool user::validEmail()
{
    regex validEmail("[\\d\\w#!%$‘&+*–/=?^_`{|}~]+.?[\\d\\w#!%$‘&+*–/=?^_`{|}~]+@[^\\s@-]+\\.[^\\s@-]{2,}$");
    return regex_match(userEmail, validEmail);
}

bool user::validUserName()
{
    regex validUserName("[-a-zA-z ]+");
    return regex_match(userName, validUserName);
}

bool user::validPhoneNumber()
{
    regex validPhoneNumber("01[0-9]{9}$");
    return regex_match(userPhoneNumber, validPhoneNumber);
}

bool user::strongPassword()
{
    int strong[4] = {0};
    for (int i = 0; i < userPassword.size(); i++){
        if (isupper(userPassword[i]))
        {
            strong[0] = 1;
        }
        else if (islower(userPassword[i]))
        {
            strong[1] = 1;
        }
        else if (isdigit(userPassword[i]))
        {
            strong[2] = 1;
        }
        else{
            strong[3] = 1;
        }
    }
    if (strong[0] + strong[1] + strong[2] + strong[3] == 4 && userPassword.size() >= 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
