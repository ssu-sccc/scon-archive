def main():
    PYS = []
    for i in range(3):
        PYS.append(input().split())

    PYS.sort(key=lambda x: x[1])
    print(''.join(x[1][2:] for x in PYS))

    PYS.sort(key=lambda x: int(x[0]), reverse=True)
    print(''.join(x[2][0] for x in PYS))


if __name__ == '__main__':
    main()
