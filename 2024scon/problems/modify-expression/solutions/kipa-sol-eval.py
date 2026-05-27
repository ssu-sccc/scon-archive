from typing import List

import ast
import sys
sys.setrecursionlimit(1000000)

def eval_list(s: List[str]) -> bool:
    return eval('(' * (len(s) + 1 >> 1) + ' '.join(s).replace('e', 'e)'))

def main():
    input()

    D = {'T': 'True', 'F': 'False', '&': 'and', '|': 'or'}
    inversion = {'True': 'False', 'False': 'True', 'and': 'or', 'or': 'and'}
    v = [D[s] for s in input().split()]
    expected = eval(D[input()])
    if eval_list(v) == expected:
        print(0)
        return
    for i, x in enumerate(v):
        orig = x
        v[i] = inversion[x]
        if eval_list(v) == expected:
            print(1)
            return
        v[i] = orig
    print(2)

if __name__ == '__main__':
    main()
