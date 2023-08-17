#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

string sumRes(vector<vector<int>>&result){
	 vector<int> answer = results.back();
        vector<int> newAnswer;
        results.pop_back();
        
        // Sum each digit from answer and result
        for (vector<int> result : results) {
            newAnswer.clear();
            int carry = 0;
            
            for (int i = 0; i < answer.size() || i < result.size(); ++i) {
                // If answer is shorter than result or vice versa, use 0 as the current digit.
                int digit1 = i < result.size() ? result[i] : 0;
                int digit2 = i < answer.size() ? answer[i] : 0;
                // Add current digits of both numbers.
                int sum = digit1 + digit2 + carry;
                // Set carry equal to the tens place digit of sum.
                carry = sum / 10;
                // Append the ones place digit of sum to answer.
                newAnswer.push_back(sum % 10);
            }

            if (carry) {
                newAnswer.push_back(carry);
            }
            answer = newAnswer;
}


vector<int> find1(string& num , char& ch , int i){
	vector<int>ans(i,0);
	int carry = 0;

	for(auto it:num){
		int tot = (it - '0')*(ch - '0') + carry;
		carry = tot/10;
		ans.push_back(tot%10);
	}

	if(carry){
		ans.push_back(carry);
	}
	return ans;
}






int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif



string num1 = "123", num2 = "456";

// if(num1 == "0" || num2 == "0"){
// 	reuturn 0;
// }
reverse(num1.begin(),num1.end());
reverse(num2.begin(),num2.end());

vector<vector<int>>ans;

for(int i=0;i<num2.size();i++){
	ans.push_back(find1(num1,num2[i],i));
}

string ans = sumRes(ans);















return 0;
}


