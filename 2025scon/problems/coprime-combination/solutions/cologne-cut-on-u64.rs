use fio::*;

fn choice(n: u64, r: u64) -> Option<u64> {
    let r = r.min(n - r);

    let mut res = 1u128;
    for i in 0..r {
        res = res * (n - i) as u128 / (i + 1) as u128;

        if res > u64::MAX as u128 {
            return None;
        }
    }

    Some(res as u64)
}

// returns true if C(n, r) is divisible by p. (for prime p)
fn calcp(n: u64, r: u64, p: u64) -> bool {
    let mut res = 0;
    for i in n - r + 1..=n {
        let mut i = i;
        while i % p == 0 {
            res += 1;
            i /= p;
        }
    }
    for i in 1..=r {
        let mut i = i;
        while i % p == 0 {
            res -= 1;
            i /= p;
        }
    }

    res > 0
}

// returns true if C(n, r) and v are coprime.
fn calc(n: u64, r: u64, mut v: u64) -> bool {
    let mut p = 1;
    while p <= v {
        p += 1;
        if v % p == 0 {
            if calcp(n, r, p) {
                return false;
            }

            while v % p == 0 {
                v /= p;
            }
        }
    }
    true
}

fn solve(n1: u64, r1: u64, n2: u64, r2: u64) -> bool {
    let c1 = choice(n1, r1);

    match c1 {
        Some(v) => calc(n2, r2, v),
        None => {
            let c2 = choice(n2, r2);

            match c2 {
                Some(v) => calc(n1, r1, v),
                None => false,
            }
        }
    }
}

fn main() {
    let t = read::<usize>();
    for _ in 0..t {
        let [n1, r1, n2, r2] = read_tuple::<u64, 4>();
        println!("{}", if solve(n1, r1, n2, r2) { 1 } else { 0 });
    }
}

mod fio {
    use std::{
        cell::RefCell,
        convert::TryInto,
        fmt::Debug,
        io::{stdin, stdout, BufWriter, StdinLock, StdoutLock},
        str::FromStr,
    };
    thread_local! {
        pub static STDIN: RefCell<StdinLock<'static>> = RefCell::new(stdin().lock());
        pub static STDOUT: RefCell<BufWriter<StdoutLock<'static>>> = RefCell::new(BufWriter::new(stdout().lock()));
    }

    #[allow(dead_code)]
    pub fn read<T: FromStr>() -> T
    where
        <T as FromStr>::Err: Debug,
    {
        read_line().parse().unwrap()
    }

    #[allow(dead_code)]
    pub fn read_vec<T: FromStr>() -> Vec<T>
    where
        <T as FromStr>::Err: Debug,
    {
        read_line()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    }

    #[allow(dead_code)]
    pub fn read_tuple<T: FromStr, const N: usize>() -> [T; N]
    where
        T: Debug,
        <T as FromStr>::Err: Debug,
    {
        read_vec::<T>().try_into().unwrap()
    }

    pub fn read_line() -> String {
        use std::io::BufRead;
        let mut s = String::new();
        STDIN.with(|cell| {
            cell.borrow_mut().read_line(&mut s).unwrap();
        });
        String::from_str(s.trim_end()).unwrap()
    }
}

#[macro_export]
macro_rules! print {
    ($($t:tt)*) => {
        fio::STDOUT.with(|cell|{
            use std::io::Write;
            write!(cell.borrow_mut(), $($t)*).unwrap()
        })};
}

#[macro_export]
macro_rules! println {
    ($($t:tt)*) => {
        fio::STDOUT.with(|cell| {
            use std::io::Write;
            writeln!(cell.borrow_mut(), $($t)*).unwrap()
        })
    };
}
