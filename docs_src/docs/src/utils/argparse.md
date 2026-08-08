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
    struct sstd::arg_rule::opt_rule opt(T& return_val, const T& initial_val, const char* opt_short, const char* opt_full, const int expected_num_of_args);
}
namespace sstd{
    class argparse{
        argparse();
        ~argparse();
        const std::string& err() const;
        
        template<class... Args>
        int parse(int argc, char* argv[], Args... args);
    };
}
```

## Description
### Parsing class

| Class method name | Description |
| ------------- | ----------- |
| argparse::parse(`argc`, `argv`, `cmd-or-option-definitions...`) | receives the inputted argc and argv passed to the main() function. And parses argc and argv according to the definitions after 3rd arg. Based on the analysis, the function returns the command ID specified by argc and argv.<br/>main() 関数に渡された argc および argv を受け取り，第3引数以降の定義に従って解析します．解析結果に基づき，この関数は argc および argv で指定されたコマンド ID を返します． |
| argparse::err()  | en-xxxxxxx<br>ja-xxxxxxx |
| argparse::help()  | en-xxxxxxx<br>ja-xxxxxxx |

### Command defining function

| Function name | Description |
| ------------- | ----------- |
| arg_rule::cmd_rule(<br/>&nbsp;&nbsp;const int cmd_id, <br/>&nbsp;&nbsp;const char* cmd, <br/>&nbsp;&nbsp;const int expected_num_of_args<br/>) | Same as follows.<br>以下に同じ． |
| arg_rule::cmd_rule(<br/>&nbsp;&nbsp;const int cmd_id, <br/>&nbsp;&nbsp;T& return_val, <br/>&nbsp;&nbsp;const T& initial_val, <br/>&nbsp;&nbsp;const char* cmd, <br/>&nbsp;&nbsp;const int expected_num_of_args<br/>) | - cmd_id: defines the command ID returned by `argparse::parse()` class method. Returned command ID can use in a `switch-case` statement.<br>- return_val: defines the address and data type of return variable.<br>- initial_val: defines the initial value of `return_val`.<br>- cmd: defines the command string.<br>- expected_num_of_args: defines the expected number of arguments for the command. `-1` treats as variable length arguments.<br><br>- cmd_id: `argparse::parse()` クラスメソッドが返すコマンドIDを定義します．返されたコマンドIDは，`switch-case` 文で使用できます．<br/>- return_val: 戻り値の変数アドレスとデータ型を定義します．<br/>- initial_val: `return_val` の初期値を定義します．<br/>- cmd: コマンド文字列を定義します．<br/>- expected_num_of_args: コマンドに指定される引数の数を定義します．`-1` は可変長引数として扱われます． |

### Option defining function

| Function name | Description |
| ------------- | ----------- |
| arg_rule::opt_rule(<br/>&nbsp;&nbsp;T& return_val, <br/>&nbsp;&nbsp;const T& initial_val, <br/>&nbsp;&nbsp;const char* opt_short, <br/>&nbsp;&nbsp;const char* opt_full, <br/>&nbsp;&nbsp;const int expected_num_of_args)  | en-xxxxxxx<br>ja-xxxxxxx |

- return_val: Same with `arg_rule::cmd_rule()` / `arg_rule::cmd_rule()` と同じ
- initial_val: Same with `arg_rule::cmd_rule()` / `arg_rule::cmd_rule()` と同じ
- opt_short: 
- opt_full: 
- expected_num_of_args: Same with `arg_rule::cmd_rule()` / `arg_rule::cmd_rule()` と同じ

メモ：optionに指定できる文字の制約として以下を記載する。
$ ./a.out -a cmd2 -1 0 1 2 -b 3
# Note: As an limitation, option did not allow to begin numeric number. `-1` will not treat as an option.
# Note: As a constraint, option must begin with an alphabetic character. In this case, So, `-1` is not treated as an option and can be extracted as a numerical value. / 注：制約としてオプションは英字で始まる必要があります．そのため，`-1` はオプションとはみなされず，数値として抽出できます．

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
    };

    std::vector<std::string> vCmdArg_s;
    std::vector<int> vCmdArg_i;
    bool opt_a=false, opt_b=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::CMD1,  vCmdArg_s, {}, "cmd1", -1)
    , sstd::arg_rule::cmd((int)CmdID::CMD2,  vCmdArg_i, {}, "cmd2", -1)
    , sstd::arg_rule::opt(opt_a, false, "-a", "--option-a", 0)
    , sstd::arg_rule::opt(opt_b, false, "-b", "--option-b", 0)
    );
    
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

### Options definitions (Case1)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
                     EMPTY
    };

    bool opt_a=false, opt_b=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::EMPTY, "", 0)
    , sstd::arg_rule::opt(opt_a, false, "-a", "--option-a", 0)
    , sstd::arg_rule::opt(opt_b, false, "-b", "--option-b", 0)
    );
    
    switch(cmd_id){
    case (int)CmdID::EMPTY:{
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

### Options definitions (Case2)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){

    enum class CmdID{
                     EMPTY
    };

    bool opt_c=false;
    
    sstd::argparse ap;
    int cmd_id = ap.parse(argc, argv
    , sstd::arg_rule::cmd((int)CmdID::EMPTY, "", 0)
    , sstd::arg_rule::opt(opt_c, false, "-c", "--option-c", 1) // Note: Expected arg length is set `1`.
    );
    
    switch(cmd_id){
    case (int)CmdID::EMPTY:{
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