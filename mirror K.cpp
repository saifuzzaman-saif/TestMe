/*

    author : s@if

*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define 		NIL 			-1
#define			INF 			1e9
#define         EPS             1e-9
#define         SAIF            main
#define		 	fi	 		    first
#define 		sec 			second
#define 		MAX 			INT_MAX
#define 		ll 			    long long
#define 		PI 			    acos(-1.0)
#define			MOD 			1000000007
#define 		PLL 			pair<ll,ll>
#define 		PII			    pair<int,int>
#define 		ull 			unsigned long long
#define 		For(i,a,b) 		for(int i=a;i<=(int)b;i++)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;

inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos)	{	return (bool) (N & (1<<pos));}
int Set(int N, int pos) {	return N = N | (1<<pos);}

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};    // King's move
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hx[]={-2,-2,-1,+1,+2,+2,-1,+1};    // Knight's move
int hy[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

const int MAXN = (int)2e5+9;



int SAIF()
{
    int i,j,k,l,m,n,p,q,x,y,u,v,w,r,tc,t;

    cin>>n; m = n*2; int a[m+9], b[m+9], c[m+1];

    for(i=1; i<=m; i++)
    {
        cin>>a[i];
        b[i] = c[i] = a[i];
    }

    bool flag = true;

    x = 0;
    int ans1 = 0;
    while(true)
    {
        for(i=1; i<=m; i++)
        {
            if(b[i]!=i) break;
        }

        if(i==m+1) break;

        if(x%2==0)
        {
            for(i=1; i<=m; i+=2)
            {
                swap(b[i], b[i+1]);
            }
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                swap(b[i], b[n+i]);
            }
        }

        ans1++;
        for(i=1; i<=m; i++)
        {
            if(b[i]!=i) break;
        }

        if(i==m+1) break;

        for(i=1; i<=m; i++)
        {
            //cout<<b[i]<<" ";
            if(a[i]!=b[i]) break;
        }
       // cout<<endl;

        if(i==m+1){
            flag = false; break;
        }

        x++;
    }

    bool flag2 = true;

    x = 0;
    int ans2 = 0;
    while(true)
    {
        for(i=1; i<=m; i++)
        {
            if(c[i]!=i) break;
        }

        if(i==m+1) break;

        if(x%2==1)
        {
            for(i=1; i<=m; i+=2)
            {
                swap(c[i], c[i+1]);
            }
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                swap(c[i], c[n+i]);
            }
        }

        ans2++;
        for(i=1; i<=m; i++)
        {
            if(c[i]!=i) break;
        }

        if(i==m+1) break;

        for(i=1; i<=m; i++)
        {
            //cout<<b[i]<<" ";
            if(a[i]!=c[i]) break;
        }
       // cout<<endl;

        if(i==m+1){
            flag2 = false; break;
        }

        x++;
    }


    int ans = -1;
    if(flag==true && flag2==true) ans = min(ans1, ans2);
    else if(flag==true) ans = ans1;
    else if(flag2==true) ans = ans2;
    cout<<ans<<endl;

    // main();

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)

// in branch feature update
