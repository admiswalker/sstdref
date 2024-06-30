# YAML
## Abstract
The SSTD YAML parser. `sstd::yaml_` seriese functions are the SSTD YAML parser set and are used along with the `sstd::terp` class.
A instance of the `sstd::terp` class operates like a in**<u>terp</u>**reter object.
And the user can treat YAML file through the `sstd::terp` object.

SSTD YAML パーサ．`sstd::yaml_` 系の関数は SSTD の yaml パーサーセットであり，`sstd::terp` クラスとともに使用されます．
`sstd::terp` クラスのインスタンスは，インタープリタ (in**<u>terp</u>**reter) のオブジェクトのように動作します．
ユーザは `sstd::terp` オブジェクトを通して，YAML ファイルを扱うことができます．

## Header file
```cpp
namespace sstd{
    bool yaml_load     (           sstd::terp::var & ret_yml,  const        char* s);
    bool yaml_load     (           sstd::terp::var & ret_yml,  const std::string& s);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, const        char* s);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, const std::string& s);
    
    bool yaml_load    (            sstd::terp::var & ret_yml,  sstd::file& fp);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, sstd::file& fp);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| yaml_load(var&, c*/s&) | reads YAML string and converts to `sstd::terp::var` object.<br>YAML 文字列を読み取り `sstd::terp::var` オブジェクトに変換します．|
| yaml_load(var&, file&) | reads YAML string through the `sstd::file` instance opened by the `sstd::file::fopen()` instance method. After that, this function converts to the YAML string to `sstd::terp::var` object.<br>`sstd::file::fopen()` インスタンスメソッドで開かれた `sstd::file` インスタンスを介して YAML テキストを読み取ります．その後，YAML 文字列を `sstd::terp::var` オブジェクトに変換します． |
| yaml_load_all()        | is extended version of `yaml_load()` and supports `---` YAML command.<br>`yaml_load()` 関数を拡張したバージョンで，`---` YAML コマンドをサポートしています． |

## Usage
### yaml_load(var&, c*/s&)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = R"(
- a1
- k1: v1
)";
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, s)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### yaml_load(var&, file&)
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- a1
- k1: v1
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string path = "./example.yaml";
    sstd::file fp; if(!fp.fopen(path, "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### yaml_load_all(var&, c*/s&)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = R"(
- a1
- k1: v1
---
- a2
- k2: v2
---
- a3
- k3: v3
)";
    
    std::vector<sstd::terp::var> v_yml;
    if(!sstd::yaml_load_all(v_yml, s)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(v_yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### yaml_load_all(var&, file&)
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- a1
- k1: v1
---
- a2
- k2: v2
---
- a3
- k3: v3
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string path = "./example.yaml";
    sstd::file fp; if(!fp.fopen(path, "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    std::vector<sstd::terp::var> v_yml;
    if(!sstd::yaml_load_all(v_yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(v_yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

### YAML notation and support status / YAML 記法とサポート状況

#### alias

Not supported.

#### anchor

Not supported.

#### data type specification

Not supported.

```text
ex:
- !str abc
- !str 123
- !pairs
  - k1: v1
  - k2: v2
