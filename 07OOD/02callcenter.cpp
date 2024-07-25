// https://godbolt.org/z/WE7j4Wrh7

#include <iostream>
#include <vector>

// 员工基类
class Employee {
protected:
    std::string name;
    bool isAvailable;

public:
    Employee(const std::string& name) : name(name), isAvailable(true) {}

    virtual bool canHandleCall() const = 0;
    virtual void handleCall() = 0;

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    std::string getName() const {
        return name;
    }
};

// 接线员类
class Operator : public Employee {
public:
    Operator(const std::string& name) : Employee(name) {}

    bool canHandleCall() const override {
        return getAvailability();
    }

    void handleCall() override {
        std::cout << "Operator " << getName() << " is handling the call.\n";
        setAvailability(false);
    }
};

// 经理类
class Manager : public Employee {
public:
    Manager(const std::string& name) : Employee(name) {}

    bool canHandleCall() const override {
        return getAvailability();
    }

    void handleCall() override {
        std::cout << "Manager " << getName() << " is handling the call.\n";
        setAvailability(false);
    }
};

// 主管类
class Director : public Employee {
public:
    Director(const std::string& name) : Employee(name) {}

    bool canHandleCall() const override {
        return getAvailability();
    }

    void handleCall() override {
        std::cout << "Director " << getName() << " is handling the call.\n";
        setAvailability(false);
    }
};

// 呼叫中心类
class CallCenter {
private:
    std::vector<Operator> operators;
    std::vector<Manager> managers;
    std::vector<Director> directors;

public:
    void addOperator(const Operator& op) {
        operators.push_back(op);
    }

    void addManager(const Manager& mgr) {
        managers.push_back(mgr);
    }

    void addDirector(const Director& dir) {
        directors.push_back(dir);
    }

    void dispatchCall() {
        for (auto& op : operators) {
            if (op.canHandleCall()) {
                op.handleCall();
                return;
            }
        }

        for (auto& mgr : managers) {
            if (mgr.canHandleCall()) {
                mgr.handleCall();
                return;
            }
        }

        for (auto& dir : directors) {
            if (dir.canHandleCall()) {
                dir.handleCall();
                return;
            }
        }

        std::cout << "All employees are busy. Please wait.\n";
    }
};

int main() {
    CallCenter callCenter;

    callCenter.addOperator(Operator("Alice"));
    callCenter.addOperator(Operator("Bob"));
    callCenter.addManager(Manager("Charlie"));
    callCenter.addDirector(Director("Diana"));

    callCenter.dispatchCall(); // Assign call to available operator
    callCenter.dispatchCall(); // Assign call to available manager if all operators are busy
    callCenter.dispatchCall(); // Assign call to available director if all managers are busy
    callCenter.dispatchCall();
    callCenter.dispatchCall();
    return 0;
}
