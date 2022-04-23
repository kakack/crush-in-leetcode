// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

// Implement the Solution class:

// Solution() Initializes the object of the system.
// String encode(String longUrl) Returns a tiny URL for the given longUrl.
// String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
 

// Example 1:

// Input: url = "https://leetcode.com/problems/design-tinyurl"
// Output: "https://leetcode.com/problems/design-tinyurl"

// Explanation:
// Solution obj = new Solution();
// string tiny = obj.encode(url); // returns the encoded tiny url.
// string ans = obj.decode(tiny); // returns the original url after deconding it.
 

// Constraints:

// 1 <= url.length <= 10^4
// url is guranteed to be a valid URL.

/** Encodes a URL to a shortened URL. */
typedef struct {
    char *tiny;
    char *original;
    UT_hash_handle hh;
} Hash;

Hash *hash_table = NULL;

char *s = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool find(char *url) {
    Hash *p;
    HASH_FIND(hh, hash_table, url, strlen(url), p);
    return p;
} 


void getRandomURL(char *tiny) {
    for (int i=0; i<6; ++i) {
        tiny[i] = s[rand() % 62];
    }
}
/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    char *tiny = calloc(7, sizeof(char));
    do {
        getRandomURL(tiny);
    } while (find(tiny));
    Hash *p = malloc(sizeof(Hash));
    p->tiny = tiny;
    p->original = longUrl;
    HASH_ADD_STR(hash_table, tiny, p);
    return tiny;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    Hash *p;
    HASH_FIND(hh, hash_table, shortUrl, strlen(shortUrl), p);
    return p->original;   
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
