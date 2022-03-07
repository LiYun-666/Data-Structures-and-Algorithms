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
list<pair<Position, Position>> A_star_search(Graph graph, Position start, Position goal)
{
    priority_queue<pair<Position, int>, vector<pair<Position, int>>, cmp> frontier;
    frontier.push({start, 0});
    list<pair<Position, Position>> came_from = {};
    unordered_map<Position, int> cost_so_far;

    came_from.push_back({start, Noplace});
    cost_so_far.push_back({start, 0});

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
            if (next not in cost_so_far || new_cost < cost_so_far[next])
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
