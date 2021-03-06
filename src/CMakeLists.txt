SET(EXEC_NAME opengms)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/ui)

## Source Code
SET(${EXEC_NAME}_HEADER_FILES
        ui/Settings.h
        Debug.h
        Helpers.h
        Logger.h
        Main.h
    )
SET(${EXEC_NAME}_SOURCE_FILES 
        ui/MainWindow.cpp
        ui/DialogAbout.cpp
        ui/UIManager.cpp
        ui/DockWidgetConsole.cpp
        ui/DockWidgetFileExplorer.cpp
        Debug.cpp
        Main.cpp
    )
SET(${EXEC_NAME}_QT_WRAP_FILES
        ui/MainWindow.h
        ui/DialogAbout.h
        ui/UIManager.h
        ui/DockWidgetConsole.h
        ui/DockWidgetFileExplorer.h
    )
SET(${EXEC_NAME}_QT_UI_FILES
        ui/MainWindow.ui 
        ui/DialogAbout.ui 
        ui/DockWidgetFileExplorer.ui 
    )
SET(${EXEC_NAME}_QT_RESOURCE_FILES
    )
SET(${EXEC_NAME}_LIBRARY_FILES
    )
SET(${EXEC_NAME}_SWIG_INPUT_FILES
    )
    
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR} ) # For generated ui_ files

## Handle the Qt stuff
IF(QT4_FOUND)
    QT4_WRAP_UI(${EXEC_NAME}_QT_WRAPPED_UI_FILES ${${EXEC_NAME}_QT_UI_FILES})
    QT4_WRAP_CPP(${EXEC_NAME}_QT_WRAPPED_CPP_FILES ${${EXEC_NAME}_QT_WRAP_FILES})
    QT4_ADD_RESOURCES(${EXEC_NAME}_QT_ADDED_RESOURCE_FILES ${${EXEC_NAME}_QT_RESOURCE_FILES})
ELSEIF(Qt5Widgets_FOUND AND Qt5Core_FOUND)
    SET(${EXEC_NAME}_QT_MODULES 
            Widgets 
            Core
        )
    QT5_WRAP_UI(${EXEC_NAME}_QT_WRAPPED_UI_FILES ${${EXEC_NAME}_QT_UI_FILES})
    QT5_WRAP_CPP(${EXEC_NAME}_QT_WRAPPED_CPP_FILES ${${EXEC_NAME}_QT_WRAP_FILES})
    QT5_ADD_RESOURCES(${EXEC_NAME}_QT_ADDED_RESOURCE_FILES ${${EXEC_NAME}_QT_RESOURCE_FILES})
ELSE()
    ## Ensure the following are cleared
    SET(${EXEC_NAME}_QT_WRAPPED_UI_FILES)
    SET(${EXEC_NAME}_QT_WRAPPED_CPP_FILES)
    SET(${EXEC_NAME}_QT_ADDED_RESOURCE_FILES)
ENDIF()

# Handle the Swig stuff 
# For this project the components being wrapped are only used to generate the wrapper CPP files and
# the interface PY files, but not to actually build the module itself.
IF(SWIG_GENERATE_CODE)
    LIST(APPEND ${EXEC_NAME}_SWIG_SOURCE_PARAMETERS -fastquery)
    SET_SOURCE_FILES_PROPERTIES(${${EXEC_NAME}_SWIG_INPUT_FILES} PROPERTIES CPLUSPLUS TRUE)
    SET_SOURCE_FILES_PROPERTIES(${${EXEC_NAME}_SWIG_INPUT_FILES} PROPERTIES SWIG_FLAGS "${${EXEC_NAME}_SWIG_SOURCE_PARAMETERS}" )
    SET(${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES "")
    # Cycle through all the swig files
    FOREACH(SWIG_FILE IN ITEMS ${${EXEC_NAME}_SWIG_INPUT_FILES})
        GET_FILENAME_COMPONENT(SWIG_FILE_NAME ${SWIG_FILE} NAME_WE)
        
        # Call swig, but do not generate the library component as SWIG_ADD_MODULE would do.
        SWIG_GENERATE_CODE(${SWIG_FILE_NAME}_MODULE python ${SWIG_FILE_NAME}_OUT_FILES ${SWIG_FILE} )
        #${SWIG_FILE_NAME}_OUT_FILES
        # Add the generated file to the list of source codes to be compiled
        SET(${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES ${${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES} ${${SWIG_FILE_NAME}_OUT_FILES})
        #MESSAGE(STATUS "Swig Source Files (Generated): ${${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES}")
        
        # When installing, copy the generated interface file to the correct location 
        INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SWIG_FILE}.py
                DESTINATION ${SWIG_PYTHON_INSTALL_DIR})
    ENDFOREACH()
ELSE()
    SET(${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES)
ENDIF()

# Executable Creation File
ADD_EXECUTABLE(${EXEC_NAME} ${${EXEC_NAME}_SOURCE_FILES} 
                            ${${EXEC_NAME}_HEADER_FILES} 
                            ${${EXEC_NAME}_QT_WRAPPED_CPP_FILES} 
                            ${${EXEC_NAME}_QT_WRAPPED_UI_FILES} 
                            ${${EXEC_NAME}_QT_ADDED_RESOURCE_FILES}
                            ${${EXEC_NAME}_SWIG_WRAPPED_SOURCE_FILES})
IF(Qt5Widgets_FOUND)
    FOREACH(QT5_MODULE_NAME IN ITEMS ${${EXEC_NAME}_QT_MODULES})
        QT5_USE_MODULES(${EXEC_NAME} ${QT5_MODULE_NAME})
    ENDFOREACH()
ENDIF()
TARGET_LINK_LIBRARIES(${EXEC_NAME} ${QT_LIBRARIES} ${${EXEC_NAME}_LIBRARY_FILES})
SET_PROPERTY(TARGET ${EXEC_NAME} PROPERTY DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
SET_PROPERTY(TARGET ${EXEC_NAME} PROPERTY RELEASE_POSTFIX ${CMAKE_RELEASE_POSTFIX})
SET_PROPERTY(TARGET ${EXEC_NAME} PROPERTY RELWITHDEBINFO_POSTFIX ${CMAKE_RELWITHDEBINFO_POSTFIX})

# Installation
INSTALL(TARGETS ${EXEC_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBRARY_SUBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_ARCHIVE_SUBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_RUNTIME_SUBDIR})
