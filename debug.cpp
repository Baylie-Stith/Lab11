#include <iostream>
#include <vector>
using namespace std;

// Checks whether a student fails based on their attendance record
bool fail_lecture(const vector<int>& attendance_records) {

    // Keeps track of how many lectures the student missed
    int absent_count = 0;

    // Goes through the attendance record, starting at index 1
    // BUG: Starting at 1 skips the first lecture (index 0)
    for (int i = 1; i < attendance_records.size(); ++i) {

        // Adds 1 to absent_count if the student was absent
        absent_count += attendance_records[i] == 0;
    }

    // Returns true if the student missed 3 or more lectures
    return absent_count >= 3;
}

int main() {

    // Stores the four attendance records used to test the program
    vector<vector<int>> tests = {
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}
    };

    // Runs each attendance record through the program
    for (int i = 0; i < tests.size(); ++i) {

        // Counts the actual number of absences for comparison
        int absent_count = 0;

        // Checks every lecture, including the first one
        for (int j = 0; j < tests[i].size(); ++j) {
            if (tests[i][j] == 0) {
                absent_count++;
            }
        }

        // Calculates the expected result using the correct absence count
        bool expected = absent_count >= 3;

        // Gets the actual result from the function containing the bug
        bool actual = fail_lecture(tests[i]);

        // Prints the test case number
        cout << "Test Case " << i + 1 << endl;

        // Prints whether the student is expected to pass or fail
        cout << "Expected: " << (expected ? "Fail" : "Pass") << endl;

        // Prints what the program actually determined
        cout << "Actual: " << (actual ? "Fail" : "Pass") << endl;

        // Separates the output of each test case
        cout << "-------------------" << endl;
    }

    return 0;
}