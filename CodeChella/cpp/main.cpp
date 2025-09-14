#include <iostream>
using namespace std;

long long calculate_running_sum(int n) {
    // Implement Me
}

int main() {
    // Test case 1: n = 3, expected = 6
    long long result1 = calculate_running_sum(3);
    if (result1 == 6) {
        cout << "#########PASS########" << endl;
        cout << "In: 3" << endl;
        cout << "Out: " << result1 << endl;
        cout << "Expected: 6" << endl;
    } else {
        cout << "------------FAIL------------" << endl;
        cout << "In: 3" << endl;
        cout << "Out: " << result1 << endl;
        cout << "Expected: 6" << endl;
    }
    
    // Test case 2: n = 100, expected = 5050
    long long result2 = calculate_running_sum(100);
    if (result2 == 5050) {
        cout << "#########PASS########" << endl;
        cout << "In: 100" << endl;
        cout << "Out: " << result2 << endl;
        cout << "Expected: 5050" << endl;
    } else {
        cout << "------------FAIL------------" << endl;
        cout << "In: 100" << endl;
        cout << "Out: " << result2 << endl;
        cout << "Expected: 5050" << endl;
    }
    
    // Test case 3: n = 1000000000, expected = 500000000500000000
    long long result3 = calculate_running_sum(1000000000);
    if (result3 == 500000000500000000LL) {
        cout << "#########PASS########" << endl;
        cout << "In: 1000000000" << endl;
        cout << "Out: " << result3 << endl;
        cout << "Expected: 500000000500000000" << endl;
    } else {
        cout << "------------FAIL------------" << endl;
        cout << "In: 1000000000" << endl;
        cout << "Out: " << result3 << endl;
        cout << "Expected: 500000000500000000" << endl;
    }
    
    return 0;
}
