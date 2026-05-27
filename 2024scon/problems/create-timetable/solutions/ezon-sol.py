import sys

def valid(case_classes):
    
    credit_check = 0
    
    group_status = [0 for group in range(group_count)]
    group_check = True
    
    schedule_status = [[], [], [], [], [], [], [], []]
    schedule_check = True
    
    for group, credit, day, start, end in case_classes:
        
        if group_status[group] == 1:
            group_check = False
            break
        else:
            group_status[group] = 1
            
        credit_check += credit
        
        for day_class in schedule_status[day]:
            if not (end <= day_class[0] or day_class[1] <= start):
                schedule_check = False
        schedule_status[day].append((start, end))
    
    if credit_check == 22 and group_check and schedule_check:
        return True
    else:
        return False

group_count = int(sys.stdin.readline())

classes = []

for group in range(group_count):
    
    class_count = int(sys.stdin.readline())
    
    for class_info in range(class_count):
        
        credit, day, start, end = sys.stdin.readline().strip().split()
        credit = int(credit)
        day = int(day)
        
        start_hour, start_min = map(int, start.split(":"))
        end_hour, end_min = map(int, end.split(":"))
        
        start = start_hour * 60 + start_min
        end = end_hour * 60 + end_min
        
        classes.append((group, credit, day, start, end))


ans = 0

for case in range(2 ** len(classes)):
    
    case_classes = []
    
    case_num = case
    for idx in range(len(classes)):
        if case_num % 2 == 1:
            case_classes.append(classes[idx])
        case_num >>= 1
    
    if valid(case_classes):
        ans += 1

print(ans)