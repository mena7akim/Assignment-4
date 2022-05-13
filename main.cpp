#include <bits/stdc++.h>
#include <vector>
#include <string>
#include<iostream>
#include<fstream>
#include <stdio.h>


using namespace std;


void empty_file (fstream &file2, string filename2)
{
    file2.open(filename2, ios::out | ios::trunc);
    file2.close();
}


void isFileExists(fstream &file,string fileName){
    if (filesystem::exists(fileName))
    {
        cout << "This File Already Exists\n";
    }
    else
    {
        cout << "This is a new file. I created it for you\n";
    }
    file.open(fileName, ios::app);
    file.close();
}

void addToFile(fstream &file, string fileName){
    string text;
    file.open(fileName, ios::app);
    cout << "Enter the text you want to append or (eof) to exit:\n";
     cin.ignore();
    while (true){
        getline(cin, text);

        if(text=="eof"){
            break;
        }
        file << text << endl;
    }
    file.close();
}

void displayContent(fstream &file, string fileName){
    string line;
    file.open(fileName, ios::out | ios::in);
    if (filesystem::file_size(fileName)==0){
        cout << "File is empty";
    }
    else{
        while(getline(file, line)){
            cout << line << endl;
        }
    }
    file.close();
}

void deleteFileContent(fstream &file, string fileName){
    file.open(fileName, ios::out | ios::trunc);
    file.close();
}

void encryptFile(fstream &file, string fileName,fstream &file2 ,string filename2){
    string line, encryptedText = "";
    file.open(fileName, ios::in);
    while (getline(file,line)){
        for(int i = 0; i < line.size(); i++){
            encryptedText += (char)(line[i]+1);
        }
        encryptedText += "\n";
    }
    file.close();
    file2.open(filename2, ios::out);
    file2 << encryptedText;
    file2.close();
}

void decryptFile(fstream &file, string fileName, fstream &file2 ,string filename2){
    string line, decryptedText = "";
    file.open(fileName, ios::in);
    while (getline(file,line)){
        for(int i = 0; i < line.size(); i++){
            decryptedText += (char)(line[i]-1);
        }
        decryptedText += "\n";
    }
    file.close();
    file2.open(filename2, ios::out);
    file2 << decryptedText;
    file2.close();
}

void mergeFile(fstream &file, string fileName) {
    char file2Name[50], text;
    cout << "Enter the name of file you want to merge: \n";
    cin >> file2Name;
    fstream file2;
    strcat(file2Name, ".txt");
    file2.open(file2Name, ios::in);
    if (!file2) {
        cout << "Enter an exist file!\n";
    } else {
        file.open(fileName, ios::app);
        while (file2 >> noskipws >> text)
            file << text;
        file << "\n";
        cout << "TWO files are merged! \n";
    }
    file2.close();
    file.close();
}

void NumberOfWords(fstream &file, string fileName) {
    file.open(fileName, ios::in);
    int count = 0;
    char word[50];
    // check whether we have reached the End-Of-File(EOF) character in a file or not
    while (!file.eof()){
        file >> word;
        count ++;
    }
    cout << "number os words is " << count-1 << ".\n";
    file.close();
}

void NumberOfCharacters(fstream &file, string fileName){
    file.open(fileName, ios::in);
    int count = 0;
    char character;
    while (!file.eof()){
        while (file >> character)
        {
         ++count;
        }
    }
    cout << "number os characters is " << count << ".\n";
    file.close();
}

void NumberOfLines(fstream &file, string fileName) {
    file.open(fileName, ios::in);
    int count = 0;
    string line;
    while (!file.eof()) {
        getline(file,line);
        count++;
    }
    cout << "number of lines is " << count << ".\n";
    file.close();
}

void SearchForAWord(fstream &file, string fileName) {
    file.open(fileName, ios::in);
    string search;
    string line;
    int word;
    cout << "what is the word you want to search about? \n";
    cin >> search;
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            word = line.find(search, 0);
            if (word != string::npos) {
                cout << "Word was found in the file \n";
                break;
            } else {
                cout << "Word was not found in the file \n";
                break;
            }
        }
    }
     file.close();
}

void num_of_word_existence(fstream &file, string fileName) {
    file.open(fileName, ios::in);
    string countword  ;
    int count = 0;
    string word;
    cout<<"please enter the word wanted to count:";
    cin >> countword ;
    for (int i=0 ; i<countword.size() ; i++)
    {
        countword[i]=toupper(countword[i]); 
    }

    while (file >> word){
        for(int i=0 ;i<word.size () ; i++)
        {
            word[i]=toupper(word[i]);
        }
        // cout <<word;
        if (word==countword)
        count ++;
    }
    cout << "number of the word at file " <<  "="<< count << ". \n \n \n";
    file.close();
}





