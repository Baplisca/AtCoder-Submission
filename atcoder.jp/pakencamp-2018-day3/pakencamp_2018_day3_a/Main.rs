use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        y:i32,m:i32,d:i32
    }
    if m == 12 && d == 25 {
        println!("{}", y - 2018);
    } else {
        println!("NOT CHRISTMAS DAY");
    }
}
