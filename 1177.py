def kaprekar_routine(n):
    kaprekar_constant = 6174
    steps = 0

    while n != kaprekar_constant:
        # Convert the number to a zero-padded 4-digit string
        num_str = f"{n:04d}"

        # Form the largest and smallest numbers from the digits
        largest = int("".join(sorted(num_str, reverse=True)))
        smallest = int("".join(sorted(num_str)))

        # Subtract the smallest from the largest
        n = largest - smallest
        steps += 1

        # Print each step for visualization
        print(f"Step {steps}: {largest} - {smallest} = {n}")

    print(f"\nKaprekar's constant (6174) reached in {steps} steps.")


# Input any 4-digit number (with at least two different digits)
# starting_number = int(input("Enter a 4-digit number: "))

starting_number = 1233

# Confirm convergence to 6174
kaprekar_routine(starting_number)

# Krantiveer Sangolli Rayanna Railway Station, Bengaluru
