import os
import sys
import glob



def path2graph_base(path_root, path_rm, depth=int(1)):
    vStr = []

    path_glob = path_root+'/*'
    #print(path_glob)
    vPath = sorted(glob.glob(path_glob))
    for path in vPath:
        if os.path.isdir(path):
            dirname = path.split("/")[-1]
            vStr.append(("%s- %s:" % (' '*2*depth, dirname)))
            vStr.extend( path2graph_base(path_root+'/'+dirname, path_rm, depth+1) )
        else:
            path_rmd      = path.split(path_rm)[-1]
            filename      = os.path.basename(path)
            filename_owEt = os.path.splitext(os.path.basename(path))[0] # without extension
            #vStr.append(("%s- %s: %s" % (' '*2*depth, filename_owEt, path_rmd)))
            vStr.append(("%s- %s" % (' '*2*depth, path_rmd)))
    
    return vStr
def path2graph(path_root, path_rm):
    vStr = []
    vStr.append('nav:')
    vStr.append('  - What is SSTD ?: index.md')
    vStr.append('  - src:')
    vStr.extend( path2graph_base(path_root, path_rm, depth=int(2)) )
    return vStr

def readAll(path):
    fp_r = open(path, "rb")
    text = fp_r.read()
    fp_r.close()
    return text

def vStr2str(vStr):
    s_ret = ''
    for s in vStr:
        s_ret += s+'\n'
    return s_ret

def main():
    argc = len(sys.argv)
    args = sys.argv
    if argc != 1+3: print('ERROR: input args != 3.'); return
    
    path_in  = args[1]
    path_out = args[2]
    path_target = args[3]
    
    vStr = path2graph(path_target, './docs_src/docs/')
    str_pages = vStr2str(vStr)

    text  = readAll(path_in)
    text += b'\n'
    text += str_pages.encode('ascii')
    
    fp_w = open(path_out, "wb")
    fp_w.write(text)
    fp_w.close()


main()

# how to test
# $ cd sstdref
# $ python ./mdEx_title/main.py ./mdEx_title/in.yml ./mdEx_title/out.yml ./docs_src/docs/src

# pages:
#   - src:
#     - glob: src/glob.md
#     - itr: src/itr.md
#     - measureTime: src/measureTime.md
#     - mkdir: src/mkdir.md
#     - pid: src/pid.md
#     - rm: src/rm.md
#     - sleep: src/sleep.md
#     - ssprintf: src/ssprintf.md
#     - stdlib:
#       - system: src/stdlib/system.md
#     - strEdit: src/strEdit.md
#     - time: src/time.md
#     - typeDef.h: src/typeDef.h.md
#     - vector:
#       - slice: src/vector/slice.md
