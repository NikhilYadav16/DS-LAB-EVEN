#include <iostream>
using namespace std;

const int NUM_STUDENTS = 3;
const int NUM_SUBJECTS = 5;

void calculateTotals(int marks[][NUM_SUBJECTS], int totals[]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            total += marks[i][j];
        }
        totals[i] = total;
    }
}

void calculateAverages(int marks[][NUM_SUBJECTS], float averages[]) {
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        float total = 0;
        for (int i = 0; i < NUM_STUDENTS; ++i) {
            total += marks[i][j];
        }
        averages[j] = total / NUM_STUDENTS;
    }
}

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    int totals[NUM_STUDENTS];
    float averages[NUM_SUBJECTS];

    // Input marks for each student
    cout << "Enter marks for " << NUM_STUDENTS << " students in " << NUM_SUBJECTS << " subjects:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Enter marks for student " << i + 1 << ": ";
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cin >> marks[i][j];
        }
    }

    // Calculate totals for each student
    calculateTotals(marks, totals);

    // Calculate averages for each subject
    calculateAverages(marks, averages);

    // Output totals for each student
    cout << "\nTotal marks of each student:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << i + 1 << ": " << totals[i] << endl;
    }

    // Output averages for each subject
    cout << "\nAverage marks of each subject:" << endl;
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        cout << "Subject " << j + 1 << ": " << averages[j] << endl;
    }

    return 0;
}
