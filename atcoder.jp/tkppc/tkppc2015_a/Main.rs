use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize
    }
    for i in 0..n {
        input! {
            a:i32,b:i32
        }
        println!("{}", a + b);
    }
}
