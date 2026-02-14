# Program to check if a matrix is an Identity Matrix

# Input: size of matrix
n = int(input())

# Read matrix
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# Check identity matrix condition
is_identity = True
for i in range(n):
    for j in range(n):
        if i == j and matrix[i][j] != 1:   # Diagonal must be 1
            is_identity = False
            break
        elif i != j and matrix[i][j] != 0: # Non-diagonal must be 0
            is_identity = False
            break

# Output result
if is_identity:
    print("Identity Matrix")
else:
    print("Not an Identity Matrix")
