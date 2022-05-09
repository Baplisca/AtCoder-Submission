use proconio::input;
use std::cmp::Reverse;
fn main() {
    input! {
      n:i32,mut m:i32,
      mut a:[i32;n]
    }
    a.sort_by_key(|&x| Reverse(x));
    let mut res = 0;
    for i in a {
        res += 1;
        if m <= i {
            println!("{}", res);
            break;
        }
        m -= i;
    }
}
