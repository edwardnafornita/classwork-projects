public class BalancedBrackets {

    public static boolean BracketMatch(String str, int n) throws Exception {
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == '(' || str.charAt(i) == '[' || str.charAt(i) == '{') {
                stack.push(str.charAt(i));
            } else if (str.charAt(i) == ')' || str.charAt(i) == ']' || str.charAt(i) == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                else {
                    switch(stack.pop()) {
                        case '(':
                            if (str.charAt(i) != ')') {
                                return false;
                            }
                            break;
                        case '[':
                            if (str.charAt(i) != ']') {
                                return false;
                            }
                            break;
                        case '{':
                            if (str.charAt(i) != '}') {
                                return false;
                            }
                            break;
                    }
                }
            }
        }

        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) throws Exception {
        String test1 = "({)}";
        String test2 = "((3*(9-(4*(6-5))))";
        String test3 = "{3*(2+[3-[4/[6/9]]]})";
        String test4 = "{2-{3*{6/[[[(((9-0)))]]]}}/7}";

        System.out.println(BracketMatch(test1, test1.length()));
        System.out.println(BracketMatch(test2, test2.length()));
        System.out.println(BracketMatch(test3, test3.length()));
        System.out.println(BracketMatch(test4, test4.length()));
    }
}