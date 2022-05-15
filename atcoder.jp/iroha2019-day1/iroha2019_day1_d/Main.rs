use std::usize;

use proconio::{input, marker::Chars};

fn main() {
    input! {
      n:i32,x:i32,y:i32,
      mut a:[i32;n]
    }
    a.sort();
    a.reverse();
    let mut X = x;
    let mut Y = y;
    for i in 0..n {
        if (i % 2 == 1) {
            continue;
        }
        X += a[i as usize];
        Y += a[(i + 1) as usize];
    }
    let mut res = "Draw";
    if X > Y {
        res = "Takahashi"
    } else if X < Y {
        res = "Aoki"
    }
    println!("{}", res);
}
