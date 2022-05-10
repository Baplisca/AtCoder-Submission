use proconio::input;

fn main() {
    input! {
      n:i32,
      mut a:[(usize,usize); n],
    }
    const m: usize = 1000010;
    let mut s: Vec<isize> = vec![0; m];
    for (i, j) in a {
        s[i] += 1;
        s[j] -= 1;
    }
    for i in 0..m - 1 {
        s[i + 1] += s[i];
    }
    let mut res = 0;
    for i in 0..m - 1 {
        if s[i + 1] > 0 && s[i] == 0 {
            res += 1;
        }
    }
    println!("{}", res);
}
