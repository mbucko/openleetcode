Palindrome Number Solution
Idea

Instead of turning the number into a string, I reverse just the second half of the number and check if it matches the first half.

Steps
If x is negative, return False (the minus sign breaks it).
If x ends in 0 and isn't 0, return False (nothing starts with 0).
Keep taking the last digit off x and adding it to reversed_half until reversed_half is bigger than or equal to x.
If the number of digits is even, the halves should be equal. If it's odd, the middle digit ends up in reversed_half, so I drop it with // 10 before comparing.

Example: 13531
13531 → x = 1353, reversed_half = 1
1353 → x = 135, reversed_half = 13
135 → x = 13, reversed_half = 135
Stop. 135 // 10 = 13, which equals x, so it's True.

Complexity
Time: O(log n), since it only goes through about half the digits
Space: O(1)
Note

Make sure to use // and not /, because / gives a decimal in Python. I also had a bug where I used x //= 1 instead of x //= 10, and test case 10 (13531) caught it.

AI Use: This was written by Claude, I asked it to write it up. 