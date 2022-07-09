use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize
    }
    let mut res = 1;
    let mut ma = 0;
    for i in 0..n {
        input! {
            a:i32
        }
        if a > ma {
            ma = a;
            res = i + 1;
        }
    }
    println!("{}", res);
}
