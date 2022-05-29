use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        n:i32,x:i32
    }
    let ans = x * 540 + (n - x) * 525;
    println!("{}", ans);
}
