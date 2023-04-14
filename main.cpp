#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "Food Access vs Demographic Visualizer\n" << endl;
    cout << "Welcome!\n" << endl;

    int exit = 1;

    //program continues running until user exits
    while (exit == 1)
    {
        int demographicSelection;
        int foodAccessSelection;
        int sortSelection;

        //main menu - get input for demographics and sorting algorithm
        cout << "Please select your metrics for comparison:\n" << endl;

        cout << "Demographic (%):" << endl;
        cout << "1. 65+ y/o \n2. 18- y/o \n3. High school+ education \n4. Bachelors degree+ education \n5. Hispanic or Latino \n6. Native Hawaiian or Pacific Islander \n7. White \n8. Home ownership \n9. Female" << endl;
        cout << "Enter 0 to exit the program\n";
        cin >> demographicSelection;
        if (demographicSelection == 0)
            break;

        cout << "Food Access (10+ miles from a super market):" << endl;
        cout << "1. Households without vehicles \n2. Children population \n3. Total population \n4. Senior population \n5. Low income population\n";
        cout << "Enter 0 to exit the program\n";
        cin >> foodAccessSelection;
        if (foodAccessSelection == 0)
            break;

        cout << "Please select the sorting algorithm to use: " << endl;
        cout << "1. Shell sort \n2. Merge sort" << endl;
        cout << "Enter 0 to exit the program\n";
        cin >> sortSelection;
        if (sortSelection == 0)
            break;

        //pull necessary data based on selections
        if (demographicSelection == 1)
        {
            //demographic = 65+ y/o
        }
        else if (demographicSelection == 2)
        {
            //demographic = 18- y/o
        }
        else if (demographicSelection == 3)
        {
            //demographic = High school+ education
        }
        else if (demographicSelection == 4)
        {
            //demographic = Bachelors degree+ education
        }
        else if (demographicSelection == 5)
        {
            //demographic = Hispanic or Latino
        }
        else if (demographicSelection == 6)
        {
            //demographic = Native Hawaiian or Pacific Islander
        }
        else if (demographicSelection == 7)
        {
            //demographic = White
        }
        else if (demographicSelection == 8)
        {
            //demographic = Home ownership
        }
        else if (demographicSelection == 9)
        {
            //demographic = Female
        }



    }
    cout << "Thank you for using our Food Access vs Demographic Visualizer!" << endl;
    return 0;

}