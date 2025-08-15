#include<bits/stdc++.h>

using namespace std;

class staff{
private:
    static int cnt;                 //dem id nhan vien
    static long long basic_salary;  //luong co ban
    string id;                      //ma so nhan vien
    string name;                    //ten
    string cccd;                    //so cccd
    string birth;                   //ngay sinh
    string gender;                  //gioi tinh
    string address;                 //dia chi
    string phone;                   //sdt
    string email;                   //email
    string education;               //hoc van
    string department;              //phong ban
    string position;                //chuc vu
    double salary_coeff;            //he so luong
    double salary;                  //luong
    double bonus;                   //thuong
    int work_time;                  //so ngay lam viec
    string status;                  //trang thai cong viet
public:
    staff();
    staff(string, string, string, string, string, string, string, string, string, string, string, double, double, double, int, string);
    string save_to_csv() const;
    void first_table();
    void show_full() const;
    void show_short() const;
    static void set_cnt(int value);
    int get_cnt();
    void read_basic_salary();
    void write_basic_salary();
    long long get_basic_salary() const;
    double get_salary_coeff() const;
    int get_work_time() const;

    static void sset_basic_salary(long long value) {
        basic_salary = value;
    }

    static int next_id() {
        return ++cnt;
    }

    friend class company;
    
    
};
int staff::cnt = 1000;
long long staff::basic_salary = 0;

staff::staff() {
    cnt++;
    id = to_string(get_cnt());
}

staff::staff(string _id, string _name, string _cccd, string _birth, string _gender, string _address, string _phone, string _email, string _education, string _department, string _position, double _salary_coeff, double _salary, double _bonus, int _work_time, string _status) {
    id = _id;
    name = _name;
    cccd = _cccd;
    birth = _birth;
    gender = _gender;
    address = _address;
    phone = _phone;
    email = _email;
    education = _education;
    department = _department;
    position = _position;
    salary_coeff = _salary_coeff;
    salary = _salary;
    bonus = _bonus;
    work_time = _work_time;
    status = _status;
}

string staff::save_to_csv() const {
    stringstream ss;
    ss << id 
    << "," << name 
    << "," << cccd 
    << "," << birth 
    << "," << gender 
    << "," << address 
    << "," << phone 
    << "," << email 
    << "," << education 
    << "," << department 
    << "," << position 
    << "," << fixed << setprecision(2) << salary_coeff 
    << "," << fixed << setprecision(0) << salary
    << "," << fixed << setprecision(0) << bonus
    << "," << work_time
    << "," << status 
    << "\n";
    return ss.str();
}

string center(const string& s, int width) {
    int len = s.length();
    if (width <= len) return s;
    int left = (width - len) / 2;
    int right = width - len - left;
    return string(left, ' ') + s + string(right, ' ');
}

string format_double(double value, int width, int precision = 1) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << value;
    return center(oss.str(), width);
}



void staff::show_full() const {
    cout << "│" << center(id, 5)
         << "│" << center(name, 20)
         << "│" << center(cccd, 11)
         << "│" << center(birth, 10)
         << "│" << center(gender, 9)
         << "│" << center(address, 20)
         << "│" << center(phone, 13)
         << "│" << center(email, 25)
         << "│" << center(education, 10)
         << "│" << center(department, 20)
         << "│" << center(position, 20)
         << "│" << format_double(salary_coeff, 12, 1) // In 1 chữ số thập phân
         << "│" << format_double(salary, 12, 0)       // In số nguyên
         << "│" << format_double(bonus, 7, 0)
         << "│" << center(to_string(work_time), 6)
         << "│" << center(status, 10)
         << "│\n";
         for (int i = 0; i <= 231; i++) {
            cout << "-";
         }
         cout << "\n";
}


void staff::show_short() const {
    cout << "│" << center(id, 5)
         << "│" << center(name, 20)
         << "│" << center(phone, 13)
         << "│" << center(email, 25)
         << "│" << center(department, 20)
         << "│" << center(position, 20)
         << "│" << center(to_string(salary_coeff), 12)
         << "│" << center(to_string(salary), 12)
         << "│" << center(to_string(bonus), 7)
         << "│" << center(to_string(work_time), 5)
         << "│" << center(status, 10)
         << "\n";
}

void staff::set_cnt(int value) {
    cnt = value;
}

int staff::get_cnt() {
    return cnt;
}

void staff::read_basic_salary() {
    ifstream fin("basic_salary.csv", ios::in);
    if (!fin.is_open()) {
        cout << "Loi khi mo file!\n";
        return;
    }
    fin >> basic_salary;
    fin.close();
}

