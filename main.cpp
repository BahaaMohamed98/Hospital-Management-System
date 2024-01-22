#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct patient {
    int age;
    string name;
    string disease;
    string gender;
};
vector<patient> records;
bool R;

void display_all();

void display(int index);

int search(string &name);

void delete_record(int index);

void patient_input_details();

inline void menu();

int main() {
    int operator_number, age;
    string name, disease;
    string gender;
    system("cls");
    cout << "Welcome!\n\n";
    cout << "[1] Add new patient record\n[2] View all patient records\n[3] Search patient record\n"
            "[4] Update patient record\n[5] Delete patient record\n[6] Exit\n\nchoose an operation:";
    cin >> operator_number;
    switch (operator_number) {
        case 1:
            patient_input_details();
            break;
        case 2:
            system("cls");
            display_all();
            break;
        case 3:
            system("cls");
            cout << "Enter patient's name:";
            cin >> name;
            cout << "Searching...\n";
            if (search(name) != -1) {
                cout << "Patient found!\n\n";
                display(search(name));
            } else
                cout << "Patient not found!\n\n";
            menu();
            break;
        case 4:
            int choice_to_update;
            system("cls");
            cout << "Enter patient's name:";
            cin >> name;
            cout << "\nSearching...\n";
            if (search(name) != -1) {
                int index = search(name);
                cout << "\nPatient found!\n";
                cout << "choose what to update:\n";
                cout << "[1] Age\n[2] Name\n[3] Gender\n[4] Disease\n";
                cin >> choice_to_update;
                system("cls");
                switch (choice_to_update) {
                    case 1:
                        cout << "Enter new age: ";
                        cin >> age;
                        records[index].age = age;
                        cout << "\nChanged successfully!\n";
                        break;
                    case 2:
                        cout << "Enter new name: ";
                        cin >> name;
                        name[0]=char(toupper(name[0]));
                        records[index].name = name;
                        cout << "\nChanged successfully!\n";
                        break;
                    case 3:
                        cout << "Enter new gender: ";
                        cin >> gender;
                        records[index].gender = (gender[0]=='M'?"Male":"Female");
                        cout << "\nChanged successfully!\n";
                        break;
                    case 4:
                        cout << "Enter new disease: ";
                        cin >> disease;
                        records[index].disease = disease;
                        cout << "\nChanged successfully!\n";
                        break;
                    default:
                        cout << "Enter a valid operation!\n";
                        return 0;
                }
            } else
                cout << "Patient not found!\n";
            menu();
            break;
        case 5:
            system("cls");
            cout << "Enter patient's name:";
            cin >> name;
            cout << "Searching...\n";
            char confirmation;
            if (search(name) != -1) {
                cout << "Patient found!\n";
                cout << "Are you sure you want to delete this record?[Y/N]:";
                cin >> confirmation;
                if (confirmation == 'y' || confirmation == 'Y') {
                    int index = search(name);
                    delete_record(index);
                    cout << "\nRecord deleted successfully!\n\n";
                }
                menu();
            } else
                cout << "Patient not found!\n";
            menu();
            break;
        case 6:
            exit(0);
        default:
            cout << "Choose valid operation!";
            return 0;
    }
    main();
}

void display_all() {
    system("cls");
    if (records.empty()) cout << "No records saved!\n\n";
    else {
        for (const auto &x: records) {
            cout << "====================================";
            cout << "\nPatient's Name: " << x.name;
            cout << "\nPatient's Age: " << x.age;
            cout << "\nPatient's Disease: " << x.disease;
            cout << "\nPatient's Gender: " << x.gender;
            cout << "\n====================================\n";
        }
    }
    menu();
}

void display(int index) {
    system("cls");
    cout << "====================================";
    cout << "\nPatient's Name: " << records[index].name;
    cout << "\nPatient's Age: " << records[index].age;
    cout << "\nPatient's Disease: " << records[index].disease;
    cout << "\nPatient's Gender: " << records[index].gender;
    cout << "\n====================================\n";
    menu();
}

int search(string &name) {
    name[0]=char(toupper(name[0]));
    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == name) {
            return i;
        }
    }
    return -1;
}

void delete_record(int index) {
    records.erase(records.begin() + index);
}

inline void menu() {
    cout << "[1] Return to main menu!\n[0] Exit\n";
    cin >> R;
    if (R) {
        system("cls");
        main();
    } else
        exit(0);
}

void patient_input_details() {
    int age;
    string name, disease;
    string gender;

    system("cls");
    cout << "\nEnter patient's details:\n";
    cin.ignore();
    cout << "Name:";
    getline(cin,name);
    name[0]=char(toupper(name[0]));
    cout << "Age:";
    cin >> age;
    cin.ignore();
    cout << "Disease:";
    getline(cin,disease);
    cout << "gender[M/F]:";
    cin >> gender;
    gender=(gender[0]=='m'?"Male":"Female");

    patient newPatient = {age, name, disease, gender};
    records.push_back(newPatient);
}
