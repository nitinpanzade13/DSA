#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 

int main() { 
    int n; 
    priority_queue<int> maxHeap; // Max-heap for finding maximum marks
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for finding minimum marks

    cout << "Enter the number of students: "; 
    cin >> n; 

    cout << "Enter the marks obtained by each student:" << endl; 
    for (int i = 0; i < n; i++) { 
        int marks; 
        cin >> marks; 
        maxHeap.push(marks); // Add marks to max-heap 
        minHeap.push(marks); // Add marks to min-heap 
    } 

    int maxMarks = maxHeap.top(); // Top of max-heap is the maximum 
    int minMarks = minHeap.top(); // Top of min-heap is the minimum 

    cout << "Maximum marks obtained: " << maxMarks << endl; 
    cout << "Minimum marks obtained: " << minMarks << endl; 

    return 0; 
}