void staff::write_basic_salary() {
    ofstream fout("basic_salary.csv", ios::out);
    if (!fout.is_open()) {
        cout << "Loi khi mo file!\n";
        return;
    }
    fout << basic_salary;
    fout.close();
}

long long staff::get_basic_salary() const {
    return basic_salary;
}

double staff::get_salary_coeff() const {
    return salary_coeff;
}

int  staff::get_work_time() const {
    return work_time;
}

class company{
private:
    list<staff> staffs;
public:
    void add_staff(const staff& s);
    int read_file_data();
    int write_file_data();
    void input_new_staff();
    void read_b_salary();
    void set_b_salary(long long value);
    void first_table();
    void display_staffs();
    void search_staff_id(string id);
    void search_staff_name(string name);
    void search_staff_department(string department);
    void search_staff_cccd(string cccd);
    void print_staff();
    void edit_salary_coeff(string id, double new_coeff);
    void edit_work_time(string id, int new_work_time);
    void diem_danh(string id);
};

void company::add_staff(const staff&s) {
    staffs.push_back(s);
}

int company::read_file_data() {
    ifstream fin("staff_data.csv");

    if (!fin.is_open()) {
        return 0;
    }

    string line;
    int maxID = 0;

    while (getline(fin, line)) {
        stringstream ss(line);

        string id, name, cccd, birth, gender, address, phone, email, education, department, position, status;
        string token;
        double salary_coeff, salary, bonus;
        int work_time;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, cccd, ',');
        getline(ss, birth, ',');
        getline(ss, gender, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, education, ',');
        getline(ss, department, ',');
        getline(ss, position, ',');
        getline(ss, token, ','); salary_coeff = stod(token);
        getline(ss, token, ','); salary = stod(token);
        getline(ss, token, ','); bonus = stod(token);
        getline(ss, token, ','); work_time = stoi(token);
        getline(ss, status, ',');

        if (stoi(id) > maxID) {
            maxID = stoi(id);
        }

        staff new_staff(id, name, cccd, birth, gender, address, phone, email, education, department, position, salary_coeff, salary, bonus, work_time, status);
        add_staff(new_staff);
    }
    staff::set_cnt(maxID);
    fin.close();
    return 1;
}

int company::write_file_data() {
    ofstream fout("staff_data.csv");

    if (!fout) {
        return 0;
    }

    for (const auto& s : staffs) {
        fout << s.save_to_csv();
    }
}

string make_email(const string& name) {
    stringstream ss(name);
    vector<string> parts;
    string word;
    while (ss >> word) {
        parts.push_back(word);
    }
    string email;
    // Lấy chữ cái đầu của các từ trừ từ cuối
    for (size_t i = 0; i + 1 < parts.size(); ++i) {
        email += tolower(parts[i][0]);
    }
    // Thêm từ cuối (viết thường)
    if (!parts.empty()) {
        for (char c : parts.back()) {
            email += tolower(c);
        }
    }
    email += "@company.com";
    return email;
}

