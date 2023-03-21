#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "project.h"
#include "date.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

class RecordManager
{
public:
    RecordManager() = default;

   // constructor, import project records from excel in a vector
    RecordManager(std::vector<project*>& ProjectVect);

    // destructor
    ~RecordManager();

    void AddRecord();

    void RemoveById(int id);


    // display menus
    void PrintMenu(std::map<enum RecordCmd, std::string> cmd_map);

    //search based on ID and display results
    void serach_ID();

    // search based on company name and display results
    void search_Name();

    // search based on date and display results
    void search_Date();

    // edit
    // will work on this after figuring out excel-import
    void Edit_Selection(int id);

    void SaveToFile();

    void LoadFromFile();
private:
    // Project list imported from Excel
    std::vector<project*> _projectList;
};
#endif