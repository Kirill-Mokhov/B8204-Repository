using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PostfixNotation
{
    public class PostfixNotationExpression
    {
        public PostfixNotationExpression()
        {
            operators = new List<string>(standart_operators);
            
        }
        private List<string> operators;
        private List<string> standart_operators =
            new List<string>(new string[] { "(", ")", "+", "-", "*", "/", "^" });

        private IEnumerable<string> Separate(string input)
        {            
            int pos = 0;
            while (pos < input.Length)
            {
                string s = string.Empty + input[pos];
                if (!standart_operators.Contains(input[pos].ToString()))
                {
                    if (Char.IsDigit(input[pos]))
                        for (int i = pos + 1; i < input.Length &&
                            (Char.IsDigit(input[i]) || input[i] == ',' || input[i] == '.'); i++)
                            s += input[i];
                    else if (Char.IsLetter(input[pos]))
                        for (int i = pos + 1; i < input.Length &&
                            (Char.IsLetter(input[i]) || Char.IsDigit(input[i])); i++)
                            s += input[i];
                }
                yield return s;
                pos += s.Length;
            }
        }
        private byte GetPriority(string s)
        {
            switch (s)
            {
                case "(":
                case ")":
                    return 0;
                case "+":
                case "-":
                    return 1;
                case "*":
                case "/":
                    return 2;
                case "^":
                    return 3;
                default:
                    return 4;
            }
        }

        public string[] ConvertToPostfixNotation(string input)
        {
            List<string> outputSeparated = new List<string>();
            Stack<string> stack = new Stack<string>();
            foreach (string c in Separate(input))
            {
                if (operators.Contains(c))
                {
                    if (stack.Count > 0 && !c.Equals("("))
                    {
                        if (c.Equals(")"))
                        {
                            string s = stack.Pop();
                            while (s != "(")
                            {
                                outputSeparated.Add(s);
                                s = stack.Pop();
                            }
                        }
                        else if (GetPriority(c) > GetPriority(stack.Peek()))
                            stack.Push(c);
                        else
                        {
                            while (stack.Count > 0 && GetPriority(c) <= GetPriority(stack.Peek()))
                                outputSeparated.Add(stack.Pop());
                            stack.Push(c);
                        }
                    }
                    else
                        stack.Push(c);
                }
                else
                    outputSeparated.Add(c);
            }
            if (stack.Count > 0)
                foreach (string c in stack)
                    outputSeparated.Add(c);

            return outputSeparated.ToArray();
        }
        public decimal result(string input)
        {
            Stack<string> stack = new Stack<string>();
            Queue<string> queue = new Queue<string>(ConvertToPostfixNotation(input));
            string str = queue.Dequeue();
            while (queue.Count >= 0)
            {
                if (!operators.Contains(str))
                {
                    stack.Push(str);
                    str = queue.Dequeue();
                }
                else
                {
                    decimal summ = 0;
                    try
                    {
                        
                        switch (str)
                        {

                            case "+":
                                {
                                    decimal a = Convert.ToDecimal(stack.Pop());
                                    decimal b = Convert.ToDecimal(stack.Pop());
                                    summ = a + b;
                                    break;
                                }
                            case "-":
                                {
                                    decimal a = Convert.ToDecimal(stack.Pop());
                                    decimal b = Convert.ToDecimal(stack.Pop());
                                    summ=b-a;
                                    break;
                                }
                            case "*":
                                {
                                    decimal a = Convert.ToDecimal(stack.Pop());
                                    decimal b = Convert.ToDecimal(stack.Pop());
                                    summ = b * a;
                                    break;
                                }
                            case "/":
                                {
                                    decimal a = Convert.ToDecimal(stack.Pop());
                                    decimal b = Convert.ToDecimal(stack.Pop());
                                    summ = b / a;
                                    break;
                                }
                            case "^":
                                {
                                    decimal a = Convert.ToDecimal(stack.Pop());
                                    decimal b = Convert.ToDecimal(stack.Pop());
                                    summ = Convert.ToDecimal(Math.Pow(Convert.ToDouble(b), Convert.ToDouble(a)));
                                    break;
                                }
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                        Console.WriteLine(ex.GetType());
                        //Console.WriteLine(ex.StackTrace);
                    }
                    stack.Push(summ.ToString());
                    if (queue.Count > 0)
                        str = queue.Dequeue();
                    else
                        break;
                }
                
            }
            return Convert.ToDecimal(stack.Pop());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int ind = 0;
            PostfixNotationExpression pse = new PostfixNotationExpression();
            while (7 != ind) {
                try {
                    switch (ind) {
                        case 0:
                            {
                                string str = "2/0";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 1:
                            {
                                string str = "(2+2";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 2:
                            {
                                string str = "2+a";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 3:
                            {
                                string str = "";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 4:
                            {
                                string str = "asdf";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 5:
                            {
                                string str = "(2*2)+((2*2))";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                        case 6:
                            {
                                string str = "(2*2)+((2*2))";
                                pse.ConvertToPostfixNotation(str);
                                Console.WriteLine(pse.result(str));
                                break;
                            }
                    }
            }
                catch (Exception ex)
            {
                    Console.WriteLine(ex.GetType());
            }
                Console.WriteLine();
                Console.WriteLine();
                ind++;
            }
            Console.ReadKey();
        }
    }

}