#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Employee {
    // properties
    public:
        string Name;
        string Company;
        int Age;

        // constructor :hearteyeemoji:
        Employee(string name, string company, int age) {
            this->Name = name;
            this->Company = company;
            this->Age = age;
        }
        void Introduce() {
            cout << "My name is " << Name << " and I work at " << Company << " at " << Age << " years old. Suck it!!!" << endl;
        }
};

int main() {
    Employee emp1 = Employee("Bill", "Microsoft", 25);
    emp1.Introduce();

    Employee emp2 = Employee("John", "Amazon", 53);
    emp2.Introduce();

    return 0;
}