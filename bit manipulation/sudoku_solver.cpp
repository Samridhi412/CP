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
void display(int input[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<input[i][j]<<endl;
		}
	}
}
void solver(int rows[9], int cols[9], int grid[3][3], int input[9][9], int i, int j){
	if(i==9){
		display(input);
		return;
	}
	if(input[i][j] > 0){
		solver(rows,cols,grid,input,j==8?i+1:i,j==8?0:j+1);
	}
	else{
		for(int i=0;i<9;i++){
			if(
				(rows[i] & (1<<i)) == 0 && 
				(cols[i] & (1<<i)) == 0 &&
				(grid[i/3][j/3] & (1<<i)) ==0
			){
				arr[i][j]=i;
			rows[i] ^= (1<<i);
			cols[j] ^= (1<<i);
			grid[i/3][j/3] ^= (1<<i);
solver(rows,cols,grid,input,j==8?i+1:i,j==8?0:j+1);
rows[i] ^= (1<<i);
			cols[j] ^= (1<<i);
			grid[i/3][j/3] ^= (1<<i);
			arr[i][j]=0;
			}
		}
	}
}
void solve(){
	int rows[9];
	int cols[9];
	int grid[3][3];
	int input[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int digit;
			cin>>digit;
			input[i][j]=digit;
			digit--;
			rows[i] |= (1<<digit);
			cols[j] |= (1<<digit);
			grid[i/3][j/3] |= (1<<digit);
		}
	}
	solver(rows,cols,grid,input,0,0);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}