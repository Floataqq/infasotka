use std::io;

pub fn func(text: &str) -> String {
    text.chars().rev().collect()
}

fn main() {
    let mut inp = String::new();

    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read input.");

    println!("{}", func(&inp));
}