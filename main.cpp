#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include "string"
using namespace std;

char *encrypt(char *plaintext, int key);
char *decrypt(char *plaintext, int key);

int main()
{
    // Define variable
    char *msg;
    string temp;
    int key, choice;\

    cout<<"What do you need ? \n 1.Encrypt (sample.txt) \n 2.Decrypt (encrypt.txt)"<<endl;
    cin >> choice;

    /*
    if (choice != 1 || choice != 2) {
    cout<<"Don't choice anything else i don't have =="<<endl;
    exit(2000);
    }
    */

    if (choice == 1)
    {
        // Read file
        ifstream ifs("sample.txt");

        // read and write file ourput
        ofstream output;                     // khai bao ten file ghi
        output.open("output.txt", ios::out); // mo file ghi bang ofstream
        // get Key
        cout << "Enter your key: ";
        cin >> key;

        // get line in input file
        while (getline(ifs, temp))
        {
            cout << "Your plaintext is: " << temp << endl;
            // convert string to char*
            char *str = &temp[0];
            // Using encrypt
            output << encrypt(str, key) << endl;
        }
        cout << "Your encrypt is: " << temp;
    }
    else if (choice == 2)
    {
        ifstream ifs("encrypt.txt");
        ofstream out;
        out.open("decrypt.txt", ios::out);

        // get Key
        cout << "Enter your key: ";
        cin >> key;

        while (getline(ifs, temp))
        {
            cout << "Your plaintext is: " << temp << endl;
            // convert string to char*
            char *str = &temp[0];
            // Using encrypt
            out << decrypt(str, key) << endl;
        }
        cout << "Your decrypt is: " << temp;
    }

    cout << "Press any key to close console"<<endl;
    system("pause");
    return 0;
}

char *encrypt(char *plaintext, int key)
{
    char ch;
    for (int i = 0; plaintext[i] != '\0'; ++i)
    {
        ch = plaintext[i];
        // encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            plaintext[i] = ch;
        }
        // encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            plaintext[i] = ch;
        }
    }
    return plaintext;
}
char *decrypt(char *plaintext, int key)
{
    char ch;
    for (int i = 0; plaintext[i] != '\0'; ++i)
    {
        ch = plaintext[i];
        // decrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            plaintext[i] = ch;
        }
        // decrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            plaintext[i] = ch;
        }
    }
    return plaintext;
}
