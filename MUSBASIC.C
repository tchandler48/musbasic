/sys region=4096
/file obj1 n(musbasic.obj) new(repl)
/inc watc
/job nogo


/* BXbasic.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011 */
/* Modified (2020) T. Chandler MUSBASIC musbasic.c   */


/*--------------------- DECLARE HEADERS ---------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*------ Main.c ------*/
    void pgm_parser(void);
    void parser(void);

/*------ Error.c ------*/
    void a_bort(int,int);
    void err_hndlr(int,int,int,int,int);
 
/*------ Input.c ------*/
    void line_cnt(char *argv[]);
    void load_src(void);
    void tmp_byte(int);
    void loader_1(void);
    void tmp_label(int);
    void tmp_byte(int);
     int get_byte(int);
    void tmp_prog(int);
    void loader_2(void);
    void get_MOD(int);
    void token_if(int);
    void str_funn(int);
     int IsEqu(int);
    void get_strfunc(char *,int);
    void str_copy(char *,int);
    void str_fun2(int);
    void get_mathfunc(char *,int);
    void preproc_sub(int);
    void str_fun3(int ndx);
 

/*------ Output.c ------*/
    void get_prnstring(void);
    void get_prnvar(void);
    char *value2strng(double);
    void get_strvar(char *);
    void parse_print(void);
    void set_TabNl(int);
    void prn_strfunc(void);
    void proc_digit(void);
    void get_strarray(char *);
    void get_strUDT(void);


/*------ Utility.c ------*/
      int iswhite(int);
     int iswhiter(int);
     int find_strng(char *);
     int get_Nvtype(int);
     int while_isalnum(int);
     int while_dd(int pi);
     int get_quote(int,int);
     int get_vtype(int);
     int get_Arrytype(int);
     int get_paramsCount(int,int);
     int get_objtype(int);
     int get_offset2(int *,int,int);
     int get_arrayndx(char *);
     int get_ObjectType(char *);
    void Sav_ObjName(char *,int,int);
    void InitObj(void);
     int get_iarrayndx(char *);
     int get_farrayndx(char *);
     int get_darrayndx(char *);
    char *local_var(char *);
     int isthis_anarray(int, int);
    char *global_var(char *);
    void set_ObjectParam(char *, int);
    void get_pnam(void);


/*------ Strings.c ------*/
    void dim_gstr(char *);
    void parse_str(char *);
    void strng_assgn(void);
    void strvar_assgn(void);
    void asn_function(void);
     int get_strndx(char *);
    char *str_express(void);
    void inputstr(void);
    void mkdstr(void);
    void parse_strarry(char *);
    void dim_strarry(char *,int,int);
    void redim_strarry(char *);
    void erase_strArray(char *);
    void reuse_strarry(char *,int);
 

/*------ Variable.c ------*/
    void parse_let(void);
  double get_varvalue(void);
    char *get_varname(void);
     int get_vndx(char *);
     int get_llvarndx(char *);
  double get_avalue(void);
    void do_dim_var(void);
    void dim_var(void);
    void parse_dim(void);
    void dim_gint(char *);
    void dim_glong(char *);
    void dim_gsingle(char *);
    void dim_gdouble(char *);
    void let_int(char *);
    void let_long(char *);
    void let_single(char *);
    void let_double(char *);
    void bld_global_table(void);
     int get_gvarndx(char *);
     int get_lvarndx(char *);
     int get_var_index(char *);
 

/*------ Rdparser.c ------*/
  double rdp_main(void);
  double Expression(void);
  double Term(void);
  double Factor(void);
    void Match(char);
    void _GetChar(void);
  double GetNum(void);
     int IsAddop(char);
     int IsMultop(char);
     int Is_White(char);
    void SkipWhite(void);
  double asc_2_dbl(void);
  double math_functn(void);


/*------ Arrays.c ------*/
    void do_dim(void);
    void dim_intarry(char *,int,int);
    void dim_fltarry(char *,int,int);
    void dim_dblarry(char *,int,int);
    void reuse_intarry(char *,int);
    void reuse_fltarry(char *,int);
    void reuse_dblarry(char *,int);
    void parse_intarry(char *);
    void parse_fltarry(char *);
    void parse_dblarry(char *);
    void erase_array(void);
    void erase_intArray(char *);
    void erase_fltArray(char *);
    void erase_dblArray(char *);
    void do_redim(void);
    void redim_intarry(char *);
    void redim_fltarry(char *);
    void redim_dblarry(char *);
  double let_intarray(char *);
  double let_fltarray(char *);
  double let_dblarray(char *);


/*------ Loops.c ------*/
    void go_to(void);
    void do_gosub(void);
    void do_return(void);
    void do_for(void);
    void do_next(void);
     int get_From(void);
     int get_To(void);
     int get_Step(void);
    void do_While(void);
    void do_Wend(void);
     int find_wend(int);
    void do_DoWhile(void);
    void do_WDo(void);
   

/*------ Subs.c ------*/
    void do_declare(void);
    void save_sub(char *, int);
    void stor_paramType(int, int, int);
    void do_callsub(void);
    void push_call(char *);
     int push_params(void);
    void enter_sub(void);
    void do_retsb(void);
    void garbage_col(void);
  

/*------ Ifendif.c ------*/
    void do_if(void);
     int boolexpress(void);
     int Nboolterm(int);
     int Nrelation(double);
     int eval_value(double,double,int);
     int AndOrBoolExp(void);
     int IsAndOrOp(void);
     int Sboolterm(int);
     int Srelation(char *);
     int eval_string(char *,char *,int);
     int get_type(void);
     int get_string(void);
    void get_qstring(void);
     int get_op(void);
     int find_if(int);
     int find_else(int);
     int if_eof(void);
     int is_eof(void);
    void do_Switch(void);
    void do_Case(void);
     int find_case(int);
     int find_sw(int);
     int sw_boolexpres(void);


/*------ Getinput.c ------*/
    void get_input(void);
    void input_str(char *,int);
    void input_val(char *,int);
    void get_lninput(void);


/*------ Fileio.c ------*/
    void reset_handle(int);
    void zero_handle(int);
    void parse_open(void);
    void get_iomode(int);
    void fopen_short(char,int,int);
    void do_fclose(void);
    void input_io(void);
    void get_finput(int,int,char);
    void read_fstring(int,char *);
    void read_fvalue(int,char *);
    void read_fline(int,char *);
    void print_io(void);
    void write_io(void);
    void get_foutput(int,int,char);
     int write_fstring(int,int,char *);
     int write_fvalue(int,int,char *);
    void print_fstring(int,char *);
    void random_fio(int,int);
    void init_fldbffrs(void);
    void do_field(void);
    void cnt_field(int,int,int);
    void asn_field(int,int);
    void do_lset(void);
    void do_rset(void);
    void get_ndxcnt(int);
    void do_put(void);
    void lod_bffr(int,int);
    void do_get(void);
    void fil_bffr(int,int);
    void do_kill(void);
 

/*------ Structs.c ------*/
    void struct_Udt(void);
     int isThisUdt(char *, int);
    void parse_UDTstr(void);
    void assn_UDTval(void);
     int get_UDTndx(void);
     int get_UdtvNamIdx(char *, int, int);
    void get_UDTstr(void);
  double get_Uval(char *);
  double get_UDTlfd(char *);

const int _staksize=50*1024;  /* set stack size to 70K bytes */


/* --- declare constants --- */
#define BUFSIZE     256
#define TOKEN_LEN   21
#define VAR_NAME    33
#define LLEN        33
#define IOARRAY     99
#define PATH        129
#define REC_LEN     128
#define DATASIZE    80
#define PARAM_STK   10


/*--------------------- SYSTEM VARIABLES ---------------------*/

    FILE *f_in, *f_out;        /* these are the i/o file handles */
    char prog_name[VAR_NAME];  /* program source-file name      */
    char p_string[BUFSIZE];    /* file input string             */
    char **array1;             /* pointer to program array      */
    char t_holder[20];         /* token data holder             */
    char s_holder[BUFSIZE];    /* xstring (print) data holder   */
     int nrows;                /* numbers of lines in source file */
     int ncolumns=BUFSIZE;     /* dimension for array1[][columns] */
     int line_ndx;             /* current execution line        */
     int s_pos, e_pos;         /* pointers to start & end of token */
    char xstring[BUFSIZE];     /* the print string              */
    char **temp_prog;          /* temp program array            */
    char **temp_label;         /* temp label name array         */
     int *temp_byte;           /* temp byte code array          */
     int *byte_array;          /* byte code array               */
    char **label_nam;          /* labels name array             */
     int token;                /* token: current byte code      */
    char var_type;             /* current variable type         */
     int use_socket = 0;	   /* tcp socket flag		 */
 unsigned char clearch=0x70;
                      

/*--------------------- GLOBAL VARIABLES ---------------------*/

  struct Global_Table
  {
        char Nam[VAR_NAME];
         int ActSub;           /* which Sub does it belong to   */
         int Int;              /* stack:integer variable values */
        long Lng;              /* stack:long variable values    */
       float Flt;              /* stack:float variable values   */
      double Dbl;              /* stack:double float values     */
        char *Str;             /* stack:string variable array   */
  };
  struct Global_Table *Gtbl;
     int glb_vct = 0;

     int ActvSubs = 0;         /* number of currently active Subs */

     int *gosub_stack;         /* Gosub: stack array            */
     int gs_ptr=0;             /* Gosub: stack position pointer */
                            
     int fornxt_flg=0;         /* For/Next: global flag         */
    char func_type;            /* current function type         */
                           
     int do_flag=0;            /* DoWhile: instance flag        */
     int do_pointer;           /* Do: jump back line address    */
                          
     int sw_flag=0;            /* Switch/Case instance flag     */
     int iswitch;              /* Switch/Case: test value       */
                           

        /* ----------- end global vars ------------ */


/*--------------------- FILE VARIABLES ---------------------*/

  struct io_handles
  {
         char path[PATH];
         char mode;
         FILE *fptr;
  };
  struct io_handles fp[IOARRAY]; /* File: handles structure     */
                            
  struct field_buffer          /* File: Field Buffer structure  */
  {
         char *f_bffr;         /* I/O buffer                    */
     unsigned bfr_size;        /* buffer length                 */
          int *str_len;        /* string length                 */
         char **str_name;      /* string name                   */
          int fld_count;       /* number of strings             */
         long record;          /* current record number         */
          int flag;            /* PUT flag, to clear buffer     */
  };                           /* File: handles structure       */
  struct field_buffer fld_bffr[IOARRAY];
                           
     int lset_ndx;             /* File: global Lset/Rset var_index */
  struct lset_rset
  {
          int ndx;
          int cnt;
  } lrs;
                           
                                    
/*----------------------- GLOBAL ARRAYS ----------------------*/

  struct string_array
  {
       char name[VAR_NAME];    /* string array name             */
       char **elem;            /* array element pointers        */
       int  dim;               /* number of dimensions          */
       int  sub[10];           /* subscripts(2,3,4)             */
  };
  struct string_array *strArry;
     int sArryCnt=0;           /* array counter                 */
                           
  struct integer_array
  {
       char name[VAR_NAME];    /* integer array name            */
       long *elem;             /* array element pointers        */
       int  dim;               /* number of dimensions          */
       int  sub[10];           /* subscripts(2,3,4)             */
  };
  struct integer_array *intArry;
     int iArryCnt=0;           /* array counter                 */
                            
  struct float_array
  {
       char name[VAR_NAME];    /* float array name              */
       float *elem;            /* array element pointers        */
       int  dim;               /* number of dimensions          */
       int  sub[10];           /* subscripts(2,3,4)             */
  };
  struct float_array *fltArry;
     int fArryCnt=0;           /* array counter                 */
                            

  struct double_array
  {
       char name[VAR_NAME];    /* double array name             */
       double *elem;           /* array element pointers        */
       int  dim;               /* number of dimensions          */
       int  sub[10];           /* subscripts(2,3,4)             */
  };
  struct double_array *dblArry;
     int dArryCnt=0;           /* array counter                 */
                            
/*--- freed array space flags ---*/
    int fre_int=0;
    int fre_flt=0;
    int fre_dbl=0;
    int fre_str=0;
                           
/*----------------------- GLOBAL SUBs ------------------------*/

/*--- OBJECTS ---*/
    char **ObjIndx;            /* object/variables name index   */
     int **ObjType;            /* object/variables type specifier */
     int ObjNdxCnt=0;          /* object/variables index count  */
    char **ObjSubVar;          /* object/local variable flag    */

/*--- SUB's ---*/
    char **SubNameStack;       /* stack:sub name stack          */
    char SubName[VAR_NAME];    /* this sub name                 */
    char *paramStack[10];      /* stack:parameter names stack   */
     int paramType[10];        /* var type of passed parameter  */

     int paramCnt=0;           /* parameter count               */
     int thisSub;              /* this sub pointer              */

     int callFlag=0;           /* sub call flag                 */

/* -------- SUB structs -------- */

     int subCnt=0;             /* counter:number of SUBs declared   */

  struct Sub_Routines
  {
      char SubName[VAR_NAME];  /* this sub name                 */
       int paramCnt;           /* parameter count               */
       int paramType[10];      /* var type of passed parameter  */
  };
  struct Sub_Routines *SubR;

  struct Sub_Index             /* use this struct as a search table */
  {
       int index;              /* index for this sub-name       */
      char SubName[VAR_NAME];  /* this sub name                 */
  };
  struct Sub_Index *Sndx;

  struct Push_Stack
  {
         int Typ;          /* stack:variable type               */
         int Int;          /* stack:integer variable values     */
        long Lng;          /* stack:long variable values        */
       float Flt;          /* stack:float variable values       */
      double Dbl;          /* stack:double float values         */
        char *Str;         /* stack:string variable array       */
  };
  struct Push_Stack *pStk;

  struct Return_Stack
  {
         int ret_Addr;     /* stack:Sub return address          */
         int Vrcnt;        /* stack: variables count            */
  };
  struct Return_Stack *rStk;

     int sub_ndx;

/* -------- end SUB structs -------- */


/*--------------------- LOCAL VARIABLES ----------------------*/

  struct Local_Table
  {  
    char Nam[VAR_NAME];
    int Typ;
    int Adr;
  };
  struct Local_Table *Ltbl;

  int lcl_cnt = 0;
  int *thissub_vars;
  int submax_cnt;
  int *sub_stack;

/*--------------------- UDT STRUCTURES --------------------*/

  struct tag_UDT
  {
      char udtName[VAR_NAME];          /* UDT:DBase             */
       int numVars;                    /* UDT:4                 */
      char **varNames;                 /* UDT:int,long,single,string */
       int *type;                      /* UDT:type=1            */
       int *size;                      /* UDT:size=4            */
       int *offset;                    /* UDT:offset=0          */
       int length;                     /* UDT:length            */
      char *data;                      /* UDT:values array      */
  };
  struct tag_UDT *UDT;
  struct tag_UDT *udtTest;

     int UdtCnt = 0;                   /* UDT counter           */
     int udtpi;                        /* udt char pointer      */
    char udtTmpName[VAR_NAME];         /* udt temp name storage */


/*--------------------- BEGIN PROGRAM ---------------------*/

int main(int numarg, char *cmdarg[])
{   
  int x=0;
  int ii;
  unsigned size = 1; 
 
  strcpy(prog_name, cmdarg[2]);
  
  for(ii=0; ii < IOARRAY; ii++)         /* clear I/O file handles */   
  {	
    zero_handle(ii);
  }

  for(ii=0; ii < IOARRAY; ii++)        /* initialize file buffers */   
  {
    fld_bffr[ii].f_bffr = malloc(size * sizeof(char));
    fld_bffr[ii].f_bffr[0] = '\0';
    fld_bffr[ii].bfr_size = 1;
    fld_bffr[ii].record = 1;
    fld_bffr[ii].fld_count = 0;
    fld_bffr[ii].flag = 0;
  }
  line_cnt(numarg);
  pgm_parser();

  /* --- end of program --- */
  
  free(label_nam);
  free(byte_array);
  free(array1);
  return 0;
}
/*--------- end main ---------*/


void pgm_parser()
{
  int ii = 0;
   
  line_ndx = 0;
  while(line_ndx < nrows)
  {   
    s_pos = 0;
    e_pos = 0;
    strcpy(p_string, array1[line_ndx]);
    token = byte_array[line_ndx];
    parser();
    line_ndx++;
  }
}
/*-------- end pgm_parser ---------*/


void parser()
{   
  int ab_code=4, x=line_ndx;

  switch(token)
  {   
    case 0:			      /* REM */
      break;
 
    case 1:                      /* LET */
      parse_let();
      break;

    case 2:                      /* CLEAR */
      if(ActvSubs == 0)
      {
        free(Gtbl);
        glb_vct = 0;
      }
      break;

    case 3:                      /* LOCATE */
      break;

    case 4:                      /* PRINT */
      parse_print();
      break;

    case 5:                      /* GOTO */
      go_to();
      break;

    case 6:                      /* BEEP */
      break;

    case 7:                      /* CLS */
      printf("%c\n",clearch);
      break;
  
    case 8:                      /* END */
      printf("\nEnd of Program\n");
      line_ndx = nrows;
      break;

    case 9:                      /* GOSUB */
      do_gosub();
      break;

    case 10:                     /* RETURN */
      do_return();
      break;

    case 11:                     /* FOR */
      do_for();
      break;

    case 12:                     /* NEXT */
      do_next();
      break;

    case 13:                     /* IF */
      do_if();
      break;

    case 14:                     /* ELSEIF */
      do_if();
      break;

    case 15:                     /* ELSE */
      return;
      break;
   
    case 16:                     /* ENDIF */
      return;
      break;

    case 17:                     /* INPUT */
      get_input();
      break;

    case 18:                     /* LINE INPUT */
      get_lninput();
      break;

    case 19:                     /* OPEN */
      parse_open();
      break;

    case 20:                     /* CLOSE */
      do_fclose();
      break;

    case 21:                     /* WRITE */
      write_io();
      break;

    case 22:                     /* FIELD */
      do_field();
      break;

    case 23:                     /* LSET */
      do_lset();
      break;

    case 24:                     /* RSET */
      do_rset();
      break;

    case 25:                     /* PUT */
      do_put();
      break;

    case 26:                     /* GET */
      do_get();
      break;
   
    case 27:                     /* WHILE */
      do_While();
      break;

    case 28:                     /* WEND */
      return;
      break;

    case 29:                     /* DO */
      do_DoWhile();
      break;

    case 30:                     /* REDIM array */
      do_redim();
      break;

    case 31:                     /* SWITCH */
      do_Switch();
      break;

    case 32:                     /* CASE */
      do_Case();
      break;

    case 33:                     /* DEFAULT */
      return;
      break;
  
    case 34:                     /* ENDSWITCH */
      return;
      break;

    case 35:                     /* DIM array */
      do_dim_var();
      break;

    case 36:                     /* DECLARE */
      do_declare();
      break;

    case 37:                     /* CALL */
      do_callsub();
      break;

    case 38:                     /* SUB-label */
      enter_sub();
      break;
 
    case 39:                     /* ENDSUB */
      do_retsb();
      break;
   
    case 40:                     /* STOP */
      line_ndx = nrows;
      break;

    case 41:                     /* SYSTEM */
      line_ndx = nrows;
      break;

    case 43:                     /* ERASE */
      erase_array();
      break;

    case 44:                     /* RANDOM */
  /*          do_random(); */
       break;

    case 45:                     /* KILL (delete) a file */
      do_kill();
      break;

    case 126:                    /* UDT/STRUCT */
      struct_Udt();
      break;

    case 127:                    /* ENDUDT/ENDSTRUCT */
    /* drop thru, do nothing. */
      return;
      break;

    case -1:	/* block label */
      break;
    
    default:
      a_bort(ab_code, x);
      break;
  }
}
/*--------- end parser ---------*/

/* bxbasic : Arrays.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011          */
/* Modified T.Chandler CMSBASIC - arrays.c   */

/* variable types:
    int    = no symbol,
    long   = %,
    float  = !,
    double = #,
    string = $
  ---------------
   array types:
    long   = %,
    float  = !,
    double = #,
    string = $
*/

#include "MUSBPROT.h"

void do_dim()
{   
  char varname[VAR_NAME],ch;
  int pi, len, type, ab_code=33, x=line_ndx;

  len = strlen(p_string);
  pi = e_pos;
  /* get_alpha Start */
  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }

  /* get_alpha Stop */
  if(pi == len)						
  {
    a_bort(ab_code, x);
  }

  e_pos = pi;
  strcpy(varname, get_varname());			
  pi = e_pos;
  /* --- get array type --- */
  type = get_Arrytype(pi);				
  if(type < 6)
  {
    a_bort(ab_code, x);
  }
  else if(type == 6)					
  {
    if(fre_str > 0)
    {
      reuse_strarry(varname, type);
    }
    else
    {
      dim_strarry(varname, len, type);
    }
  }
  else if(type == 7)					
  {
    if(fre_int > 0)
    {
      reuse_intarry(varname, type);
    }
    else
    {
      dim_intarry(varname, len, type);
    }
  }
  else if(type == 8)					
  {
    if(fre_flt > 0)
    {
      reuse_fltarry(varname, type);
    }
    else
    {
      dim_fltarry(varname, len, type);
    }
  }
  else if(type == 9)					
  {
    if(fre_dbl > 0)
    {
      reuse_dblarry(varname, type);
    }
    else
    {
      dim_dblarry(varname, len, type);
    }
  }
  else
  {
    /* other array types */
  }
}
/*------- end do_dim -------*/


void dim_intarry(char *varname, int len, int type)
{   
  int pi, indx, param, subscript, ab_code, x=line_ndx;
  unsigned multiplier, size;
  char ch;

  pi = e_pos;
  /*--- integer array ---*/
  if(iArryCnt > 0)
  {
    indx = 0;
    while((strcmp(varname, intArry[indx].name) != 0) && (indx < iArryCnt))
    {
      indx++;
    }
    if(indx < iArryCnt)		
    {
      ab_code = 34;
      a_bort(ab_code, x);
    }
  }

  if(iArryCnt == 0)
  {
    size = 1;
    intArry = malloc(size * sizeof(struct integer_array));
  }
  else
  {
    size = iArryCnt + 1;
    intArry = realloc(intArry, size * sizeof(struct integer_array));
  }

  strcpy(intArry[iArryCnt].name, varname);
  param = get_paramsCount(pi, len);	
  intArry[iArryCnt].dim = param;
  Sav_ObjName(varname, type, param);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }

  /* get_paren Stop */
  pi++;
  e_pos = pi;
  multiplier = 1;
  for(indx=0; indx < param; indx++)
  {
    subscript = (int) get_avalue();
    intArry[iArryCnt].sub[indx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];

    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }

  intArry[iArryCnt].elem = malloc(multiplier * sizeof(long));
  iArryCnt++;					
}
/*------- end dim_intarry -------*/


void dim_fltarry(char *varname, int len, int type)
{   
  int pi, indx, param, subscript, ab_code, x=line_ndx;
  unsigned multiplier, size;
  char ch;

  pi = e_pos;
  /*--- float array ---*/
  if(fArryCnt > 0)
  {
    indx = 0;
    while((strcmp(varname, fltArry[indx].name) != 0) && (indx < fArryCnt))
    {
      indx++;
    }
    if(indx < fArryCnt)		
    {
      ab_code = 34;
      a_bort(ab_code, x);
    }
  }

  if(fArryCnt == 0)
  {
    size = 1;
    fltArry = malloc(size * sizeof(struct float_array));
  }
  else
  {
    size = fArryCnt + 1;
    fltArry = realloc(fltArry, size * sizeof(struct float_array));
  }

  strcpy(fltArry[fArryCnt].name, varname);
  param = get_paramsCount(pi, len);	
  fltArry[fArryCnt].dim = param;
  Sav_ObjName(varname, type, param);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }

  /* get_paren Stop */
  pi++;
  e_pos = pi;
  multiplier = 1;
  for(indx=0; indx < param; indx++)
  {
    subscript = (int) get_avalue();
    fltArry[fArryCnt].sub[indx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }

  fltArry[fArryCnt].elem = malloc(multiplier * sizeof(float));
  fArryCnt++;					
}
/*------- end dim_fltarry -------*/


void dim_dblarry(char *varname, int len, int type)
{   
  int pi, indx, param, subscript, ab_code, x=line_ndx;
  unsigned multiplier, size;
  char ch;

  pi = e_pos;
  /*--- float array ---*/
  if(dArryCnt > 0)
  {
    indx = 0;
    while((strcmp(varname, dblArry[indx].name) != 0) && (indx < dArryCnt))
    {
      indx++;
    }
    if(indx < dArryCnt)		
    {
      ab_code = 34;
      a_bort(ab_code, x);
    }
  }

  if(dArryCnt == 0)
  {
    size = 1;
    dblArry = malloc(size * sizeof(struct double_array));
  }
  else
  {
    size = dArryCnt + 1;
    dblArry = realloc(dblArry, size * sizeof(struct double_array));
  }

  strcpy(dblArry[dArryCnt].name, varname);
  param = get_paramsCount(pi, len);	
  dblArry[dArryCnt].dim = param;
  Sav_ObjName(varname, type, param);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }

  /* get_paren Stop */
  pi++;
  e_pos = pi;
  multiplier = 1;
  for(indx=0; indx < param; indx++)
  {
    subscript = (int) get_avalue();
    dblArry[dArryCnt].sub[indx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }

  dblArry[dArryCnt].elem = malloc(multiplier * sizeof(double));
  dArryCnt++;					
}
/*------- end dim_dblarry -------*/


void reuse_intarry(char *name, int type)
{  
  char varname[VAR_NAME];             
  int ndx, indx;

  varname[0] = '\0';
  indx = get_iarrayndx(varname);
  ndx = 0;
  while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != '\0'))
  {
    ndx++;
  }
  strcpy(ObjIndx[ndx], name);
  ObjType[ndx][0] = type;
  strcpy(varname, name);
  strcpy(intArry[indx].name, varname);
  redim_intarry(varname);
  fre_int--;
}
/*------- end reuse_intarry -------*/


void reuse_fltarry(char *name, int type)
{   
  char varname[VAR_NAME];             
  int ndx, indx;

  varname[0] = '\0';
  indx = get_farrayndx(varname);
  ndx = 0;
  while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != '\0'))
  {
    ndx++;
  }
  strcpy(ObjIndx[ndx], name);
  ObjType[ndx][0] = type;
  strcpy(varname, name);
  strcpy(fltArry[indx].name, varname);
  redim_fltarry(varname);
  fre_flt--;
}
/*------- end reuse_fltarry -------*/


void reuse_dblarry(char *name, int type)
{   
  char varname[VAR_NAME];             
  int ndx, indx;

  varname[0] = '\0';
  indx = get_darrayndx(varname);
  ndx = 0;
  while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != '\0'))
  {
    ndx++;
  }
  strcpy(ObjIndx[ndx], name);
  ObjType[ndx][0] = type;
  strcpy(varname, name);
  strcpy(dblArry[indx].name, varname);
  redim_dblarry(varname);
  fre_dbl--;
}
/*------- end reuse_dblarry -------*/


void parse_intarry(char *varname)
{   
  int pi, len, indx, nDims, offset;
  char ch;
  int *Subscripts;

  indx = get_iarrayndx(varname); 
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &intArry[indx].sub[0];     
  nDims = intArry[indx].dim;             
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  Match('=');
  intArry[indx].elem[offset] = (long) rdp_main();
}
/*---------- end parse_intarry ----------*/


void parse_fltarry(char *varname)
{   
  int pi, len, indx, nDims, offset;
  char ch;
  int *Subscripts;

  indx = get_farrayndx(varname);
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &fltArry[indx].sub[0];     
  nDims = fltArry[indx].dim;              
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  Match('=');
  fltArry[indx].elem[offset] = (float) rdp_main();
}
/*---------- end parse_fltarry ----------*/


