use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        a:i32,b:i32,c:i32
    }
    if a + b + c - cmp::max(a, cmp::max(b, c)) - cmp::min(a, cmp::min(b, c)) == b {
        println!("Yes");
    } else {
        println!("No");
    }
}
