
def eval_list(s) -> bool:
    v = s[0]
    for i in range(1, len(s), 2):
        v = (v and s[i+1]) if (s[i] == 'and') else (v or s[i+1])
    return v

def main():
    input()

    D = {'T': True, 'F': False, '&': 'and', '|': 'or'}
    inversion = {True: False, False: True, 'and': 'or', 'or': 'and'}
    v = [D[s] for s in input().split()]
    expected = bool(D[input()])
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
