#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string.h>

#include "memtrace.h"

/// Using namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::atoi;

/// Functions to use at console
namespace console{

    /// Input
    // String input
    string string_input();
    // String with space input
    string string_with_space_input();
    // Char input
    char char_input();
    // Int input (Forrás: https://stackoverflow.com/questions/22818496/read-integer-from-user)
    int int_input(bool positive = false);

    /// Clear console (Forrás: https://stackoverflow.com/questions/6486289/how-can-i-clear-console)
    void Clear();

    /// Wait program to press any key (Forrás: http://www.cplusplus.com/forum/articles/7312)
    void PressAKeyToContinue();

    /// Kiírás
    // Játék címe kiírás
    void print_jatek_cim();
    // Hibas bemenet kiírás
    void print_hibas_bemenet();
    // Viszlat kiírás
    void print_viszlat();
    // Raktar cím kiírás
    void print_raktar_cim();
    // Nyertél kiírás
    void print_megnyerted(int nyero_egyenleg);

}

#endif // CONSOLE_H_INCLUDED
