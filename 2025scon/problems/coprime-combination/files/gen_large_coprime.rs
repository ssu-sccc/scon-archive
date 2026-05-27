#![feature(float_gamma)]

fn g(mut n: u64, p: u64) -> u64 {
    let mut res = 0;

    while n != 0 {
        res += n / p;

        n /= p;
    }

    res
}

fn solve(n1: u64, r1: u64, n2: u64, r2: u64, primes: &[u64]) -> bool {
    for &p in primes {
        let c1 = g(n1, p) - g(r1, p) - g(n1 - r1, p);
        let c2 = g(n2, p) - g(r2, p) - g(n2 - r2, p);

        if c1 > 0 && c2 > 0 {
            return false;
        }
    }

    true
}

fn main() {
    const MX: u64 = 5_000;
    const MINI_PRIMES: [u64; 15] = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47];

    let mut bms = vec![vec![]; 1 << MINI_PRIMES.len()];
    let mut mx_bms = vec![0f64; 1 << MINI_PRIMES.len()];

    let estimate_lg_ncr = |n: u64, r: u64| {
        ((n + 1) as f64).ln_gamma().0
            - (((r + 1) as f64).ln_gamma().0 + ((n - r + 1) as f64).ln_gamma().0)
    };

    for n in 2..=MX {
        let mut num_factors = [0; MINI_PRIMES.len()];

        for r in 1..=n / 2 {
            for (i, p) in MINI_PRIMES.iter().enumerate() {
                let mut k = n - r + 1;
                while k % p == 0 {
                    num_factors[i] += 1;
                    k /= p;
                }
                let mut k = r;
                while k % p == 0 {
                    num_factors[i] -= 1;
                    k /= p;
                }
            }

            if estimate_lg_ncr(n, r) < 2f64.ln() * 256.0 {
                continue;
            }

            let bm = (0..MINI_PRIMES.len())
                .filter_map(|x| (num_factors[x] != 0).then(|| 1 << x))
                .sum::<usize>();

            bms[bm].push((n, r));
            mx_bms[bm] = mx_bms[bm].max(estimate_lg_ncr(n, r));
        }
    }
    let mut z = vec![];
    for i in 0..1 << (MINI_PRIMES.len() - 1) {
        let m = (1 << MINI_PRIMES.len()) - 1 - i;

        let mut j = m;
        while j > 0 {
            j = (j - 1) & m;

            if !bms[i].is_empty() && !bms[j].is_empty() {
                z.push((i, j));
            }
        }
    }

    let mut primes = vec![];

    for i in 2..=5000 {
        let mut is_prime = true;

        for p in primes.iter() {
            if p * p > i {
                break;
            }
            if i % p == 0 {
                is_prime = false;
                break;
            }
        }

        if is_prime {
            primes.push(i);
        }
    }

    let key = |i: usize, j: usize| mx_bms[i].min(mx_bms[j]);

    z.sort_by(|(i1, j1), (i2, j2)| key(*i1, *j1).partial_cmp(&key(*i2, *j2)).unwrap().reverse());

    for &(a, b) in z.iter() {
        if key(a, b) < 256.0*2f64.ln() {
            return;
        }

        let filtera = bms[a]
            .iter()
            .cloned()
            .filter(|(i, j)| estimate_lg_ncr(*i, *j) > 256.0*2f64.ln())
            .collect::<Vec<_>>();
        let filterb = bms[b]
            .iter()
            .cloned()
            .filter(|(i, j)| estimate_lg_ncr(*i, *j) > 256.0*2f64.ln())
            .collect::<Vec<_>>();

        for &(i, j) in &filtera {
            for &(k, l) in &filterb {
                if solve(i, j, k, l, &primes) {
                    let val = estimate_lg_ncr(i, j).min(estimate_lg_ncr(k, l));
                    println!("{} {} {} {} {}", i, j, k, l, val);
                }
            }
        }
    }
}