CXX: = g++
CXXFLAGS : = -std = c++11
TARGET : = signal - echo

all : $(TARGET)

$(TARGET) : signal_echo.cpp
$(CXX) $(CXXFLAGS) - o $(TARGET) signal_echo.cpp

clean :
rm - f $(TARGET)
