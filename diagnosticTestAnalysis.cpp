//Jahkim Brown-Roopnarine
// BME121

# include <iostream>
# include <cmath>
using namespace std;

// iniatialize requested variables as global variables
float TPR = 0;
float FPR = 0;
float score = 0;
float bestScore = 0; 
int bestScoreTest = 0;
int counter = 1 ; // set the first diagnostic test to 1.
bool TPRTerminator = false; // handles bug for if TPR is 0 from the user, we still need to know to exit code if double negative case occurs.
bool FPRTerminator = false; // "prev. comment applies"

// generalize a function to get a TPR input from the user
int getTPR(){  

    cout << "Please enter the diagnostic test's true positive rate: ";      // request input from the user
    cin >> TPR;

    if (cin.fail()){        // check if type entered is not a float
        cerr << "Warning: invalid input to true positive rate. Please enter a numeric input."<< endl; // print message asking user to reinput the data.
        cin.clear();
        cin.ignore(100, '\n');
        return getTPR();
        // clear value and recursively call function
    }

    if (TPR > 1){        // checks if numeric value is greater than one.
        cout << "Warning: invalid input to true positive rate. Please enter an input <=1." << endl; // print message asking user to reinput the data.
        cin.clear();
        cin.ignore(100, '\n');
        return getTPR();
        // clear value and recursively call function

    }
    else if (TPR < 0) {     // checks if numeric value is less than 0.
        TPR = 0;        // set input value equal to 0
        TPRTerminator = true; // set exit clause to true
        return 0;       // exit function
    }
    else if ((TPR >= 0 & TPR <= 1)) {       // if input is in desired range
        TPR = TPR;      // set input to be what was inputted
        return 0;       // exit function
    }
    else    // will catch edge case if bug in code.
    cout << "Bug here.";
    return -1;
}

int getFPR(){

    cout << "Please enter the diagnostic test's false positive rate: ";     // request input from the user
    cin >> FPR;

    if (cin.fail()){        // check if type entered is not a float
        cerr << "Warning: invalid input to false positive rate. Please enter a numeric input."<< endl; // print message asking user to reinput the data.
        cin.clear();
        cin.ignore(100, '\n');
        return getFPR();
        // clear value and recursively call function
    }

    if (FPR > 1){ // checks if numeric value is greater than one.
        cout << "Warning: invalid input to false positive rate. Please enter an input <=1." << endl; // print message asking user to reinput the data.
        cin.clear();
        cin.ignore(100, '\n');
        return getFPR();
        // clear value and recursively call function

    }
    else if (FPR < 0) { // checks if numeric value is less than 0.
        FPR = 0; // set input equal to 0
        FPRTerminator = true; // set exit clause to true.
        return 0; // exit function
    }
    else if ((FPR >= 0 & FPR <= 1)){       // if input is in desired range
        FPR = FPR; // set input to be what was inputted
        return 0; // exit function
    }
    else // will catch edge case if bug in code
    cout << "Bug here.";
    return -1;
}

int getScore(){
    score = 1 - (sqrt(pow(FPR,2) + pow(1-TPR,2)));      // calculates the score with float percision as per given formula
    return 0;
}     // function get score

// main function to run the program
int main(){
    
    bool stopper = false; // local bool variable used to stop while loop. initialized to false
    
    while (!stopper){ // while stopper is false, the loop will run

        TPRTerminator = false; // reinitialize terminators at the beginning of each iteration, so that they may reflect current iteration's input
        FPRTerminator = false;

        getTPR(); // calls getTPR function
        getFPR(); // calls getFPR function
        getScore(); // calls getScore function

            if (counter == 1 || score > bestScore){ // checks if the current score is greater than the best score. or on the first iteration
                bestScore = score; // if it is, set value to best score
                bestScoreTest = counter; // set current counter to be best score
            }
            else
                bestScore = bestScore; // if not bestScore remains 
                bestScoreTest = bestScoreTest; // bestScoreTest remains also


        if (TPRTerminator == true & FPRTerminator == true) {  // uses the established exit case to exit the infinite loop
            cout << endl;
            cout << "Diagnostic test " << bestScoreTest << " has the best score of " << bestScore << "." << endl;
            cout << "Exiting program.";
            stopper = true; // set stopper to stop the loop and terminate program.  
                
        }
        else 
            cout << "The score for diagnostic test " << counter << " is " << score << endl; // print output
            counter++; // increment the counter for the next iteration
        
    }
    return 0;
}