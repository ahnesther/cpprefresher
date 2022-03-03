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
        string Company;
        int Age;
    protected:
        string Name;

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

// Developer inherits from Employee.
// Developer is now a subclass. 
// Employee is superclass/parentclass/baseclass
// Developer has all the properties of Employee.
class Developer:public Employee {
    private:
        string FavProgrammingLanguage;
    public:
        Developer(string name, string company, int age, string favProgrammingLanguage)
            :Employee(name, company, age) {
            this->FavProgrammingLanguage = favProgrammingLanguage;
        }
        void setFavLang(string lang) {
            this->FavProgrammingLanguage = lang;
        }
        string getFavLang() {
            return this->FavProgrammingLanguage;
        }

        void FixBug() {
            cout << this->Name << " is fixing a bug with " << this->getFavLang() << endl;
        }
};

class Manager:public Employee{
    public:
        string Department;
        int YearsOfExperience;
        Manager(string name, string company, int age, string department, int yearsOfExperience)
            :Employee(name, company, age) {
                this->Department = department;
                this->YearsOfExperience = yearsOfExperience;
        }
        void PreparingMeeting() {
            cout << this->Name << " is preparing a meeting for the " << this->Department << " all hands deck thing." << endl;
            cout << "They have used their " << this->YearsOfExperience << " years of work into their meeting well." << endl;
            cout << "It was a success!" << endl;
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

    Developer dev = Developer("Harry", "Uber", 28, "Golang");
    dev.FixBug();
    dev.AskForPrmotion(); // was not available until we put public after Developer:
    // we made the inheritance PUBLIC

    Manager mgr = Manager("Nina", "Gurgle", 35, "Research", 10);
    mgr.PreparingMeeting();
    mgr.AskForPrmotion();
    return 0;
}