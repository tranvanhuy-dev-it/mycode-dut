#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    static int cnt;
    int id;
    string Name;
    string Birth;
    long long Phone;
    string Email;
    string Class;
    int SchoolYear;
    string Faculty;
    double GPA;
    string Pass;
public:
    Student();
    Student(int, string, string, long long, string, string, int, string, double, string);
    static void setCnt(int value);
    static int getCnt();
    string HocLuc() const;
    void display() const;
    void set_GPA(double po);
    string Return_ID_Name();
    string set_Pass();
    void reset_Pass();
    void edit_Pass(string pa);
    string return_Pass();
    string return_Cls();
    double return_GPA();

    void input();
    void inputif(string cls, int year, string Faculty);
    string saveTocsv() const;
    void Edit_Name(string name);
    void Edit_Birth(string birth);
    void Edit_Phone(long long phone);
    friend class StudentList;
};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string to_string_with_precision(double value, int n = 2) {
    stringstream stream;
    stream << fixed << setprecision(n) << value;
    return stream.str();
}

string Center(const string& s, int width) {
    int len = s.length();
    if (width <= len) return s;
    int left = (width - len) / 2;
    int right = width - len - left;
    return string(left, ' ') + s + string(right, ' ');
}

int Student::cnt = 0;

Student::Student() {
    id = ++cnt;
}

Student::Student(int _id, string _Name, string _Birth,  long long _Phone, string _Email, string _Class, int _SchoolYear, string _Faculty, double _GPA, string _Pass) {
    id = _id;
    Name = _Name;
    Phone = _Phone;
    Birth = _Birth;
    Email = _Email;
    Class = _Class;
    SchoolYear = _SchoolYear;
    Faculty = _Faculty;
    GPA = _GPA;
    Pass = _Pass;
}

void Student::setCnt(int value) {
    cnt = value;
}

int Student::getCnt() {
    return cnt;
}

string Student::HocLuc() const {
    if (GPA >= 3.6) return "Xuat Sac";
    else if (GPA >= 3.2 && GPA < 3.6) return "Gioi";
    else if (GPA >= 2.5 && GPA < 3.2) return "Kha";
    else if (GPA >= 2 && GPA < 2.5) return "Trung Binh";
    else return "Kem";
}

void Student::display() const {
    cout << left
         << "│" << setw(10) << Center(to_string(id), 10)
         << "│" << setw(20) << Center(Name, 20)
         << "│" << setw(12) << Center(Birth, 12)
         << "│" << setw(15) << Center(to_string(Phone), 15)
         << "│" << setw(30) << Center(Email, 30)
         << "│" << setw(10) << Center(Class, 10)
         << "│" << setw(10) << Center(to_string(SchoolYear), 10)
         << "│" << setw(15) << Center(Faculty, 15)
         << "│" << setw(10) << Center(to_string_with_precision(GPA, 2), 10)
         << "│" << setw(15) << Center(HocLuc(), 15)
         << "│" << endl;
         cout << string(158, '-') << endl;
}

void Student::set_GPA(double po) {
    GPA = po;
}

string Student::Return_ID_Name() {
    return "ID: " + to_string(id) + " Name: " + Name + ": ";
}

double Student::return_GPA() {
    return GPA;
}

string Student::set_Pass() {
    string a;
    for (char c : Birth) {
        if (c != '/') {
            a += c;
        }
    }
    return a;
}

void Student::reset_Pass() {
    Pass = set_Pass();
}

void Student::edit_Pass(string pa) {
    Pass = pa;
}

string Student::return_Pass() {
    return Pass;
}

string Student::return_Cls() {
    return Class;
}

void Student::input() {
    cin.ignore();
    cout << "Nhap Ten: "; getline(cin, Name);
    cout << "Nhap Ngay Sinh: "; getline(cin, Birth);
    cout << "Nhap SDT: "; cin >> Phone; cin.ignore();
    cout << "Nhap Lop: "; getline(cin, Class);
    cout << "Nhap Nam hoc: "; cin >> SchoolYear; cin.ignore();
    cout << "Nhap Khoa: "; getline(cin, Faculty);
    GPA = 0;
    id = ++cnt;
    Email = to_string(id) + "@sv1.dut.udn.vn"; 
    Pass = set_Pass();
}

void Student::inputif(string cls, int year, string Faculty) {
    cin.ignore();
    cout << "Nhap Ten: "; getline(cin, Name);
    cout << "Nhap Ngay Sinh: "; getline(cin, Birth);
    cout << "Nhap SDT: "; cin >> Phone; cin.ignore();
    Class = cls;
    SchoolYear = year;
    Faculty = Faculty;
    GPA = 0;
    id = ++cnt;
    Email = to_string(id) + "@sv1.dut.udn.vn"; 
    Pass = set_Pass();
}

string Student::saveTocsv() const {
    stringstream ss;
    ss << id << "," << Name << "," << Birth << "," << Phone << "," << Email << "," << Class << "," << SchoolYear << "," << Faculty << "," << GPA << "," << Pass;
    return ss.str();
}

