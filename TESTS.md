Test 1 - No remainder:
Input
    45
    5, 10
    10, 25
    20, 50
    30, 70

Output
    1 @ 5 = 10
    4 @ 10 = 100
    Remainder: 0
    Value: 110 
-----------------------------------
Test 2 - Length that is too large but is best value:
Input
    50
    6, 12
    8, 15
    10, 20
    20, 45
    1000, 70

Output
    1 @ 6 = 12
    2 @ 20 = 90
    Remainder: 4
    Value: 102
-----------------------------------
Test 3 - Remainder expected:
Input
    17
    5, 10
    8, 15
    10, 20

Output
    3 @ 5 = 30
    Remainder: 2
    Value: 30
-----------------------------------
Test 4 - All pieces too long:
Input
    4
    5, 10
    7, 15
    8, 20
    10, 30

Output
    Remainder: 4
    Value: 0
-----------------------------------
Test 5 - 0 initial rod length:
Input
    0
    5, 10
    10, 18
    15, 25

Ouput
    Remainder: 0
    Value: 0
-----------------------------------
Test 6 - 0 piece lengths:
Input
    10
    5, 10
    10, 18
    15, 25

Ouput
    2 @ 5 = 20
    Remainder: 0
    Value: 20
-----------------------------------
Test 7 - String input:
Input
    abc

Ouput
    Invalid input. Please enter a valid integer.
    Enter rod length:
    // Re-ask for input
-----------------------------------
Test 8 - Negative input:
Input
    -1

Ouput
    Invalid input. Please enter a valid integer.
    Enter rod length:
    // Re-ask for input