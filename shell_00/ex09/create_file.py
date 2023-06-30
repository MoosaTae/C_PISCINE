with open('/Users/sawongpr/shell_00/ex09/testfile', 'rb') as f:
    f.seek(40)  # Go to the 41st byte (0-indexed)
    print(f.read(2).decode())  # Read two bytes and print
