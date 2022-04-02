// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True

// Example 2:
// Input: "abca"
// Output: True

// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

bool isPalindrome(char * s, int l, int r) {
    while (l < r) {
        if (s[l] == s[r]) {
            l ++;
            r --;
        } else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(char * s){
    int n = strlen(s);
    int l = 0, r = n - 1;
    while (s[l] == s[r] && l < r) {
        l ++;
        r --;
    }
    if (l < r) {
        return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r); 
    } else {
        return true;
    }
}