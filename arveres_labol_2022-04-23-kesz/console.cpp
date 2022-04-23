
#include "console.h"


/// Input
// String input
string console::string_input(){
    string bemenet;
    cin >> bemenet;
    cin.clear();
    cin.ignore( 100 , '\n' );
    return bemenet;
}
// String with space input
string console::string_with_space_input(){
    string bemenet;
    getline(cin , bemenet);
    return bemenet;
}
// Char input
char console::char_input(){
    string bemenet;
    getline(cin , bemenet);
    return tolower(bemenet[0]);
}
// Int input (Forrás: https://stackoverflow.com/questions/22818496/read-integer-from-user)
int console::int_input(bool positive){
        char input[8];
        cin >> input;
        int x = atoi(input);
        while( (x == 0 && strcmp(input, "0")) || (positive && x<0) ) {
            cin.clear ();
            cin.ignore ( 100 , '\n' );
            cout << "Rossz bemenet. Adj meg egy SZAMOT: ";
            cin >> input;
            x = atoi(input);
        }
        cin.clear ();
        cin.ignore ( 100 , '\n' );

    return x;
}

/// Clear console (Forrás: https://stackoverflow.com/questions/6486289/how-can-i-clear-console)
void console::Clear(){
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
    #else
    for(int i=0; i<30; i++) std::cout << std::endl;
    #endif
}

/// Wait program to press any key (Forrás: http://www.cplusplus.com/forum/articles/7312)
void console::PressAKeyToContinue(){
    #ifndef CPORTA
        cout << endl << " Press a key to continue...";
        int c = getch();
        if (c == 0 || c == 224) getch();
    #endif
}

/// Kiírás
// Játék címe kiírás
void console::print_jatek_cim(){
    std::cout << R"(
  _ _   __   ____   __   _  _ ____ ____ ____      __   ____ _  _ ____ ____ ____ ___
 ( / ) /__\ (  _ \ /__\ ( )/ (_  _( ___(  _ \    /__\ (  _ ( \/ ( ___(  _ ( ___/ __)
  ) ( /(__)\ )   //(__)\ )  (  )(  )__) )   /   /(__)\ )   /\  / )__) )   /)__)\__ \
 (_\_(__)(__(_)\_(__)(__(_)\_)(__)(____(_)\_)  (__)(__(_)\_) \/ (____(_)\_(____(___/
====================================================================================
)";
}
// Hibas bemenet kiírás
void console::print_hibas_bemenet(){
    Clear();
    cout << R"(
  _  _  ___  ____     _     ____      ____   _____  __  __  _____  _   _  _____  _____
 |  | ||_ _|| __ )   / \   / ___|    | __ ) | ____||  \/  || ____|| \ | || ____||_   _|
 | _| | | | |  _ \  / _ \  \___ \    |  _ \ |  _|  | |\/| ||  _|  |  \| ||  _|    | |
 | _  | | | | |_) |/ ___ \  ___) |   | |_) || |___ | |  | || |___ | |\  || |___   | |
 |_ |_||___||____//_/   \_\|____/    |____/ |_____||_|  |_||_____||_| \_||_____|  |_|
)";

    cout << "========================================================================================" << endl;
    cout << setw(20) << "" << "A felteteleknek nem megfelelo inputot adtal meg." << endl;
    cout << setw(28) << "" << "Menj vissza es probald meg ujra!" << endl;
    console::PressAKeyToContinue();
    Clear();
}
// Viszlat kiírás
void console::print_viszlat(){
    cout << R"(
 __    __  _               _           _     _
 \    / / (_)  ___   ____ | |   __ _  | |_  | |
  \\ / /  | | / __| |_  / | |  / _` | | __| | |
    V /   | | \__ \  / /  | | | (_| | | |_  |_|
   \_/    |_| |___/ /___| |_|  \__,_|  \__| (_)
)" << endl;
}
// Raktar cím kiírás
void console::print_raktar_cim(){
    cout << R"(
  ___            _      _
 | _ \    __ _  | | __ | |_    __ _   _ __
 | _) |  / _` | | |/ / | __|  / _` | | '__|
 | _ <  | (_| | |   <  | |_  | (_| | | |
 |_ \_\  \__,_| |_|\_\  \__|  \__,_| |_|
)";
    cout << "===========================================" << endl;
}
// Nyertél kiírás
void console::print_megnyerted(){
        cout << R"(
  _   _                         _            _     _   _   _
 | \ | |  _   _    ___   _ __  | |_    ___  | |   | | | | | |
 |  \| | | | | |  / _ \ | '__| | __|  / _ \ | |   | | | | | |
 | |\  | | |_| | |  __/ | |    | |_  |  __/ | |   |_| |_| |_|
 |_| \_|  \__, |  \___| |_|     \__|  \___| |_|   (_) (_) (_)
          |___/
)";
    }

