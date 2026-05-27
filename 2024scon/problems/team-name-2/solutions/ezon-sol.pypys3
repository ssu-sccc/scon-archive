import sys

name_count = int(sys.stdin.readline())

for name_info in range(name_count):
    
    name = sys.stdin.readline().strip()
    
    upper_count = 0
    lower_count = 0
    hyphen_count = 0
    for char in name:
        if 65 <= ord(char) <= 90:
            upper_count += 1
        elif 97 <= ord(char) <= 122:
            lower_count += 1
        elif ord(char) == 45:
            hyphen_count += 1
    
    if len(name) <= 10 and upper_count + lower_count + hyphen_count != 0 and upper_count <= lower_count:
        print(name)