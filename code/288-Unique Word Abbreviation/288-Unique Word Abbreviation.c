The abbreviation of a word is a concatenation of its first letter, the number of characters between the first and last letter, and its last letter. If a word has only two characters, then it is an abbreviation of itself.

// For example:

// dog --> d1g because there is one letter between the first letter 'd' and the last letter 'g'.
// internationalization --> i18n because there are 18 letters between the first letter 'i' and the last letter 'n'.
// it --> it because any word with only two characters is an abbreviation of itself.
// Implement the ValidWordAbbr class:

// ValidWordAbbr(String[] dictionary) Initializes the object with a dictionary of words.
// boolean isUnique(string word) Returns true if either of the following conditions are met (otherwise returns false):
// There is no word in dictionary whose abbreviation is equal to word's abbreviation.
// For any word in dictionary whose abbreviation is equal to word's abbreviation, that word and word are the same.
//  

// Example 1:

// Input
// ["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique", "isUnique"]
// [[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"], ["cake"]]
// Output
// [null, false, true, false, true, true]

// Explanation
// ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
// validWordAbbr.isUnique("dear"); // return false, dictionary word "deer" and word "dear" have the same abbreviation "d2r" but are not the same.
// validWordAbbr.isUnique("cart"); // return true, no words in the dictionary have the abbreviation "c2t".
// validWordAbbr.isUnique("cane"); // return false, dictionary word "cake" and word "cane" have the same abbreviation  "c2e" but are not the same.
// validWordAbbr.isUnique("make"); // return true, no words in the dictionary have the abbreviation "m2e".
// validWordAbbr.isUnique("cake"); // return true, because "cake" is already in the dictionary and no other word in the dictionary has "c2e" abbreviation.
//  

// Constraints:

// 1 <= dictionary.length <= 3 * 10^4
// 1 <= dictionary[i].length <= 20
// dictionary[i] consists of lowercase English letters.
// 1 <= word.length <= 20
// word consists of lowercase English letters.
// At most 5000 calls will be made to isUnique.

typedef struct {
    char key[5];  // 字符串的缩写
    char str[21]; // 原始字符串
    int count;    // 表示字符串缩写相同的字符串有多少个，abc adc 就是不同的两个
    UT_hash_handle hh;
} ValidWordAbbr;

ValidWordAbbr *g_user = NULL;

/* 获取一个字符串的缩写 */
char *GetAbbreviation(char *str)
{
    char *result = (char*)calloc(5, sizeof(char));
    int len = strlen(str);
    if (len == 2) {
        return str;
    }
    sprintf(result, "%c%d%c", str[0], len - 2, str[len - 1]);
    return result;
}


ValidWordAbbr* validWordAbbrCreate(char ** dictionary, int dictionarySize) {
    g_user = NULL;
    for (int i = 0; i < dictionarySize; i++) {
        char *abbr = GetAbbreviation(dictionary[i]);
        ValidWordAbbr *temp = NULL;
        HASH_FIND_STR(g_user, abbr, temp);
        if (temp == NULL) {
            temp = (ValidWordAbbr*)calloc(1, sizeof(ValidWordAbbr));
            strcpy(temp->key, abbr);
            strcpy(temp->str, dictionary[i]);
            temp->count = 1;
            HASH_ADD_STR(g_user, key, temp);
        } else {
            // 如果字符串不一样了再++
            if (strcmp(temp->str, dictionary[0]) != 0) {
                temp->count++;
            }
        }
        free(abbr);
        abbr = NULL;
    }
    return NULL;
}

bool validWordAbbrIsUnique(ValidWordAbbr* obj, char * word) {
    char *abbr = GetAbbreviation(word);
    ValidWordAbbr *cur = NULL;
    ValidWordAbbr *tar = NULL;
    HASH_FIND_STR(g_user, abbr, cur);
    // cur->count 为1说明这个缩写对应的字符串只有一个
    if (cur == NULL || (cur != NULL && strcmp(cur->str, word) == 0 && cur->count == 1)) {
        free(abbr);
        abbr = NULL;
        return true;
    }
    free(abbr);
    abbr = NULL;
    return false;
}

void validWordAbbrFree(ValidWordAbbr* obj) {
    ValidWordAbbr *cur = NULL;
    ValidWordAbbr *tar = NULL;
    HASH_ITER(hh, g_user, cur, tar) {
        if (cur) {
            HASH_DEL(g_user, cur);
            free(cur);
        }
    }
}

/**
 * Your ValidWordAbbr struct will be instantiated and called as such:
 * ValidWordAbbr* obj = validWordAbbrCreate(dictionary, dictionarySize);
 * bool param_1 = validWordAbbrIsUnique(obj, word);
 
 * validWordAbbrFree(obj);
*/
