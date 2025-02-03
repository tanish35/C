#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<int>())
#define vpll vector<pair<ll, ll>>
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define pq priority_queue<ll>
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll, ll, custom_hash>
#define uset unordered_set<ll, custom_hash>

/*

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣠⠤⠤⠒⠒⠂⠤⠤⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣠⠤⠤⠖⠒⠚⣉⣉⣩⣄⣤⡴⠶⠶⠛⠚⠓⠶⠦⢤⣤⣄⣌⣉⡙⠓⠒⠢⠤⠤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡤⠤⠤⠖⠒⠚⣉⣉⣍⣤⢤⠴⠶⠖⠛⠚⠋⠉⠉⠀⠀⠀⢀⣀⣀⣠⣤⣤⣀⣀⡀⠀⠀⠈⠉⠉⠙⠛⠒⠳⠶⠤⣤⣤⣩⣉⡙⠓⠒⠒⠤⠤⣤⣀⣀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣀⡤⠤⠔⠒⠒⢊⣉⣉⣥⢤⠤⠶⠖⠞⠙⠋⠛⠉⠉⠀⠀⠀⣀⣀⣀⣤⣤⣤⣶⢶⡾⣟⣿⣻⣽⣻⢯⣟⣷⣻⣽⣻⣟⡿⣶⡶⣶⣤⣤⣤⣀⣀⣀⠀⠀⠀⠉⠉⠙⠛⠙⠲⠶⠦⢤⡤⣌⣉⣉⠓⠒⠂⠦⠤⡤⣄
⢠⡧⠴⠖⠚⠛⠉⠉⠉⠀⠀⠀⣀⣀⣀⣠⣤⣴⡴⣶⢶⣾⢿⣿⣻⣽⣻⡽⣯⣟⡾⣯⢿⡽⣞⡷⣯⣟⡿⣞⣷⣻⣞⡷⣯⣟⣷⣻⢷⣯⣟⣾⣻⡽⣯⢿⣟⣷⡶⣶⢦⣤⣤⣀⣀⣀⡀⠀⠀⠈⠉⠉⠙⠛⠒⠲⠶⢼
⢸⣆⣀⣠⣤⣦⢶⡶⣶⢾⣻⢿⣯⢿⡽⣯⣟⡾⣽⢯⡿⣞⣿⣞⣷⣯⣷⣿⣷⣯⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣾⣷⣿⣿⣷⣿⣾⣿⣿⣾⣽⣾⣷⣿⣽⣻⣞⣷⣻⡽⣯⣟⣷⣻⢿⣽⣻⢿⣻⢷⡶⣶⢦⣤⣤⣄⣀⣸
⢸⣿⣽⣳⣟⡾⣯⢿⡽⣯⣟⡿⣞⣯⣿⣷⣿⣿⣿⣿⠿⠿⠿⠛⠛⠛⠋⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠙⠛⠛⠛⠿⠿⠿⣿⣷⣿⣾⣽⣟⣾⡽⣯⣟⣯⢿⡽⣯⣟⡾⣽⣞⣿
⢸⣿⣳⣟⣾⡽⣯⣿⣽⣷⣿⣿⠿⠟⠛⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠛⠻⠿⢿⣾⣯⣿⣽⣳⣯⣟⡷⣯⣿
⠸⣿⣳⣿⣾⣿⠿⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣿⣎⣿⣧⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⠿⣷⣿⣽⣷⣻
⠀⢻⣿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣉⣽⣿⣿⣿⣿⣿⡿⣿⣦⣤⣴⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢿⡟
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⡶⣟⣿⡏⠙⣾⣿⣿⣿⡿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⡇
⠀⣸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡋⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣿⣿⣿⣿⡛⠿⢶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿⠿⠿⠿⣿⣿⣥⣿⡩⢿⣿⣿⣿⣿⣿⣿⣿⠟⠾⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡿⣿⣿⣟⠻⠿⠤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠟⣿⣿⣿⣿⣯⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⡇
⠀⢹⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠋⣰⣿⣿⣿⣿⣷⣿⡿⢿⣿⡿⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⢋⣴⣿⣿⣿⣿⣟⣲⣿⣿⣦⣌⠛⠲⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠶⣦⣄⠀⠀⠀⠀⠀⠀⢀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⡙⠷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⡇
⠀⢹⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⢿⣿⣿⣿⣷⣦⣀⠀⣠⣴⣿⣿⣭⣭⣬⣻⣿⣿⣿⣿⣿⣾⣿⣿⡿⠿⣟⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣇⣿⠋⢿⣛⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣷⣦⡀⢀⡄⠀⠀⠀⠀⠀⠀⠀⣰⡟⠁⣀⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣯⣀⣀⠙⢿⣿⠃⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠻⠿⣿⡷⣌⠉⠉⠀⠀⠀⠀⠀⠀⠀⢠⣿⣇⣴⡟⠁⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣏⣯⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡍⢿⡀⠀⠀⠙⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡿⠀⣤⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇
⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⣿⣿⠙⠿⣟⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡘⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣧⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠃
⠀⠠⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⢿⡄⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠁
⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠟⠁⢻⣼⣧⠀⠀⠀⠀⠀⠉⠉⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠀
⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣆⠀⠀⠀⠀⠀⠀⠈⠻⣧⡈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⣿⠊⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀
⠀⠀⠘⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠈⠻⣦⣝⢿⣿⣿⣿⣿⣿⣇⣼⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⢰⡿⢀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠂⠀
⠀⠀⠀⢻⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢯⣽⠇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⢀⣴⣟⣠⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀
⠀⠀⠀⠸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠃⠀⠀
⠀⠀⠀⠀⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣯⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⣿⢿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀
⠀⠀⠀⠀⠈⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣾⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢸⠿⣿⡿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣧⡏⣼⣿⣿⣿⣿⣿⣿⣿⠟⠀⢼⣠⣿⠁⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣄⣀⡀⠀⡀⠀⠀⠀⠀⠈⢿⣿⣟⣿⣿⣿⣿⣿⣿⣿⠟⠃⠀⠀⢸⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣷⣒⠦⢤⣄⣠⡿⣧⢿⡛⣿⣿⣿⠏⠁⠀⠀⠀⠀⠺⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠁⠈⠉⠉⠙⠛⠓⠿⣿⣿⣿⣾⣷⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠁⠈⢻⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⡯⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⣫⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⡟⢳⢲⣶⣶⡄⠀⠀⠀⠀⢠⣾⣿⣿⡟⠁⠀⠀⠀⠀⢠⣶⣶⣶⣶⣶⣤⣤⣤⣴⣶⡖⠉⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣇⡀⠀⠀⠙⢧⡀⠀⠀⠀⣿⣥⣿⠟⠀⠀⠀⠀⠀⢰⣿⣿⠄⠀⢀⣼⠟⠉⠁⠁⠀⠀⠀⠀⠀⢀⣼⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣿⣶⣤⡀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⢀⣀⣾⣏⣠⠀⠀⠀⠀⠀⠀⠀⣠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣦⠀⠀⠀⠀⠀⠀⢠⣶⣦⠀⠀⠉⠛⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣦⠀⠀⠀⠉⣽⡟⠉⠁⠀⠀⠀⠀⠀⠀⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⣄⠀⠀⠀⠀⢹⣆⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⠀⠀⠀⢀⣼⡟⠀⠀⠀⠀⠀⠀⠀⣠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣦⡀⠀⠀⠀⠉⠳⠶⠴⠶⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠶⠦⠶⠟⠋⠀⠀⠀⠀⠀⠀⢀⣼⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢻⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣷⣤⡀⠀⠀⠀⠀⠀⢀⣤⣾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣷⣦⣀⣴⡾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣛⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

*/
ll pow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

