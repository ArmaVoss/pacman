add_subdirectory(SDL)
add_subdirectory(SDL_image)

add_library(vendor INTERFACE)

# Ensure SDL3 and SDL3_image include paths are added
target_include_directories(vendor INTERFACE
    ${CMAKE_SOURCE_DIR}/vendor/SDL/include
    ${CMAKE_SOURCE_DIR}/vendor/SDL_image/include
)

target_link_libraries(vendor INTERFACE SDL3::SDL3 SDL3_image::SDL3_image)
