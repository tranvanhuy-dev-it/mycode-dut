#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib> // Thêm thư viện này để sử dụng rand()
#include <ctime>   // Thêm thư viện này để sử dụng time()

void drawDuck(const std::string& name, int position) {
    std::cout << name << ": ";
    for (int i = 0; i < position; ++i) {
        std::cout << " ";
    }
    std::cout << "🐤" << std::endl; // Sử dụng biểu tượng vịt
}

int main() {
    const int finishLine = 50;
    int huyPosition = 0;
    int haoPosition = 0;

    std::srand(static_cast<unsigned>(std::time(0))); // Khởi tạo bộ sinh số ngẫu nhiên

    while (huyPosition < finishLine && haoPosition < finishLine) {
        system("clear"); // Dùng "cls" nếu bạn sử dụng Windows

        drawDuck("Huy", huyPosition);
        drawDuck("Hào", haoPosition);

        huyPosition += rand() % 3; // Huy chạy ngẫu nhiên 0-2 bước
        haoPosition += rand() % 3; // Hào chạy ngẫu nhiên 0-2 bước

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Tạm dừng một chút
    }

    std::cout << "Đua kết thúc!" << std::endl;
    if (huyPosition >= finishLine && haoPosition >= finishLine) {
        std::cout << "Cả hai đã đến đích cùng lúc!" << std::endl;
    } else if (huyPosition >= finishLine) {
        std::cout << "Huy chiến thắng!" << std::endl;
    } else {
        std::cout << "Hào chiến thắng!" << std::endl;
    }

    return 0;
}
