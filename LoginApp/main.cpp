#include <bits/stdc++.h>
#include <conio.h>
 #include "LoginFunctions.h"
using namespace std;

//struct user{
//    private:
//
//        string userName;
//        string userEmail;
//        string userPhoneNumber;
//        string userPassword;
//
//    public:
//
//        bool validEmail();
//        bool validUserName();
//        bool validPhoneNumber();
//        bool strongPassword();
//
//        void setName(string name);
//        void setEmail(string email);
//        void setPhoneNumber(string phoneNumber);
//        void setPassword(string password);
//        void printInfo();
//
//        string username();
//        string email();
//        string phoneNumber();
//        string password();
//};
//
//void user::setName(string name)
//{
//    userName = name;
//}
//
//void user::setEmail(string email)
//{
//    userEmail = email;
//}
//
//void user::setPhoneNumber(string phoneNumber)
//{
//    userPhoneNumber = phoneNumber;
//}
//
//void user::setPassword(string password)
//{
//    userPassword = password;
//}
//
//void user::printInfo()
//{
//    cout << "username: " << userName << endl;
//    cout << "Email: " << userEmail << endl;
//    cout << "phone number: " << userPhoneNumber << endl;
//    cout << "password: " << userPassword << endl;
//}
//
//string user::username()
//{
//    return userName;
//}
//
//string user::email()
//{
//    return userEmail;
//}
//
//string user::phoneNumber()
//{
//    return userPhoneNumber;
//}
//
//string user::password()
//{
//    return userPassword;
//}
//
//bool user::validEmail()
//{
//    regex validEmail("[\\d\\w#!%$‘&+*–/=?^_`{|}~]+.?[\\d\\w#!%$‘&+*–/=?^_`{|}~]+@[^\\s@-]+\\.[^\\s@-]{2,}$");
//    return regex_match(userEmail, validEmail);
//}
//
//bool user::validUserName()
//{
//    regex validUserName("[-a-zA-z ]+");
//    return regex_match(userName, validUserName);
//}
//
//bool user::validPhoneNumber()
//{
//    regex validPhoneNumber("01[0-9]{9}$");
//    return regex_match(userPhoneNumber, validPhoneNumber);
//}
//
//bool user::strongPassword()
//{
//    int strong[4] = {0};
//    for (int i = 0; i < userPassword.size(); i++){
//        if (isupper(userPassword[i]))
//        {
//            strong[0] = 1;
//        }
//        else if (islower(userPassword[i]))
//        {
//            strong[1] = 1;
//        }
//        else if (isdigit(userPassword[i]))
//        {
//            strong[2] = 1;
//        }
//        else{
//            strong[3] = 1;
//        }
//    }
//    if (strong[0] + strong[1] + strong[2] + strong[3] == 4 && userPassword.size() >= 12)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

user newUser;
bool isTrue = true;
string username, email, password, repeatPassword, phoneNumber, line;

string hiddenPassword();
void emailRegister();
void usernameRegister();
void phoneNumberRegister();
void passwordRegister();


int main() {
    int order;
    cout << "(1) Register\n(2) Login\n(3) Change Password\n(4) Exit\n";
    cin >> order;
    switch (order)
    {
        case 1:
            emailRegister();
            usernameRegister();
            phoneNumberRegister();
            passwordRegister();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

string hiddenPassword()
{
    const int  passwordMaxLength = 30;
    char password[passwordMaxLength + 1];
    char ch;
    int position = 0;
    while (true)
    {
        ch = getch();
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            if (position > 0)
            {
                position--;
                password[position] = '\0';
                cout << "\b \b";
            }
        }
        else if (ch == 32 || ch == 9)
        {
            continue;
        }
        else{
            if(position < passwordMaxLength)
                {
                password[position] = ch;
                position++;
                cout << "*";
            }
        }
    }
    password[position] = '\0';
    string mystring(password);
    return mystring;
}

void emailRegister()
{
    fstream data;
    data.open("data.txt", ios::out | ios::in);
    while (isTrue)
    {
        cout << "Enter your Email:\n";
        cin >> email;
        newUser.setEmail(email);
        if (newUser.validEmail())
        {
            while (getline(data, line))
            {
                if (line == email)
                {
                    cout << "email is already exist,try another one\n";
                    isTrue = true;
                    break;
                }
                else
                {
                    isTrue = false;
                }
            }

            if (!isTrue)
            {
                data.clear();
                data << "\n\n" << newUser.email();
                cout << "Your Email is: " << newUser.email() << endl;
                break;
            }
        }
        else
        {
            cout << "invalid Email. try again\n";
        }
    }
    data.close();
}

void usernameRegister()
{
    isTrue = true;
    int lineNumber = 1;
    fstream data;
    data.open("data.txt", ios::out | ios::in);
    while (isTrue)
    {
        cout << "Enter your username:\n";
        getline(cin >> ws, username);
        newUser.setName(username);
        if (newUser.validUserName())
        {
            while (getline(data, line))
            {
                if (((lineNumber - 2) % 5) == 0)
                {
                    if (line == username)
                    {
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

            if (!isTrue)
            {
                data.clear();
                data << "\n" << newUser.username();
                cout << "Your username is: " << newUser.username() << endl;
                break;
            }
        }
        else
        {
            cout << "invalid username. try again\n";
        }
    }
    data.close();
}

void phoneNumberRegister()
{
    isTrue = true;
    int lineNumber = 1;
    fstream data;
    data.open("data.txt", ios::out | ios::in);
    while (isTrue){
        cout << "Enter your phone number:\n";
        cin >> phoneNumber;
        newUser.setPhoneNumber(phoneNumber);
        if (newUser.validPhoneNumber())
        {
            while (getline(data, line))
            {
                if (((lineNumber - 2) % 5) == 0)
                {
                    if (line == phoneNumber)
                    {
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

            if (!isTrue)
            {
                data.clear();
                data << "\n" << newUser.phoneNumber();
                cout << "Your phone number is: " << newUser.phoneNumber() << endl;
                break;
            }
        }
        else
        {
            cout << "invalid phone number. try again\n";
        }
    }
    data.close();
}

void passwordRegister()
{
    fstream data;
    data.open("data.txt", ios::app);
    while (true)
    {
        cout << "\nMake your password at least 12 characters (no spaces!) a collection of\n"
                "(capital letters, small letter, numbers and  special characters)\n"
                "to get strong password.\nEnter your password:\n";
        password = hiddenPassword();
        newUser.setPassword(password);
        while (!newUser.strongPassword())
        {
            cout << "\nMake your password at least 12 characters (no spaces!) a collection of\n"
                    "(capital letters, small letter, numbers and  special characters)\n"
                    "to get strong password.\nEnter your password:\n";
            password = hiddenPassword();
            newUser.setPassword(password);
        }
        cout << "\nEnter your password again:\n";
        repeatPassword = hiddenPassword();
        if (password == repeatPassword)
        {
            cout << "\nGreat! Two password are identical\n";
            data << "\n" << newUser.password();
            break;
        }
        else
        {
            cout << "\nTwo password are not identical. Please try again\n";
        }
    }
    data.close();
}
