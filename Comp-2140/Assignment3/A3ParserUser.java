import java.io.*;
class A3ParserUser {
    public static void main(String[] args){
	try {
	File inputFile = new File ("A3_1.tiny");
        A3Parser parser = new A3Parser(new A3Scanner(new FileInputStream(inputFile)));
        Integer result = (Integer)parser.debug_parse().value;
	    System.out.println("result is " + result);
        } catch (Exception e) {
	        e.printStackTrace();
        }
    }
}
