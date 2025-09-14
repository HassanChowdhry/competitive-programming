fn calculate_running_sum(n: i32) -> i64 {
    // Implement Me
}

fn main() {
    // Test case 1: n = 3, expected = 6
    let result1 = calculate_running_sum(3);
    if result1 == 6 {
        println!("#########PASS########");
        println!("In: 3");
        println!("Out: {}", result1);
        println!("Expected: 6");
    } else {
        println!("------------FAIL------------");
        println!("In: 3");
        println!("Out: {}", result1);
        println!("Expected: 6");
    }
    
    // Test case 2: n = 100, expected = 5050
    let result2 = calculate_running_sum(100);
    if result2 == 5050 {
        println!("#########PASS########");
        println!("In: 100");
        println!("Out: {}", result2);
        println!("Expected: 5050");
    } else {
        println!("------------FAIL------------");
        println!("In: 100");
        println!("Out: {}", result2);
        println!("Expected: 5050");
    }
    
    // Test case 3: n = 1000000000, expected = 500000000500000000
    let result3 = calculate_running_sum(1000000000);
    if result3 == 500000000500000000 {
        println!("#########PASS########");
        println!("In: 1000000000");
        println!("Out: {}", result3);
        println!("Expected: 500000000500000000");
    } else {
        println!("------------FAIL------------");
        println!("In: 1000000000");
        println!("Out: {}", result3);
        println!("Expected: 500000000500000000");
    }
}
