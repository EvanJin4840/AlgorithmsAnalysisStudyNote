#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Location {
    int id;
    string place_name;
};

vector<Location> locations;
vector<vector<int>> adjlist;

int get_shortest_path(int start_id, int target_id, int total_locations) {
    queue<int> q;
    vector<bool> visited(locations.size(), false);
    vector<int> distance(locations.size(), -1); // 거리 정보를 저장할 벡터
    
    q.push(start_id);
    visited[start_id] = true;
    distance[start_id] = 0; // 시작 지점의 거리를 0으로 세팅

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target_id) {
            return distance[current];
        }

        for (int neighbor : adjlist[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}

int main(){
    locations.push_back({0, "포항터미널"});
    locations.push_back({1, "포항역"});
    locations.push_back({2, "포항시청"});
    locations.push_back({3, "한동대"});
    locations.push_back({4, "영일대"});
    locations.push_back({5, "포항공대"});
    locations.push_back({6, "주안에교회"});
    locations.push_back({7, "호미곶"});

    int total_locations = locations.size();
    adjlist.resize(total_locations);
    
    // 포항터미널(0) <-> 포항시청(2)
    adjlist[0].push_back(2);
    adjlist[2].push_back(0);

    // 영일대(4) <-> 주안에교회(6)
    adjlist[4].push_back(6);
    adjlist[6].push_back(4);

    // 영일대(4) <-> 한동대(3)
    adjlist[4].push_back(3);
    adjlist[3].push_back(4);

    // 한동대(3) <-> 주안에교회(6)
    adjlist[3].push_back(6);
    adjlist[6].push_back(3);
    
    // 포항시청(2) <-> 포항공대(5)
    adjlist[2].push_back(5);
    adjlist[5].push_back(2);
    
    // 포항역(1) <-> 포항시청(2)
    adjlist[1].push_back(2);
    adjlist[2].push_back(1);

    //포항역(1) <-> 한동대(3)
    adjlist[1].push_back(3);
    adjlist[3].push_back(1);

    cout << "=== 탄소 배출 절감을 위한 최소 경유 경로 탐색 ===" << endl;
    cout << "0: 포항터미널" << endl;
    cout << "1: 포항역" << endl;
    cout << "2: 포항시청" << endl;
    cout << "3: 한동대" << endl;
    cout << "4: 영일대" << endl;
    cout << "5: 포항공대" << endl;
    cout << "6: 주안에교회" << endl;
    cout << "7: 호미곶" << endl;
    cout << "출발지의 ID를 입력하세요: ";
    int start_id;
    cin >> start_id;
    cout << "목적지의 ID를 입력하세요: ";
    int target_id;
    cin >> target_id;
    int result = get_shortest_path(start_id, target_id, total_locations);

    if(result != -1) {
        cout << locations[start_id].place_name << "에서 " << locations[target_id].place_name << "까지의 최소 경유 구간 수는: " << result << "입니다." << endl;
    }
    else{
        cout << locations[start_id].place_name << "에서 " << locations[target_id].place_name << "로 가는 경로가 존재하지 않습니다." << endl;
    }

    return 0;
}