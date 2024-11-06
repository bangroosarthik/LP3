#include<bits/stdc++.h>
using namespace std;

//Recurisve function 
int fibRec(int n){
    if(n<0){
        //negative 
        return -1;
    }
    if(n==0|| n==1){
        return n;
    }
    else{
        return fibRec(n-1)+fibRec(n-2);
    }
}

//iterative
int fibIter(int n){ 
    if(n<0){
        //negative 
        return -1;
    }
    if(n==0|| n==1){
        return n;
    }

    int a=0;
    int b=1;
    int c; //third value
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}





//printing n fiboacci numbers
void printFibSeries(int n){
    if(n<0){
        //negative 
        cout<<"Enter positive number"<<endl;
        return;
    }
    if(n==0|| n==1){
        cout<<n<<" ";
        return;
    }

    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    int c; //third value
    for(int i=2;i<=n;i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;
}


int main(){
    while(true){
        cout<<"Enter 1 to print nth fibonacci number using recursion"<<endl;
        cout<<"Enter 2 to print nth fibonacci number using iterative"<<endl;
        cout<<"Enter 3 to print fibonacci series"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            int n1;
            cout<<"Enter the value of n"<<endl;
            cin>>n1;
            int res=fibRec(n1);
            cout<<"Result is: "<<res<<endl;
        }
        else if(op==2){
            int n2;
            cout<<"Enter the value of n"<<endl;
            cin>>n2;
            int res=fibIter(n2);
            cout<<"Result is: "<<res<<endl;
        }
        else if(op==3){
            int n3;
            cout<<"Enter the value of n"<<endl;
            cin>>n3;
            printFibSeries(n3);
        }
        else{
            cout<<"Invalid option"<<endl;
        }

    }
    return 0;
}