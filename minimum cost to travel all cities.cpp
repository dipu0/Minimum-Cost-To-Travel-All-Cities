///minimum cost to travel all cities
#include<bits/stdc++.h>
int u,v,w,i,edge,sc;
char CityList[100][100];
using namespace std;
struct city
{
    int nd,Fare;

}temp;

struct Line
{
    int Name,Key;
    bool flag;
} A[100];

vector<city> g[100];
int n, dis[100],par[100];

void inputCity(int n)
{
    int ct;

    for(ct=0 ;ct<n;ct++)
    {
        cout<<"City "<<ct<<": ";
        cin>>(CityList[ct]);

    }

}

int pop()
{
    int min=1000000;
    int index;
    for(int i=0; i<n; i++)
    {
        if(A[i].Key < min && A[i].flag==true)
        {
            min=A[i].Key;
            index=i;
        }
    }
    A[index].flag=false;
    return index;
}

bool isEmpty()
{
    for(int i=0; i<n; i++)
    {
        if(A[i].flag)
            return false;
    }
    return true;
}
int Dijkstra(int n,int u, int v, int w)
{
    while(!isEmpty())
    {
        int u=pop();
        for(int i=0; i<g[u].size(); i++)
        {
            city t=g[u][i];
            int v=t.nd;
            int w=t.Fare;
            if(dis[v]>dis[u]+w)
            {
            dis[v]=dis[u]+w;
            par[v]=u;
            A[v].Key=dis[v];
            }
        }
    }
}

void PrintPath(int parent[],int city,int length)
{
    if(city==-1) return;
    PrintPath(parent,parent[city],length+1);
    cout<<CityList[city];
    if(length!=0){
        cout<<" -> ";
    }
}

void PrintCost(int sc)
{
    int i;
    for(i=0; i<n; i++)
        {
            dis[i]=99999;
            par[i]=-1;
        }
        dis[sc]=0;
        for(i=0; i<n; i++)
        {
            A[i].Name=i;
            A[i].Key=dis[i];
            A[i].flag=true;
        }

        cout<<"From your City: "<<CityList[sc];
        cout<<"\nDestination City\tMin Fare\tMin Route\n"<<endl;
        Dijkstra(n,u,v,w);
        for(i=0; i<n; i++)
        {
            cout<<CityList[i]<<"\t\t\t";
            cout<<dis[i]<<" Taka\t\t";
            PrintPath(par,i,0);
            cout<<endl;
        }
}

int main()
{
    cout<<" N:B: Input city like Dhaka,Manikganj,Nowakhali......N.\n 0=A, 1=B, C=3....Z are city like Dhaka, CTG, Khulna";
    while(1)
    {
        cout<<"\n\n 1. Create City List.\n 2. Create Route for Map.\n 3. Your Location to Destination City Bus Fare.\n"
        << " 4. All Destination City and Fare.\n 5. Exit \n";

        int ch;
        cin>>ch;
         if(ch==1)
        {
            cout<<"Enter Number of Cities: ";
            cin>>n;
            inputCity(n);
            for(i<0;i<n;i++)
            {
                cout<<CityList[i]<<" Address as: "<<i <<endl;
            }
        }


        else if(ch==2)
        {
            if(n<=0)
            {
                cout<<"\nEnter the number of city first.";
                continue;

            }

            cout<<"\nEnter Number of Route: ";
            cin>>edge;
            for(i=0; i<edge; i++)
            {
                cout<<"Route "<<i+1<<" Edges: \n";
                cin>>u>>v;
                cout<<"Bus Fare: \n";
                cin>>w;
                temp.nd=v;
                temp.Fare=w;
                g[u].push_back(temp);
                temp.nd=u;
                g[v].push_back(temp);
            }
          //  break;
        }
        else if(ch==3)
        {
        cout<<"Enter Your Location: ";
        cin>>sc;
        if(sc<=n)
        PrintCost(sc);
        else
            cout<<"You Have To Choose from 0 to n";

        }

        else if(ch==4)
        {
            for(int k=0; k<n; k++)
            {
                PrintCost(k);
            }

        }
        else if(ch==5)
        {
            break;
        }
        else
            cout<<"WRONG CHOOSE";
    }
    return 0;
}

