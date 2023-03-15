import java.io.*;


class A3 {
	private final int YY_BUFFER_SIZE = 512;
	private final int YY_F = -1;
	private final int YY_NO_STATE = -1;
	private final int YY_NOT_ACCEPT = 0;
	private final int YY_START = 1;
	private final int YY_END = 2;
	private final int YY_NO_ANCHOR = 4;
	private final int YY_BOL = 128;
	private final int YY_EOF = 129;
	public final int YYEOF = -1;
    
      static int identifierCount = 0,commentCount = 0,keywordCount = 0,numberCount = 0,quotedStringCount = 0;
      public static void main(String argv[]) throws java.io.IOException {
	  A3 yy = new A3(new FileInputStream(new File("A3.input")));
	  while (yy.yylex()>=0){}
           FileWriter writer = new FileWriter(new File("A3.output"));
           writer.write("identifiers: " + identifierCount + "\nkeywords: " + keywordCount+"\nnumbers: " + numberCount+"\ncomments: " + commentCount+"\nquotedString: " + quotedStringCount);
           writer.close();
      }
	private java.io.BufferedReader yy_reader;
	private int yy_buffer_index;
	private int yy_buffer_read;
	private int yy_buffer_start;
	private int yy_buffer_end;
	private char yy_buffer[];
	private boolean yy_at_bol;
	private int yy_lexical_state;

	A3 (java.io.Reader reader) {
		this ();
		if (null == reader) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(reader);
	}

	A3 (java.io.InputStream instream) {
		this ();
		if (null == instream) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(new java.io.InputStreamReader(instream));
	}

	private A3 () {
		yy_buffer = new char[YY_BUFFER_SIZE];
		yy_buffer_read = 0;
		yy_buffer_index = 0;
		yy_buffer_start = 0;
		yy_buffer_end = 0;
		yy_at_bol = true;
		yy_lexical_state = YYINITIAL;
	}

