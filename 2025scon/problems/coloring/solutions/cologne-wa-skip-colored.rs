use fio::*;

fn solve(mut a: Vec<(usize, usize)>) -> usize {
    let mut color = vec![None; a.len()];
    color[0] = Some(false);

    while color.iter().any(|c| c.is_none()) {
        for &(x, y) in a.iter() {
            match (color[x], color[y]) {
                (Some(c1), Some(c2)) => {
                    if c1 == c2 {
                        return 3;
                    }
                }
                (Some(xc), None) => color[y] = Some(!xc),
                (None, Some(yc)) => color[x] = Some(!yc),
                _ => {}
            }
        }
        a.retain(|&(x, y)| color[x].is_none() || color[y].is_none());
    }

    2
}
fn main() {
    let n = read::<usize>();
    let mut a = vec![];
    for _ in 0..n {
        let [x, y] = read_tuple::<usize, 2>();
        a.push((x - 1, y - 1));
    }

    println!("{}", solve(a));
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
