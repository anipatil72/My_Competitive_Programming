MOD = 998244353

def count_ops(s):
    # Initial counts
    ops = 0
    seqs = 1

    # Process string
    i = 0
    while i < len(s):
        # Find a sequence of consecutive characters
        j = i
        while j < len(s) and s[i] == s[j]:
            j += 1
        
        k = j - i
        # If the sequence length is k, we need k-1 operations
        ops += k - 1
        # And we can pick the characters in k ways for each operation
        seqs *= k
        seqs %= MOD
        i = j

    return ops, seqs

# Input and processing
t = int(input())
for _ in range(t):
    s = input().strip()
    ops, seqs = count_ops(s)
    print(ops, seqs)
