#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <fstream>

using namespace std; 
const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
// PART 1A: Create the data struct

struct patientInfo{ // create a struct for the object of patientInfo
    int age; // set age to be of type int
    int id; // set id to be of type int
    char firstName[MAX_NAME_LENGTH]; // set firstName to be of type char array
    char lastName[MAX_NAME_LENGTH]; // set lastName to be of type char array
    char sex; // set sex to be of type char
};

int main()
{
    // PART 1B: Read the patient record
    patientInfo record[NUM_PATIENTS]; // instantiate a patientInfo record of size Num_Patients

    ifstream input("patientInfo.txt"); // input the given patientInfo text file

    for (int i=0; i < NUM_PATIENTS; i++){ // set each patient within the textfile to have it's own unique index of the record array
        input >> record[i].age; // establish pointers to point to a record index's (patient's) age attributes
        input >> record[i].id;
        input >> record[i].firstName;
        input >> record[i].lastName;
        input >> record[i].sex;
        
    }
    input.close(); // close the ifstream

    // PART 2: Select a primary sorting category from user input
    const int MAX_LENGTH = 6; // set the max length for user input to be 6, for 'First' + '\0', which is the greatest input available
    char userInput[MAX_LENGTH]; // initialize the userInput character array
    bool stopper = false; // set stopper flag to be false for while loop error checking
    int field; // create a field to handle cases for the various sorts

    cout << "Please input a category to sort patient records by." << endl << "Options (case sensitive) are Age, ID, First, Last, Sex: "; // output text to screen

    while (!stopper) { // while stopper is false, (runs on first iteration)
        cin >> userInput; // get user input, (several times if necessary)

        if (strcmp(userInput, "Age")==0){ // string compares user input to "Age"
            cout << "Case 1, sorting by Age." << endl << endl; // output text to tell user what sort is being performed
            field = 1; // establish a field to enter the bubble sort for case 1 in part 4/5
            stopper = true; // escape the loop
        }
        else if (strcmp(userInput, "ID")==0){ // * refer to case 1
            cout << "Case 2, sorting by ID." << endl << endl;
            field = 2;
            stopper = true;
        }
        else if (strcmp(userInput, "First")==0){ // * refer to case 1 (alteration of case# made from assignment for order of struct instead)
            cout << "Case 3, sorting by First Name." << endl << endl;
            field = 3;
            stopper = true;
        }
        else if (strcmp(userInput, "Last")==0){ // * refer to case 1 (alteration of case# made from assignment for order of struct instead)
            cout << "Case 4, sorting by Last Name." << endl << endl;
            field = 4;
            stopper = true;
        }
        else if (strcmp(userInput, "Sex")==0){ // * refer to case 1 (alteration of case# made from assignment for order of struct instead)
            cout << "Case 5, sorting by Sex."<< endl << endl;
            field = 5;
            stopper = true;
        }
        else { // if none of desired cases are inputted, reenter the loop)
            cout << "Unexpected input, Please input either Age, ID, First, Last, or Sex: "; // informs user of bad input
            stopper = false; // reenters the loop
        }
    }

// PART 4/5: Sorting patient records
    for (int n=0; n < NUM_PATIENTS - 1; n++){ // general case bubble sort algorithm
        for (int k=0; k < NUM_PATIENTS-n-1; k++){ // general case bubblle sort algorithm

// Case 1, sorting by age.
            if (field == 1) { // if "Age" was typed, then bubble sort by age
            
                if (record[k].age > record[k+1].age){ // compare patients by age, by accessing their age pointers
                    patientInfo temp = record[k +1]; // set temporary variable of type patientInfo to following element
                    record[k+1] = record[k]; // swap by type patientInfo, set following element to previous element
                    record[k] = temp; // swap by type patientInfo, set previous element to following element (temp)
                }
                else if (record[k].age == record[k+1].age){ // if patients's age is the same, use first-name tie brake
                    if (strcmp(record[k].firstName, record[k+1].firstName) > 0) { // use string compare to check for the sort
                        patientInfo temp = record[k +1]; // repeat algorithm as described above
                        record[k+1] = record[k];
                        record[k] = temp;
                    }
                }
            }

// Case 2, sorting by ID.
            if (field == 2) { // refer to sort by age
                if (record[k].id > record[k+1].id){
                    patientInfo temp = record[k +1];
                    record[k+1] = record[k];
                    record[k] = temp;
                }
                else if (record[k].id == record[k+1].id){
                    if (strcmp(record[k].firstName, record[k+1].firstName) > 0) {
                        patientInfo temp = record[k +1];
                        record[k+1] = record[k];
                        record[k] = temp;
                    }
                }
            }

// Case 3, sorting by First Name.

            if (field == 3 && strcmp(record[k].firstName, record[k+1].firstName) > 0) { // refer to sort by age, uses stringcompare
                patientInfo temp = record[k +1];
                record[k+1] = record[k];
                record[k] = temp;
            }

// Case 4, sorting by Last Name.

            if (field == 4){
                if (strcmp(record[k].lastName, record[k+1].lastName) > 0) { // refer to sort by age, uses stringcompare
                    patientInfo temp = record[k +1];
                    record[k+1] = record[k];
                    record[k] = temp;
                }
                else if (strcmp(record[k].lastName, record[k+1].lastName) == 0) {
                    if (strcmp(record[k].firstName, record[k+1].firstName) > 0) {
                        patientInfo temp = record[k +1];
                        record[k+1] = record[k];
                        record[k] = temp;
                    }
                }
            }


// Case 5, sorting by Sex
            if (field == 5){ // refer to sort by age
                if (record[k].sex > record[k+1].sex){
                    patientInfo temp = record[k +1];
                    record[k+1] = record[k];
                    record[k] = temp;
                }
                else if (record[k].sex == record[k+1].sex){
                    if (strcmp(record[k].firstName, record[k+1].firstName) > 0) {
                        patientInfo temp = record[k +1];
                        record[k+1] = record[k];
                        record[k] = temp;
                    }   
                }
            }
        }
    }
    
    // PART 3: Outputting patient records to terminal in tabular form
    cout << setw(15) << "Age:"; // output age, to be alligned to the right with other headings
    for (int i=0; i < NUM_PATIENTS; i++){ // for the number of patients, output each patients age in line with the header
        cout << setw(10) << record[i].age;
    }
    cout << endl; // create a space for the next header

    cout << setw(15) << "ID:"; // refer to age
    for (int i=0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].id;
    }
    cout << endl;

    cout << setw(15) << "First Name:"; // refer to age
    for (int i=0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].firstName;
    }
    cout << endl;

    cout << setw(15) << "Last Name:"; // refer to age
    for (int i=0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].lastName;
    }
    cout << endl;

    cout << setw(15) << "Sex:"; // refer to age
    for (int i=0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].sex;
    }
    cout << endl;

    return 0;
}