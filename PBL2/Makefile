# trinh bien dich
CXX = g++
CXXFLAGS = -g -IC:\SFML\include -IE:\DUT\CODE\PBL2\src\Include -IE:\DUT\CODE\PBL2\src\Entity -IE:\DUT\CODE\PBL2\src\Map -IE:\DUT\CODE\PBL2\src\UI -IE:\DUT\CODE\PBL2\src\UX

# lien ket thu vien
LDFLAGS = -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-main

# tim tat ca cac file cpp
SRC := $(shell dir /b /s src\*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET = game.exe

# Default target
all: $(TARGET)

# Link objects
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile .cpp -> .o (giữ nguyên thư mục)
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Run program
run: $(TARGET)
	$(TARGET)

# Clean all .o and exe
clean:
	del /Q $(OBJ) $(TARGET)								
