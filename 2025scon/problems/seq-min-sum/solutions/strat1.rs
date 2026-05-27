use std::ops::Range;

use fio::*;

fn strat1(a: &mut [usize]) -> bool {
    let mut ok = false;
    for i in 1..a.len() {
        if a[i - 1] > a[i] {
            a[i - 1] = a[i];
            ok = true;
        }
    }
    ok
}

fn strat2(a: &mut [usize]) -> Range<usize> {
    if a.len() <= 1 {
        return 0..0;
    }

    let mn = *a.iter().min().unwrap();
    let idx = a.iter().rposition(|x| *x == mn).unwrap();
    a[..idx].fill(mn);

    idx + 1..a.len()
}

fn main() {
    let _n = read::<usize>();
    let mut a = read_vec::<usize>();

    let mut rng = &mut a[..];

    loop {
        let r = strat1(rng);
        if !r {
            break;
        }
    }

    println!("{}", a.iter().sum::<usize>());
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
