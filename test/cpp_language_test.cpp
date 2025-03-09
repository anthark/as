//
// Created by ivn on 21.06.2024.
//

#include <gtest/gtest.h>

#include "as/core/core.h"
#include "as/languages/cpp/cpp_language.h"

#include "features_test_fixture.h"

static const char* CODE_SIMPLE_42 = R"(
#include "simple.h"

class Test42: public SimpleScript
{
public:
    int foo()
    {
        return 42;
    }
};
)";

static const char* CODE_SIMPLE_4242 = R"(
#include "simple.h"

class Test42: public SimpleScript
{
public:
    int foo()
    {
        return 4242;
    }
};
)";

static const char* CODE_INTEGER = R"(
#include "integer.h"

class TestInteger: public IntegerScript
{
public:
    int pass(int arg) override
    {
        return arg;
    }

    int mul(int arg1, int arg2) override
    {
        return arg1 * arg2;
    }

    int add(int arg1, int arg2, int arg3) override
    {
        return arg1 + arg2 + arg3;
    }
};
)";

static const char* CODE_DOUBLE = R"(
#include "double.h"

class TestDouble: public DoubleScript
{
public:
    double pass(double arg) override
    {
        return arg;
    }

    double mul(double arg1, double arg2) override
    {
        return arg1 * arg2;
    }

    double add(double arg1, double arg2, double arg3) override
    {
        return arg1 + arg2 + arg3;
    }
};
)";

static const char* CODE_SET_GET_GLOBAL = R"(
#include "set_get.h"

static int g_value = 0;

class TestGlobal: public SetGetScript
{
public:
    int get() override
    {
        return g_value;
    }

    void set(int value) override
    {
        g_value = value;
    }
};
)";

class CppLanguageTest : public FeaturesTestFixture
{
protected:
    const char* getLanguageName() const override
    {
        return "cpp";
    }

    std::shared_ptr<as::ILanguage> createLanguage() const override
    {
        return std::make_shared<as::CppLanguage>();
    }

    std::shared_ptr<as::ILanguageRuntime> createRuntime() const override
    {
        return nullptr;
    }

    const char* getSimpleScript42() const override { return CODE_SIMPLE_42; }
    const char* getSimpleScript4242() const override { return CODE_SIMPLE_4242; }
    const char* getIntegerScript() const override { return CODE_INTEGER; }
    const char* getDoubleScript() const override { return CODE_DOUBLE; }
    const char* getSetGetGlobalScript() const override { return CODE_SET_GET_GLOBAL; }
};

TEST_F(CppLanguageTest, SimpleTest)
{
    doSimpleTest();
}

TEST_F(CppLanguageTest, IntegerTest)
{
    doIntegerTest();
}

TEST_F(CppLanguageTest, DoubleTest)
{
    doDoubleTest(TreatDouble::AsDouble);
}

TEST_F(CppLanguageTest, GlobalVarTest)
{
    doGlobalVarTest();
}

TEST_F(CppLanguageTest, ModulesTest)
{
    doModulesTest();
}

TEST_F(CppLanguageTest, HotReloadTest)
{
    doHotReloadTest();
}

TEST_F(CppLanguageTest, CompileStaticInitTest)
{
    doCompileStaticInitTest();
}

TEST_F(CppLanguageTest, CompileLinkTest)
{
    doCompileLinkTest();
}

TEST_F(CppLanguageTest, CompileDebugInfoTest)
{
    /*
    * The test tries to find function definition in IR code to get DebugInfo.
    * The following regex doesn't work with Windows + LLVM 18.1.0, but it (maybe) make sense for Unix-like + LLMV 17.06
    * I assume that definition was:
    * 
    * define linkonce_odr dso_local i32 @_3foo@Test42_@UEAAHXZ_(ptr nonnull align 8 dereferenceable(8) %this) unnamed_addr #0 comdat align 2 !dbg !6 {
    */
    //doCompileDebugInfoTest("@[_\\w]+3foo[_\\w]+");

    /*
    * For Windows + LLVM 18.1.0 definition seems like:
    * 
    * define linkonce_odr dso_local i32 @"?foo@Test42@@UEAAHXZ"(ptr nonnull align 8 dereferenceable(8) %this) unnamed_addr #0 comdat align 2 !dbg !6 {
    */
    doCompileDebugInfoTest(R"(@[\"\w]+\?foo[@\w]+\")");
}
