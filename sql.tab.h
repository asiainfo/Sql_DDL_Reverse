
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     ABORT_SYM = 258,
     ACCESSIBLE_SYM = 259,
     ACTION = 260,
     ADD = 261,
     ADDDATE_SYM = 262,
     AFTER_SYM = 263,
     AGAINST = 264,
     AGGREGATE_SYM = 265,
     ALGORITHM_SYM = 266,
     ALL = 267,
     ALTER = 268,
     ANALYSE_SYM = 269,
     ANALYZE_SYM = 270,
     AND_AND_SYM = 271,
     AND_SYM = 272,
     ANY_SYM = 273,
     AS = 274,
     ASC = 275,
     ASCII_SYM = 276,
     ASENSITIVE_SYM = 277,
     AT_SYM = 278,
     AUTOEXTEND_SIZE_SYM = 279,
     AUTO_INC = 280,
     AVG_ROW_LENGTH = 281,
     AVG_SYM = 282,
     BACKUP_SYM = 283,
     BEFORE_SYM = 284,
     BEGIN_SYM = 285,
     BETWEEN_SYM = 286,
     BIGINT = 287,
     BINARY = 288,
     BINLOG_SYM = 289,
     BIN_NUM = 290,
     BIT_AND = 291,
     BIT_OR = 292,
     BIT_SYM = 293,
     BIT_XOR = 294,
     BLOB_SYM = 295,
     BLOCK_SYM = 296,
     BOOLEAN_SYM = 297,
     BOOL_SYM = 298,
     BOTH = 299,
     BTREE_SYM = 300,
     BY = 301,
     BYTE_SYM = 302,
     CACHE_SYM = 303,
     CALL_SYM = 304,
     CASCADE = 305,
     CASCADED = 306,
     CASE_SYM = 307,
     CAST_SYM = 308,
     CATALOG_NAME_SYM = 309,
     CHAIN_SYM = 310,
     CHANGE = 311,
     CHANGED = 312,
     CHARSET = 313,
     CHAR_SYM = 314,
     CHECKSUM_SYM = 315,
     CHECK_SYM = 316,
     CIPHER_SYM = 317,
     CLASS_ORIGIN_SYM = 318,
     CLIENT_SYM = 319,
     CLOSE_SYM = 320,
     COALESCE = 321,
     CODE_SYM = 322,
     COLLATE_SYM = 323,
     COLLATION_SYM = 324,
     COLUMNS = 325,
     COLUMN_SYM = 326,
     COLUMN_FORMAT_SYM = 327,
     COLUMN_NAME_SYM = 328,
     COMMENT_SYM = 329,
     COMMITTED_SYM = 330,
     COMMIT_SYM = 331,
     COMPACT_SYM = 332,
     COMPLETION_SYM = 333,
     COMPRESSED_SYM = 334,
     CONCURRENT = 335,
     CONDITION_SYM = 336,
     CONNECTION_SYM = 337,
     CONSISTENT_SYM = 338,
     CONSTRAINT = 339,
     CONSTRAINT_CATALOG_SYM = 340,
     CONSTRAINT_NAME_SYM = 341,
     CONSTRAINT_SCHEMA_SYM = 342,
     CONTAINS_SYM = 343,
     CONTEXT_SYM = 344,
     CONTINUE_SYM = 345,
     CONVERT_SYM = 346,
     COUNT_SYM = 347,
     CPU_SYM = 348,
     CREATE = 349,
     CROSS = 350,
     CUBE_SYM = 351,
     CURDATE = 352,
     CURRENT_SYM = 353,
     CURRENT_USER = 354,
     CURSOR_SYM = 355,
     CURSOR_NAME_SYM = 356,
     CURTIME = 357,
     DATABASE = 358,
     DATABASES = 359,
     DATAFILE_SYM = 360,
     DATA_SYM = 361,
     DATETIME = 362,
     DATE_ADD_INTERVAL = 363,
     DATE_SUB_INTERVAL = 364,
     DATE_SYM = 365,
     DAY_HOUR_SYM = 366,
     DAY_MICROSECOND_SYM = 367,
     DAY_MINUTE_SYM = 368,
     DAY_SECOND_SYM = 369,
     DAY_SYM = 370,
     DEALLOCATE_SYM = 371,
     DECIMAL_NUM = 372,
     DECIMAL_SYM = 373,
     DECLARE_SYM = 374,
     DEFAULT = 375,
     DEFAULT_AUTH_SYM = 376,
     DEFINER_SYM = 377,
     DELAYED_SYM = 378,
     DELAY_KEY_WRITE_SYM = 379,
     DELETE_SYM = 380,
     DESC = 381,
     DESCRIBE = 382,
     DES_KEY_FILE = 383,
     DETERMINISTIC_SYM = 384,
     DIAGNOSTICS_SYM = 385,
     DIRECTORY_SYM = 386,
     DISABLE_SYM = 387,
     DISCARD = 388,
     DISK_SYM = 389,
     DISTINCT = 390,
     DIV_SYM = 391,
     DOUBLE_SYM = 392,
     DO_SYM = 393,
     DROP = 394,
     DUAL_SYM = 395,
     DUMPFILE = 396,
     DUPLICATE_SYM = 397,
     DYNAMIC_SYM = 398,
     EACH_SYM = 399,
     ELSE = 400,
     ELSEIF_SYM = 401,
     ENABLE_SYM = 402,
     ENCLOSED = 403,
     END = 404,
     ENDS_SYM = 405,
     END_OF_INPUT = 406,
     ENGINES_SYM = 407,
     ENGINE_SYM = 408,
     ENUM = 409,
     EQ = 410,
     EQUAL_SYM = 411,
     ERROR_SYM = 412,
     ERRORS = 413,
     ESCAPED = 414,
     ESCAPE_SYM = 415,
     EVENTS_SYM = 416,
     EVENT_SYM = 417,
     EVERY_SYM = 418,
     EXCHANGE_SYM = 419,
     EXECUTE_SYM = 420,
     EXISTS = 421,
     EXIT_SYM = 422,
     EXPANSION_SYM = 423,
     EXPIRE_SYM = 424,
     EXPORT_SYM = 425,
     EXTENDED_SYM = 426,
     EXTENT_SIZE_SYM = 427,
     EXTRACT_SYM = 428,
     FALSE_SYM = 429,
     FAST_SYM = 430,
     FAULTS_SYM = 431,
     FETCH_SYM = 432,
     FILE_SYM = 433,
     FIRST_SYM = 434,
     FIXED_SYM = 435,
     FLOAT_NUM = 436,
     FLOAT_SYM = 437,
     FLUSH_SYM = 438,
     FORCE_SYM = 439,
     FOREIGN = 440,
     FOR_SYM = 441,
     FORMAT_SYM = 442,
     FOUND_SYM = 443,
     FROM = 444,
     FULL = 445,
     FULLTEXT_SYM = 446,
     FUNCTION_SYM = 447,
     GE = 448,
     GENERAL = 449,
     GEOMETRYCOLLECTION = 450,
     GEOMETRY_SYM = 451,
     GET_FORMAT = 452,
     GET_SYM = 453,
     GLOBAL_SYM = 454,
     GRANT = 455,
     GRANTS = 456,
     GROUP_SYM = 457,
     GROUP_CONCAT_SYM = 458,
     GT_SYM = 459,
     HANDLER_SYM = 460,
     HASH_SYM = 461,
     HAVING = 462,
     HELP_SYM = 463,
     HEX_NUM = 464,
     HIGH_PRIORITY = 465,
     HOST_SYM = 466,
     HOSTS_SYM = 467,
     HOUR_MICROSECOND_SYM = 468,
     HOUR_MINUTE_SYM = 469,
     HOUR_SECOND_SYM = 470,
     HOUR_SYM = 471,
     IDENT = 472,
     IDENTIFIED_SYM = 473,
     IDENT_QUOTED = 474,
     IF = 475,
     IGNORE_SYM = 476,
     IGNORE_SERVER_IDS_SYM = 477,
     IMPORT = 478,
     INDEXES = 479,
     INDEX_SYM = 480,
     INFILE = 481,
     INITIAL_SIZE_SYM = 482,
     INNER_SYM = 483,
     INOUT_SYM = 484,
     INSENSITIVE_SYM = 485,
     INSERT = 486,
     INSERT_METHOD = 487,
     INSTALL_SYM = 488,
     INTERVAL_SYM = 489,
     INTO = 490,
     INT_SYM = 491,
     INVOKER_SYM = 492,
     IN_SYM = 493,
     IO_AFTER_GTIDS = 494,
     IO_BEFORE_GTIDS = 495,
     IO_SYM = 496,
     IPC_SYM = 497,
     IS = 498,
     ISOLATION = 499,
     ISSUER_SYM = 500,
     ITERATE_SYM = 501,
     JOIN_SYM = 502,
     KEYS = 503,
     KEY_BLOCK_SIZE = 504,
     KEY_SYM = 505,
     KILL_SYM = 506,
     LANGUAGE_SYM = 507,
     LAST_SYM = 508,
     LE = 509,
     LEADING = 510,
     LEAVES = 511,
     LEAVE_SYM = 512,
     LEFT = 513,
     LESS_SYM = 514,
     LEVEL_SYM = 515,
     LEX_HOSTNAME = 516,
     LIKE = 517,
     LIMIT = 518,
     LINEAR_SYM = 519,
     LINES = 520,
     LINESTRING = 521,
     LIST_SYM = 522,
     LOAD = 523,
     LOCAL_SYM = 524,
     LOCATOR_SYM = 525,
     LOCKS_SYM = 526,
     LOCK_SYM = 527,
     LOGFILE_SYM = 528,
     LOGS_SYM = 529,
     LONGBLOB = 530,
     LONGTEXT = 531,
     LONG_NUM = 532,
     LONG_SYM = 533,
     LOOP_SYM = 534,
     LOW_PRIORITY = 535,
     LT = 536,
     MASTER_AUTO_POSITION_SYM = 537,
     MASTER_BIND_SYM = 538,
     MASTER_CONNECT_RETRY_SYM = 539,
     MASTER_DELAY_SYM = 540,
     MASTER_HOST_SYM = 541,
     MASTER_LOG_FILE_SYM = 542,
     MASTER_LOG_POS_SYM = 543,
     MASTER_PASSWORD_SYM = 544,
     MASTER_PORT_SYM = 545,
     MASTER_RETRY_COUNT_SYM = 546,
     MASTER_SERVER_ID_SYM = 547,
     MASTER_SSL_CAPATH_SYM = 548,
     MASTER_SSL_CA_SYM = 549,
     MASTER_SSL_CERT_SYM = 550,
     MASTER_SSL_CIPHER_SYM = 551,
     MASTER_SSL_CRL_SYM = 552,
     MASTER_SSL_CRLPATH_SYM = 553,
     MASTER_SSL_KEY_SYM = 554,
     MASTER_SSL_SYM = 555,
     MASTER_SSL_VERIFY_SERVER_CERT_SYM = 556,
     MASTER_SYM = 557,
     MASTER_USER_SYM = 558,
     MASTER_HEARTBEAT_PERIOD_SYM = 559,
     MATCH = 560,
     MAX_CONNECTIONS_PER_HOUR = 561,
     MAX_QUERIES_PER_HOUR = 562,
     MAX_ROWS = 563,
     MAX_SIZE_SYM = 564,
     MAX_SYM = 565,
     MAX_UPDATES_PER_HOUR = 566,
     MAX_USER_CONNECTIONS_SYM = 567,
     MAX_VALUE_SYM = 568,
     MEDIUMBLOB = 569,
     MEDIUMINT = 570,
     MEDIUMTEXT = 571,
     MEDIUM_SYM = 572,
     MEMORY_SYM = 573,
     MERGE_SYM = 574,
     MESSAGE_TEXT_SYM = 575,
     MICROSECOND_SYM = 576,
     MIGRATE_SYM = 577,
     MINUTE_MICROSECOND_SYM = 578,
     MINUTE_SECOND_SYM = 579,
     MINUTE_SYM = 580,
     MIN_ROWS = 581,
     MIN_SYM = 582,
     MODE_SYM = 583,
     MODIFIES_SYM = 584,
     MODIFY_SYM = 585,
     MOD_SYM = 586,
     MONTH_SYM = 587,
     MULTILINESTRING = 588,
     MULTIPOINT = 589,
     MULTIPOLYGON = 590,
     MUTEX_SYM = 591,
     MYSQL_ERRNO_SYM = 592,
     NAMES_SYM = 593,
     NAME_SYM = 594,
     NATIONAL_SYM = 595,
     NATURAL = 596,
     NCHAR_STRING = 597,
     NCHAR_SYM = 598,
     NDBCLUSTER_SYM = 599,
     NE = 600,
     NEG = 601,
     NEW_SYM = 602,
     NEXT_SYM = 603,
     NODEGROUP_SYM = 604,
     NONE_SYM = 605,
     NOT2_SYM = 606,
     NOT_SYM = 607,
     NOW_SYM = 608,
     NO_SYM = 609,
     NO_WAIT_SYM = 610,
     NO_WRITE_TO_BINLOG = 611,
     NULL_SYM = 612,
     NUM = 613,
     NUMBER_SYM = 614,
     NUMERIC_SYM = 615,
     NVARCHAR_SYM = 616,
     OFFSET_SYM = 617,
     OLD_PASSWORD = 618,
     ON = 619,
     ONE_SYM = 620,
     ONLY_SYM = 621,
     OPEN_SYM = 622,
     OPTIMIZE = 623,
     OPTIONS_SYM = 624,
     OPTION = 625,
     OPTIONALLY = 626,
     OR2_SYM = 627,
     ORDER_SYM = 628,
     OR_OR_SYM = 629,
     OR_SYM = 630,
     OUTER = 631,
     OUTFILE = 632,
     OUT_SYM = 633,
     OWNER_SYM = 634,
     PACK_KEYS_SYM = 635,
     PAGE_SYM = 636,
     PARAM_MARKER = 637,
     PARSER_SYM = 638,
     PARTIAL = 639,
     PARTITION_SYM = 640,
     PARTITIONS_SYM = 641,
     PARTITIONING_SYM = 642,
     PASSWORD = 643,
     PHASE_SYM = 644,
     PLUGIN_DIR_SYM = 645,
     PLUGIN_SYM = 646,
     PLUGINS_SYM = 647,
     POINT_SYM = 648,
     POLYGON = 649,
     PORT_SYM = 650,
     POSITION_SYM = 651,
     PRECISION = 652,
     PREPARE_SYM = 653,
     PRESERVE_SYM = 654,
     PREV_SYM = 655,
     PRIMARY_SYM = 656,
     PRIVILEGES = 657,
     PROCEDURE_SYM = 658,
     PROCESS = 659,
     PROCESSLIST_SYM = 660,
     PROFILE_SYM = 661,
     PROFILES_SYM = 662,
     PROXY_SYM = 663,
     PURGE = 664,
     QUARTER_SYM = 665,
     QUERY_SYM = 666,
     QUICK = 667,
     RANGE_SYM = 668,
     READS_SYM = 669,
     READ_ONLY_SYM = 670,
     READ_SYM = 671,
     READ_WRITE_SYM = 672,
     REAL = 673,
     REBUILD_SYM = 674,
     RECOVER_SYM = 675,
     REDOFILE_SYM = 676,
     REDO_BUFFER_SIZE_SYM = 677,
     REDUNDANT_SYM = 678,
     REFERENCES = 679,
     REGEXP = 680,
     RELAY = 681,
     RELAYLOG_SYM = 682,
     RELAY_LOG_FILE_SYM = 683,
     RELAY_LOG_POS_SYM = 684,
     RELAY_THREAD = 685,
     RELEASE_SYM = 686,
     RELOAD = 687,
     REMOVE_SYM = 688,
     RENAME = 689,
     REORGANIZE_SYM = 690,
     REPAIR = 691,
     REPEATABLE_SYM = 692,
     REPEAT_SYM = 693,
     REPLACE = 694,
     REPLICATION = 695,
     REQUIRE_SYM = 696,
     RESET_SYM = 697,
     RESIGNAL_SYM = 698,
     RESOURCES = 699,
     RESTORE_SYM = 700,
     RESTRICT = 701,
     RESUME_SYM = 702,
     RETURNED_SQLSTATE_SYM = 703,
     RETURNS_SYM = 704,
     RETURN_SYM = 705,
     REVERSE_SYM = 706,
     REVOKE = 707,
     RIGHT = 708,
     ROLLBACK_SYM = 709,
     ROLLUP_SYM = 710,
     ROUTINE_SYM = 711,
     ROWS_SYM = 712,
     ROW_FORMAT_SYM = 713,
     ROW_SYM = 714,
     ROW_COUNT_SYM = 715,
     RTREE_SYM = 716,
     SAVEPOINT_SYM = 717,
     SCHEDULE_SYM = 718,
     SCHEMA_NAME_SYM = 719,
     SECOND_MICROSECOND_SYM = 720,
     SECOND_SYM = 721,
     SECURITY_SYM = 722,
     SELECT_SYM = 723,
     SENSITIVE_SYM = 724,
     SEPARATOR_SYM = 725,
     SERIALIZABLE_SYM = 726,
     SERIAL_SYM = 727,
     SESSION_SYM = 728,
     SERVER_SYM = 729,
     SERVER_OPTIONS = 730,
     SET = 731,
     SET_VAR = 732,
     SHARE_SYM = 733,
     SHIFT_LEFT = 734,
     SHIFT_RIGHT = 735,
     SHOW = 736,
     SHUTDOWN = 737,
     SIGNAL_SYM = 738,
     SIGNED_SYM = 739,
     SIMPLE_SYM = 740,
     SLAVE = 741,
     SLOW = 742,
     SMALLINT = 743,
     SNAPSHOT_SYM = 744,
     SOCKET_SYM = 745,
     SONAME_SYM = 746,
     SOUNDS_SYM = 747,
     SOURCE_SYM = 748,
     SPATIAL_SYM = 749,
     SPECIFIC_SYM = 750,
     SQLEXCEPTION_SYM = 751,
     SQLSTATE_SYM = 752,
     SQLWARNING_SYM = 753,
     SQL_AFTER_GTIDS = 754,
     SQL_AFTER_MTS_GAPS = 755,
     SQL_BEFORE_GTIDS = 756,
     SQL_BIG_RESULT = 757,
     SQL_BUFFER_RESULT = 758,
     SQL_CACHE_SYM = 759,
     SQL_CALC_FOUND_ROWS = 760,
     SQL_NO_CACHE_SYM = 761,
     SQL_SMALL_RESULT = 762,
     SQL_SYM = 763,
     SQL_THREAD = 764,
     SSL_SYM = 765,
     STARTING = 766,
     STARTS_SYM = 767,
     START_SYM = 768,
     STATS_AUTO_RECALC_SYM = 769,
     STATS_PERSISTENT_SYM = 770,
     STATS_SAMPLE_PAGES_SYM = 771,
     STATUS_SYM = 772,
     STDDEV_SAMP_SYM = 773,
     STD_SYM = 774,
     STOP_SYM = 775,
     STORAGE_SYM = 776,
     STRAIGHT_JOIN = 777,
     STRING_SYM = 778,
     SUBCLASS_ORIGIN_SYM = 779,
     SUBDATE_SYM = 780,
     SUBJECT_SYM = 781,
     SUBPARTITIONS_SYM = 782,
     SUBPARTITION_SYM = 783,
     SUBSTRING = 784,
     SUM_SYM = 785,
     SUPER_SYM = 786,
     SUSPEND_SYM = 787,
     SWAPS_SYM = 788,
     SWITCHES_SYM = 789,
     SYSDATE = 790,
     TABLES = 791,
     TABLESPACE = 792,
     TABLE_REF_PRIORITY = 793,
     TABLE_SYM = 794,
     TABLE_CHECKSUM_SYM = 795,
     TABLE_NAME_SYM = 796,
     TEMPORARY = 797,
     TEMPTABLE_SYM = 798,
     TERMINATED = 799,
     TEXT_STRING = 800,
     TEXT_SYM = 801,
     THAN_SYM = 802,
     THEN_SYM = 803,
     TIMESTAMP = 804,
     TIMESTAMP_ADD = 805,
     TIMESTAMP_DIFF = 806,
     TIME_SYM = 807,
     TINYBLOB = 808,
     TINYINT = 809,
     TINYTEXT = 810,
     TO_SYM = 811,
     TRAILING = 812,
     TRANSACTION_SYM = 813,
     TRIGGERS_SYM = 814,
     TRIGGER_SYM = 815,
     TRIM = 816,
     TRUE_SYM = 817,
     TRUNCATE_SYM = 818,
     TYPES_SYM = 819,
     TYPE_SYM = 820,
     UDF_RETURNS_SYM = 821,
     ULONGLONG_NUM = 822,
     UNCOMMITTED_SYM = 823,
     UNDEFINED_SYM = 824,
     UNDERSCORE_CHARSET = 825,
     UNDOFILE_SYM = 826,
     UNDO_BUFFER_SIZE_SYM = 827,
     UNDO_SYM = 828,
     UNICODE_SYM = 829,
     UNINSTALL_SYM = 830,
     UNION_SYM = 831,
     UNIQUE_SYM = 832,
     UNKNOWN_SYM = 833,
     UNLOCK_SYM = 834,
     UNSIGNED = 835,
     UNTIL_SYM = 836,
     UPDATE_SYM = 837,
     UPGRADE_SYM = 838,
     USAGE = 839,
     USER = 840,
     USE_FRM = 841,
     USE_SYM = 842,
     USING = 843,
     UTC_DATE_SYM = 844,
     UTC_TIMESTAMP_SYM = 845,
     UTC_TIME_SYM = 846,
     VALUES = 847,
     VALUE_SYM = 848,
     VARBINARY = 849,
     VARCHAR = 850,
     VARIABLES = 851,
     VARIANCE_SYM = 852,
     VARYING = 853,
     VAR_SAMP_SYM = 854,
     VIEW_SYM = 855,
     WAIT_SYM = 856,
     WARNINGS = 857,
     WEEK_SYM = 858,
     WEIGHT_STRING_SYM = 859,
     WHEN_SYM = 860,
     WHERE = 861,
     WHILE_SYM = 862,
     WITH = 863,
     WITH_CUBE_SYM = 864,
     WITH_ROLLUP_SYM = 865,
     WORK_SYM = 866,
     WRAPPER_SYM = 867,
     WRITE_SYM = 868,
     X509_SYM = 869,
     XA_SYM = 870,
     XML_SYM = 871,
     XOR = 872,
     YEAR_MONTH_SYM = 873,
     YEAR_SYM = 874,
     ZEROFILL = 875
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 134 "sql.yy"

	SqlItem* pItem;



/* Line 1676 of yacc.c  */
#line 678 "sql.tab.hh"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

