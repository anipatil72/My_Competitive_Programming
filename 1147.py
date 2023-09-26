def min_substring_length(n, s):
    start = 0
    min_len = float('inf')

    j_count, l_count, r_count = 0, 0, 0

    for end in range(n):
        # Update counts based on character at 'end'
        if s[end] == 'J':
            j_count += 1
        elif s[end] == 'L':
            l_count += 1
        else:
            r_count += 1

        # Check if the current substring meets the criteria
        while j_count > l_count and j_count > r_count and start <= end:
            min_len = min(min_len, end - start + 1)

            # Update counts based on character at 'start'
            if s[start] == 'J':
                j_count -= 1
            elif s[start] == 'L':
                l_count -= 1
            else:
                r_count -= 1

            # Move the 'start' pointer to the right
            start += 1

    return min_len if min_len != float('inf') else -1

# Input and Output
n = int(input())
s = input().strip()
print(min_substring_length(n, s))
