#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define True 1
#define False 0
#define Y "\033[38;5;178m"
#define P "\033[38;5;146m"
#define STT        Y "STT " P
#define MASO       Y "MA SO SACH" P
#define TEN        Y "TEN SACH                      " P
#define TACGIA     Y "TAC GIA                       " P
#define NXB        Y "NHA XUAT BAN             " P
#define NAMXB      Y "NAM XUAT BAN   " P
#define TONG       Y "TONG SO   " P
#define CONLAI     Y "CON LAI   " P
#define DAMUON     Y "DA MUON   " P
#define TRANGTHAI  Y "TRANG THAI" P

typedef struct Book{
    char name[100], author[100], publisher[100], status[100];
    int ID, year, total, remains, borrowed;
} Book;

typedef struct BookNode{
    struct BookNode* Next;
    Book Data;
} BookNode;
BookNode *head = NULL;
BookNode *bin = NULL;

void FirstPage();//hang dau danh sach
int find(int ID);//xac dinh ma so sach da co trong thu vien chua
void PrintBook(Book book, int stt);//in thong tin sach
//Doc luu file
void Insert(BookNode** head ,Book data);//them sach vao danh sach
void ReadFile(char FileName[], BookNode **list);//doc du lieu tu file
void saveFile();//xuat du lieu vao file
void SaveData(char filedata[], BookNode** list);//luu du lieu vao file data
//Them sach
void InsertFirst(Book book);//chen vao dau danh sach
void InsertLast(Book book);//chen vao cuoi danh sach
void InsertAfter(Book book, int ID);//chen vao sau cuon sach bat ky
//Tim kiem
void DelSpace(char *str); //Xoa khoang trong sau chuoi
void SearchBook(int t, void *value);//tim sach
//Xem sach
void DisplayBook();//in toan bo sach
void Borrowed();//in sach da muon het
void NotBorrowed();//in sach chua muon het
void SortBy(int t);//in sach theo thu tu
void NewYear();//in sach xuat ban gan nhat
//Muon/tra sach
void BorrowBook(int ID);//muon sach
void ReturnBook(int ID);//tra sach
//Chinh sua noi dung sach
void EditBook(int t, int ID);//chinh sua thong tin
void EditAll(int ID);//chinh sua toan bo thong tin
//Xoa sach
void DeleteBy(int i, void *value);//xoa sach 
void DeleteFirst();//xoa sach o dau
void DeleteEnd();//xoa sach o cuoi
void DeleteAfter(int ID);//xoa sach sau cuon sach bat ky
void FreeList(BookNode **list);//giai phong dung luong cho list
//thung rac
int DisplayBookInBin();//in sach trong thung rac
void Restore(BookNode** head);//Phuc hoi sach
void RestoreBook(int ID);//khoi phuc sach
void Empty_Bin();
//function_menu
void create_read(); //nhap du lieu tu file
void insert(); //them sach vao thu vien
void del(); //xoa sach khoi thu vien
void search(); //tim liem sach
void read(); //xem sach
void borrow_return(); //muon va tra sach
void edit(); //chinh sua thong tin sach
void Bin();//thung rac
//Menu
void Menu();

int main() {
    system("chcp 65001 > nul");
    printf("\n\033[38;5;146m┌────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                    \033[31mPBL1 - DU AN LAP TRINH TINH TOAN\033[38;5;146m                    │\n");
    printf("├────────────────────────────────────────────────────────────────────────┤\n");
    printf("│ DE TAI: XAY DUNG CHUONG TRINH QUAN LY SACH TRONG THU VIEN.             │\n");
    printf("│ GIANG VIEN HUONG DAN: TS.NGUYEN VAN HIEU                               │\n");
    printf("│ SINH VIEN THUC HIEN:                                                   │\n");
    printf("│ HO TEN: TRAN MINH PHI      MSSV: 102240269                             │\n");
    printf("│ HO TEN: TRAN VAN HUY       MSSV: 102240251                             │\n");
    printf("│ LOP SINH HOAT: 24T_KHDL                                                │\n");
    printf("│ LOP HOC PHAN: 24.Nh15A                                                 │\n");
    printf("└────────────────────────────────────────────────────────────────────────┘\033[0m\n");
    char filedata[100] = "data.txt";
    ReadFile(filedata, &head);
    Menu();
    return 0;
}

void FirstPage() {
    printf("\033[38;5;146m┌══════┬════════════┬════════════════════════════════┬═══════════════\
═════════════════┬═══════════════════════════┬═════════════════┬════════════┬════════════┬════════════┬════════════┐\n");
    printf("│ %-4s │ %-10s │ %-30s │ %-30s │ %-25s │ %-15s │ %-10s │ %-10s │ %-10s │ %-10s │\n", 
    STT, MASO, TEN, TACGIA, NXB, NAMXB, TONG, CONLAI, DAMUON , TRANGTHAI);
    printf("├══════┼════════════┼════════════════════════════════┼═══════════════\
═════════════════┼═══════════════════════════┼═════════════════┼════════════┼════════════┼════════════┼════════════┤\n");
}


