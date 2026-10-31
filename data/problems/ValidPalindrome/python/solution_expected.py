class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            # Skip characters that aren't letters or numbers.
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1

            # Compare the two characters, ignoring case.
            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True
