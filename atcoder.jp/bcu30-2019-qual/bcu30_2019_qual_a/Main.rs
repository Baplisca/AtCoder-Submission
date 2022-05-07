use proconio::input;
fn main() {
    input! {
      n:i32,
      mut p:i32,
      a:[i32; n],
    }
    let mut ans = 0;
    for i in a {
        if p < i {
            break;
        }
        p -= i;
        ans += 1;
    }
    println!("{}", ans);
}
