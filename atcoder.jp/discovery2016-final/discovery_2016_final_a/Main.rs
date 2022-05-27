use proconio::{input, marker::Chars};
use std::usize;

fn main() {
    input! {
        n:usize,mut a:[i32;n]
    }
    let mut b = vec![0; n].into_boxed_slice();
    b[0] = 100000;
    b[1] = 50000;
    b[2] = 30000;
    b[3] = 20000;
    b[4] = 10000;

    let mut res = vec![0; n].into_boxed_slice();
    for i in 0..n {
        res[(a[i] - 1) as usize] = b[i];
    }
    for i in 0..n {
        println!("{}", res[i]);
    }
}
