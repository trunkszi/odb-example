package("clickhouse-cpp")
set_homepage("https://github.com/ClickHouse/clickhouse-cpp")
set_description("C++ client library for ClickHouse.")

add_urls("https://github.com/ClickHouse/clickhouse-cpp/archive/refs/tags/$(version).tar.gz",
        "https://github.com/ClickHouse/clickhouse-cpp.git")

add_versions("v2.3.0", "8eb8b49044247ccc57db73fdf41807a187d8a376d3469f255bab5c0eb0a64359")

add_configs("openssl", { description = "Enable OpenSSL for SSL/TLS.", default = true, type = "boolean" })
add_configs("lz4", { description = "Enable lz4 with library", default = true, type = "boolean" })
add_configs("absl", { description = "Enable absl with library", default = true, type = "boolean" })

add_deps("cmake","ninja", "openssl", "lz4","abseil")
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
    table.insert(configs, "-DCMAKE_BUILD_TYPE=" .. (package:debug() and "Debug" or "Release"))
    table.insert(configs, "-DBUILD_SHARED_LIBS=" .. (package:config("shared") and "ON" or "OFF"))
    table.insert(configs, "-DWITH_OPENSSL=" .. (package:config("openssl") and "ON" or "OFF"))
    table.insert(configs, "-DWITH_SYSTEM_LZ4=" .. (package:config("lz4") and "ON" or "OFF"))
    table.insert(configs, "-DWITH_SYSTEM_ABSEIL=" .. (package:config("absl") and "ON" or "OFF"))
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
    import("package.tools.cmake").install(package, configs)
end)

on_test(function(package)
    assert(package:has_cxxtypes("clickhouse::Client", { configs = { languages = "c++20" }, includes = "clickhouse/client.h" }))
end)
