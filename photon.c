#include "photon.h"

#define CURSOR_ERROR_MSG "LINE (%lu) COLUMN (%lu)"
#define SEMANTIC_ERROR_MSG "TYPE MISSMATCH %s INTO %s " CURSOR_ERROR_MSG "\n"
#define PARSER_ERROR_MSG "PARSE ERROR \"%s\" " CURSOR_ERROR_MSG "\n"
#define LEXER_ERROR_MSG "INVALID CHARACTER \'%c' " CURSOR_ERROR_MSG "\n"
#define DEFAULT_IDENTIFIER_COUNT 16

const char* _print_datatype(const datatype_t datatype);
//identifier_t _init_program();

static cursor_t _cursor = raw_cursor();

string_t raw_string(size_t leng)
{
    string_t rawdata;

    rawdata = (string_t) malloc((leng+1) * sizeof(char));
    if (!rawdata) { exit(EXIT_FAILURE); }
    rawdata[leng+1] = nullchr;
    return rawdata;
}

cursor_t raw_cursor()
{
    cursor_t rawdata;

    rawdata.line = 1; 
    rawdata.nextline = 1;
    rawdata.column = 1;
    rawdata.nextcolumn = 1;
    rawdata.bytes = 0;
    rawdata.nextbytes = 0;

    return rawdata;
}

datatype_t raw_datatype()
{
    datatype_t rawdata;

    rawdata.type = (datatype_e) eunknown;
    rawdata.isarray = false;
    rawdata.isconstant = true;
    rawdata.isunique = false;

    return rawdata;
}

identifier_t raw_identifier()
{
    identifier_t rawdata;

    rawdata.type = (identifier_e) eunknown;
    rawdata.lexeme = nullstr;
    rawdata.cursor = raw_cursor();
    rawdata.datatype = raw_datatype();
    rawdata.argumentcount = 0;
    rawdata.arguments = nullptr;

    return rawdata;
}

identifier_t* new_identifier(size_t size) 
{
    identifier_t* newdata;

    newdata = (identifier_t*) malloc(size * sizof(identifier_t));
    if (!newdata) { exit(EXIT_FAILURE); }

    return newdata;
}

bool_t check(datatype_t lhs, datatype_t rhs)
{
    return (lhs.isarray == rhs.isarray)
        && (lhs.type == rhs.type)
        && (!lhs.isconstant);
}

datatype_t datatype_assign(const datatype_t lhs, const datatype_t rhs)
{
    if (!check(lhs, rhs)) { semantic_error(lhs, rhs); }
    return lhs;
}

datatype_t datatype_contract(const datatype_t lhs, const datatype_t rhs)
{
    if (lhs.isarray || rhs.isarray) { semantic_error(lhs, rhs); }
    return raw_datatype();
}

void install (identifier_t identifier)
{

}

bool_t lookup(string_t lexeme, identifier_t *ptridentifier)
{
    return false;
}


void update_cursor()
{
    string_t text; char c;
    size_t line, size;

    line = 0; size = 0;
    text = yytext; c = nullchr;

    _cursor.line = _cursor.nextline;
    _cursor.column = _cursor.nextcolumn;
    _cursor.bytes = _cursor.nextbytes;
    while((c = text[size]))
    {
        ++column; ++size; 
        if (c == '\n') { _cursor.nextcolumn = 1; column = 0; ++line; }
    }
    _cursor.nextcolumn += column;
    _cursor.nextline += line;
    _cursor.nextbytes += size;
}

void lexer_error()
{
    printf(LEXER_ERROR_MSG, *yytext, _cursor.line);
    exit(EXIT_SUCCESS);
}

void parser_error()
{
    printf(PARSER_ERROR_MSG, _cursor.line);
    exit(EXIT_SUCCESS);
}

void semantic_error()
{
    printf(SEMANTIC_ERROR_MSG,
        _print_datatype(rhs),
        _print_datatype(lhs),
        _cursor.line, _cursor.column);
    exit(EXIT_FAILURE);
}

const char* _print_datatype(const datatype_t datatype)
{
    if (datatype.type = ereal) { return datatype.isarray ? "[real]" : "real" }
    if (datatype.type = eboolean) { return datatype.isarray ? "[boolean]" : "boolean" }
    if (datatype.type = einteger) { return datatype.isarray ? "[integer]" : "integer" }
    return "_unknown_";
}

identifier_t _init_program()
{
    identifier_t program;
    return _program;
}