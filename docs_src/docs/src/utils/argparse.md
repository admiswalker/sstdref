# argparse
## Abstract
`argparse.hpp` contains the functions to parse command line options.  
`argparse.hpp` は，コマンドラインオプションパースする関数を収録している．

## Header file
```cpp
namespace sstd::arg_rule{
    const static int num_error                  = -1;
    const static int num_command_does_not_exist = -2;
    
    struct cmd_rule{
        int cmd_id                     = -1;
        int   return_val_type          = sstd::num_null;
        void* return_val_ptr           = NULL;
        sstd::void_ptr initial_val_ptr;
        std::string cmd;
        int expected_num_of_args       = 0;
    };
    struct opt_rule{
        int   return_val_type          = sstd::num_null;
        void* return_val_ptr           = NULL;
        sstd::void_ptr initial_val_ptr;
        std::string opt_full;
        std::string opt_short;
        int expected_num_of_args       = 0;
    };
    
    struct sstd::arg_rule::cmd_rule cmd(const int cmd_id,                                      const char* cmd, const int expected_num_of_args);
    template<typename T>
    struct sstd::arg_rule::cmd_rule cmd(const int cmd_id, T& return_val, const T& initial_val, const char* cmd, const int expected_num_of_args);
    template<typename T>
    struct sstd::arg_rule::cmd_rule cmd(const int cmd_id, T& return_val, const T& initial_val, const char* cmd, const int expected_num_of_args, const char* description);

    template<typename T>
    struct sstd::arg_rule::opt_rule opt(T& return_val, const T& initial_val, const char* opt_short, const char* opt_full, const int expected_num_of_args);
    template<typename T>
    struct sstd::arg_rule::opt_rule opt(T& return_val, const T& initial_val, const char* opt_short, const char* opt_full, const int expected_num_of_args, const char* description);
}
namespace sstd{
    class argparse{
        argparse();
        ~argparse();
        const std::string& err() const;
        const std::string& help();
        
        template<class... Args>
        int parse(int argc, char* argv[], Args... args);
    };
}
```

## Description
### Parsing class

| Class | Method | Variable | Description |
| ----- | ------ | -------- | ----------- |
| argparse | parse() | -                              | receives the inputted argc and argv passed to the main() function. And parses argc and argv according to the definitions after 3rd arg. Based on the analysis, the function returns the command ID.<br/>main() 関数に渡された argc および argv を受け取り，第3引数以降の定義に従って解析します．解析結果に基づきコマンド ID を返します． |
|          |         | RETURN VALUE                   | returns the command ID. <br/>コマンド ID を返します． |
|          |         | int argc                       | receives the inputted argc passed to the main() function. <br/>main() 関数に入力された argc を受け取ります． |
|          |         | char* argv[]                   | receives the inputted argv passed to the main() function. <br/>main() 関数に入力された argv を受け取ります． |
|          |         | `cmd-or-option-definitions...` | receives the definitions described by `arg_rule::cmd_rule()` or `arg_rule::opt_rule()`. <br/>`arg_rule::cmd_rule()` または `arg_rule::opt_rule()` で記述された定義を受け取ります． |
|          | err()  | - | returns a string of error message. <br>エラーメッセージの文字列を返します． |
|          | help() | - | returns a string describing the usage of command and options. <br>コマンドとオプションの使い方を説明する文字列を返します． |

### Command defining function

