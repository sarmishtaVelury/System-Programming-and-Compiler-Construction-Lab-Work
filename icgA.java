import java.util.*;
import java.io.*;

class icgA
{
	static void printS(String exp)
	{
		char t = 't';
		int tc = 1;
		//System.out.println(t);
		Stack<Character> stack = new Stack<>();
		for(int i = 0;i < exp.length();i++ )
		{
			//System.out.println(t);
			char c = exp.charAt(i);
			if(Character.isLetterOrDigit(c))
				stack.push(c);
			else 
			{

				if(stack.peek() != t)
				{	
					System.out.println(stack.peek());
					char op1 = stack.peek();
					stack.pop();
					System.out.println(stack.peek());
					char op2 = stack.peek();
					stack.pop();
					stack.push('t');
					System.out.println("t"+(tc)+" = "+op2+c+op1);
					//stack.push('t');
					tc++;
				}
				else 
				{
					System.out.println(stack.peek());
					char op1 = stack.peek();
					stack.pop();
					System.out.println(stack.peek());
					char op2 = stack.peek();
					stack.pop();

					System.out.println("t"+(tc)+" = "+op2+c+op1+(tc-1));
					stack.push('t');
					tc++;
				}
			}

		}
	}
	static int prec(char c)
	{
		switch(c)
		{
			case '+':
			case '-':
				return 1;
			case '*':
			case '/':
				return 2;
			case '^':
				return 3;
			case '=':
				return 0;
		}
		return -1;
	}

	static String infixToPostfix(String exp)
	{
		String result = new String("");
		Stack<Character> stack = new Stack<>();
		for(int i=0;i<exp.length();i++)
		{	
			char c = exp.charAt(i);
			if(Character.isLetterOrDigit(c))
				result += c;
			else if(c == '(')
				stack.push(c);
			else if(c == ')')
			{
				while(!stack.isEmpty() && stack.peek()!='(')
					result += stack.pop();

				if (!stack.isEmpty() && stack.peek() != '(')
                    return "Invalid Expression";                
                else
                    stack.pop();
			}
			else
			{
				while(!stack.isEmpty()&&prec(c) <= prec(stack.peek()))
					result += stack.pop();
				stack.push(c);
			}


		}
		while(!stack.isEmpty())
			result += stack.pop();

		return result; 
	}
	public static void main(String[] args) {
		System.out.println("Enter the Expression:");
		Scanner sc = new Scanner(System.in);
		String exp = sc.next();
		String result = infixToPostfix(exp);
		System.out.println(result);
		printS(result);

	}
}