use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    let mut a: [i64; 30] = [0; 30];
    a[0] = 100;
    a[1] = 100;
    a[2] = 200;
    for i in 3..30 {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    println!("{}", a[19]);
}
