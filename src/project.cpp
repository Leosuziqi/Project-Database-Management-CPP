#include <iostream>
#include "project.h"
// #include "MyForm.h" next step
// #include "libxl.h" next step

using namespace std;

project::project() {
	project_id = 99999;
	company_name = "";
	site_location = "";
	start_up_date = "0000/00/00";
	start_up_end = "0000/00/00";
}

void project::display_projects(const int& project_id) {
	//Display in terminal for test. Will create .NET forms to display

//find this project in excel
	//open excel file

	//search for matched project and display
	for (int id : id_list) {
		if (id == project_id) {
			cout << "project_id: " << project_id;
			cout << "company_name: " << id_list[col + 1];
			cout << "site_location: " << id_list[col + 2];
		}
	}
}