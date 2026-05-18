cmake_minimum_required(VERSION 3.10)

# C++ motor projesinin tanimidir.
project(AdliMudaheleMotoru)

set(CMAKE_CXX_STANDARD 17)

# Tum modullerimizi (Ag, Kalicilik, Bellek, Tarayici, USB) derleme islemine dahil ediyoruz.
add_executable(AdliMudaheleMotoru 
    core/src/anaMotor.cpp 
    core/src/agAnalizi.cpp
    core/src/kalicilikAnalizi.cpp
    core/src/bellekTaramasi.cpp
    core/src/tarayiciAnalizi.cpp
    core/src/usbAnalizi.cpp
)

# Ciktinin gidecegi dizini belirliyoruz.
set_target_properties(AdliMudaheleMotoru PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")