// Tasks from the course "Fundamentals of C++: White Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> FindHistoryNameByYear(int year, const map<int, string>& name_changes) {
    vector<string> name_history;
    for (const auto& item : name_changes)
    {
        if (item.first > year) {
            break;
        }
        name_history.push_back(item.second);
    }
    return name_history;
}

string BuildNameHistoryByYear(const vector<string>& name_history) {
    string name_history_tostring;
    if(name_history.empty())
        return name_history_tostring;

    name_history_tostring = name_history.back();
    for (int i = name_history.size() - 2; i >= 0; -- i) //can be replaced by function reverse(begin(name_history), end(name_history)) and direct cycle for
    {
        if (name_history[i] != name_history[i + 1]){
            if(i == name_history.size() - 2)
                name_history_tostring += " (";

            name_history_tostring += name_history[i];
            if (i > 0)
                name_history_tostring += ", ";
            else
                name_history_tostring += ")";
        }
    }
    return name_history_tostring;
}

/*//no longer required
string PrintName(const string& firstname, const string& lastname) { 
    if (firstname.empty() && lastname.empty()) {
        return "No person";
    }
    else if (!firstname.empty() && lastname.empty()) {
        return firstname + " with unknown last name";
    }
    else if (firstname.empty() && !lastname.empty()) {
        return lastname + " with unknown first name";
    }
    else
        return firstname + " " + lastname;
}*/

class Person {
public:
    Person(const string& first_name, const string& last_name, int year) {
        birth_year = year;
        firstname_changes[year] = first_name;
        lastname_changes[year] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birth_year)
            firstname_changes[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birth_year)
            lastname_changes[year] = last_name;
    }
    string GetFullName(int year) const {
        if (year < birth_year)
            return "No person";

        const vector<string> firstname_history = FindFirstNamesHistory(year); //for code readability
        const vector<string> lastname_history = FindLastNamesHistory(year); //for code readability

        string firstname;
        string lastname;

        if (!firstname_history.empty())  //no longer required
            firstname.back();
        if (!lastname_history.empty())
            lastname.back();

        return firstname + " " + lastname; //firstname.back() + " " + lastname.back();
    }
    string GetFullNameWithHistory(int year) const {
        if (year < birth_year)
            return "No person";

        vector<string> firstname_history = FindFirstNamesHistory(year); //for code readability
        vector<string> lastname_history = FindLastNamesHistory(year); //for code readability

        string firstname_history_tostring = BuildNameHistoryByYear(firstname_history); //can be combined with line 81
        string lastname_history_tostring = BuildNameHistoryByYear(lastname_history); //can be combined with line 82

        return firstname_history_tostring + " " + lastname_history_tostring;
    }
private:
    vector<string> FindFirstNamesHistory(int year) const {
        return FindHistoryNameByYear(year, firstname_changes);
    }
    vector<string> FindLastNamesHistory(int year) const {
        return FindHistoryNameByYear(year, lastname_changes);
    }

    int birth_year;
    map<int, string> firstname_changes;
    map<int, string> lastname_changes;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
