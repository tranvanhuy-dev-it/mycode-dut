#include<iostream>

using namespace std;

class Customer{
private:
    static int cnt_customer;
    int id;                 //mã số khách hàng
    string name;            //tên khách hàng
    string gender;          //giới tính
    string birth;           //ngày sinh
    string cccd;            //cccd
    string phone;           //số điện thoại
    string nationality;     //quốc tịch
    string email;           //email
public:
    int get_id();
    Customer();
    Customer(int , string, string, string, string, string, string, string);
    void save_to_csv() const;
};

int Customer::cnt_customer = 0;

int Customer::get_id() {
    return ++cnt_customer;
}

Customer::Customer() {
    id = get_id();
}

Customer::Customer(int _id, string _name, string _gender, string _birth, string _ccccd, string _phone, string _nationality, string _email) {
    id = _id;
    name = _name;
    gender = _gender;
    birth = _birth;
    cccd = _ccccd;
    phone = _phone;
    nationality = _nationality;
    email = _email;
}

class Ticket {
private:
    static int cnt_ticket;
    int number;             //số vé
    int id;                 //hạng vé
    string price;           //giá vé
    string bookingDate;     ///mã số khách hàng
    string flightID;        //mã chuyến bay
    string ticketCls;       //ngày đặt vé
    string bookingTime;     //thời gian đặt vé
    string payMeth;         //phương thức thanh toán
    string status;          //trạng thái thanh toán
};

class Flight {
private:
    static int cnt_flight;
    string flightID;        //mã chuyến bay
    string flightNum;       //số hiệu chuyến bay
    string departure;       //nơi đi
    string destination;     //nơi đến
    string Date;            //ngày bay
    string Time;            //giờ bay
    string aircraftType;    //loại máy bay
    int availableSeats;     //số ghế còn trống
    string flightStatus;    //trạng thái chuyến bay

};

class Booking {
    int bookingID;      
    Customer customer;
    Flight flight;
    Ticket ticket;
    string bookingStatus;
};

int main() {

    cout << "connecting...\n";
    return 0;
}