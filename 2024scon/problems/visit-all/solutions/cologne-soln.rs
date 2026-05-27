use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let (n, a, b, s, e) = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let mut it = s
            .split_ascii_whitespace()
            .map(|x| x.parse::<u64>().unwrap());
        (
            it.next().unwrap(),
            it.next().unwrap(),
            it.next().unwrap(),
            it.next().unwrap(),
            it.next().unwrap(),
        )
    };
    println!(
        "{}",
        if a <= b {
            if (s == 1 || s == n) && (e == 1 || e == n) {
                (n - 1) * a
            } else if s == 1 || s == n || s.abs_diff(e) == 1 {
                (n - 2) * a + b
            } else {
                (n - 3) * a + 2 * b
            }
        } else {
            if s == 1 || s == n {
                (n - 2) * a + b
            } else {
                (n - 3) * a + 2 * b
            }
        }
    );
}