void parse_dblarry(char *varname)
{
  int pi, len, indx, nDims, offset;
  char ch;
  int *Subscripts;

  indx = get_darrayndx(varname);
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &dblArry[indx].sub[0];     
  nDims = dblArry[indx].dim;              
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  /* --- now get assignment value --- */
  Match('=');
  dblArry[indx].elem[offset] = (double) rdp_main();
}
/*---------- end parse_dblarry ----------*/


void do_redim()
{
  char varname[VAR_NAME],ch;
  int pi, len, ndx=0, type, ab_code=11, x=line_ndx;

  len = strlen(p_string);
  pi = e_pos;
  /* get_alpha Start */
  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_alpha Stop */
  if(pi == len)                     
  {
    a_bort(ab_code, x);
  }
  e_pos = pi;
  strcpy(varname, get_varname());		
  pi = e_pos;
  type = get_Arrytype(pi);				
  if(type < 6)
  {
    ab_code = 13;
    a_bort(ab_code, x);
  }
  e_pos = pi;
  switch(type)
  {
    case 6:						
      redim_strarry(varname);
      break;

    case 7:						
      redim_intarry(varname);
      break;

    case 8:						
      redim_fltarry(varname);
      break;

    case 9:						
      redim_dblarry(varname);
      break;
  }
}
/*-------- end do_redim ---------*/


