import java.util.regex.*;
public class RegexTest {
    public static void main(String args[]) {
        String pattern = "\\d{4}-(0?[1-9]|1[012])-\\d{2}";
        String text = "final exam 2008-04-22, or 2008-4-22, but not 2008-22-04";
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(text);
        while (m.find()) {
            System.out.println("valid date:"+text.substring(m.start(), m.end()));
        }
    }
}