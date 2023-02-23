package("ixwebsocket")
set_homepage("https://github.com/machinezone/IXWebSocket")
set_description("websocket and http client and server library, with TLS support and very few dependencies")
set_license("BSD 3-Clause")

add_urls("https://github.com/machinezone/IXWebSocket/archive/refs/tags/$(version).tar.gz",
        "https://github.com/machinezone/IXWebSocket.git")
add_versions("v11.4.3", "aa2d02c9c71339943cc61eb4efeb2ffc3a5a0011128a67027b9251b7d8a6e0ac")

add_configs("tls", { description = "Build with TLS library.", default = true, type = "boolean" })
add_configs("openssl", { description = "Enable OpenSSL for SSL/TLS.", default = true, type = "boolean" })
add_configs("zlib", { description = "Enable zlib with library", default = true, type = "boolean" })
add_configs("ws", { description = "Build with will build the ws interactive command line tool", default = false, type = "boolean" })
add_configs("unittest", { description = "Build with will build the unittest", default = false, type = "boolean" })

add_deps("cmake", "openssl", "zlib")
if is_plat("linux") then
    add_syslinks("pthread")
elseif is_plat("windows") then
    --add_syslinks("ole32", "shell32", "advapi32")
    add_syslinks("shlwapi", "wsock32", "ws2_32") -- network Libraries and string
    add_syslinks("Crypt32") -- on windows use tls need link Crypt32
    --add_defines("_WIN32_WINNT=0x0A00")
end

on_install("windows", "macosx", "linux", function(package)
    local configs = { "-DCMAKE_CXX_STANDARD=20" }
    io.replace("CMakeLists.txt", "set (CMAKE_CXX_STANDARD 11)", "set (CMAKE_CXX_STANDARD 20)", { plain = true })
    io.replace("CMakeLists.txt", "set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/opt/openssl/lib)", "", { plain = true })
    io.replace("CMakeLists.txt", "set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/local/opt/openssl/include)", "", { plain = true })
    io.replace("CMakeLists.txt", "find_package(OpenSSL REQUIRED)", "", { plain = true })
    io.replace("CMakeLists.txt", "find_package(ZLIB REQUIRED)", "", { plain = true })
    io.replace("CMakeLists.txt", "target_link_libraries(ixwebsocket PRIVATE ZLIB::ZLIB)", "", { plain = true })

    table.insert(configs, "-DCMAKE_BUILD_TYPE=" .. (package:debug() and "Debug" or "Release"))
    table.insert(configs, "-DBUILD_SHARED_LIBS=" .. (package:config("shared") and "ON" or "OFF"))
    table.insert(configs, "-DUSE_TLS=" .. (package:config("tls") and "ON" or "OFF"))
    table.insert(configs, "-DUSE_OPEN_SSL=" .. (package:config("openssl") and "ON" or "OFF"))
    table.insert(configs, "-DUSE_ZLIB=" .. (package:config("zlib") and "ON" or "OFF"))
    if is_plat("windows") then
        table.insert(configs, "-DCOMPILE_FLAGS=/EHsc /MP")
        if is_mode("debug") then
            table.insert(configs, "-DCMAKE_CXX_FLAGS_DEBUG=/MTd")
            table.insert(configs, "-DCMAKE_C_FLAGS_DEBUG=/MTd")
        else
            table.insert(configs, "-DCMAKE_CXX_FLAGS_RELEASE=/MT")
            table.insert(configs, "-DCMAKE_C_FLAGS_RELEASE=/MT")
        end
    end
    import("package.tools.cmake").install(package, configs, { packagedeps = {"openssl", "zlib" }})
end)

on_test(function(package)
    assert(package:has_cxxtypes("ix::WebSocket", { configs = { languages = "c++20" }, includes = "ixwebsocket/IXWebSocket.h" }))
end)
