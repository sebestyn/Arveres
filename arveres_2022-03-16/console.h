#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

/// Includes
#include <iostream>
#include <string>

/// Using namespaces
using std::cin;
using std::cout;
using std::string;

/// Functions to use at console
namespace console{

    /// String input
    string string_input(){
        string bemenet;
        cin >> bemenet;
        return bemenet;
    }

    /// Char input
    char char_input(){
        //char bemenet[100] = {'0', '\0'};
        string bemenet;
        cin >> bemenet;
        return bemenet[0];
    }

    /// Clear console
    // Forrás: https://stackoverflow.com/questions/6486289/how-can-i-clear-console
    void Clear(){
        #ifndef CPORTA
            #if defined _WIN32
                system("cls");
                //clrscr(); // including header file : conio.h
            #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                system("clear");
                //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
            #elif defined (__APPLE__)
                system("clear");
            #endif
        #endif
    }

    /// Wait program to press any key
    // Forrás: http://www.cplusplus.com/forum/articles/7312/
    void PressAKeyToContinue(){
        #ifndef CPORTA
              cout << endl << "Press a key to continue..." << endl;
              int c = getch();
              if (c == 0 || c == 224) getch();
         #endif
    }
}

#endif // CONSOLE_H_INCLUDED
