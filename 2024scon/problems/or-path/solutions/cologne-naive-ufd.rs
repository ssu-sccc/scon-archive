use std::io::*;

struct DisjointSet {
    p: Vec<usize>,
}
impl DisjointSet {
    fn new(n: usize) -> DisjointSet {
        DisjointSet {
            p: (0..n).collect(),
        }
    }
    fn find(&mut self, mut a: usize) -> usize {
        while a != self.p[a] {
            a = self.p[a];
        }
        a
    }
    fn merge(&mut self, a: usize, b: usize) {
        let a = self.find(a);
        let b = self.find(b);
        self.p[a] = b;
    }
}
fn main() {
    let mut stdin = stdin().lock();
    let (n, m) = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let mut it = s
            .split_ascii_whitespace()
            .map(|x| x.parse::<usize>().unwrap());
        (it.next().unwrap(), it.next().unwrap())
    };
    let mut e = Vec::new();
    for _ in 0..m {
        e.push({
            let mut s = String::new();
            stdin.read_line(&mut s).unwrap();
            let mut it = s
                .split_ascii_whitespace()
                .map(|x| x.parse::<u64>().unwrap());
            (
                it.next().unwrap() as usize - 1,
                it.next().unwrap() as usize - 1,
                it.next().unwrap(),
            )
        });
    }
    let mut forb = 0u64;
    for b in (0..60).rev() {
        let mut dsu = DisjointSet::new(n);
        forb |= 1u64 << b;
        for &(u, v, w) in &e {
            if (w & forb) == 0 {
                dsu.merge(u, v);
            }
        }
        if dsu.find(0) != dsu.find(n - 1) {
            forb ^= 1u64 << b;
        }
    }
    println!("{}", (1u64 << 60) - 1 - forb);
}
