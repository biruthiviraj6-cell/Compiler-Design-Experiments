# Experiment 09: Code Optimization Techniques

### Sample Input:
```text
a=2+4;
b=d*1;
c=s*2;
END
```

### Sample Output:
```text
===================================================
       CODE OPTIMIZATION TECHNIQUES IN C
===================================================
Enter Three Address Code lines (Type 'END' to finish):
a=2+4;
b=d*1;
c=s*2;
END

--- Unoptimized Code ---
a=2+4;
b=d*1;
c=s*2;

--- Optimized Code ---
a=6;		// Constant Folding
b=d;		// Algebraic Simplification (X*1 or X/1 -> X)
c=s+s;		// Strength Reduction (X*2 -> X+X)
===================================================
```

### Result:
Thus, the C program for simple code optimization techniques (Constant Folding, Strength Reduction, and Algebraic Simplification) was successfully implemented and verified.
