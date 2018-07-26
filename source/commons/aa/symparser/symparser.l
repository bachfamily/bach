%option noyywrap nodefault reentrant bison-bridge
%option noyyalloc noyyrealloc noyyfree
%option never-interactive
%option header-file="symparser.lex.h"
%option outfile="symparser.c"
%option prefix="symparser_"

%s NO_L NO_b NO_Lb NO_e NO_Le NO_be NO_Lbe NO_l NO_Ll NO_bl NO_Lbl NO_el NO_Lel NO_bel NO_Lbel NO_p NO_Lp NO_bp NO_Lbp NO_ep NO_Lep NO_bep NO_Lbep NO_lp NO_Llp NO_blp NO_Lblp NO_elp NO_Lelp NO_belp NO_Lbelp NO_r NO_Lr NO_br NO_Lbr NO_er NO_Ler NO_ber NO_Lber NO_lr NO_Llr NO_blr NO_Lblr NO_elr NO_Lelr NO_belr NO_Lbelr NO_pr NO_Lpr NO_bpr NO_Lbpr NO_epr NO_Lepr NO_bepr NO_Lbepr NO_lpr NO_Llpr NO_blpr NO_Lblpr NO_elpr NO_Lelpr NO_belpr NO_Lbelpr NO_s NO_Ls NO_bs NO_Lbs NO_es NO_Les NO_bes NO_Lbes NO_ls NO_Lls NO_bls NO_Lbls NO_els NO_Lels NO_bels NO_Lbels NO_ps NO_Lps NO_bps NO_Lbps NO_eps NO_Leps NO_beps NO_Lbeps NO_lps NO_Llps NO_blps NO_Lblps NO_elps NO_Lelps NO_belps NO_Lbelps NO_rs NO_Lrs NO_brs NO_Lbrs NO_ers NO_Lers NO_bers NO_Lbers NO_lrs NO_Llrs NO_blrs NO_Lblrs NO_elrs NO_Lelrs NO_belrs NO_Lbelrs NO_prs NO_Lprs NO_bprs NO_Lbprs NO_eprs NO_Leprs NO_beprs NO_Lbeprs NO_lprs NO_Llprs NO_blprs NO_Lblprs NO_elprs NO_Lelprs NO_belprs NO_Lbelprs

INTEGER ([+-]?[0-9]+)
FLOAT ([+-]?(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+)))
SIMPLEFLOAT ([+-]?(([0-9]*\.[0-9]+)|([0-9]+\.)))
BACH_RATIONAL ({INTEGER}[/]{INTEGER})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq\^v]+)

%{
    #define BACH_MAX
    #ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "symparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
    
    #include "bach_symparser_tab.h"
    #define YY_DECL int yylex(YYSTYPE *yylval_param, yyscan_t yyscanner)
    
    #define YY_NO_UNISTD_H

%}

%%

<INITIAL,NO_b,NO_e,NO_be,NO_l,NO_bl,NO_el,NO_bel,NO_p,NO_bp,NO_ep,NO_bep,NO_lp,NO_blp,NO_elp,NO_belp,NO_r,NO_br,NO_er,NO_ber,NO_lr,NO_blr,NO_elr,NO_belr,NO_pr,NO_bpr,NO_epr,NO_bepr,NO_lpr,NO_blpr,NO_elpr,NO_belpr,NO_s,NO_bs,NO_es,NO_bes,NO_ls,NO_bls,NO_els,NO_bels,NO_ps,NO_bps,NO_eps,NO_beps,NO_lps,NO_blps,NO_elps,NO_belps,NO_rs,NO_brs,NO_ers,NO_bers,NO_lrs,NO_blrs,NO_elrs,NO_belrs,NO_prs,NO_bprs,NO_eprs,NO_beprs,NO_lprs,NO_blprs,NO_elprs,NO_belprs>{
    ("("|"[") {
        parserpost(" lex: BACH_PUSH\n");
        return BACH_PUSH;
    }
    
    (")"|"]") {
        parserpost(" lex: POPPE\n");
        return BACH_POP;
    }
}

{INTEGER} {
    parserpost(" lex: INTEGER %d\n", atoi(yytext));
    yylval->l = atol(yytext);
    return BACH_LONG;
}

