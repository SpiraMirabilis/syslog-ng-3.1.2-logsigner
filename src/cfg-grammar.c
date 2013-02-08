/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "cfg-grammar.y"


#include "syslog-ng.h"
#include "cfg.h"
#include "sgroup.h"
#include "dgroup.h"
#include "center.h"
#include "filter.h"
#include "templates.h"
#include "logreader.h"
#include "logparser.h"
#include "logrewrite.h"

#if ENABLE_SSL /* BEGIN MARK: tls */
#include "tlscontext.h"
#endif         /* END MARK */

#include "affile.h"
#include "afinter.h"
#include "afsocket.h"
#include "afinet.h"
#include "afunix.h"
#include "afstreams.h"
#include "afuser.h"
#include "afprog.h"
#if ENABLE_SQL
#include "afsql.h"
#endif

#include "messages.h"

#include "syslog-names.h"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FIXME: the lexer allocates strings with strdup instead of g_strdup,
 * therefore there are unnecessary g_strdup/free pairs in the grammar. These
 * should be removed. */

void yyerror(char *msg);
int yylex();

LogDriver *last_driver;
LogReaderOptions *last_reader_options;
LogWriterOptions *last_writer_options;
LogTemplate *last_template;
SocketOptions *last_sock_options;
LogParser *last_parser;
FilterRE *last_re_filter;
LogRewrite *last_rewrite;
gint last_addr_family = AF_INET;
gchar *last_include_file;

#if ENABLE_SSL
TLSContext *last_tls_context;
#endif


#if ! ENABLE_IPV6
#undef AF_INET6
#define AF_INET6 0; g_assert_not_reached()

#endif

static struct _LogTemplate *
cfg_check_inline_template(GlobalConfig *cfg, const gchar *template_or_name)
{
  struct _LogTemplate *template = cfg_lookup_template(configuration, template_or_name);
  if (template == NULL)
    {
      template = log_template_new(NULL, template_or_name);
      template->def_inline = TRUE;
    }
  return template;
}

static gboolean
cfg_check_template(LogTemplate *template)
{
  GError *error = NULL;
  if (!log_template_compile(template, &error))
    {
      msg_error("Error compiling template",
                evt_tag_str("template", template->template),
                evt_tag_str("error", error->message),
                NULL);
      g_clear_error(&error);
      return FALSE;
    }
  return TRUE;
}




/* Line 268 of yacc.c  */
#line 170 "cfg-grammar.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_SOURCE = 258,
     KW_FILTER = 259,
     KW_PARSER = 260,
     KW_DESTINATION = 261,
     KW_LOG = 262,
     KW_OPTIONS = 263,
     KW_INCLUDE = 264,
     KW_INTERNAL = 265,
     KW_FILE = 266,
     KW_PIPE = 267,
     KW_UNIX_STREAM = 268,
     KW_UNIX_DGRAM = 269,
     KW_TCP = 270,
     KW_UDP = 271,
     KW_TCP6 = 272,
     KW_UDP6 = 273,
     KW_USERTTY = 274,
     KW_DOOR = 275,
     KW_SUN_STREAMS = 276,
     KW_PROGRAM = 277,
     KW_SQL = 278,
     KW_TYPE = 279,
     KW_COLUMNS = 280,
     KW_INDEXES = 281,
     KW_VALUES = 282,
     KW_PASSWORD = 283,
     KW_DATABASE = 284,
     KW_USERNAME = 285,
     KW_TABLE = 286,
     KW_ENCODING = 287,
     KW_DELIMITERS = 288,
     KW_QUOTES = 289,
     KW_QUOTE_PAIRS = 290,
     KW_NULL = 291,
     KW_SYSLOG = 292,
     KW_TRANSPORT = 293,
     KW_FSYNC = 294,
     KW_MARK_FREQ = 295,
     KW_STATS_FREQ = 296,
     KW_STATS_LEVEL = 297,
     KW_FLUSH_LINES = 298,
     KW_SUPPRESS = 299,
     KW_FLUSH_TIMEOUT = 300,
     KW_LOG_MSG_SIZE = 301,
     KW_FILE_TEMPLATE = 302,
     KW_PROTO_TEMPLATE = 303,
     KW_CHAIN_HOSTNAMES = 304,
     KW_NORMALIZE_HOSTNAMES = 305,
     KW_KEEP_HOSTNAME = 306,
     KW_CHECK_HOSTNAME = 307,
     KW_BAD_HOSTNAME = 308,
     KW_KEEP_TIMESTAMP = 309,
     KW_USE_DNS = 310,
     KW_USE_FQDN = 311,
     KW_DNS_CACHE = 312,
     KW_DNS_CACHE_SIZE = 313,
     KW_DNS_CACHE_EXPIRE = 314,
     KW_DNS_CACHE_EXPIRE_FAILED = 315,
     KW_DNS_CACHE_HOSTS = 316,
     KW_PERSIST_ONLY = 317,
     KW_TZ_CONVERT = 318,
     KW_TS_FORMAT = 319,
     KW_FRAC_DIGITS = 320,
     KW_LOG_FIFO_SIZE = 321,
     KW_LOG_DISK_FIFO_SIZE = 322,
     KW_LOG_FETCH_LIMIT = 323,
     KW_LOG_IW_SIZE = 324,
     KW_LOG_PREFIX = 325,
     KW_PROGRAM_OVERRIDE = 326,
     KW_HOST_OVERRIDE = 327,
     KW_THROTTLE = 328,
     KW_TLS = 329,
     KW_PEER_VERIFY = 330,
     KW_KEY_FILE = 331,
     KW_CERT_FILE = 332,
     KW_CA_DIR = 333,
     KW_CRL_DIR = 334,
     KW_TRUSTED_KEYS = 335,
     KW_TRUSTED_DN = 336,
     KW_FLAGS = 337,
     KW_PAD_SIZE = 338,
     KW_TIME_ZONE = 339,
     KW_RECV_TIME_ZONE = 340,
     KW_SEND_TIME_ZONE = 341,
     KW_LOCAL_TIME_ZONE = 342,
     KW_USE_MAC_MECH = 343,
     KW_HASH_FUNC = 344,
     KW_INITKEY_FILE = 345,
     KW_TIME_REOPEN = 346,
     KW_TIME_REAP = 347,
     KW_TIME_SLEEP = 348,
     KW_TMPL_ESCAPE = 349,
     KW_OPTIONAL = 350,
     KW_CREATE_DIRS = 351,
     KW_OWNER = 352,
     KW_GROUP = 353,
     KW_PERM = 354,
     KW_DIR_OWNER = 355,
     KW_DIR_GROUP = 356,
     KW_DIR_PERM = 357,
     KW_TEMPLATE = 358,
     KW_TEMPLATE_ESCAPE = 359,
     KW_FOLLOW_FREQ = 360,
     KW_OVERWRITE_IF_OLDER = 361,
     KW_DEFAULT_FACILITY = 362,
     KW_DEFAULT_LEVEL = 363,
     KW_KEEP_ALIVE = 364,
     KW_MAX_CONNECTIONS = 365,
     KW_LOCALIP = 366,
     KW_IP = 367,
     KW_LOCALPORT = 368,
     KW_PORT = 369,
     KW_DESTPORT = 370,
     KW_IP_TTL = 371,
     KW_SO_BROADCAST = 372,
     KW_IP_TOS = 373,
     KW_SO_SNDBUF = 374,
     KW_SO_RCVBUF = 375,
     KW_SO_KEEPALIVE = 376,
     KW_SPOOF_SOURCE = 377,
     KW_USE_TIME_RECVD = 378,
     KW_FACILITY = 379,
     KW_LEVEL = 380,
     KW_HOST = 381,
     KW_MATCH = 382,
     KW_MESSAGE = 383,
     KW_NETMASK = 384,
     KW_TAGS = 385,
     KW_CSV_PARSER = 386,
     KW_VALUE = 387,
     KW_DB_PARSER = 388,
     KW_REWRITE = 389,
     KW_SET = 390,
     KW_SUBST = 391,
     KW_YES = 392,
     KW_NO = 393,
     KW_GC_IDLE_THRESHOLD = 394,
     KW_GC_BUSY_THRESHOLD = 395,
     KW_COMPRESS = 396,
     KW_MAC = 397,
     KW_AUTH = 398,
     KW_ENCRYPT = 399,
     KW_IFDEF = 400,
     KW_ENDIF = 401,
     LL_DOTDOT = 402,
     LL_IDENTIFIER = 403,
     LL_NUMBER = 404,
     LL_FLOAT = 405,
     LL_STRING = 406,
     KW_OR = 407,
     KW_AND = 408,
     KW_NOT = 409
   };
#endif
/* Tokens.  */
#define KW_SOURCE 258
#define KW_FILTER 259
#define KW_PARSER 260
#define KW_DESTINATION 261
#define KW_LOG 262
#define KW_OPTIONS 263
#define KW_INCLUDE 264
#define KW_INTERNAL 265
#define KW_FILE 266
#define KW_PIPE 267
#define KW_UNIX_STREAM 268
#define KW_UNIX_DGRAM 269
#define KW_TCP 270
#define KW_UDP 271
#define KW_TCP6 272
#define KW_UDP6 273
#define KW_USERTTY 274
#define KW_DOOR 275
#define KW_SUN_STREAMS 276
#define KW_PROGRAM 277
#define KW_SQL 278
#define KW_TYPE 279
#define KW_COLUMNS 280
#define KW_INDEXES 281
#define KW_VALUES 282
#define KW_PASSWORD 283
#define KW_DATABASE 284
#define KW_USERNAME 285
#define KW_TABLE 286
#define KW_ENCODING 287
#define KW_DELIMITERS 288
#define KW_QUOTES 289
#define KW_QUOTE_PAIRS 290
#define KW_NULL 291
#define KW_SYSLOG 292
#define KW_TRANSPORT 293
#define KW_FSYNC 294
#define KW_MARK_FREQ 295
#define KW_STATS_FREQ 296
#define KW_STATS_LEVEL 297
#define KW_FLUSH_LINES 298
#define KW_SUPPRESS 299
#define KW_FLUSH_TIMEOUT 300
#define KW_LOG_MSG_SIZE 301
#define KW_FILE_TEMPLATE 302
#define KW_PROTO_TEMPLATE 303
#define KW_CHAIN_HOSTNAMES 304
#define KW_NORMALIZE_HOSTNAMES 305
#define KW_KEEP_HOSTNAME 306
#define KW_CHECK_HOSTNAME 307
#define KW_BAD_HOSTNAME 308
#define KW_KEEP_TIMESTAMP 309
#define KW_USE_DNS 310
#define KW_USE_FQDN 311
#define KW_DNS_CACHE 312
#define KW_DNS_CACHE_SIZE 313
#define KW_DNS_CACHE_EXPIRE 314
#define KW_DNS_CACHE_EXPIRE_FAILED 315
#define KW_DNS_CACHE_HOSTS 316
#define KW_PERSIST_ONLY 317
#define KW_TZ_CONVERT 318
#define KW_TS_FORMAT 319
#define KW_FRAC_DIGITS 320
#define KW_LOG_FIFO_SIZE 321
#define KW_LOG_DISK_FIFO_SIZE 322
#define KW_LOG_FETCH_LIMIT 323
#define KW_LOG_IW_SIZE 324
#define KW_LOG_PREFIX 325
#define KW_PROGRAM_OVERRIDE 326
#define KW_HOST_OVERRIDE 327
#define KW_THROTTLE 328
#define KW_TLS 329
#define KW_PEER_VERIFY 330
#define KW_KEY_FILE 331
#define KW_CERT_FILE 332
#define KW_CA_DIR 333
#define KW_CRL_DIR 334
#define KW_TRUSTED_KEYS 335
#define KW_TRUSTED_DN 336
#define KW_FLAGS 337
#define KW_PAD_SIZE 338
#define KW_TIME_ZONE 339
#define KW_RECV_TIME_ZONE 340
#define KW_SEND_TIME_ZONE 341
#define KW_LOCAL_TIME_ZONE 342
#define KW_USE_MAC_MECH 343
#define KW_HASH_FUNC 344
#define KW_INITKEY_FILE 345
#define KW_TIME_REOPEN 346
#define KW_TIME_REAP 347
#define KW_TIME_SLEEP 348
#define KW_TMPL_ESCAPE 349
#define KW_OPTIONAL 350
#define KW_CREATE_DIRS 351
#define KW_OWNER 352
#define KW_GROUP 353
#define KW_PERM 354
#define KW_DIR_OWNER 355
#define KW_DIR_GROUP 356
#define KW_DIR_PERM 357
#define KW_TEMPLATE 358
#define KW_TEMPLATE_ESCAPE 359
#define KW_FOLLOW_FREQ 360
#define KW_OVERWRITE_IF_OLDER 361
#define KW_DEFAULT_FACILITY 362
#define KW_DEFAULT_LEVEL 363
#define KW_KEEP_ALIVE 364
#define KW_MAX_CONNECTIONS 365
#define KW_LOCALIP 366
#define KW_IP 367
#define KW_LOCALPORT 368
#define KW_PORT 369
#define KW_DESTPORT 370
#define KW_IP_TTL 371
#define KW_SO_BROADCAST 372
#define KW_IP_TOS 373
#define KW_SO_SNDBUF 374
#define KW_SO_RCVBUF 375
#define KW_SO_KEEPALIVE 376
#define KW_SPOOF_SOURCE 377
#define KW_USE_TIME_RECVD 378
#define KW_FACILITY 379
#define KW_LEVEL 380
#define KW_HOST 381
#define KW_MATCH 382
#define KW_MESSAGE 383
#define KW_NETMASK 384
#define KW_TAGS 385
#define KW_CSV_PARSER 386
#define KW_VALUE 387
#define KW_DB_PARSER 388
#define KW_REWRITE 389
#define KW_SET 390
#define KW_SUBST 391
#define KW_YES 392
#define KW_NO 393
#define KW_GC_IDLE_THRESHOLD 394
#define KW_GC_BUSY_THRESHOLD 395
#define KW_COMPRESS 396
#define KW_MAC 397
#define KW_AUTH 398
#define KW_ENCRYPT 399
#define KW_IFDEF 400
#define KW_ENDIF 401
#define LL_DOTDOT 402
#define LL_IDENTIFIER 403
#define LL_NUMBER 404
#define LL_FLOAT 405
#define LL_STRING 406
#define KW_OR 407
#define KW_AND 408
#define KW_NOT 409




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 99 "cfg-grammar.y"

        gint token;
	gint64 num;
	double fnum;
	char *cptr;
	void *ptr;
	FilterExprNode *node;



