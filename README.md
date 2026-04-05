# C++ Core Architecture Modules | 1337 Coding School

## Overview
This repository contains a progressive series of C++ projects developed during my curriculum at 1337 (42 Network). Instead of using standard frameworks, these modules are built entirely from scratch to enforce a deep, low-level understanding of Object-Oriented Programming (OOP), memory management, and system architecture.

## Core Concepts & Architecture Mastered
* **Orthodox Canonical Form:** Strict implementation of default constructors, copy constructors, assignment operators, and destructors to ensure memory safety.
* **Low-Level Memory Management:** Manual allocation and deallocation to completely eliminate memory leaks and dangling pointers.
* **Advanced Polymorphism:** Designing scalable systems using abstract classes, interfaces, and virtual functions.
* **Generic Programming:** Utilizing C++ Templates for type-safe, reusable data structures.
* **Standard Template Library (STL):** Advanced algorithmic implementation using vectors, maps, iterators, and stacks.

## Repository Structure
The curriculum is divided into modules, each scaling in complexity:
* **Modules 00-04:** Core OOP, Encapsulation, Inheritance, and Subtype Polymorphism.
* **Modules 05-08:** Exception handling, Templates, and algorithmic optimization.
* **Module 09:** Complex data processing and performance benchmarking using the STL.

## Usage & Compilation
Each module is self-contained with its own strict `Makefile` that compiles with `-Wall -Wextra -Werror` flags in C++98 standard. 

```bash
cd CPP_Module_04/ex0X
make
./[executable_name]
