use proconio::{input, marker::Chars};
use std::usize;

fn main() {
    input! {
        mut s:Chars
    }
    s.sort();
    let res = s.iter().collect::<String>();
    if res == "ahooy" {
        println!("{}", "YES");
    } else {
        println!("NO");
    }
}