void Student::Edit_Name(string name) {
    Name = name;
}

void Student::Edit_Birth(string birth) {
    Birth = birth;
}

void Student::Edit_Phone(long long phone) {
    Phone = phone;
}

class StudentList {
private:
    list<Student> students;
    list<Student> bins;
public:
    void First_Table() const;
    int ReadFile_Data();          
    int ReadFile_Bin();  
    int ReadInput(int year, string cls, string faculty); 

    int WriteFile_Data();                           
    int WriteFile_Bin();

    void Add(const Student&);                      
    void NewStudent();   

    void Display_All() const; 
    void Display_Class(string cls) const;
    void Display_SYear(int year) const;
    void Display_Faculty(string fac) const;
    void Display_Faculty_SYear(string fac, int year) const;
    void Display_Bin() const;

    void SearchID(int id) const;                    
    void SearchName(string Name) const;            
    void SearchClass(string Class) const;        
    void SearchFaculty(string Faculty) const;     
    void SearchSYear(int SYear) const;  

    void SortID();                            
    void SortName();                               
    void SortGPA();    

    void ThongKeXS();
    void ThongKeG();
    void ThongKeK();
    void ThongKeTB();
    void ThongKeKem();

    void DeleteID(int ID);
    void DeleteSYear(int SYear);

    void Restore(int ID);
    void Clean_Bin();

    void Point(int id, double po);
    void Point_Class(string Class);

    void Edit_Name(int id);
    void Edit_Birth(int id);
    void Edit_Phone(int id);

    void Reset_Pass(int id);
    int Login(int id);

    Student Return_Std(int id);

    void Edit_Pass_Std(int id);



};

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lower;
}

bool SS(const string& a, const string& b) {
    return toLower(a) == toLower(b);
}

void StudentList::First_Table() const {
    cout << string(158, '-') << endl;
    cout << left
         << "│" << setw(10) << Center("ID", 10)
         << "│" << setw(20) << Center("Ten", 20)
         << "│" << setw(12) << Center("Ngay Sinh", 12)
         << "│" << setw(15) << Center("SDT", 15)
         << "│" << setw(30) << Center("Email", 30)
         << "│" << setw(10) << Center("Lop", 10)
         << "│" << setw(10) << Center("Nam", 10)
         << "│" << setw(15) << Center("Khoa", 15)
         << "│" << setw(10) << Center("GPA", 10)
         << "│" << setw(15) << Center("Hoc Luc", 15)
         << "│" << endl;
    cout << string(158, '-') << endl;
}

void StudentList::Add(const Student& s) {
    students.push_back(s);
}

int StudentList::ReadFile_Data() {
    ifstream fin("data.csv");
    if (!fin.is_open()) {
        return 0;
    }

    string line;
    int maxId = 0;
    while (getline(fin, line)) {
        stringstream ss(line);
        int id, year;
        long long phone;
        string name, faculty, Class, Email, birth, pass, token;
        double gpa;

        getline(ss, token, ','); id = stoi(token);
        getline(ss, name, ',');
        getline(ss, birth, ',');
        getline(ss, token, ','); phone = stoll(token);
        getline(ss, Email, ',');
        getline(ss, Class, ',');
        getline(ss, token, ','); year = stoi(token);
        getline(ss, faculty, ',');
        getline(ss, token, ','); gpa = stod(token);
        getline(ss, pass);

        if (id > maxId) maxId = id;

        Add(Student(id, name, birth, phone, Email,  Class, year, faculty, gpa, pass));
    }
    Student::setCnt(maxId);
    fin.close();
    return 1;
}

int StudentList::ReadFile_Bin() {
    ifstream fin("bin.csv");
    if (!fin.is_open()) {
        return 0;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        int id, year;
        long long phone;
        string name, faculty, Class, Email, birth, pass, token;
        double gpa;

        getline(ss, token, ','); id = stoi(token);
        getline(ss, name, ',');
        getline(ss, birth, ',');
        getline(ss, token, ','); phone = stoll(token);
        getline(ss, Email, ',');
        getline(ss, Class, ',');
        getline(ss, token, ','); year = stoi(token);
        getline(ss, faculty, ',');
        getline(ss, token, ','); gpa = stod(token);
        getline(ss, pass);

        bins.push_back(Student(id, name, birth, phone, Email, Class, year, faculty, gpa, pass));
    }
    fin.close();
    return 1;
}

int StudentList::ReadInput(int year, string cls, string faculty){
    cout << "Nhap vao file thong tin sinh vien: ";
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if (!fin.is_open()) {
        return 0;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        long long phone;
        string name, birth, token;


        getline(ss, name, ',');
        getline(ss, birth, ',');
        getline(ss, token, ','); phone = stoll(token);

        Student NewStd;
        NewStd.Name = name;
        NewStd.Phone = phone;
        NewStd.Birth = birth;
        NewStd.Class = cls;
        NewStd.Faculty = faculty;
        NewStd.Email = to_string(NewStd.id) + "@sv1.dut.udn.vn";
        NewStd.Pass = NewStd.set_Pass();
        NewStd.GPA = 0; 

        Add(NewStd);
    }
    WriteFile_Data();
    fin.close();
    return 1;
}

