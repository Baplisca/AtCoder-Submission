use proconio::input;

fn main() {
    input! {
      l:i32,x:i32
    }
    let tmp = x % (l * 2);
    // println!("{}", tmp);
    if tmp > l {
        println!("{}", 2 * l - tmp);
    } else {
        println!("{}", tmp);
    }
}
