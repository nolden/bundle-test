include_directories(../libA ../libB)
add_executable(Main MACOSX_BUNDLE main.cpp)
target_link_libraries(Main libA )

install(TARGETS Main RUNTIME DESTINATION bin )
# SET(DIRS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${ITK_LIBRARY_DIRS})
SET(DIRS \${CMAKE_INSTALL_PREFIX}/plugins/libB \${CMAKE_INSTALL_PREFIX}/plugins ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}  ${ITK_LIBRARY_DIRS})

SET(PLUGIN \${CMAKE_INSTALL_PREFIX}/plugins/${CMAKE_SHARED_LIBRARY_PREFIX}libA${CMAKE_SHARED_LIBRARY_SUFFIX})
LIST(APPEND PLUGIN \${CMAKE_INSTALL_PREFIX}/plugins/libB/${CMAKE_SHARED_LIBRARY_PREFIX}libB${CMAKE_SHARED_LIBRARY_SUFFIX})
LIST(APPEND PLUGIN \${CMAKE_INSTALL_PREFIX}/plugins/${CMAKE_SHARED_LIBRARY_PREFIX}libC${CMAKE_SHARED_LIBRARY_SUFFIX})

# SET(PLUGIN ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/../plugins/${CMAKE_SHARED_LIBRARY_PREFIX}libA${CMAKE_SHARED_LIBRARY_SUFFIX})

INSTALL(CODE "
    # use custom version of BundleUtilities
    SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_MODULE_PATH} )
    include(BundleUtilities)

    MACRO(gp_item_default_embedded_path_override item default_embedded_path_var)
      GET_FILENAME_COMPONENT(_item_name \"\${item}\" NAME)
      GET_FILENAME_COMPONENT(_item_path \"\${item}\" PATH)
      IF(_item_name MATCHES \"liblib\")
         IF(APPLE)
           SET(full_path \"full_path-NOTFOUND\")
           MESSAGE(\"override: \${item}\")        
           FILE (GLOB_RECURSE full_path \${CMAKE_INSTALL_PREFIX}/plugins/\${_item_name} )
           MESSAGE(\"find file: \${full_path}\")        
           
           GET_FILENAME_COMPONENT(_item_path \"\${full_path}\" PATH)
           
           # SET(\${default_embedded_path_var} @executable_path/../../../../plugins/ )
           STRING(REPLACE 
              \${CMAKE_INSTALL_PREFIX} 
              @executable_path/../../../../ \${default_embedded_path_var} \"\${_item_path}\" ) 
           MESSAGE(\"override result: \${\${default_embedded_path_var}}\")        
         ELSE(APPLE)
              SET(\${default_embedded_path_var} \"\${_item_path}\")
         ENDIF(APPLE)
      ENDIF()
    ENDMACRO(gp_item_default_embedded_path_override)

    fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/bin/Main.app\" \"${PLUGIN}\" \"${DIRS}\")
    " COMPONENT Runtime)
    
