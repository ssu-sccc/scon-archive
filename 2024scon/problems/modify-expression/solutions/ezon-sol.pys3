import sys

def calculate(exp):
    
    now = True
    if exp[0] == "F":
        now = False

    for idx in range(1, len(exp), 2):
        if exp[idx] == "&":
            if now == True and exp[idx+1] == "T":
                now = True
            else:
                now = False
        else:
            if now == False and exp[idx+1] == "F":
                now = False
            else:
                now = True
    
    return now

def swap(exp, idx):
    
    new_exp = exp[:]
    
    if exp[idx] == "T":
        new_exp[idx] = "F"
    elif exp[idx] == "F":
        new_exp[idx] = "T"
    elif exp[idx] == "|":
        new_exp[idx] = "&"
    else:
        new_exp[idx] = "|"

    return new_exp

exp_length = int(sys.stdin.readline())
exp = list(sys.stdin.readline().strip().split())
goal = sys.stdin.readline().strip()
if goal == "T":
    goal = True
else:
    goal = False

if calculate(exp) == goal:
    print(0)
else:
    ans = 2
    for idx in range(exp_length):
        if calculate(swap(exp, idx)) == goal:
            ans = 1
            break
    print(ans)