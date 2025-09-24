#include <iostream>
#include <string>
#include <algorithm>


std::string convertToTitle(int n) {
    std::string result = "";
    
    while (n > 0) {
        n--; 
        result += (char)('A' + n % 26);
        n /= 26;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << convertToTitle(n) << std::endl;
    return 0;
}
