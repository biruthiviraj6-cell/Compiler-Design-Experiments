# Experiment 02: Lexical Analyzer Implementation

### Sample Input (`iplex.c`):
```c
#include <stdio.h>
void main() {
    int a = 10, b = 20;
    int c = a + b;
    printf("%d", c);
}
```

### Sample Output:
```text
Enter filename: iplex.c

Delimiter		#
Preprocessor directive	include
Delimiter		<
Header file		stdio.h
Delimiter		>
Keyword			void
Identifier		main
Delimiter		(
Delimiter		)
Delimiter		{
Keyword			int
Identifier		a
Operator		=
Number			10
Delimiter		,
Identifier		b
Operator		=
Number			20
Delimiter		;
Keyword			int
Identifier		c
Operator		=
Identifier		a
Operator		+
Identifier		b
Delimiter		;
Identifier		printf
Delimiter		(
Delimiter		)
Delimiter		;
Delimiter		}

End of file
```

### Result:
Thus, the C program for implementation of a Lexical Analyzer was executed and verified successfully.