//in thong tin cua sach
void PrintBook(Book book, int stt) {
    if(strcmp(book.status, "FALSE") == 0) {
        printf("│ %-4d │ %-10d │ %-30s │ %-30s │ %-25s │ %-15d │ %-10d │ %-10d │ %-10d │ \033[1;31m%-10s\033[38;5;146m │\n",
        stt, book.ID, book.name, book.author, book.publisher, book.year, book.total, book.remains, book.borrowed, book.status);
    } else { 
        printf("│ %-4d │ %-10d │ %-30s │ %-30s │ %-25s │ %-15d │ %-10d │ %-10d │ %-10d │ \033[1;32m%-10s\033[38;5;146m │\n",
        stt, book.ID, book.name, book.author, book.publisher, book.year, book.total, book.remains, book.borrowed, book.status);
    }
    printf("├──────┼────────────┼────────────────────────────────┼─────────────────\
───────────────┼───────────────────────────┼─────────────────┼────────────┼────────────┼────────────┼────────────┤\n");
}

//dung trong them sach de xac dinh ID co bi trung hay khong
int find(int ID) {
    BookNode *temp = head;
    while (temp != NULL) {
        if (temp->Data.ID == ID) {
            return False;
        }
        temp = temp->Next;
    }
    return True;
}

//Doc luu file
void Insert(BookNode** head ,Book data) {
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    newNode->Data = data;
    newNode->Next = NULL;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    BookNode *temp = *head;
    while(temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void ReadFile(char FileName[], BookNode **list) {
    FILE* file = fopen(FileName, "r");//mo file
    if(file == NULL) {
        printf("\033[31mKhong the doc du lieu!\033[0m\n");
        return;
    }
    Book book;
    while(fscanf(file, "%d\n", &book.ID) != EOF) {
        fgets(book.name, sizeof(book.name), file); 
        strtok(book.name, "\n");//xoa ky tu xuong dong
        fgets(book.author, sizeof(book.author), file); 
        strtok(book.author, "\n");
        fgets(book.publisher, sizeof(book.publisher), file); 
        strtok(book.publisher, "\n");
        fscanf(file, "%d\n", &book.year);
        fscanf(file, "%d\n", &book.total);
        fscanf(file, "%d\n", &book.remains);
        fscanf(file, "%d\n", &book.borrowed);
        if (book.remains == 0) strcpy(book.status, "FALSE"); 
        else strcpy(book.status, "TRUE");
        Insert(list, book);
    }
    printf("\033[1;32mDa doc du lieu thanh cong!\033[0m \n");
    fclose(file);
}

void saveFile() {
    char fileName[100];
    printf("\033[38;5;146mNhap ten file de luu danh muc sach: \033[00m");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\033[31mError\033[0m\n");
        return;
    }
    fprintf(file, "┌══════┬════════════┬════════════════════════════════┬═══════════════\
═════════════════┬═══════════════════════════┬═════════════════┬════════════┬════════════┬════════════┬════════════┐\n");
    fprintf(file, "│ %-4s │ %-10s │ %-30s │ %-30s │ %-25s │ %-15s │ %-10s │ %-10s │ %-10s │ %-10s │\n",
         "STT", "MA SO SACH", "TEN SACH", "TAC GIA", "NHA XB", "NAM XB", "TONG SO", "CON LAI", "DA MUON", "TRANG THAI");  
    fprintf(file, "├══════┼════════════┼════════════════════════════════┼═══════════════\
═════════════════┼═══════════════════════════┼═════════════════┼════════════┼════════════┼════════════┼════════════┤\n");
    BookNode *temp = head;
    int stt = 1;
    while (temp != NULL) {
        fprintf(file, "│ %-4d │ %-10d │ %-30s │ %-30s │ %-25s │ %-15d │ %-10d │ %-10d │ %-10d │ %-10s │\n", 
            stt,
            temp->Data.ID, 
            temp->Data.name, 
            temp->Data.author, 
            temp->Data.publisher,
            temp->Data.year,
            temp->Data.total,
            temp->Data.remains,
            temp->Data.borrowed,
            temp->Data.status);
        fprintf(file, "├──────┼────────────┼────────────────────────────────┼─────────────────\
───────────────┼───────────────────────────┼─────────────────┼────────────┼────────────┼────────────┼────────────┤\n");
        stt++;
        temp = temp->Next;
    }
    fclose(file);
    printf("\033[1;32mDa luu danh muc sach vao file thanh cong!\033[00m\n");
}

void SaveData(char filedata[100], BookNode** list) { //luu du lieu vao file
    FILE *file = fopen(filedata, "w");
    BookNode *temp = *list;
    while (temp != NULL) {
        fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n", 
            temp->Data.ID, 
            temp->Data.name, 
            temp->Data.author, 
            temp->Data.publisher,
            temp->Data.year,
            temp->Data.total,
            temp->Data.remains,
            temp->Data.borrowed);
            temp = temp->Next;
    }
    fclose(file);
}

//Them sach
void InsertFirst(Book book) {
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    newNode->Data = book;
    newNode->Next = head;
    head = newNode;
    printf("\033[1;32mDa them sach thanh cong!\033[0\n");

}

void InsertLast(Book book) {
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    newNode->Data = book;
    newNode->Next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    } else{
        BookNode* temp = head;
        while(temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
    printf("\033[1;32mDa them sach thanh cong!\033[0m\n");
}

void InsertAfter(Book book, int ID) {
    BookNode *temp = head;
    while(temp != NULL && temp->Data.ID != ID) {
        temp = temp->Next;
    }
    if(temp == NULL) {
        printf("\033[31mError\033[0m\n"); return;
    }
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    newNode->Data = book;
    newNode->Next = temp->Next;
    temp->Next = newNode;
    printf("\033[1;32mDa them sach thanh cong!\033[0m\n");
}
//Tim kiem
void DelSpace(char *str) {
    int l = strlen(str);
    while (l > 0 && isspace((unsigned char)str[l - 1])) {
        l--;
    }
    str[l] = '\0';
}

void SearchBook(int t, void *value) {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    BookNode *temp = head;
    int found = 0, stt = 1;
    while (temp != NULL) {
        int match = 0;//dung de danh dau
        switch (t) {
            case 1:
                if (temp->Data.ID == *(int*)value)
                    match = 1;
                break;
            case 2:
                DelSpace(temp->Data.name);
                if (_stricmp(temp->Data.name, (char*)value) == 0)
                    match = 1;
                break;
            case 3:
                DelSpace(temp->Data.author);
                if (_stricmp(temp->Data.author, (char*)value) == 0)
                    match = 1;
                break;
            case 4:
                DelSpace(temp->Data.publisher);
                if (_stricmp(temp->Data.publisher, (char*)value) == 0)
                    match = 1;
                break;
        }

        if (match) {
            found = 1;//danh dau la da tim thay sach
            PrintBook(temp->Data, stt);
            stt++;
        }
        temp = temp->Next;
    }

    if (!found) {
        printf("\033[31mKhong tim thay sach!\033[0m\n");
    }
}
//Xem sach
void DisplayBook() {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    printf("\033[38;5;146mToan bo sach trong thu vien:\033[00m\n");
    FirstPage();
    int stt = 1, total_remains = 0, total_borrowed = 0, total_book = 0;
    BookNode *temp = head;
    while (temp != NULL) {

        if(strcmp(temp->Data.status, "FALSE") == 0) strcpy(temp->Data.status, "\033[1;31mFALSE\033[0m     ");
        else strcpy(temp->Data.status, "\033[1;32mTRUE\033[0m      ");
    
        printf("│ %-4d │ %-10d │ %-30s │ %-30s │ %-25s │ %-15d │ %-10d │ %-10d │ %-10d │ %-10s \033[38;5;146m│\n",
            stt, temp->Data.ID, temp->Data.name, temp->Data.author, temp->Data.publisher, temp->Data.year, temp->Data.total, temp->Data.remains, temp->Data.borrowed, temp->Data.status);
        if (temp->Next != NULL) {
            printf("├──────┼────────────┼────────────────────────────────┼─────────────────\
───────────────┼───────────────────────────┼─────────────────┼────────────┼────────────┼────────────┼────────────┤\n");
        } else {
            printf("└──────┴────────────┴────────────────────────────────┴─────────────────\
───────────────┴───────────────────────────┴─────────────────┴────────────┴────────────┴────────────┴────────────┘\n");
        }
        stt++;
        total_remains += temp->Data.remains;
        total_borrowed += temp->Data.borrowed;
        total_book += temp->Data.total;
        temp = temp->Next;
    }
    printf("\033[1;32mTong so sach: %d\n", total_book);
    printf("Tong so sach con lai: %d\n", total_remains);
    printf("Tong so sach da cho muon: %d\033[0m\n\n", total_borrowed);
}

void Borrowed() {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    BookNode *temp = head;
    int stt = 1, found = 0;
    while (temp != NULL) {
        if(strcmp(temp->Data.status, "FALSE") == 0) {
            found = 1;
            PrintBook(temp->Data, stt);
            stt++;
        }
        temp=temp->Next;
    }

    if(found == 0) printf("\033[31mTat ca sach deu chua duoc cho muon het!\033[0m\n");
}

void NotBorrowed() {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    } 
    BookNode *temp = head;
    int stt = 1, found = 0, total_book = 0;
    while (temp != NULL) {
        if(strcmp(temp->Data.status, "TRUE")==0) {
            found = 1;
            PrintBook(temp->Data, stt);
            total_book += temp->Data.remains;
            stt++;
        }
        temp=temp->Next;
    }

    if(found == 0) printf("\033[31mTat ca sach deu da duoc cho muon het!\033[0m\n");
    else printf("\033[38;5;146mTong so sach chua duoc cho muon: %d\n\033[00m", total_book);
}

void SortBy(int t) {
    if (head == NULL || head->Next == NULL) {
        DisplayBook();
        return;
    }
    BookNode *i, *j;
    Book temp;
    for (i = head; i != NULL; i = i->Next) {
        for (j = i->Next; j != NULL; j = j->Next) {
            int match = 0;
            switch (t) {
                case 1://theo ten sach
                    if (strcmp(i->Data.name, j->Data.name) > 0) match = 1;//danh dau la can hoan doi
                    break;
                case 2://theo tac gia
                    if (strcmp(i->Data.author, j->Data.author) > 0) match = 1;
                    break;
                case 3://theo nha xuat ban
                    if (strcmp(i->Data.publisher, j->Data.publisher) > 0) match = 1;
                    break;
                case 4://theo nam xuat ban
                    if (i->Data.year < j->Data.year) match = 1;
                    break;
            }
            if (match) {
                temp = i->Data;
                i->Data = j->Data;
                j->Data = temp;
            }
        }
    }
    DisplayBook();
}

void NewYear(){
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    //tim nam xuat ban moi nhat
    int MaxYear = 0;
    BookNode *temp = head;
    while(temp != NULL) {
        if (temp->Data.year > MaxYear) {
            MaxYear = temp->Data.year;
        }
        temp = temp->Next;
    }
    //in thong tin tat ca sach co nam xuat ban moi nhat
    int stt = 1;
    BookNode *temp2 = head;
    while(temp2 != NULL) {
        if (temp2->Data.year == MaxYear) {
            PrintBook(temp2->Data, stt);
            stt++;
        }
        temp2 = temp2->Next;
    }
}
//Muon/tra sach
void BorrowBook(int ID) {
    if (head == NULL){
        printf("\033[31mThu vien trong!\033[0m.\n");
        return;
    }
    int sl;
    BookNode *temp = head;
    while (temp != NULL) {
        if (temp->Data.ID == ID){
            if (temp->Data.remains <= 0) {//neu sach con co the muon duoc
                printf("\033[31mSach da duoc muon het!\033[0m\n");
                return;
            }

            while(1) {
                printf("\033[38;5;146mNhap vao so luong sach:\033[00m ");
                scanf("%d", &sl); getchar();//getchar() dung de xoa ky tu xuong dong do scanf de lai 
                if (temp->Data.remains - sl >= 0) {//sach con du so luong de muon
                    temp->Data.remains -= sl;
                    temp->Data.borrowed += sl;
                    if (temp->Data.remains == 0) strcpy(temp->Data.status, "FALSE");
                    printf("\033[1;32mSach da duoc muon thanh cong!\033[0m\n");
                    return;
                } else {//khong con du sach de muon
                    int lc;
                    printf("\033[31mSo luong sach khong du!\n\033[38;5;146mBan co muon thay doi so luong sach:\n");
                    printf("Nhap bat ky de dong y\nNhap 0 de bo qua\nLua chon:\033[00m ");
                    scanf("%d", &lc); getchar();
                    if (lc == 0) return;   
                }
            }
    }
    temp = temp->Next;
}
    printf("\033[31mKhong tim thay sach!\033[0m\n");

}

void ReturnBook(int ID) {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    int sl;
    BookNode *temp = head;
    while (temp != NULL) {
        if (temp->Data.ID == ID){
            printf("\033[38;5;146mNhap vao so luong sach muon tra:\033[00m ");

            while(1) {
                scanf("%d", &sl), getchar();
                if (sl > temp->Data.borrowed) {
                    printf("\033[38;5;146mSo luong nhieu hon so luong sach da muon!\n");
                    printf("Nhap lai so luog sach can tra: \033[00m");
                } else {
                    temp->Data.remains += sl;
                    temp->Data.borrowed -= sl;
                    strcpy(temp->Data.status, "TRUE");
                    printf("\033[1;32mSach da duoc tra thanh cong!\033[0m\n");
                    return;
                }
            }
        }
        temp = temp->Next;
    }
    printf("\033[31mKhong tim thay sach!\033[0m\n");
}
//Chinh sua thong tin sach
void EditBook(int t, int ID) {
    if (head == NULL){
        printf("\033[31mThu vien trong!\033[0m\n");
    }
    int found = 0;
    BookNode *temp = head;
    while (temp != NULL){
        if(temp->Data.ID == ID) {
            found = 1;//danh dau da tim thay sach
            switch (t) {
                case 1:
                    printf("\033[38;5;146mNhap ten sach moi: ");
                    fgets(temp->Data.name, sizeof(temp->Data.name), stdin); 
                    strtok(temp->Data.name, "\n");
                    printf("\033[1;32mDa thay doi ten sach thanh cong!\033[0m\n");
                    break;
                case 2:
                    printf("\033[38;5;146mNhap vao ten tac gia moi: ");
                    fgets(temp->Data.author, sizeof(temp->Data.author), stdin); 
                    strtok(temp->Data.author, "\n");
                    printf("\033[1;32mDa thay doi ten tac gia sach thanh cong!\033[0m\n");
                    break;
                case 3:
                    printf("\033[38;5;146mNhap vao ten nha xuat ban moi: ");
                    fgets(temp->Data.publisher, sizeof(temp->Data.publisher), stdin); 
                    strtok(temp->Data.publisher, "\n");
                    printf("\033[1;32mDa thay doi nha xuat ban thanh cong!\033[0m\n");
                    break;
                case 4:
                    printf("\033[38;5;146mNhap vao nam xuat ban moi: ");
                    scanf("%d", &temp->Data.year); getchar();
                    printf("\033[1;32mDa thay doi nam xuat ban thanh cong!\033[0m\n");
                    break;
            }
        }
        temp = temp->Next;
    }
    if (found == 0) printf("\033[31mKhong tim thay sach!\033[0m\n");
}

void EditAll(int ID) {
    if (head == NULL) {
        printf("\033[31mThu vien trong!\033[0m\n");
        return;
    }
    BookNode *temp = head;
    while (temp != NULL) {
        if(temp->Data.ID == ID){
            printf("\033[38;5;146mNhap ten sach moi: ");
            fgets(temp->Data.name, sizeof(temp->Data.name), stdin); strtok(temp->Data.name, "\n");
            printf("Nhap ten tac gia moi: ");
            fgets(temp->Data.author, sizeof(temp->Data.author), stdin); strtok(temp->Data.author, "\n");
            printf("Nhap nha xuat ban moi: ");
            fgets(temp->Data.publisher, sizeof(temp->Data.publisher), stdin); strtok(temp->Data.publisher, "\n");
            printf("Nhap nam xuat ban moi: ");
            scanf("%d", &temp->Data.year);
            printf("\033[1;32mDa thay doi thong tin sach thanh cong!\033[0m\n");
            return;
        }
        temp = temp->Next;
    }
    printf("\033[31mKhong tim thay sach!\033[0m\n");
}
//Xoa sach
void DeleteBy(int t, void *value) {
    if (head == NULL) {
        printf("\033[31mDanh sach rong!\033[0m\n");
        return;
    }

    char filebin[100] = "bin.txt";//file luu sach da xoa
    BookNode *temp = head, *prev = NULL;
    while (temp != NULL) {
        int match = 0;
        switch(t) {
            case 1:
                if (temp->Data.ID == *(int*)value) match = 1;//danh dau da tim thay sach
                break;
            case 2:
                DelSpace(temp->Data.name);
                if (_stricmp(temp->Data.name, (char*)value) == 0) match = 1;
                break;
            case 3:
                DelSpace(temp->Data.author);
                if (_stricmp(temp->Data.author, (char*)value) == 0) match = 1;
                break;
        }
        if (match) {
            printf("\033[38;5;146mBan chac chan muon xoa\n1. Chac chan\n0. Bo qua\nLua chon: \033[00m");
            int sl;
            scanf("%d", &sl);
            if (sl == 0) {
                printf("\033[38;5;146mDa bo qua!\033[00m\n");
                return;
            }
            else if (sl == 1) {
                FILE *file = fopen(filebin, "a");
                if (file != NULL) {
                    fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n", 
                    temp->Data.ID,
                    temp->Data.name,
                    temp->Data.author,
                    temp->Data.publisher,
                    temp->Data.year,
                    temp->Data.total,
                    temp->Data.remains,
                    temp->Data.borrowed);
                    fclose(file);
                }
                if (prev == NULL) head = temp->Next;
                else prev->Next = temp->Next;
                free(temp);
                printf("\033[1;32mDa chuyen sach vao thung rac!\033[0m\n");
                return;
            }
        }
        prev = temp;
        temp = temp->Next;
    }
    printf("\033[31mKhong tim thay sach!\033[0m\n");
}

void DeleteFirst() {
    if (head == NULL) {
        printf("\033[31mDanh sach rong!\033[0m\n");
        return;
    }
    
    char filebin[] = "bin.txt";
    BookNode *temp = head;
    printf("\033[38;5;146mBan chac chan muon xoa\n1. Chac chan\n0. Bo qua\nLua chon: \033[00m");
    int sl;
    while(1) {
        scanf("%d", &sl);
        if (sl == 0) {
            printf("\033[38;5;146mDa bo qua!\033[00m\n");
            return;
        }

        else if (sl == 1) {
            FILE *file = fopen(filebin, "a");
            if (file != NULL) {
                fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n", 
                    temp->Data.ID,
                    temp->Data.name,
                    temp->Data.author,
                    temp->Data.publisher,
                    temp->Data.year,
                    temp->Data.total,
                    temp->Data.remains,
                    temp->Data.borrowed);
                fclose(file);
            }
            head = head->Next;
            free(temp);
            printf("\033[1;32mDa chuyen sach vao thung rac!\033[0m\n");
            return;
        } else {
            printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
        } 
    }
}

