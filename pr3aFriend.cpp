#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct User {
    string name;
    string date_of_birth;  // in format YYYY-MM-DD
    int num_of_comments;
    vector<int> friends; // adjacency list to store friends (node IDs)
};


class SocialNetwork {
private:
    unordered_map<int, User> users; 

public:
    void addUser(int id, string name, string dob, int comments) {
        users[id] = {name, dob, comments};
    }

    void addFriendship(int u1, int u2) {
        users[u1].friends.push_back(u2);
        users[u2].friends.push_back(u1);
    }

    void findMaxFriends() {
        int max_friends = 0;
        string user_with_max_friends;

        for (const auto& user : users) {
            if (user.second.friends.size() > max_friends) {
                max_friends = user.second.friends.size();
                user_with_max_friends = user.second.name;
            }
        }

        cout << "User with the maximum friends: " << user_with_max_friends
             << " with " << max_friends << " friends.\n";
    }

    void findMaxMinComments() {
        int max_comments = -1, min_comments = INT_MAX;
        string user_with_max_comments, user_with_min_comments;

        for (const auto& user : users) {
            if (user.second.num_of_comments > max_comments) {
                max_comments = user.second.num_of_comments;
                user_with_max_comments = user.second.name;
            }
            if (user.second.num_of_comments < min_comments) {
                min_comments = user.second.num_of_comments;
                user_with_min_comments = user.second.name;
            }
        }

        cout << "User with the maximum comments: " << user_with_max_comments
             << " with " << max_comments << " comments.\n";
        cout << "User with the minimum comments: " << user_with_min_comments
             << " with " << min_comments << " comments.\n";
    }

    void findBirthdaysThisMonth(int current_month) {
        cout << "Users with birthdays in month " << current_month << ":\n";

        for (const auto& user : users) {
            int birth_month = stoi(user.second.date_of_birth.substr(5, 2)); // extract MM from YYYY-MM-DD
            if (birth_month == current_month) {
                cout << user.second.name << " has a birthday this month.\n";
            }
        }
    }

    // BFS traversal
    void BFS(int start) {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << "Visited user: " << users[current].name << "\n";

            for (int friend_id : users[current].friends) {
                if (!visited[friend_id]) {
                    visited[friend_id] = true;
                    q.push(friend_id);
                }
            }
        }
    }

    // DFS traversal 
    void DFSUtil(int user, unordered_map<int, bool>& visited) {
        visited[user] = true;
        cout << "Visited user: " << users[user].name << "\n";

        for (int friend_id : users[user].friends) {
            if (!visited[friend_id]) {
                DFSUtil(friend_id, visited);
            }
        }
    }

    void DFS(int start) {
        unordered_map<int, bool> visited;
        DFSUtil(start, visited);
    }
};

int main() {
    SocialNetwork sn;

    sn.addUser(1, "Nitin", "1990-10-15", 5);
    sn.addUser(2, "Bunty", "1985-03-22", 20);
    sn.addUser(3, "Sarvesh", "1995-10-05", 12);
    sn.addUser(4, "Aziz", "1998-11-30", 2);
    sn.addUser(5, "Vivek", "2000-12-10", 30);

    sn.addFriendship(1, 3);
    sn.addFriendship(2, 3);
    sn.addFriendship(3, 4);
    sn.addFriendship(4, 5);

    sn.findMaxFriends();

    sn.findMaxMinComments();

    sn.findBirthdaysThisMonth(10);

    cout << "\nBFS traversal starting from Nitin:\n";
    sn.BFS(1);

    cout << "\nDFS traversal starting from Nitin:\n";
    sn.DFS(1);

    return 0;
}
