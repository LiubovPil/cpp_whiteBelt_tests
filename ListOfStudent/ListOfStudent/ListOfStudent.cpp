// ListOfStudent.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    Student(string firstname_value, string lastname_value,
        int birth_day_value, int birth_month_value, int birth_year_value) {
        firstname = firstname_value;
        lastname = lastname_value;

        birth_day = birth_day_value;
        birth_month = birth_month_value;
        birth_year = birth_year_value;
    }
    string firstname = "", lastname = "";

    int birth_day = 0, birth_month = 0, birth_year = 0;
};

int main()
{
    vector<Student> students;

    int N;
    cin >> N;

    for (int i = 0; i < N ; ++i) {
        string firstname_value, lastname_value;
        int birth_day_value, birth_month_value, birth_year_value;
        cin >> firstname_value >> lastname_value 
            >> birth_day_value >> birth_month_value >> birth_year_value;

        Student student = {firstname_value , lastname_value , birth_day_value, birth_month_value, birth_year_value};
        students.push_back(student);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string requested_operation;
        size_t K;
        cin >> requested_operation 
            >> K;

        if (requested_operation == "name" && (K > 0 && K <= students.size())) {
            cout << students.at(K-1).firstname << " " << students.at(K-1).lastname << endl;
        }
        else if (requested_operation == "date" && (K > 0 && K <= students.size()))
        {
            cout << students.at(K-1).birth_day << "." << students.at(K-1).birth_month << "." << students.at(K-1).birth_year << endl;
        }
        else {
            cout << "bad request";
        }
    }
}
