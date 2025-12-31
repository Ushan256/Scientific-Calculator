# Scientific Calculator
A feature-rich console application developed in C++ to perform advanced mathematical operations. This project utilizes Object-Oriented Programming (OOP) principles to manage calculation logic, memory storage, and history tracking.

## Overview
This calculator goes beyond basic arithmetic by including trigonometric, logarithmic, and statistical functions. It features a persistent history log that saves calculations to a file, allowing users to review their past work even after restarting the program. The architecture is built around a central `ScientificCalculator` class that encapsulates all operations and data management.

## Features
### Mathematical Operations
* **Basic Arithmetic:** Addition, subtraction, multiplication, division, and modulus.
* **Trigonometry:** Sine, Cosine, Tangent, and their inverse functions (results in degrees).
* **Exponential & Log:** Power, square root, cube root, natural log (ln), and log base 10.
* **Algebra & Stats:** Factorial calculation, Permutation (nPr), Combination (nCr), and Quadratic Equation solver.

### Advanced Capabilities
* **Memory Functions:** Standard calculator memory operations (M+, M-, MR, MC).
* **History Tracking:** Automatically saves every calculation to a text file (`calc_log.txt`).
* **Error Handling:** robust checks for division by zero, negative roots, and domain errors.

## Technical Details
* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **File Handling:** Uses `fstream` to append and read calculation history.
* **Standard Libraries:** `cmath` for mathematical functions, `vector` for dynamic history storage.

## How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Ushan256/Scientific-Calculator.git](https://github.com/Ushan256/Scientific-Calculator.git)
    ```
2.  Compile the source code:
    ```bash
    g++ main.cpp -o calculator
    ```
3.  Run the application:
    ```bash
    ./calculator
    ```

## Usage
* Navigate the menu by entering the corresponding number.
* For trigonometric functions, ensure inputs are in **Degrees**.
* The history is automatically saved to `calc_log.txt` in the same directory.
