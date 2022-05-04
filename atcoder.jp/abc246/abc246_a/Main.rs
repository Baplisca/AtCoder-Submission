use proconio::input;
fn main() {
    input! {
      x1:i32,y1:i32,
      x2:i32,y2:i32,
      x3:i32,y3:i32
    }
    let mut x = x2;
    if x1 == x2 {
        x = x3
    } else if x2 == x3 {
        x = x1
    }
    let mut y = y2;
    if y1 == y2 {
        y = y3
    } else if y2 == y3 {
        y = y1
    };
    println!("{} {}", x, y);
}
