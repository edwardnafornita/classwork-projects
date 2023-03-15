import java_cup.runtime.*;

%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A3Scanner
%state COMMENT

%%
<YYINITIAL>"/**" {System.out.println(yytext()); yybegin(COMMENT); }
<COMMENT>"**/" {System.out.println(yytext()); yybegin(YYINITIAL); }
<YYINITIAL>"+" { System.out.println(yytext()); return new Symbol(A3Symbol.PLUS); }
<YYINITIAL>"-" {System.out.println(yytext()); return new Symbol(A3Symbol.MINUS); }
<YYINITIAL>"*" {System.out.println(yytext()); return new Symbol(A3Symbol.TIMES); }
<YYINITIAL>"/" {System.out.println(yytext()); return new Symbol(A3Symbol.DIVIDE); }
<YYINITIAL>\"[^\"]*\" {System.out.println(yytext()); return new Symbol(A3Symbol.QUOTEDSTRING); }
<YYINITIAL>"(" {System.out.println(yytext()); return new Symbol(A3Symbol.LPAREN); }
<YYINITIAL>")" {System.out.println(yytext()); return new Symbol(A3Symbol.RPAREN); }
<YYINITIAL>"WRITE" {System.out.println(yytext()); return new Symbol(A3Symbol.WRITE); }
<YYINITIAL>"READ" {System.out.println(yytext()); return new Symbol(A3Symbol.READ); }
<YYINITIAL>"IF" {System.out.println(yytext()); return new Symbol(A3Symbol.IF); }
<YYINITIAL>"ELSE" {System.out.println(yytext()); return new Symbol(A3Symbol.ELSE); }
<YYINITIAL>"RETURN" {System.out.println(yytext()); return new Symbol(A3Symbol.RETURN); }
<YYINITIAL>"BEGIN" {System.out.println(yytext()); return new Symbol(A3Symbol.BEGIN); }
<YYINITIAL>"END" {System.out.println(yytext()); return new Symbol(A3Symbol.END); }
<YYINITIAL>"MAIN" {System.out.println(yytext()); return new Symbol(A3Symbol.MAIN); }
<YYINITIAL>"=="|"!=" {System.out.println(yytext()); return new Symbol(A3Symbol.CONDITIONAL); }
<YYINITIAL>";" {System.out.println(yytext()); return new Symbol(A3Symbol.SEMICOLON); }
<YYINITIAL>"," {System.out.println(yytext()); return new Symbol(A3Symbol.COMMA); }
<YYINITIAL>"INT"|"REAL"|"STRING" {System.out.println(yytext()); return new Symbol(A3Symbol.TYPEDEFS); }
<YYINITIAL>":=" {System.out.println(yytext()); return new Symbol(A3Symbol.ASSIGN); }
<YYINITIAL>[a-zA-Z%@$][a-zA-Z0-9]* {System.out.println(yytext()); return new Symbol(A3Symbol.IDENTIFIER); }
<YYINITIAL>[0-9]+ {System.out.println(yytext()); return new Symbol(A3Symbol.NUMBER); }
[^] {}