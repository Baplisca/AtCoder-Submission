use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        a:i32,b:i32,c:i32,n:i32
    }
    println!(
        "{} {} {}",
        cmp::max(0, n - a),
        cmp::max(0, 2 * n - b),
        cmp::max(0, 3 * n - c)
    );
}
