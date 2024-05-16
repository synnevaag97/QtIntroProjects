cmake_minimum_required(VERSION 3.5)

project(TicTacToe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(PROJECT_SOURCES
        main.cpp
        Gui/tictactoeboardwidget.cpp
        Gui/tictactoeboardwidget.h
        tictactoeboardwidget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TicTacToe
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Gui/box.h Gui/box.cpp
        Gui/mainmenuwidget.h Gui/mainmenuwidget.cpp
        Gui/mainwindow.h Gui/mainwindow.cpp
        Gui/singleplayermenuwidget.h Gui/singleplayermenuwidget.cpp
        Gui/multiplayermenuwidget.h Gui/multiplayermenuwidget.cpp
        Gui/playermenubasewidget.h Gui/playermenubasewidget.cpp
        Gui/scoreboardwidget.h Gui/scoreboardwidget.cpp

        Functionality/gamelogic.h Functionality/gamelogic.cpp
        Functionality/gamestate.h Functionality/gamestate.cpp
        Functionality/playerdatafilemanager.h Functionality/playerdatafilemanager.cpp
        Functionality/player.h Functionality/player.cpp

        Bots/easycomputer.h Bots/easycomputer.cpp
        Bots/onelevelcomputer.h Bots/onelevelcomputer.cpp
        Bots/computerbase.h Bots/computerbase.cpp
        Bots/twolayercomputer.h Bots/twolayercomputer.cpp
        Bots/invincicomputer.h Bots/invincicomputer.cpp




    )

set(TEST_SOURCES
    Tests/tst_gamestate.h Tests/tst_gamestate.cpp
    Tests/tst_player.h Tests/tst_player.cpp
    Tests/tst_runner.h
    Tests/tst_main.cpp

    Functionality/gamestate.h Functionality/gamestate.cpp
    Functionality/player.h Functionality/player.cpp

)


# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TicTacToe APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TicTacToe SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TicTacToe
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Set up the executable for your tests
add_executable(tests ${TEST_SOURCES})

target_link_libraries(TicTacToe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(tests PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TicTacToe)
endif()
set_target_properties(TicTacToe PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TicTacToe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TicTacToe)
endif()