void uppercasefile(fstream &file,fstream &file2 ,string fileName,string filename2) {
    file.open(fileName, ios::in);
    string word ,uppercasewords;
    char c;
     while (getline(file,word))
     {
 
         for (int i=0 ;i<word.size () ;i++) 
         {
        c=toupper(word[i]);
        uppercasewords+=c;


         }
         uppercasewords += "\n";
     }
     
     file.close();
      file2.open(filename2, ios::out);
      file2 << uppercasewords ;
      file2.close();

}

void lowercasefile(fstream &file, string fileName,fstream &file2 ,string filename2) {
    file.open(fileName, ios::in);
    
    string temp, lowewords;
    char c;
    while(getline(file ,temp))
    {
        for (int i=0 ; i<temp.size() ; i++)
        {
            c=tolower(temp[i]);
             lowewords+=c;

        }
        lowewords += "\n";

    }
      file.close();
       file2.open(filename2, ios::out);
      file2 <<  lowewords;
      file2.close();



}

void First_Caps_File(fstream &file, string fileName,fstream &file2 ,string filename2) {
    file.open(fileName, ios::in);
    string temp ,temp2 ;
    while(getline(file ,temp))
    {
        temp[0] = toupper(temp[0]);
          temp2+=temp[0];
        for(int i = 0; i <temp.size()-1; i++)
        {
        if (isspace(temp[i])){
            temp2+=" ";
            temp[i+1] = toupper(temp[i+1]);
            i++;
        
        }
        else {
            temp[i] = tolower(temp[i]);
        }
        temp2+=temp[i];
        } 
        temp2+="\n";
    }
      file.close();
      file2.open(filename2, ios::out);
      file2 <<  temp2;
      file2.close();

}

void save_function (fstream &file,fstream &file2 ,string fileName ,string filename2,fstream &file3 ,string filename3)
{
    int save_choice;
    cout <<"would u like to save the changes at the same file or another one? \n 1_same \n 2_another file";
    cin>> save_choice ;
    if (save_choice==1)
    {
        label:
            file.close();
            file.open(fileName,ios::out);

            file2.close();
            file2.open(filename2,ios::in);

      while (!file2.eof())
       {
        string s;
        getline(file2,s);
		file << s << '\n';
	  }
      file.close();
      file2.close();
    }
    else if (save_choice==2)
    {
      
        cout<<"please enter file name:";
        // cin>>filename3 ;
            file3.close();
            file3.open(filename3,ios::out);

            file2.close();
            file2.open(filename2,ios::in);

      while (!file2.eof())
            {
             string s;
             getline(file2,s);
		     file3 << s << '\n';
	        }
             file3.close();
             file2.close();
    }
    empty_file (file2,filename2);
    
}

int main()
{
    int textOption;
    fstream file2("data.txt") ;

    fstream file3 ;
    char fileName[50], filename2[50]= "data.txt" , filename3[50];
    cout << "Enter the file name:\n";
    cin.getline(fileName,50);
    fstream file;
    strcat(fileName, ".txt");
    isFileExists(file, fileName);
    while (true){
        cout << "1. Add new text to the end of the file \n"
                "2. Display the content of the file\n"
                "3. Empty the file\n"
                "4. Encrypt the file content \n"
                "5. Decrypt the file content\n"
                "6. Merge another file\n"
                "7. Count the number of words in the file.\n"
                "8. Count the number of characters in the file\n"
                "9. Count the number of lines in the file\n"
                "10. Search for a word in the file\n"
                "11. Count the number of times a word exists in the file\n"
                "12. Turn the file content to upper case.\n"
                "13. Turn the file content to lower case.\n"
                "14. Turn file content to 1st caps (1st char of each word is capital) \n"
                "15. Save\n"
                "16. Exit\n";
        cin >> textOption;
        switch (textOption) {
            case 1:
                addToFile(file, fileName);
                break;
            case 2:
                displayContent(file,fileName);
                break;
            case 3:
                deleteFileContent(file,fileName);
                break;
            case 4:
                encryptFile(file, fileName,file2 ,filename2);
                break;
            case 5:
                decryptFile(file,fileName,file2 ,filename2);
                break;
            case 6:
                mergeFile(file,fileName);
                break;
            case 7:
                NumberOfWords(file,fileName);
                break;
            case 8:
                NumberOfCharacters(file, fileName);
                break;
            case 9:
                NumberOfLines(file, fileName);
                break;
            case 10:
              SearchForAWord(file,fileName);
                break;
            case 11:
               num_of_word_existence(file, fileName);
                 break;
            case 12:
                uppercasefile(file, file2 ,fileName , filename2 ) ;
                  break;
            case 13:
                lowercasefile(file,fileName,file2 ,filename2);
                   break;
           case 14:
            First_Caps_File(file,fileName,file2 ,filename2);
            break;
            case 15 :
             save_function (file,file2 ,fileName,filename2,file3 , filename3);
             break;

        }
        if (textOption == 16){
        remove(filename2);
            break;
        }
    }
}


