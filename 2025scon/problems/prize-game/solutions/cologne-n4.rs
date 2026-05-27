use fio::*;

fn main() {
    const N: usize = 100;
    let n = read();
    let mut cnt = vec![0; N];
    for _ in 0..n {
        let [a, b, c] = read_tuple::<usize, 3>();
        cnt[a - 1] += 1;
        cnt[b - 1] += 1;
        cnt[c - 1] += 1;
    }
    let mut ans = 0;
    for i in 0..N {
        for j in 0..i {
            for k in 0..j {
                cnt[i] += 1;
                cnt[j] += 1;
                cnt[k] += 1;

                let special = cnt
                    .iter()
                    .enumerate()
                    .filter(|(_, &c)| c == 1)
                    .map(|(i, _)| i)
                    .max();

                if [Some(i), Some(j), Some(k)].contains(&special) {
                    ans += 1;
                }
                cnt[i] -= 1;
                cnt[j] -= 1;
                cnt[k] -= 1;
            }
        }
    }
    println!("{}", ans);
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
