use proconio::{input, marker::Chars};
use std::{cmp, i32::MAX, io::Chain, string, usize};

fn main() {
    input! {
        n:usize
    }

    for i in 0..n {
        let mut res = "indeednow".chars().collect::<Vec<_>>();
        res.sort();
        input! {
            mut s:Chars
        }
        s.sort();
        if s == res {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
