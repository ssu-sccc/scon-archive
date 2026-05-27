use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let mut inp = || {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.chars()
            .filter(|x| !x.is_ascii_whitespace())
            .collect::<String>()
            .parse::<usize>()
            .unwrap()
    };
    let _ = inp();
    let a = inp();
    let b = inp();
    println!("{}", a.min(b));
}
