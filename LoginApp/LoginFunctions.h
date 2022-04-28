//
// Created by over- on 26/04/2022.
//

#ifndef LOGINAPP_LOGINFUNCTIONS_H
#define LOGINAPP_LOGINFUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

struct user{
    private:

        string userName;
        string userEmail;
        string userPhoneNumber;
        string userPassword;

    public:

        bool validEmail();
        bool validUserName();
        bool validPhoneNumber();

        void setName(string name);
        void setEmail(string email);
        void setPhoneNumber(string phoneNumber);
        void setPassword(string password);
        void printInfo();

        string username();
        string email();
        string phoneNumber();
        string password();
};


#endif //LOGINAPP_LOGINFUNCTIONS_H
