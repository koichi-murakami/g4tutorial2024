#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# CMakeLists.txt: Template file to build Geant4 application
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
#   [Version] 2022.03.01:   By K. Amako
#
#   [Usage]
#     Just set a value to the prameter in the 'Setup Section' below. 
#
#   [Note] 
#     This 'CMakeLists.txt' is assumed to be used with the following
#     directory structure of a Geant4 application.
#
#      MyG4Application/
#        |-- source
#        |     |-- CMakeLists.txt
#        |     |-- MyG4Application_Main.cc
#        |     |-- include
#        |     +-- src
#        |-- build  (cmake is invoked in this dir)
#        +-- bin    (executable is installed - dir is automatically created
#
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

cmake_minimum_required(VERSION 3.16...3.21)

#----------------------------------------------------------------------------
# Setup Section: You have to set the following parameter
#----------------------------------------------------------------------------
# Set the name of your main program
  set( NAME_MAIN_PROGRAM Application_Main )


#----------------------------------------------------------------------------
# Intact Section: You don't need to touch the following part
#----------------------------------------------------------------------------
# Set the Project Name
  project( ${NAME_MAIN_PROGRAM} )

# Locate and Configure Geant4
  option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
  if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
  else()
    find_package(Geant4 REQUIRED)
  endif()

# Set the Path to the Header Files of Geant4 and the Current Project
  include(${Geant4_USE_FILE})
  include_directories(${PROJECT_SOURCE_DIR}/include)

# Locate Sources and Headers of the Current Project
  file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
  file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Compile and Link the Current Project
  add_executable(${NAME_MAIN_PROGRAM} ${NAME_MAIN_PROGRAM}.cc
                                      ${sources} ${headers})
  target_link_libraries(${NAME_MAIN_PROGRAM} ${Geant4_LIBRARIES})

# Install the Executable of the Current Project
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)
  install(TARGETS ${NAME_MAIN_PROGRAM} DESTINATION bin)
