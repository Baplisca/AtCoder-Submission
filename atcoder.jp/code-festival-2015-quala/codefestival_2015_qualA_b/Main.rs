use std::usize;

use proconio::{input, marker::Chars};

fn main() {
    input! {
      n:i32,mut a:[usize;n]
    }
    let mut res = 0;
    for i in 0..n {
        for j in 0..n - i - 1 {
            a[i as usize] *= 2;
        }
        res += a[i as usize]
    }
    println!("{}", res);
}
