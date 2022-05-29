// Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

// A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

// A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

// 1 <= xi.length <= 4
// xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
// Leading zeros are allowed in xi.
// For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

 

// Example 1:

// Input: queryIP = "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".
// Example 2:

// Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".
// Example 3:

// Input: queryIP = "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.
 

// Constraints:

// queryIP consists only of English letters, digits and the characters '.' and ':'.



char * validIPAddress(char * queryIP) {
    int len = strlen(queryIP);
    if (strchr(queryIP, '.')) {
        // IPv4
        int last = -1;
        for (int i = 0; i < 4; ++i) {
            int cur = -1;
            if (i == 3) {
                cur = len;
            } else {
                char * p = strchr(queryIP + last + 1, '.');
                if (p) {
                    cur = p - queryIP;
                }
            }
            if (cur < 0) {
                return "Neither";
            }
            if (cur - last - 1 < 1 || cur - last - 1 > 3) {
                return "Neither";
            }
            int addr = 0;
            for (int j = last + 1; j < cur; ++j) {
                if (!isdigit(queryIP[j])) {
                    return "Neither";
                }
                addr = addr * 10 + (queryIP[j] - '0');
            }
            if (addr > 255) {
                return "Neither";
            }
            if (addr > 0 && queryIP[last + 1] == '0') {
                return "Neither";
            }
            if (addr == 0 && cur - last - 1 > 1) {
                return "Neither";
            }
            last = cur;
        }
        return "IPv4";
    }
    else {
        // IPv6
        int last = -1;
        for (int i = 0; i < 8; ++i) {
            int cur = -1;
            if (i == 7) {
                cur = len;
            } else {
                char * p = strchr(queryIP + last + 1, ':');
                if (p) {
                    cur = p - queryIP;
                }
            }
            if (cur < 0) {
                return "Neither";
            }
            if (cur - last - 1 < 1 || cur - last - 1 > 4) {
                return "Neither";
            }
            for (int j = last + 1; j < cur; ++j) {
                if (!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                    return "Neither";
                }
            }
            last = cur;
        }
        return "IPv6";
    }
}
