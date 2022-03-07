#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

struct Position
{
    int x;
    int y;
};
namespace std
{
    template <>
    struct hash<Position>
    { //哈希的模板定制
    public:
        size_t operator()(const Position &p) const
        {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };

    template <>
    struct equal_to<Position>
    { //等比的模板定制
    public:
        bool operator()(const Position &p1, const Position &p2) const
        {
            return p1.x == p2.x && p1.y == p2.y;
        }
    };
}
Position Noplace = {-1, -1};
class Graph
{
public:
    vector<vector<int>> map;
    vector<Position> neighbors(Position current)
    {
        //
    }
    int cost(Position d1, Position d2)
    {
        //
    }
};
int heuristic(Position p1, Position p2)
{
    //
}
struct cmp
{
    bool operator()(pair<Position, int> p1, pair<Position, int> p2)
    {
        return p1.second < p2.second;
    }
};
unordered_map<Position, Position> A_star_search(Graph graph, Position start, Position goal)
{
    priority_queue<pair<Position, int>, vector<pair<Position, int>>, cmp> frontier;
    frontier.push({start, 0});
    unordered_map<Position, Position> came_from;
    unordered_map<Position, int> cost_so_far;

    came_from[start] = Noplace;
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
                came_from[next] = current;
            }
        }
    }
    return came_from;
}

int main()
{
    
}
