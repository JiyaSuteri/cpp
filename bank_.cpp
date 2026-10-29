#include <iostream>
using namespace std;
class BaseAccountClass {
public:
    virtual void SendMoney() {
        cout << "Permission Granted: Money Sent!" << endl;
    }

    virtual void ReceiveMoney() {
        cout << "Permission Granted: Money Received!" << endl;
    }

    virtual ~BaseAccountClass() {}
};
class ConsumerAccountClass : public BaseAccountClass {
public:
    bool flagged;
    ConsumerAccountClass(bool status) {
        flagged = status;
    }
    void SendMoney() override {
        if (flagged)
            cout << "Account Flagged: Sending Permission Denied!" << endl;
        else
            cout << "Sending Permission Granted!" << endl;
    }
    void ReceiveMoney() override {
        if (flagged)
            cout << "Account Flagged: Receiving Permission Denied!" << endl;
        else
            cout << "Receiving Permission Granted!" << endl;
    }
};

int main() {
    ConsumerAccountClass account(true);

    // Upcasting
    BaseAccountClass* ptr = &account;

    // Runtime polymorphism
    ptr->SendMoney();
    ptr->ReceiveMoney();

    // Downcasting
    ConsumerAccountClass* ptr2 =
        dynamic_cast<ConsumerAccountClass*>(ptr);

    if (ptr2 != NULL) {
        cout << "Downcasting Successful" << endl;
    }

    return 0;
}

