
#include <iostream>
#include <vector>
using namespace std;

// Checks if a student fails based on attendance
bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;

    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}

int main() {
    vector<vector<int>> tests = {
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}
    };

    for (int i = 0; i < tests.size(); ++i) {
        int absent_count = 0;

        for (int j = 0; j < tests[i].size(); ++j) {
            if (tests[i][j] == 0) {
                absent_count++;
            }
        }

        bool expected = absent_count >= 3;
        bool actual = fail_lecture(tests[i]);

        cout << "Test Case " << i + 1 << endl;
        cout << "Expected: " << (expected ? "Fail" : "Pass") << endl;
        cout << "Actual: " << (actual ? "Fail" : "Pass") << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}
