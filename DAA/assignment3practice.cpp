#include<bits/stdc++.h>
using namespace std;


void printTable(vector<vector<int>>&dp,int n,int W){
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            cout<<setw(3)<<dp[i][w];
        }
        cout<<endl;
    }
}

int knapsack(vector<int>&weights,vector<int>&profits,int W,vector<int>&selectedItems){
    int n=weights.size();

    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    //fill values in the table 
    
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            //
            if(weights[i-1]<=w){
                dp[i][w]=max(dp[i-1][w],profits[i-1]+dp[i-1][w-weights[i-1]]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    printTable(dp,n,W);
    int maxProfit=dp[n][W];
    int w=W;
    for(int i=n;i>0 && maxProfit>0;i--){
        if(maxProfit!=dp[i-1][w]){
            selectedItems.push_back(i);
            maxProfit-=profits[i-1];
            w-=weights[i-1];
        }
    }


    return dp[n][W];
}

int main(){
    while(true){
        cout<<"Enter 1 to perform 0/1 knapsack problem"<<endl;
        cout<<"Enter 2 to exit"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            int n;
            cout<<"Enter the number of items"<<endl;
            cin>>n;
            //vector weights profits
            vector<int>weights(n),profits(n);
            for(int i=0;i<n;i++){
                cout<<"Enter the weight of "<<i+1<<" item: "<<endl;
                cin>>weights[i];
                cout<<"Enter the profit of "<<i+1<<" item: "<<endl;
                cin>>profits[i];
            }

            //max weight of knapsack? 
            int W;
            cout<<"Enter the maxWeight of knapsack"<<endl;
            cin>>W;

            vector<int>selectedItems;
            //maxProfit

            int res=knapsack(weights,profits,W,selectedItems);

            cout<<"Max Profit: "<<res<<endl;

            cout<<"Items selected (1-based index)"<<endl;
            for(auto item:selectedItems){
                cout<<item<<" ";
            }
            

        }

        else{
            cout<<"invalid option"<<endl;
        }
    }
    return 0;
}