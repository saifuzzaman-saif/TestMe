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

bool possible(string s, int a[], int d)
{
    for(int i=0; i<d; i++)
    {
        if(s[i]=='0' && a[i]==1) return false;
    }

    return true;
}

int SAIF()
{
    int i,j,k,l,m,n,p,q,x,y,u,v,w,r,tc,t,d;

    cin>>d>>n;

    int pushed[d+9] = {0};

    vector<pair<int,string> >vv;
    for(i=0; i<n; i++)
    {
        string s; cin>>s;
        int cnt = 0;
        for(j=0; j<d; j++) if(s[j]=='1') cnt++;
        vv.push_back(make_pair(cnt, s));
    }

    sort(vv.begin(), vv.end());

    string ans="";
    for(i=0; i<n; i++)
    {
        string s = vv[i].sec;
        if(possible(s, pushed, d))
        {
            for(j=0; j<d; j++)
            {
                if(s[j]=='1' && pushed[j]==0)
                {
                    pushed[j] = 1;
                    ans+=(char)(j+'0');
                }
            }
        }
        else
        {
            ans+='R';
            memset(pushed, 0, sizeof(pushed));
            for(j=0; j<d; j++)
            {
                if(s[j]=='1')
                {
                    pushed[j] = 1;
                    ans+=(char)(j+'0');
                }
            }
        }
    }

    cout<<ans.size()<<endl;

    for(i=0; i<ans.size(); i++) cout<<ans[i]<<" "; cout<<endl;

   // main();

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
