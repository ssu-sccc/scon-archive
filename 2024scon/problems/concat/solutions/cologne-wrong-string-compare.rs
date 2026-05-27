use std::io::*;
fn main() {
    let mut stdin = stdin().lock();
    let mut inp = || {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().to_owned()
    };
    let _ = inp();
    let a = inp();
    let b = inp();
    let ret = if a.len() < b.len() || a.len() == b.len() && a < b {
        a
    } else {
        b
    };
    println!(
        "{}",
        ret.chars()
            .filter(|x| !x.is_ascii_whitespace())
            .collect::<String>()
    );
}
