#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
void make_route(string& route, stack<string>& paths, string& res){
	if(route[0]=='/'){
		while(!paths.empty()){
			paths.pop();
		}
	}
	cout<<route<<endl;
	stringstream s1(route);
	string token;
	while (getline(s1, token, '/')) {
		if(token == " ")continue;
		if(token== ".."){
			cout<<res[res.size()-1]<<endl;
			res.pop_back();
			paths.pop();
		}else{
			res += token;
			res += '/';
    		paths.push(token);
    	}
	}
}
void solve(){
	ll n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string command;
		cin>>command;
		if(command=="pwd"){
			for(auto &i:v)cout<<"/"<<i;
			cout<<"/"<<endl;
		}
		else{
			string route;
			cin>>route;
			if(route[0]=='/')v.clear();
			for(int j=0;j<route.size();j++){
				if(route[j]=='/')route[j]=' ';
			}
			stringstream ss(route);
			while(ss>>route){
				if(route=="..")v.pop_back();
				else v.push_back(route);
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}






// The strtok function in C/C++ is a legacy function for tokenizing strings (breaking a string into smaller pieces based on a delimiter). While strtok can be useful for simple cases, it has some limitations and potential issues that can cause unexpected behavior when used with certain input scenarios.

// Here are some reasons why strtok can cause issues:

// Modifies the Original String: strtok modifies the input string by replacing the delimiter characters with null characters ('\0'). This means that the original input string is altered during the tokenization process, which can lead to unintended consequences if you need to retain the original string.

// Not Thread-Safe: strtok uses internal static variables to keep track of the progress while tokenizing. This makes it non-thread-safe, meaning that using strtok in a multi-threaded environment can lead to race conditions and unexpected results.

// Not Suitable for Nested Calls: Since strtok relies on internal static variables, it is not suitable for nested calls. If you try to tokenize multiple strings at the same time (nested calls to strtok), it can cause unexpected behavior due to shared state.

// Can Skip Empty Tokens: If your input string contains consecutive delimiters, strtok will skip empty tokens. For example, if your input is "Hello, World" and the delimiter is ",", strtok will treat multiple spaces between "Hello" and "World" as a single delimiter and skip the empty token between them.

// Limited Flexibility: strtok can only handle single-character delimiters, which might not be sufficient for more complex tokenization requirements.

// For these reasons, it is generally recommended to avoid using strtok and instead use safer alternatives like std::stringstream or std::string::find and std::string::substr for tokenization in C++. These alternatives provide better control and flexibility, are thread-safe, and don't modify the original string.

// In the provided code, using strtok with getline(cin, input) can lead to issues because getline reads a whole line (including spaces) into the input string, and strtok then treats the entire line as a single token. The result is that you can't tokenize the input correctly using strtok. By using std::stringstream, we can process the input more safely and correctly.