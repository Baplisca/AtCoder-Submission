use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        s:Chars,t:Chars,u:Chars
    }
    if s.len() == 5 && t.len() == 7 && u.len() == 5 {
        println!("valid");
    } else {
        println!("invalid");
    }
}
