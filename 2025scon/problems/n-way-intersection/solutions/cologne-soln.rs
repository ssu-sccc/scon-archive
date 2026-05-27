use fio::*;

fn main() {
    let [n, m] = read_tuple::<usize, 2>();
    let a = read_vec::<usize>();
    let mut timing = vec![0; n];
    for (i, v) in a.iter().enumerate() {
        timing[v - 1] = i;
    }

    let calc = |delta: usize| {
        let mut cur = 0;
        let mut t = 0;
        while cur != m - 1 {
            let nxt = (cur + delta) % n;
            let rd = if delta == 1 { cur } else { nxt };
            t += (timing[rd] + n - t) % n;
            cur = nxt;
        }
        t
    };

    let cw = calc(1);
    let ccw = calc(n - 1);

    println!("{}", if cw < ccw { "CW" } else { "CCW" });
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
