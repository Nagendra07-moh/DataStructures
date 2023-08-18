#include <bits/stdc++.h>
using namespace std;
int binaryStringToInt(const std::string& binaryStr) {
    int result = 0;
    int len = binaryStr.length();

    for (int i = 0; i < len; ++i) {
        if (binaryStr[i] == '1') {
            result += static_cast<int>(std::pow(2, len - i - 1));
        }
    }

    return result;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



string str = "101011";

// cout<<binaryStringToInt(str);

int x = 23;
string s = to_string(23);  
s + 23;

















 



	return 0;
}