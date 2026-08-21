# Experiment 08: Type Checking Implementation

### Sample Output 1 (Matching Types):
```text
======================================
   IMPLEMENTATION OF TYPE CHECKING
======================================

DECLARATIONS (Enter 'END' to finish):
  int a;
  int b;
  int c;
  END

EXPRESSIONS (Enter 'END' to finish):
  a = b * c;
  END

======================================
 SEMANTIC ANALYZER (TYPE CHECKING):
======================================
No type mismatch in expression: a = b * c;
```

### Sample Output 2 (Type Mismatch):
```text
======================================
   IMPLEMENTATION OF TYPE CHECKING
======================================

DECLARATIONS (Enter 'END' to finish):
  int a;
  float b;
  int c;
  END

EXPRESSIONS (Enter 'END' to finish):
  a = b + c;
  END

======================================
 SEMANTIC ANALYZER (TYPE CHECKING):
======================================
Type mismatch between operands (float and int) in 'a = b + c;'
```

### Result:
Thus, the C program for type checking was successfully implemented and verified to detect type consistency in arithmetic expressions using a symbol table.