	private boolean yy_eof_done = false;
	private final int YYINITIAL = 0;
	private final int COMMENT = 1;
	private final int yy_state_dtrans[] = {
		0,
		21
	};
	private void yybegin (int state) {
		yy_lexical_state = state;
	}
	private int yy_advance ()
		throws java.io.IOException {
		int next_read;
		int i;
		int j;

		if (yy_buffer_index < yy_buffer_read) {
			return yy_buffer[yy_buffer_index++];
		}

		if (0 != yy_buffer_start) {
			i = yy_buffer_start;
			j = 0;
			while (i < yy_buffer_read) {
				yy_buffer[j] = yy_buffer[i];
				++i;
				++j;
			}
			yy_buffer_end = yy_buffer_end - yy_buffer_start;
			yy_buffer_start = 0;
			yy_buffer_read = j;
			yy_buffer_index = j;
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}

		while (yy_buffer_index >= yy_buffer_read) {
			if (yy_buffer_index >= yy_buffer.length) {
				yy_buffer = yy_double(yy_buffer);
			}
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}
		return yy_buffer[yy_buffer_index++];
	}
	private void yy_move_end () {
		if (yy_buffer_end > yy_buffer_start &&
		    '\n' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
		if (yy_buffer_end > yy_buffer_start &&
		    '\r' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
	}
	private boolean yy_last_was_cr=false;
	private void yy_mark_start () {
		yy_buffer_start = yy_buffer_index;
	}
	private void yy_mark_end () {
		yy_buffer_end = yy_buffer_index;
	}
	private void yy_to_mark () {
		yy_buffer_index = yy_buffer_end;
		yy_at_bol = (yy_buffer_end > yy_buffer_start) &&
		            ('\r' == yy_buffer[yy_buffer_end-1] ||
		             '\n' == yy_buffer[yy_buffer_end-1] ||
		             2028/*LS*/ == yy_buffer[yy_buffer_end-1] ||
		             2029/*PS*/ == yy_buffer[yy_buffer_end-1]);
	}
	private java.lang.String yytext () {
		return (new java.lang.String(yy_buffer,
			yy_buffer_start,
			yy_buffer_end - yy_buffer_start));
	}
	private int yylength () {
		return yy_buffer_end - yy_buffer_start;
	}
	private char[] yy_double (char buf[]) {
		int i;
		char newbuf[];
		newbuf = new char[2*buf.length];
		for (i = 0; i < buf.length; ++i) {
			newbuf[i] = buf[i];
		}
		return newbuf;
	}
	private final int YY_E_INTERNAL = 0;
	private final int YY_E_MATCH = 1;
	private java.lang.String yy_error_string[] = {
		"Error: Internal error.\n",
		"Error: Unmatched input.\n"
	};
	private void yy_error (int code,boolean fatal) {
		java.lang.System.out.print(yy_error_string[code]);
		java.lang.System.out.flush();
		if (fatal) {
			throw new Error("Fatal Error.\n");
		}
	}
	private int[][] unpackFromString(int size1, int size2, String st) {
		int colonIndex = -1;
		String lengthString;
		int sequenceLength = 0;
		int sequenceInteger = 0;

		int commaIndex;
		String workString;

		int res[][] = new int[size1][size2];
		for (int i= 0; i < size1; i++) {
			for (int j= 0; j < size2; j++) {
				if (sequenceLength != 0) {
					res[i][j] = sequenceInteger;
					sequenceLength--;
					continue;
				}
				commaIndex = st.indexOf(',');
				workString = (commaIndex==-1) ? st :
					st.substring(0, commaIndex);
				st = st.substring(commaIndex+1);
				colonIndex = workString.indexOf(':');
				if (colonIndex == -1) {
					res[i][j]=Integer.parseInt(workString);
					continue;
				}
				lengthString =
					workString.substring(colonIndex+1);
				sequenceLength=Integer.parseInt(lengthString);
				workString=workString.substring(0,colonIndex);
				sequenceInteger=Integer.parseInt(workString);
				res[i][j] = sequenceInteger;
				sequenceLength--;
			}
		}
		return res;
	}
	private int yy_acpt[] = {
		/* 0 */ YY_NOT_ACCEPT,
		/* 1 */ YY_NO_ANCHOR,
		/* 2 */ YY_NO_ANCHOR,
		/* 3 */ YY_NO_ANCHOR,
		/* 4 */ YY_NO_ANCHOR,
		/* 5 */ YY_NO_ANCHOR,
		/* 6 */ YY_NO_ANCHOR,
		/* 7 */ YY_NO_ANCHOR,
		/* 8 */ YY_NO_ANCHOR,
		/* 9 */ YY_NO_ANCHOR,
		/* 10 */ YY_NOT_ACCEPT,
		/* 11 */ YY_NO_ANCHOR,
		/* 12 */ YY_NO_ANCHOR,
		/* 13 */ YY_NO_ANCHOR,
		/* 14 */ YY_NO_ANCHOR,
		/* 15 */ YY_NOT_ACCEPT,
		/* 16 */ YY_NO_ANCHOR,
		/* 17 */ YY_NO_ANCHOR,
		/* 18 */ YY_NO_ANCHOR,
		/* 19 */ YY_NOT_ACCEPT,
		/* 20 */ YY_NO_ANCHOR,
		/* 21 */ YY_NOT_ACCEPT,
		/* 22 */ YY_NO_ANCHOR,
		/* 23 */ YY_NOT_ACCEPT,
		/* 24 */ YY_NO_ANCHOR,
		/* 25 */ YY_NO_ANCHOR,
		/* 26 */ YY_NO_ANCHOR,
		/* 27 */ YY_NO_ANCHOR,
		/* 28 */ YY_NO_ANCHOR,
		/* 29 */ YY_NO_ANCHOR,
		/* 30 */ YY_NO_ANCHOR,
		/* 31 */ YY_NO_ANCHOR,
		/* 32 */ YY_NO_ANCHOR,
		/* 33 */ YY_NO_ANCHOR,
		/* 34 */ YY_NO_ANCHOR,
		/* 35 */ YY_NO_ANCHOR,
		/* 36 */ YY_NO_ANCHOR,
		/* 37 */ YY_NO_ANCHOR,
		/* 38 */ YY_NO_ANCHOR,
		/* 39 */ YY_NO_ANCHOR,
		/* 40 */ YY_NO_ANCHOR,
		/* 41 */ YY_NO_ANCHOR,
		/* 42 */ YY_NO_ANCHOR,
		/* 43 */ YY_NO_ANCHOR
	};
	private int yy_cmap[] = unpackFromString(1,130,
"25:10,20,25:2,20,25:20,19,25:7,22,25:3,2,21,1:10,25:7,8,15,18,9,7,10,16,18," +
"5,18:2,11,17,14,18:3,4,12,6,13,18,3,18:3,25,23,25:4,18:13,24,18:12,25:5,0:2")[0];

	private int yy_rmap[] = unpackFromString(1,44,
"0,1,2,1,3,4,1:4,5:2,6,7,8,6,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24," +
"25,26,27,28,29,30,31,32,33,4,34,35")[0];

	private int yy_nxt[][] = unpackFromString(36,26,
"1,2,3,4,34,13,41,27,41:4,42,41:2,43,41,35,41,12,3,16,3:2,41,3,-1:27,2,10,-1" +
":24,41,-1,41,36,41:14,-1:5,41,-1:2,41,-1,41:16,-1:5,41,-1:2,11,-1:25,15:18," +
"6,15:6,-1,41,-1,41:7,5,41:3,17,41:4,-1:5,41,-1:23,23,-1:25,19,-1:4,41,-1,41" +
":3,5,41:12,-1:5,41,-1:25,8,-1:23,7,-1:4,41,-1,41:6,5,41:9,-1:5,41,-1,1,8:19" +
",3,8,14,18,8:2,-1,41,-1,41:6,5,41,5,41:7,-1:5,41,-1:22,9,-1:5,41,-1,41:4,5," +
"41:11,-1:5,41,-1:2,41,-1,41:11,5,41:4,-1:5,41,-1:2,41,-1,41:13,5,41:2,-1:5," +
"41,-1:2,41,-1,41:8,29,41:2,20,41:4,-1:5,41,-1:2,41,-1,41:3,39,41,22,41:10,-" +
"1:5,41,-1:2,41,-1,41:9,24,41:6,-1:5,41,-1:2,41,-1,41:2,25,41:13,-1:5,41,-1:" +
"2,41,-1,41:3,24,41:12,-1:5,41,-1:2,41,-1,41,25,41:14,-1:5,41,-1:2,41,-1,41:" +
"11,26,41:4,-1:5,41,-1:2,41,-1,41:4,28,41:11,-1:5,41,-1:2,41,-1,41:5,30,41:1" +
"0,-1:5,41,-1:2,41,-1,41:2,31,41:13,-1:5,41,-1:2,41,-1,41,40,41:14,-1:5,41,-" +
"1:2,41,-1,41:13,30,41:2,-1:5,41,-1:2,41,-1,41:10,32,41:5,-1:5,41,-1:2,41,-1" +
",41:2,33,41:13,-1:5,41,-1:2,41,-1,41:3,37,41:12,-1:5,41,-1:2,41,-1,41:4,38," +
"41:11,-1:5,41,-1");

	public int yylex ()
		throws java.io.IOException {
		int yy_lookahead;
		int yy_anchor = YY_NO_ANCHOR;
		int yy_state = yy_state_dtrans[yy_lexical_state];
		int yy_next_state = YY_NO_STATE;
		int yy_last_accept_state = YY_NO_STATE;
		boolean yy_initial = true;
		int yy_this_accept;

		yy_mark_start();
		yy_this_accept = yy_acpt[yy_state];
		if (YY_NOT_ACCEPT != yy_this_accept) {
			yy_last_accept_state = yy_state;
			yy_mark_end();
		}
		while (true) {
			if (yy_initial && yy_at_bol) yy_lookahead = YY_BOL;
			else yy_lookahead = yy_advance();
			yy_next_state = YY_F;
			yy_next_state = yy_nxt[yy_rmap[yy_state]][yy_cmap[yy_lookahead]];
			if (YY_EOF == yy_lookahead && true == yy_initial) {
				return YYEOF;
			}
			if (YY_F != yy_next_state) {
				yy_state = yy_next_state;
				yy_initial = false;
				yy_this_accept = yy_acpt[yy_state];
				if (YY_NOT_ACCEPT != yy_this_accept) {
					yy_last_accept_state = yy_state;
					yy_mark_end();
				}
			}
			else {
				if (YY_NO_STATE == yy_last_accept_state) {
					throw (new Error("Lexical Error: Unmatched Input."));
				}
				else {
					yy_anchor = yy_acpt[yy_last_accept_state];
					if (0 != (YY_END & yy_anchor)) {
						yy_move_end();
					}
					yy_to_mark();
					switch (yy_last_accept_state) {
					case 1:
						
					case -2:
						break;
					case 2:
						{numberCount++;}
					case -3:
						break;
					case 3:
						{}
					case -4:
						break;
					case 4:
						{identifierCount++;}
					case -5:
						break;
					case 5:
						{keywordCount++;}
					case -6:
						break;
					case 6:
						{quotedStringCount++;}
					case -7:
						break;
					case 7:
						{yybegin(COMMENT);commentCount++;}
					case -8:
						break;
					case 8:
						{}
					case -9:
						break;
					case 9:
						{yybegin(YYINITIAL);}
					case -10:
						break;
					case 11:
						{numberCount++;}
					case -11:
						break;
					case 12:
						{}
					case -12:
						break;
					case 13:
						{identifierCount++;}
					case -13:
						break;
					case 14:
						{}
					case -14:
						break;
					case 16:
						{}
					case -15:
						break;
					case 17:
						{identifierCount++;}
					case -16:
						break;
					case 18:
						{}
					case -17:
						break;
					case 20:
						{identifierCount++;}
					case -18:
						break;
					case 22:
						{identifierCount++;}
					case -19:
						break;
					case 24:
						{identifierCount++;}
					case -20:
						break;
					case 25:
						{identifierCount++;}
					case -21:
						break;
					case 26:
						{identifierCount++;}
					case -22:
						break;
					case 27:
						{identifierCount++;}
					case -23:
						break;
					case 28:
						{identifierCount++;}
					case -24:
						break;
					case 29:
						{identifierCount++;}
					case -25:
						break;
					case 30:
						{identifierCount++;}
					case -26:
						break;
					case 31:
						{identifierCount++;}
					case -27:
						break;
					case 32:
						{identifierCount++;}
					case -28:
						break;
					case 33:
						{identifierCount++;}
					case -29:
						break;
					case 34:
						{identifierCount++;}
					case -30:
						break;
					case 35:
						{identifierCount++;}
					case -31:
						break;
					case 36:
						{identifierCount++;}
					case -32:
						break;
					case 37:
						{identifierCount++;}
					case -33:
						break;
					case 38:
						{identifierCount++;}
					case -34:
						break;
					case 39:
						{identifierCount++;}
					case -35:
						break;
					case 40:
						{identifierCount++;}
					case -36:
						break;
					case 41:
						{identifierCount++;}
					case -37:
						break;
					case 42:
						{identifierCount++;}
					case -38:
						break;
					case 43:
						{identifierCount++;}
					case -39:
						break;
					default:
						yy_error(YY_E_INTERNAL,false);
					case -1:
					}
					yy_initial = true;
					yy_state = yy_state_dtrans[yy_lexical_state];
					yy_next_state = YY_NO_STATE;
					yy_last_accept_state = YY_NO_STATE;
					yy_mark_start();
					yy_this_accept = yy_acpt[yy_state];
					if (YY_NOT_ACCEPT != yy_this_accept) {
						yy_last_accept_state = yy_state;
						yy_mark_end();
					}
				}
			}
		}
	}
}
