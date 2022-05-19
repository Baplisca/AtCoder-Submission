use std::usize;

use proconio::{input, marker::Chars};

fn main() {
    input! {
      s1:String,s2:String
    }
    let res = s1.len() * s2.len();
    println!("{}", res);
}