| Function | Variable | Description |
| -------- | ---------| ----------- |
| arg_rule::cmd_rule() | -                              | defines the command rule for `argparse::parse()`. <br/>`argparse::parse()` のコマンドルールを定義します． |
|                      | RETURN VALUE                   | returns a command definition to be passed to `argparse::parse()`. <br/>`argparse::parse()` に渡すためのコマンド定義を返します． |
|                      | const int cmd_id               | defines the command ID returned by `argparse::parse()` class method. Returned command ID can use in a `switch-case` statement. As a constraint, cmd_id must be a positive integer; negative integers are reserved as error values in the return value of `argparse::parse()`. <br/>`argparse::parse()` クラスメソッドが返すコマンドIDを定義します．返されたコマンドIDは，`switch-case` 文で使用できます．制約として `cmd_id` は正の整数である必要があります．負の整数は `argparse::parse()` の戻り値でエラー値として予約されています． |
|                      | T& return_val                  | defines the address and data type of return variable. `argparse::parse()` tries to convert the input arguments into this data type dynamically. <br/>戻り値の変数アドレスとデータ型を定義します．`argparse::parse()` は，入力引数をこのデータ型に動的に変換しようとします． |
|                      | const T& initial_val           | defines the initial value of `return_val`. <br/>`return_val` の初期値を定義します． |
|                      | const char* cmd                | defines the command string. <br/>コマンド文字列を定義します． |
|                      | const int expected_num_of_args | defines the expected number of arguments for the command. `-1` treats as variable length arguments. <br/>コマンドに指定される引数の数を定義します．`-1` は可変長引数として扱われます． |
|                      | const char* description        | defines the command description for `argparse::help()`. <br/>`argparse::help()` 向けにコマンドの説明を定義します． |

### Option defining function

| Function | Variable | Description |
| -------- | -------- | ----------- |
| arg_rule::opt_rule() | -                              | defines the option rule for `argparse::parse()`. <br/>`argparse::parse()` のオプションルールを定義します． |
|                      | RETURN VALUE                   | returns a command definition to be passed to `argparse::parse()`. <br/>`argparse::parse()` に渡すためのコマンド定義を返します． |
|                      | T& return_val                  | Same with `arg_rule::cmd_rule()`. <br/>`arg_rule::cmd_rule()` と同様． |
|                      | const T& initial_val           | Same with `arg_rule::cmd_rule()`. <br/>`arg_rule::cmd_rule()` と同様． |
|                      | const char* opt_short          | defines a short option, which should start with '-'. This option is restricted to a single alphabetic character (`*1`). As a constraint enabling to extract negative number like `$ ./a.out -3 -2 -1 0 1 2 3` command line arguments, short option must begin with an alphabetic character. With this constraint, `-3`, `-2` and `-1` are not treated as an option and can be extracted as a numerical value. <br/>短縮オプションを定義します．定義は `-` で始まる1文字のアルファベットである必要があります．制約として短縮オプションは英字で始まる必要があります．例えば `$ ./a.out -3 -2 -1 0 1 2 3` のような負の数を含むコマンドライン引数は，この制約により `-3`、`-2`、`-1` はオプションとして扱われず，数値として抽出できます． |
|                      | const char* opt_full           | defines the full-format option, which should start with '--'. <br/>オプションを定義します．定義は `--` で始まる必要があります． |
|                      | const int expected_num_of_args | Same with `arg_rule::cmd_rule()`. <br/>`arg_rule::cmd_rule()` と同様． |
|                      | const char* description        | defines the option description for `argparse::help()`. <br/>`argparse::help()` 向けにオプションの説明を定義します． |

