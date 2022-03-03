#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// Abstraction: only one rule
// virtual function.
class AbstractEmployee {
    // contract: whichever class decides to sign contract,
    // this uses this and signing needs to
    // provide implementation etc
    virtual void AskForPrmotion()=0;
    // obligatory; force any other class sign this 
    // give implementation details
    // A virtual function (has no definition, as 
    // the class inheriting it must provide its own)
};

class Employee:AbstractEmployee {
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
        // need to implement or o/w get error.
        void AskForPrmotion() {
            if(this->Age > 30) {
                cout << this->Name << " got promoted!" << endl;
            } else {
                cout << this->Name << " did not get promoted. Sry." << endl;
            }
        }
};

int main() {
    Employee emp1 = Employee("Bill", "Microsoft", 25);
    emp1.Introduce();
    emp1.setAge(10); // will not change cos of the check.w
    emp1.setCompany("Uber");

    Employee emp2 = Employee("John", "Amazon", 53);
    emp2.Introduce();
    emp1.AskForPrmotion();
    emp2.AskForPrmotion();

    return 0;
}