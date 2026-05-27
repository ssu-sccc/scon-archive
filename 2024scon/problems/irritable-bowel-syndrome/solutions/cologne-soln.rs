use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let (_, m): (usize, usize) = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let mut it = s.split_ascii_whitespace().map(|x| x.parse().unwrap());
        (it.next().unwrap(), it.next().unwrap())
    };
    let mut s = String::new();
    stdin.read_line(&mut s).unwrap();
    let mut cur = 0usize;
    let mut cnt = 0;
    for v in s
        .split_ascii_whitespace()
        .map(|x| x.parse::<isize>().unwrap())
    {
        cur = cur.saturating_add_signed(v);
        if cur >= m {
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
