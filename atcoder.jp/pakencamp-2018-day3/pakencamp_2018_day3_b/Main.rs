use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize,a:[i32;n]
    }
    let mut ttl = 0;
    let mut res = 0;
    for i in 0..n {
        ttl += a[i];
        if ttl <= 2018 {
            res += 1;
        }
    }
    println!("{}", res);
}
