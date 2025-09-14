public class RunningSum {
    public static long calculateRunningSum(int n) {
        // Implement Me
        return 0;
    }

    public static void main(String[] args) {
        // Test case 1: n = 3, expected = 6
        long result1 = calculateRunningSum(3);
        if (result1 == 6) {
            System.out.println("#########PASS########");
            System.out.println("In: 3");
            System.out.println("Out: " + result1);
            System.out.println("Expected: 6");
        } else {
            System.out.println("------------FAIL------------");
            System.out.println("In: 3");
            System.out.println("Out: " + result1);
            System.out.println("Expected: 6");
        }
        
        // Test case 2: n = 100, expected = 5050
        long result2 = calculateRunningSum(100);
        if (result2 == 5050) {
            System.out.println("#########PASS########");
            System.out.println("In: 100");
            System.out.println("Out: " + result2);
            System.out.println("Expected: 5050");
        } else {
            System.out.println("------------FAIL------------");
            System.out.println("In: 100");
            System.out.println("Out: " + result2);
            System.out.println("Expected: 5050");
        }
        
        // Test case 3: n = 1000000000, expected = 500000000500000000
        long result3 = calculateRunningSum(1000000000);
        if (result3 == 500000000500000000L) {
            System.out.println("#########PASS########");
            System.out.println("In: 1000000000");
            System.out.println("Out: " + result3);
            System.out.println("Expected: 500000000500000000");
        } else {
            System.out.println("------------FAIL------------");
            System.out.println("In: 1000000000");
            System.out.println("Out: " + result3);
            System.out.println("Expected: 500000000500000000");
        }
    }
}
