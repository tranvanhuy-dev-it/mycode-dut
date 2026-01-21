# Trình biên dịch
CXX = g++
# Tuỳ chọn biên dịch
CXXFLAGS = -std=c++17 -Wall -Wextra

# File nguồn
SRC = main.cpp 
# File object
OBJ = $(SRC:.cpp=.o)
# File thực thi
TARGET = main.exe

# Luật chính
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Biên dịch từng file .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dọn dẹp
clean:
	del /Q $(OBJ) $(TARGET)

# Chạy chương trình
run: $(TARGET)
	$(TARGET)
