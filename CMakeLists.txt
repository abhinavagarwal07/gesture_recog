
cmake_minimum_required(VERSION 2.8)
project( vis )
find_package( OpenCV REQUIRED )
add_executable( vis 
main.cpp 

)
target_link_libraries(vis  ${OpenCV_LIBS} )
