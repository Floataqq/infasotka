use std::io;

pub fn generate_all_combinations(n: i32, k: i32) -> Vec<Vec<i32>> {
    let mut result = vec![];
    create_all_state(1, n, k, &mut vec![], &mut result);

    result
}

fn create_all_state(
    increment: i32,
    total_number: i32,
    level: i32,
    current_list: &mut Vec<i32>,
    total_list: &mut Vec<Vec<i32>>,
) {
    if level == 0 {
        total_list.push(current_list.clone());
        return;
    }

    for i in increment..(total_number - level + 2) {
        current_list.push(i);
        create_all_state(i + 1, total_number, level - 1, current_list, total_list);
        current_list.pop();
    }
}

fn main() {
    let mut inp = String::new();

    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read input.");
    let a: i32 = inp.trim().parse().expect("Invalid input");

    let mut inp = String::new();

    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read input.");
    let b: i32 = inp.trim().parse().expect("Invalid input");

    println!("{:#?}", generate_all_combinations(a, b));
}