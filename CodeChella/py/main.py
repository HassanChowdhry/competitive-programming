def calculate_running_sum(n):
    # Implement Me
    return 0

# Test case 1: n = 3, expected = 6
result1 = calculate_running_sum(3)
if result1 == 6:
    print("#########PASS########")
    print("In: 3")
    print(f"Out: {result1}")
    print("Expected: 6")
else:
    print("------------FAIL------------")
    print("In: 3")
    print(f"Out: {result1}")
    print("Expected: 6")

# Test case 2: n = 100, expected = 5050
result2 = calculate_running_sum(100)
if result2 == 5050:
    print("#########PASS########")
    print("In: 100")
    print(f"Out: {result2}")
    print("Expected: 5050")
else:
    print("------------FAIL------------")
    print("In: 100")
    print(f"Out: {result2}")
    print("Expected: 5050")

# Test case 3: n = 1000000000, expected = 500000000500000000
result3 = calculate_running_sum(1000000000)
if result3 == 500000000500000000:
    print("#########PASS########")
    print("In: 1000000000")
    print(f"Out: {result3}")
    print("Expected: 500000000500000000")
else:
    print("------------FAIL------------")
    print("In: 1000000000")
    print(f"Out: {result3}")
    print("Expected: 500000000500000000")
