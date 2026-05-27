use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let mut inp = || {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.split_ascii_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .fold(
                0,
                |acc, x| {
                    if x <= 10 {
                        acc * 10 + x
                    } else {
                        acc * 100 + x
                    }
                },
            )
    };
    let _ = inp();
    let a = inp();
    let b = inp();
    println!("{}", a.min(b));
}