```

#### comment
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- a
#- b
- c
- k1: v1
#  k2: v2
  k3: v3
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### end of YAML ('...')

Using '...' notation enables to stop reading the YAML file.

'...' 記法の使用で YAML ファイルの読み込みを終了できます．

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- a
- b
...
- c
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### flow style notation
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
[a, b, c, {k1: v1}]
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### hash / ハッシュ
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
k1: v1
k2: v2
k3:
  k31: v31
  k32: v32
  k33: v33
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### list / 配列
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- a1
- b1
- c1
-
  - c12
  - c12
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### multiple line string by '|' / 複数行の文字列 ('|')

Using the pipe sign ('|') enables to read the string which contains the line feed code.

- '|' reads the string with the line feed code.
- '|+' reads the string with the line feed code and the last line feeds to the next item.
- '|-' reads the string with the line feed code, except last line.

パイプ記号 ('|') の使用で改行コードを含む文字列を読み込めます．

- '|' は改行のある文字列を読み込みます．
- '|+' は改行のある文字列と最終行は次の項目までの改行を読み込みます．
- '|-' は改行のある文字列を読み込みますが，最終行の改行は取り除かれます．

**Note / 注意:**

The YAML standard does NOT treat '#' in the `Block Chomping Indicator ('|')` as a comment, but treats as a text.

YAML の規格では，`Block Chomping Indicator ('|')` 中に含まれる '#' をコメントとして取り扱わず，テキストとして取り扱います．

Ref: [8.1.1.2. Block Chomping Indicator - The YAML Standard](https://yaml.org/spec/1.2.2/#8112-block-chomping-indicator)


- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- |
  s1
  s2
  s3 # contains the line feed / 改行を含める


- |+
  s_plus1
  s_plus2
  s_plus3 # contains the last line feed(s) to the next item / 最終行と次の項目までの改行を含める


- |-
  s_minus1
  s_minus2
  s_minus3 # not contains the last line feed / 最終行の改行を含めない
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### multiple line string by '|N' / 複数行の文字列 ('|N')

Using the pipe sign with number ('|N') enables to indicate the width of indent.

パイプ記号と数値を組み合わせ ('|N') でインデント幅を指示できます．

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- |2
    s1
    s2
    s3 # contains the line feed / 改行を含める


- |+2
    s_plus1
    s_plus2
    s_plus3 # contains the last line feed(s) to the next item / 最終行と次の項目までの改行を含める


- |-2
    s_minus1
    s_minus2
    s_minus3 # not contains the last line feed / 最終行の改行を含めない


```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### multiple line string by '>' / 複数行の文字列 ('>')

Using the greater-than sign ('>') enables to read the string which contains the line feed code. At this time, the line feed code(s) are converted to the space(s) (' ').

- '>' reads the string with line feed code, and converts line feed code(s) to the space(s) (' ').
- '>+' reads the string with line feed code, and converts line feed code(s) to space (' '), while keeping the line feed code(s) between the last line and next item.
- '>-' reads the string with line feed code, and converts line feed code(s) to space (' '), except the line feed code at the last line.

大なり記号 ('>') の使用で改行コードを含む文字列を読み込めます．このとき，改行コードはスペース (' ') に変換されます．

- '>' は改行コードのある文字列を読み込み，改行コードをスペース (' ') に変換します．
- '>+' は改行コードのある文字列を読み込み，改行コードをスペース (' ') に変換します．ただし，最終行から次の項目までの改行を保持します．
- '>-' は改行コードのある文字列を読み込み，改行コードをスペース (' ') に変換します．ただし，最終行の改行を無視します．

**Note / 注意:**

The YAML standard does NOT treat '#' in the `Block Chomping Indicator ('|')` as a comment, but treats as a text.

YAML の規格では，`Block Chomping Indicator ('|')` 中に含まれる '#' をコメントとして取り扱わず，テキストとして取り扱います．

