package("quickfix")

set_homepage("https://github.com/quickfix/quickfix/")
set_description("QuickFIX C++ Fix Engine Library")

add_urls("https://github.com/quickfix/quickfix/archive/refs/tags/$(version).tar.gz",
        "https://github.com/quickfix/quickfix.git")
add_versions("v1.15.1", "1c4322a68704526ca3d1f213e7b0dcd30e067a8815be2a79b2ab1197ef70dcf7")


local configdeps = {
    emx = "quickfix-emx",
    openssl = "openssl",
    mysql = "mysql",
    postgresql="postgresql",
    python= "python3",
    python2 = "python2",
}

for config, dep in pairs(configdeps) do
    add_configs(config, {description = "Enable " .. dep .. " support.",  type = "boolean"})
end

add_deps("cmake", "ninja")

on_load("windows", "linux", "macosx", function (package)
    for config, dep in pairs(configdeps) do
        if package:config(config) then
            package:add("deps", dep)
        end
    end
end)

on_install("windows", "linux", "macosx", function (package)
    local configs = {}
    table.insert(configs, "-DCMAKE_BUILD_TYPE=" .. (package:debug() and "Debug" or "Release"))
    table.insert(configs, "-DBUILD_SHARED_LIBS=" .. (package:config("shared") and "ON" or "OFF"))
    if is_plat("windows") then
        --table.insert(configs, "-DCMAKE_CXX_FLAGS=c++17")
        table.insert(configs, "-DCMAKE_CXX_FLAGS=/FS /EHsc")
        table.insert(configs, "-G Ninja")
    elseif is_plat("linux") then
        table.insert(configs, "-DCMAKE_CXX_FLAGS=c++14")
        table.insert(configs, "-G Unix Makefiles")
    end
    for config, dep in pairs(configdeps) do
        table.insert(configs, "-DHAVE_" .. config:upper() .. "=" .. (package:config(config) and "ON" or "OFF"))
    end

    import("package.tools.cmake").install(package, configs)
end)

on_test(function (package)
    assert(package:has_cxxtypes("FIX::Application", {includes = "quickfix/Application.h"}))
end)