void DeleteEnd() {
    if (head == NULL) {
        printf("\033[31mDanh sach rong!\033[0m\n");
        return;
    }
    int sl;
    printf("\033[38;5;146mBan chac chan muon xoa\n1. Chac chan\n0. Bo qua\nLua chon: \033[00m");
    while (1) {
        scanf("%d", &sl);
        if (sl == 1) {
            BookNode *temp = head, *prev = NULL;
            while (temp->Next != NULL) {
                prev  = temp;
                temp = temp->Next;
            }
            char filebin[] = "bin.txt";
            FILE *file = fopen(filebin, "a");
            if (file != NULL) {
                fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n", 
                    temp->Data.ID,
                    temp->Data.name,
                    temp->Data.author,
                    temp->Data.publisher,
                    temp->Data.year,
                    temp->Data.total,
                    temp->Data.remains,
                    temp->Data.borrowed);
                fclose(file);

                if (prev != NULL) {
                    prev->Next = NULL;
                } else {
                    head = NULL; 
                }
                free(temp);
            } else {
                printf("\033[31mLoi khi mo file!\033[0m\n");
                return;
            }
            printf("\033[1;32mDa chuyen sach vao thung rac!\033[0m\n");
            return;
        } 
        else if (sl == 0) {
            printf("\033[38;5;146mDa bo qua!\033[00m\n");
            return;
        } else {
            printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
        }
    }
}

