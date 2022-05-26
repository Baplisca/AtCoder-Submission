use proconio::{input, marker::Chars};
use std::usize;

fn main() {
    input! {
        a:i32,b:i32
    }
    println!("{}", std::cmp::max(a, b));
}
