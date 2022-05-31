use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        a:i32,b:i32
    }

    println!("{}", a * b);
}
