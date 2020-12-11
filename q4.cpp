//Write a program to convert left recursive grammar to right recursive gramma
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int NT, i, j, k, n;
    string str;
    char non_terminal[100];
    vector<string> Production[100];
    vector<string> alpha, beta; 
    cout<<"=== Converting given left recursive grammar to right recursive grammar ==="<<endl; 
    cout<<"Enter the total number of non terminals:";
    cin>>NT; 
    cout<<"Enter the Non Terminals                :"<<endl;   
    for(i=0;i<NT;i++)
    {
        cout<<i+1<<" : ";
        cin>>non_terminal[i];
    }
    for(i=0;i<NT;i++)
    {
        cout<<"Enter the total number of production for "<<non_terminal[i]<<": ";
        cin>>n;
        cout<<"Enter Productions                  :"<<endl;
        
        for(j=0; j<n; j++)
        {
            cout<<"Production "<<i+1<<" : ";
            cin>>str;
            Production[i].push_back(str);
        }
    }
    for(i=0; i<NT; i++)
    {
        for(j=0; j<Production[i].size(); j++)
        {
            if(Production[i][j][0] == non_terminal[i])
            {
                alpha.push_back(Production[i][j].substr(1, Production[i][j].length()-1 ));
            }
            else
            {
                beta.push_back(Production[i][j]);
            }
        }
        
        if(alpha.size() > 0)
        {
            cout<<non_terminal[i]<<" -> ";
            for(j=0; j<beta.size(); j++)
            {
                cout<<beta[j]<<non_terminal[i]<<"'"<<"|";
            }
            cout<<endl;

            cout<<non_terminal[i]<<"' -> ";
            for(j=0;j<alpha.size();j++)
            {
                cout<<alpha[j]<<non_terminal[i]<<"'|";
            }        
            cout<<"e"<<endl;
            alpha.clear();
            beta.clear();
        }      
        else
        {
            cout<<non_terminal[i]<<" -> ";     
            for(j=0;j<beta.size();j++)
            {
                cout<<beta[j]<<"|";
            }
            cout<<endl;
        }
    }
    return 0;
}