## Usage
### Commands and Options definitions
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
                     CMD1
                     , CMD2
                     , HELP
    };

    std::vector<std::string> vCmdArg_s;
    std::vector<int> vCmdArg_i;
    bool opt_a=false, opt_b=false, opt_h=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::CMD1,  vCmdArg_s, {}, "cmd1", -1, "This is description of `cmd1`.")
    , sstd::arg_rule::cmd((int)CmdID::CMD2,  vCmdArg_i, {}, "cmd2", -1, "This is description of `cmd2`.")
    , sstd::arg_rule::opt(opt_a, false, "-a", "--option-a", 0, "This is description of `--option-a`.")
    , sstd::arg_rule::opt(opt_b, false, "-b", "--option-b", 0, "This is description of `--option-b`.")
    , sstd::arg_rule::opt(opt_h, false, "-h", "--help",     0, "Help option.")
    );
    if(opt_h){ cmd_id = (int)CmdID::HELP; }
    
    switch(cmd_id){
    case (int)CmdID::CMD1: {
        printf("In CMD1\n");
        sstd::printn(opt_a);
        sstd::printn(opt_b);
        sstd::printn(vCmdArg_s);
        
    }break;
    case (int)CmdID::CMD2: {
        printf("In CMD2\n");
        sstd::printn(opt_a);
        sstd::printn(opt_b);
        sstd::printn(vCmdArg_i);
	
    }break;
    case (int)CmdID::HELP: {
        printf("%s", ap.help().c_str());
    
    }break;
    default:{ sstd::pdbg_err("%s", ap.err().c_str()); }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out cmd1 -a arg1 arg2 arg3
$ ./a.out -a cmd2 -1 0 1 2 -b 3 # Note: As a constraint, option must begin with an alphabetic character. In this case, So, `-1` is not treated as an option and can be extracted as a numerical value. / 注：制約としてオプションは英字で始まる必要があります．そのため，`-1` はオプションとはみなされず，数値として抽出できます．
$ ./a.out --help
```

### Commands definitions
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
                     EMPTY
                     , CMD1
                     , CMD2
    };

    std::vector<std::string> vCmdArg_s;
    std::vector<int> vCmdArg_i;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::EMPTY, vCmdArg_s, {}, "",     -1)
    , sstd::arg_rule::cmd((int)CmdID::CMD1,  vCmdArg_s, {}, "cmd1", -1)
    , sstd::arg_rule::cmd((int)CmdID::CMD2,  vCmdArg_i, {}, "cmd2", -1)
    );
    
    switch(cmd_id){
    case (int)CmdID::EMPTY:{printf("In EMPTY: ");sstd::printn(vCmdArg_s);}break;
    case (int)CmdID::CMD1: {printf("In CMD1: "); sstd::printn(vCmdArg_s);}break;
    case (int)CmdID::CMD2: {printf("In CMD2: "); sstd::printn(vCmdArg_i);}break;
    default:{ sstd::pdbg_err("%s", ap.err().c_str()); }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out arg1 arg2 arg3
$ ./a.out cmd1 arg1 arg2 arg3
$ ./a.out cmd2 1 2 3
$ ./a.out cmd2 arg1 arg2 arg3 # **This is error case.**
```

### Options definitions (without arguments)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    bool opt_a=false, opt_b=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::opt(opt_a, false, "-a", "--option-a", 0)
    , sstd::arg_rule::opt(opt_b, false, "-b", "--option-b", 0)
    );

    switch(cmd_id){
    case sstd::arg_rule::num_command_does_not_exist:{
        sstd::printn(opt_a);
        sstd::printn(opt_b);
        
    }break;
    default:{ sstd::pdbg_err("%s", ap.err().c_str()); }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out
$ ./a.out -a
$ ./a.out --option-a
$ ./a.out -b
$ ./a.out --option-b
$ ./a.out -ab # Following commands also output the same result: `$ ./a.out --option-a --option-b`, `$ ./a.out -a --option-b`, `$ ./a.out --option-a -b`, `$ ./a.out -ba`, `$ ./a.out --option-b --option-a`, `$ ./a.out -b --option-a`, `$ ./a.out --option-b -a`.
```

### Options definitions (with an argument)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    bool opt_c=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::opt(opt_c, false, "-c", "--option-c", 1) // Note: Expected arg length is set `1`.
    );
    
    switch(cmd_id){
    case sstd::arg_rule::num_command_does_not_exist:{
        sstd::printn(opt_c);
        
    }break;
    default:{ sstd::pdbg_err("%s", ap.err().c_str()); }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out
$ ./a.out -c # **This is error case. `--option-c` should have 1 argument.**
$ ./a.out -c true
$ ./a.out -c=true
$ ./a.out --option-c true
$ ./a.out --option-c=true
$ ./a.out -c false
$ ./a.out -c=false
$ ./a.out --option-c false
$ ./a.out --option-c=false
```

## Appendix
### Data type conversions

Supported data types:

- Basic data types:
    - `bool`, `char`, `int8`, `int16`, `int32`, `int64`, `uint8`, `uint16`, `uint32`, `uint64`, `float`, `double`, `std::string`
- Basic data types wrapped in `std::vector<T>`:
    - `std::vector<bool>`, `std::vector<char>`, `std::vector<int8>`, `std::vector<int16>`, `std::vector<int32>`, `std::vector<int64>`, `std::vector<uint8>`, `std::vector<uint16>`, `std::vector<uint32>`, `std::vector<uint64>`, `std::vector<float>`, `std::vector<double>`, `std::vector<std::string>`

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
        BOOL, CHAR, INT8, INT16, INT32, INT64, UINT8, UINT16, UINT32, UINT64, FLOAT, DOUBLE
        , VBOOL, VCHAR, VINT8, VINT16, VINT32, VINT64, VUINT8, VUINT16, VUINT32, VUINT64, VFLOAT, VDOUBLE
    };

    bool res_bool=false; char res_char='x';
    int8  res_int8 =0;  int16 res_int16 =0;  int32 res_int32 =0;  int64 res_int64 =0;
    uint8 res_uint8=0; uint16 res_uint16=0; uint32 res_uint32=0; uint64 res_uint64=0;
    float res_float=0; double res_double=0;
    std::vector<bool> res_vbool; std::vector<char> res_vchar;
    std::vector< int8> res_vint8;  std::vector< int16> res_vint16;  std::vector< int32> res_vint32;  std::vector< int64> res_vint64;
    std::vector<uint8> res_vuint8; std::vector<uint16> res_vuint16; std::vector<uint32> res_vuint32; std::vector<uint64> res_vuint64;
    std::vector<float> res_vfloat; std::vector<double> res_vdouble;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::BOOL,    res_bool,       false, "cmd-bool",     1)
    , sstd::arg_rule::cmd((int)CmdID::CHAR,    res_char,         'x', "cmd-char",     1)
    , sstd::arg_rule::cmd((int)CmdID::INT8,    res_int8,   ( int8 )0, "cmd-int8",     1)
    , sstd::arg_rule::cmd((int)CmdID::INT16,   res_int16,  ( int16)0, "cmd-int16",    1)
    , sstd::arg_rule::cmd((int)CmdID::INT32,   res_int32,  ( int32)0, "cmd-int32",    1)
    , sstd::arg_rule::cmd((int)CmdID::INT64,   res_int64,  ( int64)0, "cmd-int64",    1)
    , sstd::arg_rule::cmd((int)CmdID::UINT8,   res_uint8,  (uint8 )0, "cmd-uint8",    1)
    , sstd::arg_rule::cmd((int)CmdID::UINT16,  res_uint16, (uint16)0, "cmd-uint16",   1)
    , sstd::arg_rule::cmd((int)CmdID::UINT32,  res_uint32, (uint32)0, "cmd-uint32",   1)
    , sstd::arg_rule::cmd((int)CmdID::UINT64,  res_uint64, (uint64)0, "cmd-uint64",   1)
    , sstd::arg_rule::cmd((int)CmdID::FLOAT,   res_float,  (float )0, "cmd-float",    1)
    , sstd::arg_rule::cmd((int)CmdID::DOUBLE,  res_double, (double)0, "cmd-double",   1)
    , sstd::arg_rule::cmd((int)CmdID::VBOOL,   res_vbool,         {}, "cmd-vbool",   -1)
    , sstd::arg_rule::cmd((int)CmdID::VCHAR,   res_vchar,         {}, "cmd-vchar",   -1)
    , sstd::arg_rule::cmd((int)CmdID::VINT8,   res_vint8,         {}, "cmd-vint8",   -1)
    , sstd::arg_rule::cmd((int)CmdID::VINT16,  res_vint16,        {}, "cmd-vint16",  -1)
    , sstd::arg_rule::cmd((int)CmdID::VINT32,  res_vint32,        {}, "cmd-vint32",  -1)
    , sstd::arg_rule::cmd((int)CmdID::VINT64,  res_vint64,        {}, "cmd-vint64",  -1)
    , sstd::arg_rule::cmd((int)CmdID::VUINT8,  res_vuint8,        {}, "cmd-vuint8",  -1)
    , sstd::arg_rule::cmd((int)CmdID::VUINT16, res_vuint16,       {}, "cmd-vuint16", -1)
    , sstd::arg_rule::cmd((int)CmdID::VUINT32, res_vuint32,       {}, "cmd-vuint32", -1)
    , sstd::arg_rule::cmd((int)CmdID::VUINT64, res_vuint64,       {}, "cmd-vuint64", -1)
    , sstd::arg_rule::cmd((int)CmdID::VFLOAT,  res_vfloat,        {}, "cmd-vfloat",  -1)
    , sstd::arg_rule::cmd((int)CmdID::VDOUBLE, res_vdouble,       {}, "cmd-vdouble", -1)
    );
    
    switch(cmd_id){
    case (int)CmdID::BOOL:   { sstd::printn(res_bool   ); }break;
    case (int)CmdID::CHAR:   { sstd::printn(res_char   ); }break;
    case (int)CmdID::INT8:   { sstd::printn(res_int8   ); }break;
    case (int)CmdID::INT16:  { sstd::printn(res_int16  ); }break;
    case (int)CmdID::INT32:  { sstd::printn(res_int32  ); }break;
    case (int)CmdID::INT64:  { sstd::printn(res_int64  ); }break;
    case (int)CmdID::UINT8:  { sstd::printn(res_uint8  ); }break;
    case (int)CmdID::UINT16: { sstd::printn(res_uint16 ); }break;
    case (int)CmdID::UINT32: { sstd::printn(res_uint32 ); }break;
    case (int)CmdID::UINT64: { sstd::printn(res_uint64 ); }break;
    case (int)CmdID::FLOAT:  { sstd::printn(res_float  ); }break;
    case (int)CmdID::DOUBLE: { sstd::printn(res_double ); }break;
    case (int)CmdID::VBOOL:  { sstd::printn(res_vbool  ); }break;
    case (int)CmdID::VCHAR:  { sstd::printn(res_vchar  ); }break;
    case (int)CmdID::VINT8:  { sstd::printn(res_vint8  ); }break;
    case (int)CmdID::VINT16: { sstd::printn(res_vint16 ); }break;
    case (int)CmdID::VINT32: { sstd::printn(res_vint32 ); }break;
    case (int)CmdID::VINT64: { sstd::printn(res_vint64 ); }break;
    case (int)CmdID::VUINT8: { sstd::printn(res_vuint8 ); }break;
    case (int)CmdID::VUINT16:{ sstd::printn(res_vuint16); }break;
    case (int)CmdID::VUINT32:{ sstd::printn(res_vuint32); }break;
    case (int)CmdID::VUINT64:{ sstd::printn(res_vuint64); }break;
    case (int)CmdID::VFLOAT: { sstd::printn(res_vfloat ); }break;
    case (int)CmdID::VDOUBLE:{ sstd::printn(res_vdouble); }break;
    default:{ sstd::pdbg_err("%s", ap.err().c_str()); }
    }
    
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out cmd-bool T
$ ./a.out cmd-char a
$ ./a.out cmd-int8 -8
$ ./a.out cmd-int16 -16
$ ./a.out cmd-int32 -32
$ ./a.out cmd-int64 -64
$ ./a.out cmd-uint8 8
$ ./a.out cmd-uint16 16
$ ./a.out cmd-uint32 32
$ ./a.out cmd-uint64 64
$ ./a.out cmd-float 1.234
$ ./a.out cmd-double 1.234
$ ./a.out cmd-vbool TRUE  T YES Y ON  true  t yes y on  1
$ ./a.out cmd-vbool FALSE F NO  N OFF false f no  n off 0
$ ./a.out cmd-vchar a b c
$ ./a.out cmd-vint8 -8 -7 -6
$ ./a.out cmd-vint16 -16 -15 -14
$ ./a.out cmd-vint32 -32 -31 -30
$ ./a.out cmd-vint64 -64 -63 -62
$ ./a.out cmd-vuint8 8 7 6
$ ./a.out cmd-vuint16 16 15 14
$ ./a.out cmd-vuint32 32 31 30
$ ./a.out cmd-vuint64 64 63 62
$ ./a.out cmd-vfloat -1.1 0.0 1.1 2.2 3.3
$ ./a.out cmd-vdouble -1.1 0.0 1.1 2.2 3.3
```

### Example of CSV extraction
This sample code extracts specific rows, cols or item from CSV by selecting `get-rows`, `get-cols` or `get-item` command. If the `--skip-row-header (-r)` or `--skip-col-header (-c)` option is enabled, the code ignores the CSV header(s).

このサンプルコードは，`get-rows`, `get-cols` または `get-item` コマンドを選択することで，CSVから特定の行，列，または項目を抽出します．`--skip-row-header (-r)` または `--skip-col-header (-c)` オプションが有効な場合，コードは CSV のヘッダーを無視します．

- <u>**example.csv**</u>
```
#mdEx: cpp example (in:attachment:example.csv)
row-name, A, B, C, D, E, F, G, H, I, J
row1, A1, B1, C1, D1, E1, F1, G1, H1, I1, J1
row2, A2, B2, C2, D2, E2, F2, G2, H2, I2, J2
row3, A3, B3, C3, D3, E3, F3, G3, H3, I3, J3
row4, A4, B4, C4, D4, E4, F4, G4, H4, I4, J4
row5, A5, B5, C5, D5, E5, F5, G5, H5, I5, J5
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