int StudentList::WriteFile_Data() {
    ofstream fout("data.csv");
    if (!fout.is_open()) {
        return 0;
    }

    for (const auto& s : students) {
        fout << s.saveTocsv() << endl;
    }

    fout.close();
    return 1;
}

int StudentList::WriteFile_Bin() {
    ofstream fout("bin.csv");
    if (!fout.is_open()) {
        return 0;
    }

    for (const auto& s : bins) {
        fout << s.saveTocsv() << endl;
    }

    fout.close();
    return 1;
}

void StudentList::NewStudent() {
    Student s;
    s.input();
    Add(s);
    WriteFile_Data();
    cout << "Da them sinh vien moi!\n";
}

void StudentList::Display_All() const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    for (const auto& s : students) {
        s.display();
    }
}
void StudentList::Display_Class(string cls) const{
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    bool check = false;
    for (const auto& s : students) {
        if (s.Class == cls) {
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien thuoc lop " << cls << endl;
    }
}
void StudentList::Display_SYear(int year) const{
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    bool check = false;
    for (const auto& s : students) {
        if (s.SchoolYear == year) {
            check = true;
            s.display();
        }
    }
    if (!check) {
        cout << "Khong co sinh vien thuoc khoa " << year << endl;
    }
}
void StudentList::Display_Faculty(string fac) const{
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    bool check = false;
    for (const auto& s : students) {
        if (s.Faculty == fac) {
            check = true;
            s.display();
        }
    }
    if (!check) {
        cout << "Khong co sinh vien thuoc khoa sinh hoat " << fac << endl;
    }
}
void StudentList::Display_Faculty_SYear(string fac, int year) const{
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    bool check = false;
    for (const auto& s : students) {
        if (s.Faculty == fac && s.SchoolYear == year) {
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien hop le " << endl;
    }
}



void StudentList::Display_Bin() const {
    if (bins.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    First_Table();

    for (const auto& s : bins) {
        s.display();
    }
}

void StudentList::SearchID(int id) const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
    }

    for (const auto& s : students) {
        if (s.id == id) {
            First_Table();
            s.display();
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void StudentList::SearchName(string Name) const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (SS(s.Name, Name)) {
            if (check != true) {
                First_Table();
            }
            s.display();
            check = true;
        }
    }
    if (!check) cout << "Khong tim thay sinh vien!\n";
}

void StudentList::SearchClass(string Class) const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
    }

    bool check = false;
    for (const auto& s : students) {
        if (SS(s.Class, Class)) {
            if (check != true) {
                First_Table();
            }
            s.display();
            check = true;
        }
    }
    if (!check) cout << "Khong tim thay sinh vien!\n";
}

void StudentList::SearchFaculty(string Faculty) const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
    }

    bool check = false;
    for (const auto& s : students) {
        if (SS(s.Faculty, Faculty)) {
            if (check != true) {
                First_Table();
            }
            s.display();
            check = true;
        }
    }
    if (!check) cout << "Khong tim thay sinh vien!\n";
}

void StudentList::SearchSYear(int SYear) const {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.SchoolYear == SYear) {
            if (check != true) {
                First_Table();
            }
            s.display();
            check = true;
        }
    }
    if (!check) cout << "Khong tim thay sinh vien!\n";
}

void StudentList::SortID() {
    students.sort([](const Student& a, const Student& b) {
        return a.id < b.id;
    });
}

void StudentList::SortName() {
    students.sort([](const Student& a, const Student& b) {
        return a.Name < b.Name;
    });
}

void StudentList::SortGPA() {
    students.sort([](const Student& a, const Student& b) {
        return a.GPA < b.GPA;
    });
}

void StudentList::ThongKeXS() {
    int count = 0;
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.HocLuc() == "Xuat Sac") {
            if (!check) {
                cout << "Danh sach sinh vien dat Xuat Sac:\n";
                First_Table();
            }
            count++;
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien Xuat Sac!\n\n";
    } else {
        cout << "Tong so: " << count << "\n\n";
    }
}

void StudentList::ThongKeG() {
    int count = 0;
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.HocLuc() == "Gioi") {
            if (!check) {
                cout << "Danh sach sinh vien dat Gioi:\n";
                First_Table();
            }
            count++;
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien Gioi!\n\n";
    } else {
        cout << "Tong so: " << count << "\n\n";
    }
}

void StudentList::ThongKeK() {
    int count = 0;
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.HocLuc() == "Kha") {
            if (!check) {
                cout << "Danh sach sinh vien dat Kha:\n";
                First_Table();
            }
            count++;
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien Kha!\n\n";
    } else {
        cout << "Tong so: " << count << "\n\n";
    }
}

