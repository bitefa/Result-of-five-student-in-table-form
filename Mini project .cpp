#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits> 

using namespace std;

int main() {
    char names[5][20];
    int marks[5][3];
    int total[5];
    float avg[5];

    int top = 0;
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter student " << i + 1 << " name: ";
        cin.getline(names[i], 20);

        cout << "Enter 3 marks: ";
        for (int j = 0; j < 3; j++) {
            cin >> marks[i][j];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < 5; i++) {
        total[i] = 0;

        for (int j = 0; j < 3; j++) {
            total[i] += marks[i][j];
        }

        avg[i] = total[i] / 3.0;

        if (total[i] > total[top]) {
            top = i;
        }
    }

    cout << "\n\n";
    cout << left
         << setw(20) << "Name"
         << setw(8)  << "M1"
         << setw(8)  << "M2"
         << setw(8)  << "M3"
         << setw(10) << "Total"
         << setw(10) << "Avg" << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << left
             << setw(20) << names[i]
             << setw(8)  << marks[i][0]
             << setw(8)  << marks[i][1]
             << setw(8)  << marks[i][2]
             << setw(10) << total[i]
             << fixed << setprecision(1)
             << avg[i] << endl;
    }
    cout << "\nTop student: " << names[top] << " (Total: " << total[top] << ")" << endl;

    return 0;
}