void DeleteAfter(int ID) {
    if (head == NULL) {
        printf("\033[31mDanh sach trong!\033[0m\n");
        return;
    }

    printf("\033[38;5;146mBan chac chan muon xoa\n1. Chac chan\n0. Bo qua\nLua chon:\033[00m ");
    int sl;
    while(1) {
        scanf("%d", &sl);
        if (sl == 1) {
            BookNode *temp = head, *prev = NULL;
            while (temp != NULL && temp->Data.ID != ID) {
                prev = temp;
                temp = temp->Next;
            }
        
            if (temp == NULL || temp->Next == NULL) {
                printf("\033[31mKhong co sach dung sau sach co ID\033[0m %d\n", ID);
                return;
            }
            char filebin[] = "bin.txt";
            FILE *file = fopen(filebin, "a");
            if (file != NULL) {
                fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n", 
                temp->Data.ID,
                temp->Data.name,
                temp->Data.author,
                temp->Data.publisher,
                temp->Data.year,
                temp->Data.remains);
                fclose(file);
            }
            prev->Next = temp->Next;
            free(temp);
            printf("\033[1;32mDa chuyen sach vao thung rac!\033[0m\n");
            return;
        }
        else if (sl == 0) {
            printf("\033[38;5;146mDa bo qua!\033[00m\n");
            return;
        } else {
            printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
        }
    }
}

