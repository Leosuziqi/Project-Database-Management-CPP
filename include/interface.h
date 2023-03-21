#ifndef INTERFACE_H
#define INTERFACE_H
#include "project_manager.h"
#include <map>
#include <string>


using namespace std;

class Interface
{
public:
    Interface() = default;

    // initialize with date from excel file
    void Init();

    // print menu
    void PrintMenu();

    // run command operations listed below in  RecordCmd
    bool HandleCmd(const RecordCmd cmd);

private:
    RecordManager manager;

    // use map to save commands
    std::map<enum RecordCmd, std::string> cmdMap;
};

enum RecordCmd
{
    // print menu
    Cmd_PrintMenu,

    // print record
    Cmd_PrintRecord,

    // Search and find record base on project ID
    Cmd_Search_ID,

    // Search and find record base on company name
    Cmd_Search_Name,

    // Search and find record base on start date
    Cmd_Search_Date,

    // add a new project record
    Cmd_AddRecord,

    // remove record with ID
    Cmd_RemoveCourse,

    // edit selected record
    Cmd_edit_selection,

    // save changes
    Cmd_Save,

    // exit
    Cmd_Exit
};
#endif