#ifndef ONLINE_JUDGE
#define dbg(x)           \
    cerr << #x << " = "; \
    print_debug(x);      \
    cerr << endl;
#else
#define dbg(x)
#endif

// Forward declaration of print_debug for generic types
template <typename T>
void print_debug(const T &t);

// Overload for pair
template <typename T1, typename T2>
void print_debug(const pair<T1, T2> &p)
{
    cerr << "(";
    print_debug(p.first);
    cerr << ", ";
    print_debug(p.second);
    cerr << ")";
}

// Overload for generic types
template <typename T>
void print_debug(const T &t)
{
    cerr << t;
}

// Overload for vector
template <typename T>
void print_debug(const vector<T> &v)
{
    cerr << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
            cerr << ", ";
        print_debug(*it);
    }
    cerr << "]";
}

// Overload for set
template <typename T>
void print_debug(const set<T> &s)
{
    cerr << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (it != s.begin())
            cerr << ", ";
        print_debug(*it);
    }
    cerr << "}";
}

// Overload for unordered_set
template <typename T>
void print_debug(const unordered_set<T, custom_hash> &us)
{
    cerr << "{";
    for (auto it = us.begin(); it != us.end(); ++it)
    {
        if (it != us.begin())
            cerr << ", ";
        print_debug(*it);
    }
    cerr << "}";
}

// Overload for map
template <typename K, typename V>
void print_debug(const map<K, V> &m)
{
    cerr << "{";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it != m.begin())
            cerr << ", ";
        print_debug(it->first);
        cerr << ": ";
        print_debug(it->second);
    }
    cerr << "}";
}

// Overload for unordered_map
template <typename K, typename V>
void print_debug(const unordered_map<K, V, custom_hash> &um)
{
    cerr << "{";
    for (auto it = um.begin(); it != um.end(); ++it)
    {
        if (it != um.begin())
            cerr << ", ";
        print_debug(it->first);
        cerr << ": ";
        print_debug(it->second);
    }
    cerr << "}";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll v(k);
        uset s;
        forn(i, k)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        dbg(v);
        unordered_map<ll, unordered_set<ll, custom_hash>, custom_hash> m;
        forn(i, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            dbg(a);
            dbg(b);
            if (s.find(a) == s.end() && s.find(b) != s.end())
            {
                m[a].insert(b);
            }
            else if (s.find(b) == s.end() && s.find(a) != s.end())
            {
                m[b].insert(a);
            }
            else if (s.find(a) != s.end() && s.find(b) != s.end())
            {
                m[a].insert(b);
                m[b].insert(a);
            }
        }
        for (auto i : m)
        {
            dbg(i.first);
            dbg(i.second);
        }
        string ans = "ACCURATE";
        uset s1;
        for (int i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end() && m[i].size() == 0)
            {
                ans = "WEAK";
                break;
            }
            else if (m[i].size() <= 1 && s.find(i) == s.end())
            {
                s1.insert(m[i].begin(), m[i].end());
            }
        }
        if (ans == "WEAK")
        {
            cout << ans << endl;
            continue;
        }
        bool flag = false;
        for (auto i : s)
        {
            if (s1.find(i) == s1.end())
            {
                dbg(i);
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ans = "STRONG";
        }
        cout << ans << endl;
    }
    return 0;
}