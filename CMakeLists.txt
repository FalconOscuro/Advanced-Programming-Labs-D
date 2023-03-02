project(Lab-D LANGUAGES CXX)

cmake_minimum_required(VERSION 3.16)

# Build all binaries to the /bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Lab files
message(STATUS "Adding Executables")
set(TASK_DIR "${CMAKE_SOURCE_DIR}/Tasks")

add_executable(Grid "${TASK_DIR}/02-Reading/Main.cpp" "${TASK_DIR}/02-Reading/Grid.cpp")
configure_file(${TASK_DIR}/01-Linker-Errors/Grid1.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Grid1.txt COPYONLY)

option(BUILD_LABBOOK "Build the labbook" OFF)

# Lab Book using LaTeX
if(BUILD_LABBOOK)
    message(STATUS "Preparing for LaTeX")
    find_package(LATEX)
    set(LT_OUT_DIR "${CMAKE_BINARY_DIR}/tex")
    set(LT_WORKING_DIR "${CMAKE_SOURCE_DIR}/LabBook")
    set(MAIN_TEX "${LT_WORKING_DIR}/${PROJECT_NAME}.tex")

    if(LATEX_FOUND AND LATEX_PDFLATEX_FOUND)
        file(MAKE_DIRECTORY ${LT_OUT_DIR})

        # First Pass
        add_custom_target( latex-prebuild
                            COMMAND ${PDFLATEX_COMPILER} -output-directory ${LT_OUT_DIR} -draftmode -shell-escape -interaction=nonstopmode ${MAIN_TEX}
                            COMMENT "Starting Prebuild..."
                            WORKING_DIRECTORY ${LT_WORKING_DIR}
                            DEPENDS ${MAIN_TEX}
                    )

        # Second Pass, generating final pdf
        add_custom_target( latex-pdf
                            COMMAND ${PDFLATEX_COMPILER} -output-directory ${LT_OUT_DIR} -shell-escape ${MAIN_TEX}
                            COMMENT "Starting Final Build..."
                            WORKING_DIRECTORY ${LT_WORKING_DIR}
                            DEPENDS ${MAIN_TEX}
                    )
    
        add_custom_target(all-formats ALL) # Entry point for execution
        add_dependencies(all-formats latex-pdf)
    else()
        message(WARNING "LaTeX tools not found, unable to build tex files")
    endif()
endif()