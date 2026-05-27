use std::{
    cmp::Reverse,
    collections::{BTreeMap, BinaryHeap, VecDeque},
};

use fio::*;

trait WindowedMin {
    fn add(&mut self, v: u32);
    fn pop(&mut self);
    fn min(&mut self) -> u32;
}

struct MinMultiset {
    q: VecDeque<u32>,
    s: BTreeMap<u32, u32>,
}

impl MinMultiset {
    fn new() -> Self {
        Self {
            q: VecDeque::new(),
            s: BTreeMap::new(),
        }
    }
}

impl WindowedMin for MinMultiset {
    fn add(&mut self, v: u32) {
        self.q.push_back(v);
        *self.s.entry(v).or_insert(0) += 1;
    }

    fn pop(&mut self) {
        let v = self.q.pop_front().unwrap();
        if self.s[&v] == 1 {
            self.s.remove(&v);
        } else {
            *self.s.get_mut(&v).unwrap() -= 1;
        }
    }

    fn min(&mut self) -> u32 {
        *self.s.first_key_value().unwrap().0
    }
}

struct DoublePQ {
    q: VecDeque<u32>,
    a: BinaryHeap<Reverse<u32>>,
    b: BinaryHeap<Reverse<u32>>,
}

impl DoublePQ {
    fn new() -> Self {
        Self {
            q: VecDeque::new(),
            a: BinaryHeap::new(),
            b: BinaryHeap::new(),
        }
    }
}

impl WindowedMin for DoublePQ {
    fn add(&mut self, v: u32) {
        self.q.push_back(v);
        self.a.push(Reverse(v));
    }

    fn pop(&mut self) {
        let v = self.q.pop_front().unwrap();
        self.b.push(Reverse(v));
    }

    fn min(&mut self) -> u32 {
        while self.a.peek() == self.b.peek() {
            self.a.pop();
            self.b.pop();
        }
        self.a.peek().unwrap().0
    }
}

struct WindowedDeque {
    l: u32,
    r: u32,
    q: VecDeque<(u32, u32)>,
}

impl WindowedDeque {
    fn new() -> Self {
        Self {
            l: 0,
            r: 0,
            q: VecDeque::new(),
        }
    }
}

impl WindowedMin for WindowedDeque {
    fn add(&mut self, v: u32) {
        while self.q.back().is_some_and(|(x, _)| *x >= v) {
            self.q.pop_back();
        }

        self.q.push_back((v, self.r));
        self.r += 1;
    }

    fn pop(&mut self) {
        if self.q.front().is_some_and(|(_, i)| *i == self.l) {
            self.q.pop_front();
        }

        self.l += 1;
    }

    fn min(&mut self) -> u32 {
        self.q.front().unwrap().0
    }
}

struct NaiveCalc {
    q: VecDeque<u32>,
}

impl NaiveCalc {
    fn new() -> Self {
        Self { q: VecDeque::new() }
    }
}

impl WindowedMin for NaiveCalc {
    fn add(&mut self, v: u32) {
        self.q.push_back(v);
    }

    fn pop(&mut self) {
        self.q.pop_front();
    }

    fn min(&mut self) -> u32 {
        *self.q.iter().min().unwrap()
    }
}

fn solve_each(mul: u32, rem: u32, rng: usize, upper: usize, temp: &[u32]) -> u32 {
    let mut dp = (0..(upper as u32))
        .map(|v| (v * mul + rem).abs_diff(temp[0]))
        .collect::<Vec<_>>();

    for &t in temp.iter().skip(1) {
        let mut w = NaiveCalc::new();

        for &v in dp.iter().take(rng) {
            w.add(v);
        }

        let mut tdp = vec![0; upper];

        for i in 0..upper {
            if i + rng < upper {
                w.add(dp[i + rng]);
            }
            if i > rng {
                w.pop();
            }

            tdp[i] = w.min() + t.abs_diff(i as u32 * mul + rem);
        }

        dp = tdp;
    }

    dp.into_iter().min().unwrap()
}

fn solve(m: usize, c: usize, d: usize, b: &[u32]) -> u32 {
    let mut ans = u32::MAX;
    for rem in 1..=c {
        let upper = (m - rem) / c;

        ans = ans.min(solve_each(c as u32, rem as u32, d / c, upper + 1, b));
    }

    (m * b.len()) as u32 - ans
}

fn main() {
    let [n, m, c, d] = read_tuple::<usize, 4>();
    let b = read_vec::<u32>();
    assert_eq!(b.len(), n);

    println!("{}", solve(m, c, d, &b));
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
