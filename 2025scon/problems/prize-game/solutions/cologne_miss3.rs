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
    let zeros = cnt
        .iter()
        .enumerate()
        .filter(|(_, &c)| c == 0)
        .map(|(i, _)| (i + 1) as i32)
        .collect::<Vec<_>>();
    let ones = cnt
        .iter()
        .enumerate()
        .filter(|(_, &c)| c == 1)
        .map(|(i, _)| (i + 1) as i32)
        .rev()
        .collect::<Vec<_>>();
    let twos = cnt
        .iter()
        .enumerate()
        .filter(|(_, &c)| c >= 2)
        .map(|(i, _)| (i + 1) as i32)
        .collect::<Vec<_>>();

    let mut ans = 0;

    let c = |n: i32, r: i32| -> i32 {
        (0..r).fold(1, |acc, i| acc * (n-i) / (i + 1))
    };

    let total_ones = ones.len() as i32;
    let o1 = ones.get(0).copied().unwrap_or_default();
    let o2 = ones.get(1).copied().unwrap_or_default();
    let o3 = ones.get(2).copied().unwrap_or_default();

    let total_zeros = zeros.len() as i32;
    let over_o1 = zeros.iter().filter(|&&x| x > o1).count() as i32;
    let over_o2 = zeros.iter().filter(|&&x| x > o2).count() as i32;
    let over_o3 = zeros.iter().filter(|&&x| x > o3).count() as i32;

    let total_twos = twos.len() as i32;

    // choose 0 element from ones.

    // choose 1 element from over_o1.
    ans += over_o1 * c(total_twos, 2);
    // choose 2 elements including over_o1.
    ans += (c(total_zeros, 2) - c(total_zeros - over_o1, 2)) * total_twos;
    // choose 3 elements including over_o1.
    ans += c(total_zeros, 3) - c(total_zeros - over_o1, 3);

    // choose 1 element from ones.

    // largest element has been chosen.
    if o1 != 0 {
        // choose 1 element from over_o2.
        ans += over_o2 * total_twos;
        // choose 2 elements including over_o2.
        ans += c(total_zeros, 2) - c(total_zeros - over_o2, 2);
    }
    // non-largest element has been chosen.
    let chooable_ones = (total_ones - 1).max(0);
    // choose 1 element from over_o1 and 1 element from chooable_ones.
    ans += over_o1 * total_twos * chooable_ones;
    // choose 2 elements including over_o1 and 1 element from chooable_ones.
    ans += (c(total_zeros, 2) - c(total_zeros - over_o1, 2)) * chooable_ones; // choose 2 elements including over_o1 and 1 element from chooable_ones.

    // choose 2 elements from ones.
    // largest, 2nd largest element has been chosen.
    if o2 != 0 {
        ans += over_o3;
    }

    // largest, non-largest element has been chosen.
    let choosable_ones = (total_ones - 2).max(0);
    ans += over_o2 * choosable_ones;

    // two non-largest elements has been chosen.
    let choosable_ones = total_ones - 1; // (total_ones - 1).max(0);
    ans += over_o1 * c(choosable_ones, 2);

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
