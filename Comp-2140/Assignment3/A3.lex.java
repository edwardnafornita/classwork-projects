import java_cup.runtime.*;


class A3Scanner implements java_cup.runtime.Scanner {
	private final int YY_BUFFER_SIZE = 512;
	private final int YY_F = -1;
	private final int YY_NO_STATE = -1;
	private final int YY_NOT_ACCEPT = 0;
	private final int YY_START = 1;
	private final int YY_END = 2;
	private final int YY_NO_ANCHOR = 4;
	private final int YY_BOL = 128;
	private final int YY_EOF = 129;
	private java.io.BufferedReader yy_reader;
	private int yy_buffer_index;
	private int yy_buffer_read;
	private int yy_buffer_start;
	private int yy_buffer_end;
	private char yy_buffer[];
	private boolean yy_at_bol;
	private int yy_lexical_state;

	A3Scanner (java.io.Reader reader) {
		this ();
		if (null == reader) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(reader);
	}

	A3Scanner (java.io.InputStream instream) {
		this ();
		if (null == instream) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(new java.io.InputStreamReader(instream));
	}

	private A3Scanner () {
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
		33
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
		/* 10 */ YY_NO_ANCHOR,
		/* 11 */ YY_NO_ANCHOR,
		/* 12 */ YY_NO_ANCHOR,
		/* 13 */ YY_NO_ANCHOR,
		/* 14 */ YY_NO_ANCHOR,
		/* 15 */ YY_NO_ANCHOR,
		/* 16 */ YY_NO_ANCHOR,
		/* 17 */ YY_NO_ANCHOR,
		/* 18 */ YY_NO_ANCHOR,
		/* 19 */ YY_NO_ANCHOR,
		/* 20 */ YY_NO_ANCHOR,
		/* 21 */ YY_NO_ANCHOR,
		/* 22 */ YY_NO_ANCHOR,
		/* 23 */ YY_NO_ANCHOR,
		/* 24 */ YY_NO_ANCHOR,
		/* 25 */ YY_NO_ANCHOR,
		/* 26 */ YY_NO_ANCHOR,
		/* 27 */ YY_NOT_ACCEPT,
		/* 28 */ YY_NO_ANCHOR,
		/* 29 */ YY_NO_ANCHOR,
		/* 30 */ YY_NOT_ACCEPT,
		/* 31 */ YY_NO_ANCHOR,
		/* 32 */ YY_NO_ANCHOR,
		/* 33 */ YY_NOT_ACCEPT,
		/* 34 */ YY_NO_ANCHOR,
		/* 35 */ YY_NO_ANCHOR,
		/* 36 */ YY_NOT_ACCEPT,
		/* 37 */ YY_NO_ANCHOR,
		/* 38 */ YY_NO_ANCHOR,
		/* 39 */ YY_NO_ANCHOR,
		/* 40 */ YY_NO_ANCHOR,
		/* 41 */ YY_NO_ANCHOR,
		/* 42 */ YY_NO_ANCHOR,
		/* 43 */ YY_NO_ANCHOR,
		/* 44 */ YY_NO_ANCHOR,
		/* 45 */ YY_NO_ANCHOR,
		/* 46 */ YY_NO_ANCHOR,
		/* 47 */ YY_NO_ANCHOR,
		/* 48 */ YY_NO_ANCHOR,
		/* 49 */ YY_NO_ANCHOR,
		/* 50 */ YY_NO_ANCHOR,
		/* 51 */ YY_NO_ANCHOR,
		/* 52 */ YY_NO_ANCHOR,
		/* 53 */ YY_NO_ANCHOR,
		/* 54 */ YY_NO_ANCHOR,
		/* 55 */ YY_NO_ANCHOR,
		/* 56 */ YY_NO_ANCHOR,
		/* 57 */ YY_NO_ANCHOR,
		/* 58 */ YY_NO_ANCHOR,
		/* 59 */ YY_NO_ANCHOR,
		/* 60 */ YY_NO_ANCHOR,
		/* 61 */ YY_NO_ANCHOR,
		/* 62 */ YY_NO_ANCHOR
	};
	private int yy_cmap[] = unpackFromString(1,130,
"6:33,25,5,6,29:2,6:2,7,8,2,3,27,4,6,1,30:10,28,26,6,24,6:2,29,14,21,31,15,1" +
"3,16,22,31,11,31:2,17,23,20,31:3,10,18,12,19,31,9,31:3,6:6,31:26,6:5,0:2")[0];

	private int yy_rmap[] = unpackFromString(1,63,
"0,1,2,1:3,3,1:2,4,1:2,5,1,6,1:3,6:8,1,7,1,8,3,9,10,11,12,13,14,15,16,17,18," +
"19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,6,38,39")[0];

