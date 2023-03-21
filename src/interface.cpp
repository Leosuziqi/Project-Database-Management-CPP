#include "interface.h"
#include "project.h"

// initialize 
void Interface::Init()
{
    // load data from job_record.xlsx file
    manager.LoadFromFile();

    // init menu
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_PrintMenu, "Print Menu."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_PrintRecord, "Print result."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_Search_ID, "Search base on ID."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_Search_Name, "Search base on compnay name."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_Search_Date, "Search base on date."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_AddRecord, "Add a new project record."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_edit_selection, "Edit selected record."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_Save, "Save to file."));
    cmdMap.insert(std::pair<RecordCmd, std::string>(Cmd_Exit, "Exit"));
}


// run operations based on commands
bool Interface::HandleCmd(const RecordCmd cmd)
{
    auto iter = cmdMap.find(cmd);
    if (iter == cmdMap.end()) {
        std::cout << "NOT FOUND" << std::endl;
        return true;
    }

    switch (cmd)
    {
    case Cmd_PrintMenu: manager.PrintMenu(cmdMap); break;
    //case Cmd_PrintRecord: manager.PrintAllRecords(); break;
    case Cmd_Search_ID: manager.serach_ID(); break;
    case Cmd_Search_Name: manager.search_Name(); break;
    case Cmd_Search_Date: manager.search_Date(); break;
    case Cmd_AddRecord: manager.AddRecord(); break;
    case Cmd_edit_selection: {
        int edit_id;
        std::cout << "Project ID to Edit:";
        std::cin >> edit_id;
        manager.Edit_Selection(edit_id); break;
    case Cmd_Save: manager.SaveToFile(); break;
    case Cmd_Exit: return false;
    default: break;
    }

    return true;
}