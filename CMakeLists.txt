cmake_minimum_required(VERSION 3.16)

project(TodoProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTodoProject
    main.cpp
    taskmodel.h taskmodel.cpp
    listmodel.h listmodel.cpp
    todomodel.h todomodel.cpp
    todofiltermodel.h todofiltermodel.cpp
    listfiltermodel.h listfiltermodel.cpp
)

qt_add_qml_module(appTodoProject
    URI TodoProject
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/customcomponents/Header.qml
        qml/screens/ToDoListScreen.qml
        qml/screens/HomeScreen.qml
        qml/screens/CreateListScreen.qml
        qml/customcomponents/InputField.qml
        qml/customcomponents/ConfirmButton.qml
        qml/screens/EditListScreen.qml
        qml/customcomponents/TextButton.qml
        qml/customcomponents/ActiveTasksComponent.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTodoProject PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTodoProject
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTodoProject
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTodoProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
