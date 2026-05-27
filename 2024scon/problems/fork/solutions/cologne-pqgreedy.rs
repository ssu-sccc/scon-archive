use std::{cell::RefCell, collections::BinaryHeap, io::*};

struct Segtree {
    n: usize,
    size: usize,
    log: usize,
    d: Vec<i64>,
}

impl From<Vec<i64>> for Segtree {
    fn from(v: Vec<i64>) -> Self {
        let n = v.len();
        let log = 1 + n.saturating_sub(1).max(1).ilog2() as usize;
        let size = 1 << log;
        let mut d = vec![0; 2 * size];
        d[size..(size + n)].clone_from_slice(&v);
        let mut ret = Segtree { n, size, log, d };
        for i in (1..size).rev() {
            ret.update(i);
        }
        ret
    }
}

impl Segtree {
    fn set(&mut self, mut p: usize, x: i64) {
        assert!(p < self.n);
        p += self.size;
        self.d[p] = x;
        for i in 1..=self.log {
            self.update(p >> i);
        }
    }

    pub fn prod(&self, mut l: usize, mut r: usize) -> i64 {
        assert!(l <= r && r <= self.n);
        let mut sm = 0;
        l += self.size;
        r += self.size;
        while l < r {
            if l & 1 != 0 {
                sm += self.d[l];
                l += 1;
            }
            if r & 1 != 0 {
                r -= 1;
                sm += self.d[r];
            }
            l >>= 1;
            r >>= 1;
        }

        sm
    }

    fn update(&mut self, k: usize) {
        self.d[k] = self.d[2 * k] + self.d[2 * k + 1];
    }
}

fn main() {
    let mut stdin = stdin().lock();
    let (n, k) = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let mut it = s.split_ascii_whitespace().map(|x| x.parse().unwrap());
        (it.next().unwrap(), it.next().unwrap())
    };
    let a: Vec<i64> = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    assert_eq!(a.len(), n);
    let seg: RefCell<Segtree> = RefCell::new(a.into());
    let used = RefCell::new(vec![false; n]);
    // i-(k-1)..=i is used
    let q = RefCell::new(BinaryHeap::new());
    let push = |i: usize| {
        let l = i.saturating_sub(k - 1);
        let r = (i + 1).min(n);
        if !used.borrow()[l] || !used.borrow()[r - 1] {
            let p = seg.borrow().prod(l, r);
            if p >= 0 {
                q.borrow_mut().push((p, i));
            }
        }
    };
    for i in 0..=n + k - 2 {
        push(i);
    }
    let mut ans = 0;
    while let Some((v, i)) = {
        let z = q.borrow_mut().pop();
        z
    } {
        let l = i.saturating_sub(k - 1);
        let r = (i + 1).min(n);
        if used.borrow()[l] && used.borrow()[r - 1] {
            continue;
        }
        let p = seg.borrow().prod(l, r);

        if p != v {
            push(i);
            continue;
        }
        ans += p;

        for i in l..r {
            {
                if used.borrow()[i] {
                    break;
                }
                used.borrow_mut()[i] = true;
                seg.borrow_mut().set(i, 0);
            }
            push(i);
            push(i + k - 1);
        }
        for i in (l..r).rev() {
            {
                if used.borrow()[i] {
                    break;
                }
                used.borrow_mut()[i] = true;
                seg.borrow_mut().set(i, 0);
            }
            push(i);
            push(i + k - 1);
        }
    }
    println!("{}", ans);
}
