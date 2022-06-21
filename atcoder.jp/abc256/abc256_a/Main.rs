use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize
    }
    let mut res: i64 = 1;
    for i in 0..n {
        res *= 2;
    }
    println!("{}", res);
}
