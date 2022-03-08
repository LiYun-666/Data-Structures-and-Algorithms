#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Position
{
    int x;
    int y;
};
Position Noplace = {-1, -1};

namespace std
{
    template <>
    struct hash<Position> // 哈希的模板定制
    {
    public:
        size_t operator()(const Position &p) const
        {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };

    template <>
    struct equal_to<Position> // 等比的模板定制
    {
    public:
        bool operator()(const Position &p1, const Position &p2) const
        {
            return p1.x == p2.x && p1.y == p2.y;
        }
    };
}

class Graph
{
public:
    vector<vector<int>> map;

    Graph() // 构造函数初始化图
    {
        for (size_t i = 0; i < 5; i++)
        {
            vector<int> tmp(5, 0);
            map.push_back(tmp);
        }
    }

    vector<Position> neighbors(Position current) // 返回当前位置的相邻结点
    {
        vector<Position> ret;
        int x = current.x, y = current.y;
        if (x >= 0 && x < 5 && y - 1 >= 0 && y - 1 < 5 && !isObstacle(x, y - 1))
            ret.push_back({x, y - 1});
        if (x - 1 >= 0 && x - 1 < 5 && y >= 0 && y < 5 && !isObstacle(x - 1, y))
            ret.push_back({x - 1, y});
        if (x + 1 >= 0 && x + 1 < 5 && y >= 0 && y < 5 && !isObstacle(x + 1, y))
            ret.push_back({x + 1, y});
        if (x >= 0 && x < 5 && y + 1 >= 0 && y + 1 < 5 && !isObstacle(x, y + 1))
            ret.push_back({x, y + 1});
        return ret;
    }

    int cost(Position d1, Position d2) // 计算 cost
    {
        return abs(d1.x - d2.x) + abs(d1.y - d2.y);
    }

    bool isObstacle(int x, int y) // 判断是否是障碍物
    {
        if (x == 1 && y == 0)
            return true;
        if (x == 2 && y == 1)
            return true;
        if (x == 3 && y == 1)
            return true;
        if (x == 0 && y == 2)
            return true;
        if (x == 2 && y == 2)
            return true;
        if (x == 2 && y == 3)
            return true;
        if (x == 2 && y == 3)
            return true;
        return false;
    }
};

int heuristic(Position p1, Position p2) // 曼哈顿距离
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

struct cmp
{
    bool operator()(pair<Position, int> p1, pair<Position, int> p2) // 自定义比较函数
    {
        return p1.second > p2.second;
    }
};

vector<pair<Position, Position>> get_path(Position start, Position goal, vector<pair<Position, Position>> came_from) // 提取出路径
{

    vector<pair<Position, Position>> ret;
    for (int i = came_from.size() - 1; i >= 0; i--)
    {
        if (goal.x == came_from[i].first.x && goal.y == came_from[i].first.y)
        {
            ret.push_back(came_from[i]);
            goal = came_from[i].second;
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<pair<Position, Position>> A_star_search(Graph graph, Position start, Position goal) // 主逻辑，A*搜索算法
{
    priority_queue<pair<Position, int>, vector<pair<Position, int>>, cmp> frontier;
    frontier.push({start, 0});

    vector<pair<Position, Position>> came_from;
    unordered_map<Position, int> cost_so_far;

    came_from.push_back({start, Noplace});
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        Position current = frontier.top().first;
        frontier.pop();
        if (current.x == goal.x && current.y == goal.y) // 如果到达终点
        {
            break;
        }
        for (auto next : graph.neighbors(current))
        {
            int new_cost = cost_so_far[current] + graph.cost(current, next);
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                int priority = new_cost + heuristic(goal, next);
                frontier.push({next, priority});
                came_from.push_back({next, current});
            }
        }
    }
    return get_path(start, goal, came_from);
}

int main()
{
    Graph graph;
    vector<pair<Position, Position>> path = A_star_search(graph, {0, 0}, {4, 0});
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i].first.x << "," << path[i].first.y << " <- " << path[i].second.x << "," << path[i].second.y << endl;
    }
    return 0;
}
