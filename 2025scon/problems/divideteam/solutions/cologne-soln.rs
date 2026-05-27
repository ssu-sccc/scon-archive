use fio::*;

fn main() {
    let n = read();
    let a = read_vec::<i64>();
    let b = read_vec::<i64>();
    let c = a
        .iter()
        .zip(b.iter())
        .map(|(a, b)| (2 * a - 1) * b)
        .collect::<Vec<_>>();
    assert_eq!(c.len(), n);

    let mut suff = c.clone();
    for i in (0..n - 1).rev() {
        suff[i] += suff[i + 1];
    }

    let cnt = 1 + suff.iter().skip(1).filter(|&&x| x > 0).count();
    let ans = suff[0] + suff.iter().skip(1).map(|&x| x.max(0)).sum::<i64>();

    println!("{} {}", cnt, ans);
}

mod fio {
    use std::{
        cell::RefCell,
        convert::TryInto,
        fmt::Debug,
        io::{stdin, stdout, BufRead, BufWriter, StdinLock, StdoutLock},
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

#[macro_export]
macro_rules! flush {
    () => {
        fio::STDOUT.with(|cell| {
            use std::io::Write;
            cell.borrow_mut().flush().unwrap()
        });
    };
}
