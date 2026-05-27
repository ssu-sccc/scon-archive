use std::io::*;

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
    let mut d = vec![0; n + 1];
    let mut e = vec![0; n + 1];
    for i in (0..n).rev() {
        d[i] = (d[i + 1] + a[i]).max(e[i + 1]);
        let j = (i + k).min(n);
        let mut ev = d[j];
        for k in i..j {
            ev += a[k];
        }
        e[i] = ev.max(e[i + 1]);
    }
    println!("{}", d[0]);
}
