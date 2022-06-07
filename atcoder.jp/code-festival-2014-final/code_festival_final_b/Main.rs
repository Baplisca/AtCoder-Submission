use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, usize};

fn main() {
    input! {
        s:Chars
    }
    let mut res = 0;
    let mut odd = 0;
    for i in s {
        if odd == 1 {
            res -= i as i32 - 48;
        } else {
            res += i as i32 - 48;
        }
        odd ^= 1;
    }
    println!("{}", res);
}
