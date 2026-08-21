# CS4501 - Compiler Design Laboratory Experiments

This repository contains complete implementations and laboratory documentation for all 10 experiments of the **CS4501 Compiler Design** course as per the Anna University / Chennai Institute of Technology curriculum.

Each experiment is organized in a dedicated directory containing the following 5 parameters as separate files:
1. **`1_Aim.md`** - Clear objective of the experiment.
2. **`2_Algorithm_Procedure.md`** - Step-by-step algorithm and execution procedure.
3. **`3_Pseudocode.md`** - High-level structured pseudocode.
4. **`4_Program_Code.*`** - Clean, standard, well-commented source code (C / LEX / YACC).
5. **`5_Result_Output.md`** - Sample input, execution trace, expected output, and verification result.

---

## Index of Experiments

| Exp No. | Experiment Title | Implementation Stack | Directory |
| :---: | :--- | :---: | :--- |
| **01** | Using the LEX tool / C, develop a lexical analyzer to recognize patterns and create a Symbol Table. | C | [`Experiment_01_Symbol_Table/`](./Experiment_01_Symbol_Table/) |
| **02** | Implement a Lexical Analyzer for C language tokens. | C / LEX | [`Experiment_02_Lexical_Analyzer/`](./Experiment_02_Lexical_Analyzer/) |
| **03** | Program to recognize a valid arithmetic expression (+, -, *, /). | LEX & YACC | [`Experiment_03_Arithmetic_Expression_YACC/`](./Experiment_03_Arithmetic_Expression_YACC/) |
| **04** | Program to recognize a valid variable/identifier starting with a letter. | LEX & YACC | [`Experiment_04_Valid_Variable_YACC/`](./Experiment_04_Valid_Variable_YACC/) |
| **05** | Program to recognize valid control structure syntax in C (if, while, for, switch). | LEX & YACC | [`Experiment_05_Control_Structures_YACC/`](./Experiment_05_Control_Structures_YACC/) |
| **06** | Implementation of an Arithmetic Calculator. | LEX & YACC | [`Experiment_06_Calculator_YACC/`](./Experiment_06_Calculator_YACC/) |
| **07** | Generate Three-Address Code (TAC) for arithmetic expressions. | LEX & YACC | [`Experiment_07_Three_Address_Code_YACC/`](./Experiment_07_Three_Address_Code_YACC/) |
| **08** | Implement Type Checking and Semantic Analysis using Symbol Table. | C / Symbol Table | [`Experiment_08_Type_Checking/`](./Experiment_08_Type_Checking/) |
| **09** | Implement Simple Code Optimization Techniques (Constant Folding, Strength Reduction, Algebraic Simplification). | C | [`Experiment_09_Code_Optimization/`](./Experiment_09_Code_Optimization/) |
| **10** | Implement Target Code Generation (Three-Address Code to 8086 Assembly Language). | C / 8086 ASM | [`Experiment_10_Target_Code_Generation/`](./Experiment_10_Target_Code_Generation/) |

---

## Quick Compilation & Execution Guide

### 1. Pure C Programs (Ex. 1, 2, 8, 9, 10)
```bash
gcc 4_Program_Code.c -o program
./program
```

### 2. LEX & YACC Programs (Ex. 3, 4, 5, 6, 7)
```bash
lex 4_Program_Code.l
yacc -d 4_Program_Code.y
gcc lex.yy.c y.tab.c -o parser -lm
./parser
```

---

## Remote Repository & Pushing Instructions

To push this repository to GitHub:
```bash
cd Compiler-Design-Experiments
git remote add origin https://github.com/biruthiviraj6-cell/Compiler-Design-Experiments.git
git branch -M main
git push -u origin main
```
