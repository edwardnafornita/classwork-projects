public class CFL {
    public static String cflRecognizer(String str) throws Exception {
        Stack stack = new Stack();
        int strlen = str.length();
        int countZeros = 0, countOnes = 0;

        for (int i = 0; i < strlen; i++) {
            if (str.charAt(i) == '0' && countOnes == 0) {
                stack.push(str.charAt(i));
                countZeros++;
            } else if (str.charAt(i) == '1') {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
                countOnes++;
            }
        }
        
        if (stack.isEmpty() && countZeros == countOnes) {
            return "Yes";
        }
        else {
            return "No";
        }
    }

    public static void main(String[] args) throws Exception {
        // long startTime = System.nanoTime();
        String test1 = "01";
        String test2 = "000111";
        String test3 = "00000001111111";
        String test4 = "10";
        String test5 = "00";
        String test6 = "00111";
        String test7 = "0101";

        // String twoPower2 = "0011";
        // String twoPower3 = "00001111";
        // String twoPower4 = "0000000011111111";
        // String twoPower5 = "00000000000000001111111111111111";
        // String twoPower6 = "0000000000000000000000000000000011111111111111111111111111111111";

        System.out.println(cflRecognizer(test1));
        System.out.println(cflRecognizer(test2));
        System.out.println(cflRecognizer(test3));
        System.out.println(cflRecognizer(test4));
        System.out.println(cflRecognizer(test5));
        System.out.println(cflRecognizer(test6));
        System.out.println(cflRecognizer(test7));

        // System.out.println(cflRecognizer(twoPower2));
        // System.out.println(cflRecognizer(twoPower3));
        // System.out.println(cflRecognizer(twoPower4));
        // System.out.println(cflRecognizer(twoPower5));
        // System.out.println(cflRecognizer(twoPower6));
        // long endTime = System.nanoTime();
        // long totalTime = endTime - startTime;
        // System.out.println(totalTime);
    }
}
