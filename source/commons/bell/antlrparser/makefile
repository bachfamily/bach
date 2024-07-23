bell install:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.10.1-complete.jar" org.antlr.v4.Tool -Dlanguage=Cpp -no-listener -visitor bell.g4

	java -Xmx500M -cp "/usr/local/lib/antlr-4.10.1-complete.jar" org.antlr.v4.Tool -Dlanguage=Cpp  -no-listener -visitor pitch.g4

	java -Xmx500M -cp "/usr/local/lib/antlr-4.10.1-complete.jar" org.antlr.v4.Tool -Dlanguage=Cpp preprocLexer.g4

	java -Xmx500M -cp "/usr/local/lib/antlr-4.10.1-complete.jar" org.antlr.v4.Tool -Dlanguage=Cpp  -no-listener -visitor preproc.g4
