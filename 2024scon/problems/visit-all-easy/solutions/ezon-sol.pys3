import sys

test_count = int(sys.stdin.readline())

for test in range(test_count):
    
    room_count, start, end = map(int, sys.stdin.readline().split())
    
    if start > end:
        start = room_count + 1 - start
        end = room_count + 1 - end

    ans = 0
    if start == 1:
        if end == room_count:
            print(0)
        else:
            print(1)
    else:
        if end == start+1:
            print(1)
        else:
            print(2)