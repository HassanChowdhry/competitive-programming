package main

import (
	"fmt"
)

func calculateRunningSum(n int) int64 {
	// Implement Me
	return 0
}

func main() {
	// Test case 1: n = 3, expected = 6
	result1 := calculateRunningSum(3)
	if result1 == 6 {
		fmt.Println("#########PASS########")
		fmt.Println("In: 3")
		fmt.Printf("Out: %d\n", result1)
		fmt.Println("Expected: 6")
	} else {
		fmt.Println("------------FAIL------------")
		fmt.Println("In: 3")
		fmt.Printf("Out: %d\n", result1)
		fmt.Println("Expected: 6")
	}
	
	// Test case 2: n = 100, expected = 5050
	result2 := calculateRunningSum(100)
	if result2 == 5050 {
		fmt.Println("#########PASS########")
		fmt.Println("In: 100")
		fmt.Printf("Out: %d\n", result2)
		fmt.Println("Expected: 5050")
	} else {
		fmt.Println("------------FAIL------------")
		fmt.Println("In: 100")
		fmt.Printf("Out: %d\n", result2)
		fmt.Println("Expected: 5050")
	}
	
	// Test case 3: n = 1000000000, expected = 500000000500000000
	result3 := calculateRunningSum(1000000000)
	if result3 == 500000000500000000 {
		fmt.Println("#########PASS########")
		fmt.Println("In: 1000000000")
		fmt.Printf("Out: %d\n", result3)
		fmt.Println("Expected: 500000000500000000")
	} else {
		fmt.Println("------------FAIL------------")
		fmt.Println("In: 1000000000")
		fmt.Printf("Out: %d\n", result3)
		fmt.Println("Expected: 500000000500000000")
	}
}
