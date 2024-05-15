//https://leetcode.com/problems/course-schedule/description/
#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    // Build the adjacency list and calculate indegrees
    for (auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int prereq = prerequisite[1];
        adj[course].push_back(prereq);
        indegree[prereq]++;
    }

    // Initialize a queue with courses having no prerequisites
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int completedCourses = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();

        completedCourses++;

        // Decrement indegree of dependent courses
        for (int nextCourse : adj[course]) {
            indegree[nextCourse]--;
            if (indegree[nextCourse] == 0) {
                q.push(nextCourse);
            }
        }
    }

    // Check if all courses can be completed
    return completedCourses == numCourses;
}

int main() {
    int numCourses, numPrerequisites;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    cout << "Enter the number of prerequisites: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));

    cout << "Enter the prerequisites (course number, prerequisite number) one by one:\n";
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    if (canFinish(numCourses, prerequisites)) {
        cout << "It is possible to finish all courses." << endl;
    } else {
        cout << "It is not possible to finish all courses due to a cycle." << endl;
    }

    return 0;
}

