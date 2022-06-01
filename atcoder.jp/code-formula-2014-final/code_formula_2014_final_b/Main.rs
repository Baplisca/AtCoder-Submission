use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        n:i64
    }
    let res = (n + 1) / 2 * 3 - n / 2 * 2;
    println!("{}", res);
}
