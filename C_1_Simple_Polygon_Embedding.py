# ॥ श्री गणेशाय नमः ॥
import math

# Function to calculate the side length of the square
def find_square_side_length(n):
    # Calculate the central angle of each sector
    central_angle = 2 * math.pi / (2 * n)
    
    # Calculate the length of the diagonal of each sector
    diagonal_length = 1 / (2 * math.sin(central_angle / 2))
    
    # Calculate the side length of the square
    side_length = diagonal_length * math.cos(central_angle / 2) * 2
    
    return side_length

# Number of test cases
T = int(input())

# Iterate through each test case
for _ in range(T):
    n = int(input())
    side_length = find_square_side_length(n)
    print("{:.10f}".format(side_length))



# ॥ जय श्री राम जय श्री कृष्ण ॥