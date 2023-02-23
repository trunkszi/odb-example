add_rules("mode.debug", "mode.release")

-- 开发期间默认编译debug版本，发布时默认编译release版本
set_defaultmode("debug")
--set_defaultmode("release")
set_xmakever("2.7.6")

set_languages("c17", "cxx20")

--set_exceptions("no-cxx") -- 关闭c++异常
set_exceptions("cxx") -- 开启c++异常
set_policy("build.c++.modules", true) -- 强制开启c++20 modules
set_policy("package.install_always", true) -- xmake f -c 重新配置的时候，强制重新安装依赖库
set_policy("package.strict_compatibility", true) -- 严格检查依赖库版本
set_policy("package.librarydeps.strict_compatibility", true) -- 严格检查依赖库版本

if is_mode("debug") then
    set_warnings("all")     -- -Wall
    set_symbols("debug")    -- dbg symbols
    set_optimize("none")    -- 禁用优化
    add_requireconfs("*", { configs = {
        debug = true,
    } })
else
    set_optimize("faster")
    set_symbols("hidden")  -- hidden symbols
    set_strip("all")     -- strip all symbols
    add_requireconfs("*", { configs = {
        lto = true,
    } })
end

-- 定义项目全局配置、同时会影响add_requires所导入的第三方库配置
if is_plat("windows") then
    set_toolchains("clang-cl")
    set_arch("x64")
    --add_ldflags("/Gy")
    add_cxflags("/EHsc", "/Gy")
    add_cxflags("/FS")   -- /FS 使得多个编译器进程可以同时写入pdb文件
    -- 指定source文件和可执行文件为utf8
    add_cxflags("/source-charset:utf-8", "/execution-charset:utf-8", "/validate-charset")
    -- 设置运行时库
    if is_mode("debug") then
        set_runtimes("MTd")
        add_ldflags("/FORCE:MULTIPLE")   -- fix duplicate symbols
        --add_ldflags("/DEFAULTLIB:libcmtd")  -- 覆盖默认link msvcrt.lib
        --add_syslinks("libcmtd") -- MTd 模式需要手动link libcmtd.lib
    else
        set_runtimes("MT")
        add_cxflags("/EHsc")
        add_ldflags("/SAFESEH:NO")
        add_cxflags("/GL") -- 全程序优化
    end
elseif is_plat("linux","macosx") then
end

add_repositories("local-repo repo", { rootdir = os.scriptdir() })

add_requires("benchmark", { configs = {
    debug = false,
    lto = true,
} })

add_requires("fmtlog v2.2.1", { configs = {
    verify = false,
}})

--on_load("modules.load")
includes("examples")
