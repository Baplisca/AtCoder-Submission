use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        s:String
    }
    let res = s.replace("HAGIYA", "HAGIXILE");
    println!("{}", res);
}