std::vector<std::vector<std::string>> read_csv(
    const std::string& src_path,
    const bool skip_row_header,
    const bool skip_col_header)
{
    std::vector<std::vector<std::string>> vv = sstd::csv2vvec(src_path);
    if(skip_row_header){ vv = vv && sstd::slice(1, sstd::end()); }
    if(skip_col_header){
        for(uint i=0; i<vv.size(); ++i){
            vv[i] = vv[i] && sstd::slice(1, sstd::end());
        }
    }
    return vv;
}
void print_vv(const std::vector<std::vector<std::string>>& vv){
    printf("[\n");
    for(uint i=0; i<vv.size(); ++i){
        printf(" "); sstd::print(vv[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[]){

    enum class CmdID{
                       GET_ROWS
                     , GET_COLS
                     , GET_ITEM
    };

    std::string src_path;
    bool skip_row_header=false, skip_col_header=false;
    std::vector<uint> vArg;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::GET_ROWS, vArg, {}, "get-rows", -1)
    , sstd::arg_rule::cmd((int)CmdID::GET_COLS, vArg, {}, "get-cols", -1)
    , sstd::arg_rule::cmd((int)CmdID::GET_ITEM, vArg, {}, "get-item",  2)
    , sstd::arg_rule::opt(src_path, std::string(""), "-s", "--src", 1)
    , sstd::arg_rule::opt(skip_row_header, false, "-r", "--skip-row-header", 0)
    , sstd::arg_rule::opt(skip_col_header, false, "-c", "--skip-col-header", 0)
    );
    
    switch(cmd_id){
    case (int)CmdID::GET_ROWS : {
        std::vector<std::vector<std::string>> res_vv, vv;

        vv = read_csv(src_path, skip_row_header, skip_col_header);
        for(uint i=0; i<vArg.size(); ++i){
            int ri = vArg[i]-1; if(ri>(int)vv.size()){ sstd::pdbg("%d is out of range.\n\n", vArg[i]); return -1; }
            res_vv <<= vv[ri];
        }
        print_vv(res_vv);

    } break;
    case (int)CmdID::GET_COLS : {
        std::vector<std::vector<std::string>> res_vv, vv;

        vv = read_csv(src_path, skip_row_header, skip_col_header);
        for(uint ri=0; ri<vv.size(); ++ri){
            std::vector<std::string> tmp_v;
            for(uint i=0; i<vArg.size(); ++i){
                int ci = vArg[i]-1; if(ci>(int)vv[ri].size()){ sstd::pdbg("%d is out of range.\n\n", vArg[i]); return -1; }
                tmp_v <<= vv[ri][ci];
            }
            res_vv <<= tmp_v;
        }
        print_vv(res_vv);

    } break;
    case (int)CmdID::GET_ITEM : {
        std::vector<std::vector<std::string>> res_vv, vv;

        vv = read_csv(src_path, skip_row_header, skip_col_header);
        int ri = vArg[0]-1;
        int ci = vArg[1]-1;
        if( ri>=(int)vv.size() || ci>=(int)vv[ri].size() ){ sstd::pdbg("(%d, %d) is out of range.\n\n", vArg[0], vArg[1]); return -1; }
        res_vv <<= std::vector<std::string>({ vv[ri][ci] });
        print_vv(res_vv);

    } break;
    default : {
        sstd::pdbg_err("%s", ap.err().c_str());
    }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out get-rows 1 3 -rc --src example.csv
$ ./a.out get-cols 2 4 -rc --src example.csv
$ ./a.out get-item 2 2 -rc --src example.csv
```

### TEST
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){
    sstd::printn(argc);
    for(int i=0; i<argc; ++i){
        sstd::printn(argv[i]);
    }
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out cmd src_path dst_path
```

### A complicated example of `sstd::argparse()`
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
                     EMPTY,
                     CMD
    };

    std::vector<std::string> vCmdArgs;
    std::vector<int> vOptA, vOptR;
    bool optB=false,optC=false,optD=false,optE=false,optF=false,optG=true,optH=true;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
                          , sstd::arg_rule::cmd((int)CmdID::EMPTY, "", 0)
                          , sstd::arg_rule::cmd((int)CmdID::CMD, vCmdArgs, {}, "cmd", 2)
                          , sstd::arg_rule::opt(vOptA, std::vector<int>({}), "-a", "--option-a", 2)
                          , sstd::arg_rule::opt( optB, false, "-b", "--option-b", 0)
                          , sstd::arg_rule::opt( optC, false, "-c", "--option-c", 0)
                          , sstd::arg_rule::opt( optD, false, "-d", "--option-d", 0)
                          , sstd::arg_rule::opt( optE, false, "-e", "--option-e", 1)
                          , sstd::arg_rule::opt( optF, false, "-f", "--option-f", 1)
                          , sstd::arg_rule::opt( optG,  true, "-g", "--option-g", 1)
                          , sstd::arg_rule::opt( optH,  true, "-h", "--option-h", 1)
                          , sstd::arg_rule::opt(vOptR, std::vector<int>({0,0,0,0}), "-r", "--rectangle", 4)
                    );
    if(cmd_id==-1){ sstd::printn_all(ap.err()); }
//    if(cmd_id==-2){ sstd::printn_all(ap.err()); } // empty command が呼び出されるべきでは？
    
    switch(cmd_id){
    case (int)CmdID::EMPTY : {
        printf("--- In the `CmdID::EMPTY` case ---\n");
//        sstd::pdbg_err("%s", ap.err().c_str());
//        ASSERT_TRUE(false);
//        ap.print_help();
    } break;
    case (int)CmdID::CMD: {
        printf("--- In the `CmdID::CMD` case ---\n");
	
        // process get lines
        sstd::printn(vCmdArgs);
        sstd::printn(vOptA);
        sstd::printn(optB);
        sstd::printn(optC);
        sstd::printn(optD);
        sstd::printn(optE);
        sstd::printn(optF);
        sstd::printn(optG);
        sstd::printn(optH);
        sstd::printn(vOptR);
    } break;
    case (int)sstd::arg_rule::num_error : {
        sstd::pdbg_err("%s", ap.err().c_str());
//        ASSERT_TRUE(false);
    } break;
    default : {
        sstd::pdbg_err("%s", ap.err().c_str());
//        ASSERT_TRUE(false);
    }
    }
    
    printf("\n");
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
$ ./a.out
$ ./a.out cmd -a 1 2 -b -cd -e true -f=true -g false -h=false --rectangle 5 5 5 5 src_path dst_path
```

## Implementation
- Source: [sstd/src/utils/argparse.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/utils/argparse.cpp)
- Header: [sstd/src/utils/argparse.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/utils/argparse.hpp)
- Test: [test/src_test/utils/argparse.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/utils/argparse.cpp)