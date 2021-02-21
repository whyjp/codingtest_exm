// codetest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdexcept>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <unordered_map>
#include <unordered_set>

#pragma warning(disable:4996)
using namespace std;

//string solution(string number, int k) {
//    string answer = "";
//        
//    for (unsigned int i = 0; i < number.length(); ++i) {
//        while (answer.empty() == false && answer.back() < number[i] && k > 0) {
//            answer.back() = number[i];
//            k--;
//        }
//        if (k == 0) {
//            answer += number.substr(i,number.length()-i);
//            break;
//        }
//        answer.push_back(number[i]);
//    }
//    return answer.substr(0, answer.length()-k);
//}
//bool check_dfs[MAX];
//DFS Search
//void DFS(int index) {
//    check_dfs[index] = true; //정점 방문 체크
//
//    for (int i = 0; i < v[index].size(); i++) {
//        int next = v[index][i];
//
//        if (!check_dfs[next]) { //방문하지 않았다면 DFS() 호출
//            DFS(next);
//        }
//    }
//}
//
//vector<string> solution(vector<vector<string>> friends, string user_id) {
//    vector<string> answer;
//    return answer;
//}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> nset(scoville.begin(),scoville.end());

    while (nset.size() > 1) {
        if (nset.top() > K) {            
            break;
        }
        else if(nset.empty()) {
            answer = -1;
            break;
        }
        auto a = nset.top(); nset.pop();
        auto b = nset.top(); nset.pop();

        nset.push(a + (b * 2));
        answer++;
    }

    return answer;
}
int main()
{
    //vector<int> ii = { 1,2,3,4,5 };
    //vector<int> ii = {  };
    vector<int> ii = { 1, 2, 3, 9, 10, 12 };
    solution(ii, 7);
};

//
//string solution(string number, int k) {
//    string answer = "";
//    vector<char> remain;
//    remain.emplace_back(0);
//    for (size_t i = 0; i < number.length();++i) {
//        if (number[i] > *remain.rbegin()) {
//            *remain.rbegin()= number[i];
//        }else
//            remain.emplace_back(number[i]);
//        if (number.length() - remain.size() == k)
//            break;
//    }
//    for (auto& i : remain) {
//        answer += (i);
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<int> ii = { 1,2,3,4,5 };
//    solution("4177252841",4);
//};
#ifdef bfs
// 그래프의 인접 리스트 표현
vector < vector<int> ad;
// start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다.
vector<int> bfs(int start) {
    // 각 정점의 방문 여부
    vector<bool> discovered(adj.size(), false);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    // 정점의 방문 순서
    vector<int> order;
    discovered[start] = true;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // here를 방문한다.
        order.push_back(here);
        // 모든 인접한 정점을 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다.
            if (!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
      }
    }

    return order;
  }
// start에서 시작해 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의
  // 최단 거리와 너비 우선 탐색 스패닝 트리를 계산한다.
  // distance[i] = start로부터 i까지의 최단 거리
  // parent[i] = 너비 우선 탐색 스패닝 트리에서 i의 부모의 번호. 루트인 경우 자신의 번호
void bfs2(int start, vector<int>& distance, vector<int>& parent) {
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);
    queue<int> q; // 방문할 정점 목록을 유지하는 큐
    distance[start] = 0;
    parent[start] = start;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // here의 모든 인접한 정점을 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다.
            if (distance[there] == -1) {
                q.push(there);
                distance[there] = distance[here] + 1;
                parent[there] = here;
        }
      }
    }
  }

// v로부터 시작점까지의 최단 경로를 계산한다.
vector<int> shortestPath(int v, const vector<int>& parent) {
    vector<int> path(1, v);
    while (parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}
#endif
#ifdef _1F64C806_E0B0_44E3_BC1A_75216CBCEC18_  //asdf sort -> find prefix
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (size_t i = 0; i < phone_book.size()-1;++i) {
        auto ret = phone_book[i + 1].find(phone_book[i]);
        if (ret == 0) {
            return false;
        }
    }
    return answer;
}
int main()
{
    vector< string > arr = {"119", "97674223", "1195524421"};
    vector< string > arr2 = { "123", "456", "789" };
    cout << solution(arr) << endl;
    cout << solution(arr2) << endl;
    
};
#endif

