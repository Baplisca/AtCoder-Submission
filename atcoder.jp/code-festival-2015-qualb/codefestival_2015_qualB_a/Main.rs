use std::usize;

use proconio::{input, marker::Chars};

fn main() {
    input! {
      s:String
    }
    for i in 0..2 {
        print!("{}", s);
    }
    println!();
}
