// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/parsers/antlrparser/parsetest.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link parsetestParser}.
 */
public interface parsetestListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link parsetestParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(parsetestParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(parsetestParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#sequence}.
	 * @param ctx the parse tree
	 */
	void enterSequence(parsetestParser.SequenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#sequence}.
	 * @param ctx the parse tree
	 */
	void exitSequence(parsetestParser.SequenceContext ctx);
	/**
	 * Enter a parse tree produced by the {@code itemNumber}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void enterItemNumber(parsetestParser.ItemNumberContext ctx);
	/**
	 * Exit a parse tree produced by the {@code itemNumber}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void exitItemNumber(parsetestParser.ItemNumberContext ctx);
	/**
	 * Enter a parse tree produced by the {@code itemSequence}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void enterItemSequence(parsetestParser.ItemSequenceContext ctx);
	/**
	 * Exit a parse tree produced by the {@code itemSequence}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void exitItemSequence(parsetestParser.ItemSequenceContext ctx);
	/**
	 * Enter a parse tree produced by the {@code itemFuncall}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void enterItemFuncall(parsetestParser.ItemFuncallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code itemFuncall}
	 * labeled alternative in {@link parsetestParser#item}.
	 * @param ctx the parse tree
	 */
	void exitItemFuncall(parsetestParser.ItemFuncallContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#var}.
	 * @param ctx the parse tree
	 */
	void enterVar(parsetestParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#var}.
	 * @param ctx the parse tree
	 */
	void exitVar(parsetestParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#lvalueSpecs}.
	 * @param ctx the parse tree
	 */
	void enterLvalueSpecs(parsetestParser.LvalueSpecsContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#lvalueSpecs}.
	 * @param ctx the parse tree
	 */
	void exitLvalueSpecs(parsetestParser.LvalueSpecsContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#lvalue}.
	 * @param ctx the parse tree
	 */
	void enterLvalue(parsetestParser.LvalueContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#lvalue}.
	 * @param ctx the parse tree
	 */
	void exitLvalue(parsetestParser.LvalueContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#fakeLvalue}.
	 * @param ctx the parse tree
	 */
	void enterFakeLvalue(parsetestParser.FakeLvalueContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#fakeLvalue}.
	 * @param ctx the parse tree
	 */
	void exitFakeLvalue(parsetestParser.FakeLvalueContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(parsetestParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(parsetestParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#reference}.
	 * @param ctx the parse tree
	 */
	void enterReference(parsetestParser.ReferenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#reference}.
	 * @param ctx the parse tree
	 */
	void exitReference(parsetestParser.ReferenceContext ctx);
	/**
	 * Enter a parse tree produced by the {@code itemTerm}
	 * labeled alternative in {@link parsetestParser#term}.
	 * @param ctx the parse tree
	 */
	void enterItemTerm(parsetestParser.ItemTermContext ctx);
	/**
	 * Exit a parse tree produced by the {@code itemTerm}
	 * labeled alternative in {@link parsetestParser#term}.
	 * @param ctx the parse tree
	 */
	void exitItemTerm(parsetestParser.ItemTermContext ctx);
	/**
	 * Enter a parse tree produced by the {@code referenceTerm}
	 * labeled alternative in {@link parsetestParser#term}.
	 * @param ctx the parse tree
	 */
	void enterReferenceTerm(parsetestParser.ReferenceTermContext ctx);
	/**
	 * Exit a parse tree produced by the {@code referenceTerm}
	 * labeled alternative in {@link parsetestParser#term}.
	 * @param ctx the parse tree
	 */
	void exitReferenceTerm(parsetestParser.ReferenceTermContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(parsetestParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(parsetestParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code listOther}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void enterListOther(parsetestParser.ListOtherContext ctx);
	/**
	 * Exit a parse tree produced by the {@code listOther}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void exitListOther(parsetestParser.ListOtherContext ctx);
	/**
	 * Enter a parse tree produced by the {@code listOnlyAssignment}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void enterListOnlyAssignment(parsetestParser.ListOnlyAssignmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code listOnlyAssignment}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void exitListOnlyAssignment(parsetestParser.ListOnlyAssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code listOnlyConditional}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void enterListOnlyConditional(parsetestParser.ListOnlyConditionalContext ctx);
	/**
	 * Exit a parse tree produced by the {@code listOnlyConditional}
	 * labeled alternative in {@link parsetestParser#list}.
	 * @param ctx the parse tree
	 */
	void exitListOnlyConditional(parsetestParser.ListOnlyConditionalContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#funcall}.
	 * @param ctx the parse tree
	 */
	void enterFuncall(parsetestParser.FuncallContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#funcall}.
	 * @param ctx the parse tree
	 */
	void exitFuncall(parsetestParser.FuncallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifthen}
	 * labeled alternative in {@link parsetestParser#conditional}.
	 * @param ctx the parse tree
	 */
	void enterIfthen(parsetestParser.IfthenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifthen}
	 * labeled alternative in {@link parsetestParser#conditional}.
	 * @param ctx the parse tree
	 */
	void exitIfthen(parsetestParser.IfthenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifthenelse}
	 * labeled alternative in {@link parsetestParser#conditional}.
	 * @param ctx the parse tree
	 */
	void enterIfthenelse(parsetestParser.IfthenelseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifthenelse}
	 * labeled alternative in {@link parsetestParser#conditional}.
	 * @param ctx the parse tree
	 */
	void exitIfthenelse(parsetestParser.IfthenelseContext ctx);
	/**
	 * Enter a parse tree produced by {@link parsetestParser#nullify}.
	 * @param ctx the parse tree
	 */
	void enterNullify(parsetestParser.NullifyContext ctx);
	/**
	 * Exit a parse tree produced by {@link parsetestParser#nullify}.
	 * @param ctx the parse tree
	 */
	void exitNullify(parsetestParser.NullifyContext ctx);
}