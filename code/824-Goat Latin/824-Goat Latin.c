/*
LeetCode 824 - Goat Latin

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

// If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
// For example, the word "apple" becomes "applema".
// If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
// Return the final sentence representing the conversion from sentence to Goat Latin.



// Example 1:

// Input: sentence = "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
// Example 2:

// Input: sentence = "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


// Constraints:

// 1 <= sentence.length <= 150
// sentence consists of English letters and spaces.
// sentence has no leading or trailing spaces.
// All the words in sentence are separated by a single space.

#define MAX_LATIN_LEN 2048


char * toGoatLatin(char * sentence){
    int vowels[256];
    memset(vowels, 0, sizeof(vowels));
    vowels['a'] = 1;
    vowels['e'] = 1;
    vowels['i'] = 1;
    vowels['o'] = 1;
    vowels['u'] = 1;
    vowels['A'] = 1;
    vowels['E'] = 1;
    vowels['I'] = 1;
    vowels['O'] = 1;
    vowels['U'] = 1;
    int n = strlen(sentence), i = 0, cnt = 1;
    char *ans = (char*)malloc(sizeof(char) * MAX_LATIN_LEN);
    int pos = 0;
    while (i < n) {
        int j = i;
        while (j < n && sentence[j] != ' ') {
            j ++;
        }
        cnt ++;
        if (cnt != 2) {
            ans[pos ++] = ' ';
        }
        if (vowels[sentence[i]]) {
            memcpy(ans + pos, sentence + i, sizeof(char) * (j - i));
            pos += j - i;
            ans[pos ++] = 'm';
            memset(ans + pos, 'a', cnt);
            pos += cnt;
        } else {
            memcpy(ans + pos, sentence + i + 1, sizeof(char) * (j - i - 1));
            pos += j - i - 1;
            ans[pos ++] = sentence[i];
            ans[pos ++] = 'm';
            memset(ans + pos, 'a', cnt);
            pos += cnt;
        }
        i = j + 1;
    }
    ans[pos] = 0;
    return ans;
}
