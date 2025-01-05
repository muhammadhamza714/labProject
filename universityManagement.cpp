#include <iostream>
#include <string>
using namespace std;

int main() {
    // Constants
    const int maxSeats = 5;
    const int maxPrograms = 3;

    // Program Data
    string programNames[maxPrograms] = {"BSCS", "AI", "LAW"};
    short programMinEligibility[maxPrograms] = {550, 660, 770};
    short programAvailableSeats[maxPrograms] = {maxSeats, maxSeats, maxSeats};

    // Student Data
    string studentName = "N/A";
    string studentEmail;
    string studentPhoneNumber;
    string studentCNIC;
    string studentAppliedProgram = "N/A";
    string studentStatus = "Not Applied";
    string studentRejectionReason = "";
    short studentPreviousMarks;

    // Admin Data
    string username, password;
    int choice, adminChoice, programChoice;

    do {
        // Main Menu
        cout << "\nUniversity Admission Management System\n";
        cout << "1. Admin\n";
        cout << "2. Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Admin Section
            cout << "Enter Admin Username: ";
            cin >> username;
            cout << "Enter Admin Password: ";
            cin >> password;

            if (username == "admin" && password == "password") {
                cout << "\nAdmin Login Successful.\n";
                cout << "1. Edit Programs\n";
                cout << "2. View Application Status\n";
                cout << "3. Logout\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                if (adminChoice == 1) {
                    // Edit Programs
                    cout << "Choose Program to Edit (1: BSCS, 2: AI, 3: LAW): ";
                    cin >> programChoice;
                    if (programChoice >= 1 && programChoice <= maxPrograms) {
                        int index = programChoice - 1;
                        cout << "Enter New Program Name: ";
                        cin >> programNames[index];
                        cout << "Enter Minimum Eligibility Marks: ";
                        cin >> programMinEligibility[index];
                    } else {
                        cout << "Invalid Program Choice.\n";
                    }
                } else if (adminChoice == 2) {
                    // View Application Status
                    cout << "\nViewing Application Status:\n";
                    cout << "Student Name: " << studentName << "\n";
                    cout << "Applied Program: " << studentAppliedProgram << "\n";
                    cout << "Status: " << studentStatus;
                    if (studentStatus == "Rejected")
                        cout << " (" << studentRejectionReason << ")";
                    cout << "\n";
                } else if (adminChoice == 3) {
                    cout << "Logging out...\n";
                } else {
                    cout << "Invalid choice. Try again.\n";
                }
            } else {
                cout << "Invalid Admin credentials.\n";
            }
        } else if (choice == 2) {
            // Student Section
            cout << "Enter your Name: ";
            cin >> studentName;
            cout << "Enter your Email: ";
            cin >> studentEmail;
            cout << "Enter your Phone Number: ";
            cin >> studentPhoneNumber;
            cout << "Enter your CNIC: ";
            cin >> studentCNIC;
            cout << "Enter your Previous Marks (out of 1100): ";
            cin >> studentPreviousMarks;

            // Display Available Programs
            cout << "\nAvailable Programs:\n";
            for (int i = 0; i < maxPrograms; i++) {
                cout << i + 1 << ". " << programNames[i] 
                     << " (Eligibility: " << programMinEligibility[i] 
                     << ", Seats: " << programAvailableSeats[i] << ")\n";
            }

            cout << "Enter your Program Preference (1, 2, or 3): ";
            cin >> programChoice;

            // Decision Logic
            if (programChoice >= 1 && programChoice <= maxPrograms) {
                int index = programChoice - 1;
                studentAppliedProgram = programNames[index];
                if (studentPreviousMarks >= programMinEligibility[index] &&
                    programAvailableSeats[index] > 0) {
                    studentStatus = "Accepted";
                    programAvailableSeats[index]--;
                } else {
                    studentStatus = "Rejected";
                    studentRejectionReason = (studentPreviousMarks < programMinEligibility[index]) 
                        ? "Eligibility criteria not met" 
                        : "No seats available";
                }
            } else {
                studentAppliedProgram = "Invalid";
                studentStatus = "Rejected";
                studentRejectionReason = "Invalid program choice";
            }

            cout << "\nApplication Status: " << studentStatus;
            if (studentStatus == "Rejected")
                cout << " (" << studentRejectionReason << ")";
            cout << "\n";
        } else if (choice == 3) {
            cout << "Exiting the system...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