void FreeList(BookNode **list){
    BookNode *temp = *list;
    while(temp != NULL) {
        BookNode *next = temp->Next;
        free(temp);
        temp = next;
    }
    *list = NULL;
}

void RestoreBook(int ID) {
    char FileBin[] = "bin.txt";
    char FileData[] = "data.txt";
    //khoi phuc
    BookNode *temp = bin, *prev = NULL;
    while(temp != NULL) {
        if (temp->Data.ID == ID) {
            FILE *file = fopen(FileData, "a");
            if (file != NULL) {
                fprintf(file, "%d\n%s\n%s\n%s\n%d\n%d\n", 
                    temp->Data.ID, 
                    temp->Data.name, 
                    temp->Data.author, 
                    temp->Data.publisher,
                    temp->Data.year,
                    temp->Data.remains);
                    fclose(file);
            }
            //xoa sach trong list bin
            if (prev == NULL) bin = temp->Next;
            else prev->Next = temp->Next;
            temp->Next = head;//them sach vao head
            head = temp;
            SaveData(FileBin, &bin);
            printf("\033[1;32mDa khoi phuc sach thanh cong!\033[0m\n");
            FreeList(&bin);//giai phong dung luong cho list bin
            return;
        }
        prev = temp;
        temp = temp->Next;
    }
    printf("\033[31mKhong tim thay sach hop le!\033[0m\n");
    FreeList(&bin);
}

