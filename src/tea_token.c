#include "tea_token.h"

#include "tea.h"

#include <string.h>

static const tea_keyword_entry_t tea_keywords[] = { { "fn", TEA_TOKEN_FN }, { NULL, 0 } };

static bool equals(const char *a, const char *b, const int n)
{
  if (n > 0) {
    return !strncmp(a, b, n);
  }

  return !strcmp(a, b);
}

int tea_get_ident_token_type(const char *ident, const int length)
{
  for (int i = 0; tea_keywords[i].keyword; ++i) {
    if (equals(ident, tea_keywords[i].keyword, length)) {
      return tea_keywords[i].token_type;
    }
  }

  return TEA_TOKEN_IDENT;
}

const char *tea_get_token_name(const int token_type)
{
  switch (token_type) {
    case TEA_TOKEN_FN:
      return "FN";
    case TEA_TOKEN_IDENT:
      return "IDENT";
    case TEA_TOKEN_LPAREN:
      return "LPAREN";
    case TEA_TOKEN_RPAREN:
      return "RPAREN";
    case TEA_TOKEN_LBRACE:
      return "LBRACE";
    case TEA_TOKEN_RBRACE:
      return "RBRACE";
    case TEA_TOKEN_AT:
      return "AT";
    case TEA_TOKEN_COLON:
      return "COLON";
    case TEA_TOKEN_COMMA:
      return "COMMA";
    default:
      return NULL;
  }
}
