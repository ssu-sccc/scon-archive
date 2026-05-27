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
        sz: Vec<usize>,
    }
    impl Dfs<'_> {
        fn dfs(&mut self, a: usize, p: usize) {
            self.sz[a] = self.a[a];
            for &b in self.g[a].iter().filter(|&&x| x != p) {
                self.dfs(b, a);
                self.sz[a] += self.sz[b];
            }
        }
        fn dfs2(&mut self, a: usize, p: usize, tot: usize, ans: &mut usize) {
            *ans = tot.max(*ans);
            for &b in self.g[a].iter().filter(|&&x| x != p) {
                self.dfs2(b, a, tot + self.sz[0] - 2 * self.sz[b], ans);
            }
        }
    }
    let mut dfs = Dfs {
        g: &g,
        a: &a,
        sz: vec![0; n],
    };
    dfs.dfs(0, 0);
    let tot = dfs.sz.iter().skip(1).sum::<usize>();
    let mut ans = tot;
    dfs.dfs2(0, 0, tot, &mut ans);
    println!("{}", ans);
}