void StudentList::ThongKeTB() {
    int count = 0;
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.HocLuc() == "Trung Binh") {
            if (!check) {
                cout << "Danh sach sinh vien dat Trung Binh:\n";
                First_Table();
            }
            count++;
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien Trung Binh!\n\n";
    } else {
        cout << "Tong so: " << count << "\n\n";
    }
}

void StudentList::ThongKeKem() {
    int count = 0;
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (const auto& s : students) {
        if (s.HocLuc() == "Kem") {
            if (!check) {
                cout << "Danh sach sinh vien dat Kem:\n";
                First_Table();
            }
            count++;
            s.display();
            check = true;
        }
    }
    if (!check) {
        cout << "Khong co sinh vien Kem!\n\n";
    } else {
        cout << "Tong so: " << count << "\n\n";
    }
}

void StudentList::DeleteID(int ID) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == ID) {
            bins.push_back(*it);
            it = students.erase(it);
            if (WriteFile_Bin() && WriteFile_Data()) {
                cout << "Da chuyen vao thung rac!\n";
            } else {
                cout << "Loi khi ghi file!\n";
            }
            return;
        }
    }
    cout << "Khong tim thay sach hop le!\n";
    
}

void StudentList::DeleteSYear(int Year) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }

    bool check = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->SchoolYear == Year) {
            check = true;
            bins.push_back(*it);
            it = students.erase(it);
        }
    }
    if (!check) {
        cout << "Khong tim thay sinh vien hop le!\n";
    } else {
         if (WriteFile_Bin() && WriteFile_Data()) {
                cout << "Da chuyen vao thung rac!\n";
            } else {
                cout << "Loi khi ghi file!\n";
            }
    }
}

void StudentList::Restore(int ID) {
    if (bins.empty()) {
        cout << "Thung rac trong!\n";
        return;
    }
    for (auto it = bins.begin(); it != bins.end(); ++it) {
        if (it->id == ID) {
            students.push_back(*it);
            it = bins.erase(it);
            SortID();
            if (WriteFile_Bin() && WriteFile_Data()) {
                cout << "Da khoi phuc thanh cong!\n";
            } else {
                cout << "Loi khi ghi file!\n";
            }
            return;
        }
    }
    cout << "Khong tim thay sinh vien hop le!\n";
}

void StudentList::Clean_Bin() {
    for (auto it = bins.begin(); it != bins.end(); ++it) {
        it = bins.erase(it);
    }
    WriteFile_Bin();
}

