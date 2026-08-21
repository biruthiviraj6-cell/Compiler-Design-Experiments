# Experiment 02: Lexical Analyzer Implementation

## Pseudocode
```text
OPEN file fname
WHILE NOT EOF(fp):
    c = read_char(fp)
    IF comment_start(c):
        skip_comment(fp)
    ELSE IF isalpha(c):
        buffer = collect_alphanumeric(c, fp)
        IF buffer IN preprocessor_directives:
            PRINT "Preprocessor directive", buffer
        ELSE IF buffer IN header_files:
            PRINT "Header file", buffer
        ELSE IF buffer IN keywords:
            PRINT "Keyword", buffer
        ELSE:
            PRINT "Identifier", buffer
    ELSE IF isdigit(c):
        buffer = collect_digits(c, fp)
        PRINT "Number", buffer
    ELSE IF isdelim(c):
        PRINT "Delimiter", c
    ELSE IF isop(c):
        ch2 = check_compound_operator(c, fp)
        PRINT "Operator", c + ch2
CLOSE file
```
