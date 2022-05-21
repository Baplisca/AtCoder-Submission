use std::usize;

use proconio::{input, marker::Chars};

fn main() {
    input! {
      x1:i32,y1:i32,x2:i32,y2:i32
    }
    let mut res = 1;
    res += (x2 - x1).abs() + (y2 - y1).abs();
    println!("{}", res);
}
