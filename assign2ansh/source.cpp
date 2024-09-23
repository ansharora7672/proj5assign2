#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct STUDENT_DATA {
	string firstname;
	string lastname;

	// added this email because we had to add the email to the student input data.
	string email;
};

int main() {

	//opening and reading the file having student names first and last name.
	ifstream file("..\\StudentData.txt");
	//making the vector of type STUDENT_DATA to store the student details.
	vector<STUDENT_DATA> student_data;
	string line;

	while (getline(file, line))
	{
		istringstream iss(line);
		STUDENT_DATA student;
		//taking data line by line seperated by comma and storing it in firstname , lastname
		getline(iss, student.firstname, ',');
		getline(iss, student.lastname);

		// adding the data i.e names of students first and last name
		student_data.push_back(student);
	}

	file.close();


#ifdef _DEBUG
	for (int i = 0; i < student_data.size(); i++)
	{
		cout << "First Name: " << student_data[i].firstname << ", Last Name: " << student_data[i].lastname << endl;
	}
#endif



#ifdef PRE_RELEASE
	//opening and reading the file having emails.
    ifstream file2("..\\StudentData_Emails.txt");

    while (getline(file2, line))
    {
        istringstream iss(line);
        string email, firstname, lastname;
		
		//taking data line by line seperated by comma and storing it in firstname , lastname and the last attribute to email
		getline(iss, firstname, ',');
        getline(iss, lastname, ',');
        getline(iss, email);

		//checking for the first and last anem witht eh vector we have and then adding the email to the corresponding name. did this to just be sure..
        for (int i = 0; i < student_data.size(); ++i)
		{
			//check for correctness
			if (student_data[i].firstname == firstname && student_data[i].lastname == lastname)
			{
				//add the email
				student_data[i].email = email;
				break;
			}
        }
    }

	//close the file
    file2.close();

	//print is not asked but I did too just see 
    for (int i = 0; i < student_data.size(); i++) 
	{
        cout << "First Name: " << student_data[i].firstname << ", Last Name: " << student_data[i].lastname << ", Email: " << student_data[i].email << endl;
    }

#endif

	
	return 1;

}