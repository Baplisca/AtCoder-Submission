use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        h:i32,w:i32,r:i32,c:i32
    }
    let mut ans = 4;
    if (r == 1 || r == h) && (c == 1 || c == w) {
        ans = 2;
    } else if (r == 1 || r == h) || (c == 1 || c == w) {
        ans = 3;
    }
    ans -= (h == 1) as i32;
    ans -= (w == 1) as i32;
    println!("{}", ans);
}
