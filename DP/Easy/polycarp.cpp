#include<bits/stdc++.h>
using namespace std;
vector<string> extract_tokens(string str){
	istringstream s(str);
	vector<string> tokens;
	string token;
	while(getline(s, token, ' ')){
		tokens.push_back(token);
	}
	return tokens;
}
void solve(){
	int n;
	cin>>n;
	unordered_map<string,vector<string>> mpp;
	vector<string> posts(n);
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,posts[i]);
	}
	for(int i=0;i<n;i++){
		vector<string> res = extract_tokens(posts[i]);
		transform(res[2].begin(),res[2].end(),res[2].begin(),
			[](unsigned char c){return tolower(c); });
		transform(res[0].begin(),res[0].end(),res[0].begin(),
			[](unsigned char c){return tolower(c); });
		mpp[res[2]].push_back(res[0]);
		
	}
	if(mpp.find("polycarp") == mpp.end()){
		cout<<0<<endl;
		return;
	}
	queue<string> q;
	q.push("polycarp");
	int count=0;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			string top = q.front();
			q.pop();
			for(auto &x:mpp[top]){
			q.push(x);
		}
	    }
		count++;
	}
	cout<<count<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}