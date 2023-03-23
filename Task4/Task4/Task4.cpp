/*Task4 Fill two integer arrays A[10] and B[10]. Form the third array x[20], the elements of which will be counted from A and B in order:
a) alternation (A0, b0, a1, b1, a2, b2, ..., a9, b9);
b) following (A0, a1, a2, ..., A9, b0, b1, b2, ..., b9).*/
#include <iostream>

using namespace std;

int main()
{ 
    // Creating and Filling arrays
    int A[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int B[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int x[20];

    // Print original arrays A and B
    cout << "Array A: ";
    for (int i = 0; i < 10; i++) {

        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < 10; i++) {

        cout << B[i] << " ";
    }
    cout << endl;

    // Alternation
    for (int i = 0, j = 0, k = 0; k < 20; k++)
    {
        if (k % 2 == 0) {

            x[k] = A[i++];
        }
        else {
            x[k] = B[j++];
        }
    }

    // Print x array for alternation
    cout << "\nAlternation: ";
    for (int i = 0; i < 20; i++) {

        cout << x[i] << " ";
    }
    cout << endl;

    // Following
    for (int i = 0; i < 10; i++) {

        x[i] = A[i];
        x[i + 10] = B[i];
    }

    // Print x array for following
    cout << "Following: ";
    for (int i = 0; i < 20; i++) {

        cout << x[i] << " ";
    }
    cout << endl;
}