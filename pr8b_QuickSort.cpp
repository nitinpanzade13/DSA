#include <iostream>
using namespace std;

struct Student {
    string name;
    int credits;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].credits;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].credits > pivot) {  
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Student students[] = {{"Alice", 85}, {"Bob", 90}, {"Charlie", 88}, {"David", 92}, {"Eva", 80}, {"Frank", 87}};
    int n = sizeof(students) / sizeof(students[0]);

    quickSort(students, 0, n - 1);

    cout << "Top 3 students based on credits:\n";
    for (int i = 0; i < 3; i++) {
        cout << students[i].name << " - " << students[i].credits << " credits\n";
    }

    return 0;
}