void company::input_new_staff() {
    string id, name, cccd, birth, gender, address, phone, email, education, department, position, status;
    double salary_coeff, salary, bonus;
    int work_time;

    cout << "Nhap ten nhan vien: "; getline(cin, name);
    cout << "Nhap so can cuoc cong dan: "; getline(cin, cccd);
    cout << "Nhap ngay sinh: "; getline(cin, birth);
    cout << "Nhap gioi tinh: "; getline(cin, gender);
    cout << "Nhap dia chi: "; getline(cin, address);
    cout << "Nhap so dien thoai: "; getline(cin, phone);
    cout << "Nhap hoc van: "; getline(cin, education);

    cout << "\nChon phong ban:\n"; 
    cout << "1. Ban lanh dao\n";
    cout << "2. Phong nhan su\n";
    cout << "3. Phong ky thuat\n";
    cout << "4. Phong tai chinh-ke toan\n";
    cout << "5. Phong kinh doanh-marketing\n";
    int choice_1;
    cout << "Nhap lua chon: ";
    while (1) {
        cin >> choice_1;
        if (choice_1 >= 1 && choice_1 <= 5) {
            switch (choice_1) {
                case 1: department = "Ban lanh dao"; break;
                case 2: department = "Phong nhan su"; break;
                case 3: department = "Phong ky thuat"; break;
                case 4: department = "Phong tai chinh-ke toan"; break;
                case 5: department = "Phong kinh doanh-marketing"; break;
            }
            break;
        } else {
            cout << "Lua chon khong hop le, vui long nhap lai: ";
        }
    }

    cout << "\nChon chuc vu: \n";
    switch (choice_1) {
        case 1: {
            cout << "1. Giam doc\n";
            cout << "2. Pho giam doc\n";
            int choice_2;
            cout << "Nhap lua chon: ";
            while (1) {
                cin >> choice_2;
                if (choice_2 >= 1 && choice_2 <= 2) {
                    switch (choice_2) {
                        case 1: position = "Giam doc"; break;
                        case 2: position = "Pho giam doc"; break;
                    }
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, vui long nhap lai: ";
                }
            }
            break;
        }

        case 2: {
            cout << "1. Truong phong\n";
            cout << "2. Pho phong\n";
            cout << "3. Nhan vien\n";
            int choice_2;
            cout << "Nhap lua chon: ";
            while (1) {
                cin >> choice_2;
                if (choice_2 >= 1 && choice_2 <= 2) {
                    switch (choice_2) {
                        case 1: position = "Truong phong"; break;
                        case 2: position = "Pho phong"; break;
                        case 3: position = "Nhan vien"; break;
                    }
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, vui long nhap lai: ";
                }
            }
            break;
        }

        case 3: {
            cout << "1. Truong phong\n";
            cout << "2. Pho phong\n";
            cout << "3. Fresher\n";
            cout << "4. Junior Developer";
            cout << "5. Middle Developer";
            cout << "6. Senior Developer";
            cout << "7. Lead Developer";
            cout << "8. Principal Engineer";
            cout << "9. Manager";
            int choice_2;
            cout << "Nhap lua chon: ";
            while (1) {
                cin >> choice_2;
                if (choice_2 >= 1 && choice_2 <= 2) {
                    switch (choice_2) {
                        case 1: position = "Truong phong"; break;
                        case 2: position = "Pho phong"; break;
                        case 3: position = "Fresher"; break;
                        case 4: position = "Junior Developer"; break;
                        case 5: position = "Middle Developer"; break;
                        case 6: position = "Senior Developer"; break;
                        case 7: position = "Lead Developer"; break;
                        case 8: position = "Principal Engineer"; break;
                        case 9: position = "Manager"; break;
                    }
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, vui long nhap lai: ";
                }
            }
            break;
        }

        case 4: {
            cout << "1. Truong phong\n";
            cout << "2. Pho phong tai chinh\n";
            cout << "3. Pho phong ke toan\n";
            cout << "4. Chuyen vien tai chinh";
            cout << "5. Ke toan tong hop";
            cout << "6. Kiem soat vien";
            int choice_2;
            cout << "Nhap lua chon: ";
            while (1) {
                cin >> choice_2;
                if (choice_2 >= 1 && choice_2 <= 2) {
                    switch (choice_2) {
                        case 1: position = "Truong phong"; break;
                        case 2: position = "Pho phong tai chinh"; break;
                        case 3: position = "Pho phong ke toan"; break;
                        case 4: position = "Chuyen vien tai chinh"; break;
                        case 5: position = "Ke toan tong hop"; break;
                        case 6: position = "Kiem soat vien"; break;
                    }
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, vui long nhap lai: ";
                }
            }
            break;
        }

        case 5: {
            cout << "1. Truong phong\n";
            cout << "2. Pho phong kinh doanh\n";
            cout << "3. Pho phong marketing\n";
            cout << "4. Quan li khach hang";
            cout << "5. Nhan vien kinh doanh";
            cout << "6. Digital Marketing";
            int choice_2;
            cout << "Nhap lua chon: ";
            while (1) {
                cin >> choice_2;
                if (choice_2 >= 1 && choice_2 <= 2) {
                    switch (choice_2) {
                        case 1: position = "Truong phong"; break;
                        case 2: position = "Pho phong kinh doanh"; break;
                        case 3: position = "Pho phong marketing"; break;
                        case 4: position = "Quan li khach hang"; break;
                        case 5: position = "Nhan vien kinh doanh"; break;
                        case 6: position = "Digital Marketing"; break;
                    }
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, vui long nhap lai: ";
                }
            }
            break;
        }

    }

    salary_coeff = 2.1;
    status = "Dang lam viec";
    id = to_string(staff::next_id());
    work_time = 0;
    bonus = 0;
    salary = salary_coeff * staff::basic_salary / 28 * work_time + bonus;

    email = make_email(name);

    staff new_staff(id, name, cccd, birth, gender, address, phone, email, education, department, position, salary_coeff, salary, bonus, work_time, status);
    add_staff(new_staff);
    cout << "Da them nhan vien thanh cong...\n";
}

