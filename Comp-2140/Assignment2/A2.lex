import java.io.*;
%%
%{    
      static int identifierCount = 0,commentCount = 0,keywordCount = 0,numberCount = 0,quotedStringCount = 0;
      public static void main(String argv[]) throws java.io.IOException {
	  A2 yy = new A2(new FileInputStream(new File("A2.input")));
	  while (yy.yylex()>=0){}
           FileWriter writer = new FileWriter(new File("A2.output"));
           writer.write("identifiers: " + identifierCount + "\nkeywords: " + keywordCount+"\nnumbers: " + numberCount+"\ncomments: " + commentCount+"\nquotedString: " + quotedStringCount);
           writer.close();
      }
%}
%integer
%class A2



%state COMMENT
%%

<YYINITIAL> [0-9]+("."[0-9]+)? {numberCount++;}
<YYINITIAL> "WRITE"|"READ"|"IF"|"ELSE"|"RETURN"|"BEGIN"|"END"|"MAIN"|"STRING"|"INT"|"REAL" {keywordCount++;}
<YYINITIAL> [a-zA-Z][a-zA-Z0-9]* {identifierCount++;}
<YYINITIAL> \"[^\"]*\" {quotedStringCount++;}
<YYINITIAL>"/**" {yybegin(COMMENT);commentCount++;}
<COMMENT>"**/" {yybegin(YYINITIAL);}
<COMMENT>"\n"|. {}
\r|\n|. {}