void StudentList::Point(int id, double po) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    for (auto& s : students) {
        if (s.id == id) {
            s.set_GPA(po);
            cout << "Da cap nhat diem thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void StudentList::Point_Class(string Class) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    bool check = false;
    for (auto& s : students) {
        if (s.Class == Class) {
            check = true;
            int po;
            s.Return_ID_Name();
            cin >> po;
            s.set_GPA(po);

        }
    }
    if (!check) {
        cout << "Khong tim thay sinh vien!\n";
    } else {
        cout << "Da cap nhat diem thanh cong!\n";
    }
}

void StudentList::Edit_Name(int id) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    for (auto& s : students) {
        if (s.id == id) {
            string name;cin.ignore();
            cout << "NHap vao ten moi: ";
            getline(cin, name);
            s.Edit_Name(name);
            cout << "Da thay doi ten thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void StudentList::Edit_Birth(int id) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    for (auto& s : students) {
        if (s.id == id) {
            string birth; cin.ignore();
            cout << "NHap vao ngay sinh moi: ";
            getline(cin, birth);
            s.Edit_Birth(birth);
            cout << "Da thay doi ngay sinh thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void StudentList::Edit_Phone(int id) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    for (auto& s : students) {
        if (s.id == id) {
            long long phone;
            cout << "NHap vao so dien thoai: ";
            cin >> phone;
            s.Edit_Phone(phone);
            cout << "Da thay doi so dien thoai thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void StudentList::Reset_Pass(int id) {
    if (students.empty()) {
        cout << "Danh sach sinh vien trong\n";
        return;
    }
    for (auto& s : students) {
        if (s.id == id) {
            s.reset_Pass();
            cout << "Da thay dat lai mat khau thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

int StudentList::Login(int id) {
    for (auto& s : students) {
        if (s.id == id) {
            int t = 1;
            cout << "Nhap mat khau: ";
            while (t < 6) {
                string pass;
                cin >> pass;
                if (pass == s.return_Pass()) {
                    return 1;
                } else {
                    t++;
                    cout << "Mat khau sai!\nNhap lai mat khau: ";
                }
            }
            if (t == 6) {
                return 0;
            }
        }
    }
    return -1;
}

Student StudentList::Return_Std(int id) {
    for (auto& s : students) {
        if (s.id == id) {
            return s;
        }
    }
}

void StudentList::Edit_Pass_Std(int id) {
    for (auto& s : students) {
        if (s.id == id) {
            string p1, p2, p3;
            cout << "Nhap vao mat khau cu: ";
            cin.ignore();
            getline(cin, p1);
            if (p1 == s.Pass) {
                cout << "Nhap mat khau moi: ";
                getline(cin, p2);
                cout << "Xac nhan mat khau moi: ";
                getline(cin, p3);
                if (p2 == p3) {
                    s.edit_Pass(p2);
                    cout << "Da thay doi mat khau thanh cong!\n";
                } else {
                    cout << "Mat khau khong khop!\n";
                }
            } else {
                cout << "Sai mat khau!\n";
            }
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ID nay!\n";
}


class Menu_Function {
private:
    StudentList& Stdl;
    string pass;
public: 
    Menu_Function(StudentList& stdl) : Stdl(stdl) {}
    void Read();
    void Add_Student();
    void Del();
    void Bin();
    void Search();
    void Sort();
    void ThongKe();
    void GPA();
    void Edit();
    void Menu_Admin();
    void Std_Edit(int id);
    void Std_Check(int id);
    void Std_Edit_Pass(int id);
    void Std_Cls(int id);
    void Menu_Std(int id);

    void Read_Pass_Admin();
    void Write_Pass_Admin();
    string returnPass();
    void Edit_Pass_Admin();
};

void Menu_Function::Read() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                 XEM DANH SACH SINH VIEN                  │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Xem toan bo sinh vien                                  │\n";
    cout << "│2. Xem sinh vien theo lop sinh hoat                       │\n";
    cout << "│3. Xem sinh vien theo khoa sinh hoat                      │\n";
    cout << "│4. Xem sinh vien theo khoa hoc                            │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 4) {
            switch(choice) {
                case 1:
                {
                    Stdl.Display_All();
                    break;
                }
                case 2:
                {
                    cout << "Nhap vao lop sinh hoat: ";
                    string cls;
                    cin >> cls;
                    Stdl.Display_Class(cls);
                    break;
                }
                case 3:
                {
                    cout << "Nhap vao khoa sinh hoat: ";
                    string fac;
                    cin >> fac;
                    Stdl.Display_Faculty(fac);
                    break;
                }
                case 4:
                {
                    cout << "Nhap vao khoa hoc: ";
                    int year;
                    cin >> year;
                    Stdl.Display_SYear(year);
                    break;
                }
                case 5:
                {
                    cout << "Nhap vao khoa hoc: ";
                    int year; cin >> year;
                    cout << "Nhap vao khoa sinh hoat: ";
                    string fac; cin >> fac;
                    Stdl.Display_Faculty_SYear(fac, year);
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    } 
}

void Menu_Function::Add_Student() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                       THEM SINH VIEN                     │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Them mot sinh vien                                     │\n";
    cout << "│2. Them sinh vien vao dau nam hoc(thu cong)               │\n";
    cout << "│3. Them sinh vien vao dau nam hoc(tu file)                │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice; 
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            switch(choice) {
                case 1:
                {
                    cout << "Nhap vao thong tin sinh vien\n";
                    Student NewStd;
                    NewStd.input();
                    Stdl.Add(NewStd);
                    Stdl.WriteFile_Data();
                    cout << "Da them sinh vien thanh cong\n";
                    break;
                }
                case 2:
                {
                    int year, total;
                    string cls, faculty;
                    cout << "Nhap vao nam hoc moi: ";
                    cin >> year;
                    cout << "Nhap vao khoa sinh hoat: ";
                    cin >> faculty;
                    cout << "Nhap vao lop sinh hoat: ";
                    cin >> cls;
                    cout << "Nhap vao tong so sinh vien cua lop: ";
                    cin >> total;
                    for(int i = 1; i <= total; i++) {
                        cout << "Nhap vao sinh vien thu " << i << endl;
                        Student NewStd;
                        NewStd.inputif(cls, year, faculty);
                        Stdl.Add(NewStd);
                        cout << endl;
                    }
                    Stdl.WriteFile_Data();
                    cout << "Da  them sinh vien thanh cong!\n";
                    break;
                }
                case 3:
                {
                    int year;
                    string cls, faculty;
                    cout << "Nhap vao nam hoc moi: ";
                    cin >> year;
                    cout << "Nhap vao khoa sinh hoat: ";
                    cin >> faculty;
                    cout << "Nhap vao lop sinh hoat: ";
                    cin >> cls;
                    if (Stdl.ReadInput(year, cls, faculty)) {
                        cout << "Da them sinh vien thanh cong!\n";
                    } else {
                        cout << "Loi khi doc file!\n";
                    }
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}

void Menu_Function::Del() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                      XOA SINH VIEN                       │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Xoa mot sinh vien                                      │\n";
    cout << "│2. Xoa sinh vien da ra truong                             │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 2) {
            switch(choice) {
                case 1:
                {
                    cout << "Nhap vao ID sinh vien can xoa: ";
                    int ID; cin >> ID;
                    Stdl.DeleteID(ID);
                    break;
                }
                case 2:
                {
                    cout << "Nhap vao khoa sinh vien ra truong:";
                    int SYear; cin >> SYear;
                    Stdl.DeleteSYear(SYear);
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}

void Menu_Function::Bin() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                         THUNG RAC                        │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Khoi phuc sinh vien da xoa                             │\n";
    cout << "│2. Lam sach thung rac                                     │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 2) {
            switch(choice) {
                case 1:
                {
                    cout << "Nhap vao ID sinh vien can khoi phuc: ";
                    int ID; cin >> ID;
                    Stdl.Restore(ID);
                    break;
                }
                case 2:
                {
                    Stdl.Clean_Bin();
                    cout << "Da lam sach thung rac!\n";
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    } 
}

void Menu_Function::Search() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                    TIM KIEM SINH VIEN                    │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Tim kiem sinh vien theo ID                             │\n";
    cout << "│2. Tim kiem sinh vien theo ten                            │\n";
    cout << "│3. Tim kiem sinh vien theo khoa                           │\n";
    cout << "│4. Tim kiem sinh vien theo lop sinh hoat                  │\n";
    cout << "│5. Tim kiem sinh vien theo khoa sinh hoat                 │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 5) {
            switch(choice) {
                case 1:
                {
                    int ID;
                    cout << "Nhap vao ID sinh vien can tim: ";
                    cin >> ID;
                    Stdl.SearchID(ID);
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "Nhap vao ten sinh vien can tim: ";
                    cin.ignore();
                    getline(cin, name);
                    Stdl.SearchName(name);
                    break;
                }
                case 3:
                {
                    int year;
                    cout << "Nhap vao khoa sinh vien can tim: ";
                    cin >> year;
                    Stdl.SearchSYear(year);
                    break;
                }
                case 4:
                {
                    string cls;
                    cout << "Nhap vao lop sinh hoat cua sinh vien can tim: ";
                    cin >> cls;
                    Stdl.SearchClass(cls);
                    break;
                }
                case 5:
                {
                    string faculty;
                    cout << "Nhap vao khoa sinh hoat cua sinh vien can tim: ";
                    cin.ignore();
                    getline(cin, faculty);
                    Stdl.SearchFaculty(faculty);
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}

void Menu_Function::Sort() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                    SAP XEP SINH VIEN                     │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Sap xep theo ID                                        │\n";
    cout << "│2. Sap xep theo ten                                       │\n";
    cout << "│3. Sap xep theo GPA                                       │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while(1) {
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            switch(choice) {
                case 1:
                {
                    Stdl.SortID();
                    Stdl.Display_All();
                    break;
                }
                case 2:
                {
                    Stdl.SortName();
                    Stdl.Display_All();
                    Stdl.SortID();
                    break;
                }
                case 3:
                {
                    Stdl.SortGPA();
                    Stdl.Display_All();
                    Stdl.SortID();
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    } 
}

void Menu_Function::ThongKe() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                     THONG KE HOC LUC                     │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Xuat sac                                               │\n";
    cout << "│2. Gioi                                                   │\n";
    cout << "│3. Kha                                                    │\n";
    cout << "│4. Trung Binh                                             │\n";
    cout << "│5. Kem                                                    │\n";
    cout << "│6. Tat ca                                                 │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >= 1 && choice <= 6) {
            switch(choice) {
                case 1:
                {
                    Stdl.ThongKeXS();
                    break;
                }
                case 2:
                {
                    Stdl.ThongKeG();
                    break;
                }
                case 3:
                {
                    Stdl.ThongKeK();
                    break;
                }
                case 4:
                {
                    Stdl.ThongKeTB();
                    break;
                }
                case 5:
                {
                    Stdl.ThongKeKem();
                    break;
                }
                case 6:
                {
                    Stdl.ThongKeXS();
                    Stdl.ThongKeG();
                    Stdl.ThongKeK();
                    Stdl.ThongKeTB();
                    Stdl.ThongKeKem();
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}

void Menu_Function::GPA() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                CAP NHAT DIEM GPA TICH LUY                │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Cap nhat cho mot sinh vien                             │\n";
    cout << "│2. Cap nhat cho mot lop                                   │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while(1) {
        cin >> choice;
        if (choice >= 1 && choice <= 2) {
            switch(choice) {
                case 1:
                {
                    cout << "Nhap vao ID sinh vien: ";
                    int id; cin >> id;
                    cout << "Nhap vao GPA: ";
                    double gpa; cin >> gpa;
                    Stdl.Point(id, gpa);
                    break;
                }
                case 2:
                {
                    cout << "Nhap vao lop can nhap diem: ";
                    string cls; cin >> cls;
                    Stdl.Point_Class(cls);
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    } 
    
}

void Menu_Function::Edit() {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│               CHINH SUA THONG TIN SINH VIEN              │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Sua ten                                                │\n";
    cout << "│2. Sua ngay sinh                                          │\n";
    cout << "│3. Sua so dien thoai                                      │\n";
    cout << "│4. Sua tat ca                                             │\n";
    cout << "│5. Dat lai mat khau                                       │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >=1 && choice <= 5) {
            switch(choice) {
                case 1:
                {
                    int id;
                    cout << "Nhap vao ID sinh vien: ";
                    cin >> id;
                    Stdl.Edit_Name(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 2:
                {
                    int id;
                    cout << "Nhap vao ID sinh vien: ";
                    cin >> id;
                    Stdl.Edit_Birth(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 3:
                {
                    int id;
                    cout << "Nhap vao ID sinh vien: ";
                    cin >> id;
                    Stdl.Edit_Phone(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 4:
                {
                    int id;
                    cout << "Nhap vao ID sinh vien: ";
                    cin >> id;
                    Stdl.Edit_Name(id);
                    Stdl.Edit_Birth(id);
                    Stdl.Edit_Phone(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 5:
                {
                    int id;
                    cout << "Nhap vao ID sinh vien: ";
                    cin >> id;
                    Stdl.Reset_Pass(id);
                    Stdl.WriteFile_Data();
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}

void Menu_Function::Menu_Admin() {
    int choice;
    do {
        cout << "┌──────────────────────────────────────────────────────────┐\n";
        cout << "│                  HE THONG QUAN LI SINH VIEN              │\n";
        cout << "├──────────────────────────────────────────────────────────┤\n";
        cout << "│1.  Xem danh sach sinh vien                               │\n";
        cout << "│2.  Them sinh vien                                        │\n";
        cout << "│3.  Chinh sua thong tin sinh vien                         │\n";
        cout << "│4.  Cap nhap GPA tich luy                                 │\n";
        cout << "│5.  Xoa sinh vien                                         │\n";
        cout << "│6.  Tim kiem thong tin sinh vien                          │\n";
        cout << "│7.  Sap xep sinh vien                                     │\n";
        cout << "│8.  Thong ke hoc luc                                      │\n";
        cout << "│9.  Thung rac                                             │\n";
        cout << "│10. Doi mat khau                                          │\n";
        cout << "│0.  Thoat                                                 │\n";
        cout << "└──────────────────────────────────────────────────────────┘\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        clearScreen();
        if (choice >= 1 && choice <= 10) {
            switch(choice) {
                case 1:
                {
                    Read();
                    break;
                }
                case 2:
                {
                    Add_Student();
                    break;
                }
                case 3:
                {
                    Edit();
                    break;
                }
                case 4:
                {
                    GPA();
                    break;
                }
                case 5:
                {
                    Del();
                    break;
                }
                case 6:
                {
                    Search();
                    break;
                }
                case 7:
                {
                    Sort();
                    break;
                }
                case 8:
                {
                    ThongKe();
                    break;
                }
                case 9:
                {
                    Bin();
                    break;
                }
                case 10:
                {
                    Edit_Pass_Admin();
                    break;
                }
            }
        }
        else return;
    } while (choice != 0);
}

void Menu_Function::Read_Pass_Admin() {
    ifstream fin("pass.txt");

    string pa;
    if (fin.is_open()) {
        getline(fin, pa);
        pass = pa;
        fin.close();
    }
}

void Menu_Function::Write_Pass_Admin() {
    ofstream fout("pass.txt");
    if (fout.is_open()) {
        fout << pass;
        fout.close();
    }
}

string Menu_Function::returnPass() {
    return pass;
}

void Menu_Function::Edit_Pass_Admin() {
    string p1, p2, p3;
    cout << "Nhap mat khau cu: "; cin.ignore();
    getline(cin, p1);
    if (p1 == pass) {
        cout << "Nhap mat khau moi: "; 
        getline(cin, p2);
        cout << "Xac nhan mat khau moi: ";
        getline(cin, p3);
        if (p2 == p3) {
            pass = p2;
            Write_Pass_Admin();
            cout << "Da thay doi mat khau thanh cong!\n";
        }
        else {
            cout << "Mat khau khong khop, vui long thu lai sau\n";
        }
    }
}

void Menu_Function::Std_Edit(int id) {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│               CHINH SUA THONG TIN SINH VIEN              │\n";
    cout << "├──────────────────────────────────────────────────────────┤\n";
    cout << "│1. Sua ten                                                │\n";
    cout << "│2. Sua ngay sinh                                          │\n";
    cout << "│3. Sua so dien thoai                                      │\n";
    cout << "│4. Sua tat ca                                             │\n";
    cout << "│0. Thoat                                                  │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    cout << "Lua chon: ";
    int choice;
    while (1) {
        cin >> choice;
        if (choice >=1 && choice <= 4) {
            switch(choice) {
                case 1:
                {
                    Stdl.Edit_Name(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 2:
                {
                    Stdl.Edit_Birth(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 3:
                {
                    Stdl.Edit_Phone(id);
                    Stdl.WriteFile_Data();
                    break;
                }
                case 4:
                {
                    Stdl.Edit_Name(id);
                    Stdl.Edit_Birth(id);
                    Stdl.Edit_Phone(id);
                    Stdl.WriteFile_Data();
                    break;
                }
            }
            return;
        } 
        else if(choice != 0) {
            cout << "Lua chon khong hop le\nVui long nhap lai: ";
        } else {
            clearScreen();
            cout << "Da quay ve menu chinh\n";
            return;
        }
    }
}


void Menu_Function::Std_Check(int id) {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                       KET QUA HOC TAP                    │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    Student s = Stdl.Return_Std(id);
    cout << "GPA: " << s.return_GPA() << endl;
    cout << "Hoc Luc: " << s.HocLuc() << endl;
}

void Menu_Function::Std_Edit_Pass(int id) {
    cout << "┌──────────────────────────────────────────────────────────┐\n";
    cout << "│                          DOI MAT KHAU                    │\n";
    cout << "└──────────────────────────────────────────────────────────┘\n";
    Stdl.Edit_Pass_Std(id);
    Stdl.WriteFile_Data();
}

void Menu_Function::Std_Cls(int id) {
    Student s = Stdl.Return_Std(id);
    Stdl.SearchClass(s.return_Cls());
}

void Menu_Function::Menu_Std(int id) {
    int choice;
    do {
        cout << "┌──────────────────────────────────────────────────────────┐\n";
        cout << "│                  HE THONG QUAN LI SINH VIEN              │\n";
        cout << "├──────────────────────────────────────────────────────────┤\n";
        cout << "│1.  Chinh sua thong tin ca nhan                           │\n";
        cout << "│2.  Ket qua hoc tap                                       │\n";
        cout << "│3.  Danh sach sinh vien lop sinh hoat                     │\n";
        cout << "│4.  Doi mat khau                                          │\n";
        cout << "│0.  Thoat                                                 │\n";
        cout << "└──────────────────────────────────────────────────────────┘\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        clearScreen();
        if (choice >= 1 && choice <= 4) {
            switch(choice) {
                case 1:
                {
                    Std_Edit(id);
                    break;
                }
                case 2:
                {
                    Std_Check(id);
                    break;
                }
                case 3:
                {
                    Std_Cls(id);
                    break;
                }
                case 4:
                {
                    Std_Edit_Pass(id);
                    break;
                }
            }

        }
    } while(choice != 0);
}

// ========================== MAIN ===========================

int main() {
    system("chcp 65001 > nul");
    StudentList List;
    Menu_Function Menu(List);

    int choice;
    do {
        cout << "┌──────────────────────────────────────────────────────────┐\n";
        cout << "│          HE THONG QUANG LI SINH VIEN - DANG NHAP         │\n";
        cout << "├──────────────────────────────────────────────────────────┤\n";
        cout << "│1. Admin - Nguoi quan tri                                 │\n";
        cout << "│2. Sinh vien                                              │\n";
        cout << "│0. Thoat                                                  │\n";
        cout << "└──────────────────────────────────────────────────────────┘\n";
        cout << "Nhap lua chon: ";
        cin >> choice;cin.ignore();
        if (choice == 1 || choice == 2) {
            switch (choice) {
                case 1:
                {
                    cout << "┌──────────────────────────────────────────────────────────┐\n";
                    cout << "│               DANG NHAP VOI TU CACH ADMIN                │\n";
                    cout << "└──────────────────────────────────────────────────────────┘\n";
                    cout << "Nhap mat khau: ";
                    string mk; int t = 1;
                    Menu.Read_Pass_Admin();
                    while(t < 6) {
                        getline(cin, mk);
                        if (mk != Menu.returnPass()) {
                            cout << "Sai mat khau\nNhap lai mat khau: ";
                            t++;
                        } else {
                            clearScreen();
                            cout << "Dang nhap thanh cong!\n";

                            if (List.ReadFile_Data() && List.ReadFile_Bin()) {
                                cout << "Da doc du lieu thanh cong!\n";
                                Menu.Menu_Admin();
                            } else {
                                cout << "Loi khi doc du lieu";
                                return 0;
                            }
                            break; // Thoát khỏi vòng lặp khi nhập đúng
                        }
                    }
                    if (t >= 6) {
                        cout << "Sai mat khau qua so lan cho phep!\nHay quay lai sau!....\n\n";
                        return 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "┌──────────────────────────────────────────────────────────┐\n";
                    cout << "│             DANG NHAP VOI TU CACH SINH VIEN              │\n";
                    cout << "└──────────────────────────────────────────────────────────┘\n";
                    if (List.ReadFile_Bin() && List.ReadFile_Data()) {
                        cout << "Da doc du lieu thanh cong!\n";
                    }
                    else {
                        cout << "Loi khi doc du lieu!\n";
                    }
                    cout << "Nhap ID sinh vien: ";
                    int id; cin >> id;;cin.ignore();
                    if (List.Login(id) == 1) {
                        clearScreen();
                        cout << "Dang nhap thanh cong!\n";
                        Menu.Menu_Std(id);
                    }
                    else if (List.Login(id) == 0) {
                        cout << "Sai mat khau qua so lan cho phep!\nHay quay lai sau!....\n\n";
                    }
                    else if (List.Login(id) == -1) {
                        cout << "ID khong ton tai!\n";
                    }
                    break;
                }
            }
        }
    }while(choice != 0);
    return 0;
}