void company::read_b_salary() {
    staff s;
    s.read_basic_salary();
}

void company::set_b_salary(long long value) {
    staff::sset_basic_salary(value);
}

void company::first_table() {
    for (int i = 0; i <= 231; i++) {
            cout << "-";
         }
         cout << "\n";
    cout << "│" << center("Ma so", 5)
         << "│" << center("Ho ten", 20)
         << "│" << center("CCCD", 12)
         << "│" << center("Ngay sinh", 10)
         << "│" << center("Gioi tinh", 9)
         << "│" << center("Dia chi", 20)
         << "│" << center("Dien thoai", 13)
         << "│" << center("Email", 25)
         << "│" << center("Hoc van", 10)
         << "│" << center("Phong ban", 20)
         << "│" << center("Chuc vu", 20)
         << "│" << center("He so luong", 12)
         << "|" << center("Tong luong", 12)
         << "│" << center("Thuong", 7)
         << "│" << center("NLVc", 6)
         << "│" << center("Trang thai", 13)
         << "│\n";
    for (int i = 0; i < 231; i++) {
        cout << "-";
    }
    cout << "\n";
}

void company::display_staffs() {
    for (const auto& s : staffs) {
        s.show_full();
    }
}

void company::search_staff_id(string id) {
    for (const auto& s : staffs) {
        if (s.id == id) {
            first_table();
            s.show_full();
            return;
        }
    }
     cout << "Khong tim thay nhan vien voi ma so: " << id << "\n";
}

void company::search_staff_name(string name) {
    bool check = false;
    for (const auto& s : staffs) {
        if (s.name == name) {
            if (check == false) {
                first_table();
                check = true;
            }
            s.show_full();
        }
    }
    if (check == false) {
        cout << "Khong tim thay nhan vien co ten: " << name << "\n"; 
    }
}

void company::search_staff_department(string department) {
    bool check = false;
    for (const auto& s : staffs) {
        if (s.department == department) {
            if (check == false) {
                first_table();
                check = true;
            }
            s.show_full();
        }
    }
    if (check == false) {
        cout << "Khong tim thay nhan vien thuoc phong ban: " << department << "\n"; 
    }
}

void company::search_staff_cccd(string cccd) {
    for (const auto& s : staffs) {
        if (s.cccd == cccd) {
            first_table();
            s.show_full();
            return;
        }
    }
     cout << "Khong tim thay nhan vien co CCCD: " << cccd << "\n";
}

void company::print_staff() {
    for (const auto& s : staffs) {
        s.show_short();

    }
}

