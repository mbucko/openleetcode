# Approach

Use a dictionary to map each Roman numeral to its integer value.

Work through the string from left to right. If the current numeral is smaller than the next numeral, subtract its value from the total.
Otherwise, add its value to the total.