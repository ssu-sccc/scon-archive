use fio::*;

fn solve(n1: u64, r1: u64, n2: u64, r2: u64, primes: &[u64]) -> bool {
    for p in primes {
        let c1 = n1 / p - r1 / p - (n1 - r1) / p;
        let c2 = n2 / p - r2 / p - (n2 - r2) / p;

        if c1 > 0 && c2 > 0 {
            return false;
        }
    }

    true
}

fn main() {
    let t = read::<usize>();

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

    for _ in 0..t {
        let [n1, r1, n2, r2] = read_tuple::<u64, 4>();
        println!("{}", if solve(n1, r1, n2, r2, &primes) { 1 } else { 0 });
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