//#include <stdexcept>
//#include <functional>
//
//class FowlEgg;
//
//class Fowl
//{
//public:
//    virtual ~Fowl() {};
//    virtual FowlEgg* lay() = 0;
//};
//
//class FowlEgg
//{
//    bool bHatched = false;
//    std::function<Fowl* ()> m_createFowl;
//public:
//    FowlEgg(std::function<Fowl* ()> createFowl)
//    {
//        m_createFowl = createFowl;
//    }
//
//    Fowl* hatch()
//    {
//        if (bHatched)
//        {
//            throw std::logic_error("Already Hatched");
//            return NULL;
//        }
//        bHatched = true;
//        return m_createFowl();
//    }
//};
//
//class Goose : public Fowl
//{
//public:
//    Goose()
//    {
//    }
//
//    FowlEgg* lay()
//    {
//        auto hatch = []() -> Fowl* { return new Goose(); };
//        return new FowlEgg( hatch );
//    }
//};
//
//#ifndef RunTests
//int main()
//{
//    Fowl* goose = new Goose();
//
//    FowlEgg* fowlEgg1 = goose->lay();
//    Fowl* childGoose1 = fowlEgg1->hatch();
//    Fowl* childGoose2 = fowlEgg1->hatch();
//}
//#endif


//class Node
//{
//public:
//    Node(Node* leftChild, Node* rightChild)
//    {
//        this->leftChild = leftChild;
//        this->rightChild = rightChild;
//    }
//
//    Node* getLeftChild() const
//    {
//        return this->leftChild;
//    }
//
//    Node* getRightChild() const
//    {
//        return this->rightChild;
//    }
//
//    int DFS(Node* node)
//    {
//        if (node == NULL)
//            return 0;
//
//        return 1+ std::max( DFS(node->getLeftChild()), DFS(node->getRightChild()) );
//    }
//    int height()
//    {
//        return DFS(this) - 1;
//    }
//private:
//    Node* leftChild;
//    Node* rightChild;
//};
//
//#ifndef RunTests
//int main()
//{
//    Node* leaf1 = new Node(NULL, NULL);
//    Node* leaf2 = new Node(NULL, NULL);
//    Node* node = new Node(leaf1, NULL);
//    Node* root = new Node(node, leaf2);
//
//
//    Node* leaf3 = new Node(NULL, NULL);
//    Node* leaf4 = new Node(NULL, NULL);
//
//    std::cout << root->height();
//}
//#endif
//
//#ifdef G_T //그리디_투포인터
//int solution(vector<int> people, int limit) {
//    int answer = 0; 
//    std::sort(people.begin(), people.end());
//    int count = 0;
//    int f = 0;
//    int e = people.size() - 1;
//
//    while(f <=e)
//    {
//        if (people[e] + people[f] <= limit)
//        {
//            --e;
//            ++f;
//        }
//        else
//        {
//            --e;
//        }
//        ++count;
//    }
//    answer = count;
//    return answer;
//}
//int main()
//{
//    vector<int> arr = { 70, 80, 50 };
//    auto a = solution(arr, 100);
//    cout << a << endl;
//
//}
//#endif
//
//std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
//{
//    
//    int pre = 0;
//    int post = 1;
//    for (; pre < list.size(); ++pre) {
//        for (; pre < list.size(); ++pre) {
//
//            if (sum - list[pre] == list[post])
//            {
//
//            }
//        }
//    }
//    return { -1, -1};
//}
//
//#ifndef RunTests
//int main()
//{
//    std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
//    std::pair<int, int> indices = findTwoSum(list, 10);
//    std::cout << indices.first << '\n' << indices.second;
//}
//#endif

//class Node
//{
//public:
//    Node(int value, Node* left, Node* right)
//    {
//        this->value = value;
//        this->left = left;
//        this->right = right;
//    }
//
//    int getValue() const
//    {
//        return value;
//    }
//
//    Node* getLeft() const
//    {
//        return left;
//    }
//
//    Node* getRight() const
//    {
//        return right;
//    }
//
//private:
//    int value;
//    Node* left;
//    Node* right;
//};
//
//class BinarySearchTree
//{
//public:
//    static bool contains(const Node& root, int& value)
//    {
//        Node* cur = (Node*)&root;
//        
//        if (cur == NULL)
//            return false;
//        if (cur->getValue() == value) {
//            return true;
//        }
//
//        Node* left = cur->getLeft();
//        Node* right = cur->getRight();
//        
//        return contains(*left, value) | contains(*right, value);
//    }
//};
//
//#ifndef RunTests
//int main()
//{
//    Node n1(1, NULL, NULL);
//    Node n3(3, NULL, NULL);
//    Node n2(2, &n1, &n3);
//
//    std::cout << BinarySearchTree::contains(n2, 3);
//}
//#endif