/* Line 293 of yacc.c  */
#line 525 "cfg-grammar.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 537 "cfg-grammar.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2591

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  160
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  479
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   409

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     158,   159,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   155,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   156,     2,   157,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    11,    12,    15,    18,    21,
      24,    27,    30,    33,    36,    39,    44,    50,    56,    61,
      66,    72,    74,    78,    79,    84,    89,    94,    99,   104,
     107,   108,   116,   122,   123,   126,   127,   131,   132,   138,
     142,   143,   148,   153,   158,   163,   168,   173,   175,   180,
     185,   189,   190,   192,   194,   196,   198,   200,   202,   206,
     211,   216,   217,   221,   222,   226,   231,   233,   238,   243,
     244,   250,   251,   257,   258,   264,   265,   271,   272,   276,
     277,   281,   284,   285,   290,   294,   299,   303,   308,   312,
     317,   319,   321,   323,   324,   327,   330,   331,   333,   338,
     343,   348,   353,   355,   357,   358,   361,   364,   365,   367,
     368,   374,   376,   381,   386,   387,   393,   394,   397,   400,
     401,   403,   408,   413,   418,   423,   424,   430,   432,   437,
     438,   442,   444,   449,   451,   452,   456,   459,   460,   462,
     467,   469,   472,   473,   478,   483,   488,   493,   498,   503,
     508,   513,   518,   523,   528,   533,   538,   543,   548,   553,
     558,   563,   568,   573,   578,   583,   588,   591,   592,   596,
     597,   599,   601,   603,   605,   607,   609,   611,   616,   617,
     621,   624,   625,   627,   632,   637,   641,   646,   650,   655,
     659,   664,   668,   673,   677,   682,   686,   691,   696,   701,
     706,   711,   712,   716,   719,   720,   722,   727,   731,   736,
     740,   745,   749,   754,   759,   760,   766,   767,   773,   774,
     780,   781,   787,   788,   792,   793,   797,   800,   801,   803,
     805,   807,   808,   812,   815,   816,   821,   826,   831,   836,
     838,   840,   842,   844,   849,   850,   854,   857,   858,   860,
     861,   867,   872,   877,   878,   882,   885,   886,   888,   893,
     898,   903,   908,   913,   914,   920,   925,   930,   931,   935,
     940,   941,   944,   947,   948,   950,   955,   960,   965,   970,
     975,   980,   985,   990,   995,  1000,  1005,  1010,  1015,  1020,
    1025,  1030,  1032,  1035,  1036,  1041,  1046,  1051,  1056,  1061,
    1066,  1071,  1076,  1081,  1086,  1091,  1094,  1095,  1099,  1100,
    1105,  1110,  1115,  1120,  1125,  1130,  1135,  1140,  1145,  1150,
    1155,  1160,  1165,  1170,  1175,  1180,  1185,  1190,  1195,  1200,
    1205,  1210,  1215,  1220,  1225,  1230,  1235,  1239,  1244,  1248,
    1253,  1257,  1262,  1266,  1271,  1275,  1280,  1284,  1289,  1294,
    1299,  1304,  1309,  1314,  1319,  1324,  1329,  1334,  1339,  1344,
    1349,  1352,  1353,  1355,  1360,  1365,  1370,  1375,  1380,  1385,
    1390,  1392,  1394,  1397,  1401,  1405,  1409,  1414,  1419,  1424,
    1429,  1434,  1439,  1440,  1447,  1448,  1455,  1456,  1463,  1464,
    1471,  1472,  1479,  1482,  1483,  1485,  1490,  1493,  1494,  1499,
    1504,  1507,  1508,  1511,  1513,  1516,  1518,  1522,  1524,  1525,
    1531,  1532,  1538,  1541,  1542,  1547,  1549,  1554,  1559,  1562,
    1563,  1565,  1570,  1575,  1580,  1585,  1590,  1593,  1594,  1596,
    1599,  1600,  1601,  1610,  1611,  1619,  1622,  1623,  1628,  1633,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1658,  1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,
    1698,  1700,  1702,  1704,  1706,  1708,  1711,  1712,  1714,  1716
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     161,     0,    -1,   162,    -1,    -1,   164,   155,   163,   162,
      -1,    -1,     3,   165,    -1,     6,   169,    -1,     7,   170,
      -1,     4,   166,    -1,     5,   167,    -1,   134,   168,    -1,
     103,   179,    -1,     8,   178,    -1,     9,   171,    -1,   324,
     156,   185,   157,    -1,   324,   156,   290,   155,   157,    -1,
     324,   156,   305,   155,   157,    -1,   324,   156,   315,   157,
      -1,   324,   156,   234,   157,    -1,   156,   172,   174,   176,
     157,    -1,   324,    -1,   173,   155,   172,    -1,    -1,     3,
     158,   324,   159,    -1,     4,   158,   324,   159,    -1,     5,
     158,   324,   159,    -1,   134,   158,   324,   159,    -1,     6,
     158,   324,   159,    -1,   175,   174,    -1,    -1,     7,   156,
     172,   174,   176,   157,   155,    -1,    82,   158,   177,   159,
     155,    -1,    -1,   324,   177,    -1,    -1,   156,   286,   157,
      -1,    -1,   324,   180,   156,   181,   157,    -1,   182,   155,
     181,    -1,    -1,   103,   158,   324,   159,    -1,   104,   158,
     322,   159,    -1,   119,   158,   149,   159,    -1,   120,   158,
     149,   159,    -1,   117,   158,   322,   159,    -1,   121,   158,
     322,   159,    -1,   183,    -1,   116,   158,   149,   159,    -1,
     118,   158,   149,   159,    -1,   186,   155,   185,    -1,    -1,
     187,    -1,   188,    -1,   194,    -1,   216,    -1,   226,    -1,
     223,    -1,    10,   158,   159,    -1,    11,   158,   189,   159,
      -1,    12,   158,   191,   159,    -1,    -1,   324,   190,   231,
      -1,    -1,   324,   192,   193,    -1,    95,   158,   322,   159,
      -1,   231,    -1,    14,   158,   199,   159,    -1,    13,   158,
     201,   159,    -1,    -1,    16,   195,   158,   205,   159,    -1,
      -1,    15,   196,   158,   210,   159,    -1,    -1,    18,   197,
     158,   205,   159,    -1,    -1,    17,   198,   158,   210,   159,
      -1,    -1,   324,   200,   203,    -1,    -1,   324,   202,   203,
      -1,   204,   203,    -1,    -1,    97,   158,   326,   159,    -1,
      97,   158,   159,    -1,    98,   158,   326,   159,    -1,    98,
     158,   159,    -1,    99,   158,   149,   159,    -1,    99,   158,
     159,    -1,    95,   158,   322,   159,    -1,   215,    -1,   232,
      -1,   183,    -1,    -1,   206,   207,    -1,   208,   207,    -1,
      -1,   209,    -1,   111,   158,   324,   159,    -1,   112,   158,
     324,   159,    -1,   113,   158,   326,   159,    -1,   114,   158,
     326,   159,    -1,   232,    -1,   184,    -1,    -1,   211,   212,
      -1,   213,   212,    -1,    -1,   209,    -1,    -1,    74,   214,
     158,   288,   159,    -1,   215,    -1,   109,   158,   322,   159,
      -1,   110,   158,   149,   159,    -1,    -1,    37,   217,   158,
     218,   159,    -1,    -1,   219,   220,    -1,   221,   220,    -1,
      -1,   209,    -1,    38,   158,   324,   159,    -1,    38,   158,
      15,   159,    -1,    38,   158,    16,   159,    -1,    38,   158,
      74,   159,    -1,    -1,    74,   222,   158,   288,   159,    -1,
     215,    -1,    22,   158,   224,   159,    -1,    -1,   324,   225,
     231,    -1,   145,    -1,    21,   158,   227,   159,    -1,   146,
      -1,    -1,   324,   228,   229,    -1,   230,   229,    -1,    -1,
     145,    -1,    20,   158,   324,   159,    -1,   146,    -1,   232,
     231,    -1,    -1,    69,   158,   149,   159,    -1,    49,   158,
     322,   159,    -1,    50,   158,   322,   159,    -1,    51,   158,
     322,   159,    -1,    56,   158,   322,   159,    -1,    55,   158,
     323,   159,    -1,    57,   158,   322,   159,    -1,    71,   158,
     324,   159,    -1,    72,   158,   324,   159,    -1,    70,   158,
     324,   159,    -1,    84,   158,   324,   159,    -1,    52,   158,
     322,   159,    -1,    82,   158,   233,   159,    -1,    46,   158,
     149,   159,    -1,    68,   158,   149,   159,    -1,    83,   158,
     149,   159,    -1,   105,   158,   150,   159,    -1,   105,   158,
     149,   159,    -1,    54,   158,   322,   159,    -1,    32,   158,
     324,   159,    -1,   130,   158,   327,   159,    -1,   108,   158,
     329,   159,    -1,   107,   158,   330,   159,    -1,   324,   233,
      -1,    -1,   235,   155,   234,    -1,    -1,   236,    -1,   241,
      -1,   246,    -1,   274,    -1,   275,    -1,   268,    -1,   278,
      -1,    11,   158,   237,   159,    -1,    -1,   324,   238,   239,
      -1,   240,   239,    -1,    -1,   284,    -1,    95,   158,   322,
     159,    -1,    97,   158,   326,   159,    -1,    97,   158,   159,
      -1,    98,   158,   326,   159,    -1,    98,   158,   159,    -1,
      99,   158,   149,   159,    -1,    99,   158,   159,    -1,   100,
     158,   326,   159,    -1,   100,   158,   159,    -1,   101,   158,
     326,   159,    -1,   101,   158,   159,    -1,   102,   158,   149,
     159,    -1,   102,   158,   159,    -1,    96,   158,   322,   159,
      -1,   106,   158,   149,   159,    -1,    39,   158,   322,   159,
      -1,    87,   158,   324,   159,    -1,    12,   158,   242,   159,
      -1,    -1,   324,   243,   244,    -1,   245,   244,    -1,    -1,
     284,    -1,    97,   158,   326,   159,    -1,    97,   158,   159,
      -1,    98,   158,   326,   159,    -1,    98,   158,   159,    -1,
      99,   158,   149,   159,    -1,    99,   158,   159,    -1,    14,
     158,   251,   159,    -1,    13,   158,   253,   159,    -1,    -1,
      16,   247,   158,   257,   159,    -1,    -1,    15,   248,   158,
     262,   159,    -1,    -1,    18,   249,   158,   257,   159,    -1,
      -1,    17,   250,   158,   262,   159,    -1,    -1,   324,   252,
     255,    -1,    -1,   324,   254,   255,    -1,   255,   256,    -1,
      -1,   284,    -1,   267,    -1,   183,    -1,    -1,   324,   258,
     259,    -1,   259,   261,    -1,    -1,   111,   158,   324,   159,
      -1,   113,   158,   326,   159,    -1,   114,   158,   326,   159,
      -1,   115,   158,   326,   159,    -1,   184,    -1,   284,    -1,
     267,    -1,   260,    -1,   122,   158,   322,   159,    -1,    -1,
     324,   263,   264,    -1,   264,   265,    -1,    -1,   260,    -1,
      -1,    74,   266,   158,   288,   159,    -1,   109,   158,   322,
     159,    -1,    37,   158,   269,   159,    -1,    -1,   324,   270,
     271,    -1,   271,   272,    -1,    -1,   260,    -1,    38,   158,
     324,   159,    -1,    38,   158,    15,   159,    -1,    38,   158,
      16,   159,    -1,    38,   158,    74,   159,    -1,   122,   158,
     322,   159,    -1,    -1,    74,   273,   158,   288,   159,    -1,
      19,   158,   324,   159,    -1,    22,   158,   276,   159,    -1,
      -1,   324,   277,   283,    -1,    23,   158,   279,   159,    -1,
      -1,   280,   281,    -1,   282,   281,    -1,    -1,   145,    -1,
      24,   158,   324,   159,    -1,   126,   158,   324,   159,    -1,
     114,   158,   326,   159,    -1,    30,   158,   324,   159,    -1,
      28,   158,   324,   159,    -1,    29,   158,   324,   159,    -1,
      31,   158,   324,   159,    -1,    25,   158,   327,   159,    -1,
      26,   158,   327,   159,    -1,    27,   158,   327,   159,    -1,
      66,   158,   149,   159,    -1,    67,   158,   149,   159,    -1,
      65,   158,   149,   159,    -1,    84,   158,   324,   159,    -1,
      87,   158,   324,   159,    -1,    36,   158,   324,   159,    -1,
     146,    -1,   284,   283,    -1,    -1,    82,   158,   285,   159,
      -1,    66,   158,   149,   159,    -1,    43,   158,   149,   159,
      -1,    45,   158,   149,   159,    -1,    44,   158,   149,   159,
      -1,   103,   158,   324,   159,    -1,   104,   158,   322,   159,
      -1,    84,   158,   324,   159,    -1,    64,   158,   324,   159,
      -1,    65,   158,   149,   159,    -1,    73,   158,   149,   159,
      -1,   324,   285,    -1,    -1,   287,   155,   286,    -1,    -1,
      40,   158,   149,   159,    -1,    41,   158,   149,   159,    -1,
      42,   158,   149,   159,    -1,    43,   158,   149,   159,    -1,
      45,   158,   149,   159,    -1,    49,   158,   322,   159,    -1,
      50,   158,   322,   159,    -1,    51,   158,   322,   159,    -1,
      52,   158,   322,   159,    -1,    53,   158,   324,   159,    -1,
     123,   158,   322,   159,    -1,    56,   158,   322,   159,    -1,
      55,   158,   323,   159,    -1,    91,   158,   149,   159,    -1,
      92,   158,   149,   159,    -1,    93,   158,   149,   159,    -1,
      66,   158,   149,   159,    -1,    69,   158,   149,   159,    -1,
      68,   158,   149,   159,    -1,    46,   158,   149,   159,    -1,
      54,   158,   322,   159,    -1,    64,   158,   324,   159,    -1,
      65,   158,   149,   159,    -1,   140,   158,   149,   159,    -1,
     139,   158,   149,   159,    -1,    96,   158,   322,   159,    -1,
      97,   158,   326,   159,    -1,    97,   158,   159,    -1,    98,
     158,   326,   159,    -1,    98,   158,   159,    -1,    99,   158,
     149,   159,    -1,    99,   158,   159,    -1,   100,   158,   326,
     159,    -1,   100,   158,   159,    -1,   101,   158,   326,   159,
      -1,   101,   158,   159,    -1,   102,   158,   149,   159,    -1,
     102,   158,   159,    -1,    57,   158,   322,   159,    -1,    58,
     158,   149,   159,    -1,    59,   158,   149,   159,    -1,    60,
     158,   149,   159,    -1,    61,   158,   324,   159,    -1,    47,
     158,   324,   159,    -1,    48,   158,   324,   159,    -1,    85,
     158,   324,   159,    -1,    86,   158,   324,   159,    -1,    87,
     158,   324,   159,    -1,    88,   158,   322,   159,    -1,    89,
     158,   324,   159,    -1,    90,   158,   324,   159,    -1,   289,
     288,    -1,    -1,   145,    -1,    75,   158,   324,   159,    -1,
      76,   158,   324,   159,    -1,    77,   158,   324,   159,    -1,
      78,   158,   324,   159,    -1,    79,   158,   324,   159,    -1,
      80,   158,   327,   159,    -1,    81,   158,   327,   159,    -1,
     146,    -1,   291,    -1,   154,   290,    -1,   290,   152,   290,
      -1,   290,   153,   290,    -1,   158,   290,   159,    -1,   124,
     158,   302,   159,    -1,   124,   158,   149,   159,    -1,   125,
     158,   303,   159,    -1,     4,   158,   324,   159,    -1,   129,
     158,   324,   159,    -1,   130,   158,   327,   159,    -1,    -1,
      22,   158,   324,   292,   299,   159,    -1,    -1,   126,   158,
     324,   293,   299,   159,    -1,    -1,   127,   158,   324,   294,
     297,   159,    -1,    -1,   128,   158,   324,   295,   299,   159,
      -1,    -1,     3,   158,   324,   296,   299,   159,    -1,   298,
     297,    -1,    -1,   300,    -1,   132,   158,   324,   159,    -1,
     300,   299,    -1,    -1,    24,   158,   324,   159,    -1,    82,
     158,   301,   159,    -1,   324,   301,    -1,    -1,   330,   302,
      -1,   330,    -1,   304,   303,    -1,   304,    -1,   329,   147,
     329,    -1,   329,    -1,    -1,   131,   158,   306,   312,   159,
      -1,    -1,   133,   158,   307,   308,   159,    -1,   309,   308,
      -1,    -1,    11,   158,   324,   159,    -1,   311,    -1,    25,
     158,   327,   159,    -1,   103,   158,   324,   159,    -1,   313,
     312,    -1,    -1,   310,    -1,    82,   158,   314,   159,    -1,
      33,   158,   324,   159,    -1,    34,   158,   324,   159,    -1,
      35,   158,   324,   159,    -1,    36,   158,   324,   159,    -1,
     324,   314,    -1,    -1,   316,    -1,   317,   316,    -1,    -1,
      -1,   136,   158,   324,   324,   318,   320,   159,   155,    -1,
      -1,   135,   158,   324,   319,   320,   159,   155,    -1,   321,
     320,    -1,    -1,   132,   158,   324,   159,    -1,    24,   158,
     324,   159,    -1,    82,   158,   301,   159,    -1,   137,    -1,
     138,    -1,   149,    -1,   322,    -1,    62,    -1,   148,    -1,
     151,    -1,   325,    -1,     5,    -1,   134,    -1,     9,    -1,
      25,    -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,
     131,    -1,   133,    -1,    32,    -1,   135,    -1,   136,    -1,
     132,    -1,    71,    -1,    72,    -1,    38,    -1,    80,    -1,
      81,    -1,   128,    -1,    24,    -1,    23,    -1,   107,    -1,
     108,    -1,   324,    -1,   149,    -1,   328,    -1,   324,   328,
      -1,    -1,   324,    -1,   324,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   322,   322,   327,   326,   341,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   357,   361,   365,   368,   371,
     375,   379,   382,   383,   387,   388,   389,   390,   391,   395,
     396,   400,   404,   405,   410,   411,   416,   421,   420,   429,
     430,   434,   435,   439,   440,   441,   442,   446,   447,   448,
     452,   453,   457,   458,   459,   460,   461,   462,   466,   470,
     471,   476,   475,   486,   485,   495,   496,   500,   501,   502,
     502,   503,   503,   504,   504,   505,   505,   510,   509,   523,
     522,   536,   537,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   555,   555,   566,   567,   571,   575,   576,
     577,   578,   579,   580,   585,   585,   596,   597,   601,   604,
     603,   616,   620,   621,   625,   625,   630,   630,   641,   642,
     646,   647,   648,   649,   650,   652,   651,   663,   667,   672,
     671,   681,   684,   685,   692,   691,   702,   703,   707,   710,
     711,   717,   718,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   749,   758,   759,   764,   765,
     769,   770,   771,   772,   773,   774,   776,   781,   786,   785,
     796,   797,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   812,   813,   814,   815,   816,   817,   818,
     822,   827,   826,   837,   838,   842,   843,   844,   845,   846,
     847,   848,   852,   853,   854,   854,   855,   855,   856,   856,
     857,   857,   862,   861,   873,   872,   883,   884,   888,   889,
     890,   895,   894,   907,   908,   913,   914,   915,   916,   917,
     918,   919,   923,   924,   929,   928,   941,   942,   946,   948,
     947,   962,   967,   971,   970,   982,   983,   987,   988,   989,
     990,   991,   992,   994,   993,  1009,  1013,  1018,  1017,  1029,
    1034,  1034,  1043,  1044,  1048,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1068,  1076,  1077,  1081,  1082,  1083,  1084,  1085,  1086,
    1094,  1095,  1096,  1097,  1098,  1103,  1104,  1109,  1110,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1178,  1179,  1183,  1187,  1192,  1197,  1202,  1207,  1212,  1216,
    1220,  1228,  1229,  1230,  1231,  1232,  1236,  1237,  1238,  1239,
    1240,  1241,  1243,  1242,  1255,  1254,  1267,  1266,  1290,  1289,
    1301,  1300,  1315,  1316,  1320,  1321,  1337,  1338,  1342,  1347,
    1351,  1352,  1357,  1358,  1362,  1363,  1367,  1371,  1380,  1379,
    1386,  1385,  1394,  1395,  1400,  1404,  1405,  1409,  1422,  1423,
    1427,  1428,  1429,  1430,  1431,  1432,  1436,  1437,  1441,  1445,
    1446,  1451,  1450,  1463,  1462,  1471,  1472,  1476,  1496,  1507,
    1511,  1512,  1513,  1517,  1518,  1522,  1523,  1524,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,  1540,
    1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,
    1551,  1552,  1556,  1557,  1561,  1565,  1566,  1570,  1587,  1601
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_SOURCE", "KW_FILTER", "KW_PARSER",
  "KW_DESTINATION", "KW_LOG", "KW_OPTIONS", "KW_INCLUDE", "KW_INTERNAL",
  "KW_FILE", "KW_PIPE", "KW_UNIX_STREAM", "KW_UNIX_DGRAM", "KW_TCP",
  "KW_UDP", "KW_TCP6", "KW_UDP6", "KW_USERTTY", "KW_DOOR",
  "KW_SUN_STREAMS", "KW_PROGRAM", "KW_SQL", "KW_TYPE", "KW_COLUMNS",
  "KW_INDEXES", "KW_VALUES", "KW_PASSWORD", "KW_DATABASE", "KW_USERNAME",
  "KW_TABLE", "KW_ENCODING", "KW_DELIMITERS", "KW_QUOTES",
  "KW_QUOTE_PAIRS", "KW_NULL", "KW_SYSLOG", "KW_TRANSPORT", "KW_FSYNC",
  "KW_MARK_FREQ", "KW_STATS_FREQ", "KW_STATS_LEVEL", "KW_FLUSH_LINES",
  "KW_SUPPRESS", "KW_FLUSH_TIMEOUT", "KW_LOG_MSG_SIZE", "KW_FILE_TEMPLATE",
  "KW_PROTO_TEMPLATE", "KW_CHAIN_HOSTNAMES", "KW_NORMALIZE_HOSTNAMES",
  "KW_KEEP_HOSTNAME", "KW_CHECK_HOSTNAME", "KW_BAD_HOSTNAME",
  "KW_KEEP_TIMESTAMP", "KW_USE_DNS", "KW_USE_FQDN", "KW_DNS_CACHE",
  "KW_DNS_CACHE_SIZE", "KW_DNS_CACHE_EXPIRE", "KW_DNS_CACHE_EXPIRE_FAILED",
  "KW_DNS_CACHE_HOSTS", "KW_PERSIST_ONLY", "KW_TZ_CONVERT", "KW_TS_FORMAT",
  "KW_FRAC_DIGITS", "KW_LOG_FIFO_SIZE", "KW_LOG_DISK_FIFO_SIZE",
  "KW_LOG_FETCH_LIMIT", "KW_LOG_IW_SIZE", "KW_LOG_PREFIX",
  "KW_PROGRAM_OVERRIDE", "KW_HOST_OVERRIDE", "KW_THROTTLE", "KW_TLS",
  "KW_PEER_VERIFY", "KW_KEY_FILE", "KW_CERT_FILE", "KW_CA_DIR",
  "KW_CRL_DIR", "KW_TRUSTED_KEYS", "KW_TRUSTED_DN", "KW_FLAGS",
  "KW_PAD_SIZE", "KW_TIME_ZONE", "KW_RECV_TIME_ZONE", "KW_SEND_TIME_ZONE",
  "KW_LOCAL_TIME_ZONE", "KW_USE_MAC_MECH", "KW_HASH_FUNC",
  "KW_INITKEY_FILE", "KW_TIME_REOPEN", "KW_TIME_REAP", "KW_TIME_SLEEP",
  "KW_TMPL_ESCAPE", "KW_OPTIONAL", "KW_CREATE_DIRS", "KW_OWNER",
  "KW_GROUP", "KW_PERM", "KW_DIR_OWNER", "KW_DIR_GROUP", "KW_DIR_PERM",
  "KW_TEMPLATE", "KW_TEMPLATE_ESCAPE", "KW_FOLLOW_FREQ",
  "KW_OVERWRITE_IF_OLDER", "KW_DEFAULT_FACILITY", "KW_DEFAULT_LEVEL",
  "KW_KEEP_ALIVE", "KW_MAX_CONNECTIONS", "KW_LOCALIP", "KW_IP",
  "KW_LOCALPORT", "KW_PORT", "KW_DESTPORT", "KW_IP_TTL", "KW_SO_BROADCAST",
  "KW_IP_TOS", "KW_SO_SNDBUF", "KW_SO_RCVBUF", "KW_SO_KEEPALIVE",
  "KW_SPOOF_SOURCE", "KW_USE_TIME_RECVD", "KW_FACILITY", "KW_LEVEL",
  "KW_HOST", "KW_MATCH", "KW_MESSAGE", "KW_NETMASK", "KW_TAGS",
  "KW_CSV_PARSER", "KW_VALUE", "KW_DB_PARSER", "KW_REWRITE", "KW_SET",
  "KW_SUBST", "KW_YES", "KW_NO", "KW_GC_IDLE_THRESHOLD",
  "KW_GC_BUSY_THRESHOLD", "KW_COMPRESS", "KW_MAC", "KW_AUTH", "KW_ENCRYPT",
  "KW_IFDEF", "KW_ENDIF", "LL_DOTDOT", "LL_IDENTIFIER", "LL_NUMBER",
  "LL_FLOAT", "LL_STRING", "KW_OR", "KW_AND", "KW_NOT", "';'", "'{'",
  "'}'", "'('", "')'", "$accept", "start", "stmts", "$@1", "stmt",
  "source_stmt", "filter_stmt", "parser_stmt", "rewrite_stmt", "dest_stmt",
  "log_stmt", "include_stmt", "log_items", "log_item", "log_forks",
  "log_fork", "log_flags", "log_flags_items", "options_stmt",
  "template_stmt", "$@2", "template_items", "template_item",
  "socket_option", "inet_socket_option", "source_items", "source_item",
  "source_afinter", "source_affile", "source_affile_params", "$@3",
  "source_afpipe_params", "$@4", "source_afpipe_options",
  "source_afsocket", "$@5", "$@6", "$@7", "$@8",
  "source_afunix_dgram_params", "$@9", "source_afunix_stream_params",
  "$@10", "source_afunix_options", "source_afunix_option",
  "source_afinet_udp_params", "$@11", "source_afinet_udp_options",
  "source_afinet_udp_option", "source_afinet_option",
  "source_afinet_tcp_params", "$@12", "source_afinet_tcp_options",
  "source_afinet_tcp_option", "$@13", "source_afsocket_stream_params",
  "source_afsyslog", "$@14", "source_afsyslog_params", "$@15",
  "source_afsyslog_options", "source_afsyslog_option", "$@16",
  "source_afprogram", "source_afprogram_params", "$@17",
  "source_afstreams", "source_afstreams_params", "$@18",
  "source_afstreams_options", "source_afstreams_option",
  "source_reader_options", "source_reader_option",
  "source_reader_option_flags", "dest_items", "dest_item", "dest_affile",
  "dest_affile_params", "$@19", "dest_affile_options",
  "dest_affile_option", "dest_afpipe", "dest_afpipe_params", "$@20",
  "dest_afpipe_options", "dest_afpipe_option", "dest_afsocket", "$@21",
  "$@22", "$@23", "$@24", "dest_afunix_dgram_params", "$@25",
  "dest_afunix_stream_params", "$@26", "dest_afunix_options",
  "dest_afunix_option", "dest_afinet_udp_params", "$@27",
  "dest_afinet_udp_options", "dest_afinet_option",
  "dest_afinet_udp_option", "dest_afinet_tcp_params", "$@28",
  "dest_afinet_tcp_options", "dest_afinet_tcp_option", "$@29",
  "dest_afsocket_option", "dest_afsyslog", "dest_afsyslog_params", "$@30",
  "dest_afsyslog_options", "dest_afsyslog_option", "$@31", "dest_afuser",
  "dest_afprogram", "dest_afprogram_params", "$@32", "dest_afsql",
  "dest_afsql_params", "$@33", "dest_afsql_options", "dest_afsql_option",
  "dest_writer_options", "dest_writer_option", "dest_writer_options_flags",
  "options_items", "options_item", "tls_options", "tls_option",
  "filter_expr", "filter_simple_expr", "$@34", "$@35", "$@36", "$@37",
  "$@38", "filter_match_opts", "filter_match_opt", "filter_re_opts",
  "filter_re_opt", "regexp_option_flags", "filter_fac_list",
  "filter_level_list", "filter_level", "parser_expr", "$@39", "$@40",
  "parser_db_opts", "parser_db_opt", "parser_column_opt", "parser_opt",
  "parser_csv_opts", "parser_csv_opt", "parser_csv_flags",
  "rewrite_expr_list", "rewrite_expr_list_build", "rewrite_expr", "$@41",
  "$@42", "rewrite_expr_opts", "rewrite_expr_opt", "yesno", "dnsmode",
  "string", "reserved_words_as_strings", "string_or_number", "string_list",
  "string_list_build", "level_string", "facility_string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,    59,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   160,   161,   163,   162,   162,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   172,   173,   173,   173,   173,   173,   174,
     174,   175,   176,   176,   177,   177,   178,   180,   179,   181,
     181,   182,   182,   183,   183,   183,   183,   184,   184,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   187,   188,
     188,   190,   189,   192,   191,   193,   193,   194,   194,   195,
     194,   196,   194,   197,   194,   198,   194,   200,   199,   202,
     201,   203,   203,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   206,   205,   207,   207,   208,   209,   209,
     209,   209,   209,   209,   211,   210,   212,   212,   213,   214,
     213,   213,   215,   215,   217,   216,   219,   218,   220,   220,
     221,   221,   221,   221,   221,   222,   221,   221,   223,   225,
     224,   226,   226,   226,   228,   227,   229,   229,   230,   230,
     230,   231,   231,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   236,   238,   237,
     239,   239,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     241,   243,   242,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   246,   246,   247,   246,   248,   246,   249,   246,
     250,   246,   252,   251,   254,   253,   255,   255,   256,   256,
     256,   258,   257,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   261,   261,   263,   262,   264,   264,   265,   266,
     265,   267,   268,   270,   269,   271,   271,   272,   272,   272,
     272,   272,   272,   273,   272,   274,   275,   277,   276,   278,
     280,   279,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     288,   288,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   290,   290,   290,   290,   290,   291,   291,   291,   291,
     291,   291,   292,   291,   293,   291,   294,   291,   295,   291,
     296,   291,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   303,   304,   304,   306,   305,
     307,   305,   308,   308,   309,   310,   310,   311,   312,   312,
     313,   313,   313,   313,   313,   313,   314,   314,   315,   316,
     316,   318,   317,   319,   317,   320,   320,   321,   321,   321,
     322,   322,   322,   323,   323,   324,   324,   324,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   326,   326,   327,   328,   328,   329,   330,   330
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     5,     5,     4,     4,
       5,     1,     3,     0,     4,     4,     4,     4,     4,     2,
       0,     7,     5,     0,     2,     0,     3,     0,     5,     3,
       0,     4,     4,     4,     4,     4,     4,     1,     4,     4,
       3,     0,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     0,     3,     0,     3,     4,     1,     4,     4,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     3,     0,
       3,     2,     0,     4,     3,     4,     3,     4,     3,     4,
       1,     1,     1,     0,     2,     2,     0,     1,     4,     4,
       4,     4,     1,     1,     0,     2,     2,     0,     1,     0,
       5,     1,     4,     4,     0,     5,     0,     2,     2,     0,
       1,     4,     4,     4,     4,     0,     5,     1,     4,     0,
       3,     1,     4,     1,     0,     3,     2,     0,     1,     4,
       1,     2,     0,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     0,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     3,
       2,     0,     1,     4,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     4,     4,     4,
       4,     0,     3,     2,     0,     1,     4,     3,     4,     3,
       4,     3,     4,     4,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     3,     0,     3,     2,     0,     1,     1,
       1,     0,     3,     2,     0,     4,     4,     4,     4,     1,
       1,     1,     1,     4,     0,     3,     2,     0,     1,     0,
       5,     4,     4,     0,     3,     2,     0,     1,     4,     4,
       4,     4,     4,     0,     5,     4,     4,     0,     3,     4,
       0,     2,     2,     0,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     2,     0,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     0,     3,     0,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       2,     0,     1,     4,     4,     4,     4,     4,     4,     4,
       1,     1,     2,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     2,     0,     1,     4,     2,     0,     4,     4,
       2,     0,     2,     1,     2,     1,     3,     1,     0,     5,
       0,     5,     2,     0,     4,     1,     4,     4,     2,     0,
       1,     4,     4,     4,     4,     4,     2,     0,     1,     2,
       0,     0,     8,     0,     7,     2,     0,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,   448,   450,   469,   468,   451,   458,   452,
     453,   454,   455,   464,   462,   463,   465,   466,   470,   471,
     467,   456,   461,   457,   449,   459,   460,   445,   446,     6,
       0,   447,     9,     0,    10,     0,     7,     0,    23,     8,
     308,    13,    14,    21,    12,    37,    11,     0,     1,     3,
      51,     0,     0,   169,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   430,
       5,     0,     0,     0,     0,     0,    71,    69,    75,    73,
       0,     0,   114,   131,   133,     0,     0,    52,    53,    54,
      55,    57,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   371,     0,     0,     0,
       0,     0,     0,     0,   216,   214,   220,   218,     0,     0,
       0,     0,     0,     0,   170,   171,   172,   175,   173,   174,
     176,     0,     0,     0,     0,     0,     0,    33,    30,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,   308,    40,     0,     0,
       0,   428,   430,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   476,   372,     0,
       0,     0,     0,   408,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,    19,   169,
       0,     0,     0,     0,     0,    23,     0,     0,    29,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   440,   441,
     442,     0,     0,     0,     0,     0,     0,   444,   443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,   336,   472,     0,   338,     0,     0,   340,   342,
       0,   344,     0,     0,   346,     0,     0,     0,   307,     0,
       0,     0,     0,     0,     0,    18,   429,    58,     0,    61,
       0,    63,     0,    79,     0,    77,   104,    93,   104,    93,
       0,   134,     0,   129,   116,    50,   390,     0,   382,   479,
       0,     0,   478,   403,     0,   405,   477,   407,   384,   386,
     388,     0,   476,     0,   474,   375,   373,   374,    16,   419,
     413,    17,     0,   178,     0,   201,     0,   224,     0,   222,
       0,     0,     0,     0,     0,     0,   267,     0,   273,     0,
     253,   168,    24,    25,    26,    28,    27,    30,    35,    20,
     309,   310,   311,   312,   313,   328,   352,   353,   314,   315,
     316,   317,   318,   329,   321,   320,   347,   348,   349,   350,
     351,   330,   331,   325,   327,   326,   354,   355,   356,   357,
     358,   359,   322,   323,   324,   334,   335,   337,   339,   341,
     343,   345,   319,   333,   332,     0,     0,    38,    40,   433,
       0,    59,   142,    60,   142,    68,    82,    67,    82,     0,
     107,     0,    96,     0,     0,   132,   137,   128,   142,     0,
     119,   397,   379,   397,   377,   376,   402,   378,   404,     0,
     397,   393,   397,   380,   475,   381,     0,     0,     0,     0,
       0,     0,     0,   420,   415,     0,   419,     0,     0,   413,
     177,   181,   200,   204,   213,   227,   212,   227,     0,   244,
       0,   231,     0,     0,   265,   266,   293,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   291,   271,   273,   252,   256,
      33,     0,    35,     0,     0,    39,   436,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,   142,     0,    64,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    80,    82,    90,    91,
      78,    72,   109,     0,     0,     0,     0,     0,     0,    47,
     103,   108,   105,   107,   111,   102,    70,    94,    96,    97,
      76,    74,     0,   138,   140,   135,   137,   130,   115,     0,
     125,   120,   127,   117,   119,     0,     0,     0,   397,     0,
     406,     0,     0,     0,   393,   394,     0,   476,     0,     0,
       0,     0,   427,     0,   409,   418,     0,   411,   412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   181,   182,     0,     0,     0,   202,   204,   205,
     225,   223,   217,   247,   215,   234,   221,   219,   268,   293,
       0,   476,   476,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   254,     0,     0,
      34,    41,    42,     0,     0,     0,     0,   436,   436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
     476,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,   106,    95,     0,   136,     0,     0,   118,     0,   401,
     391,   396,   383,   385,     0,   387,   392,   389,     0,     0,
       0,     0,     0,     0,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
       0,     0,     0,   203,     0,   230,   226,   229,   228,   245,
     232,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,   239,   257,   241,   255,   240,
       0,    32,     0,   401,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    86,     0,     0,    88,
       0,     0,     0,     0,     0,     0,   361,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   361,     0,
       0,   401,     0,   416,   422,   423,   424,   425,   421,   426,
     417,   414,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   185,     0,   187,     0,
       0,   189,   191,     0,   193,     0,     0,   195,     0,     0,
       0,   207,     0,   209,     0,     0,   211,     0,   249,   248,
     246,     0,   242,   233,   275,   282,   283,   284,   279,   280,
     278,   281,   290,   287,   285,   286,   288,   289,   277,   276,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,   434,     0,   162,   156,   144,   145,   146,   154,   161,
     148,   147,   149,   157,   143,   152,   150,   151,   155,   166,
     158,   153,   160,   159,   165,   164,   163,    65,    89,    83,
      85,    87,   112,   113,    45,    43,    44,    46,     0,     0,
       0,     0,     0,     0,     0,   362,   370,     0,   361,    98,
      99,   100,   101,    48,    49,   139,   122,   123,   124,   121,
       0,   398,   399,   400,   395,   198,   296,   298,   297,   302,
     303,   295,   304,   294,   305,   301,   199,   183,   196,   184,
     186,   188,   190,   192,   194,   299,   300,   197,   206,   208,
     210,     0,     0,     0,     0,     0,     0,     0,   361,     0,
       0,     0,     0,     0,   438,   439,   437,   432,     0,     0,
       0,     0,     0,   476,   476,   110,   360,   126,   251,   361,
       0,   259,   260,   261,   258,     0,   235,   236,   237,   238,
     262,     0,     0,     0,     0,     0,     0,     0,     0,   243,
     264,   363,   364,   365,   366,   367,   368,   369,   250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,   120,    12,    39,    42,    44,    56,    46,
      49,    52,    69,    70,   187,   188,   297,   581,    51,    54,
     118,   361,   362,   639,   640,   135,   136,   137,   138,   368,
     492,   370,   494,   613,   139,   250,   249,   252,   251,   374,
     498,   372,   496,   626,   627,   501,   502,   647,   648,   641,
     499,   500,   642,   643,   794,   628,   140,   255,   509,   510,
     663,   664,   806,   141,   382,   508,   142,   380,   506,   655,
     656,   610,   645,   913,   172,   173,   174,   412,   541,   711,
     712,   175,   414,   543,   717,   718,   176,   281,   280,   283,
     282,   418,   547,   416,   545,   720,   856,   550,   725,   860,
     886,  1003,   548,   723,   859,  1000,  1122,   887,   177,   429,
     579,   747,   888,  1021,   178,   179,   425,   556,   180,   427,
     428,   576,   577,   728,   889,   970,   116,   117,  1077,  1078,
     155,   156,   513,   520,   521,   522,   511,   673,   674,   667,
     668,   950,   391,   394,   395,   159,   409,   410,   538,   539,
     533,   534,   535,   536,   823,   240,   241,   242,   758,   586,
     756,   757,   318,   319,   343,    41,   344,   403,   404,   397,
     393
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -929
static const yytype_int16 yypact[] =
{
     109,  1956,  1956,  1956,  1956,  -120,  -116,  1956,  1956,  1956,
      57,  -929,   -93,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
     -85,  -929,  -929,   -74,  -929,   -66,  -929,   -63,    97,  -929,
    1955,  -929,  -929,  -929,  -929,  -929,  -929,   -59,  -929,  -929,
      62,    64,   -42,   111,   -52,   -27,   -18,   -16,   -14,   147,
       2,    12,    21,    27,    40,    41,    46,    55,    65,    66,
      67,    68,    72,    74,    75,    76,    77,    78,    79,    84,
      98,   110,   112,   113,   114,   115,   116,   121,   122,   124,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     144,   146,   148,   155,   157,   158,   160,    86,    99,   -25,
     109,   161,   162,   166,   167,   168,  -929,  -929,  -929,  -929,
     169,   170,  -929,  -929,  -929,   172,   150,  -929,  -929,  -929,
    -929,  -929,  -929,   177,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    64,    64,   -89,  -929,   188,   191,   195,
     193,   194,   196,   197,  -929,  -929,  -929,  -929,   200,   201,
     202,   203,   207,   198,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  1956,  1956,  1956,  1956,  1956,   209,   284,   147,    97,
     118,   218,   219,   222,   223,   224,  1956,  1956,   -68,   -68,
     -68,   -68,  1956,   -68,   -17,   -68,   -68,   225,   226,   227,
    1956,  1956,   228,   231,   232,   233,  1956,  1956,  1956,   -68,
    1956,  1956,   236,   237,   238,   -68,   276,   298,   -98,   478,
     844,   -94,   -68,   239,   240,  -929,  1955,    63,   235,   241,
     234,  -929,   -25,  -929,   243,  1956,  1956,  1956,  1956,   242,
     245,   255,   256,  1956,  1956,   257,  -929,    62,  1956,  1956,
    1956,  1670,  1956,  1956,  1956,  1956,  1956,  1956,  -929,  -110,
      64,    64,   259,  -929,  -929,   260,  1956,  1956,  1956,  1956,
     265,   270,   278,   280,  1956,  1956,  -929,  1956,  -929,   111,
     281,   282,   283,   285,   286,    97,   290,   261,  -929,  -929,
     291,   292,   293,   294,   295,   297,   299,   300,  -929,  -929,
    -929,   301,   303,   304,   305,   306,   307,  -929,  -929,   308,
     309,   317,   322,   323,   326,   327,   329,   331,   337,   339,
     340,   341,   345,   349,   350,   356,   358,   360,   361,   362,
     363,  -929,  -929,  -929,   364,  -929,   365,   366,  -929,  -929,
     367,  -929,   368,   370,  -929,   379,   386,   387,  -929,   389,
     390,   394,   288,  1956,  1956,  -929,  -929,  -929,   393,  -929,
     395,  -929,   396,  -929,   397,  -929,  -929,  -929,  -929,  -929,
     398,  -929,   401,  -929,  -929,  -929,  -929,   402,  -929,  -929,
     403,   404,  -929,  1802,   405,  1956,  -929,   248,  -929,  -929,
    -929,   406,  1956,   407,  -929,  -929,   244,  -929,  -929,   215,
     385,  -929,   409,  -929,   410,  -929,   411,  -929,   412,  -929,
    1956,  1956,  1956,  1956,   413,   419,  -929,   424,   673,   425,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,   147,  1956,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  1956,   -68,  -929,    63,  -929,
    1956,  -929,  2348,  -929,  2306,  -929,  2147,  -929,  2147,   428,
    2064,   429,  2229,   430,   431,  -929,     1,  -929,  2348,   432,
     423,     5,  -929,     5,  -929,  -929,  -929,  -929,  -929,  1956,
       5,     3,     5,  -929,  -929,  -929,   434,   435,   438,   439,
     440,   442,   444,  -929,  -929,   446,   215,   445,   456,   385,
    -929,  2058,  -929,  1212,  -929,  -929,  -929,  -929,   457,  -929,
     458,  -929,   459,   460,  -929,  -929,   588,  -929,   464,   465,
     466,   467,   470,   472,   476,   477,   480,   482,   483,   484,
     485,   486,   487,   488,  -929,  -929,  -929,   673,  -929,  -929,
     284,   489,  1956,   490,   496,  -929,     6,  -929,   498,   499,
     500,   502,   504,   507,   510,   511,   513,   517,   525,   526,
     528,   529,   530,   531,   532,   535,   536,   537,   538,   547,
    -929,  2348,   548,  -929,  -929,   549,   550,   552,   553,   554,
     555,   556,   557,   558,   559,  -929,  -929,  2147,  -929,  -929,
    -929,  -929,  -929,   560,   561,   562,   563,   564,   565,  -929,
    -929,  -929,  -929,  2064,  -929,  -929,  -929,  -929,  2229,  -929,
    -929,  -929,   566,  -929,  -929,  -929,     1,  -929,  -929,   567,
    -929,  -929,  -929,  -929,   423,   568,   569,   584,     5,   586,
    -929,   587,   570,   589,     3,  -929,   590,  1956,  1956,  1956,
    1956,  1956,  1956,  1956,  -929,  -929,  1956,  -929,  -929,   592,
     593,   594,   595,   596,   597,   598,   601,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   616,   618,   622,   623,
     624,  -929,  2058,  -929,   625,   626,   627,  -929,  1212,  -929,
    2342,  2342,  -929,  -929,  -929,  -929,  -929,  -929,  -929,   588,
    1956,  1956,  1956,  1956,  1956,  1956,  1956,  1956,  1956,   249,
     433,   637,  1956,  1956,  1824,  1956,  -929,  2384,   479,   492,
    -929,  -929,  -929,   630,   631,   632,   633,     6,     6,  1956,
     642,   -68,   -68,   -68,   -68,   -68,   -17,   -68,   -68,   644,
     647,  1956,  1956,  1956,  1956,   648,  1956,    19,  1802,  1956,
    1956,  -929,   -68,   -68,   876,  1017,   -54,   -68,   649,   -68,
     651,   652,   -68,  -929,   645,  1956,  1956,  1824,  1824,   656,
     657,  -929,  -929,  1956,  -929,  1514,   653,  -929,  1956,  1956,
    -929,  -929,  -929,  -929,  1956,  -929,  -929,  -929,   655,   658,
     661,   662,   663,   665,  1956,   666,   667,   -68,   678,   679,
     680,  1956,   682,   683,   684,  1956,  1956,  1956,   -68,   -68,
    1039,  1172,   -40,  1194,  1327,   -10,  1956,   -68,   688,  -929,
    1349,  1482,    -6,  -929,   654,  -929,  -929,  -929,  -929,  2470,
    2446,  -929,   681,   685,   691,   692,   693,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   705,   707,  -929,
     708,   712,   713,   714,   715,  -929,  -929,  -929,  -929,  -929,
     660,  -929,  1956,  1956,  1956,   686,  -929,   716,   724,   725,
     727,   728,   729,   730,   731,   735,   736,   737,   738,   739,
     743,   744,   745,   746,  1956,   747,   748,   758,   759,   760,
     761,   762,   763,   764,  -929,   767,  -929,   768,   769,  -929,
     770,   771,   772,   773,   774,   775,    83,   777,   778,   779,
     780,   781,   782,   783,   784,   785,   786,   787,    83,   790,
     794,  1956,   795,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,   796,   799,   800,   801,   802,   803,   804,   805,
     806,  1956,   807,   808,   809,   810,  -929,   812,  -929,   814,
     815,  -929,  -929,   822,  -929,   823,   826,  -929,   827,   828,
     829,  -929,   830,  -929,   831,   832,  -929,   -68,  -929,  -929,
    -929,   836,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    1648,   838,  1956,  1824,  1824,  1824,   -68,  -929,   839,   840,
     841,  -929,   687,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,   843,   847,
     848,   855,   856,   857,   858,  -929,  -929,   859,    83,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
     861,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,   864,   870,   -68,   871,   872,   873,   874,    83,   875,
     877,   878,   879,   880,  -929,  -929,  -929,  -929,  1956,  1956,
    1956,  1956,  1956,  1956,  1956,  -929,  -929,  -929,  -929,    83,
     884,  -929,  -929,  -929,  -929,   886,  -929,  -929,  -929,  -929,
    -929,   887,   888,   895,   897,   898,   899,   900,   901,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -929,  -929,   319,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -154,  -929,  -183,  -929,  -190,   165,  -929,  -929,
    -929,   328,  -929,  -482,  -723,   582,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -475,  -929,   495,  -929,   354,  -929,  -477,
     619,  -929,   374,  -929,  -929,  -478,  -929,  -929,  -929,  -929,
     414,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,   154,
    -929,  -460,  -400,   -71,   740,  -929,  -929,  -929,  -929,   353,
    -929,  -929,  -929,  -929,   343,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,   519,  -929,   646,  -929,  -929,
    -686,  -929,   659,  -929,  -929,  -929,  -929,  -545,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,   491,  -929,   338,  -515,   105,   834,  -929,  -928,  -929,
    -115,  -929,  -929,  -929,  -929,  -929,  -929,   408,  -929,  -466,
    -502,  -847,   690,   689,  -929,  -929,  -929,  -929,   540,  -929,
    -929,  -929,   544,  -929,   262,  -929,   845,  -929,  -929,  -929,
    -580,  -929,  -188,   324,    -1,  -929,  -177,  -673,   694,  -510,
     313
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      40,    43,    45,    47,   818,   298,    53,    55,    57,   670,
     311,   312,   313,   314,   625,   316,   625,   320,   321,   675,
    1090,   652,   644,   630,   885,   649,   713,   665,   719,   665,
     753,   334,   662,   661,   614,   299,    48,   340,   268,   269,
      50,   729,   270,   271,   355,   317,  1029,   669,   657,   405,
     346,   347,   350,   352,   671,   353,   676,    58,   863,   864,
     865,   348,    59,   270,   271,   354,   272,   143,   144,   308,
     309,    60,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   310,    61,   130,   131,   666,   145,   666,   754,   157,
      62,   158,   611,    63,   611,   928,   629,   119,   629,   132,
      64,    65,    66,    67,  1093,   929,   181,   921,   611,   980,
     238,   239,     1,     2,     3,     4,     5,     6,     7,   981,
     308,   309,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   182,   310,   169,   170,   672,   885,   885,   755,   986,
     183,   437,   184,   995,   185,   625,   653,   654,   171,   987,
    1146,   781,   793,   996,   186,   406,   407,   189,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,   644,   359,   360,   917,   918,
     190,   649,   675,   999,  1002,   857,   857,   896,   897,   191,
     290,   291,   292,   293,   294,   192,   662,   661,   146,   147,
     148,   149,   150,   151,   152,   306,   307,   713,   193,   194,
    1155,   315,   811,   719,   195,   858,   858,   133,   134,   325,
     326,   611,     8,   196,   729,   331,   332,   333,   153,   335,
     336,  1168,   154,   197,   198,   199,   200,   629,  1075,  1076,
     201,    68,   202,   203,   204,   205,   206,   207,   855,   855,
     526,   236,   208,     9,   369,   371,   373,   375,   527,   528,
     529,   530,   381,   383,   580,   237,   209,   386,   387,   388,
     392,   396,   398,   399,   400,   401,   402,   300,   210,   920,
     211,   212,   213,   214,   215,   413,   415,   417,   419,   216,
     217,    13,   218,   424,   426,    14,   430,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   531,   584,    15,
      16,    17,   229,    13,   230,   257,   231,    14,    18,    19,
      20,    21,    22,   232,    23,   233,   234,   235,   532,   244,
     245,    15,    16,    17,   246,   247,   248,   253,   254,   256,
      18,    19,    20,    21,    22,   258,    23,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   273,    24,    25,   274,
     275,   276,   277,   289,   278,   279,    26,    27,   284,   285,
     286,   287,   489,   490,   288,   295,   296,   301,   302,    24,
      25,   303,   304,   305,   322,   323,   324,   327,    26,    27,
     328,   329,   330,    28,    29,   337,   338,   339,   356,   357,
     748,   365,   392,   363,   396,   519,   537,   271,   871,   364,
     376,   402,   367,   377,    30,    28,    29,    31,    32,    33,
      34,    35,    36,   378,   379,   384,   408,   411,   439,   549,
     551,   549,   551,   420,    37,   341,    30,    38,   421,    31,
      32,    33,    34,    35,    36,   342,   422,   582,   423,   243,
     432,   433,   434,   488,   435,   436,    37,   341,   438,    38,
     440,   441,   442,   443,   444,   588,   445,   345,   446,   447,
     448,   659,   449,   450,   451,   452,   453,   454,   455,   589,
    1166,  1167,   590,   591,   592,   593,   456,   594,   595,   596,
     597,   457,   458,    13,   583,   459,   460,    14,   461,   587,
     462,   598,   599,   600,   601,   602,   463,   660,   464,   465,
     466,    15,    16,    17,   467,   603,   604,   605,   468,   469,
      18,    19,    20,    21,    22,   470,    23,   471,   396,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   606,   481,
     607,   608,   619,   620,   633,   634,   635,   636,   482,   637,
     621,   638,   622,   623,   624,   483,   484,   485,   486,    24,
      25,   487,   491,   609,   493,   495,   497,   505,    26,    27,
     507,   512,   514,   515,   517,   523,   525,   876,   540,   542,
     544,   546,   554,   900,   901,   902,   903,   904,   555,   906,
     907,   582,   872,   557,   578,    28,    29,   631,   646,   650,
     651,   658,   677,   678,   922,   923,   679,   680,   681,   930,
     682,   932,   683,   686,   935,   684,    30,   925,   927,    31,
      32,    33,    34,    35,    36,   687,   722,   724,   726,   727,
     939,   940,   730,   731,   732,   733,    37,   341,   734,    38,
     735,   690,   691,   692,   736,   737,   890,   349,   738,   962,
     739,   740,   741,   742,   743,   744,   745,   891,   749,   751,
     974,   975,   693,   694,   695,   752,   759,   760,   761,   989,
     762,   696,   763,   977,   979,   764,   983,   985,   765,   766,
     697,   767,   698,   992,   994,   768,   402,   819,   820,   821,
     822,   824,   825,   769,   770,   826,   771,   772,   773,   774,
     775,   708,   709,   776,   777,   778,   779,   558,   559,   560,
     561,   562,   563,   564,   565,   780,   782,   783,   784,   566,
     785,   786,   787,   788,   789,   790,   791,   792,   795,   796,
     797,   798,   799,   800,   803,   805,   808,   809,   814,   862,
     402,   402,   402,   866,   867,   868,   869,   870,   567,   568,
     569,   874,   875,   810,   877,   812,   813,   750,   815,   817,
     827,   828,   829,   830,   831,   832,   833,   570,   898,   834,
     571,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     910,   911,   912,   914,   844,   916,   845,   392,   396,   402,
     846,   847,   848,   850,   851,   852,   873,   572,   892,   893,
     894,   899,   895,   908,   937,   938,   909,   915,   931,   573,
     933,   934,   943,   936,   947,   941,   942,   949,   951,  1121,
     804,   948,   997,   952,   953,  1027,   585,   954,   574,   575,
     955,   956,   957,   824,   958,   960,   961,   963,   964,   965,
     966,   967,   968,   969,   971,   972,   973,   990,  1133,   385,
    1004,  1031,  1137,  1049,  1005,   988,  1130,  1131,  1132,    13,
    1006,  1007,  1008,    14,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1022,    15,    16,    17,
    1023,  1024,  1025,  1026,   504,  1032,    18,    19,    20,    21,
      22,    13,    23,  1033,  1034,    14,  1035,  1036,  1037,  1038,
    1039,  1028,   951,  1030,  1040,  1041,  1042,  1043,  1044,    15,
      16,    17,  1045,  1046,  1047,  1048,  1050,  1051,    18,    19,
      20,    21,    22,   914,    23,    24,    25,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,    26,    27,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1150,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,    24,    25,  1091,
     951,    28,    29,  1092,  1094,  1095,    26,    27,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1105,  1106,  1107,  1108,
     971,  1109,    30,  1110,  1111,    31,    32,    33,    34,    35,
      36,  1112,  1113,    28,    29,  1114,  1115,  1116,  1117,  1118,
    1119,  1120,    37,   341,  1123,    38,  1128,   503,  1134,  1135,
    1136,  1138,   802,   351,    30,  1139,  1140,    31,    32,    33,
      34,    35,    36,  1141,  1142,  1143,  1144,   801,  1145,  1127,
    1147,  1129,    13,  1148,    37,   341,    14,    38,  1149,   431,
    1151,  1152,  1153,  1154,  1156,   924,  1157,  1158,  1159,  1160,
      15,    16,    17,  1169,    13,  1170,  1171,  1172,    14,    18,
      19,    20,    21,    22,  1173,    23,  1174,  1175,  1176,  1177,
    1178,   853,    15,    16,    17,   849,   721,   861,   746,   553,
     358,    18,    19,    20,    21,    22,  1104,    23,   807,   688,
     685,   552,   816,   516,   518,     0,   959,   366,    24,    25,
     905,   919,     0,     0,     0,     0,   524,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1161,  1162,  1163,
    1164,  1165,   402,   402,     0,    30,    28,    29,    31,    32,
      33,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   341,    30,    38,     0,
      31,    32,    33,    34,    35,    36,   926,    13,     0,     0,
       0,    14,     0,     0,     0,     0,     0,    37,   341,     0,
      38,     0,     0,     0,     0,    15,    16,    17,   976,    13,
       0,     0,     0,    14,    18,    19,    20,    21,    22,     0,
      23,     0,     0,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,   690,   691,   692,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,    26,    27,   693,   694,   695,    28,
      29,     0,     0,     0,     0,   696,     0,     0,     0,     0,
       0,     0,     0,     0,   697,     0,   698,     0,     0,     0,
      30,    28,    29,    31,    32,    33,    34,    35,    36,   714,
     715,   716,     0,     0,     0,   708,   709,     0,     0,     0,
      37,   341,    30,    38,     0,    31,    32,    33,    34,    35,
      36,   978,    13,     0,     0,     0,    14,     0,     0,     0,
       0,     0,    37,   341,     0,    38,     0,     0,     0,     0,
      15,    16,    17,   982,    13,     0,     0,     0,    14,    18,
      19,    20,    21,    22,     0,    23,     0,     0,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    28,    29,    31,    32,
      33,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   341,    30,    38,     0,
      31,    32,    33,    34,    35,    36,   984,    13,     0,     0,
       0,    14,     0,     0,     0,     0,     0,    37,   341,     0,
      38,     0,     0,     0,     0,    15,    16,    17,   991,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    13,
      23,     0,     0,    14,     0,     0,     0,     0,     0,   944,
     945,     0,     0,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,   946,    28,
      29,     0,     0,     0,    26,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,    28,    29,     0,     0,     0,     0,     0,     0,     0,
      37,   341,     0,    38,     0,     0,     0,     0,     0,     0,
       0,   993,    30,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,    13,     0,     0,     0,    14,     0,     0,
       0,     0,    37,  1124,  1125,    38,     0,     0,     0,     0,
       0,    15,    16,    17,     0,    13,     0,     0,     0,    14,
      18,    19,    20,    21,    22,     0,    23,     0,     0,     0,
       0,     0,     0,    15,    16,    17,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,   389,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,  1126,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    28,    29,    31,
      32,    33,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    30,    38,
       0,    31,    32,    33,    34,    35,    36,    13,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    37,   390,
       0,    38,     0,     0,     0,    15,    16,    17,     0,    13,
       0,     0,     0,    14,    18,    19,    20,    21,    22,   389,
      23,     0,     0,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    28,    29,    31,    32,    33,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    30,    38,     0,    31,    32,    33,    34,    35,
      36,    13,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,    37,   341,     0,    38,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    71,    72,    73,    74,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    92,
      93,    94,     0,    95,    96,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,    30,     0,     0,    31,    32,    33,
      34,    35,    36,     0,   114,   115,   588,   689,     0,     0,
       0,   690,   691,   692,    37,     0,     0,    38,     0,     0,
     589,     0,     0,   590,   591,   592,   593,     0,   594,   595,
     596,   597,   693,   694,   695,     0,     0,     0,     0,     0,
       0,   696,   598,   599,   600,   601,   602,     0,   632,     0,
     697,     0,   698,     0,     0,   699,   603,   604,   605,     0,
       0,     0,     0,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,     0,   710,     0,     0,     0,     0,   606,
       0,   607,   608,   619,   620,   633,   634,   635,   636,   588,
     637,   621,   638,   622,   623,   624,     0,     0,     0,     0,
       0,     0,     0,   589,   609,     0,   590,   591,   592,   593,
       0,   594,   595,   596,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,   599,   600,   601,   602,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   603,
     604,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   615,     0,   616,   617,   618,     0,     0,     0,
       0,     0,   606,     0,   607,   608,   619,   620,     0,     0,
       0,   588,     0,     0,   621,     0,   622,   623,   624,     0,
       0,     0,     0,     0,     0,   589,     0,   609,   590,   591,
     592,   593,     0,   594,   595,   596,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,   600,
     601,   602,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   603,   604,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,   607,   608,   588,     0,
     633,   634,   635,   636,     0,   637,   621,   638,   622,   623,
     624,     0,   589,     0,     0,   590,   591,   592,   593,   609,
     594,   595,   596,   597,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   598,   599,   600,   601,   602,     0,
     588,     0,     0,     0,     0,   690,   691,   692,   603,   604,
     605,     0,     0,     0,   589,     0,     0,   590,   591,   592,
     593,   612,   594,   595,   596,   597,   693,   694,   695,     0,
       0,   606,     0,   607,   608,   696,   598,   599,   600,   601,
     602,     0,   878,     0,   697,     0,   698,   690,   691,   692,
     603,   604,   605,     0,     0,     0,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   708,   709,     0,   693,   694,
     695,   854,     0,   606,     0,   607,   608,   696,   879,   621,
       0,   622,   623,   624,     0,     0,   697,     0,   698,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,     0,
       0,     0,     0,     0,     0,     0,     0,   708,   709,   690,
     691,   692,     0,   854,     0,   880,     0,   881,   882,   883,
     637,   621,   638,   622,   623,   624,   884,     0,     0,     0,
     693,   694,   695,   690,   691,   692,     0,     0,     0,   696,
       0,     0,     0,     0,     0,     0,     0,     0,   697,     0,
     698,     0,     0,     0,   693,   694,   695,     0,     0,     0,
       0,     0,     0,   696,   998,     0,     0,     0,     0,   708,
     709,     0,   697,     0,   698,   854,     0,   880,     0,   881,
     882,   883,   637,   621,   638,   622,   623,   624,  1001,     0,
       0,     0,     0,   708,   709,     0,     0,     0,     0,   854,
       0,   880,     0,   881,   882,   883,   637,   621,   638,   622,
     623,   624
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-929))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,   677,   188,     7,     8,     9,   519,
     198,   199,   200,   201,   496,   203,   498,   205,   206,   521,
     948,    20,   500,   498,   747,   502,   541,    24,   543,    24,
      24,   219,   510,   510,   494,   189,   156,   225,   153,   154,
     156,   556,   152,   153,   232,    62,   893,   513,   508,   159,
     227,   149,   229,   230,   520,   149,   522,     0,   731,   732,
     733,   159,   155,   152,   153,   159,   155,     3,     4,   137,
     138,   156,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   149,   156,    21,    22,    82,    22,    82,    82,   131,
     156,   133,   492,   156,   494,   149,   496,   156,   498,    37,
       3,     4,     5,     6,   951,   159,   158,   780,   508,   149,
     135,   136,     3,     4,     5,     6,     7,     8,     9,   159,
     137,   138,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   158,   149,    22,    23,   132,   859,   860,   132,   149,
     158,   295,   158,   149,   158,   627,   145,   146,    37,   159,
    1078,   611,   627,   159,     7,   270,   271,   155,    75,    76,
      77,    78,    79,    80,    81,   643,   103,   104,   149,   150,
     158,   648,   674,   859,   860,   720,   721,   757,   758,   158,
     181,   182,   183,   184,   185,   158,   664,   664,   124,   125,
     126,   127,   128,   129,   130,   196,   197,   712,   158,   158,
    1128,   202,   668,   718,   158,   720,   721,   145,   146,   210,
     211,   611,   103,   158,   729,   216,   217,   218,   154,   220,
     221,  1149,   158,   158,   158,   158,   158,   627,   145,   146,
     158,   134,   158,   158,   158,   158,   158,   158,   720,   721,
      25,   155,   158,   134,   245,   246,   247,   248,    33,    34,
      35,    36,   253,   254,   437,   156,   158,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   149,   158,   779,
     158,   158,   158,   158,   158,   276,   277,   278,   279,   158,
     158,     5,   158,   284,   285,     9,   287,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,    82,   486,    23,
      24,    25,   158,     5,   158,   155,   158,     9,    32,    33,
      34,    35,    36,   158,    38,   158,   158,   157,   103,   158,
     158,    23,    24,    25,   158,   158,   158,   158,   158,   157,
      32,    33,    34,    35,    36,   158,    38,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,    71,    72,   158,
     155,   158,   158,   155,   158,   158,    80,    81,   158,   158,
     158,   158,   363,   364,   157,   156,    82,   149,   149,    71,
      72,   149,   149,   149,   149,   149,   149,   149,    80,    81,
     149,   149,   149,   107,   108,   149,   149,   149,   149,   149,
     580,   157,   393,   158,   395,   147,    11,   153,   149,   158,
     158,   402,   159,   158,   128,   107,   108,   131,   132,   133,
     134,   135,   136,   158,   158,   158,   157,   157,   157,   420,
     421,   422,   423,   158,   148,   149,   128,   151,   158,   131,
     132,   133,   134,   135,   136,   159,   158,   438,   158,   120,
     159,   159,   159,   155,   159,   159,   148,   149,   158,   151,
     159,   159,   159,   159,   159,    32,   159,   159,   159,   159,
     159,    38,   159,   159,   159,   159,   159,   159,   159,    46,
    1143,  1144,    49,    50,    51,    52,   159,    54,    55,    56,
      57,   159,   159,     5,   485,   159,   159,     9,   159,   490,
     159,    68,    69,    70,    71,    72,   159,    74,   159,   159,
     159,    23,    24,    25,   159,    82,    83,    84,   159,   159,
      32,    33,    34,    35,    36,   159,    38,   159,   519,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   105,   159,
     107,   108,   109,   110,   111,   112,   113,   114,   159,   116,
     117,   118,   119,   120,   121,   159,   159,   158,   158,    71,
      72,   157,   159,   130,   159,   159,   159,   159,    80,    81,
     159,   159,   159,   159,   159,   159,   159,   744,   159,   159,
     159,   159,   159,   761,   762,   763,   764,   765,   159,   767,
     768,   582,   149,   159,   159,   107,   108,   159,   159,   159,
     159,   159,   158,   158,   782,   783,   158,   158,   158,   787,
     158,   789,   158,   158,   792,   159,   128,   784,   785,   131,
     132,   133,   134,   135,   136,   159,   159,   159,   159,   159,
     797,   798,   158,   158,   158,   158,   148,   149,   158,   151,
     158,    43,    44,    45,   158,   158,   157,   159,   158,   827,
     158,   158,   158,   158,   158,   158,   158,   155,   159,   159,
     838,   839,    64,    65,    66,   159,   158,   158,   158,   847,
     158,    73,   158,   840,   841,   158,   843,   844,   158,   158,
      82,   158,    84,   850,   851,   158,   677,   678,   679,   680,
     681,   682,   683,   158,   158,   686,   158,   158,   158,   158,
     158,   103,   104,   158,   158,   158,   158,    24,    25,    26,
      27,    28,    29,    30,    31,   158,   158,   158,   158,    36,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   730,
     731,   732,   733,   734,   735,   736,   737,   738,    65,    66,
      67,   742,   743,   159,   745,   159,   159,   582,   159,   159,
     158,   158,   158,   158,   158,   158,   158,    84,   759,   158,
      87,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     771,   772,   773,   774,   158,   776,   158,   778,   779,   780,
     158,   158,   158,   158,   158,   158,   149,   114,   158,   158,
     158,   149,   159,   149,   795,   796,   149,   149,   149,   126,
     149,   149,   803,   158,   805,   149,   149,   808,   809,   997,
     656,   158,   158,   814,   159,   155,   488,   159,   145,   146,
     159,   159,   159,   824,   159,   159,   159,   149,   149,   149,
     831,   149,   149,   149,   835,   836,   837,   149,  1026,   257,
     159,   155,   155,   914,   159,   846,  1023,  1024,  1025,     5,
     159,   159,   159,     9,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   158,   158,    23,    24,    25,
     158,   158,   158,   158,   379,   159,    32,    33,    34,    35,
      36,     5,    38,   159,   159,     9,   159,   159,   159,   159,
     159,   892,   893,   894,   159,   159,   159,   159,   159,    23,
      24,    25,   159,   159,   159,   159,   159,   159,    32,    33,
      34,    35,    36,   914,    38,    71,    72,   159,   159,   159,
     159,   159,   159,   159,    80,    81,   159,   159,   159,   159,
     159,   159,   159,   159,   159,  1123,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,    71,    72,   159,
     951,   107,   108,   159,   159,   159,    80,    81,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     971,   159,   128,   159,   159,   131,   132,   133,   134,   135,
     136,   159,   159,   107,   108,   159,   159,   159,   159,   159,
     159,   159,   148,   149,   158,   151,   158,   378,   159,   159,
     159,   158,   648,   159,   128,   158,   158,   131,   132,   133,
     134,   135,   136,   158,   158,   158,   158,   643,   159,  1020,
     159,  1022,     5,   159,   148,   149,     9,   151,   158,   289,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
      23,    24,    25,   159,     5,   159,   159,   159,     9,    32,
      33,    34,    35,    36,   159,    38,   159,   159,   159,   159,
     159,   718,    23,    24,    25,   712,   547,   729,   577,   423,
     236,    32,    33,    34,    35,    36,   971,    38,   664,   539,
     536,   422,   674,   393,   395,    -1,   824,   242,    71,    72,
     766,   778,    -1,    -1,    -1,    -1,   402,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1138,  1139,  1140,
    1141,  1142,  1143,  1144,    -1,   128,   107,   108,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   128,   151,    -1,
     131,   132,   133,   134,   135,   136,   159,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,    23,    24,    25,   159,     5,
      -1,    -1,    -1,     9,    32,    33,    34,    35,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    64,    65,    66,   107,
     108,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
     128,   107,   108,   131,   132,   133,   134,   135,   136,    97,
      98,    99,    -1,    -1,    -1,   103,   104,    -1,    -1,    -1,
     148,   149,   128,   151,    -1,   131,   132,   133,   134,   135,
     136,   159,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
      23,    24,    25,   159,     5,    -1,    -1,    -1,     9,    32,
      33,    34,    35,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   107,   108,   131,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   128,   151,    -1,
     131,   132,   133,   134,   135,   136,   159,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,    23,    24,    25,   159,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,     5,
      38,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    74,   107,
     108,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,   131,   132,   133,   134,   135,   136,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   128,    -1,    -1,   131,   132,   133,   134,   135,
     136,    -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,   148,    15,    16,   151,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,     5,    -1,    -1,    -1,     9,
      32,    33,    34,    35,    36,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   107,   108,   131,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,   128,   151,
      -1,   131,   132,   133,   134,   135,   136,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    23,    24,    25,    -1,     5,
      -1,    -1,    -1,     9,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   107,   108,   131,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,   128,   151,    -1,   131,   132,   133,   134,   135,
     136,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,   132,   133,
     134,   135,   136,    -1,   139,   140,    32,    39,    -1,    -1,
      -1,    43,    44,    45,   148,    -1,    -1,   151,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    68,    69,    70,    71,    72,    -1,    74,    -1,
      82,    -1,    84,    -1,    -1,    87,    82,    83,    84,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,   105,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,    32,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,   130,    -1,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,   110,    -1,    -1,
      -1,    32,    -1,    -1,   117,    -1,   119,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,   130,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,    32,    -1,
     111,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    46,    -1,    -1,    49,    50,    51,    52,   130,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      32,    -1,    -1,    -1,    -1,    43,    44,    45,    82,    83,
      84,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    95,    54,    55,    56,    57,    64,    65,    66,    -1,
      -1,   105,    -1,   107,   108,    73,    68,    69,    70,    71,
      72,    -1,    38,    -1,    82,    -1,    84,    43,    44,    45,
      82,    83,    84,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,    -1,    64,    65,
      66,   109,    -1,   105,    -1,   107,   108,    73,    74,   117,
      -1,   119,   120,   121,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,    43,
      44,    45,    -1,   109,    -1,   111,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      64,    65,    66,    43,    44,    45,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,   103,
     104,    -1,    82,    -1,    84,   109,    -1,   111,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
      -1,   111,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,   121
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,   103,   134,
     161,   162,   164,     5,     9,    23,    24,    25,    32,    33,
      34,    35,    36,    38,    71,    72,    80,    81,   107,   108,
     128,   131,   132,   133,   134,   135,   136,   148,   151,   165,
     324,   325,   166,   324,   167,   324,   169,   324,   156,   170,
     156,   178,   171,   324,   179,   324,   168,   324,     0,   155,
     156,   156,   156,   156,     3,     4,     5,     6,   134,   172,
     173,    40,    41,    42,    43,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    64,    65,    66,    68,    69,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    96,    97,    98,    99,
     100,   101,   102,   123,   139,   140,   286,   287,   180,   156,
     163,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      21,    22,    37,   145,   146,   185,   186,   187,   188,   194,
     216,   223,   226,     3,     4,    22,   124,   125,   126,   127,
     128,   129,   130,   154,   158,   290,   291,   131,   133,   305,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    22,
      23,    37,   234,   235,   236,   241,   246,   268,   274,   275,
     278,   158,   158,   158,   158,   158,     7,   174,   175,   155,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   157,   155,   156,   135,   136,
     315,   316,   317,   162,   158,   158,   158,   158,   158,   196,
     195,   198,   197,   158,   158,   217,   157,   155,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   290,   290,
     152,   153,   155,   158,   158,   155,   158,   158,   158,   158,
     248,   247,   250,   249,   158,   158,   158,   158,   157,   155,
     324,   324,   324,   324,   324,   156,    82,   176,   174,   172,
     149,   149,   149,   149,   149,   149,   324,   324,   137,   138,
     149,   322,   322,   322,   322,   324,   322,    62,   322,   323,
     322,   322,   149,   149,   149,   324,   324,   149,   149,   149,
     149,   324,   324,   324,   322,   324,   324,   149,   149,   149,
     322,   149,   159,   324,   326,   159,   326,   149,   159,   159,
     326,   159,   326,   149,   159,   322,   149,   149,   286,   103,
     104,   181,   182,   158,   158,   157,   316,   159,   189,   324,
     191,   324,   201,   324,   199,   324,   158,   158,   158,   158,
     227,   324,   224,   324,   158,   185,   324,   324,   324,    37,
     149,   302,   324,   330,   303,   304,   324,   329,   324,   324,
     324,   324,   324,   327,   328,   159,   290,   290,   157,   306,
     307,   157,   237,   324,   242,   324,   253,   324,   251,   324,
     158,   158,   158,   158,   324,   276,   324,   279,   280,   269,
     324,   234,   159,   159,   159,   159,   159,   172,   158,   157,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   158,   158,   157,   155,   324,
     324,   159,   190,   159,   192,   159,   202,   159,   200,   210,
     211,   205,   206,   210,   205,   159,   228,   159,   225,   218,
     219,   296,   159,   292,   159,   159,   302,   159,   303,   147,
     293,   294,   295,   159,   328,   159,    25,    33,    34,    35,
      36,    82,   103,   310,   311,   312,   313,    11,   308,   309,
     159,   238,   159,   243,   159,   254,   159,   252,   262,   324,
     257,   324,   262,   257,   159,   159,   277,   159,    24,    25,
      26,    27,    28,    29,    30,    31,    36,    65,    66,    67,
      84,    87,   114,   126,   145,   146,   281,   282,   159,   270,
     174,   177,   324,   324,   322,   181,   319,   324,    32,    46,
      49,    50,    51,    52,    54,    55,    56,    57,    68,    69,
      70,    71,    72,    82,    83,    84,   105,   107,   108,   130,
     231,   232,    95,   193,   231,    95,    97,    98,    99,   109,
     110,   117,   119,   120,   121,   183,   203,   204,   215,   232,
     203,   159,    74,   111,   112,   113,   114,   116,   118,   183,
     184,   209,   212,   213,   215,   232,   159,   207,   208,   209,
     159,   159,    20,   145,   146,   229,   230,   231,   159,    38,
      74,   209,   215,   220,   221,    24,    82,   299,   300,   299,
     329,   299,   132,   297,   298,   300,   299,   158,   158,   158,
     158,   158,   158,   158,   159,   312,   158,   159,   308,    39,
      43,    44,    45,    64,    65,    66,    73,    82,    84,    87,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     106,   239,   240,   284,    97,    98,    99,   244,   245,   284,
     255,   255,   159,   263,   159,   258,   159,   159,   283,   284,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   281,   271,   176,   159,
     177,   159,   159,    24,    82,   132,   320,   321,   318,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   231,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   203,   214,   158,   158,   158,   158,   158,
     158,   212,   207,   158,   229,   158,   222,   220,   158,   158,
     159,   299,   159,   159,   158,   159,   297,   159,   327,   324,
     324,   324,   324,   314,   324,   324,   324,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   239,
     158,   158,   158,   244,   109,   183,   256,   267,   284,   264,
     259,   283,   324,   327,   327,   327,   324,   324,   324,   324,
     324,   149,   149,   149,   324,   324,   326,   324,    38,    74,
     111,   113,   114,   115,   122,   184,   260,   267,   272,   284,
     157,   155,   158,   158,   158,   159,   320,   320,   324,   149,
     322,   322,   322,   322,   322,   323,   322,   322,   149,   149,
     324,   324,   324,   233,   324,   149,   324,   149,   150,   330,
     329,   327,   322,   322,   159,   326,   159,   326,   149,   159,
     322,   149,   322,   149,   149,   322,   158,   324,   324,   326,
     326,   149,   149,   324,    15,    16,    74,   324,   158,   324,
     301,   324,   324,   159,   159,   159,   159,   159,   159,   314,
     159,   159,   322,   149,   149,   149,   324,   149,   149,   149,
     285,   324,   324,   324,   322,   322,   159,   326,   159,   326,
     149,   159,   159,   326,   159,   326,   149,   159,   324,   322,
     149,   159,   326,   159,   326,   149,   159,   158,    74,   260,
     265,   122,   260,   261,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     158,   273,   158,   158,   158,   158,   158,   155,   324,   301,
     324,   155,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   233,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,    75,    76,
      77,    78,    79,    80,    81,   145,   146,   288,   289,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     288,   159,   159,   301,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   285,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   322,   266,   158,    15,    16,    74,   324,   158,   324,
     326,   326,   326,   322,   159,   159,   159,   155,   158,   158,
     158,   158,   158,   158,   158,   159,   288,   159,   159,   158,
     322,   159,   159,   159,   159,   288,   159,   159,   159,   159,
     159,   324,   324,   324,   324,   324,   327,   327,   288,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 327 "cfg-grammar.y"
    {
            if (last_include_file && !cfg_lex_process_include(last_include_file))
              {
                free(last_include_file);
                last_include_file = NULL;
                YYERROR;
              }
            if (last_include_file)
              {
                free(last_include_file);
                last_include_file = NULL;
              }
          }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 345 "cfg-grammar.y"
    { cfg_add_source(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 346 "cfg-grammar.y"
    { cfg_add_dest(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 347 "cfg-grammar.y"
    { cfg_add_connection(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 348 "cfg-grammar.y"
    { cfg_add_filter(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 349 "cfg-grammar.y"
    { cfg_add_parser(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 350 "cfg-grammar.y"
    { cfg_add_rewrite(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 351 "cfg-grammar.y"
    { cfg_add_template(configuration, (yyvsp[(2) - (2)].ptr)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 352 "cfg-grammar.y"
    {  }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 353 "cfg-grammar.y"
    {  }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 357 "cfg-grammar.y"
    { (yyval.ptr) = log_source_group_new((yyvsp[(1) - (4)].cptr), (yyvsp[(3) - (4)].ptr)); free((yyvsp[(1) - (4)].cptr)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 361 "cfg-grammar.y"
    { (yyval.ptr) = log_filter_rule_new((yyvsp[(1) - (5)].cptr), (yyvsp[(3) - (5)].node)); free((yyvsp[(1) - (5)].cptr)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 365 "cfg-grammar.y"
    { (yyval.ptr) = log_parser_rule_new((yyvsp[(1) - (5)].cptr), (yyvsp[(3) - (5)].ptr)); free((yyvsp[(1) - (5)].cptr)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 368 "cfg-grammar.y"
    { (yyval.ptr) = log_rewrite_rule_new((yyvsp[(1) - (4)].cptr), (yyvsp[(3) - (4)].ptr)); free((yyvsp[(1) - (4)].cptr)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 371 "cfg-grammar.y"
    { (yyval.ptr) = log_dest_group_new((yyvsp[(1) - (4)].cptr), (yyvsp[(3) - (4)].ptr)); free((yyvsp[(1) - (4)].cptr)); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 375 "cfg-grammar.y"
    { LogPipeItem *pi = log_pipe_item_append_tail((yyvsp[(2) - (5)].ptr), (yyvsp[(3) - (5)].ptr)); (yyval.ptr) = log_connection_new(pi, (yyvsp[(4) - (5)].num)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 379 "cfg-grammar.y"
    { last_include_file = (yyvsp[(1) - (1)].cptr); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 382 "cfg-grammar.y"
    { log_pipe_item_append((yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 383 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 387 "cfg-grammar.y"
    { (yyval.ptr) = log_pipe_item_new(EP_SOURCE, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 388 "cfg-grammar.y"
    { (yyval.ptr) = log_pipe_item_new(EP_FILTER, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 389 "cfg-grammar.y"
    { (yyval.ptr) = log_pipe_item_new(EP_PARSER, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 390 "cfg-grammar.y"
    { (yyval.ptr) = log_pipe_item_new(EP_REWRITE, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 391 "cfg-grammar.y"
    { (yyval.ptr) = log_pipe_item_new(EP_DESTINATION, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 395 "cfg-grammar.y"
    { log_pipe_item_append((yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr)); (yyval.ptr) = (yyvsp[(1) - (2)].ptr); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 396 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 400 "cfg-grammar.y"
    { LogPipeItem *pi = log_pipe_item_append_tail((yyvsp[(3) - (7)].ptr), (yyvsp[(4) - (7)].ptr)); (yyval.ptr) = log_pipe_item_new_ref(EP_PIPE, log_connection_new(pi, (yyvsp[(5) - (7)].num))); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 404 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(3) - (5)].num); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 405 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 410 "cfg-grammar.y"
    { (yyval.num) = log_connection_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 411 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 416 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 421 "cfg-grammar.y"
    {
	    last_template = log_template_new((yyvsp[(1) - (1)].cptr), NULL);
	    free((yyvsp[(1) - (1)].cptr));
	  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 425 "cfg-grammar.y"
    { (yyval.ptr) = last_template;  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 434 "cfg-grammar.y"
    { last_template->template = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); if (!cfg_check_template(last_template)) { YYERROR; } }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 435 "cfg-grammar.y"
    { log_template_set_escape(last_template, (yyvsp[(3) - (4)].num)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 439 "cfg-grammar.y"
    { last_sock_options->sndbuf = (yyvsp[(3) - (4)].num); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 440 "cfg-grammar.y"
    { last_sock_options->rcvbuf = (yyvsp[(3) - (4)].num); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 441 "cfg-grammar.y"
    { last_sock_options->broadcast = (yyvsp[(3) - (4)].num); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 442 "cfg-grammar.y"
    { last_sock_options->keepalive = (yyvsp[(3) - (4)].num); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 447 "cfg-grammar.y"
    { ((InetSocketOptions *) last_sock_options)->ttl = (yyvsp[(3) - (4)].num); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 448 "cfg-grammar.y"
    { ((InetSocketOptions *) last_sock_options)->tos = (yyvsp[(3) - (4)].num); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 452 "cfg-grammar.y"
    { if ((yyvsp[(1) - (3)].ptr)) {log_drv_append((yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); log_drv_unref((yyvsp[(3) - (3)].ptr)); (yyval.ptr) = (yyvsp[(1) - (3)].ptr); } else { YYERROR; } }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 453 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 457 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 458 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 459 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 460 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 461 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 462 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 466 "cfg-grammar.y"
    { (yyval.ptr) = afinter_sd_new(); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 470 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 471 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 476 "cfg-grammar.y"
    {
	    last_driver = affile_sd_new((yyvsp[(1) - (1)].cptr), 0);
	    free((yyvsp[(1) - (1)].cptr));
	    last_reader_options = &((AFFileSourceDriver *) last_driver)->reader_options;
	  }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 481 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 486 "cfg-grammar.y"
    {
	    last_driver = affile_sd_new((yyvsp[(1) - (1)].cptr), AFFILE_PIPE);
	    free((yyvsp[(1) - (1)].cptr));
	    last_reader_options = &((AFFileSourceDriver *) last_driver)->reader_options;
	  }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 491 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 495 "cfg-grammar.y"
    { last_driver->optional = (yyvsp[(3) - (4)].num); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 496 "cfg-grammar.y"
    {}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 500 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 501 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 502 "cfg-grammar.y"
    { last_addr_family = AF_INET; }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 502 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 503 "cfg-grammar.y"
    { last_addr_family = AF_INET; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 503 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 504 "cfg-grammar.y"
    { last_addr_family = AF_INET6; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 504 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 505 "cfg-grammar.y"
    { last_addr_family = AF_INET6; }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 505 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 510 "cfg-grammar.y"
    {
	    last_driver = afunix_sd_new(
		(yyvsp[(1) - (1)].cptr),
		AFSOCKET_DGRAM | AFSOCKET_LOCAL);
	    free((yyvsp[(1) - (1)].cptr));
	    last_reader_options = &((AFSocketSourceDriver *) last_driver)->reader_options;
	    last_sock_options = &((AFUnixSourceDriver *) last_driver)->sock_options;
	  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 518 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 523 "cfg-grammar.y"
    {
	    last_driver = afunix_sd_new(
		(yyvsp[(1) - (1)].cptr),
		AFSOCKET_STREAM | AFSOCKET_KEEP_ALIVE | AFSOCKET_LOCAL);
	    free((yyvsp[(1) - (1)].cptr));
	    last_reader_options = &((AFSocketSourceDriver *) last_driver)->reader_options;
	    last_sock_options = &((AFUnixSourceDriver *) last_driver)->sock_options;
	  }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 531 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 541 "cfg-grammar.y"
    { afunix_sd_set_uid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 542 "cfg-grammar.y"
    { afunix_sd_set_uid(last_driver, "-2"); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 543 "cfg-grammar.y"
    { afunix_sd_set_gid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 544 "cfg-grammar.y"
    { afunix_sd_set_gid(last_driver, "-2"); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 545 "cfg-grammar.y"
    { afunix_sd_set_perm(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 546 "cfg-grammar.y"
    { afunix_sd_set_perm(last_driver, -2); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 547 "cfg-grammar.y"
    { last_driver->optional = (yyvsp[(3) - (4)].num); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 548 "cfg-grammar.y"
    {}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 549 "cfg-grammar.y"
    {}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 550 "cfg-grammar.y"
    {}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 555 "cfg-grammar.y"
    {
	    last_driver = afinet_sd_new(last_addr_family,
			NULL, 514,
			AFSOCKET_DGRAM);
	    last_reader_options = &((AFSocketSourceDriver *) last_driver)->reader_options;
	    last_sock_options = &((AFInetSourceDriver *) last_driver)->sock_options.super;
	  }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 562 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 575 "cfg-grammar.y"
    { afinet_sd_set_localip(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 576 "cfg-grammar.y"
    { afinet_sd_set_localip(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 577 "cfg-grammar.y"
    { afinet_sd_set_localport(last_driver, (yyvsp[(3) - (4)].cptr), afinet_sd_get_proto_name(last_driver)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 578 "cfg-grammar.y"
    { afinet_sd_set_localport(last_driver, (yyvsp[(3) - (4)].cptr), afinet_sd_get_proto_name(last_driver)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 585 "cfg-grammar.y"
    {
	    last_driver = afinet_sd_new(last_addr_family,
			NULL, 514,
			AFSOCKET_STREAM);
	    last_reader_options = &((AFSocketSourceDriver *) last_driver)->reader_options;
	    last_sock_options = &((AFInetSourceDriver *) last_driver)->sock_options.super;
	  }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 592 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 604 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    last_tls_context = tls_context_new(TM_SERVER);
#endif
	  }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 610 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    afsocket_sd_set_tls_context(last_driver, last_tls_context);
#endif
          }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 616 "cfg-grammar.y"
    {}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 620 "cfg-grammar.y"
    { afsocket_sd_set_keep_alive(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 621 "cfg-grammar.y"
    { afsocket_sd_set_max_connections(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 625 "cfg-grammar.y"
    { last_addr_family = AF_INET; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 625 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 630 "cfg-grammar.y"
    {
	    last_driver = afinet_sd_new(last_addr_family,
			NULL, 601,
			AFSOCKET_STREAM | AFSOCKET_SYSLOG_PROTOCOL);
	    last_reader_options = &((AFSocketSourceDriver *) last_driver)->reader_options;
	    last_sock_options = &((AFInetSourceDriver *) last_driver)->sock_options.super;
	  }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 637 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 647 "cfg-grammar.y"
    { afinet_sd_set_transport(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 648 "cfg-grammar.y"
    { afinet_sd_set_transport(last_driver, "tcp"); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 649 "cfg-grammar.y"
    { afinet_sd_set_transport(last_driver, "udp"); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 650 "cfg-grammar.y"
    { afinet_sd_set_transport(last_driver, "tls"); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 652 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    last_tls_context = tls_context_new(TM_SERVER);
#endif
	  }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 658 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    afsocket_sd_set_tls_context(last_driver, last_tls_context);
#endif
          }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 663 "cfg-grammar.y"
    {}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 667 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 672 "cfg-grammar.y"
    {
	    last_driver = afprogram_sd_new((yyvsp[(1) - (1)].cptr));
	    free((yyvsp[(1) - (1)].cptr));
	    last_reader_options = &((AFProgramSourceDriver *) last_driver)->reader_options;
	  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 677 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 681 "cfg-grammar.y"
    {
#if ENABLE_SUN_STREAMS
}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 684 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 685 "cfg-grammar.y"
    {
#endif
}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 692 "cfg-grammar.y"
    {
#if ENABLE_SUN_STREAMS
	    last_driver = afstreams_sd_new((yyvsp[(1) - (1)].cptr));
	    free((yyvsp[(1) - (1)].cptr));
#endif
	  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 698 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 707 "cfg-grammar.y"
    {
#if ENABLE_SUN_STREAMS
}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 710 "cfg-grammar.y"
    { afstreams_sd_set_sundoor(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 711 "cfg-grammar.y"
    {
#endif
}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 722 "cfg-grammar.y"
    { last_reader_options->super.init_window_size = (yyvsp[(3) - (4)].num); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 723 "cfg-grammar.y"
    { last_reader_options->super.chain_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 724 "cfg-grammar.y"
    { last_reader_options->super.normalize_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 725 "cfg-grammar.y"
    { last_reader_options->super.keep_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 726 "cfg-grammar.y"
    { last_reader_options->super.use_fqdn = (yyvsp[(3) - (4)].num); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 727 "cfg-grammar.y"
    { last_reader_options->super.use_dns = (yyvsp[(3) - (4)].num); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 728 "cfg-grammar.y"
    { last_reader_options->super.use_dns_cache = (yyvsp[(3) - (4)].num); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 729 "cfg-grammar.y"
    { last_reader_options->super.program_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 730 "cfg-grammar.y"
    { last_reader_options->super.host_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 731 "cfg-grammar.y"
    { gchar *p = strrchr((yyvsp[(3) - (4)].cptr), ':'); if (p) *p = 0; last_reader_options->super.program_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 732 "cfg-grammar.y"
    { last_reader_options->recv_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 733 "cfg-grammar.y"
    { last_reader_options->check_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 734 "cfg-grammar.y"
    { last_reader_options->options = (yyvsp[(3) - (4)].num); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 735 "cfg-grammar.y"
    { last_reader_options->msg_size = (yyvsp[(3) - (4)].num); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 736 "cfg-grammar.y"
    { last_reader_options->fetch_limit = (yyvsp[(3) - (4)].num); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 737 "cfg-grammar.y"
    { last_reader_options->padding = (yyvsp[(3) - (4)].num); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 738 "cfg-grammar.y"
    { last_reader_options->follow_freq = (long) ((yyvsp[(3) - (4)].fnum) * 1000); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 739 "cfg-grammar.y"
    { last_reader_options->follow_freq = ((yyvsp[(3) - (4)].num) * 1000); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 740 "cfg-grammar.y"
    { last_reader_options->super.keep_timestamp = (yyvsp[(3) - (4)].num); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 741 "cfg-grammar.y"
    { last_reader_options->text_encoding = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 742 "cfg-grammar.y"
    { log_reader_options_set_tags(last_reader_options, (yyvsp[(3) - (4)].ptr)); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 744 "cfg-grammar.y"
    {
	    if (last_reader_options->default_pri == 0xFFFF)
	      last_reader_options->default_pri = LOG_USER;
	    last_reader_options->default_pri = (last_reader_options->default_pri & ~7) | (yyvsp[(3) - (4)].num);
          }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 750 "cfg-grammar.y"
    {
	    if (last_reader_options->default_pri == 0xFFFF)
	      last_reader_options->default_pri = LOG_NOTICE;
	    last_reader_options->default_pri = (last_reader_options->default_pri & 7) | (yyvsp[(3) - (4)].num);
          }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 758 "cfg-grammar.y"
    { (yyval.num) = log_reader_options_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 759 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 764 "cfg-grammar.y"
    { log_drv_append((yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); log_drv_unref((yyvsp[(3) - (3)].ptr)); (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 765 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 769 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 770 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 771 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 772 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 773 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 774 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 776 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 781 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 786 "cfg-grammar.y"
    {
	    last_driver = affile_dd_new((yyvsp[(1) - (1)].cptr), 0);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFFileDestDriver *) last_driver)->writer_options;
	  }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 792 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 802 "cfg-grammar.y"
    { last_driver->optional = (yyvsp[(3) - (4)].num); }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 803 "cfg-grammar.y"
    { affile_dd_set_file_uid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 804 "cfg-grammar.y"
    { affile_dd_set_file_uid(last_driver, "-2"); }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 805 "cfg-grammar.y"
    { affile_dd_set_file_gid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 806 "cfg-grammar.y"
    { affile_dd_set_file_gid(last_driver, "-2"); }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 807 "cfg-grammar.y"
    { affile_dd_set_file_perm(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 808 "cfg-grammar.y"
    { affile_dd_set_file_perm(last_driver, -2); }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 809 "cfg-grammar.y"
    { affile_dd_set_dir_uid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 810 "cfg-grammar.y"
    { affile_dd_set_dir_uid(last_driver, "-2"); }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 811 "cfg-grammar.y"
    { affile_dd_set_dir_gid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 812 "cfg-grammar.y"
    { affile_dd_set_dir_gid(last_driver, "-2"); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 813 "cfg-grammar.y"
    { affile_dd_set_dir_perm(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 814 "cfg-grammar.y"
    { affile_dd_set_dir_perm(last_driver, -2); }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 815 "cfg-grammar.y"
    { affile_dd_set_create_dirs(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 816 "cfg-grammar.y"
    { affile_dd_set_overwrite_if_older(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 817 "cfg-grammar.y"
    { affile_dd_set_fsync(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 818 "cfg-grammar.y"
    { affile_dd_set_local_time_zone(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 822 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 827 "cfg-grammar.y"
    {
	    last_driver = affile_dd_new((yyvsp[(1) - (1)].cptr), AFFILE_PIPE);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFFileDestDriver *) last_driver)->writer_options;
	    last_writer_options->flush_lines = 0;
	  }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 833 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 843 "cfg-grammar.y"
    { affile_dd_set_file_uid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 844 "cfg-grammar.y"
    { affile_dd_set_file_uid(last_driver, "-2"); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 845 "cfg-grammar.y"
    { affile_dd_set_file_gid(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 846 "cfg-grammar.y"
    { affile_dd_set_file_gid(last_driver, "-2"); }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 847 "cfg-grammar.y"
    { affile_dd_set_file_perm(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 848 "cfg-grammar.y"
    { affile_dd_set_file_perm(last_driver, -2); }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 852 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 853 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 854 "cfg-grammar.y"
    { last_addr_family = AF_INET; }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 854 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 855 "cfg-grammar.y"
    { last_addr_family = AF_INET; }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 855 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 856 "cfg-grammar.y"
    { last_addr_family = AF_INET6; }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 856 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 857 "cfg-grammar.y"
    { last_addr_family = AF_INET6; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 857 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(4) - (5)].ptr); }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 862 "cfg-grammar.y"
    {
	    last_driver = afunix_dd_new((yyvsp[(1) - (1)].cptr), AFSOCKET_DGRAM);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFSocketDestDriver *) last_driver)->writer_options;
	    last_sock_options = &((AFUnixDestDriver *) last_driver)->sock_options;
	  }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 868 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 873 "cfg-grammar.y"
    {
	    last_driver = afunix_dd_new((yyvsp[(1) - (1)].cptr), AFSOCKET_STREAM);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFSocketDestDriver *) last_driver)->writer_options;
	    last_sock_options = &((AFUnixDestDriver *) last_driver)->sock_options;
	  }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 879 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 895 "cfg-grammar.y"
    {
	    last_driver = afinet_dd_new(last_addr_family,
			(yyvsp[(1) - (1)].cptr), 514,
			AFSOCKET_DGRAM);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFSocketDestDriver *) last_driver)->writer_options;
	    last_sock_options = &((AFInetDestDriver *) last_driver)->sock_options.super;
	  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 903 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 913 "cfg-grammar.y"
    { afinet_dd_set_localip(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 914 "cfg-grammar.y"
    { afinet_dd_set_localport(last_driver, (yyvsp[(3) - (4)].cptr), afinet_dd_get_proto_name(last_driver)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 915 "cfg-grammar.y"
    { afinet_dd_set_destport(last_driver, (yyvsp[(3) - (4)].cptr), afinet_dd_get_proto_name(last_driver)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 916 "cfg-grammar.y"
    { afinet_dd_set_destport(last_driver, (yyvsp[(3) - (4)].cptr), afinet_dd_get_proto_name(last_driver)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 924 "cfg-grammar.y"
    { afinet_dd_set_spoof_source(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 929 "cfg-grammar.y"
    {
	    last_driver = afinet_dd_new(last_addr_family,
			(yyvsp[(1) - (1)].cptr), 514,
			AFSOCKET_STREAM);
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFSocketDestDriver *) last_driver)->writer_options;
	    last_sock_options = &((AFInetDestDriver *) last_driver)->sock_options.super;
	  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 937 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 948 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    last_tls_context = tls_context_new(TM_CLIENT);
#endif
	  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 954 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    afsocket_dd_set_tls_context(last_driver, last_tls_context);
#endif
          }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 962 "cfg-grammar.y"
    { afsocket_dd_set_keep_alive(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 967 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 971 "cfg-grammar.y"
    {
            last_driver = afinet_dd_new(last_addr_family, (yyvsp[(1) - (1)].cptr), 601, AFSOCKET_STREAM | AFSOCKET_SYSLOG_PROTOCOL);
	    last_writer_options = &((AFSocketDestDriver *) last_driver)->writer_options;
	    last_sock_options = &((AFInetDestDriver *) last_driver)->sock_options.super;
	    free((yyvsp[(1) - (1)].cptr));
	  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 977 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 988 "cfg-grammar.y"
    { afinet_dd_set_transport(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 989 "cfg-grammar.y"
    { afinet_dd_set_transport(last_driver, "tcp"); }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 990 "cfg-grammar.y"
    { afinet_dd_set_transport(last_driver, "udp"); }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 991 "cfg-grammar.y"
    { afinet_dd_set_transport(last_driver, "tls"); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 992 "cfg-grammar.y"
    { afinet_dd_set_spoof_source(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 994 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    last_tls_context = tls_context_new(TM_CLIENT);
#endif
	  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1000 "cfg-grammar.y"
    {
#if ENABLE_SSL
	    afsocket_dd_set_tls_context(last_driver, last_tls_context);
#endif
          }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1009 "cfg-grammar.y"
    { (yyval.ptr) = afuser_dd_new((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1013 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1018 "cfg-grammar.y"
    {
	    last_driver = afprogram_dd_new((yyvsp[(1) - (1)].cptr));
	    free((yyvsp[(1) - (1)].cptr));
	    last_writer_options = &((AFProgramDestDriver *) last_driver)->writer_options;
	  }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1023 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1029 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1034 "cfg-grammar.y"
    {
            #if ENABLE_SQL	
            last_driver = afsql_dd_new();
            #endif /* ENABLE_SQL */
          }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1039 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1048 "cfg-grammar.y"
    {
#if ENABLE_SQL
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1051 "cfg-grammar.y"
    { afsql_dd_set_type(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1052 "cfg-grammar.y"
    { afsql_dd_set_host(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1053 "cfg-grammar.y"
    { afsql_dd_set_port(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1054 "cfg-grammar.y"
    { afsql_dd_set_user(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1055 "cfg-grammar.y"
    { afsql_dd_set_password(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1056 "cfg-grammar.y"
    { afsql_dd_set_database(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1057 "cfg-grammar.y"
    { afsql_dd_set_table(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1058 "cfg-grammar.y"
    { afsql_dd_set_columns(last_driver, (yyvsp[(3) - (4)].ptr)); }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1059 "cfg-grammar.y"
    { afsql_dd_set_indexes(last_driver, (yyvsp[(3) - (4)].ptr)); }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1060 "cfg-grammar.y"
    { afsql_dd_set_values(last_driver, (yyvsp[(3) - (4)].ptr)); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1061 "cfg-grammar.y"
    { afsql_dd_set_mem_fifo_size(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1062 "cfg-grammar.y"
    { afsql_dd_set_disk_fifo_size(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1063 "cfg-grammar.y"
    { afsql_dd_set_frac_digits(last_driver, (yyvsp[(3) - (4)].num)); }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1064 "cfg-grammar.y"
    { afsql_dd_set_send_time_zone(last_driver,(yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1065 "cfg-grammar.y"
    { afsql_dd_set_local_time_zone(last_driver,(yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1066 "cfg-grammar.y"
    { afsql_dd_set_null_value(last_driver, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1068 "cfg-grammar.y"
    {
#endif /* ENABLE_SQL */
}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1081 "cfg-grammar.y"
    { last_writer_options->options = (yyvsp[(3) - (4)].num); }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 1082 "cfg-grammar.y"
    { last_writer_options->mem_fifo_size = (yyvsp[(3) - (4)].num); }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1083 "cfg-grammar.y"
    { last_writer_options->flush_lines = (yyvsp[(3) - (4)].num); }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1084 "cfg-grammar.y"
    { last_writer_options->flush_timeout = (yyvsp[(3) - (4)].num); }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1085 "cfg-grammar.y"
    { last_writer_options->suppress = (yyvsp[(3) - (4)].num); }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1086 "cfg-grammar.y"
    {
	                                          last_writer_options->template = cfg_check_inline_template(configuration, (yyvsp[(3) - (4)].cptr));
                                                  if (!cfg_check_template(last_writer_options->template))
	                                            {
	                                              YYERROR;
	                                            }
	                                          free((yyvsp[(3) - (4)].cptr));
	                                        }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1094 "cfg-grammar.y"
    { log_writer_options_set_template_escape(last_writer_options, (yyvsp[(3) - (4)].num)); }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1095 "cfg-grammar.y"
    { last_writer_options->send_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1096 "cfg-grammar.y"
    { last_writer_options->ts_format = cfg_ts_format_value((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1097 "cfg-grammar.y"
    { last_writer_options->frac_digits = (yyvsp[(3) - (4)].num); }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 1098 "cfg-grammar.y"
    { last_writer_options->throttle = (yyvsp[(3) - (4)].num); }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1103 "cfg-grammar.y"
    { (yyval.num) = log_writer_options_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1104 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1109 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1110 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1114 "cfg-grammar.y"
    { configuration->mark_freq = (yyvsp[(3) - (4)].num); }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1115 "cfg-grammar.y"
    { configuration->stats_freq = (yyvsp[(3) - (4)].num); }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1116 "cfg-grammar.y"
    { configuration->stats_level = (yyvsp[(3) - (4)].num); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1117 "cfg-grammar.y"
    { configuration->flush_lines = (yyvsp[(3) - (4)].num); }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1118 "cfg-grammar.y"
    { configuration->flush_timeout = (yyvsp[(3) - (4)].num); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1119 "cfg-grammar.y"
    { configuration->chain_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1120 "cfg-grammar.y"
    { configuration->normalize_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1121 "cfg-grammar.y"
    { configuration->keep_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1122 "cfg-grammar.y"
    { configuration->check_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1123 "cfg-grammar.y"
    { cfg_bad_hostname_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1124 "cfg-grammar.y"
    { configuration->use_time_recvd = (yyvsp[(3) - (4)].num); }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1125 "cfg-grammar.y"
    { configuration->use_fqdn = (yyvsp[(3) - (4)].num); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1126 "cfg-grammar.y"
    { configuration->use_dns = (yyvsp[(3) - (4)].num); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1127 "cfg-grammar.y"
    { configuration->time_reopen = (yyvsp[(3) - (4)].num); }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1128 "cfg-grammar.y"
    { configuration->time_reap = (yyvsp[(3) - (4)].num); }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1130 "cfg-grammar.y"
    {
		  configuration->time_sleep = (yyvsp[(3) - (4)].num);
		  if ((yyvsp[(3) - (4)].num) > 500)
		    {
		      msg_notice("The value specified for time_sleep is too large", evt_tag_int("time_sleep", (yyvsp[(3) - (4)].num)), NULL);
		      configuration->time_sleep = 500;
		    }
		}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1138 "cfg-grammar.y"
    { configuration->log_fifo_size = (yyvsp[(3) - (4)].num); }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 1139 "cfg-grammar.y"
    { configuration->log_iw_size = (yyvsp[(3) - (4)].num); }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 1140 "cfg-grammar.y"
    { configuration->log_fetch_limit = (yyvsp[(3) - (4)].num); }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1141 "cfg-grammar.y"
    { configuration->log_msg_size = (yyvsp[(3) - (4)].num); }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1142 "cfg-grammar.y"
    { configuration->keep_timestamp = (yyvsp[(3) - (4)].num); }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1143 "cfg-grammar.y"
    { configuration->ts_format = cfg_ts_format_value((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1144 "cfg-grammar.y"
    { configuration->frac_digits = (yyvsp[(3) - (4)].num); }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1145 "cfg-grammar.y"
    { /* ignored */; }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1146 "cfg-grammar.y"
    { /* ignored */; }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1147 "cfg-grammar.y"
    { configuration->create_dirs = (yyvsp[(3) - (4)].num); }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1148 "cfg-grammar.y"
    { cfg_file_owner_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1149 "cfg-grammar.y"
    { cfg_file_owner_set(configuration, "-2"); }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1150 "cfg-grammar.y"
    { cfg_file_group_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1151 "cfg-grammar.y"
    { cfg_file_group_set(configuration, "-2"); }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 1152 "cfg-grammar.y"
    { cfg_file_perm_set(configuration, (yyvsp[(3) - (4)].num)); }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 1153 "cfg-grammar.y"
    { cfg_file_perm_set(configuration, -2); }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 1154 "cfg-grammar.y"
    { cfg_dir_owner_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 1155 "cfg-grammar.y"
    { cfg_dir_owner_set(configuration, "-2"); }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 1156 "cfg-grammar.y"
    { cfg_dir_group_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 1157 "cfg-grammar.y"
    { cfg_dir_group_set(configuration, "-2"); }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 1158 "cfg-grammar.y"
    { cfg_dir_perm_set(configuration, (yyvsp[(3) - (4)].num)); }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 1159 "cfg-grammar.y"
    { cfg_dir_perm_set(configuration, -2); }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1160 "cfg-grammar.y"
    { configuration->use_dns_cache = (yyvsp[(3) - (4)].num); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1161 "cfg-grammar.y"
    { configuration->dns_cache_size = (yyvsp[(3) - (4)].num); }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1162 "cfg-grammar.y"
    { configuration->dns_cache_expire = (yyvsp[(3) - (4)].num); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1164 "cfg-grammar.y"
    { configuration->dns_cache_expire_failed = (yyvsp[(3) - (4)].num); }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1165 "cfg-grammar.y"
    { configuration->dns_cache_hosts = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1166 "cfg-grammar.y"
    { configuration->file_template_name = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1167 "cfg-grammar.y"
    { configuration->proto_template_name = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1168 "cfg-grammar.y"
    { configuration->recv_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1169 "cfg-grammar.y"
    { configuration->send_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1170 "cfg-grammar.y"
    { configuration->local_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1171 "cfg-grammar.y"
    { configuration->use_mac_mechanism = (yyvsp[(3) - (4)].num); }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1172 "cfg-grammar.y"
    { configuration->hash_func_name = cfg_ls_hfo_format_value((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1173 "cfg-grammar.y"
    { configuration->initkey_file = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1183 "cfg-grammar.y"
    {
#if ENABLE_SSL
}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1188 "cfg-grammar.y"
    {
	    last_tls_context->verify_mode = tls_lookup_verify_mode((yyvsp[(3) - (4)].cptr));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1193 "cfg-grammar.y"
    {
	    last_tls_context->key_file = g_strdup((yyvsp[(3) - (4)].cptr));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1198 "cfg-grammar.y"
    {
	    last_tls_context->cert_file = g_strdup((yyvsp[(3) - (4)].cptr));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1203 "cfg-grammar.y"
    {
	    last_tls_context->ca_dir = g_strdup((yyvsp[(3) - (4)].cptr));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1208 "cfg-grammar.y"
    {
	    last_tls_context->crl_dir = g_strdup((yyvsp[(3) - (4)].cptr));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1213 "cfg-grammar.y"
    {
            tls_session_set_trusted_fingerprints(last_tls_context, (yyvsp[(3) - (4)].ptr));
          }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1217 "cfg-grammar.y"
    {
            tls_session_set_trusted_dn(last_tls_context, (yyvsp[(3) - (4)].ptr));
          }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1220 "cfg-grammar.y"
    {
#endif
}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1228 "cfg-grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if (!(yyvsp[(1) - (1)].node)) return 1; }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1229 "cfg-grammar.y"
    { (yyvsp[(2) - (2)].node)->comp = !((yyvsp[(2) - (2)].node)->comp); (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1230 "cfg-grammar.y"
    { (yyval.node) = fop_or_new((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1231 "cfg-grammar.y"
    { (yyval.node) = fop_and_new((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1232 "cfg-grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1236 "cfg-grammar.y"
    { (yyval.node) = filter_facility_new((yyvsp[(3) - (4)].num));  }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1237 "cfg-grammar.y"
    { (yyval.node) = filter_facility_new(0x80000000 | (yyvsp[(3) - (4)].num)); }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1238 "cfg-grammar.y"
    { (yyval.node) = filter_level_new((yyvsp[(3) - (4)].num)); }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1239 "cfg-grammar.y"
    { (yyval.node) = filter_call_new((yyvsp[(3) - (4)].cptr), configuration); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1240 "cfg-grammar.y"
    { (yyval.node) = filter_netmask_new((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1241 "cfg-grammar.y"
    { (yyval.node) = filter_tags_new((yyvsp[(3) - (4)].ptr)); }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1243 "cfg-grammar.y"
    {
	    last_re_filter = (FilterRE *) filter_re_new(LM_V_PROGRAM);
          }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1247 "cfg-grammar.y"
    {
            if(!filter_re_set_regexp(last_re_filter, (yyvsp[(3) - (6)].cptr)))
              YYERROR;
            free((yyvsp[(3) - (6)].cptr));

            (yyval.node) = &last_re_filter->super;
          }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1255 "cfg-grammar.y"
    {
	    last_re_filter = (FilterRE *) filter_re_new(LM_V_HOST);
          }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1259 "cfg-grammar.y"
    {
            if(!filter_re_set_regexp(last_re_filter, (yyvsp[(3) - (6)].cptr)))
              YYERROR;
            free((yyvsp[(3) - (6)].cptr));

            (yyval.node) = &last_re_filter->super;
          }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1267 "cfg-grammar.y"
    {
	    last_re_filter = (FilterRE *) filter_match_new();
	  }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1271 "cfg-grammar.y"
    {
            if(!filter_re_set_regexp(last_re_filter, (yyvsp[(3) - (6)].cptr)))
              YYERROR;
            free((yyvsp[(3) - (6)].cptr));
            (yyval.node) = &last_re_filter->super;

            if (last_re_filter->value_handle == 0)
              {
                static gboolean warn_written = FALSE;

                if (!warn_written)
                  {
                    msg_warning("WARNING: the match() filter without the use of the value() option is deprecated and hinders performance, please update your configuration",
                                NULL);
                    warn_written = TRUE;
                  }
              }
          }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1290 "cfg-grammar.y"
    {
	    last_re_filter = (FilterRE *) filter_re_new(LM_V_MESSAGE);
          }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1294 "cfg-grammar.y"
    {
            if(!filter_re_set_regexp(last_re_filter, (yyvsp[(3) - (6)].cptr)))
              YYERROR;
	    free((yyvsp[(3) - (6)].cptr));
            (yyval.node) = &last_re_filter->super;
          }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1301 "cfg-grammar.y"
    {
	    last_re_filter = (FilterRE *) filter_re_new(LM_V_SOURCE);
            filter_re_set_matcher(last_re_filter, log_matcher_string_new());
          }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1306 "cfg-grammar.y"
    {
            if(!filter_re_set_regexp(last_re_filter, (yyvsp[(3) - (6)].cptr)))
              YYERROR;
	    free((yyvsp[(3) - (6)].cptr));
            (yyval.node) = &last_re_filter->super;
          }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1322 "cfg-grammar.y"
    {
            const gchar *p = (yyvsp[(3) - (4)].cptr);
            if (p[0] == '$')
              {
                msg_warning("Value references in filters should not use the '$' prefix, those are only needed in templates",
                            evt_tag_str("value", (yyvsp[(3) - (4)].cptr)),
                            NULL);
                p++;
              }
            last_re_filter->value_handle = log_msg_get_value_handle(p);
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1343 "cfg-grammar.y"
    {
            filter_re_set_matcher(last_re_filter, log_matcher_new((yyvsp[(3) - (4)].cptr)));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1347 "cfg-grammar.y"
    { filter_re_set_flags(last_re_filter, (yyvsp[(3) - (4)].num)); }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1351 "cfg-grammar.y"
    { (yyval.num) = log_matcher_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1352 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1357 "cfg-grammar.y"
    { (yyval.num) = (1 << ((yyvsp[(1) - (2)].num) >> 3)) | (yyvsp[(2) - (2)].num); }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 1358 "cfg-grammar.y"
    { (yyval.num) = (1 << ((yyvsp[(1) - (1)].num) >> 3)); }
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 1362 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (2)].num) | (yyvsp[(2) - (2)].num); }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 1363 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1368 "cfg-grammar.y"
    {
	    (yyval.num) = syslog_make_range((yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num));
	  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1372 "cfg-grammar.y"
    {
	    (yyval.num) = 1 << (yyvsp[(1) - (1)].num);
	  }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1380 "cfg-grammar.y"
    {
            last_parser = (LogParser *) log_csv_parser_new();
          }
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 1384 "cfg-grammar.y"
    { (yyval.ptr) = last_parser; }
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1386 "cfg-grammar.y"
    {
            last_parser = (LogParser *) log_db_parser_new();
          }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1390 "cfg-grammar.y"
    { (yyval.ptr) = last_parser; }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1400 "cfg-grammar.y"
    { log_db_parser_set_db_file(((LogDBParser *) last_parser), (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1405 "cfg-grammar.y"
    { log_column_parser_set_columns((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].ptr)); }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 1409 "cfg-grammar.y"
    {
                                                  LogTemplate *template = cfg_check_inline_template(configuration, (yyvsp[(3) - (4)].cptr));
                                                  if (!cfg_check_template(template))
                                                    {
                                                      YYERROR;
                                                    }
                                                  log_parser_set_template(last_parser, template);
                                                  free((yyvsp[(3) - (4)].cptr));
                                                }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 1428 "cfg-grammar.y"
    { log_csv_parser_set_flags((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].num)); }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1429 "cfg-grammar.y"
    { log_csv_parser_set_delimiters((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1430 "cfg-grammar.y"
    { log_csv_parser_set_quotes((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1431 "cfg-grammar.y"
    { log_csv_parser_set_quote_pairs((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1432 "cfg-grammar.y"
    { log_csv_parser_set_null_value((LogColumnParser *) last_parser, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1436 "cfg-grammar.y"
    { (yyval.num) = log_csv_parser_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1437 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1441 "cfg-grammar.y"
    { (yyval.ptr) = g_list_reverse((yyvsp[(1) - (1)].ptr)); }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1445 "cfg-grammar.y"
    { (yyval.ptr) = g_list_append((yyvsp[(2) - (2)].ptr), (yyvsp[(1) - (2)].ptr)); }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1446 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1451 "cfg-grammar.y"
    {
            last_rewrite = log_rewrite_subst_new((yyvsp[(4) - (4)].cptr));
            free((yyvsp[(4) - (4)].cptr));
          }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1456 "cfg-grammar.y"
    {
            if(!log_rewrite_set_regexp(last_rewrite, (yyvsp[(3) - (8)].cptr)))
              YYERROR;
            free((yyvsp[(3) - (8)].cptr));
            (yyval.ptr) = last_rewrite;
          }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1463 "cfg-grammar.y"
    {
            last_rewrite = log_rewrite_set_new((yyvsp[(3) - (3)].cptr));
            free((yyvsp[(3) - (3)].cptr));
          }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1467 "cfg-grammar.y"
    { (yyval.ptr) = last_rewrite; }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 1477 "cfg-grammar.y"
    {
            const gchar *p = (yyvsp[(3) - (4)].cptr);
            if (p[0] == '$')
              {
                msg_warning("Value references in rewrite rules should not use the '$' prefix, those are only needed in templates",
                            evt_tag_str("value", (yyvsp[(3) - (4)].cptr)),
                            NULL);
                p++;
              }
            last_rewrite->value_handle = log_msg_get_value_handle(p);
            if (log_msg_is_handle_macro(last_rewrite->value_handle))
              {
                msg_warning("Macros are read-only, they cannot be changed in rewrite rules, falling back to MESSAGE instead",
                            evt_tag_str("macro", p),
                            NULL);
                last_rewrite->value_handle = LM_V_MESSAGE;
              }
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 1497 "cfg-grammar.y"
    {
            if (strcmp((yyvsp[(3) - (4)].cptr), "glob") == 0)
              {
                msg_error("Rewrite rules do not support glob expressions",
                          NULL);
                YYERROR;
              }
            log_rewrite_set_matcher(last_rewrite, log_matcher_new((yyvsp[(3) - (4)].cptr)));
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 1507 "cfg-grammar.y"
    { log_rewrite_set_flags(last_rewrite, (yyvsp[(3) - (4)].num)); }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 1511 "cfg-grammar.y"
    { (yyval.num) = 1; }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 1512 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 1513 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 1517 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 1518 "cfg-grammar.y"
    { (yyval.num) = 2; }
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 1524 "cfg-grammar.y"
    { (yyval.cptr) = cfg_lex_get_keyword_string((yyvsp[(1) - (1)].token)); }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 1556 "cfg-grammar.y"
    { (yyval.cptr) = (yyvsp[(1) - (1)].cptr); }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 1557 "cfg-grammar.y"
    { char buf[32]; snprintf(buf, sizeof(buf), "%" G_GINT64_FORMAT, (yyvsp[(1) - (1)].num)); (yyval.cptr) = strdup(buf); }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 1561 "cfg-grammar.y"
    { (yyval.ptr) = g_list_reverse((yyvsp[(1) - (1)].ptr)); }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 1565 "cfg-grammar.y"
    { (yyval.ptr) = g_list_append((yyvsp[(2) - (2)].ptr), g_strdup((yyvsp[(1) - (2)].cptr))); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 1566 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 1571 "cfg-grammar.y"
    {
	    /* return the numeric value of the "level" */
	    int n = syslog_name_lookup_level_by_name((yyvsp[(1) - (1)].cptr));
	    if (n == -1)
	      {
	        msg_error("Unknown priority level",
                          evt_tag_str("priority", (yyvsp[(1) - (1)].cptr)),
                          NULL);
	        YYERROR;
	      }
	    free((yyvsp[(1) - (1)].cptr));
            (yyval.num) = n;
	  }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 1588 "cfg-grammar.y"
    {
            /* return the numeric value of facility */
	    int n = syslog_name_lookup_facility_by_name((yyvsp[(1) - (1)].cptr));
	    if (n == -1)
	      {
	        msg_error("Unknown facility",
	                  evt_tag_str("facility", (yyvsp[(1) - (1)].cptr)),
	                  NULL);
                YYERROR;
	      }
	    free((yyvsp[(1) - (1)].cptr));
	    (yyval.num) = n;
	  }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 1601 "cfg-grammar.y"
    { (yyval.num) = LOG_SYSLOG; }
    break;



/* Line 1806 of yacc.c  */
#line 6170 "cfg-grammar.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1605 "cfg-grammar.y"


extern int linenum;

void
yyerror(char *msg)
{
  fprintf(stderr, "%s in %s at line %d.\n\n"
                  "syslog-ng documentation: http://www.balabit.com/support/documentation/?product=syslog-ng\n"
                  "mailing list: https://lists.balabit.hu/mailman/listinfo/syslog-ng\n", msg, cfg_lex_get_current_file(), cfg_lex_get_current_lineno());
}


