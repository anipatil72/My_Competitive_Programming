# Function to calculate total pancakes collected by Alice and Bob
def calculate_pancakes(test_case, N, A, La, Ra, Lb, Rb):
    alice_pancakes = 0
    bob_pancakes = 0
    alice_prev = None
    bob_prev = None

    # Calculate total pancakes collected by Alice
    for i in range(La - 1, Ra):
        if alice_prev is None or i == alice_prev + 1:
            alice_pancakes += A[i]
            alice_prev = i

    # Calculate total pancakes collected by Bob
    for i in range(Lb - 1, Rb):
        if bob_prev is None or i == bob_prev + 1:
            if i != alice_prev:
                bob_pancakes += A[i]
                bob_prev = i

    return "Case #{}: {}".format(test_case, alice_pancakes)


# Read input for number of test cases
T = int(input())

# Loop through each test case
for test_case in range(1, T + 1):
    # Read input for current test case
    N = int(input())
    A = list(map(int, input().split()))
    La, Ra, Lb, Rb = map(int, input().split())

    # Calculate and print total pancakes collected by Alice
    print(calculate_pancakes(test_case, N, A, La, Ra, Lb, Rb))