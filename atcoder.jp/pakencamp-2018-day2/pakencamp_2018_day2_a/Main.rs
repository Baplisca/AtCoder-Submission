use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize
    }
    let mut res = n;
    if n >= 123 {
        res -= 1;
    }
    println!("{}", res);
}
