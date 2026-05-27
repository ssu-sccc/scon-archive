class SegmentTree:
    def __init__(self, size, initial_value):
        self.n = 1
        while self.n < size:
            self.n <<= 1
        self.size = size
        self.data = [initial_value] * (2 * self.n)

    def update(self, pos, value):
        pos += self.n
        if self.data[pos] >= value:
            return
        self.data[pos] = value
        while pos > 1:
            pos >>= 1
            new_val = max(self.data[2*pos], self.data[2*pos+1])
            if self.data[pos] == new_val:
                break
            self.data[pos] = new_val

    def query_range(self, l, r):
        res = -float('inf')
        l += self.n
        r += self.n
        while l <= r:
            if l % 2 == 1:
                res = max(res, self.data[l])
                l += 1
            if r % 2 == 0:
                res = max(res, self.data[r])
                r -= 1
            l >>= 1
            r >>= 1
        return res

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    c = int(data[2])
    d = int(data[3])
    
    optimal_temps = list(map(int, data[4:4+n]))
    
    # Initialize the segment tree with -infinity
    initial_value = -float('inf')
    st = SegmentTree(m, initial_value)
    
    # Base case: t=0, all temperatures have 0 flavor
    for x in range(1, m+1):
        st.update(x-1, 0)  # Using 0-based index
    
    for t in range(n):
        kt = optimal_temps[t]
        new_st = SegmentTree(m, initial_value)
        
        for y in range(1, m+1):
            y_idx = y - 1  # 0-based index
            
            # Determine the range of x's that can transition to y
            min_x = max(1, y - d)
            max_x = min(m, y + d)
            
            # Generate all x's in [min_x, max_x] where (y - x) is divisible by c
            # To find the start and end x's that satisfy (x ≡ y mod c)
            rem = y % c
            start_x = min_x + ((rem - min_x % c) + c) % c
            if start_x < min_x:
                start_x += c
            if start_x > max_x:
                start_x = None
            
            if start_x is None:
                max_flavor = -float('inf')
            else:
                end_x = max_x - ((max_x - rem) % c)
                if end_x < start_x:
                    max_flavor = -float('inf')
                else:
                    max_flavor = st.query_range(start_x - 1, end_x - 1)
            
            if max_flavor != -float('inf'):
                flavor = max_flavor + (m - abs(kt - y))
                new_st.update(y_idx, flavor)
        
        st = new_st
    
    max_flavor = max(st.data[st.n:2*st.n])
    print(max_flavor)

if __name__ == "__main__":
    main()