#include "MyString.h"

//testing library
#include "TEST2.h"

//define tests
T_GROUP(Creation, {
    T_TEST(Constructor, {
        MyString test("str1");

        T_EXPECT(test == MyString("str1"));
        T_EXPECT(test != MyString("str2"));
    });

    T_TEST(Length, {
        MyString test("str1");
        
        T_EXPECT(test.getLength() == 4);
    });
});

T_GROUP(Access, {
    T_TEST(Compare, {
        MyString test1("string1");
        MyString test2("string1");
        MyString test3("str3");

        T_EXPECT(test1.compare(test2) == 0);
        T_EXPECT(test1.compare(test3) > 0);
    });

    T_TEST(GetChar, {
        MyString test("str");

        T_EXPECT(test.getChar(0) == 's');
        T_EXPECT(test.getChar(1) == 't');
        T_EXPECT(test.getChar(2) == 'r');
    });
})

T_GROUP(Modify, {
    T_TEST(AddChar, {
        MyString testStr("str");

        testStr.addChar('a');
        T_EXPECT(testStr == MyString("stra"));

        testStr.addChar('a');
        T_EXPECT(testStr == MyString("straa"));
    });

    T_TEST(Append, {
        MyString testStr("str");

        testStr.append(MyString("STR"));
        T_EXPECT(testStr == MyString("strSTR"));

        testStr.append(MyString("123"));
        T_EXPECT(testStr == MyString("strSTR123"));
    });

    T_TEST(InsertCharAt, {
        MyString testStr("str");

        testStr.insertCharAt('1', 1);
        T_EXPECT(testStr == MyString("s1tr"));

        testStr.insertCharAt('2', 3);
        T_EXPECT(testStr == MyString("s1t2r"));
    });

    T_TEST(InsertStringAt, {
        MyString testStr("str");

        testStr.insertStrAt(MyString("123"), 1);
        T_EXPECT(testStr == MyString("s123tr"));
    });
});

T_GROUP(Conversions, {
    T_TEST(ToUppercase, {
        MyString testStr("StRiNg");

        testStr.toLower();
        T_EXPECT(testStr == MyString("string"));

        //double lowercase should not change anything
        testStr.toLower();
        T_EXPECT(testStr == MyString("string"));
    });

    T_TEST(ToLowercase, {
        MyString testStr("StRiNg");

        testStr.toUpper();
        T_EXPECT(testStr == MyString("STRING"));

        //double uppercase should not change anything
        testStr.toUpper();
        T_EXPECT(testStr == MyString("STRING"));
    });
});

int main() {
    //run tests
    T_EXECUTE(Creation);
    T_EXECUTE(Access);
    T_EXECUTE(Modify);
    T_EXECUTE(Conversions);

    return 0;
}
