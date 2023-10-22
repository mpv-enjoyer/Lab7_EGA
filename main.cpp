#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cout << "N > 0: "; cin >> N;
    vector<int> prices(N, 0); vector<int> weight(N, 0);
    for (int i = 0; i < N; i++)
    {
        cout << "price " << i + 1 << ": "; cin >> prices[i];
        cout << "weight " << i + 1 << ": "; cin >> weight[i];
    }
    int Wmax; cout << "Wmax > 0: "; cin >> Wmax;
    int sumW = 0; int Q = 0; vector<bool> S(N, false);
    int sumWcheck = 0;
    for (int i = 0; i < N; i++)
    {
        sumWcheck += weight[i]; cout << i + 1 << ") price:" << prices[i] << " weight:" << weight[i] << "\n";
    }
    cout << "overall weight:" << sumWcheck << "\n";
    if (sumWcheck <= Wmax) { cout << "putting everything in, no task here.\n"; return 1; }
    for (int i = 0; i < N; i++)
    {
        int cl = -1; int ci = -1;
        for (int j = 0; j < N; j++)
        {
            if (S[j]) continue;
            if (cl < prices[j]) { cl = prices[j]; ci = j; }
        }
        if (sumW + weight[ci] <= Wmax)
        {
            Q += cl; sumW += weight[ci]; S[ci] = true;
        }
        else break;
        cout << i + 1 << ") put:" << ci + 1 << " weight:" << weight[ci] << " price:" << prices[ci];
        cout << " backpack_price:" << Q << " backpack_weight:" << sumW << "\n";
    }
    cout << "Final Result:\nitems: ";
    for (int i = 0; i < N; i++) if (S[i]) cout << i + 1 << " ";
    cout << "\nprice: " << Q << "\nweight: " << sumW << "\n";
    return 0;
}
//challenge: c++ lab under 50 lines of code is done, it's so messy lol