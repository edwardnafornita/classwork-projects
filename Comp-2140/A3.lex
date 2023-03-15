import java_cup.runtime.*;

%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A3Scanner
%state COMMENT

%%
<YYINITIAL>"/**" { yybegin(COMMENT); }
<COMMENT>"**/" { yybegin(YYINITIAL); }
<YYINITIAL>"+" { return new Symbol(A3Symbol.PLUS); }
<YYINITIAL>"-" { return new Symbol(A3Symbol.MINUS); }
<YYINITIAL>"*" { return new Symbol(A3Symbol.TIMES); }
<YYINITIAL>"/" { return new Symbol(A3Symbol.DIVIDE); }
<YYINITIAL>\"[^\"]*\" { return new Symbol(A3Symbol.QUOTEDSTRING); }
<YYINITIAL>"(" { return new Symbol(A3Symbol.LPAREN); }
<YYINITIAL>")" { return new Symbol(A3Symbol.RPAREN); }
<YYINITIAL>"WRITE" { return new Symbol(A3Symbol.WRITE); }
<YYINITIAL>"READ" { return new Symbol(A3Symbol.READ); }
<YYINITIAL>"IF" { return new Symbol(A3Symbol.IF); }
<YYINITIAL>"ELSE" { return new Symbol(A3Symbol.ELSE); }
<YYINITIAL>"RETURN" { return new Symbol(A3Symbol.RETURN); }
<YYINITIAL>"BEGIN" { return new Symbol(A3Symbol.BEGIN); }
<YYINITIAL>"END" { return new Symbol(A3Symbol.END); }
<YYINITIAL>"MAIN" { return new Symbol(A3Symbol.MAIN); }
<YYINITIAL>"=="|"!=" { return new Symbol(A3Symbol.CONDITIONAL); }
<YYINITIAL>";" { return new Symbol(A3Symbol.SEMICOLON); }
<YYINITIAL>"," { return new Symbol(A3Symbol.COMMA); }
<YYINITIAL>"INT"|"REAL"|"STRING" { return new Symbol(A3Symbol.TYPEDEFS); }
<YYINITIAL>":=" { return new Symbol(A3Symbol.ASSIGN); }
<YYINITIAL>[a-zA-Z%@$][a-zA-Z0-9]* { return new Symbol(A3Symbol.IDENTIFIER); }
<YYINITIAL>[0-9]+(\.[0-9]+)? { return new Symbol(A3Symbol.NUMBER); }
[^] {}