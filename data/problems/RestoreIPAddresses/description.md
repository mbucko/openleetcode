# Restore IP Addresses

A valid IPv4 address is four numbers from ``0`` to ``255`` separated by dots, with no leading zeros in any number. For example ``"10.0.12.255"`` is valid, while ``"10.01.2.3"``, ``"256.1.1.1"`` and ``"1.2.3"`` are not.

You are given a string ``s`` of digits. Return every valid IP address you can make by inserting exactly three dots into ``s`` without reordering or removing digits. List them in ascending lexicographic order.
\
\
\
**Example 1:**

>**Input:** s = "19216811"\
>**Output:** ["1.92.168.11","19.2.168.11","19.21.68.11","19.216.8.11","19.216.81.1","192.1.68.11","192.16.8.11","192.16.81.1","192.168.1.1"]

**Example 2:**

>**Input:** s = "0000"\
>**Output:** ["0.0.0.0"]

**Example 3:**

>**Input:** s = "1111111111111"\
>**Output:** []\
>**Explanation:** 13 digits can't fit into four numbers of at most 3 digits each.

**Constraints:**

* ``1 <= s.length <= 20``
* ``s`` contains only digits.
