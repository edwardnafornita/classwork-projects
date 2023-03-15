import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Set;
import java.util.HashSet;

public class A11 {
	//check whether the char is a letter
	static boolean isLetter(int character) {
		return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
	}

	// check whether the char is a letter or digit
	static boolean isLetterOrDigit(int character) {
		return isLetter(character) || (character >= '0' && character <= '9');
	}

	public static Set<String> getIdentifiers(String filename) throws Exception {
		String[] keywordsArray = {"IF", "WRITE", "READ", "RETURN", "BEGIN", "END", "MAIN", "INT", "REAL"};
		Set<String> keywords = new HashSet<String>();
		Set<String> identifiers = new HashSet<String>();
		for (String s : keywordsArray) {;
			keywords.add(s);
		}
		String state = "INIT"; // Initially it is in the INIT state. 

		StringBuilder code = new StringBuilder();
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line;
		while ((line = br.readLine()) != null) {
			code = code.append(line + '\n');
		} // read the text line by line.
		code = code.append('$'); //add a special symbol to indicate the end of file.  

		int len = code.length();
		String token = "";
		boolean isQuotedString = false;
		for (int i = 0; i < len; i++) { //look at the characters one by one
			char next_char = code.charAt(i);
			if (next_char == '"') {
				if (isQuotedString) {
					isQuotedString = false;
				} else {
					isQuotedString = true;
					continue;
				}
			}
			if (state.contentEquals("INIT")) {
				if (isLetter(next_char)) {
					state = "ID";  // go to the ID state
					token = token + next_char;
				} //ignore everything if it is not a letter
			} else if (state.equals("ID")) {
				if (isLetterOrDigit(next_char)) { //take letter or digit if it is in ID state
					token = token + next_char;
				} else { // end of ID state
					if (keywords.contains(token) || isQuotedString) {
						token = "";
						state = "INIT";
						isQuotedString = false;
						continue;
					} else {
						identifiers.add(token);
						token = "";
						state = "INIT";
					}
				}
			}
		}
		br.close();
		return identifiers;
	}

	public static void main(String[] args) throws Exception {
		Set<String> ids = getIdentifiers(args[0]);
		// System.out.println(ids);
		System.out.println(ids.size());
	}
}