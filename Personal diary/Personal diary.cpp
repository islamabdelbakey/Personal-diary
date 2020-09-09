#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void welcome() {

	cout << "\n\n\n\n\t\t\t\t---------------------------------------\n\n";
	cout << "\t\t\t\t\t    Personal diary\n";
	cout << "\n\t\t\t\t---------------------------------------\n\n\n\n\n";
}
void login() {
    string passward;
    char ch;
	cout << "\t\t\t\tEnter your Passward: ";
    ch = _getch();
    while (ch != 13) {//character 13 is enter
        passward.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (passward == "0") {
        cout << "\n\n\n\n\t\t\t\tAccess Granted \n";
        cout << "\t\t\t\tPress Enter to continue........ ";
        cin.get(); 
        clear();
        int main();
    }
    else {
        cout << "\n\t\t\t\tAccess Aborted...\n";
        login();
    }
}
void menu (){
    cout << "\n\n\n\n\t\t\t\t---------------------------------------\n\n";
    cout << "\t\t\t\t\t    Personal diary\n";
    cout << "\n\t\t\t\t---------------------------------------\n\n\n\n\n";
    cout << "\t\t\t\t1- ADD STORY\n\n";
    cout << "\t\t\t\t2- VIEW STORY\n\n";
    cout << "\t\t\t\t3- EDIT STORY\n\n";
    cout << "\t\t\t\t4- DELETE STORY\n\n";
    cout << "\t\t\t\t5- EXIT\n\n";
    cout << "\n\n\t\t\t\tEnter your choise: ";
}






int main() {
    char name[10];

    int i;
    system("title Daily Personal");
	welcome();
    login();
    b:
    cout << "\n\n\n\n\t\t\t\t---------------------------------------\n\n";
    cout << "\t\t\t\t\t    Personal diary\n";
    cout << "\n\t\t\t\t---------------------------------------\n\n\n\n\n";
    cout << "\t\t\t\t1- ADD STORY\n\n";
    cout << "\t\t\t\t2- VIEW STORY\n\n";
    cout << "\t\t\t\t3- EDIT STORY\n\n";
    cout << "\t\t\t\t4- DELETE STORY\n\n";
    cout << "\t\t\t\t6- EXIT\n\n";
    cout << "\n\n\t\t\t\tEnter your choise: ";
    cin >> i;
    if (i == 1) {
        clear();
        ofstream file;
        cout << "\n\n\tEnter your file name: ";

        char name[10];

        cin.ignore();
        fgets(name, 10, stdin);
        file.open(name);
        if (!name) {
            cout << "\tError open file\n";
            goto b;
        }
        else {
            char wards[200];
            cout << "\t Enter your daily: \n";
            fgets(wards, 200, stdin);
            file << wards << "\n";
            cout << "\t--------------------------------------------------------------\n";
        }
        cin.get();
        cout << "press enter\n\n";
        clear();
        goto b;
    }

    

     if (i==2) {
         clear();
         char name[10];
         ifstream file;
         cout << "Enter your file name ";
         cin.get();
         fgets(name, 10, stdin);
         file.open(name,ios::in);
         if (!name) {
             cout << "\nerror while opening file\n";
             goto b;
         }
         else
         {
             cout << "\n\n\n\n\t........................"<<name ;
             string info;
             while (file.good())
             {
                 getline(file, info);
                 cout << info << "\n";
             }
             cout << "\n";
             file.close();
         }


     }
    
     if (i == 3) {
         clear();
         cout << "Enter name file: ";
         fstream file;
         char name[10];
         cin.ignore();
         fgets(name, 10, stdin);
         file.open(name, ios::in | ios::out);
         if (!name) {
             cout << "\n \n  error while open file\n";
             goto b;
         }
         else {
             string info;
             while (file.good())
             {
                 getline(file, info);
                 cout << info << "\n";
             }
             cout << "\n-----------------------------------------------\n";
             file.close();

         }
         file.open(name, ios::out);
         if (!name) {
             char wards[1000];
             cout << "write you want: \n\t";
             fgets(wards, 1000, stdin);
             file << wards << "\n";
         }

     }
    
   
    
    
   
     if (i==5) {
        return 0; 

     }
    
    
}