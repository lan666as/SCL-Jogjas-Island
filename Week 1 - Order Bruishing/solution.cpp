#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll shopid[1903030];
ll userid[1903030];
ll waktu[1903030];
ll b[1903030];
ll n;
pair<ll, pair<ll, ll> > A[1903030]; 
vector<pair<ll, pair<ll, ll> > > v;
map<ll, int> me;
vector<pair<ll, ll > > jaw;
ll pars_waktu(string z)
{
	//2019-12-27 00:23:03
	//0123456789012345678
	ll tgl = stoll(z.substr(8,2)); 
	ll jam = stoll(z.substr(11,2)); 
	ll men = stoll(z.substr(14,2)); 
	ll dtk = stoll(z.substr(17,2));
	// cout << tgl << " " << jam << " " << men << " " << dtk << "\n";
	return tgl * 60 * 60 * 24 + jam * 60 * 60 + men * 60 + dtk; 
}
void pars(string z)
{
	string tmp;
    z += ",";
    ll L = z.length();
    vector<string> isi;
    for(ll i = 0; i < L; i++)
    {
        if(z[i] == ',')
        {
            isi.pb(tmp);
            tmp = "";
        }
        else
            tmp += z[i];
    }
    shopid[n] = stoll(isi[1]);
    userid[n] = stoll(isi[2]);
    waktu[n] = pars_waktu(isi[3]);
    A[n] = mp(shopid[n], mp(waktu[n], userid[n]));
}
void buat()
{
	ll m = v.size();
	ll L = 0, R = -1, unik = 0, iya = 0, kiri = 0, kanan = m - 1, bes = 0;
	ll ma = 0, isi = 0;
	for(ll i = 0; i < m; i++)
		b[i] = 0;
	me.clear();
	while(L < m)
	{
		while(R < (m - 1) && ((R == 0) || ((v[R + 1].se.fi - v[L].se.fi) <= 3600)))
		{
			R++;
			if(v[R].se.se != -1)
			{
				bes++;
				if(me[v[R].se.se] == 0)
					unik++;
				me[v[R].se.se]++;
			}
		}
		if((bes) >= unik * 3LL && bes != 0)
		{
			iya = 1;
			for(ll i = max(kiri, L); i <= R; i++)
				b[i] = 1;
			kiri = max(kiri, R + 1);
		}
		if(v[L].se.se != -1)
		{	
			bes--;
			me[v[L].se.se]--;
			if(me[v[L].se.se] == 0)
				unik--;
		}
		L++;		
	}
	bes = 0;
	me.clear();
	unik = 0;
	L = m, R = m - 1; 
	while(R >= 0)
	{
		while(L > 0 && ((L == m) || ((v[R].se.fi - v[L - 1].se.fi) <= 3600)))
		{
			L--;
			if(v[L].se.se != -1)
			{
				bes++;
				if(me[v[L].se.se] == 0)
					unik++;
				me[v[L].se.se]++;
			}
		}
		if((bes) >= unik * 3LL && bes != 0)
		{
			iya = 1;
			for(ll i = min(kanan, R); i >= L; i--)
				b[i] = 1;
			kanan = min(kanan, L - 1);
		}
		if(v[R].se.se != -1)
		{
			bes--;
			me[v[R].se.se]--;
			if(me[v[R].se.se] == 0)
				unik--;
		}
		R--;		
	}
	if(!iya)
	{
		cout << v[0].fi << ",0\n";
		return ;
	}
	me.clear();
	for(ll i = 0; i < m; i++)
	{
		if(!b[i])continue;
		if(v[i].se.se == -1)continue;
		me[v[i].se.se]++;
		ma = max(ma, (ll)me[v[i].se.se]);
	}
	vector<ll> isinya;
	ll udh = 0;
	cout << v[0].fi << ",";
	for(ll i = 0; i < m; i++)
	{
		if(!b[i])continue;
		if(v[i].se.se == -1)continue;
		if(me[v[i].se.se] == ma)
		{
			me[v[i].se.se] = 0;
			isinya.pb(v[i].se.se);
		}
	}
	sort(isinya.begin(),isinya.end());
	for(ll i = 0; i < isinya.size(); i++)
	{
		if(i > 0)
			cout << "&";
		cout << isinya[i];
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("order_brush_order.csv", "r", stdin);
	freopen("jawaban00.csv", "w", stdout);
	string s;
	getline(cin,s);
	while(1)
	{
		getline(cin,s);
		n++;
		pars(s);
		if(n == 222750)
			break;
	}
	ll te = n;
	for(ll i = 1; i <= n; i++)
	{
		A[++te] = mp(A[i].fi, mp(A[i].se.fi - 3600, -1));
		A[++te] = mp(A[i].fi, mp(A[i].se.fi + 3600, -1));
		A[++te] = mp(A[i].fi, mp(A[i].se.fi + 3601, -1));
		A[++te] = mp(A[i].fi, mp(A[i].se.fi - 3601, -1));
		A[++te] = mp(A[i].fi, mp(A[i].se.fi - 3599, -1));
		A[++te] = mp(A[i].fi, mp(A[i].se.fi + 3599, -1));
	}
	n = te;
	cout << "shopid,userid\n";
	sort(A + 1, A + 1 + n);
	for(ll i = 1; i <= n; i++)
	{
		// cout << A[i].fi << " " << A[i].se.fi << " " << A[i].se.se << "\n";
		v.pb(A[i]);
		if(i == n || A[i].fi != A[i + 1].fi)
		{
			buat();
			v.clear();
		}
	}
	// for(ll i = 0; i < jaw.size(); i++)
	// {
	// 	if(i > 0 && jaw[i].fi == jaw[i - 1].fi)
	// 		continue;
	// 	cout << jaw[i].fi << "," << jaw[i].se << "\n"; 
	// }

}