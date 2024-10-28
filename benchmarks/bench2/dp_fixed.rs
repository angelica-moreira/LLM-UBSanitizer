fn main() {
    let x = 5;
    let r = &x; // Safe reference to 'x'

    println!("r: {}", *r); // No 'unsafe' block needed
    // 'x' goes out of scope here, which is fine because we're done using 'r'
}