// Tasks from the course "Fundamentals of C++: White Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

string FindNameByYear(int year, const map<int, string>& name_changes) {
    string name_result;
    for (const auto& item : name_changes)
    {
        if (item.first > year) {
            break;
        }
        name_result = item.second;
    }
    return name_result;
}

string BuildNameHistory(int year, const map<int, string>& name_changes) {
    string name_history;
    for (const auto& item : name_changes)
    {

    }
    return name_history;
    /*set<string> name_history;
    
    for (const auto& item : name_changes){
        if (item.first > year) {
            break;
        }
        name_history.insert(item.second);
    }
    name_history.erase(FindNameByYear(year, name_changes));
    for (const auto& item : name_history){
        result_name_history += item + ",";
    }*/
}

string PrintName(const string& firstname, const string& lastname) {
    if (firstname.empty() && lastname.empty()) {
        return "Incognito";
    }
    else if (!firstname.empty() && lastname.empty()) {
        return firstname + " with unknown last name";
    }
    else if (firstname.empty() && !lastname.empty()) {
        return lastname + " with unknown first name";
    }
    else
        return firstname + " " + lastname;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstname_changes[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        lastname_changes[year] = last_name;
    }
    string GetFullName(int year) {
        const string firstname = FindNameByYear(year, firstname_changes);
        const string lastname = FindNameByYear(year, lastname_changes);

        return PrintName(firstname, lastname);
    }
    string GetFullNameWithHistory(int year) {
        const string firstname_history = BuildNameHistory(year, firstname_changes);
        const string lastname_history = BuildNameHistory(year, lastname_changes);

        return PrintName(firstname_history, lastname_history);

        /*for (const auto& item : firstname_changes) {
            if (item.first < year)
                firstname_history.insert(item.second);
        }
        for (const auto& item : lastname_changes) {
            if (item.first < year)
                lastname_history.insert(item.second);
        }
        firstname_history.erase(firstname);
        lastname_history.erase(lastname);*/

        /*if (firstname_history.empty() && lastname_history.empty()){
            return GetFullName(year);
        }
        else 
            if (lastname == "EMPTY") {
                return firstname + "(" + firstname_history + ")" + " with unknown last name";
            }
            else if (firstname == "EMPTY") {
                return lastname + "(" + lastname_history + ")" + " with unknown first name";
            }
            else
                return firstname + "(" + firstname_history + ")" + " " + lastname + "(" + lastname_history + ")";*/
    }
private:
    map<int, string> firstname_changes;
    map<int, string> lastname_changes;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
