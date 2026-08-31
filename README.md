# 42 C++ Modules 🚀

This repository contains my solutions to the **C++ pool** modules (C00 to C09) from the [42 School](https://42.fr/) curriculum.

These modules are designed to transition students from procedural C programming to Object-Oriented Programming (OOP) in C++98, focusing strictly on memory safety, the Orthodox Canonical Class Form, and the Standard Template Library (STL).

## 📚 Curriculum Breakdown

Each module introduces progressively more complex OOP paradigms and C++ features:

### Core OOP (C00 - C04)
* **CPP00:** Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and basic OOP.
* **CPP01:** Memory allocation (`new`/`delete`), references, pointers to members, file streams.
* **CPP02:** Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.
* **CPP03:** Inheritance (Single and Multiple).
* **CPP04:** Subtype polymorphism, abstract classes, interfaces.

### Advanced Concepts (C05 - C09)
* **CPP05:** Exception handling, try/catch blocks.
* **CPP06:** C++ Casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`).
* **CPP07:** C++ Templates (Function templates and Class templates).
* **CPP08:** Templated containers, iterators, and algorithms (STL).
* **CPP09:** Practical applications of STL containers (Maps, Stacks, Vectors, Deques) for complex algorithmic problems (e.g., Reverse Polish Notation, Ford-Johnson merge-insert sort).

## 🛠 Rules & Technologies
* **Language:** C++98
* **Compiler:** `c++` with flags `-Wall -Wextra -Werror -std=c++98`
* **Style:** The Orthodox Canonical Class Form is strictly enforced from Module 02 onwards, requiring:
  1. Default Constructor
  2. Copy Constructor
  3. Copy Assignment Operator
  4. Destructor

## 🚀 Execution
Each subfolder contains its own `Makefile`. To compile and run a specific exercise:
```bash
cd c00/ex01
make
./phonebook
```
