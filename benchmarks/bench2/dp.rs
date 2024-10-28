fn main() {
    let r: *const i32; // Declare a raw pointer to an integer
    {
        let x = 5;
        r = &x; // 'r' points to 'x', but 'x' will be dropped after this scope
    }
    // 'x' is now out of scope, but we try to dereference 'r'
    unsafe {
        println!("r: {}", *r); // Dangling pointer, undefined behavior
    }
}
