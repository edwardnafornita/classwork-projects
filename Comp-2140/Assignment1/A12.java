import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.*;
public class A12 {
    public static Set<String> getIdRegex(String filename) throws Exception {
        String[] keywordsArray = {"IF", "WRITE", "READ", "RETURN", "BEGIN","END", "MAIN", "INT", "REAL"};
        Set<String> keywords = new HashSet<String>();
        Set<String> identifiers = new HashSet<String>();
        for (String s : keywordsArray) keywords.add(s);
        FileReader reader = new FileReader(filename);
        BufferedReader br = new BufferedReader(reader);
        String line;
        Pattern idPattern = Pattern.compile("[a-zA-Z][a-zA-Z0-9]*");
        Pattern quotedStringPattern = Pattern.compile("\"[^\"]*\"");
        while ((line = br.readLine()) != null) {
            Matcher m_quotedString = quotedStringPattern.matcher(line);
            String lineWithoutQuotedStrings = m_quotedString.replaceAll("");
            Matcher m = idPattern.matcher(lineWithoutQuotedStrings);
            while (m.find()) {
                String id = line.substring(m.start(), m.end());
                if (!keywords.contains(id)) identifiers.add(id);
            }
        }
        br.close();
        return identifiers;
    }
    public static void main(String[] args) throws Exception {
        Set<String> ids = getIdRegex(args[0]);
        // for (String id : ids) System.out.println(id);
        System.out.println(ids.size());
    }
}
