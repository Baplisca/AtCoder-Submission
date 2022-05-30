use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        n:usize,a:[f64;n]
    }
    let mut ttl: f64 = 0.0;
    for i in 0..n - 1 {
        ttl += a[i + 1] - a[i];
    }
    println!("{}", ttl / ((n - 1) as f64));
}