int DisplayBookInBin(BookNode *bin) {
    BookNode *temp = bin;
    if (temp == NULL) {
        printf("\033[31mThung rac trong!\033[0m\n");
        return 0;
    }
    printf("\033[38;5;146mToan bo sach trong thung rac:\033[00m\n");
    FirstPage();
    int stt = 1;
    while (temp != NULL) {     
        PrintBook(temp->Data, stt);
        stt++; 
        temp = temp->Next;
    }
    return 1;
}

void Empty_Bin(){
    printf("\033[38;5;146mBan chac chan muon lam sach thung rac.\n");
    printf("1. Chac chan\n0. Bo qua\nLua chon: \033[00m");
    int sl;
    scanf("%d", &sl);
    if (sl == 1) {
        char filebin[100] = "bin.txt";
        FILE *file = fopen(filebin, "w");
        if (file == NULL) {
            printf("\033[31mLoi khi mo thung rac!\033[0m\n");
            return;
        }
        fclose(file);
        printf("\033[1;32mDa lam sach thung rac thanh cong!\033[0m\n");
    } else {
        printf("\033[38;5;146mDa bo qua!\033[0m\n");
    }
}

void create_read() {
        char filename[100];
        printf("\033[38;5;146mNhap vao ten file:\033[0m "); fgets(filename, sizeof(filename), stdin); strtok(filename, "\n");
        ReadFile(filename, &head);
}

