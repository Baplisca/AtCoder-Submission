use proconio::{input, marker::Chars};
use std::{io::Chain, usize};

fn main() {
    input! {
        n:usize
    }
    let mut res = 0;
    for i in 0..n {
        let mut ttl = 0;
        input! {
            a:i32,b:i32,c:i32,d:i32,e:i32
        }
        ttl += a + b + c + d + e;
        if ttl < 20 {
            res += 1;
        }
    }
    println!("{}", res);
}
