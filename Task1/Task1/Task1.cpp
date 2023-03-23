/*Task1. The array stores information on the number of residents of each apartment in a five-story building (4 entrances, 2 apartments on each floor).
a) determine the number of residents and their neighbors living on the same floor by the selected apartment number;
b) determine the total number of residents for each entrance;
c) determine apartment numbers where large families live. Conventionally, we will consider families with more than five children to be large families.*/

#include <iostream>
using namespace std;

int main() {
    const int NUM_FLOORS = 5;
    const int NUM_ENTRANCES = 4;
    const int NUM_APARTMENTS_PER_FLOOR = 2;

    int start;
    cout << "For start enter 1, for exit enter 2: "; cin >> start;

    while (start != 2) {

        // initialize the array with the number of residents per apartment
        int residents[NUM_FLOORS][NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR] = {
            {2, 4, 3, 2, 1, 5, 2, 3},
            {4, 3, 2, 1, 5, 2, 3, 4},
            {1, 2, 3, 5, 2, 3, 4, 1},
            {2, 3, 5, 2, 1, 3, 4, 5},
            {3, 4, 1, 2, 5, 3, 2, 1}
        };

        // a) determine the number of residents and their neighbors living on the same floor by the selected apartment number
        int apt_number;
        cout << endl;

        cout << "Enter the apartment number: ";
        cin >> apt_number;

        int floor = (apt_number - 1) / (NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR) + 1;
        int entrance = ((apt_number - 1) % (NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR)) / NUM_APARTMENTS_PER_FLOOR + 1;
        int apt = ((apt_number - 1) % NUM_APARTMENTS_PER_FLOOR) + 1;

        cout << endl;
        cout << "The number of residents in the selected apartment is: " << residents[floor - 1][(entrance - 1) * NUM_APARTMENTS_PER_FLOOR + (apt - 1)] << endl;
        cout << "The number of residents living on the same floor are: " << residents[floor - 1][(entrance - 1) * NUM_APARTMENTS_PER_FLOOR + (apt - 2)]
            << " and " << residents[floor - 1][(entrance - 1) * NUM_APARTMENTS_PER_FLOOR + apt] << endl;
        cout << endl;

        // b) determine the total number of residents for each entrance
        int entrance_totals[NUM_ENTRANCES] = { 0 };

        for (int i = 0; i < NUM_FLOORS; i++) {

            for (int j = 0; j < NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR; j++) {

                if (j % NUM_APARTMENTS_PER_FLOOR == apt - 1) {

                    entrance_totals[j / NUM_APARTMENTS_PER_FLOOR] += residents[i][j];
                }
            }
        }
        for (int i = 0; i < NUM_ENTRANCES; i++) {

            cout << "The total number of residents for entrance " << i + 1 << " is: " << entrance_totals[i] << endl;
        }
        cout << endl;

        // c) determine apartment numbers where large families live
        cout << "The apartment numbers where large families live are: ";
        for (int i = 0; i < NUM_FLOORS; i++) {

            for (int j = 0; j < NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR; j++) {

                if (residents[i][j] >= 5) {

                    cout << (i * NUM_ENTRANCES * NUM_APARTMENTS_PER_FLOOR + j + 1) << " ";
                }
            }
        }
        cout << endl;
        cout << "\nFor start enter 1, for exit enter 2: "; cin >> start;
    }

}