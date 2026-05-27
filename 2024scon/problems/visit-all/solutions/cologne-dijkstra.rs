use std::{cmp::Reverse, collections::*, io::*};
fn main() {
    let mut stdin = stdin().lock();
    let (n, a, b, s, e) = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let mut it = s
            .split_ascii_whitespace()
            .map(|x| x.parse::<usize>().unwrap());
        (
            it.next().unwrap(),
            it.next().unwrap(),
            it.next().unwrap(),
            it.next().unwrap() - 1,
            it.next().unwrap() - 1,
        )
    };
    let mut vis = HashSet::new();
    let mut q = BinaryHeap::new();
    let mut st = vec![false; n];
    st[s] = true;
    let st = (st, s);
    q.push((Reverse(0usize), st));
    while let Some((Reverse(d), st)) = q.pop() {
        if vis.contains(&st) {
            continue;
        }
        vis.insert(st.clone());
        let (vs, ls) = st;
        if vs.iter().all(|x| *x) && ls == e {
            println!("{}", d);
            return;
        }
        if ls != 0 && !vs[ls - 1] {
            let mut vn = vs.clone();
            vn[ls - 1] = true;
            q.push((Reverse(d + a), (vn, ls - 1)));
        }
        if ls != n - 1 && !vs[ls + 1] {
            let mut vn = vs.clone();
            vn[ls + 1] = true;
            q.push((Reverse(d + a), (vn, ls + 1)));
        }
        if !vs[0] {
            let mut vn = vs.clone();
            vn[0] = true;
            q.push((Reverse(d + b), (vn, 0)));
        }
        if !vs[n - 1] {
            let mut vn = vs.clone();
            vn[n - 1] = true;
            q.push((Reverse(d + b), (vn, n - 1)));
        }
    }
}
