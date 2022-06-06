use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, usize};

fn main() {
    input! {
        n:usize,mut a:[i32;n]
    }
    a.sort();
    let mut ma: i32 = -1;
    let mut mi: i32 = MAX;
    for i in 0..n / 2 {
        let sum = a[i] + a[n - i - 1];
        ma = cmp::max(ma, sum);
        mi = cmp::min(mi, sum);
    }
    println!("{}", ma - mi);
}
