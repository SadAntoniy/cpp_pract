#include <iostream>
#include <string>
#include <map>

using namespace std;
struct name_lastname {
    string name;
    string lastname;
};
class Person {
public:

    void ChangeFirstName(int year, const string& first_name) {
        all_changes[year].name = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {     
        all_changes[year].lastname = last_name;
    }

    string GetFullName(int year) {
        string name;
        string lastname;   

        for (auto& ch : all_changes) {
            if (year < ch.first) {
                return "Incognito";
            }
            break;
        }               

        for (auto& ch : all_changes) {            
            if (ch.first <= year && ch.second.name != "")
                name = ch.second.name;
            if (ch.first <= year && ch.second.lastname != "")
                lastname = ch.second.lastname;
        }

        if (lastname == "")   
            return name + " with unknown last name";        
        else if (name == "") 
            return lastname + " with unknown first name";        
        else  
          return name + " " + lastname;       
    }

private:
    map<int, name_lastname> all_changes;      
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
         cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}