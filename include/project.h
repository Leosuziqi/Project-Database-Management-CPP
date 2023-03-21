#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include "date.h"

//Base clss
class project
{
public:
	//Default constructor: create a new instance without paramters
	project();

	//Create a new instance with project_ID
	project(std::string& new_id, std::string& company_name, std::string& company_address);

	//Create a new instance with project_ID, company name and location
	project(std::string& new_id, std::string new_company_name, std::string& new_site_location, date& new_start_up_date, date& new_start_up_end);

	//Accessors
	//Display selected project with project_id. 
	//It will be used in job-search and edit functions
	virtual void display_projects();

	//Modifiers
	//Set start_up_date to given ID project
	//It will be used in job-edit functions
	virtual void edit_start_up_date(std::string& project_id, date& start_up_date);

	//Set start_up__end date to given ID project
	//It will be used in job-edit functions
	virtual void edit_start_up_end(std::string& project_id, date& start_up_end);

	//getter
	std::string get_ID() {
		return project_id;
	}

	std::string get_name() {
		return company_name;
	}

	std::string get_address() {
		return site_location;
	}

protected:
		std::string project_id;
		std::string company_name;
		std::string site_location;

		date start_up_date;
		date start_up_end;

};


// Derived class
class new_project : public project
{
public:
	//Add new project to Job Record file in Excel
	virtual void savetorecord(int& new_id, std::string& new_company_name, std::string& new_site_location, date& new_start_up_date, date& new_start_up_end);

	//Set status tag
	virtual void set_tag(const std::string& tag);


private:
	// Add a status to new project: Opened, Shipped, Handovered, Paid, and Archived
	std::string status;
};


class modification_project :
	public project
{
};


#endif 