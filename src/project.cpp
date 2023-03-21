#include <iostream>
#include "project.h"
// #include "MyForm.h" next step
// #include "libxl.h" next step


project::project() {
	project_id = 99999;
	company_name = "";
	site_location = "";
}

//Create a new instance with project_ID
project::project(std::string& new_id, std::string& company_name, std::string& company_address) {
	project_id = new_id;
	company_name = company_name;
	site_location = company_address;
};

//Create a new instance with project_ID, company name and location
project::project(std::string& new_id, std::string new_company_name, std::string& new_site_location, date& new_start_up_date, date& new_start_up_end) {
	project_id = new_id;
	company_name = new_company_name;
	site_location = new_site_location;
	start_up_date = new_start_up_date;
	start_up_end = new_start_up_end;
};


//Display in terminal for test. Will create .NET forms to display
void project::display_projects() {
	std::cout << project_id;
	std::cout << company_name;
	std::cout << site_location;
	start_up_date.display_date();
	start_up_end.display_date();
}

//find this project in excel
	//open excel file

void edit_start_up_date(std::string& project_id, date& start_up_date) {

}

//Set start_up__end date to given ID project
//It will be used in job-edit functions
void edit_start_up_end(std::string& project_id, date& start_up_end) {

}
