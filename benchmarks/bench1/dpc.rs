pub fn main() {
    let x = 5; // 'x' is declared in the main scope
    let r: &i32 = &x; // 'r' references 'x' and they share the same lifetime
    println!("r: {}", r); // Now safe to access, as 'x' is still valid
}
