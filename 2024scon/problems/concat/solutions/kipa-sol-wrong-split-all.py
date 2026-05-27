
from typing import Generator, Iterable

def split_further_incorrect(x: Iterable[int]) -> Generator[int, None, None]:
    for y in x:
        while y:
            if y >= 10:
                yield y // 10
                y %= 10
            else:
                yield y
                y = 0

def main():
    n = int(input())
    S = [int(x) for x in input().split()]
    T = [int(x) for x in input().split()]
    count_S = sum(1 if x < 10 else 2 for x in S)
    count_T = sum(1 if x < 10 else 2 for x in T)
    target = S
    if count_S > count_T:
        target = T
    elif count_S == count_T:
        for x, y in zip(split_further_incorrect(S), split_further_incorrect(T)):
            if x < y:
                target = S
                break
            if x > y:
                target = T
                break
    for x in target:
        print(x, end='')
    print()

if __name__ == '__main__':
    main()