	private int yy_nxt[][] = unpackFromString(40,32,
"1,2,3,4,5,6,28,7,8,9,53,29,60,45,60:4,61,60:2,62,60,54,31:2,10,11,34,60,12," +
"60,-1:34,27,-1:30,30:4,13,30:26,-1:9,60,55,60:13,-1:6,60:2,-1:30,12,-1:10,6" +
"0:15,-1:6,60:2,-1:2,17,-1:38,60:7,14,60:3,32,60:3,-1:6,60:2,-1:24,15,-1:16," +
"60:3,18,60:11,-1:6,60:2,1,28,37,28:29,-1:24,16,-1:16,60:6,19,60:8,-1:6,60:2" +
",-1,26,-1:32,36,-1:38,60:6,20,60,18,60:6,-1:6,60:2,-1:9,60:4,21,60:10,-1:6," +
"60:2,-1:9,60:11,22,60:3,-1:6,60:2,-1:9,60:4,23,60:10,-1:6,60:2,-1:9,60:11,2" +
"4,60:3,-1:6,60:2,-1:9,60:11,25,60:3,-1:6,60:2,-1:9,60:13,18,60,-1:6,60:2,-1" +
":9,60:8,47,60:2,35,60:3,-1:6,60:2,-1:9,60:3,58,60,38,60:9,-1:6,60:2,-1:9,60" +
":9,39,60:5,-1:6,60:2,-1:9,60:2,40,60:12,-1:6,60:2,-1:9,60:3,41,60:11,-1:6,6" +
"0:2,-1:9,60:2,42,60:12,-1:6,60:2,-1:9,60,43,60:13,-1:6,60:2,-1:9,60:11,44,6" +
"0:3,-1:6,60:2,-1:9,60:4,46,60:10,-1:6,60:2,-1:9,60:5,48,60:9,-1:6,60:2,-1:9" +
",60:2,49,60:12,-1:6,60:2,-1:9,60,59,60:13,-1:6,60:2,-1:9,60:13,50,60,-1:6,6" +
"0:2,-1:9,60:10,51,60:4,-1:6,60:2,-1:9,60:2,52,60:12,-1:6,60:2,-1:9,60:3,56," +
"60:11,-1:6,60:2,-1:9,60:4,57,60:10,-1:6,60:2");

	public Symbol next_token ()
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
				return null;
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
						{System.out.println(yytext()); return new Symbol(A3Symbol.DIVIDE); }
					case -3:
						break;
					case 3:
						{System.out.println(yytext()); return new Symbol(A3Symbol.TIMES); }
					case -4:
						break;
					case 4:
						{ System.out.println(yytext()); return new Symbol(A3Symbol.PLUS); }
					case -5:
						break;
					case 5:
						{System.out.println(yytext()); return new Symbol(A3Symbol.MINUS); }
					case -6:
						break;
					case 6:
						{}
					case -7:
						break;
					case 7:
						{System.out.println(yytext()); return new Symbol(A3Symbol.LPAREN); }
					case -8:
						break;
					case 8:
						{System.out.println(yytext()); return new Symbol(A3Symbol.RPAREN); }
					case -9:
						break;
					case 9:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -10:
						break;
					case 10:
						{System.out.println(yytext()); return new Symbol(A3Symbol.SEMICOLON); }
					case -11:
						break;
					case 11:
						{System.out.println(yytext()); return new Symbol(A3Symbol.COMMA); }
					case -12:
						break;
					case 12:
						{System.out.println(yytext()); return new Symbol(A3Symbol.NUMBER); }
					case -13:
						break;
					case 13:
						{System.out.println(yytext()); return new Symbol(A3Symbol.QUOTEDSTRING); }
					case -14:
						break;
					case 14:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IF); }
					case -15:
						break;
					case 15:
						{System.out.println(yytext()); return new Symbol(A3Symbol.CONDITIONAL); }
					case -16:
						break;
					case 16:
						{System.out.println(yytext()); return new Symbol(A3Symbol.ASSIGN); }
					case -17:
						break;
					case 17:
						{System.out.println(yytext()); yybegin(COMMENT); }
					case -18:
						break;
					case 18:
						{System.out.println(yytext()); return new Symbol(A3Symbol.TYPEDEFS); }
					case -19:
						break;
					case 19:
						{System.out.println(yytext()); return new Symbol(A3Symbol.END); }
					case -20:
						break;
					case 20:
						{System.out.println(yytext()); return new Symbol(A3Symbol.READ); }
					case -21:
						break;
					case 21:
						{System.out.println(yytext()); return new Symbol(A3Symbol.ELSE); }
					case -22:
						break;
					case 22:
						{System.out.println(yytext()); return new Symbol(A3Symbol.MAIN); }
					case -23:
						break;
					case 23:
						{System.out.println(yytext()); return new Symbol(A3Symbol.WRITE); }
					case -24:
						break;
					case 24:
						{System.out.println(yytext()); return new Symbol(A3Symbol.BEGIN); }
					case -25:
						break;
					case 25:
						{System.out.println(yytext()); return new Symbol(A3Symbol.RETURN); }
					case -26:
						break;
					case 26:
						{System.out.println(yytext()); yybegin(YYINITIAL); }
					case -27:
						break;
					case 28:
						{}
					case -28:
						break;
					case 29:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -29:
						break;
					case 31:
						{}
					case -30:
						break;
					case 32:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -31:
						break;
					case 34:
						{}
					case -32:
						break;
					case 35:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -33:
						break;
					case 37:
						{}
					case -34:
						break;
					case 38:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -35:
						break;
					case 39:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -36:
						break;
					case 40:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -37:
						break;
					case 41:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -38:
						break;
					case 42:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -39:
						break;
					case 43:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -40:
						break;
					case 44:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -41:
						break;
					case 45:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -42:
						break;
					case 46:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -43:
						break;
					case 47:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -44:
						break;
					case 48:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -45:
						break;
					case 49:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -46:
						break;
					case 50:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -47:
						break;
					case 51:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -48:
						break;
					case 52:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -49:
						break;
					case 53:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -50:
						break;
					case 54:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -51:
						break;
					case 55:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -52:
						break;
					case 56:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -53:
						break;
					case 57:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -54:
						break;
					case 58:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -55:
						break;
					case 59:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -56:
						break;
					case 60:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -57:
						break;
					case 61:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -58:
						break;
					case 62:
						{System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
					case -59:
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
