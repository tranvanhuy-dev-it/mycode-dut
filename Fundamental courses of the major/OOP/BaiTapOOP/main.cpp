#include <iostream>
#include "LopSinhHoat.h"
#include "SinhVien.h"
#include "Lecturer.h"
#include "lib.h"

using namespace std;

int main()
{
    LopSinhHoat **List_Cls = nullptr;
    int Count_Cls = 0;
    int choice;

    do
    {
        cout << "\n===== MENU QUAN LY LOP HOC =====\n";
        cout << "1. Them lop hoc moi\n";
        cout << "2. Them sinh vien vao lop\n";
        cout << "3. Hien thi danh sach sinh vien\n";
        cout << "4. Cap nhat diem cho sinh vien\n";
        cout << "5. Tim sinh vien theo MSSV\n";
        cout << "6. Sua thong tin sinh vien\n";
        cout << "7. Sua thong tin GVCN\n";
        cout << "8. Xoa lop hoc\n";
        cout << "9. Xoa sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "\n=====THEM LOP HOC MOI====\n\n";
            char name[100];
            cout << "Nhap ten lop hoc moi: ";
            cin.getline(name, 100);

            cout << "Nhap thong tin giao vien chu nhiem:\n";
            Lecturer gvcn;
            cin >> gvcn;

            LopSinhHoat *newcls = new LopSinhHoat(name, &gvcn);

            LopSinhHoat **temp = new LopSinhHoat *[Count_Cls + 1];
            for (int i = 0; i < Count_Cls; i++)
                temp[i] = List_Cls[i];

            temp[Count_Cls] = newcls;

            delete[] List_Cls;
            List_Cls = temp;
            Count_Cls++;

            cout << "Da them lop hoc moi: " << newcls->get_name() << endl;
            cout << *(newcls);
            break;
        }
        case 2:
        {
            cout << "\n====THEM SINH VIEN VAO LOP HOC====\n\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->addStudent();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 3:
        {
            cout << "\n====HIEN THI DANH SACH SINH VIEN====\n\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                cout << *(List_Cls[stt - 1]);
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 4:
        {
            cout << "\n====CAP NHAT DIEM SO====\n\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->update_gpa();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 5:
        {
            cout << "\n====TIM SINH VIEN THEO MSSV====\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->searchStudent();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 6:
        {
            cout << "\n====SUA THONG TIN SINH VIEN====\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->editStudent();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 7:
        {
            cout << "\n====SUA THONG TIN GVCN====\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->editLecturer();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 8:
        {
            cout << "\n====XOA LOP HOC====\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                int idx = stt - 1;
                delete List_Cls[idx];

                LopSinhHoat **temp = nullptr;

                if (Count_Cls - 1 > 0)
                {
                    temp = new LopSinhHoat *[Count_Cls - 1];
                    int j = 0;
                    for (int i = 0; i < Count_Cls; i++)
                    {
                        if (i != idx)
                        {
                            temp[j++] = List_Cls[i];
                        }
                    }
                }
                delete[] List_Cls;
                List_Cls = temp;
                Count_Cls--;
                cout << "Da xoa lop hoc thanh cong!\n";
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 9:
        {
            cout << "\n====XOA SINH VIEN====\n";
            cout << "Danh sach cac lop:\n";
            for (int i = 0; i < Count_Cls; i++)
            {
                cout << i + 1 << ": " << List_Cls[i]->get_name() << endl;
            }
            cout << endl;

            int stt;
            cout << "Chon lop hoc: ";
            cin >> stt;

            if (stt > 0 && stt <= Count_Cls)
            {
                List_Cls[stt - 1]->delStudent();
            }
            else
                cout << "Lop hoc khong hop le!\n";

            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }

    } while (choice != 0);

    for (int i = 0; i < Count_Cls; i++)
        delete List_Cls[i];
    delete[] List_Cls;

    return 0;
}

// g++ *.cpp -o main.exe
// g++ *.cpp -o main