void insert(Book book) {
    int select2;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│            \033[38;5;178mTHEM MOT CUON SACH VAO THU VIEN\033[38;5;117m               │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Them vao dau danh muc sach.                           │\n");
    printf("│ 2. Them vao cuoi danh muc sach.                          │\n");
    printf("│ 3. Them vao sau cuon sach nao do.                        │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m "); 
    do{
        scanf("%d", &select2);
        if (select2 >= 0 && select2 <= 3) {
            switch(select2) {
                case 1:
                case 2:
                case 3:{
                    printf("\033[38;5;146mNhap thong tin cuon sach: \n");
                    int validID = 0;
                    while (!validID) {
                        printf("Nhap ID: ");
                        scanf("%d", &book.ID); getchar();

                        if (!find(book.ID)) {
                            printf("ID da ton tai, vui long nhap lai!\n");
                        } else {
                            validID = 1;
                        }
                    }
          
                    printf("Nhap ten sach: "); fgets(book.name, sizeof(book.name), stdin); strtok(book.name, "\n");
                    printf("Nhap ten tac gia: "); fgets(book.author, sizeof(book.author), stdin); strtok(book.author, "\n");
                    printf("Nhap nha xuat ban: "); fgets(book.publisher, sizeof(book.publisher), stdin); strtok(book.publisher, "\n");
                    printf("Nhap nam xuat ban: "); scanf("%d", &book.year); getchar();
                    printf("Nhap so luong sach:\033[0m "); scanf("%d", &book.total); getchar();
                    book.remains = book.total;
                    book.borrowed = 0;
                    if (book.total == 0) strcpy(book.status, "FALSE"); 
                    else strcpy(book.status, "TRUE");   
                            
                    if (select2 == 1) {
                        InsertFirst(book);
                    } 
                    else if (select2 == 2) {
                        InsertLast(book);
                    } 
                    else if (select2 == 3) {
                        int ID;
                        printf("\033[38;5;146mNhap vao ma so cuon sach muon chen sach vao sau:\033[0m "); 
                        scanf("%d", &ID); getchar();
                        InsertAfter(book, ID);
                    }
                    break;   
                }        
                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break; 
            }
            return;
        } else  printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
    }while(select2 != 0);
}

void del() {
    int select3;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│             \033[38;5;178mXOA MOT CUON SACH KHOI THU VIEN\033[38;5;117m              │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Xoa sach theo ma so.                                  │\n");
    printf("│ 2. Xoa sach theo ten.                                    │\n");
    printf("│ 3. Xoa sach cua tac gia.                                 │\n");
    printf("│ 4. Xoa cuon sach o dau danh sach.                        │\n");
    printf("│ 5. Xoa cuon sach o cuoi danh sach.                       │\n");
    printf("│ 6. Xoa cuon sach sau mot cuon sach nao do.               │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m ");  
    do{
        scanf("%d", &select3); getchar();
        if (select3 >= 0 && select3 <= 6) {
            switch (select3) {
                case 1: 
                    int ID;
                    printf("\033[38;5;146mNhap vao ma so sach can xoa:\033[0m ");
                    scanf("%d", &ID); getchar();
                    DeleteBy(1, &ID);
                    break;

                case 2:
                    char name[100];
                    printf("\033[38;5;146mNhap vao ten sach can xoa:\033[0m ");
                    fgets(name, sizeof(name), stdin); strtok(name, "\n");
                    DeleteBy(2, &name);
                    break;

                case 3:
                    char author[100];
                    printf("\033[38;5;146mNhap vao ten tac gia can xoa:\033[0m ");
                    fgets(author, sizeof(author), stdin); strtok(author, "\n");
                    DeleteBy(3, &author);
                    break;

                case 4:
                    DeleteFirst();
                    break;

                case 5:
                    DeleteEnd();
                    break;

                case 6:
                    int ID2;
                    printf("\033[38;5;146mNhap vao ma so sach can xoa phia sau:\033[0m ");
                    scanf("%d", &ID2); getchar();
                    DeleteAfter(ID2);
                    break;

                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break;
            }
            return;
        }else  printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
    }while(select3 != 0);
}

void search() {
    int select4;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│                    \033[38;5;178mTIM KIEM SACH\033[38;5;117m                         │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Tim kiem theo ma so.                                  │\n");
    printf("│ 2. Tim kiem theo ten sach.                               │\n");
    printf("│ 3. Tim kiem theo ten tac gia.                            │\n");
    printf("│ 4. Tim kiem theo ten nha xuat ban.                       │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m "); 
    do{
        scanf("%d", &select4); getchar();
        if (select4 >= 0 && select4 <= 4) {
            switch (select4) {
                case 1:
                    int id;
                    printf("\033[38;5;146mNhap vao ma so sach can tim:\033[0m ");
                    scanf("%d", &id);getchar();
                    FirstPage();
                    SearchBook(1, &id);
                    break;

                case 2:
                    char name[101];
                    printf("\033[38;5;146mNhap vao ten sach can tim:\033[0m ");
                    fgets(name, sizeof(name), stdin); strtok(name, "\n");
                    FirstPage();
                    SearchBook(2, &name);
                    break;

                case 3:
                    char author[101];
                    printf("\033[38;5;146mNhap vao ten tac gia can tim:\033[0m ");
                    fgets(author, sizeof(author), stdin); strtok(author, "\n");
                    FirstPage();
                    SearchBook(3, &author);
                    break;

                case 4:
                    char publisher[101];
                    printf("\033[38;5;146mNhap vao ten nha xuat ban can tim:\033[0m ");
                    fgets(publisher, sizeof(publisher), stdin); strtok(publisher, "\n");
                    FirstPage();
                    SearchBook(4, &publisher);
                    break;

                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break;
            }
            return;
        } else printf("\033[31mLua chon khong hop le, vui long nhap lai: \033[0m");
    }while(select4 != 0);
}

void read() {
    int select5;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│                   \033[38;5;178mCHUC NANG XEM SACH\033[38;5;117m                     │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Xem toan bo sach.                                     │\n");
    printf("│ 2. Xem sach da cho muon het.                             │\n");
    printf("│ 3. Xem sach chua cho muon het.                           │\n");
    printf("│ 4. Xem sach theo van alphabet cua ten sach.              │\n");
    printf("│ 5. Xem sach theo van alphabet cua ten tac gia.           │\n");
    printf("│ 6. Xem sach theo van alphabet cua ten nha xuat ban.      │\n");
    printf("│ 7. Xem sach theo thoi gian xuat ban (moi nhat - cu nhat).│\n");
    printf("│ 8. Xem sach duoc xuat ban gan day nhat.                  │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m ");  
    do{
        scanf("%d", &select5); getchar();
        if (select5 >= 0 && select5 <= 8) {
            switch(select5) {
                case 1:
                    DisplayBook();
                    break;

                case 2:
                    FirstPage();
                    Borrowed();
                    break;

                case 3:
                    FirstPage();
                    NotBorrowed();
                    break;

                case 4:
                    SortBy(1);
                    break;

                case 5:
                    SortBy(2);
                    break;

                case 6:
                    SortBy(3);
                    break;

                case 7:
                    SortBy(4);
                    break;

                case 8:
                    FirstPage();
                    NewYear();
                    break;

                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break;          
            }
            return;
        } else printf("\033[31mLua chon khong hop le, vui long nhap lai: \033[0m");
    } while(select5 != 0);
}

void borrow_return() {
    int select6;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│                   \033[38;5;178mCHUC NANG MUON/TRA SACH\033[38;5;117m                │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Muon sach.                                            │\n");
    printf("│ 2. Tra sach.                                             │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m ");  
    do{
        scanf("%d", &select6);
        if (select6 >= 0 && select6 <= 2) {
            switch (select6) {
                case 1:
                    int id;
                    DisplayBook();
                    printf("\033[38;5;146mNhap ma so sach can muon: \033[0m");
                    scanf("%d", &id);
                    BorrowBook(id);
                    break;

                case 2:
                    int id1;
                    printf("\033[38;5;146mNhap ma so sach can tra:\033[0m ");
                    scanf("%d", &id1);
                    ReturnBook(id1);
                    break;

                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break;      
            }
            return;
        } else printf("\033[31mLua chon khong hop le, vui long nhap lai: \033[0m");
    }while(select6 != 0);
}

void edit() {
    int select7, id;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│           \033[38;5;178mCHUC NANG CHINH SUA THONG TIN SACH\033[38;5;117m             │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Chinh sua ten sach.                                   │\n");
    printf("│ 2. Chinh sua ten tac gia.                                │\n");
    printf("│ 3. Chinh sua ten nha xuat ban.                           │\n");
    printf("│ 4. Chinh sua nam xuat ban.                               │\n");
    printf("│ 5. Chinh sua tat ca noi dung sach.                       │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m ");  
    do{
        scanf("%d", &select7);
        if (select7 >=0 && select7 <= 5) {
            switch (select7) {
                case 1:
                    printf("\033[38;5;146mNhap vao ma so sach can sua:\033[0m ");
                    scanf("%d", &id); getchar();
                    EditBook(1, id);
                    break;

                case 2:
                    printf("\033[38;5;146mNhap vao ma so sach can sua:\033[0m ");
                    scanf("%d", &id); getchar();
                    EditBook(2, id);
                    break;

                case 3:
                    printf("\033[38;5;146mNhap vao ma so sach can sua:\033[0m ");
                    scanf("%d", &id); getchar();
                    EditBook(3, id);
                    break;

                case 4:
                    printf("\033[38;5;146mNhap vao ma so sach can sua:\033[0m ");
                    scanf("%d", &id); getchar();
                    EditBook(4, id);
                    break;

                case 5:
                    printf("\033[38;5;146mNhap vao ma so sach can sua:\033[0m ");
                    scanf("%d", &id); getchar();
                    EditAll(id);
                    break;

                case 0:
                    printf("\033[1;32mDa quay ve Menu chinh!\033[0m\n");
                    break;
            }
            return;
        } else printf("\033[31mLua chon khong hop le, vui long nhap lai: \033[0m");
    }while(select7 != 0);
}

void Bin(BookNode** head) {
    int select9;
    printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
    printf("│                         \033[38;5;178mTHUNG RAC\033[38;5;117m                        │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Khoi phuc sach da xoa.                                │\n");
    printf("│ 2. Lam sach thung rac.                                   │\n");
    printf("│ 0. Quay ve Menu chinh.                                   │\n");
    printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[38;5;146mNhap lua chon:\033[0m "); 
    while (1) { 
        scanf("%d", &select9);
        if (select9 == 1) {
            char FileBin[100] = "bin.txt";
            ReadFile(FileBin, &bin);
            if (DisplayBookInBin(bin)) {
                printf("\033[38;5;146mNhap ma so sach muon khoi phuc:\033[0m ");
                int id;
                scanf("%d", &id); getchar();
                RestoreBook(id);
            }
            FreeList(&bin);
            return;
        }

        else if (select9 == 2) {
            Empty_Bin();
            return;
        }

        else if (select9 == 0) {
            printf("\033[1;32mDa quay ve menu chinh!\033[0m\n");
            return;
        }

        else{
            printf("\033[31mLua chon khong hop le, vui long nhap lai:\033[0m ");
        }
    }
}

//Menu
void Menu() {

    int select;
    char filedata[100] = "data.txt";
    char filebin[100] = "bin.txt";

    do {

        Book book;
        printf("\n\033[38;5;117m┌──────────────────────────────────────────────────────────┐\n");
        printf("│                \033[38;5;178mHE THONG QUAN LI THU VIEN\033[38;5;117m                 │\n");
        printf("├──────────────────────────────────────────────────────────┤\n");
        printf("│ 1. Nhap du lieu tu file.                                 │\n");
        printf("│ 2. Them mot cuon sach vao thu vien.                      │\n");
        printf("│ 3. Xoa mot cuon sach khoi thu vien.                      │\n");
        printf("│ 4. Tim kiem sach trong thu vien.                         │\n");
        printf("│ 5. Chuc nang xem sach.                                   │\n");
        printf("│ 6. Chuc nang muon/tra sach.                              │\n");
        printf("│ 7. Chuc nang chinh sua thong tin sach.                   │\n");
        printf("│ 8. Chuc nang luu file.                                   │\n");
        printf("│ 9. Thung rac.                                            │\n");
        printf("│ 0. Thoat.                                                │\n");
        printf("└──────────────────────────────────────────────────────────┘\033[0m\n");
        printf("\033[38;5;146mNhap lua chon:\033[0m ");  
        scanf("%d", &select); getchar();

        if (select >= 0 && select <= 9) {
            switch (select) {
                case 1:
                    create_read();
                    SaveData(filedata, &head);
                    break;
                case 2:
                    insert(book);
                    SaveData(filedata, &head);
                    break;
                case 3:
                    del();
                    SaveData(filedata, &head);
                    FreeList(&bin);
                    break;
                case 4:
                    search();
                    break;
                case 5:
                    read();
                    FreeList(&head);
                    ReadFile(filedata, &head);
                    break;
                case 6:
                    borrow_return();
                    SaveData(filedata, &head);
                    break;
                case 7:
                    edit();
                    SaveData(filedata, &head);
                    break;
                case 8:
                    saveFile();
                    break;
                case 9:
                    Bin(&head);
                    break;
                case 0:
                    FreeList(&head);
                    printf("\033[1;32mDa thoat khoi chuong trinh!\033[0m\n");
                    break;
            }
        } else {
            printf("\033[31mLua chon khong hop le, vui long nhap lai: \033[0m");
        }

    } while (select != 0);
}