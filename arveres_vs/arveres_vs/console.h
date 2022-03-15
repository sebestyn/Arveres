#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

/// Includes
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "memtrace.h"


using std::cout;
using std::endl;

namespace console{

    /// Clear console
    // Forrás: https://stackoverflow.com/questions/6486289/how-can-i-clear-console
    void Clear(){
        #if defined _WIN32
            system("cls");
            //clrscr(); // including header file : conio.h
        #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            system("clear");
            //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
        #elif defined (__APPLE__)
            system("clear");
        #endif
    }

    /// Wait program to press any key
    // Forrás: http://www.cplusplus.com/forum/articles/7312/
    void PressAKeyToContinue(){
          cout << endl << "Press a key to continue..." << endl;
          //int c = getch();
          //if (c == 0 || c == 224) c = getch();
    }
}

#endif // CONSOLE_H_INCLUDED
