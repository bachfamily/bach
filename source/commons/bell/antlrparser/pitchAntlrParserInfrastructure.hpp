//
//  pitchAntlrParserInfrastructure.hpp
//  bach
//
//  Created by Andrea Agostini on 12/07/24.
//

#ifndef pitchAntlrParserInfrastructure_hpp
#define pitchAntlrParserInfrastructure_hpp

#include <bell/bach_codableobj.hpp>
#include "pitchLexer.h"
#include "pitchParser.h"

#include "antlr4-runtime.h"
#include "pitchBaseVisitor.h"
#include "ast.hpp"

class pchListener : public pitchBaseVisitor {

public:
    antlrcpp::Any visitPch(pitchParser::PchContext *ctx) override {
        
        char dtxt = ctx->NOTENAME()->getText()[0];
        int d = t_pitch::text2degree(dtxt);
        
        t_shortRational a = {0, 1};

        if (ctx->ACCIDENTAL()) {
            for (char atxt : ctx->ACCIDENTAL()->getText()) {
                switch (atxt) {
                    case 'x':    a += t_pitch::dblsharp;    break;
                    case '#':    a += t_pitch::sharp;       break;
                        
                    case 'b':    a += t_pitch::flat;        break;
                        
                    case 'q':    a += t_pitch::qrtrsharp;   break;
                    case 'd':    a += t_pitch::qrtrflat;    break;
                        
                    case '^':    a += t_pitch::eighthsharp; break;
                    case 'v':    a += t_pitch::eighthflat;  break;
                }
            }
        }
        
        int o = stoi(ctx->UINT()->getText());
        if (ctx->UMINUS().size() % 2)
            o = -o;
        
        t_shortRational deviation;
        t_pitch p;
        if (ctx->dev()) {
            deviation = std::any_cast<t_shortRational>(visit(ctx->dev()));
            p = t_pitch(d, a+deviation, o);
        } else {
            p = t_pitch(d, a, o);
        }
        return p;
    }

    antlrcpp::Any visitDevInt(pitchParser::DevIntContext *ctx) override {
        int d = stoi(ctx->UINT()->getText());
        if (ctx->UMINUS().size() % 2)
            d = -d;
        return t_shortRational(d);
    }
    
    antlrcpp::Any visitDevRat(pitchParser::DevRatContext *ctx) override {
        auto r = std::any_cast<t_shortRational>(visit(ctx->urat()));
        if (ctx->UMINUS().size() % 2)
            r = -r;
        return r;
    }
    
    antlrcpp::Any visitUrat(pitchParser::UratContext *ctx) override {
        int num = stoi(ctx->UINT(0)->getText());
        int den = stoi(ctx->UINT(1)->getText());
        if (ctx->UMINUS().size() % 2)
            num = -num;
        auto r = t_shortRational(num, den);
        return r;
    }
    
};

#endif /* pitchAntlrParserInfrastructure_hpp */
