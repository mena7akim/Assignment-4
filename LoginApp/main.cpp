#include <bits/stdc++.h>
#include "LoginFunctions.h"
using namespace std;

user newUser;
bool isTrue = true;
string username,email,password,phoneNumber,line;

void emailRegister();
void usernameRegister();
void phoneNumberRegister();
void passwordRegister();

int main() {
    int order;
    cout << "(1) Register\n(2) Login\n(3) Change Password\n(4) Exit\n";
    cin >> order;
    switch (order) {
        case 1:
            emailRegister();
            usernameRegister();
            phoneNumberRegister();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

void emailRegister(){
    fstream data;
    data.open("data.txt", ios::out|ios::in);
    while (isTrue){
        cout << "Enter your Email:\n";
        cin >> email;
        newUser.setEmail(email);
        if (newUser.validEmail())
        {
            while (getline(data, line))
            {
                if (line == email){
                    cout << "email is already exist,try another one\n";
                    isTrue = true;
                    break;
                }
                else{
                    isTrue = false;
                }
            }

            if (!isTrue){
                data.clear();
                data << "\n\n" << newUser.email();
                cout << "Your Email is: " << newUser.email() << endl;
                break;
            }
        }
        else
        {
            cout << "unvalid Email. try again\n";
        }
    }
    data.close();
}

void usernameRegister(){
    isTrue = true;
    int lineNumber = 1;
    fstream data;
    data.open("data.txt", ios::out|ios::in);
    while (isTrue){
        cout << "Enter your username:\n";
        cin >> username;
        newUser.setName(username);
        if (newUser.validUserName())
        {
            while (getline(data, line))
            {
                if (((lineNumber-2)%5)==0){
                    if (line == username){
                        cout << "username is already exist,try another one\n";
                        isTrue = true;
                        break;
                    }
                    else{
                        isTrue = false;
                    }
                }
                lineNumber++;
            }

            if (!isTrue){
                data.clear();
                data << "\n" << newUser.username();
                cout << "Your username is: " << newUser.username() << endl;
                break;
            }
        }
        else
        {
            cout << "unvalid username. try again\n";
        }
    }
    data.close();
}

void phoneNumberRegister(){
    isTrue = true;
    int lineNumber = 1;
    fstream data;
    data.open("data.txt", ios::out|ios::in);
    while (isTrue){
        cout << "Enter your phone number:\n";
        cin >> phoneNumber;
        newUser.setPhoneNumber(phoneNumber);
        if (newUser.validPhoneNumber())
        {
            while (getline(data, line))
            {
                if (((lineNumber-3)%5)==0){
                    if (line == phoneNumber){
                        cout << "phone number is already exist,try another one\n";
                        isTrue = true;
                        break;
                    }
                    else{
                        isTrue = false;
                    }
                }
                lineNumber++;
            }

            if (!isTrue){
                data.clear();
                data << "\n" << newUser.phoneNumber();
                cout << "Your phone number is: " << newUser.phoneNumber() << endl;
                break;
            }
        }
        else
        {
            cout << "unvalid phone number. try again\n";
        }
    }
    data.close();
}