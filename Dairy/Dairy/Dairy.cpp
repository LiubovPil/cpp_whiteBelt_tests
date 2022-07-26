// Tasks from the course "Fundamentals of C++: White Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
    int q;
    cin >> q;

    int month = 0;
    vector<vector<string>> dairy_with_tasks(months[month]);

    for (int i = 0; i < q; ++q) {
        string requested_operation;
        cin >> requested_operation;

        if (requested_operation == "ADD") {
            int day = 0;
            string task;
            cin >> day >> task;

            if (day > 0 && day <= months[month]) {
                --day;
                dairy_with_tasks[day].push_back(task);
            }
            else
                cout << "There is no such day" << endl;
        }
        else if (requested_operation == "NEXT") {
            int previous_month = month;
            ++month;
            if (month >= months.size()) {
                month = 0;
            }
            if (months[month] < months[previous_month]) {
                vector<string>& last_day = dairy_with_tasks[months[month] - 1];
                for (int i = months[month]; i < months[previous_month]; ++i) {
                    last_day.insert(end(last_day), begin(dairy_with_tasks[i]), end(dairy_with_tasks[i]));
                }
            }
            dairy_with_tasks.resize(months[month]);
        }
        else if (requested_operation == "DUMP") {
            int day = 0;
            cin >> day;
            if (day <= 0 || day > 31) {
                cout << "There is no such day" << endl;
            }
            else {
                --day;
                cout << dairy_with_tasks[day].size() << ": ";
                for (const auto& item : dairy_with_tasks[day]) {
                    cout << item << " ";
                }
            }
        }
    }
    return 0;
}

