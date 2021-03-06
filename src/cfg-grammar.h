/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 99 "cfg-grammar.y"

        gint token;
	gint64 num;
	double fnum;
	char *cptr;
	void *ptr;
	FilterExprNode *node;



/* Line 2068 of yacc.c  */
#line 369 "cfg-grammar.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


