// Derived class from project class
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