void company::edit_salary_coeff(string id, double new_coeff) {
    for (auto& s : staffs) {
        if (s.id == id) {
            s.salary_coeff = new_coeff;
            s.salary = new_coeff * staff::basic_salary / 28 * s.work_time + s.bonus;
            write_file_data();
            cout << "Da cap nhat he so luong thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma so: " << id << "\n";
}

void company::edit_work_time(string id, int new_work_time) {
    for (auto& s : staffs) {
        if (s.id == id) {
            s.work_time = new_work_time;
            s.salary = s.salary_coeff * staff::basic_salary / 28 * new_work_time + s.bonus;
            write_file_data();
            cout << "Da cap nhat thoi gian lam viec thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma so: " << id << "\n";
}

void company::diem_danh(string id) {
    for (auto& s : staffs) {
        if (s.id == id) {
            s.work_time++;
            s.salary = s.salary_coeff * staff::basic_salary / 28 * s.work_time + s.bonus;
            write_file_data();
            cout << "Da diem danh thanh cong cho nhan vien co ma so: " << id << "\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma so: " << id << "\n";
}

class menu {
private:
    company com;
public:
    friend class staff;
    company& get_company() {return com;}
    void input_staff();  
    void search_staff();
    void set_basic_salary();
    void set_salary_coeff();
    void set_work_time();
    void main_menu();
    

};

void menu::input_staff() {
    cout << "THEM NHAN VIEN\n";
    cout << "1. Them nhan vien moi:\n";
    cout << "2. Them nhan vien tu file:\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "Nhap lua chon: ";
    int choice;
    while (1) {
        cin >> choice; cin.ignore();
        if (choice >= 1 && choice <= 2) {
            switch (choice) {
                case 1: {
                    com.input_new_staff();
                    com.write_file_data();
                    cout << "Da them nhan vien moi thanh cong!\n";
                    break;
                }

                case 2: {
                    cout << "He thong dang bao tri, chuc nang nay tam thoi khong kha dung!\n";
                    break;
                }
            }
            return;
        }
        else if (choice == 0) {
            cout << "Da quay ve menu chinh\n";
            return;
        } else {
            cout << "Lua chon khong hop le, vui long nhap lai: ";
        }
    }
}

void menu::search_staff() {
    cout << "TIM KIEM THONG TIN NHAN VIEN\n";
    cout << "1. Tim kiem nhan vien theo ma so\n";
    cout << "2. Tim kiem nhan vien theo ten\n";
    cout << "3. Tim kiem nhan vien theo phong ban\n";
    cout << "4. Tim kiem nhan vien theo CCCD\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "Nhap lua chon: ";
    int choice;
    while (1) {
        cin >> choice; cin.ignore();
        if (choice >= 1 && choice <= 4) {
            string key;
            switch (choice) {
                case 1: {
                    "Nhap ma so nhan vien can tim: ";
                    getline(cin, key);
                    com.search_staff_id(key);
                    break;
                }

                case 2: {
                    "Nhap ten nhan vien can tim: ";
                    getline(cin, key);
                    com.search_staff_name(key);
                    break;
                }

                case 3: {
                    "Nhap phong ban cua nhan vien can tim: ";
                    getline(cin, key);
                    com.search_staff_department(key);
                    break;
                }

                case 4: {
                    "Nhap ma so CCCD nhan vien can tim: ";
                    getline(cin, key);
                    com.search_staff_cccd(key);
                    break;
                }
            }
            return;
        }
        else if (choice == 0) {
            cout << "Da quay ve menu chinh\n";
            return;
        } else {
            cout <<"Lua chon khojng hop le, vui long nhap lai: ";
        }
    }
}

void menu::set_basic_salary() {
    cout << "CAP NHAT LUONG CO BAN\n";
    staff s;
    s.read_basic_salary();
    cout << "Luong co ban hien tai: " << s.get_basic_salary() << "\n";
    cout << "Nhap luong co ban moi: ";
    long long new_basic_salary;
    cin >> new_basic_salary;
    s.sset_basic_salary(new_basic_salary);
    s.write_basic_salary();
    cout << "Da cap nhap luong co ban thanh cong!\n";
}

void menu::set_salary_coeff() {
    cout << "CAP NHAT HE SO LUONG\n";
    cout << "Nhap ma so nhan vien can cap nhat: ";
    string id;
    cin >> id; cin.ignore();
    cout << "Nhap he so luong moi: ";
    double new_coeff;
    cin >> new_coeff; cin.ignore();
    com.edit_salary_coeff(id, new_coeff);
    com.write_file_data();
}

void menu::set_work_time() {
    cout << "DIEM DANH DAU NGAY\n";
    cout << "Nhap ma so nhan vien: ";
    string id;
    cin >> id; cin.ignore();
    com.diem_danh(id);
    com.write_file_data();
}

void menu::main_menu() {
    int choice;
    do {
        cout << "HE THONG QUAN LI NHAN VIEN\n";
        cout << "1. Them nhan vien moi\n";
        cout << "2. Tim kiem thong tin nhan vien\n";
        cout << "3. Cap nhat luong co ban\n";
        cout << "4. Cap nhat he so luong cho nhan vien\n";
        cout << "5. Quan li cham cong\n";
        cout << "6. Quan li nghi phep\n";
        cout << "7. Quan li thuong\n";
        cout << "8. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        if (choice >= 1 && choice <= 7) {
            switch (choice) {
                case 1: {
                    input_staff();
                    break;
                }

                case 2: {
                    search_staff();
                    break;
                }

                case 3: {
                    set_salary_coeff();
                    break;
                }

                case 4: {
                    set_salary_coeff();
                    break;
                }

                case 5: {
                    set_work_time();
                    break;
                }

                case 6: {
                    cout << "He thong dang hoan thien, vui long quay lai sau!\n";
                    break;
                }

                case 7: {
                    cout << "He thong dang hoan thien, vui long quay lai sau!\n";
                    break;
                }
            }
        } 
    } while (choice != 0);
}

int main() {

    system("chcp 65001 > nul");
    menu menu;
    menu.get_company().read_b_salary();
    menu.main_menu();
    return 0;
}