use std::io::*;

fn main() {
    let mut stdin = stdin().lock();
    let n: usize = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mut a = Vec::new();
    let mut b = Vec::new();
    for i in 0..n/3 {
        a.push(n - 3*i);
        b.push(n - 3*i - 1);
        b.push(n - 3*i - 2);
    }
    if n % 3 == 2 {
        a.push(1);
        b.push(2);
    }
    println!("{}", a.len());
    for c in a {
        print!("{} ", c);
    }
    println!();
    println!("{}", b.len());
    for c in b {
        print!("{} ", c);
    }
    println!();
}
