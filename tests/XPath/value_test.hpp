#ifndef XPATHIC_VALUE_TEST_H
#define XPATHIC_VALUE_TEST_H

#include "../CppUnit/framework/TestCase.h"
#include "../CppUnit/framework/TestSuite.h"
#include "../CppUnit/framework/TestCaller.h"

#include <XPath/XPath.hpp>

template<class string_type, class string_adaptor>
class ValueTest : public TestCase
{
private:
  DOM::Node<string_type> dummy_;
  typedef string_adaptor SA;

public:
  ValueTest(std::string name) : TestCase(name)
  {
  } // ValueTest

  void setUp()
  {
  } // setUp

  void test1()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> b(new BoolValue<string_type, string_adaptor>(true));
    assertEquals(true, b->evaluateAsBool(dummy_));
    assertEquals(1.0, b->evaluateAsNumber(dummy_), 0.0);
    assertTrue(SA::construct_from_utf8("true") == b->evaluateAsString(dummy_));
  }

  void test2()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> b2(new BoolValue<string_type, string_adaptor>(false));
    assertEquals(false, b2->evaluateAsBool(dummy_));
    assertEquals(0.0, b2->evaluateAsNumber(dummy_), 0.0);
    assertTrue(SA::construct_from_utf8("false") == b2->evaluateAsString(dummy_));
  } // test2

  void test3()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> n(new NumericValue<string_type, string_adaptor>(99.5));
    assertEquals(true, n->evaluateAsBool(dummy_));
    assertEquals(99.5, n->evaluateAsNumber(dummy_), 0.0);
    assertTrue(SA::construct_from_utf8("99.5") == n->evaluateAsString(dummy_));
  }

  void test4()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> n(new NumericValue<string_type, string_adaptor>(0.0));
    assertEquals(false, n->evaluateAsBool(dummy_));
    assertEquals(0, n->evaluateAsNumber(dummy_), 0);
    assertTrue(SA::construct_from_utf8("0") == n->evaluateAsString(dummy_));
  }

  void test5()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> s(new StringValue<string_type, string_adaptor>("hello"));
    assertEquals(true, s->evaluateAsBool(dummy_));
    assertTrue(SA::construct_from_utf8("hello") == s->evaluateAsString(dummy_));
  } // test5

  void test6()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> s(new StringValue<string_type, string_adaptor>(""));
    assertEquals(false, s->evaluateAsBool(dummy_));
  }

  void test7()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> s(new StringValue<string_type, string_adaptor>("100"));
    assertEquals(true, s->evaluateAsBool(dummy_));
    assertEquals(100.0, s->evaluateAsNumber(dummy_), 0.0);
    assertTrue(SA::construct_from_utf8("100") == s->evaluateAsString(dummy_));
  } // test7

  void test8()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> s(new StringValue<string_type, string_adaptor>("0"));
    assertEquals(true, s->evaluateAsBool(dummy_));
    assertEquals(0.0, s->evaluateAsNumber(dummy_), 0.0);
    assertTrue(SA::construct_from_utf8("0") == s->evaluateAsString(dummy_));
  } // test8

  void test9()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> bt(new BoolValue<string_type, string_adaptor>(true));
    XPathExpressionPtr<string_type> st(new StringValue<string_type, string_adaptor>("true"));
    XPathExpressionPtr<string_type> bf(new BoolValue<string_type, string_adaptor>(false));
    XPathExpressionPtr<string_type> sf(new StringValue<string_type, string_adaptor>(""));

    assertTrue((impl::areEqual<string_type, string_adaptor>(bt->evaluate(dummy_), (st->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(st->evaluate(dummy_), (bt->evaluate(dummy_)))));

    assertTrue((impl::areEqual<string_type, string_adaptor>(sf->evaluate(dummy_), (bf->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(bf->evaluate(dummy_), (sf->evaluate(dummy_)))));

    assertTrue((impl::areEqual<string_type, string_adaptor>(bt->evaluate(dummy_), (bt->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(bf->evaluate(dummy_), (bf->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(st->evaluate(dummy_), (st->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(sf->evaluate(dummy_), (sf->evaluate(dummy_)))));
  } // test9

  void test10()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> bt(new BoolValue<string_type, string_adaptor>(true));
    XPathExpressionPtr<string_type> nt(new NumericValue<string_type, string_adaptor>(1.0));
    XPathExpressionPtr<string_type> bf(new BoolValue<string_type, string_adaptor>(false));
    XPathExpressionPtr<string_type> nf(new NumericValue<string_type, string_adaptor>(0.0));

    assertTrue((impl::areEqual<string_type, string_adaptor>(bt->evaluate(dummy_), (nt->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(nt->evaluate(dummy_), (bt->evaluate(dummy_)))));

    assertTrue((impl::areEqual<string_type, string_adaptor>(bf->evaluate(dummy_), (nf->evaluate(dummy_)))));
    assertTrue((impl::areEqual<string_type, string_adaptor>(nf->evaluate(dummy_), (bf->evaluate(dummy_)))));
  } // test10

  void test11()
  {
    using namespace Arabica::XPath;
    XPathExpressionPtr<string_type> nt(new NumericValue<string_type, string_adaptor>(1.0));
    XPathValuePtr<string_type> ns = nt->evaluate(dummy_);

    assertTrue((impl::areEqual<string_type, string_adaptor>(ns, (nt->evaluate(dummy_)))));
  } // test11
}; // ValueTest

template<class string_type, class string_adaptor>
TestSuite* ValueTest_suite()
{
  TestSuite *suiteOfTests = new TestSuite;

  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test1", &ValueTest<string_type, string_adaptor>::test1));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test2", &ValueTest<string_type, string_adaptor>::test2));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test3", &ValueTest<string_type, string_adaptor>::test3));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test4", &ValueTest<string_type, string_adaptor>::test4));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test5", &ValueTest<string_type, string_adaptor>::test5));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test6", &ValueTest<string_type, string_adaptor>::test6));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test7", &ValueTest<string_type, string_adaptor>::test7));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test8", &ValueTest<string_type, string_adaptor>::test8));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test9", &ValueTest<string_type, string_adaptor>::test9));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test10", &ValueTest<string_type, string_adaptor>::test10));
  suiteOfTests->addTest(new TestCaller<ValueTest<string_type, string_adaptor> >("test11", &ValueTest<string_type, string_adaptor>::test11));

  return suiteOfTests;
} // ValueTest_suite

#endif
