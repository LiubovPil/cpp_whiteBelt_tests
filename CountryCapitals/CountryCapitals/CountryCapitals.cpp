// Tasks from the course "Fundamentals of C++: White Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int q = 0; // count of request
    cin >> q;

    map<string, string> counties_capitals;

    for (int i = 0; i < q; ++i) {
        string requested_operation;
        cin >> requested_operation;

        if (requested_operation == "CHANGE_CAPITAL") {
            string country_value, new_capital_value;
            cin >> country_value >> new_capital_value;
            
            if (counties_capitals.count(country_value) == 0) {
                counties_capitals[country_value] = new_capital_value;
                cout << "Introduce new " << country_value << " with capital " << new_capital_value << endl;
            }
            else if (counties_capitals[country_value] == new_capital_value) {
                cout << "Country " << country_value << " hasn't changed its capital" << endl;
            }
            else {
                string old_capital_value = counties_capitals[country_value];
                counties_capitals[country_value] = new_capital_value;
                cout << "Country " << country_value << " has changed its capital from " << old_capital_value << " to " << new_capital_value << endl;
            }
        }
        else if (requested_operation == "RENAME") {
            string old_country_value, new_country_value;
            cin >> old_country_value >> new_country_value;

            if (counties_capitals.count(old_country_value) == 1 && counties_capitals.count(new_country_value) == 0) {
                counties_capitals[new_country_value] = counties_capitals[old_country_value];
                counties_capitals.erase(old_country_value);
                cout << "Country " << old_country_value << " with capital " << counties_capitals[new_country_value] << " has been renamed to " << new_country_value << endl;
            }
            else {
                cout << "Incorrect rename, skip " << endl;
            }
        }
        else if (requested_operation == "ABOUT") {
            string country_value;
            cin >> country_value;
            if (counties_capitals.count(country_value) == 0) {
                cout << "Country " << country_value << " does't exist" << endl;
            }
            else {
                cout << "Country " << country_value << " has capital " << counties_capitals[country_value] << endl;
            }
        }
        else if (requested_operation == "DUMP") {
            if (counties_capitals.size() == 0) {
                cout << "There no countries in the world" << endl;
            }
            else {
                for (const auto& item : counties_capitals){
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
    }
}

