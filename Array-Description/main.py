MOD = 1000000007

n, m = map(int, input().split())
nums = list(map(int, input().split()))

# Early exit if input is impossible
possible = True
for i in range(n - 1):
    if abs(nums[i] - nums[i + 1]) > 1 and nums[i] != 0 and nums[i + 1] != 0:
        possible = False
        break

if not possible:
    print(0)
else:
    # Using only two 1D arrays for dp rows
    prev_dp = [0] * (m + 1)
    curr_dp = [0] * (m + 1)

    # Initialize dp for first element
    if nums[0] == 0:
        for i in range(1, m + 1):
            prev_dp[i] = 1
    else:
        prev_dp[nums[0]] = 1

    # Fill DP table with optimized transition logic
    for i in range(1, n):
        # Reset current row dp
        curr_dp = [0] * (m + 1)

        # If nums[i] is zero, calculate all transitions
        if nums[i] == 0:
            for j in range(1, m + 1):
                left = prev_dp[j - 1] if j > 1 else 0
                middle = prev_dp[j]
                right = prev_dp[j + 1] if j < m else 0
                curr_dp[j] = (left + middle + right) % MOD
        else:
            # If nums[i] is non-zero, calculate only valid transitions
            left = prev_dp[nums[i] - 1] if nums[i] > 1 else 0
            middle = prev_dp[nums[i]]
            right = prev_dp[nums[i] + 1] if nums[i] < m else 0
            curr_dp[nums[i]] = (left + middle + right) % MOD

        # Update prev_dp to current dp
        prev_dp = curr_dp

    # Sum up the results in the last row of DP
    res = sum(prev_dp) % MOD
    print(res)
