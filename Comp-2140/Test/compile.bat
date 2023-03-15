java JLex.Main %1.lex
java java_cup.Main -parser %2 -symbols %3 %1.cup
javac %1.lex.java
javac %2.java %3.java %4.java
java %4