<INITIAL,NO_L,NO_b,NO_Lb,NO_e,NO_Le,NO_be,NO_Lbe,NO_l,NO_Ll,NO_bl,NO_Lbl,NO_el,NO_Lel,NO_bel,NO_Lbel,NO_p,NO_Lp,NO_bp,NO_Lbp,NO_ep,NO_Lep,NO_bep,NO_Lbep,NO_lp,NO_Llp,NO_blp,NO_Lblp,NO_elp,NO_Lelp,NO_belp,NO_Lbelp,NO_s,NO_Ls,NO_bs,NO_Lbs,NO_es,NO_Les,NO_bes,NO_Lbes,NO_ls,NO_Lls,NO_bls,NO_Lbls,NO_els,NO_Lels,NO_bels,NO_Lbels,NO_ps,NO_Lps,NO_bps,NO_Lbps,NO_eps,NO_Leps,NO_beps,NO_Lbeps,NO_lps,NO_Llps,NO_blps,NO_Lblps,NO_elps,NO_Lelps,NO_belps,NO_Lbelps>{BACH_RATIONAL} {
    yylval->r = t_parser::eatRational(yytext);
    parserpost(" lex: BACH_RATIONAL %ld / %ld\n", yylval->r.num(), yylval->r.den());
    return BACH_RAT;
}

<INITIAL,NO_L,NO_b,NO_Lb,NO_l,NO_Ll,NO_bl,NO_Lbl,NO_p,NO_Lp,NO_bp,NO_Lbp,NO_lp,NO_Llp,NO_blp,NO_Lblp,NO_r,NO_Lr,NO_br,NO_Lbr,NO_lr,NO_Llr,NO_blr,NO_Lblr,NO_pr,NO_Lpr,NO_bpr,NO_Lbpr,NO_lpr,NO_Llpr,NO_blpr,NO_Lblpr,NO_s,NO_Ls,NO_bs,NO_Lbs,NO_ls,NO_Lls,NO_bls,NO_Lbls,NO_ps,NO_Lps,NO_bps,NO_Lbps,NO_lps,NO_Llps,NO_blps,NO_Lblps,NO_rs,NO_Lrs,NO_brs,NO_Lbrs,NO_lrs,NO_Llrs,NO_blrs,NO_Lblrs,NO_prs,NO_Lprs,NO_bprs,NO_Lbprs,NO_lprs,NO_Llprs,NO_blprs,NO_Lblprs>{FLOAT} {
    yylval->d = atof(yytext);
    parserpost(" lex: BACH_DOUBLE %lf\n", yylval->d);
    return BACH_DOUBLE;
}

<NO_e,NO_Le,NO_be,NO_Lbe,NO_el,NO_Lel,NO_bel,NO_Lbel,NO_ep,NO_Lep,NO_bep,NO_Lbep,NO_elp,NO_Lelp,NO_belp,NO_Lbelp,NO_er,NO_Ler,NO_ber,NO_Lber,NO_elr,NO_Lelr,NO_belr,NO_Lbelr,NO_epr,NO_Lepr,NO_bepr,NO_Lbepr,NO_elpr,NO_Lelpr,NO_belpr,NO_Lbelpr,NO_es,NO_Les,NO_bes,NO_Lbes,NO_els,NO_Lels,NO_bels,NO_Lbels,NO_eps,NO_Leps,NO_beps,NO_Lbeps,NO_elps,NO_Lelps,NO_belps,NO_Lbelps,NO_ers,NO_Lers,NO_bers,NO_Lbers,NO_elrs,NO_Lelrs,NO_belrs,NO_Lbelrs,NO_eprs,NO_Leprs,NO_beprs,NO_Lbeprs,NO_elprs,NO_Lelprs,NO_belprs,NO_Lbelprs>{SIMPLEFLOAT} {
    yylval->d = atof(yytext);
    parserpost(" lex: BACH_DOUBLE %lf\n", yylval->d);
    return BACH_DOUBLE;
}

