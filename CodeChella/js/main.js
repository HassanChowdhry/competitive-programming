function calculateRunningSum(n) {
    // Implement Me
}

// Test case 1: n = 3, expected = 6
const result1 = calculateRunningSum(3);
if (result1 === 6) {
    console.log("#########PASS########");
    console.log("In: 3");
    console.log(`Out: ${result1}`);
    console.log("Expected: 6");
} else {
    console.log("------------FAIL------------");
    console.log("In: 3");
    console.log(`Out: ${result1}`);
    console.log("Expected: 6");
}

// Test case 2: n = 100, expected = 5050
const result2 = calculateRunningSum(100);
if (result2 === 5050) {
    console.log("#########PASS########");
    console.log("In: 100");
    console.log(`Out: ${result2}`);
    console.log("Expected: 5050");
} else {
    console.log("------------FAIL------------");
    console.log("In: 100");
    console.log(`Out: ${result2}`);
    console.log("Expected: 5050");
}

// Test case 3: n = 1000000000, expected = 500000000500000000
const result3 = calculateRunningSum(1000000000);
if (result3 === 500000000500000000) {
    console.log("#########PASS########");
    console.log("In: 1000000000");
    console.log(`Out: ${result3}`);
    console.log("Expected: 500000000500000000");
} else {
    console.log("------------FAIL------------");
    console.log("In: 1000000000");
    console.log(`Out: ${result3}`);
    console.log("Expected: 500000000500000000");
}
