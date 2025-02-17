#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    ssize_t len = str.length();
    if (start< 0) start += len;
    if (end <= 0) end+= len;
    if (start < 0) start = 0;
    if (end > len) end = len;
    if (start >= end) return "";
    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept{
    std::string cap = str; 
    cap[0] = toupper(cap[0]);
    for (size_t i = 1; i < cap.length(); ++i) {
        cap[i] = tolower(cap[i]);  
    }
    return cap;
}

std::string Upper(const std::string &str) noexcept{
    std::string up = str; 
    for (char &ch : up) {
        ch = toupper(ch);  
    }
    return up;
}

std::string Lower(const std::string &str) noexcept{
    std::string low = str; 
    for (char &ch : low) {
        ch = tolower(ch);  
    }
    return low;
}

std::string LStrip(const std::string &str) noexcept{
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        start++;
    }
    return str.substr(start);
}

std::string RStrip(const std::string &str) noexcept{
    size_t end = str.length();
    while (end > 0 && std::isspace(str[end-1])) {
        end--;
    }
    return str.substr(0,end);
}

std::string Strip(const std::string &str) noexcept{
    std::string strip = LStrip(str);
    strip = RStrip(strip);
    return strip;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    size_t space = (width - str.length());
    size_t left= space / 2;
    size_t right = space - left;
    return std::string(left, fill) + str + std::string(right, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    size_t space = (width - str.length());
    std::string(space,fill);
    return str+std::string(space,fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    size_t space = (width - str.length());
    std::string(space,fill);
    return std::string(space,fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string result = str;
    size_t pos = 0;

    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), rep);
        pos += rep.length();  
    }

    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> result;

    if (splt.empty()) {
        size_t start = 0;
        while (start < str.length()) {
            while (start < str.length() && isspace(str[start])) {
                start++;
            }
            if (start >= str.length()) break;
            size_t end = start;
            while (end < str.length() && !isspace(str[end])) {
                end++;
            }
            result.push_back(str.substr(start, end - start));
            start = end;
        }
    } else {
        size_t start = 0, end;
        while ((end = str.find(splt, start)) != std::string::npos) {
            result.push_back(str.substr(start, end - start));
            start = end + splt.length();
        }
        result.push_back(str.substr(start)); 
    }

    return result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    if (vect.empty()) return "";  

    std::string result = vect[0];  
    for (size_t i = 1; i < vect.size(); ++i) {
        result += str + vect[i];  
    }

    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    int column = 0; 

    for (char ch : str) {
        if (ch == '\t') {
            int spaces_to_add = tabsize - (column % tabsize); 
            result.append(spaces_to_add, ' '); 
            column += spaces_to_add; 
        } else {
            result += ch;
            column = (ch == '\n') ? 0 : column + 1; 
        }
    }

    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    size_t m = left.size();
    size_t n = right.size();

    std::string l = left, r = right;
    if (ignorecase) {
        for (char &ch : l) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += ('a' - 'A');
            }
        }

        for (char &ch : r) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += ('a' - 'A');
            }
        }
    }
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (size_t i = 0; i <= m; i++) dp[i][0] = i; 
    for (size_t j = 0; j <= n; j++) dp[0][j] = j; 
    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (l[i - 1] == r[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else {
                dp[i][j] = dp[i - 1][j] + 1; 
                if (dp[i][j] > dp[i][j - 1] + 1) dp[i][j] = dp[i][j - 1] + 1; 
                if (dp[i][j] > dp[i - 1][j - 1] + 1) dp[i][j] = dp[i - 1][j - 1] + 1; 
            }
        }
    }

    return dp[m][n];
}

};