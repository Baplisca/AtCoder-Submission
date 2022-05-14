use proconio::{input, marker::Chars};

fn main() {
    input! {
      n:i32
    }
    for i in n - 8..n {
        println!("{}", i + 1);
    }
}
