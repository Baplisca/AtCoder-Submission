use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, usize};

fn main() {
    input! {
        n:usize
    }
    let mut res = 1;
    if n == 1 {
        res -= 1;
    }
    println!("{}", res);
}
