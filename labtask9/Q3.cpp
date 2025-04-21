#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    string name, id, dob;
    string medicalHistory, currentTreatment;
    string billingDetails;

public:
    PatientRecord(string n, string i, string d)
        : name(n), id(i), dob(d), medicalHistory(""), currentTreatment(""), billingDetails("") {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id + ", DOB: " + dob;
    }

    string getMedicalData() const {
        return "History: " + medicalHistory + ", Treatment: " + currentTreatment;
    }

    void updateMedicalHistory(const string& history) { medicalHistory = history; }
    void updateTreatment(const string& treatment) { currentTreatment = treatment; }
    void addBillingDetails(const string& billing) { billingDetails = billing; }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void diagnose(PatientRecord& record, const string& history, const string& treatment) {
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
    }
};

class Billing {
public:
    void processPayment(PatientRecord& record, const string& details) {
        record.addBillingDetails(details);
    }
};

class Receptionist {
public:
    void tryAccess(PatientRecord& record) {
        cout << record.getPublicData() << endl;
        // cout << record.getMedicalData() << endl; // Not allowed
    }
};

int main() {
    PatientRecord p("John Doe", "P123", "1990-01-01");
    Doctor d;
    Billing b;
    Receptionist r;

    d.diagnose(p, "Flu", "Rest and hydration");
    b.processPayment(p, "$150 - paid");
    r.tryAccess(p);

    cout << "Medical Info (Doctor): " << p.getMedicalData() << endl;

    return 0;
}
