#include <stdio.h>
#include <stdint.h>

long long calculate_running_sum(int n) {
    // Implement Me
    return 0;
}

int main() {
    // Test case 1: n = 3, expected = 6
    long long result1 = calculate_running_sum(3);
    if (result1 == 6) {
        printf("#########PASS########\n");
        printf("In: 3\n");
        printf("Out: %lld\n", result1);
        printf("Expected: 6\n");
    } else {
        printf("------------FAIL------------\n");
        printf("In: 3\n");
        printf("Out: %lld\n", result1);
        printf("Expected: 6\n");
    }
    
    // Test case 2: n = 100, expected = 5050
    long long result2 = calculate_running_sum(100);
    if (result2 == 5050) {
        printf("#########PASS########\n");
        printf("In: 100\n");
        printf("Out: %lld\n", result2);
        printf("Expected: 5050\n");
    } else {
        printf("------------FAIL------------\n");
        printf("In: 100\n");
        printf("Out: %lld\n", result2);
        printf("Expected: 5050\n");
    }
    
    // Test case 3: n = 1000000000, expected = 500000000500000000
    long long result3 = calculate_running_sum(1000000000);
    if (result3 == 500000000500000000LL) {
        printf("#########PASS########\n");
        printf("In: 1000000000\n");
        printf("Out: %lld\n", result3);
        printf("Expected: 500000000500000000\n");
    } else {
        printf("------------FAIL------------\n");
        printf("In: 1000000000\n");
        printf("Out: %lld\n", result3);
        printf("Expected: 500000000500000000\n");
    }
    
    return 0;
}
