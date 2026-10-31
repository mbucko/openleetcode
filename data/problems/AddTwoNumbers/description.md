# Add Two Numbers

Two non-negative integers are stored as linked lists of digits, with the **least significant digit first**. For example, the number 381 is stored as ``1 -> 8 -> 3``.

Add the two numbers and return the sum in the same format.

Neither number has leading zeros, except the number 0 itself.

The test runner passes each list as an array of digits from head to tail, so ``addTwoNumbers`` takes and returns arrays.
\
\
\
**Example 1:**

>**Input:** l1 = [1,8,3], l2 = [6,2,4]\
>**Output:** [7,0,8]\
>**Explanation:** 381 + 426 = 807.

**Example 2:**

>**Input:** l1 = [0], l2 = [0]\
>**Output:** [0]

**Example 3:**

>**Input:** l1 = [9,9], l2 = [1]\
>**Output:** [0,0,1]\
>**Explanation:** 99 + 1 = 100, so the carry adds a new digit.

**Constraints:**

* Each list has between ``1`` and ``100`` nodes.
* ``0 <= Node.val <= 9``
* Neither number has leading zeros, except the number 0 itself.
