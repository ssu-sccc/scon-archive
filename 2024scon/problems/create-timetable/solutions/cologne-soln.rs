use std::io::*;

fn parse_time(t: &str) -> usize {
    let mut c = t.chars();
    let h1 = c.next().unwrap();
    let h2 = c.next().unwrap();
    c.next().unwrap();
    let m1 = c.next().unwrap();
    let m2 = c.next().unwrap();
    (h1.to_digit(10).unwrap() * 600
        + h2.to_digit(10).unwrap() * 60
        + m1.to_digit(10).unwrap() * 10
        + m2.to_digit(10).unwrap()) as usize
}
fn ok(v: Vec<(usize, usize, usize, usize, usize)>) -> bool {
    let credits = v.iter().map(|x| x.1).sum::<usize>();
    if credits != 22 {
        return false;
    }
    for (i, c1) in v.iter().enumerate() {
        for c2 in v.iter().take(i) {
            if c1.0 == c2.0 {
                return false;
            }
            if c1.2 != c2.2 {
                continue;
            }
            if c1.4 < c2.3 {
                continue;
            }
            if c2.4 < c1.3 {
                continue;
            }
            return false;
        }
    }
    return true;
}
fn main() {
    let mut stdin = stdin().lock();
    let n: usize = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mut classes = Vec::new();
    for grp in 0..n {
        let a = {
            let mut s = String::new();
            stdin.read_line(&mut s).unwrap();
            s.trim().parse().unwrap()
        };
        for _ in 0..a {
            let (c, d, s, e) = {
                let mut s = String::new();
                stdin.read_line(&mut s).unwrap();
                let mut it = s.split_ascii_whitespace();
                (
                    it.next().unwrap().parse::<usize>().unwrap(),
                    it.next().unwrap().parse::<usize>().unwrap(),
                    parse_time(it.next().unwrap()),
                    parse_time(it.next().unwrap()),
                )
            };
            classes.push((grp, c, d - 1, s, e));
        }
    }
    let mut cnt = 0;
    for bm in 0..1 << classes.len() {
        let mut sub = Vec::new();
        for i in 0..classes.len() {
            if (bm & (1 << i)) != 0 {
                sub.push(classes[i]);
            }
        }
        if ok(sub) {
            cnt += 1
        }
    }
    println!("{}", cnt);
}
