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
fn ok(max_grp: usize, v: Vec<(usize, usize, usize, usize, usize)>) -> bool {
    let mut vac = [[false; 1440]; 7];
    let mut grp = vec![false; max_grp];
    let mut cr = 0;
    for &(g, c, d, s, e) in v.iter() {
        if grp[g] {
            return false;
        }
        grp[g] = true;
        cr += c;
        for t in s..e {
            if vac[d][t] {
                return false;
            }
            vac[d][t] = true;
        }
    }
    return cr == 22;
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
        if ok(n, sub) {
            cnt += 1
        }
    }
    println!("{}", cnt);
}
