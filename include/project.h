#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <date.h>

using namespace std;

//Base clss
class project
{
	//friend: read new created project
	friend void read(istream &inputStream, project& project);

public:
	//Default constructor: create a new instance without paramters
	project();

	//Create a new instance with project_ID
	project(int& new_id) : project() {
		project_id = new_id;
	};

	//Create a new instance with project_ID, company name and location
	project(const int new_id = (int)0, const string new_company_name, const string& new_site_location, const date& new_start_up_date, const date& new_start_up_end) : project() {
		project_id = new_id;
		company_name = new_company_name;
		site_location = new_site_location;
		start_up_date = new_start_up_date;
		start_up_end = new_start_up_end;
	};

	//Accessors
	//Display selected project with project_id. 
	//It will be used in job-search and edit functions
	virtual void display_projects(const int& project_id);

	//Modifiers
	//Set start_up_date to given ID project
	//It will be used in job-edit functions
	virtual void edit_start_up_date(int& project_id, date& start_up_date);

	//Set start_up__end date to given ID project
	//It will be used in job-edit functions
	virtual void edit_start_up_end(int& project_id, date& start_up_end);


protected:
		int project_id;
		string company_name;
		string site_location;

		date start_up_date;
		date start_up_end;

};


// Derived class
class new_project : public project
{
public:
	//Add new project to Job Record file in Excel
	virtual void savetorecord(int& new_id, string& new_company_name, string& new_site_location, date& new_start_up_date, date& new_start_up_end);

	//Set status tag
	virtual void set_tag(const string& tag);


private:
	// Add a status to new project: Opened, Shipped, Handovered, Paid, and Archived
	string status;
};


#endif 
