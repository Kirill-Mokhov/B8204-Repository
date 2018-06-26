using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using PostfixNotation;

namespace TestOPZ
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            PostfixNotationExpression test1 = new PostfixNotationExpression();
            string str1 = "2+(2-1)*1/1";
            Assert.AreEqual(3, test1.result(str1));
        }

        [TestMethod]
        public void TestMethod2()
        {
            PostfixNotationExpression test2 = new PostfixNotationExpression();
            string str2 = "2+2";
            string resStr = "22+";
            string[] postStr = test2.ConvertToPostfixNotation(str2);
            string outp = String.Join("", postStr);
            Assert.IsTrue(resStr.Equals(outp));
        }

        [TestMethod]
        public void TestMethod3()
        {
            PostfixNotationExpression test3 = new PostfixNotationExpression();
            try
            {
                string str3 = "2/0";
                test3.result(str3);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.GetType());
            }
        }
    }
}
