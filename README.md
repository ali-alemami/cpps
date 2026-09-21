*This project has been created as part of the 42 curriculum by aalemami.*

# 42 C++ Modules (CPP 00–09)

---

## Description

This repository contains my solutions to the **C++ Modules** (CPP00 to CPP09) from the [42 School](https://42.fr/) curriculum.

The modules guide the transition from procedural C programming to Object-Oriented Programming (OOP) in C++98, emphasizing memory management, the Orthodox Canonical Class Form, subtype polymorphism, template metaprogramming, and the Standard Template Library (STL).

---

## Curriculum Breakdown

### Core OOP (CPP 00 – CPP 04)
* **CPP00**: Namespaces, classes, member functions, stdio streams, initialization lists, `static`, `const`.
* **CPP01**: Dynamic allocation (`new`/`delete`), references, pointers to members, file streams.
* **CPP02**: Ad-hoc polymorphism, operator overloading, fixed-point arithmetic, and the Orthodox Canonical Class Form.
* **CPP03**: Single and multiple inheritance, constructor chaining, diamond problem resolution.
* **CPP04**: Subtype polymorphism, abstract base classes, pure virtual functions, and interface definitions.

### Advanced Concepts (CPP 05 – CPP 09)
* **CPP05**: Exception handling mechanisms and nested exception classes.
* **CPP06**: C++ type casting (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`) and type serialization.
* **CPP07**: Function templates, class templates, and template specialization.
* **CPP08**: Templated STL containers, iterators, and generic algorithm functions.
* **CPP09**: Practical algorithmic applications of STL containers (Reverse Polish Notation, Ford-Johnson merge-insert sort with Jacobsthal sequences, Bitcoin exchange lookup).

---

## Rules and Standards

* **Standard**: C++98
* **Compilation Flags**: `c++ -Wall -Wextra -Werror -std=c++98`
* **Orthodox Canonical Class Form**: Strictly implemented for all classes from Module 02 onward:
  1. Default constructor
  2. Copy constructor
  3. Copy assignment operator
  4. Destructor (virtual in base classes)

---

## Compilation and Execution

Each exercise directory contains an independent `Makefile`. To build and execute any module:

```bash
cd c00/ex01
make
./phonebook
```

Clean build artifacts:
```bash
make clean   # Remove object files
make fclean  # Remove object files and binary
make re      # Full rebuild
```

---

## Resources

- [cppreference.com](https://en.cppreference.com/) — C++ language and standard library reference.
- [C++ Primer (5th Edition)](https://www.oreilly.com/library/view/c-primer-fifth/9780133053043/) — Foundational reference for object-oriented C++.

### AI Usage

AI tools were used as a development reference for:
- Clarifying subtleties of C++98 template syntax and container iterator traits.
- Reviewing Jacobsthal grouping intervals for the Ford-Johnson sorting algorithm in Module 09.
- Verifying Orthodox Canonical Form completeness across class hierarchies.
