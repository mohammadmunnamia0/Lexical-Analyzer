
# **Lexical Analyzer in C**

This project is a simple **Lexical Analyzer** written in C. It takes a mathematical expression, processes it, and breaks it down into **tokens**, classifying each token into categories like **NUMBER**, **OPERATOR**, **IDENTIFIER**, or **BRACKET**.

---

## **Program Description**

### **What is a Lexical Analyzer?**

A **Lexical Analyzer** is a fundamental component of compilers or interpreters. It scans the input code or expressions and converts them into a sequence of **tokens**, which are the smallest units of meaning. 

For instance, consider the expression:

```
Calculate=√[{(((13*20)+50)-80)/2}]%2
```

The tokens are:

- **Token**: `Calculate`, **Type**: `IDENTIFIER`
- **Token**: `=`, **Type**: `OPERATOR`
- **Token**: `√`, **Type**: `FUNCTION`
- **Token**: `[`, **Type**: `BRACKET`
- ... and so on.

### **Purpose of This Program**

This program demonstrates the basic operation of a lexical analyzer. It identifies:
- **Identifiers** (e.g., `Calculate`, `x`, `y`).
- **Numbers** (e.g., `13`, `20`, `50`).
- **Operators** (e.g., `+`, `-`, `*`, `/`, `%`).
- **Brackets and Parentheses** (e.g., `[`, `]`, `{`, `}`).
- **Functions** (e.g., `√`).

It provides a foundational understanding for students and beginners in programming.

---

## **How to Run the Program**

### **Requirements**
- A C compiler (e.g., GCC).
- A terminal or IDE (such as Visual Studio Code or Code::Blocks).

### **Steps to Compile and Run**
1. Save the code in a file named `lexical_analyzer.c`.
2. Open a terminal and navigate to the directory where the file is saved.
3. Compile the program using the following command:
   ```bash
   gcc lexical_analyzer.c -o lexical_analyzer
   ```
4. Run the program with:
   ```bash
   ./lexical_analyzer
   ```

---

## **Input and Output**

### **Input**
The input is hardcoded in the program. The default example expression is:

```
Calculate=√[{(((13*20)+50)-80)/2}]%2
```

You can modify the expression by changing the `expression` variable in the code:
```c
const char expression[] = "your_expression_here";
```

### **Output**
The program tokenizes the input and produces output in this format:

```
Analyzing Expression: Calculate=√[{(((13*20)+50)-80)/2}]%2

Token: Calculate	Type: IDENTIFIER
Token: =         	Type: OPERATOR
Token: √         	Type: FUNCTION
Token: [         	Type: BRACKET
Token: {         	Type: BRACE
Token: (         	Type: PARENTHESIS
Token: (         	Type: PARENTHESIS
Token: (         	Type: PARENTHESIS
Token: 13        	Type: NUMBER
Token: *         	Type: OPERATOR
Token: 20        	Type: NUMBER
Token: )         	Type: PARENTHESIS
Token: +         	Type: OPERATOR
Token: 50        	Type: NUMBER
Token: )         	Type: PARENTHESIS
Token: -         	Type: OPERATOR
Token: 80        	Type: NUMBER
Token: )         	Type: PARENTHESIS
Token: /         	Type: OPERATOR
Token: 2         	Type: NUMBER
Token: }         	Type: BRACE
Token: ]         	Type: BRACKET
Token: %         	Type: OPERATOR
Token: 2         	Type: NUMBER
```

---

## **Code Overview**

### **Key Features**
1. **Token Types**:
   - Numbers are categorized as **NUMBER**.
   - Mathematical operators like `+`, `-`, `*`, `/`, `%`, and `=` are identified as **OPERATOR**.
   - Brackets, braces, and parentheses (`[`, `{`, `(`) are recognized as **BRACKETS**, **BRACES**, and **PARENTHESES** respectively.
   - Identifiers like `Calculate` are labeled as **IDENTIFIER**.
   - The square root (`√`) is classified as **FUNCTION**.

2. **Multi-digit Number Support**:
   - The program can handle numbers like `13` and `20` without splitting them into separate tokens.

3. **Flexible Expression Parsing**:
   - The code can be updated easily to handle new expressions.

### **How It Works**
1. **Expression Analysis**:
   - The program reads the expression character by character.
   - It identifies each token based on character type (e.g., digits, letters, operators, etc.).
2. **Token Classification**:
   - Tokens are categorized and printed with their type.

---

## **Customizing the Code**

### Modify the Input Expression
To analyze a different expression, update the `expression` variable in the code:
```c
const char expression[] = "your_expression_here";
```

### Examples:
1. `x+y*z/(a-3)`
2. `(12 + 25) * (x / y) % 5`

---

## **Common Errors and Solutions**

### Error: `Token: � Type: UNKNOWN`
- This occurs when the program encounters non-ASCII characters like `√`.
- Solution:
  - Use `sqrt` as a placeholder for the square root symbol.
  - Modify the expression to:
    ```c
    const char expression[] = "Calculate=sqrt[{(((13*20)+50)-80)/2}]%2";
    ```

### Error: `gcc not found`
- Ensure GCC is installed:
  - On Ubuntu/Debian:
    ```bash
    sudo apt install gcc
    ```
  - On macOS:
    ```bash
    brew install gcc
    ```


