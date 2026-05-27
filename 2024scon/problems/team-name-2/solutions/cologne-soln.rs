use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let n = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    for _ in 0..n {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        let s = s.trim();
        let u = s.chars().filter(|x| x.is_ascii_uppercase()).count();
        let l = s.chars().filter(|x| x.is_ascii_lowercase()).count();
        let len = s.len();
        let nn = s.chars().filter(|x| !x.is_ascii_digit()).count();
        if u <= l && len <= 10 && nn >= 1 {
            println!("{}", s);
        }
    }
}
