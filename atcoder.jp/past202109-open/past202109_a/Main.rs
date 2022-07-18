use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        a:i32,b:i32,c:i32,d:i32
    }
    let res = cmp::min(a + b - c, d);
    println!("{}", res);
}
