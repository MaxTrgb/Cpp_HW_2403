/*Task2. The specified air temperature for each day of January. Define:
a) average temperature for the month;
b) how many times the temperature dropped below the specified mark.*/

#include <iostream>
#include <cstdlib> // for rand() function
#include <ctime> // for time() function
using namespace std;

int main()
{
    const int NUM_DAYS = 31; // number of days in January
    const int MIN_TEMP = -20; // minimum temperature
    const int MAX_TEMP = 20; // maximum temperature
    int temps[NUM_DAYS]; // array to hold temperatures for each day
    double averageTemp = 0; // variable to hold average temperature
    int belowThresholdCount = 0; // variable to hold count of temperatures below threshold
    int threshold; // variable to hold user-specified temperature threshold
    srand(time(NULL)); // seed random number generator with current time

    int start;
    cout << "For star press 1, for exit press 2: "; cin >> start;

    while (start != 2) { 

        // generate random temperatures for each day of January and store in array
        cout << "\nTemperatures for the month of January:" << endl;
        for (int i = 0; i < NUM_DAYS; i++)
        {
            temps[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            cout << temps[i] << " ";
        }
        cout << endl;

        // ask user to specify the temperature threshold
        cout << "\nEnter temperature threshold: ";
        cin >> threshold;

        // calculate average temperature for the month of January
        for (int i = 0; i < NUM_DAYS; i++)
        {
            averageTemp += temps[i];
        }
        averageTemp /= NUM_DAYS;

        // count how many times the temperature dropped below the specified mark
        for (int i = 0; i < NUM_DAYS; i++)
        {
            if (temps[i] < threshold)
            {
                belowThresholdCount++;
            }
        }

        // output results
        cout << "\nAverage temperature for the month of January: " << averageTemp << " degrees Celsius." << endl;
        cout << "\nTemperature dropped below " << threshold << " degrees Celsius " << belowThresholdCount << " times in January." << endl;
        cout << "\nFor star press 1, for exit press 2: "; cin >> start;

    }
}
