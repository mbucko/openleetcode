# Best Time to Buy and Sell Stock

You are given an array ``prices`` where ``prices[i]`` is the price of a stock on day ``i``.

You may make at most one trade: pick one day to buy a single share and a later day to sell it.

Return the largest profit this trade can make. If no trade makes a profit, return ``0``.
\
\
\
**Example 1:**

>**Input:** prices = [8,2,6,4,9,3]\
>**Output:** 7\
>**Explanation:** Buy on day 1 (price = 2) and sell on day 4 (price = 9) for a profit of 9 - 2 = 7. Selling before buying is not allowed, so buying at 2 and selling at 8 does not count.

**Example 2:**

>**Input:** prices = [9,7,5,2,1]\
>**Output:** 0\
>**Explanation:** The price only goes down, so no trade makes a profit.

**Constraints:**

* ``1 <= prices.length <= 10^5``
* ``0 <= prices[i] <= 10^4``