Ref: [8.1.1.2. Block Chomping Indicator - The YAML Standard](https://yaml.org/spec/1.2.2/#8112-block-chomping-indicator)


- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- >
  s1
  s2
  s3 # contains the line feed / 改行を含める


- >+
  s_plus1
  s_plus2
  s_plus3 # contains the last line feed(s) to the next item / 最終行と次の項目までの改行を含める


- >-
  s_minus1
  s_minus2
  s_minus3 # not contains the last line feed / 最終行の改行を含めない


```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### multiple line string by '>N' / 複数行の文字列 ('>N')

Using the greater-than with number ('>N') enables to indicate the width of indent.

大なり記号と数値を組み合わせ ('>N') でインデント幅を指示できます．

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- >2
    s1
    s2
    s3 # contains the line feed / 改行を含める


- >+2
    s_plus1
    s_plus2
    s_plus3 # contains the last line feed(s) to the next item / 最終行と次の項目までの改行を含める


- >-2
    s_minus1
    s_minus2
    s_minus3 # not contains the last line feed / 最終行の改行を含めない


```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### quotes / 引用符
- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
- ' a 1 '
- " b 1 "
- ' k 1 ': ' v 1 '
- " k 2 ": " v 2 "
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Example of setting file loading

#### sample1

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
users:
  - name: user001
    email: user001@example.com
    public-keys:
      - ssh-ed25519 XXXX user001-1@XXX.XXX
      - ssh-ed25519 XXXX user001-2@XXX.XXX
  - name: user002
    email: user002@example.com
    public-keys:
      - ssh-ed25519 XXXX user002@XXX.XXX
  - name: user003
    email: user003@example.com
    public-keys:
      - ssh-ed25519 XXXX user003@XXX.XXX
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

struct usr{
    std::string usr_name;
    std::string email;
    std::vector<std::string> v_public_key;
};

bool usrObj2usrStruct(struct usr& ret, const sstd::terp::var& obj){
    if(!sstd::terp::isHash( obj )){ return false; }
    if(!(obj.find("name"       )!=obj.end())){ return false; }
    if(!(obj.find("email"      )!=obj.end())){ return false; }
    if(!(obj.find("public-keys")!=obj.end())){ return false; }
    
    ret.usr_name = obj["name" ].to<std::string>();
    ret.email    = obj["email"].to<std::string>();
    
    for(uint ip=0; ip<obj["public-keys"].size(); ++ip){
        ret.v_public_key.push_back( obj["public-keys"][ip].to<std::string>() );
    }
    
    return true;
}
bool usrObj2usrStruct(std::vector<struct usr>& ret, const sstd::terp::var& v_obj){
    std::vector<struct usr> v;
    for(uint i=0; i<v_obj.size(); ++i){
        struct usr tmp; if(! usrObj2usrStruct(tmp, v_obj[i]) ){ return false; }
        ret.push_back( tmp );
    }
    return true;
}

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }

    std::vector<struct usr> v_usr; if(!usrObj2usrStruct(v_usr, yml["users"])){ sstd::pdbg_err("Parsing the yaml object is failed."); };
    
    for(uint i=0; i<v_usr.size(); ++i){
        printf("usr_name: %s\n", v_usr[i].usr_name.c_str());
        printf("email: %s\n",    v_usr[i].email.c_str()   );
        printf("public_keys: [");
        for(uint ip=0; ip<v_usr[i].v_public_key.size(); ++ip){
            printf(" \"%s\"", v_usr[i].v_public_key[ip].c_str());
        }
        printf(" ]\n");
        printf("\n");
    }
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### sample2

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
parameter:
  lib_url: "https://github.com/admiswalker/SubStandardLibrary-SSTD-/archive/refs/heads/master.zip"
  max_retry: 10
  wait_time_sec: 10
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    
    std::string lib_url = yml["parameter"]["lib_url"].to<std::string>();
    uint max_retry      = yml["parameter"]["max_retry"].to<uint>();
    uint wait_time_sec  = yml["parameter"]["wait_time_sec"].to<uint>();
    sstd::printn( lib_url       );
    sstd::printn( max_retry     );
    sstd::printn( wait_time_sec );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### sample2: setting file for some Server

- <u>**example.yaml**</u>
```
#mdEx: cpp example (in:attachment:example.yaml)
#cloud-config
cloud_final_modules:
  - [users-groups, always]
users: # run by "users-groups" option
  - default
  - name: user_name
    groups: [wheel]
    sudo: ["ALL=(ALL) NOPASSWD:ALL"]
    shell: /bin/bash
    ssh-authorized-keys:
      - ssh-ed25519 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX user_name@user_name.XXX.XXX
runcmd: # run by "scripts-user" option
  - echo ""
  - echo ""
  - echo "--- begin --- example of run command -------------------------------------------"
  - echo "Hello cloud-config / runcmd"
  - echo "------------------------------------------------------------------------ end ---"
  - echo ""
  - echo ""
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp; if(!fp.fopen("./example.yaml", "r")){ sstd::pdbg_err("fopen() is failed.\n"); return 0; }
    
    sstd::terp::var yml;
    if(!sstd::yaml_load(yml, fp)){ sstd::pdbg_err("yaml_load() is failed.\n"); return 0; }
    sstd::printn(yml);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/yaml.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/yaml.cpp)
- Header: [sstd/src/file/yaml.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/yaml.hpp)
- Test: [test/file/yaml.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/yaml.cpp)
