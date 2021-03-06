/*
4coder_language_cpp.h - Sets up the C++ language context.

TYPE: 'langauge-description'
*/

// TOP

#if !defined(FCODER_LANGUAGE_VHDL_H)
#define FCODER_LANGUAGE_VHDL_H

static Parse_Context_ID parse_context_language_vhdl;

#define PSAT(s, t) {s, sizeof(s)-1, t}
static void
init_language_vhdl(Application_Links *app){
    if (parse_context_language_vhdl != 0) return;
    
    Parser_String_And_Type kw[] = {
        
        PSAT("begin"    , CPP_TOKEN_KEY_CONTROL_FLOW), // CPP_TOKEN_BRACE_OPEN),
        PSAT("end"      , CPP_TOKEN_KEY_CONTROL_FLOW), // CPP_TOKEN_BRACE_CLOSE),
        
        PSAT("entity"   , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("architecture", CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("process"  , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("function" , CPP_TOKEN_KEY_TYPE_DECLARATION),
        
        PSAT("is"       , CPP_TOKEN_KEY_TYPE),
        PSAT("of"       , CPP_TOKEN_KEY_TYPE),
        
        PSAT("port"     , CPP_TOKEN_KEY_OTHER),
        PSAT("in"       , CPP_TOKEN_KEY_OTHER),
        PSAT("out"      , CPP_TOKEN_KEY_OTHER),
        PSAT("inout"    , CPP_TOKEN_KEY_OTHER),
        
        PSAT("signal"          , CPP_TOKEN_KEY_TYPE),
        PSAT("downto"          , CPP_TOKEN_KEY_TYPE),
        
        PSAT("std_logic"       , CPP_TOKEN_KEY_TYPE),
        PSAT("std_logic_vector", CPP_TOKEN_KEY_TYPE),
        PSAT("unsigned"        , CPP_TOKEN_KEY_TYPE),
        PSAT("signed"          , CPP_TOKEN_KEY_TYPE),
        
        PSAT("to_integer"      , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("to_unsigned"     , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("to_signed"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        
        PSAT("if"              , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("then"            , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("elsif"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("else"            , CPP_TOKEN_KEY_CONTROL_FLOW),
        
        PSAT("and"      , CPP_TOKEN_AND),
        PSAT("or"       , CPP_TOKEN_OR),
        PSAT("xor"      , CPP_TOKEN_BIT_XOR),
        PSAT("not"      , CPP_TOKEN_NOT),
#if 0
        PSAT("true"  , CPP_TOKEN_BOOLEAN_CONSTANT),
        PSAT("false" , CPP_TOKEN_BOOLEAN_CONSTANT),

        PSAT("and"      , CPP_TOKEN_AND),
        PSAT("and_eq"   , CPP_TOKEN_ANDEQ),
        PSAT("bitand"   , CPP_TOKEN_BIT_AND),
        PSAT("bitor"    , CPP_TOKEN_BIT_OR),
        PSAT("or"       , CPP_TOKEN_OR),
        PSAT("or_eq"    , CPP_TOKEN_OREQ),
        PSAT("sizeof"   , CPP_TOKEN_SIZEOF),
        PSAT("alignof"  , CPP_TOKEN_ALIGNOF),
        PSAT("decltype" , CPP_TOKEN_DECLTYPE),
        PSAT("throw"    , CPP_TOKEN_THROW),
        PSAT("new"      , CPP_TOKEN_NEW),
        PSAT("delete"   , CPP_TOKEN_DELETE),
        PSAT("xor"      , CPP_TOKEN_BIT_XOR),
        PSAT("xor_eq"   , CPP_TOKEN_XOREQ),
        PSAT("not"      , CPP_TOKEN_NOT),
        PSAT("not_eq"   , CPP_TOKEN_NOTEQ),
        PSAT("typeid"   , CPP_TOKEN_TYPEID),
        PSAT("compl"    , CPP_TOKEN_BIT_NOT),

        PSAT("void"   , CPP_TOKEN_KEY_TYPE),
        PSAT("bool"   , CPP_TOKEN_KEY_TYPE),
        PSAT("char"   , CPP_TOKEN_KEY_TYPE),
        PSAT("int"    , CPP_TOKEN_KEY_TYPE),
        PSAT("float"  , CPP_TOKEN_KEY_TYPE),
        PSAT("double" , CPP_TOKEN_KEY_TYPE),
        
        PSAT("long"     , CPP_TOKEN_KEY_MODIFIER),
        PSAT("short"    , CPP_TOKEN_KEY_MODIFIER),
        PSAT("unsigned" , CPP_TOKEN_KEY_MODIFIER),
        
        PSAT("const"    , CPP_TOKEN_KEY_QUALIFIER),
        PSAT("volatile" , CPP_TOKEN_KEY_QUALIFIER),
        
        PSAT("asm"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("break"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("case"          , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("catch"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("continue"      , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("default"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("do"            , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("else"          , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("for"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("goto"          , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("if"            , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("return"        , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("switch"        , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("try"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("while"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("static_assert" , CPP_TOKEN_KEY_CONTROL_FLOW),
        
        PSAT("const_cast"       , CPP_TOKEN_KEY_CAST),
        PSAT("dynamic_cast"     , CPP_TOKEN_KEY_CAST),
        PSAT("reinterpret_cast" , CPP_TOKEN_KEY_CAST),
        PSAT("static_cast"      , CPP_TOKEN_KEY_CAST),
        
        PSAT("class"    , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("enum"     , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("struct"   , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("typedef"  , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("union"    , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("template" , CPP_TOKEN_KEY_TYPE_DECLARATION),
        PSAT("typename" , CPP_TOKEN_KEY_TYPE_DECLARATION),
        
        PSAT("friend"    , CPP_TOKEN_KEY_ACCESS),
        PSAT("namespace" , CPP_TOKEN_KEY_ACCESS),
        PSAT("private"   , CPP_TOKEN_KEY_ACCESS),
        PSAT("protected" , CPP_TOKEN_KEY_ACCESS),
        PSAT("public"    , CPP_TOKEN_KEY_ACCESS),
        PSAT("using"     , CPP_TOKEN_KEY_ACCESS),
        
        PSAT("extern"  , CPP_TOKEN_KEY_LINKAGE),
        PSAT("export"  , CPP_TOKEN_KEY_LINKAGE),
        PSAT("inline"  , CPP_TOKEN_KEY_LINKAGE),
        PSAT("static"  , CPP_TOKEN_KEY_LINKAGE),
        PSAT("virtual" , CPP_TOKEN_KEY_LINKAGE),
        
        PSAT("alignas"      , CPP_TOKEN_KEY_OTHER),
        PSAT("explicit"     , CPP_TOKEN_KEY_OTHER),
        PSAT("noexcept"     , CPP_TOKEN_KEY_OTHER),
        PSAT("nullptr"      , CPP_TOKEN_KEY_OTHER),
        PSAT("operator"     , CPP_TOKEN_KEY_OTHER),
        PSAT("register"     , CPP_TOKEN_KEY_OTHER),
        PSAT("this"         , CPP_TOKEN_KEY_OTHER),
        PSAT("thread_local" , CPP_TOKEN_KEY_OTHER),
#endif
        
#if defined(EXTRA_KEYWORDS)
#include EXTRA_KEYWORDS
#undef EXTRA_KEYWORDS
#endif
    };
    
    Parser_String_And_Type pp[] = {
        PSAT("library" , CPP_PP_INCLUDE ),
        PSAT("Library" , CPP_PP_INCLUDE ),
        PSAT("LIBRARY" , CPP_PP_INCLUDE ),
#if 0
        PSAT("end if"  , CPP_PP_ENDIF   ),
        PSAT("End if"  , CPP_PP_ENDIF   ),
        PSAT("End If"  , CPP_PP_ENDIF   ),
        PSAT("END IF"  , CPP_PP_ENDIF   ),
        PSAT("ifdef"   , CPP_PP_IFDEF   ),
        PSAT("IFDEF"   , CPP_PP_IFDEF   ),
#endif
        PSAT("use"     , CPP_PP_USING   ),
        PSAT("Use"     , CPP_PP_USING   ),
        PSAT("USE"     , CPP_PP_USING   ),

#if 0        
        PSAT("else"    , CPP_PP_ELSE    ),
        PSAT("ELSE"    , CPP_PP_ELSE    ),
        PSAT("elsif"   , CPP_PP_ELIF    ),
        PSAT("ELSIF"   , CPP_PP_ELIF    ),
        PSAT("line"    , CPP_PP_LINE    ),
        PSAT("LINE"    , CPP_PP_LINE    ),
        PSAT("if"      , CPP_PP_IF      ),
        PSAT("IF"      , CPP_PP_IF      ),
#endif

        
#if defined(EXTRA_PREPROPS)
#include EXTRA_PREPROPS
#undef EXTRA_PREPROPS
#endif
    };
    
    parse_context_language_vhdl = create_parse_context(app, kw, ArrayCount(kw), pp, ArrayCount(pp));
}
#undef PSAT

#endif

// BOTTOM



