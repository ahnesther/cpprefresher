#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Employee {
    // properties
    private:
        string Name;
        string Company;
        int Age;
    public:
        // setters and getters (ugly)
        void setName(string name) {
            this->Name = name;
        }
        string getName() {
            return this->Name;
        }

        void setCompany(string company) {
            this->Company = company;
        }
        string getCompany() {
            return this->Company;
        }

        void setAge(int age) {
            if(age >= 18) {
                this->Age = age;
            }
        }
        int getAge() {
            return this->Age;
        }

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
    emp1.setAge(10); // will not change cos of the check.
    emp1.setCompany("Uber");
    emp1.Introduce();
    cout << emp1.getAge();

    Employee emp2 = Employee("John", "Amazon", 53);
    emp2.Introduce();
    cout << emp2.getAge();

    return 0;
}