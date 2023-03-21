#include "project_manager.h"
#include "project.h"
#include <map>

// constructor, import project records from excel in a vector
RecordManager::RecordManager(std::vector<project*>& progectVect)
{
    _projectList = progectVect;
}

// display menus
void RecordManager::PrintMenu(std::map<enum RecordCmd, std::string> cmd_map)
{
    std::cout << "------------------Available Operations:------------------" << std::endl;
    for (auto iter = cmd_map.begin(); iter != cmd_map.end(); iter++)
        std::cout << iter->first << ":" << iter->second << std::endl;
}

//search based on ID and display results
void RecordManager::serach_ID() {
    std::string search_id;
    std::cout << "Enter ID to search: ";
    std::cin >> search_id;
    for (project* item : _projectList) {
        if (item->get_ID() == search_id) {
            item->display_projects();
        }
    }
}

// search based on company name and display results
void RecordManager::search_Name() {
    std::string search_name = "";
    std::cout << "Enter NAME to search: ";
    std::cin >> search_name;
    for (project* item : _projectList) {
        if (item->get_name() == search_name) {
            item->display_projects();
        }
    }
}

// search based on date and display results
void RecordManager::search_Date() {
    char* date_string;
    Csv::multitype& search_date;
    std::cout << "Enter DATE to search: ";
    std::cin >> date_string;
    search_date = date::string_to_time(search_date);
    // date format need to be decided
    for (project* item : _projectList) {
        if (item->get_address() == date_string) {
            item->display_projects();
        }
    }
}

// edit
// will go deep into this after figuring out excel-import
void RecordManager::Edit_Selection(int id) {
    RecordManager::RemoveById(id);
    RecordManager::AddRecord();
    RecordManager::SaveToFile();
}

// add a new record
void RecordManager::AddRecord(){
    std::cout << "Enter Project ID：";
    int new_ID;
    std::cin >> new_ID;

    std::cout << "Enter Client's Name：";
    std::string company_name;
    std::cin >> company_name;

    std::cout << "Enter Client's Address：";
    std::string company_addr;
    std::cin >> company_addr;
    project* p = new project(new_ID, company_name, company_addr);

    _projectList.push_back(p);
}


// remove by id
void RecordManager::RemoveById(int id)
{
    // find row
    int len = _projectList.size();
    int id_to_reomve;
    for (int i = 0; i < len; i++)
    {
        if (_projectList[i]->get_ID() == id) {
            id_to_reomve = i;
            break;
        }
    }
    //remove record
    if (id_to_reomve != -1)
    {
        delete _projectList[id_to_reomve];
        auto iter = _projectList.begin() + id_to_reomve;
        _projectList.erase(iter);
    }
}

// save to excel file
void RecordManager::SaveToFile()
{
    // will work on it later
}

void RecordManager::LoadFromFile()
{
    // will work on it later
}