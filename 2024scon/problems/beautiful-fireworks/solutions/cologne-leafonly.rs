use std::io::*;

fn main() {
    let mut stdin = stdin().lock();
    let n = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mut g = vec![Vec::new(); n];
    for _ in 0..n - 1 {
        let (u, v) = {
            let mut s = String::new();
            stdin.read_line(&mut s).unwrap();
            let mut it = s
                .split_ascii_whitespace()
                .map(|x| x.parse::<usize>().unwrap() - 1);
            (it.next().unwrap(), it.next().unwrap())
        };
        g[u].push(v);
        g[v].push(u);
    }
    let a: Vec<usize> = {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    assert_eq!(a.len(), n);
    struct Dfs<'a> {
        g: &'a Vec<Vec<usize>>,
        a: &'a Vec<usize>,
    }
    impl Dfs<'_> {
        fn dfs(&mut self, a: usize, p: usize, d: usize, ans: &mut usize) {
            *ans += self.a[a] * d;
            for &b in self.g[a].iter().filter(|&&x| x != p) {
                self.dfs(b, a, d + 1, ans);
            }
        }
    }
    let mut dfs = Dfs { g: &g, a: &a };
    let mut tot = 0;
    for i in 0..n {
        if g[i].len() == 1 {
            let mut ans = 0;
            dfs.dfs(i, i, 0, &mut ans);
            tot = tot.max(ans);
        }
    }
    println!("{}", tot);
}
