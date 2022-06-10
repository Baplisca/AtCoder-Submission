use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        a:i32,b:i32,c:i32
    }
    for i in 1..128 {
        if i % 3 == a && i % 5 == b && i % 7 == c {
            println!("{}", i);
        }
    }
}
