use proconio::input;
use proconio::marker::Chars;
fn main() {
    input! {
      s:Chars,
    }
    print!("0");
    print!("{}", s[0]);
    print!("{}", s[1]);
    println!("{}", s[2]);
}
