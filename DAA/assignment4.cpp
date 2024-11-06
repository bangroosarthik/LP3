#include<bits/stdc++.h>
using namespace std;


/// using Backtracking 
bool isItSafe(int row,int col,vector<string>&board,int n){
    int preRow=row;
    int preCol=col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }

    row=preRow;
    col=preCol;

    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }

    row=preRow;
    col=preCol;
    while(row<n && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}


void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    else{
        for(int i=0;i<n;i++){ //O(N)
            if(isItSafe(i,col,board,n)){ //O(N)  -->> O(N2)
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                //backtrack
                board[i][col]='.';
            }
        }
    }
}

//using branch and bound 

void solve(int col,vector<int>&Left,vector<int>LeftDiag,vector<int>RightDiag,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    else{
        for(int i=0;i<n;i++){
            if(Left[i]==0 && LeftDiag[i+col]==0 && RightDiag[i-col+n-1]==0){
                board[i][col]='Q';
                Left[i]=1;
                LeftDiag[i+col]=1;
                RightDiag[i-col+n-1]=1;
                //backtrack
                solve(col+1,Left,LeftDiag,RightDiag,board,ans,n);
                board[i][col]='.';
                Left[i]=0;
                LeftDiag[i+col]=0;
                RightDiag[i-col+n-1]=0;
            }
        }
    }
}


int main(){
    int n;
    cout<<"Enter the size of n"<<endl;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }

    solve(0,board,ans,n);

    ///using branch and bound --->> we are bounding our branches 

    vector<int>Left(n,0);

    //left diagonal
    vector<int>LeftDiag(2*n-1,0);

    //right diagonal

    vector<int>RightDiag(2*n-1,0);

    // solve(0,Left,LeftDiag,RightDiag,board,ans,n);
    for(const auto row:ans){
        for(const auto val:row){
            cout<<val<<endl;
        }
        cout<<endl;
    }
    return 0;
}