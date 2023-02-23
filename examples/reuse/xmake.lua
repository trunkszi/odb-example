-- on_load -> after_load -> on_config -> before_build -> on_build -> after_build

target("reuse", function()
    on_load(function(target)
        os.cd("$(projectdir)/examples/reuse")
        if is_plat("windows") then
            -- windows平台需要安装build2构建系统
            os.setenv("PATH", os.getenv("PATH") .. ";" .. path.translate("C:/build2/bin"))
            os.execv(path.absolute("../../vendor/odb/windows/bin/odb.exe"), { "--std", "c++14", "-d", "pgsql", "--generate-query", "--generate-schema", "--generate-prepared", "employee.h" })
        elseif is_plat("linux") then
            os.addenv("PATH", path.absolute("../../vendor/odb/linux/bin/"))
            os.addenv("LD_LIBRARY_PATH", path.absolute("../../vendor/odb/linux/bin/"))
            os.execv("chmod", { "+x", path.absolute("../../vendor/odb/linux/bin/odb") })
            os.execv(path.absolute("../../vendor/odb/linux/bin/odb"), { "--std", "c++14", "-d", "pgsql", "-I", path.absolute("../../vendor/odb/linux/include"), "--generate-query", "--generate-schema", "--generate-prepared", "employee.h" })
        elseif is_plat("macosx") then
            os.addenv("PATH", path.absolute("../../vendor/odb/macosx/bin/"))
            os.addenv("LD_LIBRARY_PATH", path.absolute("../../vendor/odb/macosx/bin/"))
            os.execv("chmod", { "+x", path.absolute("../../vendor/odb/macosx/bin/odb") })
            os.execv(path.absolute("../../vendor/odb/macosx/bin/odb"), { "--std", "c++14", "-d", "pgsql", "-I", path.absolute("../../vendor/odb/macosx/include"), "--generate-query", "--generate-schema", "--generate-prepared", "--generate-session","employee.h" })
        end

        local files = os.files(os.curdir() .. "/**")
        for _, filepath in ipairs(files) do
            if path.extension(filepath) == ".hxx" or path.extension(filepath) == ".ixx" or path.extension(filepath) == ".cxx" then
                cprint('generate for odb on %s ... ${bright magenta}%s', os.host(), filepath)
            end
        end
        os.cd("$(projectdir)")
    end)

    set_kind("binary")

    if is_plat("windows") then
        add_includedirs("$(projectdir)/vendor/odb/windows/include")
        if is_mode("debug") then
            add_linkdirs("$(projectdir)/vendor/odb/windows/lib/x64/debug")
        else
            add_linkdirs("$(projectdir)/vendor/odb/windows/lib/x64/release")
        end
    elseif is_plat("linux") then
        add_includedirs("$(projectdir)/vendor/odb/linux/include")
        add_linkdirs("$(projectdir)/vendor/odb/linux/lib/")
    elseif is_plat("macosx") then
        add_includedirs("$(projectdir)/vendor/odb/macosx/include")
        add_linkdirs("$(projectdir)/vendor/odb/macosx/lib/")
    end
    add_links("odb", "odb-pgsql", "pq")

    --add_includedirs("../")
    add_headerfiles("*.h")
    add_defines("DATABASE_PGSQL")

    add_files("*.cpp", "*.cxx")
    add_packages("fmtlog")

    after_build(function(target)
        import("core.base.process")
        import("core.base.scheduler")
        scheduler.co_start(function()
            --process.openv("xmake", {"project", "-k", "vsxmake", "-a", "x64", "-y", "-v"}, {detach = true}):close()
            --process.openv("xmake", {"project", "-k", "cmake", "-y", "-v"}, {detach = true}):close()
            --process.openv("xmake", {"project" ,"-k", "cmake", "--project=unitest"}, {detach = true}):close()
            --process.openv("xmake", {"project" ,"-k", "cmake", "--project=benchmarks"}, {detach = true}):close()
        end)
    end)
end)