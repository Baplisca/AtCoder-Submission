use proconio::input;
fn main() {
    input! {
      s:String
    }

    for c in s.chars() {
        let res = if c == 'O' {
            'A'
        } else if c == 'A' {
            'O'
        } else {
            c
        };
        print!("{}", res);
    }
    println!();
}
