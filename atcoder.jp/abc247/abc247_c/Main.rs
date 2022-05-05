use proconio::input;
fn main() {
    input! {
      n:i32
    }
    let mut ans = String::from("1");
    // println!("{}", ans);
    for i in 1..n {
        let tmp = ans.clone();
        ans = ans.to_string() + " " + &(i + 1).to_string() + " " + &tmp;
    }
    println!("{}", ans);
}
