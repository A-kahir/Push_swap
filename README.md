# Push Swap

Push Swap is a project from **42 School** that requires sorting a stack of numbers using two stacks and a limited set of operations.

## 🚀 **Project Overview**
The goal of **Push Swap** is to sort a list of integers using the fewest moves possible. The sorting must be performed using only **two stacks** and a set of predefined operations.

## 🔧 **Allowed Operations**
- `sa` : Swap the first two elements of stack A  
- `sb` : Swap the first two elements of stack B  
- `ss` : `sa` and `sb` at the same time  
- `pa` : Push the first element from stack B to stack A  
- `pb` : Push the first element from stack A to stack B  
- `ra` : Rotate stack A (shift all elements up)  
- `rb` : Rotate stack B (shift all elements up)  
- `rr` : `ra` and `rb` at the same time  
- `rra` : Reverse rotate stack A (shift all elements down)  
- `rrb` : Reverse rotate stack B (shift all elements down)  
- `rrr` : `rra` and `rrb` at the same time  

## 📜 **How It Works**
1. The program receives a list of integers as arguments.
2. It checks for duplicates and invalid inputs.
3. It sorts the numbers using the most efficient moves.
4. It outputs the necessary operations.

## 🛠 **Compilation**
To compile the project, use:
```bash
make
