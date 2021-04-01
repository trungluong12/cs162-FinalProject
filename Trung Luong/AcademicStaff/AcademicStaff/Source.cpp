#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct AcademicStaff {
	string Name;
	bool Gender = 0;//0 is female 1 is male
	string UserName;
	string Password;
};
void ReadfileAcademicStaff(AcademicStaff*& staff, int& n) {
	fstream t;
	t.open("AcademicStaff.txt");
	if (!t.is_open()) {
		cout << "Can't load data "; return;
	}
	string temp;
	getline(t, temp); n = stoi(temp);
	int i = 0;
	staff = new AcademicStaff[n];
	while (!t.eof()) {
		getline(t, staff[i].UserName, '\n');
		getline(t, staff[i].Password, '\n');
		getline(t, staff[i].Name, '\n');
		getline(t, temp); staff[i].Gender = stoi(temp);
		i = i + 1;
	}
	t.close();
}
void WritefileAcademaicStaff(AcademicStaff* staff, int& n) {
	fstream t;
	t.open("AcademicStaff.txt", fstream::out);
	if (!t.is_open()) {
		cout << "Can't load data "; return;
	}
	t << n;
	for (int i = 0; i < 4; i++) {
		t << endl << staff[i].UserName << endl;
		t << staff[i].Password << endl;
		t << staff[i].Name << endl;
		t << staff[i].Gender;
	}
	t.close();
}
int LoginforStaff(AcademicStaff* staff, int n) {
	AcademicStaff person;
	bool flag = false; int count = 0;
	while (flag == false) {
		cout << "User Name: "; cin >> person.UserName;
		cout << "Password: "; cin >> person.Password;
		for (int i = 0; i < n; i++)
			if (staff[i].UserName == person.UserName && staff[i].Password == person.Password) {
				cout << "Log in successfully! " << endl;
				if (staff[i].Gender == 0) cout << "Hello Ms." << staff[i].Name << ". Have a nice day " << endl;
				else cout << "Hello Mr." << staff[i].Name << ". Have a nice day " << endl;
				return i;
			}
		count = count + 1; cout << "Wrong usename or password.Pls enter again! " << endl;
		if (count == 3) { cout << "You tried to log in but you wrong two many time. Pls contact I53 to reset your acount "; return -1; }
	}
}
void ResetPassword(AcademicStaff*& staff, int n, int& indexofstaff) {
	cout << "Are you sure to change your password (Yes/No) "; string s; cin >> s; int count = 0;
	if (s == "Yes") {
		cout << "So be careful! " << endl << "Pls enter your current password ";
		cin.ignore();
		getline(cin, s);
		while (s != staff[indexofstaff].Password && count != 3) {
			cout << "Wrong password. Pls enter again ";
			getline(cin, s);
			count = count + 1;
		}
		s = "1"; string ss = "0";
		if (count != 3) {
			while (s != ss) {
				cout << "New password: "; getline(cin, s);
				cout << "Cofirm New password "; getline(cin, ss);
				if (s == ss) {
					cout << "Change password successfully!.Pls login again! ";
					staff[indexofstaff].Password = s;
					WritefileAcademaicStaff(staff, n);
					indexofstaff = -1;
				}
				else { cout << "Your cofirm new password is not same. Pls enter again! " << endl; }
			}
		}
		else {
			s = (staff[indexofstaff].Gender == 0) ? "Ms." : "Mr.";
			cout << "You loss your password or you not " << s << staff[indexofstaff].Name << ". So you will be loged out";
			indexofstaff = -1;
			return;
		}
	}
	else return;
}
void Profile(AcademicStaff* staff, int indexofstaff) {
	string s = (staff[indexofstaff].Gender == 0) ? "Female" : "Male";
	cout << "Use Name: " << staff[indexofstaff].UserName << endl;
	cout << "Name: " << staff[indexofstaff].Name << endl;
	cout << "Gender: " << s;
}
void Logout(AcademicStaff*& staff, int& indexofstaff) {
	indexofstaff = -1;
	delete[] staff;
}
int main() {
	AcademicStaff* staff = nullptr;
	int n;
	ReadfileAcademicStaff(staff, n);

	int k = LoginforStaff(staff, n);
	Profile(staff, k);
	Logout(staff, k);
}

