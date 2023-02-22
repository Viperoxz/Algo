#include <iostream>
#include <queue>
#define MAX 10000+5
using namespace std;
struct car{
	int id, arrive_time;
};
int main() {
	int tc, n, t, m;
	int res[MAX] = { 0 };
	cin >> tc;
	while (tc--) {
		queue<car>q_side[2]; // Khoi tao mot mang gom 2 queue co do dai khac nhau: q_side[0] ben trai, q_side[1] ben phai
		string pos;
		int arrive_time;
		cin >> n >> t >> m;
		for (int i = 1; i <= m; i++) {
			cin >> arrive_time >> pos;
			if (pos == "left") {
				q_side[0].push({i,arrive_time});
			}
			else q_side[1].push({i,arrive_time});
		}
		int cur_side = 0, cur_time = 0, next_time = 0; // ban dau pha o bo ben trai
		int waiting = !q_side[0].empty() + !q_side[1].empty();
		while (waiting) {
			if (waiting == 1) {
				next_time = (q_side[1].empty() ? q_side[0].front().arrive_time:q_side[1].front().arrive_time);
			}
			else next_time = min(q_side[0].front().arrive_time, q_side[1].front().arrive_time);
			cur_time = max(next_time, cur_time);
			int carried = 0;
			while (!q_side[cur_side].empty())
			{
				car next_car = q_side[cur_side].front();
				if (carried < n && next_car.arrive_time <= cur_time) {
					carried++;
					q_side[cur_side].pop();
					res[next_car.id] = cur_time + t;
				}
				else break;
			}
			cur_side = 1 - cur_side;
			cur_time += t;
			waiting = !q_side[0].empty() + !q_side[1].empty();
		}
		for (int i = 1; i <= m; i++) {
			cout << res[i] << endl;
		}
		if (tc) {
			cout << endl;
		}
		
	}
	return 0;
}
