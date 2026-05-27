import sys

gift_count = int(sys.stdin.readline())

if gift_count % 3 == 1:
    gift_count -= 1

if gift_count % 3 == 2:

    print((gift_count + 1) // 3)
    for num in range(2, gift_count+1, 3):
        print(num, end = ' ')
    print()
    
    print(gift_count - (gift_count + 1) // 3)
    for num in range(1, gift_count+1):
        if num % 3 != 2:
            print(num, end = ' ')

else:
    
    print(gift_count // 3)
    for num in range(3, gift_count+1, 3):
        print(num, end = ' ')
    print()
    
    print(gift_count - gift_count // 3)
    for num in range(1, gift_count+1):
        if num % 3 != 0:
            print(num, end = ' ')