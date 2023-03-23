/*Task3. Write a program that finds values that are repeated two or more times in an array and displays them on the screen*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arr[SIZE];
    int choice;

    while (true) { // Infinite loop that keeps running until the user chooses to exit

        cout << "\nDo you want to:\n";
        cout << "\n1. Enter integers manually\n";
        cout << "2. Generate random integers between 0 and 9\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) // If the user chooses to enter integers manually
        {
            cout << "Enter " << SIZE << " integers: ";
            for (int i = 0; i < SIZE; i++)
            {
                cin >> arr[i]; // Read in the integers entered by the user
            }
        }
        else if (choice == 2) // If the user chooses to generate random integers
        {
            srand(time(0)); // Seed the random number generator with the current time
            for (int i = 0; i < SIZE; i++)
            {
                arr[i] = rand() % 10; // Generate a random integer between 0 and 9 and store it in the array
                cout << arr[i] << " "; // Display the generated integer on the screen
            }
            cout << endl;
        }
        else // If the user chooses to exit
        {
            cout << "Exiting...\n";
            return 1; // Exit the program with status code 1
        }

        cout << "Values that are repeated two or more times: ";
        for (int i = 0; i < SIZE; i++) // Loop through each element in the array
        {
            for (int j = i + 1; j < SIZE; j++) // Loop through each element in the array after the current one
            {
                if (arr[i] == arr[j]) // If the current element is equal to the next element
                {
                    bool isDuplicate = false;
                    for (int k = 0; k < i; k++) // Check if the current element has already been printed as a duplicate
                    {
                        if (arr[k] == arr[i])
                        {
                            isDuplicate = true;
                            break;
                        }
                    }
                    if (!isDuplicate) // If the current element has not already been printed as a duplicate
                    {
                        cout << arr[i] << " "; // Display the current element as a duplicate
                    }
                    break; // Exit the inner loop
                }
            }
        }
    }
}