void redim_intarry(char *varname)
{   
  int pi, len, ii, ndx, indx, param, subscript;
  unsigned multiplier;
  char ch;

  indx = get_iarrayndx(varname);
  pi = e_pos;
  len = strlen(p_string);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  param = get_paramsCount(pi, len);    
  intArry[indx].dim = param;
  set_ObjectParam(varname, param);
  e_pos = pi;
  multiplier = 1;
  for(ii = 0; ii < 10; ii++)
  {                                    
    intArry[indx].sub[ii] = '\0';
  }
  for(ndx=0; ndx < param; ndx++)
  {
    subscript = (int) get_avalue();
    intArry[indx].sub[ndx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }
  intArry[indx].elem = realloc(intArry[indx].elem, 
                      multiplier * sizeof(long));
}
/*------- end redim_intarry -------*/


void redim_fltarry(char *varname)
{   
  int pi, len, ii, ndx, indx, param, subscript;
  unsigned multiplier;
  char ch;

  indx = get_farrayndx(varname);
  pi = e_pos;
  len = strlen(p_string);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  param = get_paramsCount(pi, len);    
  fltArry[indx].dim = param;
  set_ObjectParam(varname, param);
  e_pos = pi;
  multiplier = 1;
  for(ii = 0; ii < 10; ii++)
  {                                    
    fltArry[indx].sub[ii] = '\0';
  }
  for(ndx=0; ndx < param; ndx++)
  {
    subscript = (int) get_avalue();
    fltArry[indx].sub[ndx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }
  fltArry[indx].elem = realloc(fltArry[indx].elem, 
                       multiplier * sizeof(float));
}
/*------- end redim_fltarry -------*/


void redim_dblarry(char *varname)
{   
  int pi, len, ii, ndx, indx, param, subscript;
  unsigned multiplier;
  char ch;

  indx = get_darrayndx(varname);
  pi = e_pos;
  len = strlen(p_string);
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  param = get_paramsCount(pi, len);   
  dblArry[indx].dim = param;
  set_ObjectParam(varname, param);
  e_pos = pi;
  multiplier = 1;
  for(ii = 0; ii < 10; ii++)
  {                                    
    dblArry[indx].sub[ii] = '\0';
  }
  for(ndx=0; ndx < param; ndx++)
  {
    subscript = (int) get_avalue();
    dblArry[indx].sub[ndx] = subscript;
    multiplier = multiplier * subscript;
    pi = e_pos;
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;
  }
  dblArry[indx].elem = realloc(dblArry[indx].elem, 
                   multiplier * sizeof(double));
}
/*------- end redim_dblarry -------*/


void erase_array()
{   
  char varname[VAR_NAME],ch;
  int pi, len, type;
  int ab_code=32, x=line_ndx;

  len = strlen(p_string);
  pi = 0;
  /* get_alpha Start */
  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_alpha Stop */
  if(pi == len)					
  {
    a_bort(ab_code, x);
  }
  e_pos = pi;
  strcpy(varname, get_varname());			
  pi = e_pos;
  type = get_Arrytype(pi);
  if(type < 6)
  {
    ab_code = 36;
    a_bort(ab_code, x);
  }
  else if(type == 6)					
  {
    erase_strArray(varname);
  }
  else if(type == 7)					
  {
    erase_intArray(varname);
  }
  else if(type == 8)                 
  {
    erase_fltArray(varname);
  }
  else if(type >= 9)                
  {
    erase_dblArray(varname);
  }
}
/*------- end erase_array -------*/


void erase_dblArray(char *varname)
{   
  int indx, ii;

  indx = get_darrayndx(varname);
  free(dblArry[indx].elem);
  dblArry[indx].name[0] = '\0';
  for(ii = 0; ii < 10; ii++)
  {                                    
    dblArry[indx].sub[ii] = '\0';
  }
  indx = 0;
  while((indx < ObjNdxCnt) && (strcmp(varname, ObjIndx[indx]) != 0))
  {
    indx++;
  }
  ObjIndx[indx][0] = '\0';
  ObjType[indx][0] = 0;
  ObjType[indx][1] = 0;
  fre_dbl++;                    
}
/*------- end erase_dblArray -------*/


void erase_fltArray(char *varname)
{   
  int indx, ii;

  indx = get_farrayndx(varname);
  free(fltArry[indx].elem);
  fltArry[indx].name[0] = '\0';
  for(ii = 0; ii < 10; ii++)
  {                                    
    fltArry[indx].sub[ii] = '\0';
  }
  indx = 0;
  while((indx < ObjNdxCnt) && (strcmp(varname, ObjIndx[indx]) != 0))
  {
    indx++;
  }
  ObjIndx[indx][0] = '\0';
  ObjType[indx][0] = 0;
  ObjType[indx][1] = 0;
  fre_flt++;                      
}
/*------- end erase_fltArray -------*/


void erase_intArray(char *varname)
{   
  int indx, ii;

  indx = get_iarrayndx(varname);
  free(intArry[indx].elem);
  intArry[indx].name[0] = '\0';
  for(ii = 0; ii < 10; ii++)
  {                                    
    intArry[indx].sub[ii] = '\0';
  }
  indx = 0;
  while((indx < ObjNdxCnt) && (strcmp(varname, ObjIndx[indx]) != 0))
  {
    indx++;
  }
  ObjIndx[indx][0] = '\0';
  ObjType[indx][0] = 0;
  ObjType[indx][1] = 0;
  fre_int++;                      
}
/*------- end erase_intArray -------*/


double let_intarray(char *varname)
{   
  int pi, len, indx, nDims, offset;
  int *Subscripts;
  char ch;
  double value;

  e_pos = s_pos;
  indx = get_iarrayndx(varname);
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &intArry[indx].sub[0];     
  nDims = intArry[indx].dim;              
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  value = (double) intArry[indx].elem[offset];
  return value;
}
/*-------- end let_intarray --------*/


double let_fltarray(char *varname)
{
  int pi, indx, len, nDims, offset;
  int *Subscripts;
  char ch;
  double value;

  e_pos = s_pos;
  indx = get_farrayndx(varname);
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &fltArry[indx].sub[0];    
  nDims = fltArry[indx].dim;             
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  value = (double) fltArry[indx].elem[offset];
  return value;
}
/*-------- end let_fltarray --------*/


double let_dblarray(char *varname)
{   
  int pi, indx, len, nDims, offset;
  int *Subscripts;
  char ch;
  double value;

  e_pos = s_pos;
  indx = get_darrayndx(varname);
  len = strlen(p_string);
  pi = e_pos;
  /* get_paren Start */
  ch = p_string[pi];
  while((strchr("()", ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_paren Stop */
  pi++;
  e_pos = pi;
  Subscripts = &dblArry[indx].sub[0];     
  nDims = dblArry[indx].dim;              
  offset = get_offset2(Subscripts, nDims, len);
  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  e_pos = pi;
  value = dblArry[indx].elem[offset];
  return value;
}
/*-------- end let_dblarray --------*/

/* cmsbasic : error.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011          */
/* Modified T.Chandler CMSBASIC - error.c    */

void a_bort(int code,int line_ndx)
{
  switch(code)
  {
    case 1:
      printf("Unspecified Program Name.\n");
      printf("Enter:\"MUSBASIC program_name.bas\"\n");
      printf("code(%d)\n",code);
      break;
 
    case 2:
      printf("Program file:\"%s\" not found.\n", t_holder);
      printf("Enter: \"MUSBASIC program_name.bas\"\n");
      printf("Program Terminated.\ncode(%d)\n", code);
      break;

    case 3:
      printf("\nSyntax error: in program line:");
      printf(" %d.\n%s",(line_ndx+1),p_string);
      printf("Keywords must be in UpperCase:\n");
      printf("code(%d)\n", code);
      break;

    case 4:
      printf("\nSyntax error: in program line:");
      printf(" %d.\n%s",(line_ndx+1),p_string);
      printf("Unknown Command.\ncode(%d)\n", code);
      break;

    case 5:
      printf("\nVariable Type error: in program line:");
      printf(" %d.\n%s",(line_ndx+1),p_string);
      printf("Type must be: Integer.\ncode(%d)\n", code);
      break;

    case 6:
      printf("\nSyntax error: in program line:");
      printf(" %d.\n%s",(line_ndx+1),p_string);
      printf("No closing quotes.\ncode(%d)\n", code);
      break;

    case 7:
      printf("\nSyntax error: in program line:");
      printf(" %d.\n%s",(line_ndx+1),p_string);
      printf("Expected: \"%s\".\ncode(%d)\n",t_holder,code);
      break;

    case 8:
      printf("\nGOTO Error: no such label:");
      printf(" %s:\nin program line:",t_holder);
      printf(" %d:\nGOTO %s",(line_ndx+1),p_string);
      printf("Program Terminated\ncode(%d)\n", code);
      break;

    case 9:
      printf("\nSyntax error: in program line: %d.\n",(line_ndx+1));
      printf("%s", p_string);
      printf("Missing quotes.\ncode(%d)\n", code);
      break;

    case 11:
      printf("\nSyntax error: in program line: %d.\n",(line_ndx+1));
      printf("%s", p_string);
      printf("Useage LET (variable assignment):\ncode(%d)\n", code);
      break;
 
    case 12:
      printf("\nExpected %s ",t_holder);
      printf(": in line: %d.\n", (line_ndx+1));
      printf("%scode(%d)\n", p_string, code);
      break;

    case 13:
      printf("\nVariable not found: in line: %d.\n", (line_ndx+1));
      printf("%scode(%d)\n", p_string, code);
      break;

    case 14:
      printf("\nInvalid operator: in line: %d.\n", (line_ndx+1));
      printf("%scode(%d)\n", p_string, code);
      break;

    case 15:
      printf("\nSyntax error: in line: %d.\n", (line_ndx+1));
      printf("%s {value} not found.\n%s", t_holder, p_string);
      printf("code(%d)\n", code);
      break;

    case 16:
      printf("\nFOR NEXT error: in line: %d.\n", (line_ndx+1));
      printf("NEXT without a FOR.\nNEXT %s", p_string);
      printf("code(%d)\n", code);
      break;

    case 17:
      printf("\nIF:Operand Type error: in line: ");
      printf("%d.\n%s\nNot a valid ", (line_ndx+1), p_string);
      printf("variable type.\ncode(%d)\n", code);
      break;

    case 18:
      printf("\nRelational Operator Type error: in line: ");
      printf("%d.\n%s\nValid operators:", (line_ndx+1), p_string);
      printf(" =<> .\ncode(%d)\n", code);
      break;

    case 19:
      printf("\nINPUT : error: in statement: %d.\n",(line_ndx+1));
      printf("INPUT %sUsage: INPUT \"Enter your ", p_string);
      printf("name\"; name$:\ncode(%d)\n", code);
      break;

    case 20:
      printf("\nOPEN : error: in statement: %d.\n",(line_ndx+1));
      printf("%s\tOPEN %sUsage: OPEN \"I\", #1, ",xstring,p_string);
      printf("\"filename\"\ncode(%d)\n", code);
      break;
 
    case 21:
      printf("\nINPUT : error: in statement: ");
      printf("%d.\n\tINPUT %s%s\n",(line_ndx+1),p_string,xstring);
      printf("Usage: INPUT#1, input$, (var,,)\ncode(%d)\n", code);
      break;
 
    case 22:
      printf("\nCLOSE : error: in statement: %d.\n",(line_ndx+1));
      printf("\tCLOSE %s%s\t",p_string,xstring);
      printf("Usage: CLOSE 1, (handle,,)\ncode(%d)\n", code);
      break;

    case 23:
      printf("\nIF EOF : error: in statement: ");
      printf("%d.\n\tIF %s%s",(line_ndx+1),p_string,xstring);
      printf("Usage: IF EOF(1) THEN...\ncode(%d)\n", code);
      break;

    case 24:
      printf("\nWRITE : error: in statement: ");
      printf("%d.\n\tWRITE %s%s\n",(line_ndx+1),p_string,xstring);
      printf("Usage: WRITE#1, output$, (var,,)\ncode(%d)\n", code);
      break;

    case 25:
      printf("\nFIELD : error: in statement: %d.\n",(line_ndx+1));
      printf("\tFIELD %s%s\n",p_string,xstring);
      printf("Usage: FIELD 1, 1 AS a$, (var,,)\ncode(%d)\n", code);
      break;

    case 26:
      printf("\nLSET : error: in statement: ");
      printf("%d.\n\tLSET %s%s",(line_ndx+1),p_string,xstring);
      printf("Usage: LSET A$ = var$\ncode(%d)\n", code);
      break;

    case 27:
      printf("\nRSET : error: in statement: ");
      printf("%d.\n\tRSET %s%s",(line_ndx+1),p_string,xstring);
      printf("Usage: RSET A$ = var$\ncode(%d)\n", code);
      break;

    case 28:
      printf("\nPUT : error: in statement: ");
      printf("%d.\n\tPUT %s%s",(line_ndx+1),p_string,xstring);
      printf("Usage: PUT 1, [record%c]\ncode(%d)\n", '%', code);
      break;

    case 29:
      printf("\nGET : error: in statement: ");
      printf("%d.\n\tGET %s%s",(line_ndx+1),p_string,xstring);
      printf("Usage: GET 1, [record%c]\ncode(%d)\n", '%', code);
      break;

    case 30:
      printf("\nLOC : error: in statement: %d.\n",(line_ndx+1));
      printf("%s\nUsage: n = LOC(1)\n",xstring);
      printf("code(%d)\n", code);
      break;

    case 31:
      printf("\nLOF : error: in statement: %d.\n",(line_ndx+1));
      printf("%s\nUsage: n = LOF(1)\n",xstring);
      printf("code(%d)\n", code);
      break;

    case 32:
      printf("\nWHILE : error: in statement: %d.\n",(line_ndx+1));
      printf("WHILE without WEND\n");
      printf("code(%d)\n", code);
      break;

    case 33:
      printf("\nDIM Array(n)\tin statement:%d\n",(line_ndx+1));
      printf("%s", p_string);
      printf("Invalid array type.\ncode(%d)\n", code);
      break;

    case 34:
      printf("\nDIM Array(n)\tin statement:%d\n",(line_ndx+1));
      printf("%s", p_string);
      printf("Array already dimensioned.\ncode(%d)\n", code);
      break;

    case 35:
      printf("\nArray index not found\n");
      printf("%s in line:%d\n", p_string, (line_ndx+1));
      printf("Recheck spelling of array name.\n");
      printf("code(%d)\n", code);
      break;
  
    case 36:
      printf("\nERASE Array(n)\tin statement:%d\n",(line_ndx+1));
      printf("%s", p_string);
      printf("Invalid array type.\ncode(%d)\n", code);
      break;

    case 37:
      printf("\nCASE without SWITCH, in line:%d\n", line_ndx+1);
      printf("CASE %s", p_string);
      printf("code(%d)\n", code);
      break;

    case 38:
      printf("\nNo SUBs have been DECLARED, in line:%d\n", line_ndx+1);
      printf("CALL %s", p_string);
      printf("code(%d)\n", code);
      break;

    case 39:
      printf("\nSUB has not been DECLARED, in line:%d\n", line_ndx+1);
      printf("CALL %s", p_string);
      printf("code(%d)\n", code);
      break;

    case 40:
      printf("\nRETURN without GOSUB, in line:%d\n", line_ndx+1);
      printf("code(%d)\n", code);
      break;

    case 42:
      printf("\nDECLARE without SUB, in line:%d\n", line_ndx+1);
      printf("DECLARE %s", p_string);
      printf("code(%d)\n", code);
      break;

    case 43:
      printf("\nDECLARE %s...in line:%d\n", p_string, line_ndx+1);
      printf("Functions are not yet enabled.\n");
      printf("code(%d)\n", code);
      break;

    case 44:
      printf("\nVariable not found: in line: %d.\n", (line_ndx+1));
      printf("CALL %s...%s\n", p_string, s_holder);
      printf("\ncode(%d)\n", code);
      break;

    case 45:
      printf("\nCALL without Parameter: in line: %d.\n", (line_ndx+1));
      printf("CALL %s", p_string);
      printf("\ncode(%d)\n", code);
      break;

    case 46:
      printf("\nSUB without Parameter: in line: %d.\n", (line_ndx+1));
      printf("SUB %s", p_string);
      printf("\ncode(%d)\n", code);
      break;

    case 47:
      printf("\nSyntax error: in program line: %d.\n",(line_ndx+1));
      printf("NAME %s", p_string);
      printf("Use: NAME Old, New .\ncode(%d)\n", code);
      break;

    case 48:
      printf("\nSyntax error: in program line: %d.\n",(line_ndx+1));
      printf("MESSAGEBOX %s", p_string);
      printf("\nMissing delimiter (comma)\ncode(%d)\n", code);
      break;

    case 49:
      printf("\nCall_Type: %s  not supported.\n", s_holder);
      printf("in program line: %d.\n",(line_ndx+1));
      printf("\nCALLAPI %s code(%d)\n", p_string, code);
      break;

    case 54:
      printf("\nDraw Line error: in program line: %d.\n",(line_ndx+1));
      printf("LINE %s", p_string);
      printf("\nNo gui window created yet.\ncode(%d)\n", code);
      break;

    case 55:
      printf("\nDraw error: in program line: %d.\n",(line_ndx+1));
      printf("%s %s", t_holder, p_string);
      printf("\nDid not find window name.\ncode(%d)\n", code);
      break;

    case 56:
      printf("\nDraw Box error: in program line: %d.\n",(line_ndx+1));
      printf("BOX %s", p_string);
      printf("\nNo gui window created yet.\ncode(%d)\n", code);
      break;

    case 57:
      printf("\nDraw Text error: in program line: %d.\n",(line_ndx+1));
      printf("TEXT %s", p_string);
      printf("\nNo gui window created yet.\ncode(%d)\n", code);
      break;

    case 58:
      printf("\nFONT error: in program line: %d.\n",(line_ndx+1));
      printf("FONT %s", p_string);
      printf("\nNo gui window created yet.\ncode(%d)\n", code);
      break;

    case 78:
      printf("\nBKMODE error: in program line: %d.\n",(line_ndx+1));
      printf("BKMODE %s", p_string);
      printf("\nNo gui window created yet.\ncode(%d)\n", code);
      break;

    case 79:
      printf("\nBKMODE error: in program line: %d.\n",(line_ndx+1));
      printf("BKMODE %s", p_string);
      printf("\nMode type not found.\ncode(%d)\n", code);
      break;

    case 97:
      printf("\nSYSMETRIC error: in program line: %d.\n",(line_ndx+1));
      printf("%s", p_string);
      printf("\nMetric parameter not found.\ncode(%d)\n", code);
      break;

    case 131:
      printf("\nSyntax error: in program line: %d.\n",(line_ndx+1));
      printf("UDT %s", p_string);
      printf("Useage: UDT (udt name):\ncode(%d)\n", code);
      break;
 
    case 132:
      printf("\nUDT Element not found: in line: %d.\n", (line_ndx+1));
      printf("%scode(%d)\n", p_string, code);
      break;

    case 133:
      printf("\nUDT structure found: in line: %d.\n", (line_ndx+1));
      printf("UDT %s\n", p_string);
      printf("UDT already defined.\ncode(%d)\n", code);
      break;

    default:
      printf("Program aborted, undefined error.\n");
      printf("%s", p_string);
      break;
  }
 
/*    
  int ii;

  printf("\n");
  for(ii = (subCnt-1); ii >= 0; ii--)
  {
    printf("%d, %s\n", ii, SubR[ii].SubName);
  }
  printf("\nvar count=%d\nactive subs=%d\n\n", glb_vct, ActvSubs);
*    exit(1); * 

  if(glb_vct > 0)
  {
    printf("\nloop\n");
    for(ii = (glb_vct - 1); ii >= 0; ii--)
    {
      printf("%d, %s, %d\n", ii, Gtbl[ii].Nam, Gtbl[ii].Int);
    }
  }
  exit(1);
*/
}
/*----------end a_bort -----------*/


void err_hndlr(int ab_code, int x, int mssg, int p1, int p2)
{
  int ibool=0;

  switch(mssg)
  {
    case 1:
      if(p1 == p2)
      {
        strcpy(xstring, "Invalid I/O Mode:");
        ibool = 1;
      }
      break;
     
    case 2:
      if(p1 == p2)
      {
        strcpy(xstring, "Invalid I/O Format:");
        ibool = 1;
      }
      break;
     
    case 3:
      if((p1 < 0) || (p1 > p2))
      {
        strcpy(xstring, "Invalid File Number:\n1 to 99:");
        ibool = 1;
      }
      break;
    
    case 4:
      if(fp[p1].path[0] != '\0')
      {
        strcpy(xstring, "File Number In Use:");
        ibool = 1;
      }
      break;
     
    case 5:
      if(p1 == p2)
      {
        strcpy(xstring, "Invalid File Name:");
        ibool = 1;
      }
      break;
    
    case 6:
      strcpy(xstring, "Unable to Open File:");
      break;

    case 7:
      if(fp[p1].mode != 'I')
      {
        strcpy(xstring, "FILE not OPEN for INPUT:");
        ibool = 1;
      }
      break;
     
    case 8:
      if((p1 != 'O') && (p1 != 'A'))
      {   
        strcpy(xstring, "FILE not OPEN for OUTPUT:");
        ibool = 1;
      }
      break;
 
    case 9:
      if(fp[p1].path[0] == '\0')
      {
        strcpy(xstring, "File Number Not Open:");
        ibool = 1;
      }
      break;
      
    case 10:
      if(p1 == p2)
      {
        strcpy(xstring, "Invalid Field Format:");
        ibool = 1;
      }
      break;
     
    case 11:
      if(p1 < p2)
      {
        strcpy(xstring, "Invalid Field Format:");
        ibool = 1;
      }
      break;
     
    case 12:
      if(p1 > p2)
      {
        strcpy(xstring, "Incorrect Field length:");
        ibool = 1;
      }
      break;
     
    case 13:
      if((p1 == 0) || (p2 >= IOARRAY))
      {
        strcpy(xstring, "Source variable not found:\n");
        ibool = 1;
      }
      break;
     
    default:
      break;
  }
  if(ibool == 1)
  {
    a_bort(ab_code,x);
  }
}

/* cmsbasic : Fileio.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011           */
/* Modified T. Chandler - CMSBASIC fileio.c   */


void reset_handle(int ndx)
{
  FILE *handle;

  handle = fp[ndx].fptr;           
  fclose(handle);
  zero_handle(ndx);
}
/*------ end reset_handle -------*/


void zero_handle(int ndx)
{
  fp[ndx].path[0] = '\0';              
  fp[ndx].mode = '\0';
  fp[ndx].fptr = '\0';
}
/*------ end zero_handle -------*/


void parse_open()
{   
  int pi, len, ab_code=20, x=line_ndx;
  char ch;

  len = strlen(p_string);
  pi = e_pos;
  /* get_upper Start */
  ch = p_string[pi];
  while((isupper(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_upper Stop */
  err_hndlr(ab_code, x, 1, pi, len);     
  e_pos = pi;
  get_iomode(len);
}
/*------ end parse_open -------*/


void get_iomode(int len)
{   
  char ch, io_mode;
  int pi, ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=20;
  double file_no;

  pi = e_pos;
  ch = p_string[pi];
  io_mode = ch;
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  err_hndlr(ab_code, x, 2, pi, len);    
  e_pos = pi;
  file_no = get_avalue();
  ndx = (int) file_no;
  ndx--;
  err_hndlr(ab_code, x, 3, ndx, maxfiles); 
  err_hndlr(ab_code, x, 4, ndx, 0);        
  fopen_short(io_mode, ndx, len);
}
/*------ end get_iomode -------*/


void fopen_short(char io_mode, int ndx, int len)
{
  char ch, quote='\"', io_path[PATH], varname[VAR_NAME];
  int pi, indx, x=line_ndx, ab_code=20;
  FILE *handle;

  pi = e_pos;
  ch = p_string[pi];
  while((ch != quote) && (isalpha(ch) == 0) && (pi < len))
  {
    pi++;                      
    ch = p_string[pi];              
  }
  err_hndlr(ab_code, x, 5, pi, len);        
  e_pos = pi;
  if(ch == quote)			    
  {
    strng_assgn();
    strcpy(io_path, s_holder);
  }
  else				 
  {
    strcpy(varname, get_varname());
    indx = get_strndx(varname);
    strcpy(io_path, Gtbl[indx].Str);
  }
  fp[ndx].mode = io_mode;                    
  strcpy(fp[ndx].path, io_path);
  switch(io_mode)
  {
    case 'I':			       
      handle = fopen(io_path, "r");
      err_hndlr(ab_code, x, 6, pi, len); 
      break;

    case 'O':			      
      handle = fopen(io_path, "w");
      err_hndlr(ab_code, x, 6, pi, len);
      break;

    case 'A':			      
      handle = fopen(io_path, "a");
      err_hndlr(ab_code, x, 6, pi, len);
      break;
 
    case 'R':			      
      handle = fopen(io_path, "r+");
      if(handle == NULL)
      {
        handle = fopen(io_path, "w+");
      }
      random_fio(ndx, len);
      err_hndlr(ab_code, x, 6, pi, len);
      break;

    default:			  
      err_hndlr(ab_code, x, 1, 0, 0);
      break;
  }
  if(handle == NULL)
  {
    a_bort(ab_code,x);                    
  }
  else
  {
    fp[ndx].fptr = handle;
  }
}
/*------ end fopen_short -------*/


void do_fclose()
{   
  char ch;
  int ii, pi, ndx, len, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=22;
  double file_no;

  len = strlen(p_string);
  pi = e_pos;
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  if(pi == len)			      
  {
    for(ii=0; ii<IOARRAY; ii++)
    {
      if(fp[ii].path[0] != '\0')	 
      {
        reset_handle(ii);
      }
    }
  }
  else
  {
    ch = p_string[pi];
    while(pi < len)
    {
      if(isdigit(ch) == 0)
      {
        /* get_digit Start */
        ch = p_string[pi];
        while((isdigit(ch) == 0) && (pi < len))
        {
          pi++;
          ch = p_string[pi];
        }
        /* get_digit Stop */
      }
      if(pi < len)
      {
        e_pos = pi;
        file_no = get_avalue();
        ndx = (int) file_no;
        ndx--;
        err_hndlr(ab_code, x, 3, ndx, maxfiles);
        if(fp[ndx].path[0] != '\0')     
        {
          reset_handle(ndx);
        }
        pi = e_pos;
        ch = p_string[pi];
        }
      }
  }
}
/*------ end do_fclose -------*/


void input_io()
{
  char ch;
  int pi, port, len, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=21;
  double file_no;

  len = strlen(p_string);
  pi = e_pos;
  ch = p_string[pi]; 
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  err_hndlr(ab_code, x, 2, pi, len);        
  e_pos = pi;
  file_no = get_avalue();
  port = (int) file_no;
  port--;
  err_hndlr(ab_code, x, 3, port, maxfiles);  
  err_hndlr(ab_code, x, 7, port, 0);     
 get_finput(port, len, ch);
}
/*------- end input_io ----------*/


void get_finput(int port, int len, char chx)
{   
  char ch, varname[VAR_NAME];
  int pi, type;

  pi = e_pos;
  ch = p_string[pi];
  while((pi < len) && (ch != '\n'))  
  {
    if(isalpha(ch) == 0)
    {
      /* get_alpha Start */
      ch = p_string[pi];
      while((isalpha(ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_alpha Stop */
      ch = p_string[pi];
    }
    if(pi < len)
    {
      e_pos = pi;
      type = get_vtype(pi);
      e_pos = pi;
      strcpy(varname, get_varname());  
      if(chx == '@')               
      {
        read_fline(port, varname);
        break;
      }
      else if(type == 3)           
      {
        read_fstring(port, varname);
      }
      else                    
      {
        read_fvalue(port, varname);
      }
      pi = e_pos;
      ch = p_string[pi];
    }
  }
}
/*------- end get_finput ----------*/


void read_fstring(int port, char *varname)
{
  char chIn='\0', temp[BUFSIZE];
  int ii=0, ndx=0, indx=0, xsize;
  FILE *handle;

  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);       
  }
  handle = fp[port].fptr;
  while((chIn != '\"') && (!feof(handle)))
  {
    ii = fgetc(handle);
    chIn = (char) ii;
  }
  chIn = '\0';
  if(!feof(handle))
  {
    while((chIn != '\"') && (!feof(handle)))
    {
      ii = fgetc(handle);
      chIn = (char) ii;
      if(chIn != '\"')
      {
        temp[indx] = chIn;
        indx++;
      }
    }
  }
  temp[indx] = '\0';
  xsize = strlen(temp);
  xsize++;
  Gtbl[ndx].Str = realloc(Gtbl[ndx].Str, xsize * sizeof(char));
  strcpy(Gtbl[ndx].Str, temp);
}
/*------- end read_fstring ----------*/


void read_fvalue(int port, char *varname)
{   
  char chi='\0', temp[BUFSIZE];
  int pi, type, ii=0, ndx=0, indx=0;
  FILE *handle;

  pi = e_pos;
  type = get_Nvtype(pi);
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  handle = fp[port].fptr;
  while((isdigit(chi) == 0) && (!feof(handle)))
  {
    ii = fgetc(handle);       
    chi = (char) ii;
    if((chi == '-') || (chi == '.'))
    {
      temp[indx] = chi;
      indx++;
    }
  }
  while((isdigit(chi) != 0) || (chi == '.') && (!feof(handle)))
  {
    temp[indx] = chi;
    indx++;
    ii = fgetc(handle);
    chi = (char) ii;
  }
  temp[indx] = '\0';
  switch(type)
  {
    case 4:
      Gtbl[ndx].Dbl = (double) atof(temp);
      break;
    
    case 3:
      Gtbl[ndx].Flt = atof(temp);
      break;

    case 2:
      Gtbl[ndx].Lng = atol(temp);
      break;

    default:			     
      Gtbl[ndx].Int = atoi(temp);
      break;
  }
}
/*------- end read_fvalue ----------*/


void read_fline(int port, char *varname)
{
  char temp[BUFSIZE];
  int ndx, xsize;
  FILE *handle;

  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  temp[0] = '\0';
  handle = fp[port].fptr;
  if(!feof(handle))
  {
    fgets(temp, BUFSIZE, handle);
  }
  xsize = strlen(temp);
  xsize++;
  if(xsize > 2)
  {
    temp[(xsize-2)] = '\0';              
  }
  Gtbl[ndx].Str = realloc(Gtbl[ndx].Str, xsize * sizeof(char));
  strcpy(Gtbl[ndx].Str, temp);
}
/*------- end read_fline ----------*/


void print_io()
{   
  char ch, chmode, quote = '\"', nl='\n';
  char varname[VAR_NAME], temp[BUFSIZE];
  int pi, len, port, si, type, indx, nDims, offset;
  int maxfiles=(IOARRAY-1), x=line_ndx, ab_code=24;
  int *Subscripts;
  double file_no;
  FILE *handle;

  len = strlen(p_string);
  pi = e_pos;
  ch = p_string[pi];
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  err_hndlr(ab_code, x, 2, pi, len);    
  e_pos = pi;
  file_no = get_avalue();
  port = (int) file_no;
  port--;
  chmode = fp[port].mode;              
  err_hndlr(ab_code, x, 3, port, maxfiles); 
  err_hndlr(ab_code, x, 8, chmode, 0);  
  while(((isalpha(ch)== 0) && (ch != '\"')) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  e_pos = pi;
  ch = p_string[pi];
  if(ch == quote)							
  {
    pi++;
    ch = p_string[pi];
    si = 0;
    while((ch != quote) && (pi < len))
    {
      xstring[si] = ch;
      pi++;
      si++;
      ch = p_string[pi];
    }
    xstring[si] = '\0';
    strcpy(temp, xstring);
    handle = fp[port].fptr;
    fprintf(handle, "%s", temp);
  }
  else								
  {
    pi = e_pos;
    strcpy(varname, get_varname());
    type = get_objtype(pi);
    if(type == 0)
    {
      print_fstring(port,varname); 	
    }
    else if(type == 6)
    {
      indx = get_arrayndx(varname);	
      len = strlen(p_string);
      pi = e_pos;
      /* get_paren Start */
      ch = p_string[pi];
      while((strchr("()", ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_paren Stop */
      pi++;
      e_pos = pi;
      Subscripts = &strArry[indx].sub[0];  
      nDims = strArry[indx].dim;           
      offset = get_offset2(Subscripts, nDims, len);
      strcpy(temp, strArry[indx].elem[offset]);
      handle = fp[port].fptr;
      fprintf(handle, "%s", temp);
    }
  }
  handle = fp[port].fptr;
  fprintf(handle, "%c", nl);
}
/*------- end print_io ----------*/


void write_io()
{   
  char ch, chmode;
  int pi, len, port, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=24;
  double file_no;

  len = strlen(p_string);
  pi = e_pos;
  ch = p_string[pi];
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  err_hndlr(ab_code, x, 2, pi, len);     
  e_pos = pi;
  file_no = get_avalue();
  port = (int) file_no;
  port--;
  chmode = fp[port].mode;             
  err_hndlr(ab_code, x, 3, port, maxfiles);  
  err_hndlr(ab_code, x, 8, chmode, 0);  
  get_foutput(port, len, ch);
}
/*------- end write_io ----------*/


void get_foutput(int port, int len, char chx)
{   
  char ch, nl='\n', varname[VAR_NAME];
  int pi, type, wflag=0, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=24;
  FILE *handle;

  pi = e_pos;
  ch = p_string[pi];
  while((pi < len) && (ch != '\n'))	
  {
    if(isalpha(ch) == 0)
    {
      /* get_alpha Start */
      ch = p_string[pi];
      while((isalpha(ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_alpha Stop */
      ch = p_string[pi];
    }
    if(pi < len)
    {
      e_pos = pi;
      type = get_vtype(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(type == 3)			   				
      {
        wflag = write_fstring(wflag,port,varname);
      }
      else			  						
      {
        wflag = write_fvalue(wflag,port,varname);
      }
      pi = e_pos;
      ch = p_string[pi];
    }
  }
  handle = fp[port].fptr;
  fprintf(handle, "%c", nl);
}
/*------- end get_foutput ----------*/


int write_fstring(int wflag, int port, char *varname)
{
  char quote='\"', comma=',', temp[BUFSIZE];
  int ndx;
  FILE *handle;

  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  strcpy(temp, Gtbl[ndx].Str);
  handle = fp[port].fptr;
  if(wflag > 0)
  {
    fprintf(handle, "%c", comma);
  }
  fprintf(handle, "%c%s%c", quote, temp, quote);
  wflag++;
  return wflag;
}
/*------- end write_fstring ----------*/


int write_fvalue(int wflag, int port, char *varname)
{
  char ch, comma=',', temp[BUFSIZE];
  int pi, type, ndx=0, indx=0, len, idx;
  int ivalue;
  long lvalue;
  float fvalue;
  long double dvalue;
  FILE *handle;

  pi = e_pos;
  type = get_Nvtype(pi);
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);       
  }
  switch(type)
  {
    case 4:
      dvalue = Gtbl[ndx].Dbl;
      sprintf(temp, "%Lf", dvalue);    
      break;
    
    case 3:
      fvalue = Gtbl[ndx].Flt;
      sprintf(temp, "%f", fvalue);     
      break;
 
    case 2:
      lvalue = Gtbl[ndx].Lng;
      break;
     
    default:			     
      ivalue = Gtbl[ndx].Int;
      sprintf(temp, "%d", ivalue);     
      break;
  }
  len = strlen(temp);
  idx = (len-1);
  ch = temp[idx];
  if((type == 4) || (type == 3))
  {
    if(ch == '0')
    {
      while(ch == '0')
      {
        temp[idx] = '\0';
        idx--;
        ch = temp[idx];
        if(ch == '.')
        {
          temp[idx] = '\0';
        }
      }
    }
  }
  handle = fp[port].fptr;
  if(wflag > 0)
  {
    fprintf(handle, "%c", comma);
  }
  fprintf(handle, "%s", temp);
  wflag++;
  return wflag;
}
/*------- end write_fvalue ----------*/


void print_fstring(int port, char *varname)
{
  char temp[BUFSIZE];
  int ndx;
  FILE *handle;

  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);       
  }
  strcpy(temp, Gtbl[ndx].Str);
  handle = fp[port].fptr;
  fprintf(handle, "%s", temp);
}
/*------- end print_fstring ----------*/


void random_fio(int ndx, int len)
{   
  int pi, bffrlen;
  char ch;
  double dbuffer;
  unsigned size;

  pi = e_pos;
  /* get_alnum Start */
  ch = p_string[pi];
  while((isalnum(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  if(pi == len)
  {
    bffrlen = REC_LEN;
  }
  else
  {
    e_pos = pi;
    dbuffer = get_avalue();
    bffrlen = (int) dbuffer;
  }
  size = bffrlen;
  size++;                              
  fld_bffr[ndx].bfr_size = bffrlen;      
  fld_bffr[ndx].f_bffr = realloc(fld_bffr[ndx].f_bffr, size * sizeof(char));
  fld_bffr[ndx].f_bffr[0] = '\0';
  fld_bffr[ndx].record = 1;
  fld_bffr[ndx].flag = 0;
}
/*------ end random_fio -------*/


void do_field()
{
  int pi, ii, ndx, len, x=line_ndx, ab_code=25;
  int cnt=0, maxfiles=(IOARRAY-1);
  double file_no;
  char ch;

  len = strlen(p_string);      
  pi = e_pos;
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  err_hndlr(ab_code, x, 10, pi, len);       
  e_pos = pi;
  file_no = get_avalue();
  ndx = (int) file_no;
  ndx--;
  err_hndlr(ab_code, x, 3, ndx, maxfiles);  
  err_hndlr(ab_code, x, 9, ndx, 0);        
  cnt = fld_bffr[ndx].fld_count;    
  if(cnt > 0) 	      
  {
    free(fld_bffr[ndx].str_len);
    for(ii = 0; ii < cnt; ii++)
    {
      free(fld_bffr[ndx].str_name[ii]);
    }
    free(fld_bffr[ndx].str_name);
    fld_bffr[ndx].fld_count = 0;
    cnt = 0;
  }
  cnt_field(ndx, cnt, len);
}
/*------- end do_field ----------*/


void cnt_field(int ndx,int cnt,int len)
{
  char temp[VAR_NAME];
  int pi, ii, mark=1, x=line_ndx, ab_code=25;
  unsigned size;

  strcpy(temp, "AS");      
  s_pos = 1;                
  while(mark > 0)
  {
    mark = find_strng(temp);                  
    if(mark > 0)
    {
      cnt++;
      pi = mark;
      pi++;
      s_pos = pi;
    }
  }
  err_hndlr(ab_code, x, 10, cnt, 0);         
  size = cnt;                
  fld_bffr[ndx].fld_count = cnt;
  fld_bffr[ndx].str_len = malloc(size * sizeof(int));
  fld_bffr[ndx].str_name = malloc(size * sizeof(char *));
  for(ii = 0; ii < size; ii++)
  {
    fld_bffr[ndx].str_name[ii] = malloc(VAR_NAME * sizeof(char));
    fld_bffr[ndx].str_name[ii][0] = '\0';
  }
  asn_field(ndx, len);
}
/*------- end cnt_field ----------*/


void asn_field(int ndx,int len)
{
  char ch, temp[VAR_NAME];
  int pi, ii, cnt, fld_len, str_ndx, x=line_ndx, ab_code=25;
  double dvalue;
    
  pi = 0;
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  pi = while_isalnum(pi);
  ch = p_string[pi];
  cnt = 0;
  while(pi < len)
  {
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_digit Stop */
    ch = p_string[pi];
    if(pi == len)
    {
      break;
    }
    else if(isdigit(ch))
    {
      e_pos = pi;
      dvalue = get_avalue();
      str_ndx = (int) dvalue;
      err_hndlr(ab_code, x, 11, str_ndx, 1);  
      fld_bffr[ndx].str_len[cnt] = str_ndx;
      pi = e_pos;
      pi = iswhite(pi);
      pi += 2;
      /* get_alpha Start */
      ch = p_string[pi];
      while((isalpha(ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_alpha Stop */
      ch = p_string[pi];
      ii = 0;
      while(isalnum(ch) != 0)
      {
        temp[ii] = ch;
        ii++;
        pi++;
        ch = p_string[pi];
      }
      temp[ii] = '\0';
      strcpy(fld_bffr[ndx].str_name[cnt], temp);
      cnt++;
    }
    else
    {
      err_hndlr(ab_code, x, 11, 0, 1);   
    }
  }
  cnt = fld_bffr[ndx].fld_count;
  len = 0;
  for(ii=0; ii< cnt; ii++)
  {
    len += fld_bffr[ndx].str_len[ii];
  }
  fld_len = fld_bffr[ndx].bfr_size;
  err_hndlr(ab_code, x, 12, len, fld_len); 
}
/*------- end asn_field ----------*/


void do_lset()
{   
  char *temp;
  int ii, len, fld_len, ndx, indx, cnt, ab_code=26;
  unsigned size;

  parse_let();               
  get_ndxcnt(ab_code);        
  ndx = lrs.ndx;              
  cnt = lrs.cnt;
  fld_len = fld_bffr[ndx].str_len[cnt];
  size = (fld_len+1);
  temp = malloc(size * sizeof(char));
  indx = lset_ndx;
  len = strlen(Gtbl[indx].Str);
  if(len > fld_len)
  {
    for(ii=0; ii < fld_len; ii++)
    {
      temp[ii] = Gtbl[indx].Str[ii];
    }
    temp[ii] = '\0';
  }
  else
  {
    strcpy(temp, Gtbl[indx].Str);
  }
  Gtbl[indx].Str = realloc(Gtbl[indx].Str, size * sizeof(char));
  strcpy(Gtbl[indx].Str, temp);
  free(temp);
  if(fld_len > len)		     
  {
    for(ii=len; ii < fld_len; ii++)
    {
      Gtbl[indx].Str[ii] = ' ';                
    }
    Gtbl[indx].Str[ii] = '\0';
  }
}
/*------- end do_lset ----------*/


void do_rset()
{   
  char *temp;
  int ii, len, fld_len, pad, ndx, indx, cnt, ab_code=27;
  unsigned size;

  parse_let();                
  get_ndxcnt(ab_code);        
  ndx = lrs.ndx;              
  cnt = lrs.cnt;
  fld_len = fld_bffr[ndx].str_len[cnt];
  size = (fld_len+1);
  temp = malloc(size * sizeof(char));
  indx = lset_ndx;
  len = strlen(Gtbl[indx].Str);
  if(len > fld_len)
  {
    for(ii=0; ii < fld_len; ii++)
    {
      temp[ii] = Gtbl[indx].Str[ii];
    }
    temp[ii] = '\0';
  }
  else
  {
    pad = (fld_len - len);                
    for(ii=0; ii < pad; ii++)           
    {
      temp[ii] = ' ';
    }
    temp[ii] = '\0';
    strcat(temp, Gtbl[indx].Str);
  }
  Gtbl[indx].Str = realloc(Gtbl[indx].Str, size * sizeof(char));
  strcpy(Gtbl[indx].Str, temp);
  free(temp);
}
/*------- end do_rset ----------*/


void get_ndxcnt(int xcode)
{   
  char *stack, *buffer;
  int ii, fld_len, x=line_ndx, ab_code=xcode;
  int test=0, ndx=0, indx, cnt=0;

  indx = lset_ndx;
  stack = Gtbl[indx].Nam;
  while((test == 0) && (ndx < IOARRAY))
  {
    if(fp[ndx].mode == 'R')
    {
      fld_len = fld_bffr[ndx].fld_count;
      for(ii=0; ii < fld_len; ii++)
      {
        buffer = fld_bffr[ndx].str_name[ii];
        if(strcmp(stack, buffer) == 0)
        {
          test = 1;         
          cnt = ii;
          ii = fld_len;
        }
      }
      if(test == 0)
      {
  	 ndx++;
      }
    }
    else
    {
      ndx++;
    }
  }
  err_hndlr(ab_code, x, 13, test, ndx);   
  lrs.ndx = ndx;                    
  lrs.cnt = cnt;
  fld_bffr[ndx].flag++;             
}
/*------- end get_ndxcnt ----------*/


void do_put()
{   
  int len, pi, ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=28;
  double file_no;
  char ch;

  len = strlen(p_string);      
  pi = e_pos;  
  /* get_digit Start */
  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_digit Stop */
  e_pos = pi;                  
  file_no = get_avalue();       
  ndx = (int) file_no;
  ndx--;
  err_hndlr(ab_code, x, 3, ndx, maxfiles);  
  err_hndlr(ab_code, x, 9, ndx, 0);        
  lod_bffr(ndx,len);
}
/*------- end do_put ----------*/


void lod_bffr(int ndx, int len)
{   char temp[VAR_NAME], ch;
    int pi, ii=0, indx=0, cnt, bfr_len;
    long fil_rcrd, tmp_rcrd;
    double this_rcrd;
    FILE *handle;


    if(fld_bffr[ndx].flag == 0) 	     
    {
        bfr_len = fld_bffr[ndx].bfr_size;
        memset(fld_bffr[ndx].f_bffr, 32, bfr_len);  
        fld_bffr[ndx].f_bffr[bfr_len] = '\0';
    }
    else
    {
        cnt = fld_bffr[ndx].fld_count;    
        fld_bffr[ndx].f_bffr[0] = '\0';

        for(; ii < cnt; ii++)
        {
            indx = 0;
            strcpy(temp, fld_bffr[ndx].str_name[ii]);

        while((ndx < glb_vct) && (strcmp(Gtbl[indx].Nam, temp) != 0))
            {
                indx++;
            }
            strcat(fld_bffr[ndx].f_bffr, Gtbl[indx].Str);
        }
    }

    pi = e_pos;
    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_alnum Stop */
    if(pi < len)                    
    {
        e_pos = pi;
        this_rcrd = get_avalue();
        fil_rcrd = (long) this_rcrd;
    }
    else                           
    {
        fil_rcrd = fld_bffr[ndx].record;
    }

    tmp_rcrd = fil_rcrd;                    
    handle = fp[ndx].fptr;
    bfr_len = fld_bffr[ndx].bfr_size;

    fil_rcrd--;                            
    fil_rcrd = (fil_rcrd * bfr_len);    

    fseek(handle, fil_rcrd, SEEK_SET);            
    fputs(fld_bffr[ndx].f_bffr, handle);       

    tmp_rcrd++;                            
    fld_bffr[ndx].record = tmp_rcrd;       
    /**/
    fld_bffr[ndx].flag = 0;               
}
/*------- end lod_bffr ----------*/



void do_get()
{   int len, pi, ndx;
    int maxfiles=(IOARRAY-1), x=line_ndx, ab_code=29;
    double file_no;
    char ch;


    len = strlen(p_string);            
    pi = e_pos; 
    /* get_digit Start */
    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_digit Stop */
    e_pos = pi;                      

    file_no = get_avalue();           
    ndx = (int) file_no;
    ndx--;

    err_hndlr(ab_code, x, 3, ndx, maxfiles);  
    err_hndlr(ab_code, x, 9, ndx, 0);       

    fil_bffr(ndx,len);
}
/*------- end do_get ----------*/



void fil_bffr(int ndx, int len)
{   char varname[VAR_NAME], ch;
    int pi, ii, indx, ndxb, cnt, bfr_len;
    long fil_rcrd, tmp_rcrd;
    unsigned size;
    double this_rcrd;
    FILE *handle;


    pi = e_pos;
    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_alnum Stop */
    e_pos = pi;

    if(pi < len)		    
    {
        e_pos = pi;
        this_rcrd = get_avalue();
        fil_rcrd = (long) this_rcrd;
    }
    else				
    {
        fil_rcrd = fld_bffr[ndx].record;
    }

    tmp_rcrd = fil_rcrd;                   
    /*-------------------*/

    handle = fp[ndx].fptr;
    bfr_len = fld_bffr[ndx].bfr_size;

    fil_rcrd--;                            
    fil_rcrd = (fil_rcrd * bfr_len);    
    fseek(handle, fil_rcrd, SEEK_SET);            

    bfr_len++;                        
    fgets(fld_bffr[ndx].f_bffr, bfr_len, handle);
    /*-------------------*/

    tmp_rcrd++;                           
    fld_bffr[ndx].record = tmp_rcrd;       
    cnt = fld_bffr[ndx].fld_count;       
    size = 1;
    ndxb = 0;

    /* --- copy from buffer to strings --- */
    for(ii=0; ii < cnt; ii++)
    {
        indx = 0;
        size = fld_bffr[ndx].str_len[ii];
        strcpy(varname, fld_bffr[ndx].str_name[ii]);

        if(callFlag == 0)
        {
            indx = get_vndx(varname);
        }
        else
        {
            indx = get_llvarndx(varname);        
        }

        strcpy(Gtbl[indx].Nam, varname);      
        Gtbl[indx].Str = realloc(Gtbl[indx].Str, size * sizeof(char));

        /* --- move (size) chars to string --- */
        for(pi=0; pi < size; pi++)
        {
            Gtbl[indx].Str[pi] = fld_bffr[ndx].f_bffr[ndxb];
            ndxb++;
        }
        Gtbl[indx].Str[pi] = '\0';
    }
}
/*------- end fil_bffr ----------*/



void do_kill()
{
    get_pnam();    

    remove(s_holder);

}
/*---------- end do_kill ----------*/


/* bxbasic : Getinput.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011            */
/* Modified T. Chandler CMSBASIC getinput.c    */

void get_lninput()
{   
   char ch, varname[VAR_NAME];
   int pi, loc=0;

   pi = e_pos;
   ch = p_string[pi];
   if(ch == '#')
   {
      p_string[pi] = '@';
      input_io();
      return;
   }
   else if(ch == ';')		
   {
      loc = 1;
      pi++;
      pi = iswhite(pi);
      ch = p_string[pi];
      e_pos = pi;
   }

   if(ch == '\"')          	
   {
      get_prnstring();
      pi = e_pos;
      pi++;
      pi = iswhite(pi);
      ch = p_string[pi];
      e_pos = pi;
   }
   /* --- input string --- */
   strcpy(varname, get_varname());
   input_str(varname,loc);
}
/*---------- end get_lninput ----------*/



void get_input()
{   
   char ch, varname[VAR_NAME];
   int pi, len, type, loc=0;
   int ab_code=19, x=line_ndx;

   pi = e_pos;
   ch = p_string[pi];
   if(ch == '#')                  
   {
      input_io();
      return;
   }
   else if(ch == ';')		
   {
      loc = 1;
      pi++;
      pi = iswhite(pi);
      ch = p_string[pi];
      e_pos = pi;
   }
   len = strlen(p_string);
   while(pi < len)                       
   {
      if(ch == '\"')          	
      {
         get_prnstring();
         pi = e_pos;
         pi++;
         pi = iswhite(pi);
         ch = p_string[pi];
         e_pos = pi;
      }
      /* --- a string$ or numeric variable --- */
      else if(isalpha(ch))
      {
         type = get_vtype(pi);
         strcpy(varname, get_varname());
         if(type == 3)       	
         {
            input_str(varname,loc);
            pi = e_pos;
            ch = p_string[pi];
         }
         else  		 
         {
            input_val(varname,loc);
            pi = e_pos;
            ch = p_string[pi];
         }
      }
      else
      {   
         a_bort(ab_code, x);
      }
   }
}
/*---------- end get_input ----------*/



void input_val(char *varname, int loc)
{   
   char ch, string[VAR_NAME];
   int pi, ndx, len, row, col;

   pi = e_pos;
   ch = p_string[pi];
   /* --- get cursor --- */
   switch(loc)
   {
      case 1:			/* --- get data-input --- */
        gets(string);
        len = strlen(string);
        break;

      default:
        gets(string);
        break;
  }

  switch(ch)
  {
      case '#':		/* --- double --- */		
        if(callFlag == 0)
        {
           ndx = get_vndx(varname);
        }
        else
        {
           ndx = get_llvarndx(varname);        
        }
        Gtbl[ndx].Dbl = (double) atof(string);
        pi++;
        break;
        
      case '!':		/* --- float --- */
        if(callFlag == 0)
        {
           ndx = get_vndx(varname);
        }
        else
        {
           ndx = get_llvarndx(varname);        
        }
        Gtbl[ndx].Flt = (float) atof(string);
        pi++;
        break;
        
      case '%':		/* --- long --- */
        if(callFlag == 0)
        {
           ndx = get_vndx(varname);
        }
        else
        {
           ndx = get_llvarndx(varname);        
        }
        Gtbl[ndx].Lng = atol(string);
        pi++;
        break;
        
      default:		/* --- integer --- */
        if(callFlag == 0)
        {
           ndx = get_vndx(varname);
        }
        else
        {
           ndx = get_llvarndx(varname);        
        }
        Gtbl[ndx].Int = atoi(string);
        break;
  }

  pi = iswhite(pi);
  ch = p_string[pi];
  if(strchr(":;,", ch))
  {
     pi++;
     set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
}
/*---------- end input_val ----------*/



void input_str(char *varname, int loc)
{   
   char ch, string[BUFSIZE];
   int pi, ndx, len, row, col;
   unsigned xsize;

   if(callFlag == 0)
   {
      ndx = get_vndx(varname);
   }
   else
   {
      ndx = get_llvarndx(varname);        
   }
   /* --- get cursor --- */
   switch(loc)
   {
      case 1:		/* --- get data-input --- */
        gets(string);
        len = strlen(string);
        break;
   
      default:
        gets(string);
        break;
  }

  /* --- store data --- */
  xsize = strlen(string);
  xsize++;
  Gtbl[ndx].Str = realloc(Gtbl[ndx].Str, xsize * sizeof(char));
  strcpy(Gtbl[ndx].Str, string);
  pi = e_pos;
  pi++;
  ch = p_string[pi];
  if(strchr(":;,", ch))
  {
     pi++;
     set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
}
/*---------- end input_str ----------*/


/* cmsbasic : Ifendif.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011            */
/* Modified T. Chandler CMSBASIC CMSBIF.c      */


void do_Switch()
{    
   int pi;

   pi = 0;
   pi = iswhite(pi);             
   e_pos = pi;
   iswitch = (int) get_avalue();  
   sw_flag++;                     
}
/*------- end do_Switch ----------*/


void do_Case()
{
   int ibool, case_ndx, endsw_ndx;
   int ab_code = 37, x = line_ndx;

   if(sw_flag <= 0)
   {
      a_bort(ab_code, x);
   }
   ibool = sw_boolexpres();
   /* --- now take action --- */
   if(ibool == 1)
   {
      case_ndx = find_case(line_ndx);   
      endsw_ndx = find_sw(line_ndx);  
      line_ndx++;			 
      while(line_ndx != case_ndx)
      {
         s_pos = 0;
         e_pos = 0;
         strcpy(p_string, array1[line_ndx]);
         token = byte_array[line_ndx];
         if(token == 5)
         {
            break;
         }
         parser();
         line_ndx++;
      }
      if(token == 5)
      {
         line_ndx--;
         return;
      }
      sw_flag--;                    
      line_ndx = endsw_ndx;          
   }
   else
   {
      case_ndx = find_case(line_ndx);     
      case_ndx--;
      line_ndx = case_ndx;
   }
}
/*------- end do_Case ----------*/


int find_case(int ndx)
{   
   int tok=0;

   while((tok != 32) && (tok != 33) && (tok != 34))
   {
      ndx++;			    
      tok = byte_array[ndx];
      if(tok == 31)
      {
        ndx = find_sw(ndx); 	
      }
   }
   return ndx;
}
/*------- end find_case -------*/


int find_sw(int ndx)
{   
   int tok=0;

   while(tok != 34)  		
   {
     ndx++;
     tok = byte_array[ndx];
     if(tok == 31)
     {
       ndx = find_sw(ndx);
     }
   }
   return ndx;
}
/*------- end find_endsw -------*/


int sw_boolexpres()
{   
   int ibool=0, pi;
   int rvalue;

   pi = 0;
   pi = iswhite(pi);              
   e_pos = pi;
   rvalue = (int) get_avalue();   
   if(iswitch == rvalue)
   {
     ibool = 1;
   }
   return ibool;
}
/*------- end sw_boolexpres -------*/


void do_if()
{   
   int ibool, els_ndx, end_ndx;

   ibool = boolexpress();
   /* --- now take action --- */
   if(ibool == 1)
   {
      els_ndx = find_else(line_ndx);   
      end_ndx = find_if(line_ndx);  
      line_ndx++;			
      while(line_ndx != els_ndx)
      {
        s_pos = 0;
        e_pos = 0;
        strcpy(p_string, array1[line_ndx]);
        token = byte_array[line_ndx];
        if(token == 5)
        {
           break;
        }
        parser();
        line_ndx++;
      }
      if(token == 5)
      {
        line_ndx--;
        return;
      }
      line_ndx = end_ndx;
   }
   else
   {
      els_ndx = find_else(line_ndx);     
      els_ndx--;
      line_ndx = els_ndx;
   }
}
/*------- end do_if ----------*/


int find_else(int ndx)
{   
   int tok=0;

   while((tok != 14) && (tok != 15) && (tok != 16))
   {
     ndx++;                      
     tok = byte_array[ndx];
     if(tok == 13)
     {
       ndx = find_if(ndx);  
     }
   }
   return ndx;
}
/*------- end find_else -------*/


int find_if(int ndx)
{   
   int tok=0;

   while(tok != 16)  		
   {
     ndx++;
     tok = byte_array[ndx];
     if(tok == 13)
     {
       ndx = find_if(ndx);
     }
   }
   return ndx;
}
/*------- end find_endif -------*/


int boolexpress()
{   
   int ibool, type, a_bool, or_bool, op;
   int ab_code=17, x=line_ndx;

   type = get_type();		
   switch(type)
   {
      case 1:
      case 2:
        ibool = Nboolterm(type);        
        break;
   
      case 3:
      case 4:
        ibool = Sboolterm(type);       
        break;
  
      case 5:
        ibool = is_eof();               
        if(ibool != 0)
        {
           ibool = 1;
        }
        break;
        
      default:
        a_bort(ab_code,x);
        break;
  }

  /* --- process AND / OR --- */
  op = IsAndOrOp();
  while(op != 0)
  {
    if(op == 1)
    {
      a_bool = AndOrBoolExp();		
      if((ibool == 1) && (a_bool == 1))
      {
         ibool = 1;
      }
      else
      {
         ibool = 0;
      }
    }
    else if(op == 2)
    {
       or_bool = AndOrBoolExp();		
       if((ibool == 1) || (or_bool == 1))
       {
          ibool = 1;
       }
    }
    op = IsAndOrOp();
  }
  return ibool;
}
/*------- end boolexpress --------*/


int AndOrBoolExp()
{   
   int ibool, type;
   int ab_code=17, x=line_ndx;

   type = get_type();		
   switch(type)
   {
     case 1:
     case 2:
       ibool = Nboolterm(type);        
       break;
    
     case 3:
     case 4:
       ibool = Sboolterm(type);      
       break;
 
     default:
       a_bort(ab_code,x);
       break;
  }
  return ibool;
}
/*------- end AndOrBoolExp --------*/


int Nboolterm(int type)
{
   int ibool;
   double lvalue;

   if(type == 1)
   {
     lvalue = get_avalue();	     
   }
   else
   {
     lvalue = rdp_main();	    
   }
   ibool = Nrelation(lvalue);
   return ibool;
}
/*------- end Nboolterm --------*/


int Nrelation(double lvalue)
{
   int ibool, op, type;
   int ab_code=17, x=line_ndx;
   double rvalue;

   op = get_op();			
   type = get_type();			
   switch(type)
   {
     case 1:
       rvalue = get_avalue();   
       break;

     case 2:
       rvalue = rdp_main();    
       break;

     default:
       a_bort(ab_code,x);
       break;
  }
  ibool = eval_value(lvalue, rvalue, op);  
  return ibool;
}
/*------- end Nrelation --------*/


int eval_value(double lval,double rval,int op)
{
   int ibool=0;

   switch(op)
   {
     case 1:
       if(lval == rval)
       {
          ibool = 1;
       }
       break;
       
     case 2:
       if(lval < rval)
       {
          ibool = 1;
       }
       break;
       
     case 3:
       if(lval > rval)
       {
          ibool = 1;
       }
       break;
       
     case 4:
       if(lval <= rval)
       {
          ibool = 1;
       }
       break;
       
     case 5:
       if(lval >= rval)
       {
          ibool = 1;
       }
       break;
       
     case 6:
       if(lval != rval)
       {
          ibool = 1;
       }
       break;
       
     default:
       break;
  }
  return ibool;
}
/*------- end eval_value -------*/


int Sboolterm(int type)
{
   char lstring[BUFSIZE];
   int ibool, ndx;

   if(type == 3)
   {
      ndx = get_string();		
      strcpy(lstring, Gtbl[ndx].Str);
   }
   else
   {
      get_qstring();			
      strcpy(lstring, s_holder);
   }
   ibool = Srelation(lstring);
   return ibool;
}
/*------- end Sboolterm --------*/


int Srelation(char *lstring)
{
   char rstring[BUFSIZE];
   int ibool, ndx, op, type;
   int ab_code=17, x=line_ndx;

   op = get_op();			
   type = get_type();			
   switch(type)
   {
     case 3:
       ndx = get_string();	        
       strcpy(rstring, Gtbl[ndx].Str);
       break;

     case 4:
       get_qstring();              
       strcpy(rstring, s_holder);
       break;

     default:
       a_bort(ab_code,x);
       break;
  }
  ibool = eval_string(lstring, rstring, op);
  return ibool;
}
/*------- end Srelation --------*/


int eval_string(char *lstr,char *rstr,int op)
{   
   int ibool=0, comp;

   comp = strcmp(lstr, rstr);
   /* --- now test expression --- */
   switch(op)
   {
      case 1:
        if(comp == 0)
        {
           ibool = 1;
        }
        break;
        
      case 2:
        if(comp < 0)
        {
           ibool = 1;
        }
        break;
        
      case 3:
        if(comp > 0)
        {
           ibool = 1;
        }
        break;
     
      case 4:
        if(comp <= 0)
        {
           ibool = 1;
        }
        break;
        
      case 5:
        if(comp >= 0)
        {
           ibool = 1;
        }
        break;
        
      case 6:
        if(comp != 0)
        {
           ibool = 1;
        }
        break;
        
      default:
        break;
  }
  return ibool;
}
/*------- end eval_string -------*/


int IsAndOrOp()
{   
   char ch;
   int pi, op=0;

   pi = e_pos;
   pi = iswhiter(pi);
   ch = p_string[pi];
   if(ch == '&')
   {
      op = 1;
      pi++;
      pi = iswhiter(pi);
   }
   else if(ch == '|')
   {
      op = 2;
      pi++;
      pi = iswhiter(pi);
   }
   e_pos = pi;
   return op;
}
/*------- end IsAndOrOp --------*/


int get_type()
{
   char ch;
   int pi, type=0;

   pi = e_pos;
   pi = iswhiter(pi);
   ch = p_string[pi];
   if(isalpha(ch))
   {
      s_pos = pi;
      type = get_vtype(pi);          
   }
   else if(isdigit(ch))
   {
      type = 1;                      
   }
   else if(ch == '(')
   {
      type = 2;                      
   }
   else if(ch == '\"')
   {
      type = 4;                      
   }
   else if(ch == '\?')
   {
      type = 5;                      
      pi = pi + 3;
   }
   e_pos = pi;
   return type;
}
/*------- end get_type ---------*/


int get_string()
{   
   char varname[VAR_NAME];
   int pi, ndx;

   strcpy(varname, get_varname());    
   /* --- get stack index --- */
   ndx = 0;
   if(callFlag == 0)
   {
      ndx = get_vndx(varname);         
   }
   else
   {
      ndx = get_llvarndx(varname);        
   }
   pi = e_pos;
   pi++;
   pi = iswhiter(pi);
   e_pos = pi;
   return ndx;
}
/*------- end get_string -------*/


void get_qstring()
{   
   char ch, quote='\"';
   int pi, si=0, stlen, ab_code=6, x=line_ndx;

   stlen = strlen(p_string);
   pi = e_pos;                        
   pi++;
   ch = p_string[pi];
   /* --- we now have first character --- */
   /* --- fill buffer with string --- */
   si = 0;
   while((ch != quote) && (pi < stlen))
   {
      s_holder[si] = ch;
      si++;
      pi++;
      ch = p_string[pi];
   }
   s_holder[si] = '\0';
   if(pi == stlen)                
   {
      a_bort(ab_code,x);
   }
   pi++;
   e_pos = pi;
}
/*------- end get_qstring -------*/


int get_op()
{
   char ch;
   int pi, op, ab_code=18, x=line_ndx;

   pi = e_pos;
   ch = p_string[pi];
   if(strchr("\"$%!#", ch))
   {
      pi++;			
   }
   pi = iswhite(pi);
   ch = p_string[pi];
   switch(ch)
   {
      case '=':
        op = 1;             
        break;

      case '<':
        pi++;
        ch = p_string[pi];
        if(ch == '>')
        {
           op = 6;         
        }
        else if(ch == '=')
        {
           op = 4;		
        }
        else
        {
           op = 2;		
        }
        break;
        
      case '>':
        pi++;
        ch = p_string[pi];
        if(ch == '=')
        {
           op = 5;         
        }
        else
        {
           op = 3;         
        }
        break;
        
      default:
        a_bort(ab_code,x);
        break;
  }
  if(strchr("=>", ch))
  {
     pi++;
  }
  e_pos = pi;
  return op;
}
/*------- end get_op -------*/


int if_eof()
{
   char tmp[4];
   int flag=0;

   strcpy(tmp, "EOF");       
   flag = find_strng(tmp);   
   return flag;
}
/*-------- end if_eof ---------*/


int is_eof()
{   
   int pi, len, ibool, port, maxfiles=(IOARRAY-1);
   int x=line_ndx, ab_code=23;
   double file_no;
   char ch;
   FILE *handle;

   len = strlen(p_string);
   pi = e_pos; 
   /* get_digit Start */
   ch = p_string[pi];
   while((isdigit(ch) == 0) && (pi < len))
   {
      pi++;
      ch = p_string[pi];
   }
   e_pos = pi;
   /* get_digit Stop */
   file_no = get_avalue();
   port = (int) file_no;
   port--;
   err_hndlr(ab_code, x, 3, port, maxfiles);   
   err_hndlr(ab_code, x, 9, port, 0);         
   handle = fp[port].fptr;
   ibool = feof(handle);
   return ibool;
}
/*------- end is_eof ----------*/

/* bxbasic : input.c : alpha version.20.3.1  */
/* Copyright:(c) sarbayo, 2001-2011          */
/* Modified T. Chandler MUSBASIC - MUSBINP.c */


void line_cnt(char *argv[])
{   
   int pi, len, ii=0, x=0;
   int ab_code=2;
   unsigned fnam_len;

   nrows = 0;
   strcpy(s_holder, prog_name);
   strcpy(t_holder, prog_name);

   f_in = fopen(prog_name,"r");
   if(f_in == NULL)                
   {
      a_bort(ab_code, x);
   }
   else
   {
      load_src();            
      loader_1();            
      loader_2();           
   }
}
/*------- end line_cnt ----------*/

void load_src()
{   
   char *tmp="source.tmp";
   int pi, len;
   char ch;
    
   f_out = fopen(tmp,"w");                      
   while(fgets(p_string, BUFSIZE, f_in) != NULL)
   {
     pi = 0;
     pi = iswhite(pi);
     len = strlen(p_string);
     if((len > 2) && (pi < len))              
     {
       if(!feof(f_in))
       {   
         strcpy(xstring, "  ");
         strcat(xstring, p_string);
         pi = 0;
         ch = p_string[pi];
         /* --- test for a Label: --- */
         if(isupper(ch) != 0)
         {
           len = (LLEN-2);
           pi = while_isalnum(pi);                  
           ch = p_string[pi];
           if((ch == ':') && (pi <= len))
           {
             pi++;
             p_string[pi] = '\0';
             strcat(p_string, "\n\0");
             fprintf(f_out,"%s", p_string);       
             nrows++;
           }
           else
           {
             fprintf(f_out,"%s", xstring);        
             nrows++;
           }
         }
/* --- test for numbered line --- */
         else if(isdigit(ch))
         {
           fprintf(f_out,"%s", p_string);           
           nrows++;
         }
         else
         {
            pi = iswhite(pi);
            ch = p_string[pi];
            if(ch != '\'')                           
            {
              fprintf(f_out,"%s", xstring);        
              nrows++;
            }
          }
        }
      }
   }
   fclose(f_in);
   fclose(f_out);
}
/*------- end load_src ----------*/

void loader_1()
{   
   char ch;
   char *tmp="source.tmp";
   int ii, len, pi;
   unsigned size=ncolumns;

   /* --- create temp arrays --- */
   temp_prog = malloc(nrows * sizeof(char *));
   for(ii = 0; ii < nrows; ii++)
   {
      temp_prog[ii] = malloc(size * sizeof(char));
   }
   temp_label = malloc(nrows * sizeof(char *));

   for(ii = 0; ii < nrows; ii++)
   {
      temp_label[ii] = malloc(LLEN * sizeof(char));
   }
   temp_byte = malloc(nrows * sizeof(int));

   /* --- open source.tmp for Read --- */
   f_in = fopen(tmp,"r");
   ii = 0;
   while(fgets(p_string, BUFSIZE, f_in) != NULL)                      
   {
     if(!feof(f_in))
     {
       len = strlen(p_string);
       /* ----- fill temp_label[] here ----- */
       tmp_label(ii);                      
       pi = e_pos;
       ch = p_string[pi];
       if(ch == ':')                       
       {
         temp_byte[ii] = -1;
         strcpy(temp_prog[ii], "\n\0");
       }
       /* ----- fill temp_byte[] here ----- */
       else
       {
          tmp_byte(ii);                    
          tmp_prog(ii);
       }
     }
     ii++;
  }
  fclose(f_in);
}
/*---------- end loader_1 ----------*/


void tmp_label(int ii)
{
   char ch, ln_label[LLEN];
   int pi;

   /* ----- fill temp_label[] here ----- */
   pi = 0;
   ch = p_string[pi];
   if(isalnum(ch))
   {
     while(isalnum(ch))
     {
       ln_label[pi] = ch;
        pi++;
        ch = p_string[pi];
     }
     ln_label[pi] = '\0';
     strcpy(temp_label[ii], ln_label);
  }
  else
  {
     strcpy(temp_label[ii], " \0");
  }
  e_pos = pi;
}
/*---------- end tmp_label ----------*/



void get_MOD(int pi)
{   
   char ch, temp[VAR_NAME];
   int i, si=0, xi, len;

   len = strlen(p_string);
   xi = pi;
   pi = get_quote(pi, len);           
   if(pi < len)
   {
      return;                                  
   }
   else
   {
      pi = xi;
   }
   pi++;
   pi = iswhite(pi);
   ch = p_string[pi];
   while( pi < (len - 2))
   {
     if((ch == 'F') && (p_string[pi+1] == 'M'))
     {                                        
       pi = pi + 2;
       ch = p_string[pi];
     }
     if(ch == 'M')
     {
       if(p_string[pi+3] == 'F')
       {
         pi = pi + 2;
         ch = p_string[pi];
       }
     }
     if(ch == 'M')                            
     {
       si = pi;
       i = 0;
       while(isalnum(ch))
       {
         temp[i] = ch;
         pi++;
         i++;
         ch = p_string[pi];
       }
       temp[i] = '\0';
       if(strcmp(temp, "MOD") == 0)         
       {
         p_string[si] = '%';
         si++;
         xi = si;                         
         while(pi < len)                  
         {
            p_string[si] = p_string[pi];
            pi++;
            si++;
         }
         p_string[si] = '\0';
         pi = xi;                         
       }
       pi++;
     }
     else
     {
        pi++;
     }
     ch = p_string[pi];
  }
}
/*---------- end get_MOD ----------*/


int get_byte(int ii)
{   
   char ch, keyword[TOKEN_LEN];
   int pi, si=0, pii, byte;
   int x=ii, ab_code=4;

   pi = e_pos;
   ch = p_string[pi];
   while(isalnum(ch))
   {
      keyword[si] = ch;
      si++;
      pi++;
      ch = p_string[pi];
   }
   keyword[si] = '\0';
   /* --- assign byte code --- */
   if(strcmp(keyword, "REM") == 0)            byte=0;
   else if(strcmp(keyword, "LET") == 0)
   {			   byte=1;
      get_MOD(pi);    /* scan for a MOD expression */
   }
   else if(strcmp(keyword, "CLEAR") == 0)     byte=2;
   else if(strcmp(keyword, "LOCATE") == 0)    byte=3;
   else if(strcmp(keyword, "PRINT") == 0)     byte=4;
   else if(strcmp(keyword, "GOTO") == 0)      byte=5;
   else if(strcmp(keyword, "BEEP") == 0)      byte=6;
   else if(strcmp(keyword, "CLS") == 0)       byte=7;
   else if(strcmp(keyword, "END") == 0)       byte=8;
   else if(strcmp(keyword, "GOSUB") == 0)     byte=9;
   else if(strcmp(keyword, "RETURN") == 0)    byte=10;
   else if(strcmp(keyword, "FOR") == 0)       byte=11;
   else if(strcmp(keyword, "NEXT") == 0)      byte=12;
   else if(strcmp(keyword, "IF") == 0)        byte=13;
   else if(strcmp(keyword, "ELSEIF") == 0)    byte=14;
   else if(strcmp(keyword, "ELSE") == 0)      byte=15;
   else if(strcmp(keyword, "ENDIF") == 0)     byte=16;
   else if(strcmp(keyword, "INPUT") == 0)     byte=17;
   else if(strcmp(keyword, "LINE") == 0)
   {
     pii = pi;
     pii = iswhite(pii);
     ch = p_string[pii];
     if(ch == 'I')                          byte=18;
     else                                   byte=58;
  }
  else if(strcmp(keyword, "OPEN") == 0)      byte=19;
  else if(strcmp(keyword, "CLOSE") == 0)     byte=20;
  else if(strcmp(keyword, "WRITE") == 0)     byte=21;
  else if(strcmp(keyword, "FIELD") == 0)     byte=22;
  else if(strcmp(keyword, "LSET") == 0)      byte=23;
  else if(strcmp(keyword, "RSET") == 0)      byte=24;
  else if(strcmp(keyword, "PUT") == 0)       byte=25;
  else if(strcmp(keyword, "GET") == 0)       byte=26;
  else if(strcmp(keyword, "WHILE") == 0)     byte=27;
  else if(strcmp(keyword, "WEND") == 0)      byte=28;
  else if(strcmp(keyword, "DO") == 0)        byte=29;
  else if(strcmp(keyword, "REDIM") == 0)     byte=30;
  else if(strcmp(keyword, "SWITCH") == 0)    byte=31;
  else if(strcmp(keyword, "CASE") == 0)      byte=32;
  else if(strcmp(keyword, "DEFAULT") == 0)   byte=33;
  else if(strcmp(keyword, "ENDSWITCH") == 0) byte=34;
  else if(strcmp(keyword, "DIM") == 0)       byte=35;
  else if(strcmp(keyword, "DECLARE") == 0)   byte=36;
  else if(strcmp(keyword, "CALL") == 0)      byte=37;
  else if(strcmp(keyword, "SUB") == 0)       byte=38;
  else if(strcmp(keyword, "ENDSUB") == 0)    byte=39;
  else if(strcmp(keyword, "STOP") == 0)      byte=40;
  else if(strcmp(keyword, "SYSTEM") == 0)    byte=41;
  else if(strcmp(keyword, "ERASE") == 0)     byte=43;
  else if(strcmp(keyword, "RANDOM") == 0)    byte=44;
  else if(strcmp(keyword, "KILL") == 0)      byte=45;
  else if(strcmp(keyword, "UDT") == 0)          byte=126;
  else if(strcmp(keyword, "STRUCT") == 0)       byte=126;
  else if(strcmp(keyword, "ENDUDT") == 0)       byte=127;
  else if(strcmp(keyword, "ENDSTRUCT") == 0)    byte=127;
  else if(strcmp(keyword, "APPTYPE") == 0)      byte=200;
  else
  {
     pi = iswhite(pi);
     ch = p_string[pi];
     if(strchr("=#%!$", ch))                 
     {
        byte = 1;
        get_MOD(pi);                    
        pi = e_pos;                          
     }
     else if(strchr("._", ch))                
     {
        byte = 1;
        get_MOD(pi);                    
        pi = e_pos;                          
     }
     else
     {
        a_bort(ab_code, x);            
     }
  }
  e_pos = pi;
  return byte;
}
/*---------- end get_byte ----------*/


void tmp_prog(int ii)
{   
   char ch, prog[BUFSIZE];
   int pi, si=0, len;

   len = strlen(p_string);
   pi = e_pos;
   pi = iswhite(pi);
   /* --- correct: LINE INPUT --- */
   if(temp_byte[ii] == 18)
   {
      ch = p_string[pi];
      while(isalpha(ch))
      {
         pi++;                               
         ch = p_string[pi];
      }
      pi = iswhite(pi);
      ch = p_string[pi];
      while(ch != '\0')
      {
         prog[si] = ch;
         si++;
         pi++;
         ch = p_string[pi];
      }
      prog[si] = '\0';
  }
  else if((pi < len) && (temp_byte[ii] != 0))
  {
     ch = p_string[pi];
     while(ch != '\0')
     {
        prog[si] = ch;
        si++;
        pi++;
        ch = p_string[pi];
     }
     prog[si] = '\0';
  }
  else
  {
     strcpy(prog, "\n\0");
  }
  strcpy(temp_prog[ii], prog);
}
/*---------- end tmp_prog ----------*/


void loader_2()
{   
   int ndx, ii, line_count=0, lines=nrows;
   unsigned size;

   /* --- re-count number of lines --- */
   for(ndx=0; ndx < nrows; ndx++)
   {
      if(temp_byte[ndx] != 0)
      {
        line_count++;
      }
      if((temp_byte[ndx] == 13) || (temp_byte[ndx] == 14))
      {
         token_if(ndx);		            
         str_fun3(ndx);
      }
      if(temp_byte[ndx] == 27)
      {
         token_if(ndx);		            
         str_fun3(ndx);
      }
      else if(temp_byte[ndx] == 1)
      {
         str_funn(ndx);	           
      }
      else if(temp_byte[ndx] == 4)
      {
         str_fun2(ndx);	            
      }
      else if((temp_byte[ndx] == 23) || (temp_byte[ndx] == 24))
      {
         str_funn(ndx);	  		    
      }
      else if(temp_byte[ndx] == 38)
      {
         preproc_sub(ndx);	  			    
      }
  }
  nrows = line_count;
  /* --- create program arrays --- */
  array1 = malloc(nrows * sizeof(char *));
  label_nam = malloc(nrows * sizeof(char *));
  for(ii = 0; ii < nrows; ii++)
  {
    label_nam[ii] = malloc(LLEN * sizeof(char));
  }
  byte_array = malloc(nrows * sizeof(int));
  /* --- transfer temp_arrays to program_arrays --- */
  ndx = 0;
  for(ii=0; ii < lines; ii++)
  {
    if(temp_byte[ii] != 0)
    {
       strcpy(label_nam[ndx], temp_label[ii]);
       byte_array[ndx] = temp_byte[ii];
       size = strlen(temp_prog[ii]);
       size++;
       array1[ndx] = malloc(size * sizeof(char));
       strcpy(array1[ndx], temp_prog[ii]);
       ndx++;
    }
  }
  /* --- free temp array memory --- */
  for(ii=0; ii < lines; ii++)
  {
     free(temp_label[ii]);
     free(temp_prog[ii]);
  }
  free(temp_label);
  free(temp_byte);
  free(temp_prog);
}
/*---------- end loader_2 ----------*/


void preproc_sub(int ndx)
{   
   char label[LLEN];
   int pi=0;

   e_pos = pi;
   strcpy(p_string, temp_prog[ndx]);
   strcpy(label, get_varname());
   strcpy(temp_label[ndx], label);		      
}
/*------- end preproc_sub -------*/


void token_if(int ndx)
{   
   char temp[TOKEN_LEN];
   int loc;

   strcpy(p_string, temp_prog[ndx]);
   s_pos = 0;
   strcpy(temp, "AND");
   loc = 0;
   while(loc >= 0)
   {
     loc = find_strng(temp);
     loc--;
     if(loc > 0)
     {
       p_string[loc] = '&';                 
       p_string[(loc+1)] = ' ';
       p_string[(loc+2)] = ' ';
     }
  }
  strcpy(temp, "OR");
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = '|';                 
      p_string[(loc+1)] = ' ';
    }
  }
  strcpy(temp, "THEN");                        
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = '\n';                
      p_string[(loc+1)] = '\0';
    }
  }
  strcpy(temp, "Then");                        
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = '\n';               
      p_string[(loc+1)] = '\0';
    }
  }
 strcpy(temp_prog[ndx], p_string);
}
/*---------- end token_if ----------*/


void str_funn(int ndx)                    
{
   char ch, temp[VAR_NAME]; 	            
   int pi=0, len;

   strcpy(p_string, temp_prog[ndx]);
   while(IsEqu(pi) == 0)		            
   {
      pi = e_pos;
      pi++;
   }
   pi = e_pos;	       
   len = strlen(p_string);
   pi++;                                   
   while(pi < len)
   {
     pi = iswhiter(pi);                 
     ch = p_string[pi];                  
     if(ch == '\"')                      
     {
       pi = get_quote(pi, len);
     }
     else
     {    
       /* get_upper Start */
       ch = p_string[pi];
       while((isupper(ch) == 0) && (pi < len))
       {
         pi++;
         ch = p_string[pi];
       }
       /* get_upper Stop */
       if(pi < len)
       {
          e_pos = pi;
          strcpy(temp, get_varname());     
          s_pos = e_pos;
          ch = p_string[s_pos];
          /* printf("spos=%d, ch=%c, name=%s\n", s_pos, ch, temp);*/
          if(ch == '$')                    
          {
            e_pos = pi;
            get_strfunc(temp,ndx);      
          }
          else
          {
            e_pos = pi;
            get_mathfunc(temp,ndx);	     
          }
          pi = e_pos;
          pi++;
        }
      }
   }
}
/*---------- end str_functn ----------*/


void str_fun2(int ndx)
{   
   char ch, quote='\"', temp[VAR_NAME];         
   int pi=0, len;		                         

   strcpy(p_string, temp_prog[ndx]);
   len = strlen(p_string);
   /* --- loop --- */
   while(pi < len)
   {
     ch = p_string[pi];
     if(ch == quote)
     {
       pi= get_quote(pi, len);
     }
     else
     {
        /* get_upper Start */
        ch = p_string[pi];
        while((isupper(ch) == 0) && (pi < len))
        {
          pi++;
          ch = p_string[pi];
        }
        /* get_upper Stop */
        if(pi < len)
        {
          e_pos = pi;
          strcpy(temp, get_varname());	
          s_pos = e_pos;
          ch = p_string[s_pos];
          if(ch == '$')                    
          {
             e_pos = pi;
             get_strfunc(temp,ndx);	     
          }
          else
          {
             e_pos = pi;
             get_mathfunc(temp,ndx);      
          }
          pi = e_pos;
          pi++;
        }
      }
   }
}
/*---------- end str_funct2 ----------*/


void get_strfunc(char *varname,int ndx)		     
{   
   char temp[TOKEN_LEN];

   temp[0] = '\0';

   /* --- now compare to functions --- */
   if(strcmp(varname, "CHR") == 0)
   {
      strcpy(temp, "   1");	                 
   }
   else if(strcmp(varname, "LEFT") == 0)
   { 
      strcpy(temp, "    2");	               
   }
   else if(strcmp(varname, "RIGHT") == 0)
   {
      strcpy(temp, "     3");	                 
   }
   else if(strcmp(varname, "MID") == 0)
   {
      strcpy(temp, "   4");	                 
   }
   else if(strcmp(varname, "SPACE") == 0)
   {
      strcpy(temp, "     5");	                 
   }
   else if(strcmp(varname, "STR") == 0)
   {
      strcpy(temp, "   6");	                 
   }
   else if(strcmp(varname, "STRING") == 0)
   {
      strcpy(temp, "      7");                 
   }
   else if(strcmp(varname, "INKEY") == 0)
   {
      strcpy(temp, "     8");                 
   }
   else if(strcmp(varname, "INPUT") == 0)
   {
      strcpy(temp, "     9");                  
   }
   else if(strcmp(varname, "MKD") == 0)
   {
      strcpy(temp, "  10");                   
   }
   else if(strcmp(varname, "MKI") == 0)
   {
      strcpy(temp, "  11");                    
   }
   else if(strcmp(varname, "MKS") == 0)
   {
      strcpy(temp, "  12");                    
   }
   else if(strcmp(varname, "UCASE") == 0)
   { 
      strcpy(temp, "    13");                  
   }
   else if(strcmp(varname, "LCASE") == 0)
   {
      strcpy(temp, "    14");                  
   }
   else if(strcmp(varname, "TIME") == 0)
   {
      strcpy(temp, "   15");                   
   }
   else if(strcmp(varname, "DATE") == 0)
   {
      strcpy(temp, "   16");                   
   }
   str_copy(temp, ndx);		            
}
/*---------- end get_strfunc ----------*/


void get_mathfunc(char *varname, int ndx)        
{   
   char temp[TOKEN_LEN];

   temp[0] = '\0';
   /* --- now compare to functions --- */
   if(strcmp(varname, "ABS") == 0)
   {
      strcpy(temp, " ?1");		             
   }
   else if(strcmp(varname, "ASC") == 0)
   {
      strcpy(temp, " ?2");		             
   }
   else if(strcmp(varname, "ATN") == 0)
   {
      strcpy(temp, " ?3");		             
   }
   else if(strcmp(varname, "COS") == 0)
   {
      strcpy(temp, " ?4");		             
   }
   else if(strcmp(varname, "SIN") == 0)
   {
      strcpy(temp, " ?5");		             
   }
   else if(strcmp(varname, "TAN") == 0)
   {
      strcpy(temp, " ?6");		             
   }
   else if(strcmp(varname, "SQRT") == 0)
   {
      strcpy(temp, "  ?7");		             
   }
   else if(strcmp(varname, "INT") == 0)
   {
      strcpy(temp, " ?8");		             
   }
   else if(strcmp(varname, "LEN") == 0)
   {
      strcpy(temp, " ?9");		             
   }
   else if(strcmp(varname, "LOF") == 0)
   {
      strcpy(temp, "?10");		             
   }
   else if(strcmp(varname, "LOC") == 0)
   {
      strcpy(temp, "?11");		             
   }
   else if(strcmp(varname, "CVD") == 0)
   {
      strcpy(temp, "?12");		            
   }
   else if(strcmp(varname, "CVI") == 0)
   {
      strcpy(temp, "?13");		             
   }
   else if(strcmp(varname, "CVS") == 0)
   {
      strcpy(temp, "?14");		             
   }
   else if(strcmp(varname, "EOF") == 0)
   {
      strcpy(temp, "?15");		             
   }
   else if(strcmp(varname, "VAL") == 0)
   {
      strcpy(temp, "?16");		             
   }
   else if(strcmp(varname, "CLOCK") == 0)
   {
      strcpy(temp, "  ?17");                  
   }
   else if(strcmp(varname, "RAND") == 0)
   {
      strcpy(temp, " ?18");                    
   }
   else if(strcmp(varname, "LOG") == 0)
   {   
      strcpy(temp, "?19");                     
   }
   else if(strcmp(varname, "LOG10") == 0)
   {
      strcpy(temp, "  ?20");                   
   }
   else if(strcmp(varname, "SECONDS") == 0)
   {
      strcpy(temp, "    ?21");                 
   }
   else if(strcmp(varname, "EXP") == 0)
   {
      strcpy(temp, "?23");                     
   }
   else if(strcmp(varname, "ACOS") == 0)
   {
      strcpy(temp, " ?24");                    
   }
   else if(strcmp(varname, "ASIN") == 0)
   {
      strcpy(temp, " ?25");                    
   }
   else if(strcmp(varname, "CEIL") == 0)
   {
      strcpy(temp, " ?26");                   
   }
   else if(strcmp(varname, "COSH") == 0)
   {
      strcpy(temp, " ?27");                    
   }
   else if(strcmp(varname, "FABS") == 0)
   {
      strcpy(temp, " ?28");                    
   }
   else if(strcmp(varname, "FLOOR") == 0)
   {
      strcpy(temp, "  ?29");                   
   }
   else if(strcmp(varname, "FMOD") == 0)
   {
      strcpy(temp, " ?30");                    
   }
   else if(strcmp(varname, "HYPOT") == 0)
   {
      strcpy(temp, "  ?31");                   
   }
   else if(strcmp(varname, "LDEXP") == 0)
   {
      strcpy(temp, "  ?32");                   
   }
   else if(strcmp(varname, "MODF") == 0)
   {
      strcpy(temp, " ?33");                    
   }
   else if(strcmp(varname, "POW") == 0)
   {
      strcpy(temp, "?34");                     
   }
   else if(strcmp(varname, "POW10") == 0)
   {
      strcpy(temp, "  ?35");                   
   }
   else if(strcmp(varname, "SINH") == 0)
   {
      strcpy(temp, " ?36");                    
   }
   else if(strcmp(varname, "TANH") == 0)
   {
      strcpy(temp, " ?37");                    
   }
   else if(strcmp(varname, "ATAN2") == 0)
   {
      strcpy(temp, "  ?38");                   
   }
   else if(strcmp(varname, "FREXP") == 0)
   { 
      strcpy(temp, "  ?39");                   
   }
   else if(strcmp(varname, "LABS") == 0)
   {
      strcpy(temp, " ?40");                    
   }
   else if(strcmp(varname, "TIMER") == 0)
   {
      strcpy(temp, "  ?42");                   
   }
   else if(strcmp(varname, "SGN") == 0)
   {
      strcpy(temp, "?43");                     
   }
   else if(strcmp(varname, "CINT") == 0)
   {
      strcpy(temp, " ?48");                    
   }
   else if(strcmp(varname, "CDBL") == 0)
   {
      strcpy(temp, " ?49");                    
   }
   else if(strcmp(varname, "CSNG") == 0)
   {
      strcpy(temp, " ?50");                    
   }
   else if(strcmp(varname, "CLNG") == 0)
   {
      strcpy(temp, " ?51");                   
   }
   str_copy(temp, ndx);		   
}
/*---------- end get_mathfunc ----------*/


void str_copy(char *temp,int ndx)
{   
   char ch, tok[TOKEN_LEN];	            
   int pi, si=0;

   strcpy(tok, temp);
   pi = e_pos;
   ch = tok[si];
   if(ch != '\0')
   {
     while(ch != '\0')
     {
       p_string[pi] = ch;
       si++;
       pi++;
       ch = tok[si];
     }
     strcpy(temp_prog[ndx], p_string);
     e_pos = pi;
  }
  else
  {
     e_pos = s_pos;		                     
  }
}
/*---------- end str_copy ----------*/


int IsEqu(int pi)
{   
   char ch;			                         
   int ibool=0;

   pi = iswhite(pi);
   e_pos = pi;
   ch = p_string[pi];
   if(ch == '=')
   {
     ibool = 1;
   }
   return ibool;
}
/*---------- end IsEqu ----------*/


void str_fun3(int ndx)
{   
   char ch, quote='\"', temp[VAR_NAME];        
   int pi, len;		                        

   strcpy(p_string, temp_prog[ndx]);
   len = strlen(p_string);
   pi = 0;
   /* --- loop --- */
   while(pi <= len)
   {
     ch = p_string[pi];
     if(ch == quote)
     {
       pi= get_quote(pi, len);
     }
     else if(isupper(ch) != 0)
     {
       e_pos = pi;
       strcpy(temp, get_varname());	       
       s_pos = e_pos;
       ch = p_string[s_pos];
       if(ch == '$')                        
       {
         e_pos = pi;
         get_strfunc(temp,ndx);	         
       }
       else
       {
         e_pos = pi;
         get_mathfunc(temp,ndx);          
       }
       pi = e_pos;
       /* pi++; */
     }
     else
     {
       pi++;
     }
  }
}
/*---------- end str_funct3 ----------*/

void tmp_byte(int ii)
{
   char ch;
   int pi, si, byte;
   int x=ii, ab_code=4;

   /* ----- fill temp_byte[] here ----- */
   pi = e_pos;
   pi = iswhite(pi);
   ch = p_string[pi];
   if(ch == '\'')                               
   {
     byte = 0;
     strcpy(temp_prog[ii], "\n\0");
   }
   else
   {
     if(isupper(ch))                          
     {
       e_pos = pi;
       byte = get_byte(ii);                 
       pi = e_pos;
     }
     else
     {
       if(isalpha(ch))
       {
         si = pi;                             
        
         pi = while_dd(pi);           
         pi = iswhite(pi);
         ch = p_string[pi];
         if(strchr("=#%!$", ch))              
         {
           byte = 1;
           get_MOD(pi);                     
           pi = si;
         }
         else
         {
           a_bort(ab_code, x);              
         }
       }

     }
   }
   temp_byte[ii] = byte;
   e_pos = pi;
}

/*  need to study 
   else
   {
     if(isupper(ch))                          
     {
       e_pos = pi;
       byte = get_byte(ii);                 
       pi = e_pos;
     }
     else             
     {
       if(isalpha(ch))
       {
         si = pi;                             
        
         pi = while_dd(pi);           
         pi = iswhite(pi);
         ch = p_string[pi];
         if(strchr("=#%!$", ch))              
         {
           byte = 1;
           get_MOD(pi);                     
           pi = si;
         }
         else
         {
           a_bort(ab_code, x);              
         }
       }
     }
     else
     {
       a_bort(ab_code, x);                 
     }
   }
*/
/*---------- end tmp_byte ----------*/

/* bxbasic : Loops.c : alpha version.20.3.1   */
/* Copyright:(c) sarbayo, 2001-2011           */
/* Modified T. Chandler CMSBASIC - cmsloops.c */


void go_to()
{   
   char ch;
   char goto_label[LLEN];
   int pi, si=0, ab_code=8;
   int xtest, x=line_ndx;

   pi = e_pos;
   pi = iswhite(pi);
   ch = p_string[pi];
   while(isalnum(ch))
   {
     goto_label[si] = ch;
     pi++;
     si++;
     ch = p_string[pi];
   }
   goto_label[si] = '\0';             
   pi = -1;            
   xtest = -1;
   while(xtest != 0)
   {
     pi++;
     if(pi == nrows)
     {
       strcpy(t_holder, goto_label);
       a_bort(ab_code, x);        
     }
     xtest = strcmp(label_nam[pi], goto_label);
   }
   pi--;
   line_ndx = pi;            
}
/*--------- end go_to ----------*/


void do_gosub()
{   
   unsigned size;

   if(gs_ptr == 0)
   {
     size = (gs_ptr + 1);
     gosub_stack = malloc(size * sizeof(int));
   }
   else
   {
     size = (gs_ptr + 1);
     gosub_stack = realloc(gosub_stack, size * sizeof(int));
   }
   gosub_stack[gs_ptr] = line_ndx;
   gs_ptr++;
   go_to();
}
/*------- end do_gosub ----------*/


void do_return()
{   
   int ab_code=40, x=line_ndx;
   unsigned size;

   if(gs_ptr == 0)
   {
      a_bort(ab_code, x);        
   }
   else if(gs_ptr == 1)
   {
      gs_ptr--;                      
      line_ndx = gosub_stack[gs_ptr];   
      free(gosub_stack);
   }
   else
   {
      gs_ptr--;                      
      line_ndx = gosub_stack[gs_ptr];    
      size = (gs_ptr);
      gosub_stack = realloc(gosub_stack, size * sizeof(int));
   }
}
/*------- end do_return ----------*/


void do_for()
{   
   char ch;                          
   int pi, f_ndx, Inc=1;
   int start, next_tru;
   int From, Final;

   /* --- assign FROM --- */
   f_ndx = get_From();
   /* --- get TO --- */
   Final = get_To();
   /* --- get STEP --- */
   pi = e_pos;
   ch = p_string[pi];
   if(ch == 'S')
   {
     Inc = get_Step();
   }
   /* --- setup for-loop conditions --- */
   From = Gtbl[f_ndx].Int;
   start = line_ndx;                       
   fornxt_flg++;                          
   /* --- increment loop --- */
   if(From < Final)
   {
     for(; Gtbl[f_ndx].Int <= Final; Gtbl[f_ndx].Int += Inc)
     {
       next_tru = 1;
       line_ndx = (start + 1);        
       while(next_tru == 1)
       {
         strcpy(p_string, array1[line_ndx]);
         token = byte_array[line_ndx];
         s_pos = 0;
         e_pos = 0;
         parser();
         if(token == 12)           
         {
           next_tru = 0;
           token = 0;
         }
         else
         {
           line_ndx++;
         }
       }
     }
  }
  /* --- decrement loop --- */
  else
  {
    for(; Gtbl[f_ndx].Int >= Final; Gtbl[f_ndx].Int -= Inc)
    {
      next_tru = 1;
      line_ndx = (start + 1);        
      while(next_tru == 1)
      {
        strcpy(p_string, array1[line_ndx]);
        token = byte_array[line_ndx];
        s_pos = 0;
        e_pos = 0;
        parser();
        if(token == 12)           
        {
          next_tru = 0;
          token = 0;
        }
        else
        {
          line_ndx++;
         }
       }
     }
  }
  fornxt_flg--;                          
}
/*-------- end do_for ----------*/


void do_next()
{
   int ab_code=16, x=line_ndx;

   if(fornxt_flg == 0)
   {
     a_bort(ab_code,x);
   }
}
/*-------- end do_next ---------*/


int get_From()
{
   char varname[VAR_NAME];
   int pi, type, f_ndx, sav_pi, ab_code=5, x=line_ndx;

   pi = e_pos;
   sav_pi = pi;
   /* --- get varname --- */                   
   strcpy(varname, get_varname());
   type = get_objtype(pi);
   if(type != 1)
   {
     a_bort(ab_code, x);
   }
   let_int(varname);
   /* --- get array index --- */
   if(callFlag == 0)
   {
     f_ndx = get_vndx(varname);
   }
   else
   {
     f_ndx = get_llvarndx(varname);        
   }
   return f_ndx;
}
/*-------- end get_from ----------*/


int get_To()
{   
   char ch, varname[VAR_NAME];
   int pi, Final, ab_code, x=line_ndx;

   pi = e_pos;
   pi = iswhite(pi);
   ch = p_string[pi];
   /* --- get TO --- */
   if(ch != 'T')
   {
     strcpy(t_holder,"TO");
     ab_code=7;
     a_bort(ab_code,x);
   }
   else
   {
     strcpy(varname, get_varname());
     pi = e_pos;
     ch = p_string[pi];
     if(strcmp(varname, "TO") != 0)
     {
       strcpy(t_holder,"TO");
       ab_code=7;
       a_bort(ab_code,x);
     }
   }
   pi = iswhite(pi);
   ch = p_string[pi];
   e_pos = pi;
   /* --- get Final value --- */
   if(isalnum(ch))
   {
     Final = (int) get_avalue();
   }
   else                       
   {
     strcpy(t_holder,"TO");
     ab_code=15;
     a_bort(ab_code, x);
   }
   return Final;
}
/*-------- end get_to ----------*/


int get_Step()
{   
   char ch, varname[VAR_NAME];
   int pi, Inc, ab_code, x=line_ndx;
   char sav_ch=' ';

   strcpy(varname, get_varname());
   if(strcmp(varname, "STEP") != 0)
   {
     strcpy(t_holder, "STEP");
     ab_code=7;
     a_bort(ab_code,x);
   }
   pi = e_pos;
   pi = iswhiter(pi);
   ch = p_string[pi];
   /* --- get Inc value --- */
   if(IsAddop(ch))
   {
     sav_ch = ch;
     pi++;
     pi = iswhiter(pi);
     ch = p_string[pi];
   }
   e_pos = pi;
   if(isalnum(ch))
   {
     Inc = (int) get_avalue();
   }
   else                       
   {
     strcpy(t_holder,"STEP");
     ab_code=15;
     a_bort(ab_code, x);
   }
   if(sav_ch == '-')
   {
     Inc = (0 - Inc);
   }
   return Inc;
}
/*-------- end get_Step ----------*/


void do_Wend()
{   
   int begn_ndx, wend_ndx;

   begn_ndx = line_ndx;
   wend_ndx = find_wend(line_ndx);
   while(boolexpress())
   {
     line_ndx++;
     while(line_ndx != wend_ndx)
     {
       s_pos = 0;
       e_pos = 0;
       strcpy(p_string, array1[line_ndx]);
       token = byte_array[line_ndx];
       parser();
       line_ndx++;
     }
     line_ndx = begn_ndx;
     strcpy(p_string, array1[line_ndx]);
     token = byte_array[line_ndx];
     e_pos = 0;
  }
  line_ndx = wend_ndx;
}
/*-------- end do_WhileWend ----------*/


int find_wend(int ndx)
{   
   int tok=0, ab_code=32, x=line_ndx;

   while((tok != 28) && (ndx < nrows))	   
   {
     ndx++;
     tok = byte_array[ndx];
     if(tok == 27)                  
     {
       ndx = find_wend(ndx);
     }
   }
   if(ndx >= nrows)
   {
     a_bort(ab_code, x);
   }
   return ndx;
}
/*------- end find_wend -------*/


void do_DoWhile()
{
  do_flag++;
  do_pointer = line_ndx;     
}
/*------- end do_DoWhile -------*/


void do_While()
{
   if(do_flag == 0)
   {
     do_Wend();        
   }
   else
   {
     do_WDo();          
   }
}
/*------- end do_While -------*/


void do_WDo()
{
   if(boolexpress())
   {
     line_ndx = do_pointer;  
   }
   else
   {
     do_flag--;
     do_pointer = 0;
   }
}
/*------- end do_WhileDo -------*/


/* bxbasic : Output.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011          */
/* Modified T. Chandler CMSBASIC - cmsbout.c */


void set_TabNl(int ch)
{
   if(ch == ',')
   {
      printf("\t");
   }
   else if(ch == ':')
   {
      printf("\n");
   }
}
/*---------- end set_TabNl ----------*/


void parse_print()
{
  char varname[VAR_NAME], ch;
  int pi, pii, ii, type;
  int ab_code=9, x=line_ndx;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;
  /* --- print to file --- */
  if(ch == '#')
  {
    p_string[pi] = '@';           
    print_io();
    return;
  }
  /* --- print newline --- */
  else if(strchr(":\n", ch))
  {
    printf("\n");
    return;
  }
  /* --- LOOP: multiple print statements --- */
  while(ch != '\n')
  {
    if(isalpha(ch))    /* --- print variable --- */
    {
      pi = e_pos;
      pii = pi;                       
      strcpy(varname, get_varname());
      ii = e_pos;
      type = get_objtype(ii);
      if((UdtCnt > 0) && (type < 6))  
      {
        type = isThisUdt(varname, type);
        udtpi += pii;               
      }
      if(type == 0)
      {
        get_strvar(varname);        
      }
      else if(type == 6)
      {
        get_strarray(varname);	    
      }
      else if(type == 10)             
      {
        e_pos = pi;
        get_strUDT();
      }
      else
      {
        e_pos = pi;
        get_prnvar();		        
      }
    }
    else if(isdigit(ch))
    {
      proc_digit();	           
    }
    else if(ch == '?')
    {
      var_type = '?';
      get_prnvar();		       
    }
    else if(ch == '(')
    {
      get_prnvar();		      
    }
    else if(ch == '\"')    	  
    {
      get_prnstring();
    }
    /* --- error: --- */
    else
    {
      a_bort(ab_code, x);
    }
    pi = e_pos;
    ch = p_string[pi];
    if(ch != '\n')
    {
      pi++;
      pi = iswhiter(pi);
      ch = p_string[pi];
      e_pos = pi;
    }
  }
}
/*-------- end parse_print --------*/


void proc_digit()
{   
   char ch, val_strng[VAR_NAME];
   int pi, len, px;
   double value;

   pi = e_pos;
   len = strlen(p_string);
   /* get_paren Start */
   ch = p_string[pi];
   while((strchr("()", ch) == 0) && (pi < len))
   {
     pi++;
     ch = p_string[pi];
   }
   /* get_paren Stop */
   px = pi;
   /* get_NextOp Start */ 
   pi = while_isalnum(pi);
   pi = iswhiter(pi);
   /* get_NextOp Stop */
   if(pi == px)                      
   {
     prn_strfunc();                
   }
   else
   {
     value = rdp_main();           
     strcpy(val_strng, value2strng(value));
     pi = e_pos;
     pi = iswhiter(pi);
     ch = p_string[pi];
     e_pos = pi;
     if(ch == ',')      printf("%s \t", val_strng);
     else if(ch == ';') printf("%s ", val_strng);
     else               printf("%s \n", val_strng);
  }
}
/*-------- end proc_digit --------*/


void prn_strfunc()
{   
   char ch;
   int pi;

   /* --- get function --- */
   asn_function();

   pi = e_pos;
   pi++;
   pi = iswhiter(pi);
   ch = p_string[pi];
   e_pos = pi;
   /* --- display string$ --- */
   if(ch == ',')      printf("%s\t", s_holder);
   else if(ch == ';') printf("%s", s_holder);
   else               printf("%s\n", s_holder);
}
/*--------- end prn_strfunc -----------*/


void get_prnstring()
{   
  char ch;
  int pi, si = 0, stlen;
  int ab_code=6, x=line_ndx;

  stlen = strlen(p_string);
  pi = e_pos;
  pi++;
  ch = p_string[pi];
  while((ch != '\"') && (pi < stlen))
  {
    xstring[si] = ch;
    pi++;
    si++;
    ch = p_string[pi];
  }
  xstring[si]='\0';
  /* --- error: no closing quote --- */
  if(pi >= stlen)
  {
    a_bort(ab_code, x);
  }
  /* --- advance to next character --- */
  pi++;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;
  /* --- print quoted string --- */
  if(ch == ',')      printf("%s\    ", xstring);
  else if(ch == ';') printf("%s",      xstring);
  else               printf("%s\n",    xstring);
}
/*-------- end get_prnstring --------*/



void get_strUDT()
{
   char varname[VAR_NAME], temp[BUFSIZE];
   char ch, *ptr;
   int pi, ndx, indx, vcount, offset, size;

   ndx = get_UDTndx();                     
   pi = udtpi;
   pi++;
   e_pos = pi;
   strcpy(varname, get_varname());	       
   /* -------------------------------- */
   pi = e_pos;
   ch = p_string[pi];
   if(ch == '$')
   {
      pi++;
   }
   pi = iswhiter(pi);
   e_pos = pi;
   /* -------------------------------- */
   vcount = UDT[ndx].numVars;         
   indx = get_UdtvNamIdx(varname, ndx, vcount); 
   offset = UDT[ndx].offset[indx];
   size = UDT[ndx].size[indx];
   /* --- make string assignment --- */
   ptr = UDT[ndx].data;
   ptr += offset;
   memcpy(temp, ptr, size * sizeof(char));
   /* --- display string$ --- */
   if(ch == ',')      printf("%s\t", temp);
   else if(ch == ';') printf("%s", temp);
   else               printf("%s\n", temp);
}
/*------ end get_strUDT ------*/


void get_strvar(char *varname)
{
   char ch;
   int pi, ndx=0, ab_code=13, x=line_ndx;

   if(callFlag == 0)
   {
     ndx = get_vndx(varname);
   }
   else
   {
     ndx = get_llvarndx(varname);       
   }
   pi = e_pos;
   ch = p_string[pi];
   if(ch == '$')
   {
      pi++;
   }
   pi = iswhiter(pi);
   ch = p_string[pi];
   e_pos = pi;
   /* --- display string$ --- */
   if(ch == ',')      printf("%s\t", Gtbl[ndx].Str);
   else if(ch == ';') printf("%s", Gtbl[ndx].Str);
   else               printf("%s\n", Gtbl[ndx].Str);
}
/*--------- end get_strvar -----------*/


void get_strarray(char *varname)
{   
   char ch;
   int pi, indx, nDims, len, offset;
   int *Subscripts;

   indx = get_arrayndx(varname);
   len = strlen(p_string);
   pi = e_pos;
   /* get_paren Start */
   ch = p_string[pi];
   while((strchr("()", ch) == 0) && (pi < len))
   {
      pi++;
      ch = p_string[pi];
   }
   /* get_paren Stop */
   pi++;
   e_pos = pi;
   Subscripts = &strArry[indx].sub[0];  
   nDims = strArry[indx].dim;           
   offset = get_offset2(Subscripts, nDims, len);
   pi = e_pos;
   pi++;
   pi = iswhiter(pi);
   ch = p_string[pi];
   e_pos = pi;
   /* --- display string$ --- */
   if(ch == ',')      printf("%s\t", strArry[indx].elem[offset]);
   else if(ch == ';') printf("%s", strArry[indx].elem[offset]);
   else               printf("%s\n", strArry[indx].elem[offset]);
}
/*--------- end get_strarray ---------*/


void get_prnvar()
{   
   char ch=var_type, val_strng[VAR_NAME];
   int pi;
   double value;

   /* --- call math parser --- */
   value = rdp_main();
   if(ch == '?')
   {
     var_type = func_type;
   }
   /* --- convert value to string$ --- */
   strcpy(val_strng, value2strng(value));
   var_type = '\0';
   func_type = '\0';
   pi = e_pos;
   pi = iswhiter(pi);
   ch = p_string[pi];
   e_pos = pi;
   if(ch == ',')      printf("%s \t", val_strng);
   else if(ch == ';') printf("%s ", val_strng);
   else               printf("%s \n", val_strng);
}
/*--------- end get_prnvar -----------*/


char *value2strng(double value)
{   
   static char buffer[81];
   int len, idx=0, dot=0;
   char ch, chx=var_type;

   /* --- convert to ascii, here --- */
   sprintf(buffer, "% f", value);
   len = strlen(buffer);
   ch = buffer[idx];
   /* --- trim trailing zeros --- */
   if(chx == '#')                          
   {
     idx = (len-1);
     ch = buffer[idx];
     while(ch == '0')
     {
       idx--;
       ch = buffer[idx];
     }
     buffer[(idx+1)] = '\0';
  }
  /* --- round up to .nn --- */
  else if(chx == '!')                    
  {
    dot = (len-5);
    idx = (len-1);
    while(idx > dot)
    {
      if((buffer[idx] >= '5') && (buffer[(idx-1)] == '9'))
      {
        buffer[idx] = '\0';
      }
      else if(buffer[idx] >= '5')
      {
        buffer[(idx-1)]++;
        buffer[idx] = '\0';
      }
      else
      {
         buffer[idx] = '\0';
      }
      idx--;
    }
  }
  /* --- trim to dot --- */
  else                           
  {
    idx = (len-7);
    buffer[idx] = '\0';
  }
  return buffer;
}
/*------ end value2strng -------*/

/* cmsbasic : Rdparser.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011             */
/* special credits to: Jack Crenshaw's:
   "How to Build a Compiler"                    */
/* Modified T. Chandler CMSBASIC - CMSBRDP.c    */


double rdp_main()		
{   
   double value;

   value = Expression();
   return value;
}
/*---------- end rdp_main ----------*/


double Expression()	
{
   char ch;
   int pi;
   double Value;

   pi = e_pos;
   ch = p_string[pi];
   if(IsAddop(ch))
   {               
     Value = 0;  /* ie: 0 = 0 - 2  (= -2) */
   }
   else
   {
     Value = Term();
     pi = e_pos;
     ch = p_string[pi];
   }
   while(IsAddop(ch))
   {
     switch(ch)
     {
        case '+':
          Match('+');
          Value = Value + Term();
          break;
    
        case '-':
          Match('-');
          Value = Value - Term();
          break;

        default:
          break;
     }
     pi = e_pos;
     ch = p_string[pi];
  }
  return Value;
}
/*---------- end Expression ----------*/


double Term()		
{   
   char ch;
   int pi;
   double Value;

   Value = Factor();
   pi = e_pos;
   ch = p_string[pi];
   while(IsMultop(ch))
   {
     switch(ch)
     {
        case '*':
          Match('*');
          Value = Value * Factor();   
          break;
    
        case '/':
          Match('/');
          Value = Value / Factor();   
          break;

        case '^':
          Match('^');
          Value = pow(Value, Factor()); 
          break;

        case '%':
          Match('%');
          Value = (int) Value % (int) Factor();     
          break;

        default:
          break;
     }
     pi = e_pos;
     ch = p_string[pi];
  }
  return Value;
}
/*---------- end Term ----------*/


double Factor()                        
{   
   char ch;
   int pi;
   double value;

   pi = e_pos;
   ch = p_string[pi];
   if(ch == '(')
   {
     Match('(');
     value = Expression();
     Match(')');
   }
   else
   {
     if(isalpha(ch))			
     {
       strcpy(s_holder, get_varname());
       value = get_varvalue();
       SkipWhite();
     }
     else if(ch == '?')		
     {
       value = math_functn();
       SkipWhite();
     }
     else				
     {
       value = GetNum();
     }
  }
  return value;
}
/*---------- end Factor ----------*/


double math_functn()
{   
  char ch, varname[VAR_NAME]; 
  int pi, type, ndx, len; 
  double value = 0;
  long ivalue;

  pi = e_pos;                     
  pi++;                          
  e_pos = pi;
  type = (int) get_avalue();

  switch(type)
  {
    case 1:		/* get_ABS */
      ivalue = (long) Factor();
      value = (double) abs(ivalue);
      break;

    case 2:		/* get_ASC */
      pi = e_pos;
      pi++;
      pi = iswhite(pi);
      ch = p_string[pi];
      e_pos = pi;
      if(isalpha(ch))                  
      {
        strcpy(varname, get_varname());
        if(callFlag == 0)
        {
          ndx = get_vndx(varname);          
        }
        else
        {
          ndx = get_llvarndx(varname);        
        }
        ch = Gtbl[ndx].Str[0];
      }
      else                            
      {
        pi++;
        ch = p_string[pi];
      }
      len = strlen(p_string);
      ch = p_string[pi];
      while((strchr("()", ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      pi++;
      e_pos = pi;
      value = (double) ch;
      break;

    case 3:		/* get_ATN */
      value = Factor();
      value = atan(value);
      break;

    case 4:		/* get_COS */
      value = Factor();
      value = cos(value);
      break;

    case 5:		/* get_SIN */
      value = Factor();
      value = sin(value);
      break;

    case 6:		/* get_TAN */
      value = Factor();
      value = tan(value);
      break;

    case 7:		/* get_SQRT */
      value = Factor();
      value = sqrt(value);
      break;

        case 8:
     /*       value = get_INT();	     */       
            break;
        case 9:
    /*        value = get_LEN();	     */         
            break;
        case 10:
    /*        value = get_LOF();	     */            
            break;
        case 11:
    /*        value = get_LOC();	     */             
            break;
        case 12:			                    
        case 13:			                     
        case 14:			                     
    /*        value = get_CVD();	    */
            break;
        case 16:
    /*        value = get_VAL();       */             
            break;
        case 17:
    /*        value = get_CLOCK();     */            
            break;
        case 18:
    /*        value = do_RAND();      */            
            break;
        case 19:
    /*        value = do_LOG();       */             
            break;
        case 20:
    /*        value = do_LOG10();     */             
            break;
        case 21:
    /*        value = get_SECONDS();  */            
            break;
        case 22:
            break;
        case 23:
    /*        value = get_EXP();     */              
            break;
        case 24:
    /*        value = get_ACOS();     */             
            break;
        case 25:
    /*        value = get_ASIN();    */              
            break;
        case 26:
     /*       value = get_CEIL();    */              
            break;
        case 27:
    /*        value = get_COSH();     */             
            break;
        case 28:
    /*        value = get_FABS();    */              
            break;
        case 29:
     /*       value = get_FLOOR();   */              
            break;
        case 30:
      /*      value = get_FMOD();    */              
            break;
        case 31:
    /*        value = get_HYPOT();   */              
            break;
        case 32:
    /*        value = get_LDEXP();   */              
            break;
        case 33:
    /*        value = get_MODF();    */              
            break;
        case 34:
     /*       value = get_POW();    */              
            break;
        case 35:
     /*       value = get_POW10();     */            
            break;

    case 36:		/*  get_SINH */
      value = Factor();
      value = sinh(value);
      break;

    case 37:		/*  get_TANH */
      value = Factor();
      value = tanh(value);
      break;

        case 38:
     /*       value = get_ATAN2();   */              
            break;
        case 39:
     /*       value = get_FREXP();    */             
            break;
        case 40:
     /*       value = get_LABS();     */             
            break;
        case 41:
     /*       value = call_API();     */             
            break;
        case 43:
     /*       value = get_SGN();     */             
            break;
        case 48:
     /*       value = get_CINT();    */              
            break;
        case 49:
     /*       value = get_CDBL();   */               
            break;
        case 50:
     /*       value = get_CSNG();    */              
            break;
        case 51:
     /*       value = get_CLNG();    */              
            break;
     /**/
        default:
            /* error */
            break;
    }

    switch(type)
    {   case 1:
        case 2:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
            func_type = '%';
            break;

        case 12:
            func_type = '#';
            break;

        default:
            func_type = '!';
            break;
    }
    return value;
}
/*---------- end math_functn ----------*/


/*
double get_CLNG()
{   long lngpart;
    double value;              
                            
    value = Factor();

    if(value > 0)
    {                             
        lngpart = (long) value;
        value -= lngpart;

        if(value >= .5)
        {
            value = 1.0;
        }
        else
        {
            value = 0.0;
        }
    }
    else
    {                            
        lngpart = (long) value;
        value -= lngpart;

        if(value <= -.5)
        {
            value = -1.0;
        }
        else
        {
            value = 0.0;
        }
    }

    value += lngpart;
    return value;
}
*/
/*---------- end get_CLNG ----------*/


/*
double get_CSNG()
{   float  fvalue;
    double value;             
                               
    fvalue = (float) Factor();
    value = fvalue;

    return value;
}
*/
/*---------- end get_CSNG ----------*/


/*
double get_CDBL()
{   double value;              
                              
    value = (double) Factor();

    return value;
}
*/
/*---------- end get_CDBL ----------*/



/*
double get_CINT()
{   int intpart;
    double value;             
                         
    value = Factor();

    if(value > 0)
    {                             
        intpart = (int) value;
        value -= intpart;

        if(value >= .5)
        {
            value = 1.0;
        }
        else
        {
            value = 0.0;
        }
    }
    else
    {                            
        intpart = (int) value;
        value -= intpart;

        if(value <= -.5)
        {
            value = -1.0;
        }
        else
        {
            value = 0.0;
        }
    }

    value += intpart;

    return value;
}
*/
/*---------- end get_CINT ----------*/


/*
double get_SGN()
{   double value;      
                       

    value = Factor();

    if(value > 0)
    {
        value = 1;
    }
    else if(value < 0)
    {
        value = -1;
    }
    else
    {
        value = 0;
    }

    return value;
}
*/
/*---------- end get_SGN ----------*/



/*
double get_LABS()
{   long ivalue;           
    double value;           
                            

    ivalue = (long) Factor();     
    value = (double) labs(ivalue); 

    return value;

}
*/
/*---------- end get_LABS ----------*/


/*
double get_FREXP()
{   char varname[VAR_NAME], ch;       
    int pi, len, ndx, valuey;     
    double value, valuex;         
                                  
                                  
    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;
    strcpy(varname, get_varname());		

    if(callFlag == 0)
    {
        ndx = get_vndx(varname);         
    }
    else
    {
        ndx = get_llvarndx(varname);        
    }

    value = frexp(valuex, &valuey);

    Gtbl[ndx].Int = valuey;        

    return value;

}
*/
/*---------- end get_FREXP ----------*/


/*
double get_ATAN2()
{   int pi, len; 
    char ch;                
    double value, valuex, valuey;


    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
   
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuey = get_avalue();
    value = atan2(valuex, valuey);

    return value;

}
*/
/*---------- end get_ATAN2 ----------*/


/*
double get_POW10()
{   double value, valuex=10, valuey;
                               

    valuey = Factor();
    value = pow(valuex, valuey);

    return value;

}
*/
/*---------- end get_POW10 ----------*/


/*
double get_POW()
{   int pi, len;
    char ch;                 
    double value, valuex, valuey;


    len = strlen(p_string);
    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
   
    e_pos = pi;

    valuey = get_avalue();
    value = pow(valuex, valuey);

    return value;

}
*/
/*---------- end get_POW ----------*/


/*
double get_MODF()
{   char varname[VAR_NAME], ch;       
    int pi, len, ndx;             
    double value, valuex, valuey; 


    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
   
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;
    strcpy(varname, get_varname());		

    if(callFlag == 0)
    {
        ndx = get_vndx(varname);         
    }
    else
    {
        ndx = get_llvarndx(varname);        
    }

    value = modf(valuex, &valuey);

    Gtbl[ndx].Dbl = valuey;        

    return value;

}
*/
/*---------- end get_MODF ----------*/


/*
double get_LDEXP()
{   int pi, len, valuey;  
    char ch;   
    double value, valuex;    
                             

    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuey = (int) get_avalue();
    value = ldexp(valuex, valuey);

    return value;

}
*/
/*---------- end get_LDEXP ----------*/


/*
double get_HYPOT()
{   int pi, len;  
    char ch;                  
    double value, valuex, valuey;   
                                    
                                    
    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
   
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
   
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuey = get_avalue();
    value = hypot(valuex, valuey);

    return value;

}
*/
/*---------- end get_HYPOT ----------*/


/*
double get_FMOD()
{   int pi, len;   
    char ch;                   
    double value, valuex, valuey;     
                                      

    len = strlen(p_string);
    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuex = get_avalue();

    pi = e_pos;
    
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    
    e_pos = pi;

    valuey = get_avalue();
    value = fmod(valuex, valuey);

    return value;

}
*/
/*---------- end get_FMOD ----------*/


/*
double get_FLOOR()
{   double value;         
                          
                          
    value = Factor();
    value = floor(value);

    return value;

}
*/
/*---------- end get_FLOOR ----------*/


/*
double get_FABS()
{   double value;          
                           
                           
    value = Factor();
    value = fabs(value);

    return value;

}
*/
/*---------- end get_FABS ----------*/


/*
double get_COSH()
{   double value;         
                          

    value = Factor();
    value = cosh(value);

    return value;

}
*/
/*---------- end get_COSH ----------*/


/*
double get_CEIL()
{   double value;       
                         
                         
    value = Factor();
    value = ceil(value);

    return value;

}
*/
/*---------- end get_CEIL ----------*/


/*
double get_ASIN()
{   double value;           
                            

    value = Factor();
    value = asin(value);

    return value;

}
*/
/*---------- end get_ASIN ----------*/


/*
double get_ACOS()
{   double value;         
                           

    value = Factor();
    value = acos(value);

    return value;

}
*/
/*---------- end get_ACOS ----------*/


/*
double get_EXP()
{   double value;          
                           

    value = Factor();
    value = exp(value);

    return value;

}
*/
/*---------- end get_EXP ----------*/


/*
long get_SECONDS()
{   long value;            
    time_t timer;          

    time(&timer);
    value = (long) timer;

    return value;

}
*/
/*---------- end get_SECONDS ----------*/


/*
double do_LOG10()
{   double value;              
                               

    value = Factor();
    value = log10(value);

    return value;
}
*/
/*---------- end do_LOG10 ----------*/


/*
double do_LOG()
{   double value;              
                               

    value = Factor();
    value = log(value);

    return value;
}
*/
/*---------- end do_LOG ----------*/


/*
int do_RAND()
{   char ch;                  
    int pi, len, random_val;  


    len = strlen(p_string);
    pi = e_pos;
    ch = p_string[pi];

    while((ch != ')') && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }

    pi++;
    pi = iswhite(pi);
    e_pos = pi;

    random_val = rand();

    return random_val;
}
*/
/**------ END RND_HANDLER -------**/


/*
long get_CLOCK()
{   long value;           
                         

    value = (long) clock();

    return value;
}
*/
/*---------- end get_CLOCK ----------*/


/*
void do_random()
{   char ch;
    int pi, seed;
    double value;


    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];
    

    if((isalpha(ch)) || (isdigit(ch)))	
    {
        e_pos = pi;
        value = get_avalue();

        seed = (int) value;
    }

    srand(seed);

}
*/
/*---------- end do_random ----------*/


/*
double get_VAL()
{   char ch, quote='\"', varname[VAR_NAME];       
    int pi, ndx, len, si, ab_code=9, x=line_ndx;
    double value;                  


    len = strlen(p_string);
    pi = e_pos;
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];
    e_pos = pi;

    if(isalpha(ch))			
    {
        strcpy(varname, get_varname());
        ndx = get_strndx(varname);

        value = atof(Gtbl[ndx].Str);
    }
    else if(ch == quote)
    {				        
        si = 0;
        pi++;
        ch = p_string[pi];

        while((ch != quote) && (pi < len))
        {
            s_holder[si] = ch;
            si++;
            pi++;
            ch = p_string[pi];
        }
        s_holder[si] = '\0';

        value = atof(s_holder);
    }
    else
    {   a_bort(ab_code,x);
    }

   
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
   
		
    pi++;
    e_pos = pi;

    return value;

}
*/
/*---------- end get_VAL ----------*/



/*
double get_INT()
{   long ivalue;            
    double value;           

    ivalue = (long) Factor();
    value = (double) ivalue;

    return value;
}
*/
/*---------- end get_INT ----------*/


void Match(char x)             
{   
   char ch, string[6];
   int pi, ab_code=12, ln=line_ndx;

   pi = e_pos;
   ch = p_string[pi];
   if(ch != x)
   {
     strcpy(string, "\" \"");
     string[1] = x;
     strcpy(t_holder, string);
     a_bort(ab_code,ln);
   }
   else
   {
     _GetChar();
     SkipWhite();
   }
}
/*---------- end Match ----------*/


void _GetChar()
{
  e_pos++;
}
/*---------- end _GetChar ----------*/


int Is_White(char ch)
{   
   int test=0;

   if((ch == ' ') || (ch == '\t'))
   {
     test = -1;
   }
   return test;
}
/*---------- end Is_White ----------*/


void SkipWhite() 	
{   
   char ch;
   int pi;

   pi = e_pos;
   ch = p_string[pi];
   while(Is_White(ch))
   {
     _GetChar();
     pi = e_pos;
     ch = p_string[pi];
   }
}
/*---------- end SkipWhite ----------*/


double GetNum()			
{   
   char ch;
   int pi, ab_code=12, ln=line_ndx;
   double value=0;

   pi = e_pos;
   ch = p_string[pi];
   if((! isdigit(ch)) && (ch != '.'))
   {
     strcpy(t_holder, "Numeric Value");
     a_bort(ab_code,ln);
   }
   value = asc_2_dbl();
   pi = e_pos;
   ch = p_string[pi];
   if(isdigit(ch))
   {
     while(isdigit(ch))
     {
       pi++;
       ch = p_string[pi];
     }
     e_pos = pi;
  }
  SkipWhite();
  return value;
}
/*---------- end GetNum ----------*/


int IsAddop(char ch) 		
{   
   int rval=0;

   if((ch == '+') || (ch == '-'))
   {
     rval = 1;
   }
   return rval;
}
/*---------- end IsAddop ----------*/


int IsMultop(char ch) 		
{   
   int rval=0;

   if(ch == '\0')
   {                       
     rval = 0;           
   }
   else if(strchr("*^/%", ch))
   {
     rval = 1;
   }
   return rval;
}
/*---------- end IsMultop ----------*/


double asc_2_dbl()
{   
   char ch, cvalue[33];
   int pi, vi_pos=0;
   double fvalue;

   pi = e_pos;
   ch = p_string[pi];
   while((isdigit(ch)) || (ch == '.') && (vi_pos <= 32))
   {
     cvalue[vi_pos] = ch;
     pi++;
     vi_pos++;
     ch = p_string[pi];
   }
   cvalue[vi_pos] = '\0';
   fvalue = atof(cvalue);                 
   e_pos = pi;
   return fvalue;
}
/*------- end asc_2_dbl ---------*/


/*
double get_LEN()
{   char ch, varname[VAR_NAME];          
    int pi, ndx, len, strnglen=0;        
    int type, indx, offset, nDims;
    int *Subscripts;
    double value=0;


    len = strlen(p_string);
    pi = e_pos;
 
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }

    if(pi < len)
    {
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];

        if(isalpha(ch))
        {
            e_pos = pi;
            strcpy(varname, get_varname());
            type = get_objtype(pi);

            switch(type)
            {
                case 0:                     
                    if(callFlag == 0)
                    {
                        ndx = get_vndx(varname);
                    }
                    else
                    {
                        ndx = get_llvarndx(varname);     
                    }

                    strnglen = strlen(Gtbl[ndx].Str);
                    pi = e_pos;
                    break;
                case 6:                     
                    indx = get_arrayndx(varname);

                    Subscripts = &strArry[indx].sub[0];  
                    nDims = strArry[indx].dim;           
                    pi = e_pos;

                    ch = p_string[pi];
                    while((strchr("()", ch) == 0) && (pi < len))
                    {
                      pi++;
                      ch = p_string[pi];
                    }

                    pi++;
                    e_pos = pi;

                    offset = get_offset2(Subscripts, nDims, len);

                    strnglen = strlen(strArry[indx].elem[offset]);
                    break;
            }
        }
        else
        {
            pi++;
            ch = p_string[pi];

            while((ch != '\"') && (pi < len))
            {
                strnglen++;
                pi++;
                ch = p_string[pi];
            }
        }
    }

    e_pos = pi;
    value = (double) strnglen;

    return value;
}
*/
/*---------- end get_LEN ----------*/


/*
double get_LOC()
{   int ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=30;
    long fil_rcrd;                
    double value;
    FILE *handle;


    value = Factor();                        
    ndx = (int) value;
    ndx--;

    err_hndlr(ab_code, x, 3, ndx, maxfiles);   
    err_hndlr(ab_code, x, 9, ndx, 0);         

    handle = fp[ndx].fptr;
    fil_rcrd = ftell(handle);
    value = (double) fil_rcrd;

    return value;
}
*/
/*---------- end get_LOC ----------*/


/*
double get_LOF()
{   int ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=31;
    long offset;
    double value;
    FILE *handle;


    value = Factor();                         
    ndx = (int) value;
    ndx--;

    err_hndlr(ab_code, x, 3, ndx, maxfiles);   
    err_hndlr(ab_code, x, 9, ndx, 0);         

    handle = fp[ndx].fptr;
    fseek(handle, 0L, SEEK_END);
    offset = ftell(handle);
    value = (double) offset;

    return value;
}
*/
/*---------- end get_LOF ----------*/


/*
double get_CVD()
{   double value;        
                        

    value = Factor();

    return value;
}
*/
/*---------- end get_CVD ----------*/


/* bxbasic : Strings.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011           */
/* Modified T. Chandler CMSBASIC - CMSBSTRG.c */


void dim_gstr(char *varname)
{   
   char temp[BUFSIZE];
   int pi, ndx;
   unsigned size;

   pi = e_pos;
   ndx = get_var_index(varname);
   lset_ndx = ndx;                   
   pi++;
   pi = iswhite(pi);
   e_pos = pi;
   Gtbl[ndx].ActSub = ActvSubs;   
   /* --- now get assignment string --- */
   Match('=');
   strcpy(temp, str_express());
   /* --- make string assignment --- */
   size = strlen(temp);
   size++;
   Gtbl[ndx].Str = malloc(size * sizeof(char));
   if(size == 1)
   {
     Gtbl[ndx].Str[0] = '\0';
   }
   else
   {
     strcpy(Gtbl[ndx].Str, temp);
   }
}
/*---------- end dim_gstr ----------*/


void parse_st(char *varname)
{   
   char temp[BUFSIZE];
   int pi, ndx;
   unsigned size;

   pi = e_pos;
   if(callFlag == 0)
   {
     ndx = get_vndx(varname);
   }
   else
   {
     ndx = get_llvarndx(varname);        
   }
   lset_ndx = ndx;                   
   pi++;
   pi = iswhite(pi);
   e_pos = pi;
   /* --- now get assignment string --- */
   Match('=');
   strcpy(temp, str_express());
   /* --- make string assignment --- */
   size = strlen(temp);
   size++;
   Gtbl[ndx].Str = realloc(Gtbl[ndx].Str, size * sizeof(char));
   strcpy(Gtbl[ndx].Str, temp);
}
/*---------- end parse_str ----------*/


char *str_express()
{   
   char ch;
   static char temp[BUFSIZE];
   int pi, len;

   temp[0] = '\0';
   len = strlen(p_string);
   pi = e_pos;
   while(pi < len)
   {
     ch = p_string[pi];
     if(ch == '\"')
     {
       strng_assgn();                  
     }
     else if(isdigit(ch))
     {
       asn_function();                 
     }
     else
     {
       strvar_assgn();                
     }
     strcat(temp, s_holder);           
     pi = e_pos;
     pi++;
     pi = iswhite(pi);
     e_pos = pi;
     ch = p_string[pi];
     if(ch == ',')
     {
       break;                          
     }
     else if(pi < len)
     {
       Match('+');                     
       pi = e_pos;
     }
  }
  return temp;
}
/*---------- end str_express ----------*/


void asn_function()
{   
  int type;
  char varname[VAR_NAME], ch, ztime[30];
  char char_x, quote='\"';
  int i, pi, indx, count, len, ii, left, ivalue;
  double fvalue,  value;
  time_t xtime;

  type = (int) get_avalue();

  switch(type)
  {
    case 1:		/* CHR$ */
      pi = e_pos;              
      pi++;                    
      pi = iswhite(pi);
      e_pos = pi;
      fvalue = get_avalue();
      ivalue = fvalue;
      s_holder[0] = ivalue;
      s_holder[1] = '\0';
      break;

    case 2:		/* LEFT$  */
      pi = e_pos;                  
      pi++;                    
      pi = iswhite(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(callFlag == 0)
      {
        indx = get_vndx(varname);
      }
      else
      {
        indx = get_llvarndx(varname);        
      }
      pi = e_pos;              
      pi += 2;                    
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      len = strlen(Gtbl[indx].Str);
      if(count > len)
      {
        count = len;
      }
      for(i=0; i < count; i++)
      {
        s_holder[i] = Gtbl[indx].Str[i];
      }
      s_holder[count] = '\0';
      break;
    
    case 3:		/* RIGHT$ */
      pi = e_pos;                 
      pi++;                   
      pi = iswhite(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(callFlag == 0)
      {
        indx = get_vndx(varname);
      }
      else
      {
        indx = get_llvarndx(varname);        
      }
      pi = e_pos;              
      pi += 2;                   
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      len = strlen(Gtbl[indx].Str);
      if(count > len)
      {
        count = len;
      }
      left = (len - count);
      for(ii=0; ii < count; ii++, left++)
      {
        s_holder[ii] = Gtbl[indx].Str[left];
      }
      s_holder[count] = '\0';
      break;

    case 4:		/* MIDSTR$ */
      pi = e_pos;               
      pi++;                   
      pi = iswhite(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(callFlag == 0)
      {
        indx = get_vndx(varname);
      }
      else
      {
        indx = get_llvarndx(varname);        
      }
      pi = e_pos;               
      pi += 2;                  
      pi = iswhite(pi);
      e_pos = pi;
      left = (int) get_avalue();
      pi = e_pos;              	
      pi = iswhite(pi);           
      ch = p_string[pi];
      e_pos = pi;
      if(ch == ')')
      {
        count = 255;          
      }
      else
      {
        pi++;                 
        pi = iswhite(pi);
        e_pos = pi;
        count = (int) get_avalue();
      }
      if(count < 1)
      {
        count = 0;
      }
      len = strlen(Gtbl[indx].Str);
      left--;		    		
      if((left + count) > len)
      {
        count = (len - left);
      }
      for(ii=0; ii < count; ii++, left++)
      {
        s_holder[ii] = Gtbl[indx].Str[left];
      }
      s_holder[count] = '\0';
      break;
       
    case 5:		/* SPACESTR$ */
      pi = e_pos;               
      pi++;                  
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      else if(count > 255)
      {
        count = 255;
      }
      for(ii=0; ii < count; ii++)
      {
        s_holder[ii] = ' ';
      }
      s_holder[count] = '\0';
      break;
      
    case 6:		/* STR$ */
      pi = e_pos;              
      pi++;                    
      pi = iswhite(pi);
      e_pos = pi;
      value = get_avalue();
      strcpy(s_holder, value2strng(value));
      break;

    case 7:		/* STRINGS$ */
      pi = e_pos;           
      pi++;                
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      else if(count > 255)
      {
        count = 255;
      }
      pi = e_pos;                
      pi++;
      pi = iswhite(pi);
      e_pos = pi;
      ch = p_string[pi];
      if(ch == quote)               
      {
        pi++;
        ch = p_string[pi];
        char_x = ch;
        while(ch != ')')          
        {
            pi++;
            ch = p_string[pi];
        }
        e_pos = pi;
      }
      else
      {
        fvalue = get_avalue();
        ivalue = fvalue;
      }
      for(ii=0; ii < count; ii++)
      {
        s_holder[ii] = ivalue;
      }
      s_holder[count] = '\0';
      break;

    case 9:	/* a$ = INPUT$(n) */
	

    /*        inputstr();	*/	
            break;
        case 10:	/* a$ = MKD$(n) */
	
        case 11:	/* a$ = MKI$(n) */
	
        case 12:	/* a$ = MKS$(n) */
	
    /*        mkdstr();	*/
            break;
   
    case 13:		/* a$ = UCASE$(x$) */
      pi = e_pos;                  
      pi++;                    
      pi = iswhite(pi);
      e_pos = pi;  
      strcpy(varname, get_varname());
      indx = get_strndx(varname);
      pi = e_pos;               
      pi += 2;                    
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      len = strlen(Gtbl[indx].Str);
      count = len;
      for(i=0; i < count; i++)
      {
        s_holder[i] = toupper(Gtbl[indx].Str[i]);
      }
      s_holder[count] = '\0';
      break;

    case 14:		/* a$ = LCASE$(x$) */
      pi = e_pos;                  
      pi++;                    
      pi = iswhite(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      indx = get_strndx(varname);
      pi = e_pos;               
      pi += 2;                    
      pi = iswhite(pi);
      e_pos = pi;
      count = (int) get_avalue();
      if(count < 1)
      {
        count = 0;
      }
      len = strlen(Gtbl[indx].Str);
      count = len;
      for(i=0; i < count; i++)
      {
        s_holder[i] = tolower(Gtbl[indx].Str[i]);
      }
      s_holder[count] = '\0';
      break;

    case 15:		/* a$ = TIME$ */
      time(&xtime);
      strcpy(ztime, ctime(&xtime));
      len = strlen(ztime);
      ztime[len-1] = '\0';
      left = 11;
      count = 8;
      for(ii=0; ii < count; ii++, left++)
      {
        s_holder[ii] = ztime[left];
      }
      s_holder[count] = '\0';
      break;

    case 16:		 /* a$ = DATE$ */
      time(&xtime);
      strcpy(ztime, ctime(&xtime));
      len = strlen(ztime);
      ztime[len-1] = '\0';
      left = 0;
      count = 10;
      for(ii=0; ii < count; ii++, left++)
      {
        s_holder[ii] = ztime[left];
      }
      s_holder[count] = '\0';
      left = 19;
      count = 15;
      for(ii=10; ii < count; ii++, left++)
      {
        s_holder[ii] = ztime[left];
      }
      s_holder[count] = '\0';
      break;

    default:
      /* error */
      break;
  }
}
/*---------- end asn_function ----------*/


/*
void mkdstr()                       
{                                   
  strsval();                      
}
*/
/*------ end mkdstr ------*/


/*
void inputstr()
{   
  char ch;
  int pi, count, i;

  pi = e_pos;                      
  pi++;                            
  e_pos = pi;
  count = (int) get_avalue();

  for(i=0; i <= count; i++)
  {
    s_holder[i] = '\0';
  }

  i = 0;
  while(i < count)
  {
    ch = getche();
    if((ch > 31) && (ch < 127))	
    {
      s_holder[i] = ch;
      i++;
    }
    else if((ch == 8) && (i > 0))	
    {
      s_holder[i] = '\0';
      i--;
    }
  }
  s_holder[count] = '\0';
}
*/
/*---------- end inputstr ----------*/


void strng_assgn()
{   
   char ch, quote='\"';
   int pi, stlen, si=0, ab_code=6, x=line_ndx;

   stlen = strlen(p_string);
   pi = e_pos;                       
   pi++;
   ch = p_string[pi];
   /* --- fill buffer with string --- */
   si = 0;
   while((ch != quote) && (pi < stlen))
   {
     s_holder[si] = ch;
     si++;
     pi++;
     ch = p_string[pi];
   }
   s_holder[si] = '\0';
   if(pi == stlen)                 
   {
     a_bort(ab_code,x);
   }
   e_pos = pi;
}
/*---------- end strng_assgn ----------*/


int get_strndx(char *varname)
{   
   int indx=0;

   if(callFlag == 0)
   {
     indx = get_vndx(varname);
   }
   else
   {
     indx = get_llvarndx(varname);        
   }
   return indx;
}
/*---------- end get_strndx ----------*/


void strvar_assgn()
{
  char varname[VAR_NAME], ch;
  int pi, pii, len, type, indx, nDims, offset;
  int *Subscripts;

  pi = e_pos;
  pii = pi;                               
  strcpy(varname, get_varname());
  pi = e_pos;
  type = get_objtype(pi);

  if((UdtCnt > 0) && (type == 0))         
  {
    type = isThisUdt(varname, type);
    udtpi += pii;                       
  }

  switch(type)
  {
    case 0:                                  
      if(callFlag == 0)
      {
        indx = get_vndx(varname);
      }
      else
      {
        indx = get_llvarndx(varname);    
      }
      strcpy(s_holder, Gtbl[indx].Str);
      break;

    case 6:                                  
      indx = get_arrayndx(varname);
      Subscripts = &strArry[indx].sub[0];  
      nDims = strArry[indx].dim;           
      pi = e_pos;
      len = strlen(p_string);
      /* get_paren Start */
      ch = p_string[pi];
      while((strchr("()", ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_paren Stop */
      pi++;
      e_pos = pi;
      offset = get_offset2(Subscripts, nDims, len);
      strcpy(s_holder, strArry[indx].elem[offset]);
      /* get_paren Start */
      ch = p_string[pi];
      while((strchr("()", ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_paren Stop */
      e_pos = pi;
      break;

    case 10:
      e_pos = pi;
      get_UDTstr();
      break;
  }
}
/*---------- end strvar_assgn ----------*/


void dim_strarry(char *varname, int len, int type)
{   int pi, ii, indx, param, subscript, ab_code=34, x=line_ndx;
    unsigned multiplier, size;
    char ch;

    pi = e_pos;

    /*---- string array ----*/
    if(sArryCnt > 0)
    {
        indx = 0;

        while((strcmp(varname, strArry[indx].name) != 0)
                                    && (indx < sArryCnt))
        {   indx++;
        }

        if(indx < sArryCnt)		
        {   a_bort(ab_code, x);
        }
    }
    /* --- dynamically create array structures --- */

    if(sArryCnt == 0)
    {
        size = 1;
        strArry = malloc(size * sizeof(struct string_array));
    }
    else
    {
        size = sArryCnt + 1;
        strArry = realloc(strArry, 
                 size * sizeof(struct string_array));
    }

    /**/
    strcpy(strArry[sArryCnt].name, varname);
    param = get_paramsCount(pi, len);	
    strArry[sArryCnt].dim = param;
    Sav_ObjName(varname, type, param);

    /**/
    /* get_paren Start */
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_paren Stop */
    pi++;
    e_pos = pi;
    multiplier = 1;

    for(indx=0; indx < param; indx++)
    {
        subscript = (int) get_avalue();
        strArry[sArryCnt].sub[indx] = subscript;
        multiplier = multiplier * subscript;
        pi = e_pos;
        /* get_digit Start */
        ch = p_string[pi];
        while((isdigit(ch) == 0) && (pi < len))
        {
          pi++;
          ch = p_string[pi];
        }
        /* get_digit Stop */
        e_pos = pi;
    }

    strArry[sArryCnt].elem = malloc(multiplier * sizeof(char *));

    /* initialize array */
    for(ii=0; ii < multiplier; ii++)
    {
        strArry[sArryCnt].elem[ii] = malloc(1 * sizeof(char));
    }

    sArryCnt++;					

}
/*------- end dim_strarry -------*/


void reuse_strarry(char *name, int type)
{   char varname[VAR_NAME];             
    int ndx, indx;


    varname[0] = '\0';
    indx = get_arrayndx(varname);
    ndx = 0;

    while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != '\0'))
    {   ndx++;
    }

    strcpy(ObjIndx[ndx], name);
    ObjType[ndx][0] = type;

    strcpy(varname, name);
    strcpy(strArry[indx].name, varname);

    redim_strarry(varname);

    fre_str--;

}
/*------- end reuse_strarry -------*/



void parse_sa(char *varname)
{   char temp[BUFSIZE], ch;
    int pi, len, indx, nDims, offset;
    int *Subscripts;
    unsigned size;


    indx = get_arrayndx(varname);

    len = strlen(p_string);
    pi = e_pos;
    /* get_paren Start */
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_paren Stop */
    pi++;
    e_pos = pi;

    Subscripts = &strArry[indx].sub[0];  
    nDims = strArry[indx].dim;           

    offset = get_offset2(Subscripts, nDims, len);

    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;

    Match('=');         

    strcpy(temp, str_express());

    size = strlen(temp);    
    size++;
    strArry[indx].elem[offset] = realloc(strArry[indx].elem[offset], 
                                              size * sizeof(char));

    strcpy(strArry[indx].elem[offset], temp);

}
/*---------- end parse_strarry ----------*/



void redim_strarry(char *varname)
{   int pi, len, ii, ndx, indx, param, subscript;
    unsigned multiplier;
    char ch;

    indx = get_arrayndx(varname);
    param = strArry[indx].dim;
    multiplier = 1;

    /* --- free existing array structure --- */
    for(ii=0; ii < param; ii++)
    {
        subscript = strArry[indx].sub[ii];
        multiplier = multiplier * subscript;
    }

    multiplier--;

    for(ii=multiplier; ii >= 0; ii--)
    {
        if(strArry[indx].elem[ii] != NULL)
        {
            free(strArry[indx].elem[ii]);
        }
    }

    /* --- dynamically recreate array structures --- */
    pi = e_pos;
    len = strlen(p_string);
    /* get_paren Start */
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_paren Stop */
    pi++;
    e_pos = pi;
    /**/
    param = get_paramsCount(pi, len);    
    strArry[indx].dim = param;
    set_ObjectParam(varname, param);
    /**/
    e_pos = pi;
    multiplier = 1;

    for(ii = 0; ii < 10; ii++)
    {                                    
        strArry[indx].sub[ii] = '\0';
    }

    for(ndx=0; ndx < param; ndx++)
    {
        subscript = (int) get_avalue();
        strArry[indx].sub[ndx] = subscript;
        multiplier = multiplier * subscript;
        pi = e_pos;
        /* get_digit Start */
        ch = p_string[pi];
        while((isdigit(ch) == 0) && (pi < len))
        {
          pi++;
          ch = p_string[pi];
        }
        /* get_digit Stop */
        e_pos = pi;
    }

    strArry[indx].elem = realloc(strArry[indx].elem, 
                       multiplier * sizeof(char *));

    /* initialize array */
    for(ii=0; ii < multiplier; ii++)
    {
        strArry[indx].elem[ii] = malloc(1 * sizeof(char));
    }

}
/*------- end redim_strarry -------*/



void erase_strArray(char *varname)
{   int indx, params, ii, multiplier, subscript;


    indx = get_arrayndx(varname);

    params = strArry[indx].dim;
    multiplier = 1;

    for(ii=0; ii < params; ii++)
    {
        subscript = strArry[indx].sub[ii];
        multiplier = multiplier * subscript;
    }

    multiplier--;

    for(ii=multiplier; ii > 0; ii--)
    {
        free(strArry[indx].elem[ii]);
    }
    strArry[indx].name[0] = '\0';

    for(ii = 0; ii < 10; ii++)
    {                                   
        strArry[indx].sub[ii] = '\0';
    }

    /**/
    indx = 0;

    while((indx < ObjNdxCnt) && (strcmp(varname, ObjIndx[indx]) != 0))
    {   indx++;
    }

    ObjIndx[indx][0] = '\0';
    ObjType[indx][0] = 0;
    ObjType[indx][1] = 0;

    fre_str++;                    

}
/*------- end erase_strArray -------*/


/* bxbasic.c : structs.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011 */


/***********************
   variable types:
    int    = no symbol,
    long   = %,
    float  = !,
    double = #,
    string = $
  ---------------
   array types:
    long   = %,
    float  = !,
    double = #,
    string = $
***********************/



double get_UDTlfd(char *name)
{
    char varname[VAR_NAME];
    char ch, *ptr;
    int pi, len, ndx, indx, vcount, offset, type;

    long lvalue;
    float fvalue;
    double dvalue;


    ndx = get_UDTndx();                         

    len = strlen(name);
    pi = e_pos - len;
    pi--;
    pi += udtpi;
    pi++;

    e_pos = pi;
    strcpy(varname, get_varname());	        
    pi = e_pos;
    pi++;                                   
    e_pos = pi;

    vcount = UDT[ndx].numVars;         

    indx = get_UdtvNamIdx(varname, ndx, vcount);

    offset = UDT[ndx].offset[indx];
    type = UDT[ndx].type[indx];

    ptr = UDT[ndx].data;
    ptr += offset;

    switch(type)
    {
        case 2:           /* lval2 = *(unsigned long *) &myarray[5]; */
            lvalue = *(unsigned long *) ptr;
            dvalue = (double) lvalue;
            break;
        case 3:           /* fval2 = *(float *) &myarray[9]; */
            fvalue = *(float *) ptr;
            dvalue = (double) fvalue;
            break;
        case 4:           /* dval2 = *(double *) &myarray[13]; */
            dvalue = *(double *) ptr;
            break;
    }

    return dvalue;
}
/*------ end get_UDTlfd ------*/



double get_Uval(char *name)
{
    char varname[VAR_NAME];
    char ch, *ptr;
    int pi, len, ndx, indx, vcount, offset;

    int ivalue;
    double dvalue;


    ndx = get_UDTndx();                    

    len = strlen(name);
    pi = e_pos - len;
    pi += udtpi;
    pi++;
    e_pos = pi;
    strcpy(varname, get_varname());	        

    vcount = UDT[ndx].numVars;         

    indx = get_UdtvNamIdx(varname, ndx, vcount); 

    offset = UDT[ndx].offset[indx];
    ptr = UDT[ndx].data;
    ptr += offset;

    ivalue = *(unsigned int *) ptr;
    dvalue = (double) ivalue;

    return dvalue;
}
/*------ end get_UDTval ------*/



void get_UDTstr()
{
    char varname[VAR_NAME];
    char ch, *ptr;
    int pi, ndx, indx, vcount, offset, size;

    ndx = get_UDTndx();                     
    pi = udtpi;
    pi++;
    e_pos = pi;
    strcpy(varname, get_varname());	        
    vcount = UDT[ndx].numVars;         
    indx = get_UdtvNamIdx(varname, ndx, vcount); 
    offset = UDT[ndx].offset[indx];
    size = UDT[ndx].size[indx];

    /* --- make string assignment --- */
    ptr = UDT[ndx].data;
    ptr += offset;
    memcpy(s_holder, ptr, size * sizeof(char));
}
/*------ end get_UDTstr ------*/


void parse_UDTstr()
{
    char temp[BUFSIZE], varname[VAR_NAME];
    char ch, *ptr;
    int pi, ndx, indx, vcount, offset, size;


    ndx = get_UDTndx();                     

    pi = udtpi;
    pi++;
    e_pos = pi;
    strcpy(varname, get_varname());	        
    pi = e_pos;
    vcount = UDT[ndx].numVars;         

    indx = get_UdtvNamIdx(varname, ndx, vcount); 

    offset = UDT[ndx].offset[indx];

    if(IsEqu(pi) == 0)                           
    {
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
    }

    /* --- now get assignment string --- */
    Match('=');

    strcpy(temp, str_express());

    /* --- make string assignment --- */
    size = strlen(temp);
    size++;
    ptr = UDT[ndx].data;
    ptr += offset;

    memcpy(ptr, &temp, size * sizeof(char));
}
/*------ end parse_UDTstr ------*/



void assn_UDTval()
{
    char varname[VAR_NAME];
    char *ptr;
    int pi, ndx, indx, vcount, type, offset=0;

    int    iresult;
    long   lresult;
    float  fresult;
    double dresult;


    ndx = get_UDTndx();                    

    pi = udtpi;
    pi++;
    e_pos = pi;
    strcpy(varname, get_varname());	        
    pi = e_pos;
    vcount = UDT[ndx].numVars;         

    indx = get_UdtvNamIdx(varname, ndx, vcount); 

    type = UDT[ndx].type[indx];
    offset = UDT[ndx].offset[indx];
    ptr = UDT[ndx].data;
    ptr += offset;

    if(IsEqu(pi) == 0)                           
    {
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
    }

    Match('=');                                  

    switch(type)
    {                                  
        case 1:                        
            iresult = (int) rdp_main();
            memcpy(ptr, &iresult, sizeof(unsigned int));
            break;
        case 2:
            lresult = (long) rdp_main();
            memcpy(ptr, &lresult, sizeof(unsigned long));
            break;
        case 3:
            fresult = (float) rdp_main();
            memcpy(ptr, &fresult, sizeof(float));
            break;
        case 4:
            dresult = (double) rdp_main();
            memcpy(ptr, &dresult, sizeof(double));
            break;
    }
}
/*------ end assn_UDTval ------*/



int get_UdtvNamIdx(char *Name, int Ndx, int Cnt)
{
    int indx=0;
    int ab_code=132, x=line_ndx;


    while((indx < Cnt) && (strcmp(Name, UDT[Ndx].varNames[indx]) != 0))
    {
        indx++;
    }

    if(indx >= Cnt)
    {
        a_bort(ab_code, x);                 
    }

    return indx;
}
/*------ end get_UdtvNamIdx ------*/



int get_UDTndx()
{
    char udtName[VAR_NAME];
    int ndx;


    strcpy(udtName, udtTmpName);     
    ndx = 0;

    while((ndx < UdtCnt) && (strcmp(udtName, UDT[ndx].udtName) != 0))
    {
        ndx++;
    }

    return ndx;
}
/*------ end get_UDTndx ------*/



int isThisUdt(char *varname, int type)
{
    char udtName[VAR_NAME];
    char ch, dot='.';
    int pi, len, ndx;

    strcpy(udtName, varname);
    len = strlen(udtName);
    pi = 0;
    ch = udtName[pi];

    while((ch != dot) && (pi < len))
    {
        pi++;
        ch = udtName[pi];
    }

    if(ch == dot)
    {
        udtName[pi] = '\0';
        ndx = 0;

        while((ndx < UdtCnt) && (strcmp(udtName, UDT[ndx].udtName) != 0))
        {
            ndx++;
        }

        if(ndx < UdtCnt)
        {
            type += 10;
            udtpi = pi;
            strcpy(udtTmpName, udtName);
        }
    }

    return type;
}
/*------ end isThisUdt ------*/



void struct_Udt()
{   char varname[VAR_NAME], udtName[VAR_NAME], ch;
    char **elementName;
    int *elemType, *elemSize, *elemOffset;
    int pi, len, ii, indx, vcount=0;
    int thistoken=0, curline=line_ndx, ndx=line_ndx;
    int type, varsize, offset=0, length;
    int ab_code=131, x=line_ndx;
    int result;
    unsigned size;


    len = strlen(p_string);
    pi = e_pos;
    /* get_alpha Start */
    ch = p_string[pi];
    while((isalpha(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_alpha Stop */
    if(pi == len)                                
    {
        a_bort(ab_code, x);
    }

    e_pos = pi;

/* ---------- begin collecting struct info -------------- */

    strcpy(udtName, get_varname());	            
    pi = e_pos;

    indx = 0;                          
    if(UdtCnt > 0)                     
    {
        while((strcmp(udtName, UDT[indx].udtName) != 0) && (indx < UdtCnt))
        {
            indx++;
        }

        if(indx < UdtCnt)                        
        {
            ab_code = 133;
            a_bort(ab_code, x);
        }
    }

    if(UdtCnt == 0)
    {
        size = 1;                                
        UDT = malloc(size * sizeof(struct tag_UDT));
    }
    else
    {
        size = UdtCnt + 1;                       
        UDT = realloc(UDT, size * sizeof(struct tag_UDT));
    }

    while(thistoken != 127)
    {
        ndx++;
        thistoken = byte_array[ndx];

        if(thistoken == 1)
        {
            vcount++;                            
        }
    }


    ndx = curline + 1;
    thistoken=0;
    size = vcount;
    elementName = malloc(size * sizeof(char *));
    size = VAR_NAME;

    for(ii=0; ii < vcount; ii++)
    {
        elementName[ii] = malloc(size * sizeof(char));
    }

    size = vcount;
    elemType = malloc(size * sizeof(int *));
    elemSize = malloc(size * sizeof(int *));
    elemOffset = malloc(size * sizeof(int *));

    for(ii=0; ii < vcount; ii++)
    {
        thistoken = byte_array[ndx];

        if(thistoken == 1)
        {
            strcpy(p_string, array1[ndx]);
            e_pos = 0;
            strcpy(varname, get_varname());      
            strcpy(elementName[ii], varname);
            pi = e_pos;

            type = get_objtype(pi);              
            elemType[ii] = type;

            switch(type)
            {
                case 0:
                    len = strlen(p_string);
                    /* get_digit Start */
                    ch = p_string[pi];
                    while((isdigit(ch) == 0) && (pi < len))
                    {
                      pi++;
                      ch = p_string[pi];
                    }
                    /* get_digit Stop */

                    e_pos = pi;
                    varsize = get_avalue();
                    varsize++;
                    elemSize[ii] = varsize;
                    elemOffset[ii] = offset;
                    break;
                case 1:
                    varsize = sizeof(int);
                    elemSize[ii] = varsize;
                    elemOffset[ii] = offset;
                    break;
                case 2:
                    varsize = sizeof(long);
                    elemSize[ii] = varsize;
                    elemOffset[ii] = offset;
                    break;
                case 3:
                    varsize = sizeof(float);
                    elemSize[ii] = varsize;
                    elemOffset[ii] = offset;
                    break;
                case 4:
                    varsize = sizeof(double);
                    elemSize[ii] = varsize;
                    elemOffset[ii] = offset;
                    break;
            }
            offset += varsize;
        }
        ndx++;
    }

    length = offset;

/* ------------------------------------------------------ */

    strcpy(UDT[indx].udtName, udtName);
    UDT[indx].numVars = vcount;

    size = vcount;
    UDT[indx].varNames = malloc(size * sizeof(char *));
    size = VAR_NAME;

    for(ii=0; ii < vcount; ii++)
    {
        UDT[indx].varNames[ii] = malloc(size * sizeof(char));
    }

    for(ii=0; ii < vcount; ii++)
    {
        strcpy(UDT[indx].varNames[ii], elementName[ii]);
    }

    size = vcount;
    UDT[indx].type = malloc(size * sizeof(int));
    UDT[indx].size = malloc(size * sizeof(int));
    UDT[indx].offset = malloc(size * sizeof(int));

    for(ii=0; ii < vcount; ii++)
    {
        UDT[indx].type[ii] = elemType[ii];
        UDT[indx].size[ii] = elemSize[ii];
        UDT[indx].offset[ii] = elemOffset[ii];
    }

    UDT[indx].length = length;
    size = length;
    UDT[indx].data = malloc(size * sizeof(char));

    free(elemOffset);
    free(elemSize);
    free(elemType);
    free(elementName);

    UdtCnt++;                       

    line_ndx = ndx;

}
/*------ end struct_Udt ------*/


/* bxbasic : Subs.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011 */


void do_declare()
{   char varname[VAR_NAME], ch;                   
    int pi, len, param;
    int ab_code=42, xx = line_ndx;


    len = strlen(p_string);
    pi = e_pos;
    strcpy(varname, get_varname());          

    pi = e_pos;
    pi = iswhite(pi);
    e_pos = pi;

    if(strcmp(varname, "SUB") == 0)
    {
        strcpy(varname, get_varname());
        pi = e_pos;
        /* get_paren Start */
        ch = p_string[pi];
        while((strchr("()", ch) == 0) && (pi < len))
        {
          pi++;
          ch = p_string[pi];
        }
        /* get_paren Stop */

        param = get_paramsCount(pi, len);	

        save_sub(varname, param);           
    }
    else if(strcmp(varname, "FUNCTION") == 0)
    {
        /*strcpy(varname, get_varname());*/
        ab_code = 43;
        a_bort(ab_code, xx);
    }
    else
    {   a_bort(ab_code, xx);            
    }


}
/*------- end do_declare -------*/



void save_sub(char *varname, int param)
{   int pi, ndx;                   
    unsigned size;                 

    ndx = subCnt;

    if(ndx == 0)
    {                              
        size = 1;
        SubR = (struct Sub_Routines *) 
               malloc(size * sizeof(struct Sub_Routines));
        Sndx = (struct Sub_Index *) malloc(size * sizeof(struct Sub_Index));
    }
    else
    {                            
        size = ndx + 1;
        SubR = (struct Sub_Routines *) 
                 realloc(SubR, size * sizeof(struct Sub_Routines));
        Sndx = (struct Sub_Index *) 
                 realloc(Sndx, size * sizeof(struct Sub_Index));
    }
    /**/
    strcpy(SubR[ndx].SubName, varname);    
    strcpy(Sndx[ndx].SubName, varname);    

    SubR[ndx].paramCnt = param;            
    Sndx[ndx].index = ndx;                 

    pi = 0;
    stor_paramType(pi, ndx, param);     

    subCnt++;                           

}
/*------- end save_sub -------*/



void stor_paramType(int pi, int ndx, int param)
{   int len, ii, type; 
    char ch;              


    len = strlen(p_string); 
    /* get_paren Start */
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_paren Stop */
 
    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_alnum Stop */

    if(param > 0)
    {
        for(ii = 0; ii < param; ii++)
        {
            pi = while_isalnum(pi);
            type = get_objtype(pi);
            SubR[ndx].paramType[ii] = type;
            /**/
            /* get_alnum Start */
            ch = p_string[pi];
            while((isalnum(ch) == 0) && (pi < len))
            {
              pi++;
              ch = p_string[pi];
            }
            /* get_alnum Stop */
        }
    }
    else
    {
        for(ii = 0; ii < 10; ii++)
        {
            SubR[ndx].paramType[ii] = '\0';
        }
    }
}
/*------- end stor_paramType -------*/



void do_callsub()
{   char varname[VAR_NAME];              
    int pi, ab_code=38, xx = line_ndx;


    if(subCnt == 0)
    {   a_bort(ab_code, xx);             
    }

    pi = 0;
    e_pos = pi;
    strcpy(varname, get_varname());			

    push_call(varname);                     

    callFlag++;
    e_pos = 0;

    go_to();
}
/*------- end do_callsub -------*/


void push_call(char *varname)
{   int ndx, addr, params, type, sndx;    
    int ab_code=39, xx = line_ndx;
    unsigned size;


    ndx = 0;                              

    while((ndx < subCnt) && (strcmp(varname, Sndx[ndx].SubName) != 0))
    {
        ndx++;
    }

    if(ndx >= subCnt)
    {   a_bort(ab_code, xx);             
    }

    addr = Sndx[ndx].index;              
    params = SubR[addr].paramCnt;       

    if(params > 0)                          
    {                                       
        size = PARAM_STK;                   
     pStk = (struct Push_Stack *) malloc(size * sizeof(struct Push_Stack));

        ndx = 0;

        for(ndx = 0; ndx < params; ndx++)
        {
            type = SubR[addr].paramType[ndx];   
            sndx = push_params();              

            switch(type)
            {
                case 0:
                    size = strlen(Gtbl[sndx].Str);
                    size++;

                    pStk[ndx].Str = malloc(size * sizeof(char));
                    strcpy(pStk[ndx].Str, Gtbl[sndx].Str);
                    pStk[ndx].Typ = 0;
                    break;
                case 1:
                    pStk[ndx].Int = Gtbl[sndx].Int;
                    pStk[ndx].Typ = 1;
                    break;
                case 2:
                    pStk[ndx].Lng = Gtbl[sndx].Lng;
                    pStk[ndx].Typ = 2;
                    break;
                case 3:
                    pStk[ndx].Flt = Gtbl[sndx].Flt;
                    pStk[ndx].Typ = 3;
                    break;
                case 4:
                    pStk[ndx].Dbl = Gtbl[sndx].Dbl;
                    pStk[ndx].Typ = 4;
                    break;
                default:
                    printf("\nerror! push_call\n");
                    exit(0);
            }
        }
    }

    if(subCnt == 0)
    {                           
        size = 1;
        rStk = (struct Return_Stack *) 
                 malloc(size * sizeof(struct Return_Stack));
    }
    else
    {
        size = ActvSubs + 1;
        rStk = (struct Return_Stack *) 
                 realloc(rStk, size * sizeof(struct Return_Stack));
    }

    ndx = ActvSubs;
    rStk[ndx].ret_Addr = line_ndx;       

}
/*------- end push_call -------*/



int push_params()
{   char varname[VAR_NAME], ch;
    int pi, len, ndx, thsSb, indx;
    int ab_code=44, xx = line_ndx;


    pi = e_pos;                 
    len = strlen(p_string);     

    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }
    /* get_alnum Stop */
  
    e_pos = pi;                     
    strcpy(varname, get_varname());     

    if(varname[0] == '\0')
    {                               
        ab_code = 45;
        a_bort(ab_code, xx);
    }

    ndx = glb_vct - 1;             
    thsSb = ActvSubs;                     
    indx = Gtbl[ndx].ActSub;             

    while((ndx > 0) && (strcmp(varname, Gtbl[ndx].Nam) != 0) 
                                         && (thsSb == indx))
    {                                          
        ndx--;                                 
        indx = Gtbl[ndx].ActSub;              
    }

    if(strcmp(varname, Gtbl[ndx].Nam) != 0)
    {                                    
        strcpy(s_holder, varname);
        a_bort(ab_code, xx);
    }

    return ndx;
}
/*------- end push_params -------*/





void enter_sub()
{   char varname[VAR_NAME], xp_string[BUFSIZE], ch;
    int pi, len, ii, type, xpi, ndx, addr, params;
    int ab_code=39, xx = line_ndx;
    unsigned size;


    ActvSubs++;                  

    pi = 0;
    e_pos = pi;
    strcpy(varname, get_varname());			

    ndx = 0;

    while((ndx < subCnt) && (strcmp(varname, Sndx[ndx].SubName) != 0))
    {
        ndx++;
    }

    if(ndx > subCnt)
    {   a_bort(ab_code, xx);             
    }

    addr = Sndx[ndx].index;              
    params = SubR[addr].paramCnt;        

    addr = (ActvSubs - 1);
    rStk[addr].Vrcnt = params;           
    sub_ndx = addr;                      

    pi = e_pos;
    len = strlen(p_string);

    if(params > 0)
    {                                   
        for(ii=0; ii < params; ii++)	
        {
            /* get_alnum Start */
            ch = p_string[pi];
            while((isalnum(ch) == 0) && (pi < len))
            {
              pi++;
              ch = p_string[pi];
            }
            /* get_alnum Stop */
            e_pos = pi;
            strcpy(varname, get_varname());

            if(varname[0] == '\0')
            {                            
                ab_code = 46;
                a_bort(ab_code, xx);
            }

            strcpy(xp_string, p_string); 
            xpi = e_pos;

            ndx = get_lvarndx(varname);  

            type = pStk[ii].Typ;         
                                         
            switch(type)
            {
                case 0:
                    size = strlen(pStk[ii].Str);
                    size++;

                    Gtbl[ndx].Str = malloc(size * sizeof(char));
                    strcpy(Gtbl[ndx].Str, pStk[ii].Str);

                    break;
                case 1:
                    Gtbl[ndx].Int = pStk[ii].Int;

                    break;
                case 2:
                    Gtbl[ndx].Lng = pStk[ii].Lng;

                    break;
                case 3:
                    Gtbl[ndx].Flt = pStk[ii].Flt;

                    break;
                case 4:
                    Gtbl[ndx].Dbl = pStk[ii].Dbl;

                    break;
            }

            Gtbl[ndx].ActSub = ActvSubs;  

            strcpy(p_string, xp_string);
            pi = xpi;
        }

        free(pStk);                      
    }
}
/*------- end enter_sub -------*/



void do_retsb()
{   int ndx;
    unsigned size;


    garbage_col();                 

    ActvSubs--;                   
    callFlag--;

    ndx = ActvSubs;
    line_ndx = rStk[ndx].ret_Addr;       

    size = ActvSubs;
    rStk = (struct Return_Stack *) 
              realloc(rStk, size * sizeof(struct Return_Stack));

}
/*------- end do_returnsub -------*/


void garbage_col()
{   int ndx, indx, sub, totVars;      
    unsigned size;


    ndx = (ActvSubs - 1);
    totVars = rStk[ndx].Vrcnt;           

    if(totVars > 0)
    {
        indx = glb_vct - 1;
        sub = Gtbl[indx].ActSub;             
        ndx++;

        while((indx > 0) && (sub == ndx))
        {
          /*  free(Gtbl[indx].Str); */
            indx--;                             
            sub = Gtbl[indx].ActSub;          
        }

        size = glb_vct - totVars;     
        Gtbl = (struct Global_Table *) 
               realloc(Gtbl, size * sizeof(struct Global_Table));
    }

    glb_vct = glb_vct - totVars;
}
/*------- end grbge_cllctr -------*/



/* bxbasic : Utility.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011 */


char *global_var(char *name)
{   
  static char varname[VAR_NAME];
  int ii, limit;

  strcpy(varname, name);		
  if(callFlag > 0)
  {
    ii = 0;
    limit = (ObjNdxCnt-1);
    while((ii <= limit) && (strcmp(varname, ObjIndx[ii]) != 0))
    {
      ii++;
    }
    if(ii == ObjNdxCnt)
    {
      strcpy(varname, local_var(varname));
    }
  }
  return varname;
}
/*------- end global_var -------*/


char *local_var(char *name)
{
  static char varname[VAR_NAME];
  int ii, idx;

  strcpy(varname, name);		
  if(callFlag > 0)
  {
    idx = lcl_cnt - 1;
    ii = thissub_vars[submax_cnt];
    while((ii > 0) && (strcmp(varname, Ltbl[idx].Nam) != 0))
    {
      ii--;
    }
  }
  return varname;
}
/*------- end local_var -------*/


void InitObj()			
{
  int ndx;
  unsigned size;

  if(ObjNdxCnt == 0)
  {
    ndx = ObjNdxCnt;
    ObjNdxCnt++;
    size = ObjNdxCnt;
    ObjIndx = malloc(size * sizeof(char *));
    ObjSubVar = malloc(size * sizeof(char *));
    ObjType = malloc(size * sizeof(int *));
    size = VAR_NAME;
    ObjIndx[ndx] = malloc(size * sizeof(char));
    ObjSubVar[ndx] = malloc(size * sizeof(char));
    size = 2;
    ObjType[ndx] = malloc(size * sizeof(int));
  }
  else
  {
    ndx = ObjNdxCnt;
    ObjNdxCnt++;
    size = ObjNdxCnt;
    ObjIndx = realloc(ObjIndx, size * sizeof(char *));
    ObjSubVar = realloc(ObjSubVar, size * sizeof(char *));
    ObjType = realloc(ObjType, size * sizeof(int *));
    size = VAR_NAME;
    ObjIndx[ndx] = malloc(size * sizeof(char));
    ObjSubVar[ndx] = malloc(size * sizeof(char));
    size = 2;
    ObjType[ndx] = malloc(size * sizeof(int));
  }
}
/*---------- end InitObj ----------*/


void Sav_ObjName(char *varname, int type, int parm)
{   
  int ndx=0, ibool=0;

  InitObj();
  ndx = ObjNdxCnt - 1;
  strcpy(ObjIndx[ndx], varname);
  ObjType[ndx][0] = type;
  ObjType[ndx][1] = parm;
  if((type == 11) || (callFlag == 0))
  {
    ObjSubVar[ndx][0] = '\0';
  }
  else
  {
    strcpy(ObjSubVar[ndx], SubName);
  }
}
/*---------- end Sav_ObjName ----------*/


int get_ObjectType(char *varname)	
{
  int ndx=0, type=-1;

  while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != 0))
  {
    ndx++;
  }
  if(ndx < ObjNdxCnt)
  {
    type = ObjType[ndx][0];
  }
  return type;
}
/*---------- end get_ObjectType ----------*/


void set_ObjectParam(char *varname, int param)	
{   
  int ndx=0;

  while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != 0))
  {
    ndx++;
  }
  ObjType[ndx][1] = param;
}
/*---------- end set_ObjectParam ----------*/


int get_arrayndx(char *varname)				
{   
  int indx=0, ab_code=35, x=line_ndx;

  while((strcmp(varname, strArry[indx].name) != 0) && (indx < sArryCnt))
  {
    indx++;
  }
  if(indx == sArryCnt)             
  {
    printf("\n\nArray:\"%s\"", varname);
    a_bort(ab_code, x);
  }
  return indx;
}
/*---------- end get_arrayndx ----------*/


int get_iarrayndx(char *varname)				
{   
  int indx=0, ab_code=35, x=line_ndx;

  while((strcmp(varname, intArry[indx].name) != 0) && (indx < iArryCnt))
  {
    indx++;
  }
  if(indx == iArryCnt)              
  {
    printf("\n\nArray:\"%s\"", varname);
    a_bort(ab_code, x);
  }
  return indx;
}
/*---------- end get_iarrayndx ----------*/


int get_farrayndx(char *varname)				
{   
  int indx=0, ab_code=35, x=line_ndx;

  while((strcmp(varname, fltArry[indx].name) != 0) && (indx < fArryCnt))
  {
    indx++;
  }
  if(indx == fArryCnt)              
  {
    printf("\n\nArray:\"%s\"", varname);
    a_bort(ab_code, x);
  }
  return indx;
}
/*---------- end get_farrayndx ----------*/


int get_darrayndx(char *varname)				
{   
  int indx=0, ab_code=35, x=line_ndx;

  while((strcmp(varname, dblArry[indx].name) != 0) && (indx < dArryCnt))
  {
    indx++;
  }
  if(indx == dArryCnt)              
  {
    printf("\n\nArray:\"%s\"", varname);
    a_bort(ab_code, x);
  }
  return indx;
}
/*---------- end get_darrayndx ----------*/


int get_offset2(int *subScripts, int nDims, int len)
{   
  int pi, i, ii, this_DIM, next_Param, offset;  
  char ch;    

  next_Param = (int) get_avalue();
  next_Param--;
  offset = next_Param;
  ii=1;
  for(i=1; i < nDims; i++)
  {
    this_DIM = subScripts[i];
    pi = e_pos;
    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_alnum Stop */
    e_pos = pi;
    next_Param = (int) get_avalue();
    next_Param--;
    offset = (offset * this_DIM) + next_Param;
    ii++;
  }
  return offset;
}
/*------ end get_offset2 ------*/


int get_paramsCount(int pi, int len)
{   
  char ch;
  int xcnt=0;

  ch = p_string[pi];
  while((ch != ')') && (pi < len))		
  {
    /* get_alnum Start */
    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {
      pi++;
      ch = p_string[pi];
    }
    /* get_alnum Stop */
    ch = p_string[pi];
    if(isalnum(ch))
    {
      xcnt++;
      /* get_NextOp Start */
      pi = while_isalnum(pi);
      pi = iswhiter(pi);
      /* get NextOp Stop */
      ch = p_string[pi];
    }
  }
  return xcnt;
}
/*---------- end get_paramsCount ----------*/


int get_objtype(int pi)
{
  char ch, chx;
  int type=-1;

  ch = p_string[pi];
  chx = p_string[(pi+1)];
  if(ch == '$')
  {
    type = 0;
    if(chx == '(')					
    {
      type = 6;					
    }
  }
  else
  {
    type = get_Nvtype(pi);
    if(chx == '(')                  
    {
      switch(ch)
      {
        case '%':
          type = 7;			
          break;

        case '!':
          type = 8;			
          break;
 
        case '#':
          type = 9;			
          break;
      }
    }
  }
  return type;
}
/*------- end get_objtype --------*/


int get_Arrytype(int pi)
{   
  char ch, chx;
  int type=0;

  pi = iswhite(pi);
  ch = p_string[pi];
  chx = p_string[(pi+1)];
  if(ch == '$')
  {
    if(chx == '(')					
    {
      type = 6;					
    }
  }
  else if(strchr("%!#", ch))
  {
    if(chx == '(')				
    {
      switch(ch)
      {
        case '%':
          type = 7;			
          break;
   
        case '!':
          type = 8;			
          break;

        case '#':
          type = 9;			
          break;
      }
    }
  }
  return type;
}
/*------- end get_Arrytype --------*/


int get_vtype(int pi)
{   
  char ch;
  int type=0, f_flag=0;

  pi = while_isalnum(pi);
  ch = p_string[pi];
  if(ch == '$')
  {
    type = 3;			
  }
  else if(strchr(" =<>%!#;", ch))
  {
    type = 1;			
  }
  else if(ch == '\n')     
  {
    type = 1;
  }
  else if(ch == '(')                  
  {
    f_flag = if_eof();             
    f_flag--;
    if(f_flag == s_pos)             
    {
      type = 5;
      e_pos = pi;
    }
  }
  return type;
}
/*------- end get_vtype --------*/


int get_Nvtype(int pi)
{   
  char ch;
  int type=0;

  pi = while_isalnum(pi);
  ch = p_string[pi];
  if(strchr(":;, <>)=+*-/\n", ch))
  {
    type = 1;		
  }
  else if(ch == '%')
  {
    type = 2;		
  }
  else if(ch == '!')
  {
    type = 3;		
  }
  else if(ch == '#')
  {
    type = 4;		
  }
  else if(ch == '~')
  {
    type = 5;		
  }
  return type;
}
/*------- end get_Nvtype --------*/


int isthis_anarray(int pi, int stlen)
{   
  char ch;

  /* get_NextOp Start */
  pi = while_isalnum(pi);
  pi = iswhiter(pi);
  /* get_NextOp Stop */
  ch = p_string[pi];
  if(strchr("$%!#~", ch) != 0)
  {
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
  }
  if(ch != '(')
  {
    pi = 0;
  }
  return pi;
}
/*---------- end isthis_anarray ----------*/


int iswhite(int pi)
{   
  char ch;

  ch = p_string[pi];                  
  while(isspace(ch) != 0)                            
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}
/*-------- end iswhite ----------*/


int iswhiter(int pi)
{   
  char ch;

  ch = p_string[pi];                   
  while(ch == ' ')                            
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}
/*-------- end iswhiter ---------*/


void clr_arrays()
{   
  int ii;    

  for(ii=0; ii < nrows; ii++)
  {
    free(label_nam[ii]);
    free(array1[ii]);
  }
  free(label_nam);
  free(byte_array);
  free(array1);
}
/*-------- end clr_arrays ----------*/


int find_strng(char *tmp)
{   
  char ch, cx;
  char temp[TOKEN_LEN], xxstring[TOKEN_LEN];
  int pi, i, mark, len, len2;

  strcpy(xxstring, tmp);
  len = strlen(p_string);        
  len2 = strlen(xxstring);
  pi = s_pos;                         
  ch = p_string[pi];
  cx = xxstring[0];             
  while(pi < len)
  {
    while((ch != cx) && (pi < len))        
    {
      if(ch == '\"')            
      {
        pi++;                    
        ch = p_string[pi];
        while(ch != '\"')
        {
          pi++;
          ch = p_string[pi];
         }
       }
       pi++;
       ch = p_string[pi];
     }
     if((pi == len) || (pi > len))
     {
       mark = 0;       
       return mark;
     }
     mark = pi;         
     for(i=0; i < len2; i++)         
     {
       temp[i] = ch;
       pi++;
       ch = p_string[pi];
     }
     temp[i] = '\0';
     if(strcmp(temp, xxstring) != 0)      
     {
       pi = (mark+1);              
       ch = p_string[pi];
     }
     else
     {
       mark++;
       pi = len;
     }
  }
  return mark;
}
/*-------- end find_strng ---------*/


int while_dd(int pi)            
{
  char ch;

  ch = p_string[pi];
  while((isalnum(ch) != 0) || (strchr("._", ch)))
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}
/*------ end while_isalnum_dd ------*/


int while_isalnum(int pi)
{
  char ch;

  ch = p_string[pi];
  while(isalnum(ch))
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}
/*-------- end while_isalnum ---------*/


int get_quote(int pi, int len)
{   
  char ch;

  pi++;
  ch = p_string[pi];
  while((ch != '\"') && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  if(ch == '\"')
  {
    pi++;
  }
  return pi;
}
/*-------- end get_quote ---------*/


void get_pnam()
{   
  char ch;
  int pi, indx, len, si;

  len = strlen(p_string);
  pi = e_pos;
  ch = p_string[pi];
  if(ch == '\"')
  {
    si = 0;
    pi++;
    ch = p_string[pi];
    while((ch != '\"') && (pi < len))
    {
      s_holder[si] = ch;
      si++;
      pi++;
      ch = p_string[pi];
    }
    s_holder[si] = '\0';
    e_pos = pi;
  }
  else
  {
    strcpy(s_holder, get_varname());
    indx = get_strndx(s_holder);       
    strcpy(s_holder, Gtbl[indx].Str);
  }
  /* return param/varname in s_holder */
}
/*---------- end get_param_name ----------*/


/* bxbasic : Variable.c : alpha version.20.3.1 */
/* Copyright:(c) sarbayo, 2001-2011 */
/* CMSBASIC port, by tchandler48@gmail.com */


/* variable types:
    int    = no symbol,
    long   = %,
    float  = !,
    double = #,
    string = $
   ---------------
   array types:
    long   = %,
    float  = !,
    double = #,
    string = $
*/

void do_dim_var()
{   
  int test, pi, len;           

  pi = 0;
  e_pos = pi;
  len = strlen(p_string);
  test = isthis_anarray(pi, len);
  if(test == 0)                 
  {
    dim_var();                
  }
  else
  {                             
    do_dim();
  }
}
/*---------- end do_dim_var -----------*/


void dim_var()
{   
  char ch;
  int pi, len;

  len = strlen(p_string);
  pi = e_pos;
  ch = p_string[pi];
  while((ch != '\n') && (pi < len))
  {
    if(isalpha(ch))
    {
      parse_dim();
      pi = e_pos;
    }
    else
    {
      /* get_alpha Start */
      ch = p_string[pi];
      while((isalpha(ch) == 0) && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
      /* get_alpha Stop */
      ch = p_string[pi];
      e_pos = pi;
    }
    ch = p_string[pi];
  }
}
/*---------- end dim_var -----------*/


void parse_dim()
{   
  char varname[VAR_NAME], ch;
  int pi, len, ndx=0, type, ab_code=11, x=line_ndx;

  len = strlen(p_string);
  pi = e_pos;
  /* get_alpha Start */
  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }

  /* get_alpha Stop */
  if(pi == len)                     
  {
    a_bort(ab_code, x);
  }
  e_pos = pi;
  strcpy(varname, get_varname());		
  pi = e_pos;
  type = get_objtype(pi);
  e_pos = pi;
  switch(type)
  {
    case 0:						
      dim_gstr(varname);
      break;
 
    case 1:                     
      dim_gint(varname);
      break;

    case 2:						
      dim_glong(varname);
      break;

    case 3:						
      dim_gsingle(varname);
      break;

    case 4:						
      dim_gdouble(varname);
      break;
  }
}
/*-------- end parse_dim ---------*/


void dim_gdouble(char *varname)
{   
  int pi, ndx;

  pi = e_pos;
  ndx = get_var_index(varname);
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Gtbl[ndx].ActSub = ActvSubs;   
  Match('=');					
  Gtbl[ndx].Dbl = (double) rdp_main();
}
/*-------- end dim_gdouble --------*/


void dim_gsingle(char *varname)
{   
  int pi, ndx;

  pi = e_pos;
  ndx = get_var_index(varname);
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Gtbl[ndx].ActSub = ActvSubs;   
  Match('=');					
  Gtbl[ndx].Flt = (float) rdp_main();
}
/*-------- end dim_gsingle --------*/


void dim_glong(char *varname)
{   
  int pi, ndx=0;

  pi = e_pos;
  ndx = get_var_index(varname);
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Gtbl[ndx].ActSub = ActvSubs;   
  Match('=');					
  Gtbl[ndx].Lng = (long) rdp_main();
}
/*-------- end dim_glong --------*/



void dim_gint(char *varname)
{   
  int pi, ndx;               

  pi = e_pos;
  ndx = get_var_index(varname);
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Gtbl[ndx].ActSub = ActvSubs;   
  Match('=');					
  Gtbl[ndx].Int = (int) rdp_main();
}
/*-------- end dim_gint --------*/


void bld_global_table()
{   
  unsigned size;

  if(glb_vct == 0)
  {                            
    glb_vct++;
    size = glb_vct;
    Gtbl = (struct Global_Table *) 
              malloc(size * sizeof(struct Global_Table));
  }
  else
  {                            
    glb_vct++;
    size = glb_vct;
    Gtbl = (struct Global_Table *) realloc(Gtbl, 
                    size * sizeof(struct Global_Table));
  }
}
/*---------- end bld_global_table -----------*/


int get_gvarndx(char *varname)
{   
  int ndx;      

  if(glb_vct > 0)
  {
    ndx = 0;
    while((ndx < glb_vct) && (strcmp(varname, Gtbl[ndx].Nam) != 0))
    {
      ndx++;
    }
    if(ndx == glb_vct)
    {
      bld_global_table();             
      ndx = glb_vct - 1;
      strcpy(Gtbl[ndx].Nam, varname); 
    }
  }
  else
  {
    bld_global_table();
    ndx = glb_vct - 1;
    strcpy(Gtbl[ndx].Nam, varname);     
  }
  return ndx;
}
/*-------- end get_gvarndx --------*/


int get_lvarndx(char *varname)
{   
  int ndx;       

  bld_global_table();
  ndx = glb_vct - 1;
  strcpy(Gtbl[ndx].Nam, varname);     
  return ndx;
}
/*-------- end get_lvarndx --------*/


int get_var_index(char *varname)
{  
  int ndx;                        
                                     
  if(ActvSubs > 0)
  {
    ndx = get_lvarndx(varname);
    rStk[sub_ndx].Vrcnt++;       
  }
  else
  {
    ndx = get_gvarndx(varname);
  }
  return ndx;
}
/*-------- end get_var_index --------*/


void parse_let()
{   
  char varname[VAR_NAME], ch;
  int pi, len, ndx=0, type, ab_code=11, x=line_ndx;

  len = strlen(p_string);
  pi = e_pos;
  /* get_alpha Start */
  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < len))
  {
    pi++;
    ch = p_string[pi];
  }
  /* get_alpha Stop */
  if(pi == len)                      
  {
    a_bort(ab_code, x);
  }
  e_pos = pi;
  strcpy(varname, get_varname());	   
  pi = e_pos;
  type = get_objtype(pi);
  e_pos = pi;
  if((UdtCnt > 0) && (type < 6))     
  {
    type = isThisUdt(varname, type);
  }
  switch(type)
  {
    case 0:                        
      parse_st(varname);
      break;
  
    case 1:                        
      let_int(varname);
      break;

    case 2:                        
      let_long(varname);
      break;

    case 3:                       
      let_single(varname);
      break;

    case 4:                        
      let_double(varname);
      break;
  
    case 5:                        
      break;
 
    case 6:                       
      parse_sa(varname);
      break;

    case 7:                        
      parse_intarry(varname);
      break;
 
    case 8:                        
      parse_fltarry(varname);
      break;

    case 9:                        
      parse_dblarry(varname);
      break;

    case 10:                       
      parse_UDTstr();
      break;

    case 11:                       
    case 12:                       
    case 13:                       
    case 14:                      
      assn_UDTval();
      break;
  }
}
/*-------- end parse_let ---------*/


void let_double(char *varname)
{   
  int pi, ndx;

  pi = e_pos;
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Match('=');					
  Gtbl[ndx].Dbl = (double) rdp_main();
}
/*-------- end let_double --------*/


void let_single(char *varname)
{   
  int pi, ndx;

  pi = e_pos;
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Match('=');					
  Gtbl[ndx].Flt = (float) rdp_main();
}
/*-------- end let_single --------*/


void let_long(char *varname)
{   
  int pi, ndx;
  long lvalue;
  double dvalue;

  pi = e_pos;
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Match('=');					
  Gtbl[ndx].Lng = (long) rdp_main();
}
/*-------- end let_long --------*/


void let_int(char *varname)
{   
  int pi, ndx;

  pi = e_pos;
  if(callFlag == 0)
  {
    ndx = get_vndx(varname);         
  }
  else
  {
    ndx = get_llvarndx(varname);        
  }
  if(IsEqu(pi) == 0)                 
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
  }
  Match('=');					
  Gtbl[ndx].Int = (int) rdp_main();
}
/*-------- end let_int --------*/


int get_vndx(char *varname)
{   
  int ndx, ab_code=13, x=line_ndx;

  if(glb_vct > 0)
  {
    ndx = 0;
    while((ndx < glb_vct) && (strcmp(varname, Gtbl[ndx].Nam) != 0))
    {
      ndx++;
    }
    if(ndx >= glb_vct)
    {
      a_bort(ab_code, x);
    }
  }
  else
  {
    a_bort(ab_code, x);
  }
  return ndx;
}
/*--------- end get_varndx ----------*/


int get_llvarndx(char *varname)
{  
  int ndx, sndx, sub, ab_code=13, x=line_ndx;
                                              
  if(glb_vct > 0)
  {
    sndx = ActvSubs;
    ndx = (glb_vct - 1);
    sub = Gtbl[ndx].ActSub;               
    while((ndx > 0) && (sub == sndx) && 
              (strcmp(varname, Gtbl[ndx].Nam) != 0))
    {
      ndx--;                             
      sub = Gtbl[ndx].ActSub;           
    }
    if((sub != sndx) || (strcmp(varname, Gtbl[ndx].Nam) != 0))
    {                                      
      ndx = 0;
      sub = Gtbl[ndx].ActSub;           
      while((sub == 0) && (strcmp(varname, Gtbl[ndx].Nam) != 0))
      {
        ndx++;                        
        sub = Gtbl[ndx].ActSub;        
      }
      if((sub != 0) || (strcmp(varname, Gtbl[ndx].Nam) != 0))
      {                                
        a_bort(ab_code, x);
      }
    }
  }
  else
  {
    a_bort(ab_code, x);
  }
  return ndx;
}
/*--------- end get_llvarndx ----------*/


char *get_varname()
{   
  char ch;
  static char varname[VAR_NAME];
  int pi, si=0;

  pi = e_pos;
  ch = p_string[pi];
  while((isalnum(ch) != 0) || (strchr("._", ch)))
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';
  e_pos = pi;
  return varname;
}
/*---------- end get_varname ----------*/


double get_varvalue()
{   
  char varname[VAR_NAME];
  int pi, pii, ndx=0, type;
  int ab_code=13, x=line_ndx;
  double value;

  strcpy(varname, s_holder);
  pi = e_pos;
  var_type = p_string[pi];
  type = get_objtype(pi);	                     
  if((UdtCnt > 0) && (type < 6))          
  {
    type = isThisUdt(varname, type);
  }
  s_pos = e_pos;
  switch(type)
  {
    case 0:
    case 2:
    case 3:
    case 4:
      _GetChar();
      break;

    case 12:
    case 13:
    case 14:
      _GetChar();
      break;
  }
  if(type < 6)
  {
    if(callFlag == 0)
    {
      ndx = get_vndx(varname);
    }
    else
    {
      ndx = get_llvarndx(varname);             
    }
  }
  switch(type)
  {
    case 0:
      value = atof(Gtbl[ndx].Str);
      break;

    case 1:
      value = (double) Gtbl[ndx].Int;
      break;

    case 2:
      value = (double) Gtbl[ndx].Lng;
      break;

    case 3:
      value = (double) Gtbl[ndx].Flt;
      break;

    case 4:
      value = (double) Gtbl[ndx].Dbl;
      break;

    case 7:
      value = let_intarray(varname);
      break;

    case 8:
      value = let_fltarray(varname);
      break;

    case 9:
      value = let_dblarray(varname);
      break;

    case 11:                           
      value = get_Uval(varname);
      break;
 
    case 12:                            
    case 13:                           
    case 14:                            
      value = get_UDTlfd(varname);
      break;
  }
  return value;
}
/*--------- end get_varvalue ----------*/


double get_avalue()
{  
  char ch, varname[VAR_NAME];
  int pi, si=0;
  double value=0;

  pi = e_pos;
  ch = p_string[pi];
  if(isalpha(ch))                   
  {
    e_pos = pi;
    s_pos = pi;
    strcpy(s_holder, get_varname());
    value = get_varvalue();
    pi = e_pos;
  }
  else if((isdigit(ch)) || (IsAddop(ch))) 
  {
    if(IsAddop(ch))
    {
      varname[si] = ch;
      si++;
      pi++;
      ch = p_string[pi];
    }
    while(isdigit(ch) != 0)
    {
      varname[si] = ch;
      pi++;
      si++;
      ch = p_string[pi];
    }
    varname[si] = '\0';
    value = atof(varname);      
  }
  pi = iswhite(pi);
  e_pos = pi;
  return value;
}
/*-------- end get_avalue --------*/