<INITIAL,NO_L,NO_b,NO_Lb,NO_e,NO_Le,NO_be,NO_Lbe,NO_l,NO_Ll,NO_bl,NO_Lbl,NO_el,NO_Lel,NO_bel,NO_Lbel,NO_r,NO_Lr,NO_br,NO_Lbr,NO_er,NO_Ler,NO_ber,NO_Lber,NO_lr,NO_Llr,NO_blr,NO_Lblr,NO_elr,NO_Lelr,NO_belr,NO_Lbelr,NO_s,NO_Ls,NO_bs,NO_Lbs,NO_es,NO_Les,NO_bes,NO_Lbes,NO_ls,NO_Lls,NO_bls,NO_Lbls,NO_els,NO_Lels,NO_bels,NO_Lbels,NO_rs,NO_Lrs,NO_brs,NO_Lbrs,NO_ers,NO_Lers,NO_bers,NO_Lbers,NO_lrs,NO_Llrs,NO_blrs,NO_Lblrs,NO_elrs,NO_Lelrs,NO_belrs,NO_Lbelrs>{
    [-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER} {
        yylval->p = t_parser::eatPitchAsNameAccInt(yytext);
        parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
        return BACH_PITCH;
    }
    
    [-+]?{NOTENAME}{INTEGER}{ACCIDENTAL} {
        yylval->p = t_parser::eatPitchAsNameIntAcc(yytext);
        parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
        return BACH_PITCH;
    }
    
    [-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+t {
        yylval->p = t_parser::eatPitchAsNameAccIntIntT(yytext);
        parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
        return BACH_PITCH;
    }
    
    [-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+[/]{INTEGER}t {
        yylval->p = t_parser::eatPitchAsNameAccIntRatT(yytext);
        parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
        return BACH_PITCH;
    }
}

<INITIAL,NO_L,NO_e,NO_Le,NO_l,NO_Ll,NO_el,NO_Lel,NO_p,NO_Lp,NO_ep,NO_Lep,NO_lp,NO_Llp,NO_elp,NO_Lelp,NO_r,NO_Lr,NO_er,NO_Ler,NO_lr,NO_Llr,NO_elr,NO_Lelr,NO_pr,NO_Lpr,NO_epr,NO_Lepr,NO_lpr,NO_Llpr,NO_elpr,NO_Lelpr,NO_s,NO_Ls,NO_es,NO_Les,NO_ls,NO_Lls,NO_els,NO_Lels,NO_ps,NO_Lps,NO_eps,NO_Leps,NO_lps,NO_Llps,NO_elps,NO_Lelps,NO_rs,NO_Lrs,NO_ers,NO_Lers,NO_lrs,NO_Llrs,NO_elrs,NO_Lelrs,NO_prs,NO_Lprs,NO_eprs,NO_Leprs,NO_lprs,NO_Llprs,NO_elprs,NO_Lelprs>\`.* {
    parserpost(" lex: BACKTICKED BACH_SYMBOL %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    return BACH_SYMBOL;
}

\"\" {
    parserpost(" lex: QUOTED EMPTY BACH_SYMBOL %s\n", yytext);
    yylval->sym = gensym("");
    return BACH_SYMBOL;
}

<INITIAL,NO_L,NO_b,NO_Lb,NO_e,NO_Le,NO_be,NO_Lbe,NO_l,NO_Ll,NO_bl,NO_Lbl,NO_el,NO_Lel,NO_bel,NO_Lbel,NO_p,NO_Lp,NO_bp,NO_Lbp,NO_ep,NO_Lep,NO_bep,NO_Lbep,NO_lp,NO_Llp,NO_blp,NO_Lblp,NO_elp,NO_Lelp,NO_belp,NO_Lbelp,NO_r,NO_Lr,NO_br,NO_Lbr,NO_er,NO_Ler,NO_ber,NO_Lber,NO_lr,NO_Llr,NO_blr,NO_Lblr,NO_elr,NO_Lelr,NO_belr,NO_Lbelr,NO_pr,NO_Lpr,NO_bpr,NO_Lbpr,NO_epr,NO_Lepr,NO_bepr,NO_Lbepr,NO_lpr,NO_Llpr,NO_blpr,NO_Lblpr,NO_elpr,NO_Lelpr,NO_belpr,NO_Lbelpr>{
    "null" {
        parserpost(" lex: null\n");
        return BACH_NULL;
    }
    
    "nil" {
        parserpost(" lex: nil\n");
        return BACH_NIL;
    }
}

<INITIAL,NO_b,NO_e,NO_be,NO_p,NO_bp,NO_ep,NO_bep,NO_r,NO_br,NO_er,NO_ber,NO_pr,NO_bpr,NO_epr,NO_bepr,NO_s,NO_bs,NO_es,NO_bes,NO_ps,NO_bps,NO_eps,NO_beps,NO_rs,NO_brs,NO_ers,NO_bers,NO_prs,NO_bprs,NO_eprs,NO_beprs>{
    [^\(\)\[\]]* {
        parserpost(" lex: BACH_SYMBOL %s\n", yytext);
        yylval->sym = gensym(yytext);
        return BACH_SYMBOL;
    }

    [^ \t\n\,\;]*[ \t\n\,\;].* {
        parserpost(" lex: BACH_SYMBOL %s\n", yytext);
        yylval->sym = gensym(yytext);
        return BACH_SYMBOL;
    }
}

<NO_L,NO_Lb,NO_Le,NO_Lbe,NO_l,NO_Ll,NO_bl,NO_Lbl,NO_el,NO_Lel,NO_bel,NO_Lbel,NO_Lp,NO_Lbp,NO_Lep,NO_Lbep,NO_lp,NO_Llp,NO_blp,NO_Lblp,NO_elp,NO_Lelp,NO_belp,NO_Lbelp,NO_Lr,NO_Lbr,NO_Ler,NO_Lber,NO_lr,NO_Llr,NO_blr,NO_Lblr,NO_elr,NO_Lelr,NO_belr,NO_Lbelr,NO_Lpr,NO_Lbpr,NO_Lepr,NO_Lbepr,NO_lpr,NO_Llpr,NO_blpr,NO_Lblpr,NO_elpr,NO_Lelpr,NO_belpr,NO_Lbelpr,NO_Ls,NO_Lbs,NO_Les,NO_Lbes,NO_ls,NO_Lls,NO_bls,NO_Lbls,NO_els,NO_Lels,NO_bels,NO_Lbels,NO_Lps,NO_Lbps,NO_Leps,NO_Lbeps,NO_lps,NO_Llps,NO_blps,NO_Lblps,NO_elps,NO_Lelps,NO_belps,NO_Lbelps,NO_Lrs,NO_Lbrs,NO_Lers,NO_Lbers,NO_lrs,NO_Llrs,NO_blrs,NO_Lblrs,NO_elrs,NO_Lelrs,NO_belrs,NO_Lbelrs,NO_Lprs,NO_Lbprs,NO_Leprs,NO_Lbeprs,NO_lprs,NO_Llprs,NO_blprs,NO_Lblprs,NO_elprs,NO_Lelprs,NO_belprs,NO_Lbelprs>{
    .* {
        parserpost(" lex: BACH_SYMBOL %s\n", yytext);
        yylval->sym = gensym(yytext);
        return BACH_SYMBOL;
    }
}

.|\n {
    parserpost(" lex: UNRECOGNIZED CHARACTER %s\n", yytext);
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
    yylex();
}
#endif


t_symParser::t_symParser(long ignore) : t_parser()
{
    setPtr(sizeof(struct yyguts_t));
    setBasePtr();
    reset();
    startCondition = ignore;
}

void t_symParser::reset()
{
    t_parser::reset();
    memset(this,0x00,sizeof(struct yyguts_t));
    //yy_init_globals ((yyscan_t) this);
}

YY_BUFFER_STATE symparser_scan_string(yyscan_t myscanner, char *buf)
{
    struct yyguts_t *yyg = (struct yyguts_t*) myscanner;
    BEGIN ((t_symParser *) myscanner)->getStartCondition();
    YY_BUFFER_STATE bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    return bp;
}

void symparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp)
{
    yy_flush_buffer(bp, myscanner);
    yy_delete_buffer(bp, myscanner);
}



void *symparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_symParser *) yyscanner)->getPtr(bytes);
    parserpost(" symparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *symparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    parserpost(" symparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void symparser_free(void *ptr,void *yyscanner)
{
    return;
}
