# Experiment 01: Symbol Table Implementation

### Sample Output:
```text
Enter your choice:
1.Create
2.Insert
3.Modify
4.Search
5.Display
6.Exit
Choice: 1
Enter the no. of entries: 3
Enter variable 1 and value: AIM 45
Enter variable 2 and value: ASK 34
Enter variable 3 and value: BALL 56

The table after creation is:
--------------------------
VARIABLE	VALUE
--------------------------
AIM		45
ASK		34
BALL		56
--------------------------

Enter your choice:
Choice: 2
Enter the variable and value: SIM 25

The table after insertion is:
--------------------------
VARIABLE	VALUE
--------------------------
AIM		45
ASK		34
BALL		56
SIM		25
--------------------------

Enter your choice:
Choice: 3
Enter the variable to be modified: ASK
Current value of variable 'ASK' is 34
Enter the new variable name and its value: RIM 40

The table after modification is:
--------------------------
VARIABLE	VALUE
--------------------------
AIM		45
RIM		40
BALL		56
SIM		25
--------------------------

Enter your choice:
Choice: 4
Enter the variable to be searched for: RIM
The location of the variable is 2
The value of RIM is 40

Enter your choice:
Choice: 5
--------------------------
VARIABLE	VALUE
--------------------------
AIM		45
RIM		40
BALL		56
SIM		25
--------------------------

Enter your choice:
Choice: 6
Exiting...
```

### Result:
Thus, the C program to implement the Symbol Table with Create, Insert, Modify, Search, and Display operations was executed and verified successfully.