//class TextInput
//{
//protected:
//    std::string str;
//public:
//    virtual void add(char c) { 
//            str += c;
//    }
//
//    std::string getValue() { return str; }
//};
//
//class NumericInput : public TextInput { 
//
//    virtual void add(char c) {
//        if (c <= 0x39 && c >= 0x30) {
//            str += c;
//        }
//    }
//};
//
//#ifndef RunTests
//int main()
//{
//    TextInput* input = new NumericInput();
//    input->add('1');
//    input->add('a');
//    input->add('0');
//    std::cout << input->getValue();
//}
//#endif

//std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
//{
//    vector<std::string> ret;
//
//    ret.insert(ret.begin(), names1.begin(), names1.end());
//    ret.insert(ret.begin(), names2.begin(), names2.end());
//
//    std::sort(ret.begin(), ret.end());
//    auto it = std::unique(ret.begin(), ret.end());
//
//    ret.erase(it, ret.end());
//    return ret;
//}
//
//#ifndef RunTests
//int main()
//{
//    std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
//    std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };
//
//    std::vector<std::string> result = unique_names(names1, names2);
//    for (auto element : result)
//    {
//        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
//    }
//}
//#endif


//#include <math.h>
//큰수 sort 알고리즘
//int dLen(int a)
//{
//    if (a == 0)
//        return 1;
//    return static_cast<int>(log10(a)) + 1;
//}
//bool compare(int a, int b)
//{
//    int aL = dLen(a);
//    int bL = dLen(b);
//
//    int ab = a * pow(10, bL) + b;
//    int ba = b * pow(10, aL) + a;
//    return ab > ba;
//}
//string solution(vector<int> numbers) {
//    std::sort(numbers.begin(), numbers.end(), compare);
//
//    if (numbers.size() != 0 && numbers.at(0) == '0')
//        return "0";
//    string answer = "";
//    char chBuf[4];
//    for (auto& v : numbers)
//    {
//        sprintf(chBuf, "%d", v);
//        answer.append(chBuf);
//    }
//    return answer;
//}
//int sort(vector<int> array, vector<int> command)
//{
//    int iStart = command[0] - 1;
//    int iEnd = command[1] - 1;
//    int iAt = command[2] - 1;
//
//    std::sort(array.begin() + iStart, array.begin() + iEnd+1);
//    return array[iAt + iStart];
//}
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer; 
//    for (auto& v : commands)
//    {
//        answer.push_back(sort(array, v));
//    }
//    return answer;
//}

//priority_queue<int> pq;
//priority_queue<int, vector<int>, less<int>> pq;

//vector<tuple<int, int>> startandend;

//int maps[5000][5000];
//int visit[5000];
//
//priority_queue<int, vector<int>, less<int>> pq;
//void DFS(int n, int d) 
//{
//    if (n == d)
//        return;
//    int i; visit[n] = 1;
//    for (i = 1; i <= d; i++)
//    { 
//        if (maps[n][i] > 0 && !visit[i]) 
//        {
//            pq.push(maps[n][i]);
//         
//            if (i == d)
//                return;
//
//            DFS(i, d);
//        }
//    }
//}
//
//// route_row_len은 2차원 배열 route의 행(세로) 길이입니다.
//// route_col_len은 2차원 배열 route의 열(가로) 길이입니다.
//// route[i][j]는 route의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
//int solution(int n, vector<vector<int>> route) {
//    int answer = 0;
//
//    for (size_t row = 0; row < route.size(); ++row)
//    {
//        maps[route[row][0]][route[row][1]] = maps[route[row][1]][route[row][0]] = route[row][2];
//    }
//    DFS(1, n);
//    answer = pq.top();
//    return answer;
//}
//int main()
//{
//    vector< vector<int> > arr;
//
//    for (int i = 0; i < 3; i++)
//    {
//        vector<int> element(3);
//        arr.push_back(element);
//    }
//
//    arr[0][0] = 1;
//    arr[0][1] = 2;
//    arr[0][2] = 1;
//    
//    arr[1][0] = 1;
//    arr[1][1] = 3;
//    arr[1][2] = 4;
//    
//    arr[2][0] = 2;
//    arr[2][1] = 3;
//    arr[2][2] = 2;
//    solution(3, arr);
//    
//};

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
