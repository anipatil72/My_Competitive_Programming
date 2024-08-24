def max_rides(left_prices, right_prices, money):
    left_len = len(left_prices)
    right_len = len(right_prices)

    # Calculate prefix sums for right prices
    right_sum = [0] * (right_len + 1)
    for i in range(1, right_len + 1):
        right_sum[i] = right_sum[i-1] + right_prices[i-1]

    max_rides = 0
    left_cost = 0
    right_ptr = right_len

    # Sliding window approach
    for left_ptr in range(left_len + 1):
        # Adjust right_ptr
        while right_ptr > 0 and left_cost + right_sum[right_ptr] > money:
            right_ptr -= 1

        # Update max_rides
        if left_cost + right_sum[right_ptr] <= money:
            max_rides = max(max_rides, left_ptr + right_ptr)

        # Move to next left ride
        if left_ptr < left_len:
            left_cost += left_prices[left_ptr]

    return max_rides


# Read input and process test cases
t = int(input())
for _ in range(t):
    l = int(input())
    left_prices = list(map(int, input().split()))
    r = int(input())
    right_prices = list(map(int, input().split()))
    m = int(input())

    print(max_rides(left_prices, right_prices, m))
