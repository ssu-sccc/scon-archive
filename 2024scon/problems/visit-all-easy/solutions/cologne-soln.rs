use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let t = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    for _ in 0..t {
        let (n, s, e) = {
            let mut s = String::new();
            stdin.read_line(&mut s).unwrap();
            let mut it = s
                .split_ascii_whitespace()
                .map(|x| x.parse::<u64>().unwrap());
            (it.next().unwrap(), it.next().unwrap(), it.next().unwrap())
        };
        println!(
            "{}",
            if (s == 1 || s == n) && (e == 1 || e == n) {
                0
            } else if s == 1 || s == n || s.abs_diff(e) == 1 {
                1
            } else {
                2
            }
        );
    }
}
