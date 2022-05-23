use proconio::{input, marker::Chars};
use std::usize;

fn main() {
    input! {
        n:i64,k:i64,mut a:[i64;n]
    }
    a.sort();
    let mut res: i64 = 0;
    for i in 0..k {
        res += a[i as usize] + i;
    }
    println!("{}", res);
}
