from collections import defaultdict

def beauty(s):
    '''Returns the beauty of string s, i.e., the maximum frequency of any of its substrings.'''
    freq = defaultdict(int)
    max_occurrence = 0

    # Iterate over every possible substring and count its occurrences.
    for length in range(1, len(s)+1):
        for i in range(len(s) - length + 1):
            freq[s[i:i+length]] += 1
            max_occurrence = max(max_occurrence, freq[s[i:i+length]])

    return max_occurrence

def optimize_string(s, N):
    '''Optimize the string s over N rounds to maximize its beauty.'''
    for _ in range(N):
        current_beauty = beauty(s)
        best_s = s

        # Try replacing every character in the string.
        for i in range(len(s)):
            for c in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
                if s[i] != c:
                    new_s = s[:i] + c + s[i+1:]
                    if beauty(new_s) > current_beauty:
                        best_s = new_s
                        current_beauty = beauty(new_s)

        s = best_s

    return s

def solve(N, M, P, Q, R):
    P = optimize_string(P, N)
    Q = optimize_string(Q, N)
    R = optimize_string(R, N)

    p_beauty = beauty(P)
    q_beauty = beauty(Q)
    r_beauty = beauty(R)

    if p_beauty > q_beauty and p_beauty > r_beauty:
        return "Bob"
    elif q_beauty > p_beauty and q_beauty > r_beauty:
        return "Ben"
    elif r_beauty > p_beauty and r_beauty > q_beauty:
        return "Mike"
    else:
        return "Draw"

# Sample tests
print(solve(1, 6, "abcabc", "cbabac", "ababca"))  # Mike
print(solve(3, 5, "aaaaa", "aaaaa", "aaaab"))    # Draw
