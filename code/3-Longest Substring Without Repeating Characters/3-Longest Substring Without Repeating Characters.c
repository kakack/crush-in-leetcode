/*Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

选一个hash表，其实就是通过字符表达的值作为index能找到其在string中位置的储存结构，然后从左往右扫描一遍，准备一个start指针，凡是找到一个重复的字符，那么先算一下是不是当时情况下的最长，然后更新最长值，接着把之前的start到被重复的字符的hash值重新设置为-1，然后把当前的hash值更新

*/

typedef struct {
    char key;
    UT_hash_handle hh;
}HashItem;

int lengthOfLongestSubstring(char * s){
    HashItem *mp = NULL;
    int start = -1, res = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            HashItem *tmp = NULL;
            HASH_FIND(hh, mp, &s[i - 1], sizeof(char), tmp);
            HASH_DEL(mp, tmp);
        }
        
        while (start + 1 < n) {
            HashItem* tmp_ = NULL;
            HASH_FIND(hh, mp, &s[start + 1], sizeof(char), tmp_);
            if (tmp_ == NULL) {
                tmp_  = (HashItem*)malloc(sizeof(HashItem));
                tmp_->key = s[start + 1];
                HASH_ADD(hh, mp, key, sizeof(char), tmp_);
                start ++; 
            } else {
                break;
            }
        }
        res = fmax(res, start - i + 1);
    }
    return res;
}