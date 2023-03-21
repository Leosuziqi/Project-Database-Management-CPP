#include "interface.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    // initialize a command homepage 
    Interface homepage;
    homepage.Init();
    // display all menu
    homepage.PrintMenu();

    cout << "New Command:";

    // main loop
    int cmd;
    while (cin >> cmd)
    {
        if (cin.good())
        {
            bool exitCode = homepage.HandleCmd((RecordCmd)cmd);
            if (!exitCode)
                return 0;
        }

        cout << "-------------------------" << endl;
        cout << "New Command:";

        cin.clear();
        cin.ignore();
    }

    fstream file;
    file.open("./test.dat", ios::out | ios::binary);
    string a("hello");
    string b;
    file.write(reinterpret_cast<char*>(&a), sizeof(a));
    file.close();
}
