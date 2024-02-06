cmake_minimum_required(VERSION 3.16)
project(libhandy-no-force-theme VERSION 0.0.1)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBHANDY REQUIRED libhandy-1)

add_library(handy-no-force-theme SHARED libhandy-no-force-theme.c)
set_target_properties(handy-no-force-theme PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)
target_include_directories(handy-no-force-theme PRIVATE "${LIBHANDY_INCLUDE_DIRS}")
target_link_libraries(handy-no-force-theme PRIVATE dl)

include(GNUInstallDirs)
if("${CMAKE_INSTALL_PREFIX}" MATCHES "local")
    message(WARNING "Library will be installed in ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}. If you intend to LD_PRELOAD it globally, sudo will throw errors unless it is installed in either /lib or /usr/lib.")
endif()

install(TARGETS handy-no-force-theme LIBRARY
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ
        SETUID # Required so that sudo doesn't complain
)

install(FILES 51libhandy-no-force-theme
    DESTINATION "${CMAKE_INSTALL_SYSCONFDIR}/Xsession.d"
    PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ
)
